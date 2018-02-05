#include "Renderer.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	Renderer::Renderer(Graphics ^im, Color ^col, Pen ^p, Brush ^br) : graphics(im), color(col), pen(p), brush(br) { }

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
		// TODO: clear z buffer
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
}