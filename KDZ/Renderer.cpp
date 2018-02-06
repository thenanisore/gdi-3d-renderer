#include "Renderer.h"

#include <climits>

namespace GL {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	Renderer::Renderer(Graphics ^im, Color _bgColor, Color _wfColor, int viewportWidth, int viewportHeight) 
		: graphics(im), bgColor(_bgColor), wfColor(_wfColor) {
		pen = gcnew Pen(wfColor);
		brush = gcnew SolidBrush(wfColor);
		// initialize a z-buffer
		zbuffer = gcnew array<int, 2>(viewportWidth, viewportHeight);
		setViewport(viewportWidth, viewportHeight);
	}

	void Renderer::setViewport(int width, int height) {
		viewportX = width;
		viewportY = height;
	}

	void Renderer::drawAxes(Vector3 origin, Vector3 x_axis, Vector3 y_axis, Vector3 z_axis, bool grid) {
		drawLine(origin, x_axis);
		drawLine(origin, y_axis);
		drawLine(origin, z_axis);
	}

	void Renderer::clearScreen() {
		graphics->Clear(bgColor);
	}

	void Renderer::clearZBuffer() {
		for (int x = 0; x < zbuffer->GetLength(0); x++) {
			for (int y = 0; y < zbuffer->GetLength(1); y++) {
				zbuffer->SetValue(INT_MIN, x, y);
			}
		}
	}

	void Renderer::renderObject(const SceneObject &obj, const Matrix4& transformMatrix) {
		// return if doesn't contain at least a triangle
		if (obj.polygons.size() < 3) return;

		for (GL::Polygon pol : obj.polygons) {
			// the ndc vector memorizes the vectors already in clip space
			std::vector<Vector3> ndc{
				NDCtoViewport((transformMatrix * Vector4(pol.vertices[0])).fromHomogeneous())
			};
			for (int i = 0; i < pol.vertices.size() - 1; i++) {
				// transform 3D world coordinates to the NDC
				ndc.push_back(NDCtoViewport((transformMatrix * pol.vertices[i + 1]).fromHomogeneous()));
				// draw the lines
				graphics->DrawLine(pen, ndc[i].x, ndc[i].y, ndc[i + 1].x, ndc[i + 1].y);
			}
			// draw the last line
			graphics->DrawLine(pen, ndc[ndc.size() - 1].x, ndc[ndc.size() - 1].y, ndc[0].x, ndc[0].y);
		}
	}

	void Renderer::setGraphics(Graphics ^g) {
		graphics = g;
	}

	void Renderer::drawLine(const Vector3 &from, const Vector3 &to) {
		// test code
		// TODO: implement line drawing algorithm
		graphics->DrawLine(pen, from.x, from.y, to.x, to.y);
	}

	// TODO: Z-test
	void Renderer::drawPoint(int x, int y) {
		graphics->FillRectangle(brush, x, y, 1, 1);
	}

	// Remaps the coordinates from [-1, 1] to the [0, viewport] space. 
	Vector3 Renderer::NDCtoViewport(const Vector3 &vertex) {
		return Vector3((1.0f + vertex.x) * viewportX / 2.0f, (1.0f - vertex.y) * viewportY / 2.0f, 0.0f);
	}
}