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
		lightColor = DEFAULT_LIGHT_COLOR;
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

	void Renderer::drawAxes(Matrix4 transformMatrix, bool grid) {
		// TODO: rework
		// get correct axes' coordinates 
		Vector3 origin = NDCtoViewport((transformMatrix * Vector4(0.0f, 0.0f, 0.0f, 1.0f)).fromHomogeneous());
		Vector3 x = NDCtoViewport((transformMatrix * Vector4(50.0f, 0.0f, 0.0f, 1.0f)).fromHomogeneous());
		Vector3 y = NDCtoViewport((transformMatrix * Vector4(0.0f, 50.0f, 0.0f, 1.0f)).fromHomogeneous());
		Vector3 z = NDCtoViewport((transformMatrix * Vector4(0.0f, 0.0f, 50.0f, 1.0f)).fromHomogeneous());
		drawLine(origin, x);
		drawLine(origin, y);
		drawLine(origin, z);
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

	bool Renderer::toClip(const Polygon &pol) {
		// don't draw a poly if it's entirely outside
		for (const Vector4 &vert : pol.vertices) {
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
		Vector3 norm = pol.normals[0];
		Vector3 v0 = pol.vertices[0].toVec3();
		Vector3 camPos = perspective ? Vector3() : Vector3(v0.x, v0.y, -1.f);
		bool visible = (camPos - v0).dot(norm) >= 0;
		return visible;
	}

	void Renderer::renderObject(const SceneObject &obj, const Matrix4 &model, const Matrix4 &view, const Matrix4& proj, 
		const Vector3 &cameraPos, const Vector3 &lightPos, bool wireframe, bool solid) 
	{
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
					fillPolygon(transformed, worldTransformed, cameraPos, lightPos);
				}
			}
		}
	}

	// returns a signum of x
	inline int sign(int x) {
		return (x > 0) - (x < 0);
	}

	// swaps two numbers in-place
	template<typename T>
	void swap(T &x, T &y) {
		T t = x; x = y; y = t;
	}

	float getZ(float x, float y, const Vector3 &p, const Vector3 &normal) {
		return p.z - (normal.x * (x - p.x) + normal.y * (y - p.y)) / normal.z;
	}

	// Draws a line using the Bresenham's algorithm with Z-testing.
	void Renderer::drawLine(const Vector3 &from, const Vector3 &to) {
		int x = from.x, y = from.y;

		int dx = abs(to.x - x);
		int dy = abs(to.y - y);
		int sx = sign(to.x - x);
		int sy = sign(to.y - y);

		// swap the deltas if 2, 3, 6 or 7th octant
		bool isSwap = dy > dx;
		if (isSwap) swap(dx, dy);

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

	void Renderer::drawPoint(int x, int y, float z, SolidBrush ^br) {
		if (x >= 0 && x < viewportX && y >= 0 && y < viewportY && z > -1 && z < 1) {
			// z test
			if (z < zbuffer[x, y]) {
				zbuffer[x, y] = z;
				graphics->FillRectangle(br, x, y, 1, 1);
			}
		}
	}

	void Renderer::drawPolygon(const GL::Polygon &pol) {
		drawLine(pol.vertices[0].toVec3(), pol.vertices[1].toVec3());
		drawLine(pol.vertices[1].toVec3(), pol.vertices[2].toVec3());
		drawLine(pol.vertices[2].toVec3(), pol.vertices[0].toVec3());
	}

	float max(float a, float b) { return a > b ? a : b; }
	float min(float a, float b) { return a < b ? a : b; }

	void clampVec(Vector3 &vec, float min, float max) {
		if (vec.x < min) vec.x = min;
		if (vec.y < min) vec.y = min;
		if (vec.z < min) vec.z = min;
		if (vec.x > max) vec.x = max;
		if (vec.y > max) vec.y = max;
		if (vec.z > max) vec.z = max;
	}

	void Renderer::fillPolygon(const Polygon &poly, const Polygon &worldPoly, const Vector3 &cameraPos, const Vector3 &lightPos) {
		// copy vectors first
		Vector3 first = poly.vertices[0].toVec3(), second = poly.vertices[1].toVec3(), third = poly.vertices[2].toVec3();
		// in world coordinates (for lighting calculations) 
		Vector3 firstW = worldPoly.vertices[0].toVec3(), secondW = worldPoly.vertices[1].toVec3(), thirdW = worldPoly.vertices[2].toVec3();
		// normals (in world coordinates, for lighting calculations)
		Vector3 firstNorm = worldPoly.normals[0], secondNorm = worldPoly.normals[1], thirdNorm = worldPoly.normals[2];
		Vector4 firstColor = poly.colors[0], secondColor = poly.colors[1], thirdColor = poly.colors[2];

		// deformed triangles not needed to be rendered
		if ((first.y == second.y && first.y == third.y) || (first.x == second.x && first.x == third.x))
			return;

		// sort the vertices, third -> second -> first
		if (first.y > second.y) {
			swap(first, second);
			swap(firstW, secondW);
			swap(firstColor, secondColor);
			swap(firstNorm, secondNorm);
		}
		if (first.y > third.y) {
			swap(first, third);
			swap(firstW, thirdW);
			swap(firstColor, thirdColor);
			swap(firstNorm, thirdNorm);
		}
		if (second.y > third.y) {
			swap(second, third);
			swap(secondW, thirdW);
			swap(secondColor, thirdColor);
			swap(secondNorm, thirdNorm);
		}

		// memorize z-values
		Vector3 zs(first.z, second.z, third.z);
		// we're working in the 2d space, so we get rid of z
		first.z = second.z = third.z = 0.f;
		// discard very narrow triangles
		if (first.equalEpsilon(second, 0.5f) || second.equalEpsilon(third, 0.5f) || third.equalEpsilon(first, 0.5f)) {
			return;
		}
		int totalHeight = third.y - first.y;
		// scan down to up
		for (int i = 0; i < totalHeight; i++) {
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
			if (A.x > B.x) swap(A, B);
			// fill the line between A and B
			for (int j = A.x; j <= B.x; j++) {
				// find barycentric coordinates for interpolation
				Vector3 coordinates = Util::barycentric2d(Vector3(j, first.y + i, 0.f), first, second, third);
				// determine a color
				Vector3 col = (firstColor * coordinates.x + secondColor * coordinates.y + thirdColor * coordinates.z).toVec3();
				// determine a fragment position (in world coords)
				Vector3 fragPos = (firstW * coordinates.x + secondW * coordinates.y + thirdW * coordinates.z);
				// determine an interpolated normal
				Vector3 fragNormal = (firstNorm * coordinates.x + secondNorm * coordinates.y + thirdNorm * coordinates.z).normalized();
				// map negative colors to 0, >1 to 1

				// lighting calculations
				float ambientStrength = 0.1f;
				Vector3 ambient = Util::colorToVec(lightColor).toVec3() * ambientStrength;
				// diffuse lighting
				float diffuseStrength = 0.8f;
				Vector3 lightDir = (-fragPos).normalized();
				float diff = max(fragNormal.dot(lightDir), 0.f);
				Vector3 diffuse = Util::colorToVec(lightColor).toVec3() * diff * diffuseStrength;
				// specular lighting
				float specularStrength = 0.7f;
				Vector3 viewDir = (-fragPos).normalized();
				Vector3 reflectDir = Util::reflect(-lightDir, fragNormal).normalized();
				float spec = pow(max(viewDir.dot(reflectDir), 0.f), 8);
				Vector3 specular = Util::colorToVec(lightColor).toVec3() * specularStrength * spec;
				// resulting
				col = (diffuse + ambient + specular) * col;
				clampVec(col, 0, 1.f);
				surfaceBrush->Color = Color::FromArgb(255, col.x * 255, col.y * 255, col.z * 255);

				// find interpolated z-value
				float z = coordinates.dot(zs);
				//surfaceBrush->Color = Color::FromArgb(255, z * 255, z * 255, z * 255);
				drawPoint(j, first.y + i, z, surfaceBrush);
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


	// test code
	void Renderer::ztofile() {
			std::ofstream myfile;
			myfile.open("log.txt");
			for (int x = viewportX / 3; x < 2 * viewportX / 3; x++) {
				for (int y = viewportY / 3; y < 2 * viewportY / 3; y++) {
					if (zbuffer[x, y] == INFINITY) {
						myfile << "| |";
					} else {
						myfile << "|" << zbuffer[x, y] << "|";
					}
				}
				myfile << std::endl;
			}
			myfile.close();
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

	Color Renderer::getLightColor() {
		return lightColor;
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

	void Renderer::setLightColor(Color _col) {
		lightColor = _col;
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