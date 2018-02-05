#include "Renderer.h"

#include <climits>

namespace GL {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	Renderer::Renderer(Graphics ^im, Color ^col, int width, int height) : graphics(im), color(col) {
		pen = gcnew Pen(color->Blue);
		brush = gcnew SolidBrush(color->Blue);
		// initialize a z-buffer
		zbuffer = gcnew array<int, 2>(width, height);
		setViewport(width, height);
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
		graphics->Clear(color->GhostWhite);
	}

	void Renderer::clearZBuffer() {
		for (int x = 0; x < zbuffer->GetLength(0); x++) {
			for (int y = 0; y < zbuffer->GetLength(1); y++) {
				zbuffer->SetValue(INT_MIN, x, y);
			}
		}
	}

	void Renderer::renderObject(const SceneObject &obj) {
		for (GL::Polygon pol : obj.polygons) {
			for (int i = 0; i < pol.vertices.size() - 1; i++) {
				graphics->DrawLine(pen, pol.vertices[i].x, pol.vertices[i].y, pol.vertices[i + 1].x, pol.vertices[i + 1].y);
			}
			graphics->DrawLine(pen, pol.vertices[pol.vertices.size() - 1].x, pol.vertices[pol.vertices.size() - 1].y, pol.vertices[0].x, pol.vertices[0].y);
		}
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
		return Vector3((1.0f + vertex.x) * viewportX / 2.0f, (1.0f + vertex.y) * viewportY / 2.0f, 0.0f);
	}
}