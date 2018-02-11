/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Класс Renderer: растеризатор, содержит функции перевода 3D-объектов в 2D-изображения (преобразование вершин, затенение).
*/

#include "Renderer.h"
#include "Util.h"

#include <climits>
#include <iostream>
#include <fstream>

namespace GL {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	Renderer::Renderer(Graphics ^im, int viewportWidth, int viewportHeight) : graphics(im) {
		// initialize colors
		bgColor = DEFAULT_BG_COLOR;
		wfBrush = gcnew SolidBrush(DEFAULT_WF_COLOR);
		selectedBrush = gcnew SolidBrush(DEFAULT_SELECTED_COLOR);
		surfaceBrush = gcnew SolidBrush(Color::Black);
		// initialize z-buffer
		setViewport(viewportWidth, viewportHeight);
	}

	void Renderer::setViewport(int width, int height) {
		viewportX = width;
		viewportY = height;
		zbuffer = gcnew array<float, 2>(viewportX, viewportY);
	}

	float Renderer::getViewportAspect() {
		return (float)viewportX / (float)viewportY;
	}

	void Renderer::clearScreen() {
		graphics->Clear(bgColor);
	}

	void Renderer::clearZBuffer() {
		for (int x = 0; x < zbuffer->GetLength(0); x++) {
			for (int y = 0; y < zbuffer->GetLength(1); y++) {
				zbuffer->SetValue(INFINITY, x, y);
			}
		}
	}

	// True, if a polygon is back-faced.
	bool Renderer::toClip(const Polygon &poly) {
		// don't draw a poly if it's entirely outside or with area = 0
		if (Util::area(poly) < 0.01) {
			return true;
		}
		for (const Vector4 &vert : poly.vertices) {
			if (vert.x >= 0 || vert.x < viewportX || vert.y >= 0 || vert.y < viewportY) {
				// draw a poly if at least one vertex is inside
				return false;
			}
		}
		return true;
	}

	bool Renderer::isVisible(const Polygon &pol) {
		// a face is visible is a dot-product of its normal vector
		// and the first vertex of the triangle is less than zero (here's reversed)
		Vector3 norm = Util::normal(pol.vertices[0].toVec3(), pol.vertices[1].toVec3(), pol.vertices[2].toVec3());
		Vector3 v0 = pol.vertices[0].toVec3();
		Vector3 camPos = perspective ? Vector3() : Vector3(v0.x, v0.y, -1.f);
		bool visible = (camPos - v0).dot(norm) > 0.5;
		return visible;
	}

	// Calculates the colors in the vertices of a polygon using the Gouraud shading.
	std::vector<Vector4> Renderer::getGouraudColors(const GL::Polygon &poly, Light lightSource, Material material) {
		// Gouraud model lighting calculations:
		std::vector<Vector4> colors;
		for (int i = 0; i < 3; i++) {
			// diffuse lighting
			Vector3 lightDir = (lightSource.position - poly.vertices[i].toVec3()).normalized();
			float diff = Util::max(poly.normals[i].dot(lightDir), 0.f);
			Vector4 diffuse = lightSource.getDiffuseColor() * (material.getDiffuseColor() * diff);
			// specular lighting
			Vector3 viewDir = (-poly.vertices[i].toVec3()).normalized();
			Vector3 reflectDir = Util::reflect(-lightDir, poly.normals[i]);
			float spec = pow(Util::max(viewDir.dot(reflectDir), 0.f), material.getShininess());
			Vector4 specular = lightSource.getSpecularColor() * (material.getSpecularColor() * spec);
			colors.push_back(diffuse + specular);
		}
		return colors;
	}

	void Renderer::renderObject(const SceneObject &obj, const Matrix4 &model, const Matrix4 &view, const Matrix4& proj, 
		const Light &lightSource, bool wireframe, bool solid) 
	{
		//Material material = obj.getMaterial();
		Matrix4 modelView = view * model;
		Matrix3 normalTransform = modelView.inverted().transposed().toMat3();
		for (const GL::Polygon &pol : obj.polygons) {
			// get the polygon transformed (world and camera coords).
			GL::Polygon cameraTransformed = pol.getTransformed(modelView, normalTransform);
			// check visibility is back-culling is on, don't draw if is a back face
			if (cullFace && !isVisible(cameraTransformed)) {
				continue;
			}
			// get the polygon transformed (clip space). if ortho, don't forget to apply the view matrix.
			GL::Polygon transformed = cameraTransformed.getTransformed(perspective ? proj : proj * view, Matrix3());
			viewportTransform(transformed);
			if (!toClip(transformed)) {
				if (wireframe) { drawPolygon(transformed); }
				if (solid) { 
					// another one for lighting calculations
					GL::Polygon worldTransformed = pol.getTransformed(modelView, normalTransform);
					std::vector<Vector4> gouraudColors = { Vector4(), Vector4(), Vector4() };
					if (lightSource.mode == LightMode::GOURAUD) {
						// doing gouraud lighting calculations here in a 'vertex shader'
						gouraudColors = getGouraudColors(worldTransformed, lightSource, obj.getMaterial());
					}
					// essentially, entering fragment shader
					fillPolygon(transformed, worldTransformed, lightSource, obj.getMaterial(), gouraudColors);
				}
			}
		}
	}

	// Draws a line using the Bresenham's algorithm with Z-testing.
	void Renderer::drawLine(const Vector3 &from, const Vector3 &to) {
		int x = from.x, y = from.y;

		int dx = abs(to.x - x);
		int dy = abs(to.y - y);
		int sx = Util::sign(to.x - x);
		int sy = Util::sign(to.y - y);

		// swap the deltas if 2, 3, 6 or 7th octant
		bool isSwap = dy > dx;
		if (isSwap) Util::swap(dx, dy);

		int e = 2 * dy - dx;

		// start drawing
		for (int i = 1; i <= dx; i++, e += 2 * dy) {
			// calculate z-value in pixel
			float t = (Vector3(x, y, 0.f) - Vector3(from.x, from.y, 0.f)).length() / (Vector3(to.x, to.y, 0.f) - Vector3(from.x, from.y, 0.f)).length();
			float z = (1 - t) * from.z + t * to.z;
			drawPoint(x, y, z, isSelectedObject ? selectedBrush : wfBrush);

			// determine if need to change the direction
			while (e >= 0) {
				if (isSwap) { x += sx; }
				else { y += sy; }
				e -= 2 * dx;
			}

			// increment y or x each step, depending on the octant
			if (isSwap) { y += sy; }
			else { x += sx; }
		}
	}

	// Draw a single pixel with a Z-test.
	void Renderer::drawPoint(int x, int y, float z, SolidBrush ^br) {
		if (x >= 0 && x < viewportX && y >= 0 && y < viewportY && z > (perspective ? -1 : 0) && z < 1) {
			// z test
			if (z < zbuffer[x, y]) {
				zbuffer[x, y] = z;
				graphics->FillRectangle(br, x, y, 1, 1);
			}
		}
	}

	// Draw a wireframe of a polygon.
	void Renderer::drawPolygon(const GL::Polygon &pol) {
		drawLine(pol.vertices[0].toVec3(), pol.vertices[1].toVec3());
		drawLine(pol.vertices[1].toVec3(), pol.vertices[2].toVec3());
		drawLine(pol.vertices[2].toVec3(), pol.vertices[0].toVec3());
	}

	// Fills and shades a polygon.
	void Renderer::fillPolygon(const Polygon &poly, const Polygon &worldPoly, const Light &lightSource,
		const Material &material, std::vector<Vector4> gouraudColors) {
		// copy vectors first
		Vector3 first = poly.vertices[0].toVec3(), second = poly.vertices[1].toVec3(), third = poly.vertices[2].toVec3();
		// in world coordinates (for lighting calculations) 
		Vector3 firstW = worldPoly.vertices[0].toVec3(), secondW = worldPoly.vertices[1].toVec3(), thirdW = worldPoly.vertices[2].toVec3();
		// normals (in world coordinates, for lighting calculations)
		Vector3 firstNorm = worldPoly.normals[0], secondNorm = worldPoly.normals[1], thirdNorm = worldPoly.normals[2];
		Vector4 firstColor = poly.colors[0], secondColor = poly.colors[1], thirdColor = poly.colors[2];

		// deformed triangles not needed to be rendered
		if ((first.y == second.y && first.y == third.y) || (first.x == second.x && first.x == third.x)) {
			return;
		}

		// sort the vertices, third -> second -> first
		if (first.y > second.y) {
			Util::swap(first, second);
			Util::swap(firstW, secondW);
			Util::swap(firstColor, secondColor);
			Util::swap(firstNorm, secondNorm);
			Util::swap(gouraudColors[0], gouraudColors[1]);
		}
		if (first.y > third.y) {
			Util::swap(first, third);
			Util::swap(firstW, thirdW);
			Util::swap(firstColor, thirdColor);
			Util::swap(firstNorm, thirdNorm);
			Util::swap(gouraudColors[0], gouraudColors[2]);
		}
		if (second.y > third.y) {
			Util::swap(second, third);
			Util::swap(secondW, thirdW);
			Util::swap(secondColor, thirdColor);
			Util::swap(secondNorm, thirdNorm);
			Util::swap(gouraudColors[1], gouraudColors[2]);
		}

		// memorize z-values
		Vector3 zs(first.z, second.z, third.z);
		// we're working in the 2d space, so we get rid of z
		first.z = second.z = third.z = 0.f;
		// discard very narrow triangles
		if (first.equalEpsilon(second, 0.5f) || second.equalEpsilon(third, 0.5f) || third.equalEpsilon(first, 0.5f)) {
			return;
		}

		// ambient lighting
		Vector4 ambient = lightSource.getAmbientColor() * material.getAmbientColor();

		int totalHeight = third.y - first.y;
		// scan down to up
		for (int i = 0; i < totalHeight; i++) {
			// line is off the screen, don't draw
			if (first.y >= viewportY) return;
			if (first.y + i < 0) continue;
			bool secondHalf = i > second.y - first.y || second.y == first.y;
			int segmentHeight = secondHalf ? third.y - second.y : second.y - first.y;
			// current height to overall height ratio
			float alpha = (float)i / totalHeight;
			// current segment height to overall segment height ratio
			float beta = (float)(i - (secondHalf ? second.y - first.y : 0)) / segmentHeight;
			// find current intersection point between scanline and first-to-third side
			Vector3 A = first + (third - first) * alpha;
			// find current intersection point between scanline and first-to-second (or second-to-third) side
			Vector3 B = secondHalf ? second + (third - second) * beta : first + (second - first) * beta;
			// A should be on the left
			if (A.x > B.x) Util::swap(A, B);
			// the line is off the screen, don't draw
			if (A.x > viewportX || B.x <= 0) continue;
			if (A.x < 0) A.x = 0;
			if (B.x > viewportX) B.x = viewportX - 1;
			// fill the line between A and B
			for (int j = A.x; j <= B.x; j++) {
				// find barycentric coordinates for interpolation
				try {
					Vector3 coordinates = Util::barycentric2d(Vector3(j, first.y + i, 0.f), first, second, third);
					// determine a color
					Vector4 col = firstColor * coordinates.x + secondColor * coordinates.y + thirdColor * coordinates.z;
					// determine a fragment position (in world coords)
					Vector3 fragPos = (firstW * coordinates.x + secondW * coordinates.y + thirdW * coordinates.z);
					// determine an interpolated normal
					Vector3 fragNormal;
					switch (lightSource.mode) {
					case LightMode::FLAT:
						fragNormal = ((firstNorm + secondNorm + thirdNorm) / 3.f).normalized();
						break;
					case LightMode::PHONG:
						// Phong model shading normal interpolation:
						fragNormal = (firstNorm * coordinates.x + secondNorm * coordinates.y + thirdNorm * coordinates.z).normalized();
						break;
					}

					if (lightSource.mode != LightMode::GOURAUD) {
						// diffuse lighting
						Vector3 lightDir = (lightSource.position - fragPos).normalized();
						float diff = Util::max(fragNormal.dot(lightDir), 0.f);
						Vector4 diffuse = lightSource.getDiffuseColor() * (material.getDiffuseColor() * diff);

						// specular lighting
						Vector3 viewDir = (-fragPos).normalized();
						Vector3 reflectDir = Util::reflect(-lightDir, fragNormal);
						float spec = pow(Util::max(viewDir.dot(reflectDir), 0.f), material.getShininess());
						Vector4 specular = lightSource.getSpecularColor() * (material.getSpecularColor() * spec);

						// resulting
						col = Util::clampVec((ambient + (lightSource.on ? diffuse + specular : Vector4())) * col, 0.f, 1.f);
					}
					else {
						// using pre-computed vertex color values
						Vector4 sumLight = gouraudColors[0] * coordinates.x + gouraudColors[1] * coordinates.y + gouraudColors[2] * coordinates.z;
						col = Util::clampVec(ambient + (lightSource.on ? sumLight : Vector4()) * col , 0.f, 1.f);
					}

					surfaceBrush->Color = Color::FromArgb(255, col.x * 255, col.y * 255, col.z * 255);

					// find interpolated z-value
					float z = coordinates.dot(zs);
					//surfaceBrush->Color = Color::FromArgb(255, z * 255, z * 255, z * 255);
					drawPoint(j, first.y + i, z, surfaceBrush);
				}
				catch (std::exception &e) {
					// deformed triangle or something else, don't draw
					return;
				}
			}
		}
	}

	// Translate from homonegenous coordinates (w-division) and map to the viewport.
	void Renderer::viewportTransform(GL::Polygon &poly) {
		poly.vertices[0] = NDCtoViewport(poly.vertices[0].fromHomogeneous());
		poly.vertices[1] = NDCtoViewport(poly.vertices[1].fromHomogeneous());
		poly.vertices[2] = NDCtoViewport(poly.vertices[2].fromHomogeneous());
	}

	// Remaps coordinates from [-1, 1] to the [0, viewport] space. 
	Vector3 Renderer::NDCtoViewport(const Vector3 &vertex) {
		return Vector3((int)((1.f + vertex.x) * viewportX / 2.f),
			           (int)((1.f - vertex.y) * viewportY / 2.f),
			            vertex.z);
	}

	void Renderer::setGraphics(Graphics ^g) {
		graphics = g;
	}

	Color Renderer::getBGColor() {
		return bgColor;
	}

	Color Renderer::getWFColor() {
		return wfBrush->Color;
	}

	Color Renderer::getSelectedColor() {
		return selectedBrush->Color;
	}

	void Renderer::setBGColor(Color _col) {
		bgColor = _col;
	}

	void Renderer::setWFColor(Color _col) {
		wfBrush->Color = _col;
	}

	void Renderer::setSelectedColor(Color _col) {
		selectedBrush->Color = _col;
	}

	void Renderer::setProjection(bool _perspective) {
		perspective = _perspective;
	}

	void Renderer::setFaceCulling(bool _cullFace) {
		cullFace = _cullFace;
	}

}