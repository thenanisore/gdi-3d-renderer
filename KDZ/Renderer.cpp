#include "Renderer.h"

#include <climits>

namespace GL {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	Renderer::Renderer(Graphics ^im, int viewportWidth, int viewportHeight) : graphics(im), 
		bgColor(Color::White), wfColor(Color::Black), selectedColor(Color::Blue)
	{
		wfPen = gcnew Pen(wfColor, 3);
		selectedPen = gcnew Pen(selectedColor, 3);
		wfBrush = gcnew SolidBrush(wfColor);
		selectedBrush = gcnew SolidBrush(selectedColor);
		// initialize z-buffer
		zbuffer = gcnew array<int, 2>(viewportWidth, viewportHeight);
		setViewport(viewportWidth, viewportHeight);
	}

	void Renderer::setViewport(int width, int height) {
		viewportX = width;
		viewportY = height;
	}

	float Renderer::getViewportAspect() {
		return (float)viewportX / (float)viewportY;
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

	void Renderer::renderObject(const SceneObject &obj, const Matrix4& transformMatrix, bool wireframe, bool solid) {
		for (GL::Polygon pol : obj.polygons) {
			GL::Polygon transformed = pol.transform(transformMatrix);
			Vector3 first = NDCtoViewport(transformed.vertices[0].fromHomogeneous());
			Vector3 second = NDCtoViewport(transformed.vertices[1].fromHomogeneous());
			Vector3 third = NDCtoViewport(transformed.vertices[2].fromHomogeneous());
			if (wireframe) drawPolygon(first, second, third);
			if (solid) fillPolygon(first, second, third);
		}
	}

	void Renderer::setGraphics(Graphics ^g) {
		graphics = g;
	}

	Color Renderer::getBGColor() {
		return bgColor;
	}

	Color Renderer::getWFColor() {
		return wfColor;
	}

	Color Renderer::getSelectedColor() {
		return selectedColor;
	}

	void Renderer::setBGColor(Color _col) {
		bgColor = _col;
	}

	void Renderer::setWFColor(Color _col) {
		wfColor = _col;
		wfPen->Color = wfColor;
		wfBrush = gcnew SolidBrush(wfColor);
	}

	void Renderer::setSelectedColor(Color _col) {
		selectedColor = _col;
		selectedPen->Color = selectedColor;
		selectedBrush = gcnew SolidBrush(selectedColor);
	}

	//int outCode(int x, int y, int X1, int X2, int Y1, int Y2) {
	//	int code = 0;
	//	if (x < X1) code |= 0x01;
	//	if (x < X2) code |= 0x02;
	//	if (x < Y1) code |= 0x04;
	//	if (x < Y2) code |= 0x08;
	//	return code;
	//}

	// returns a signum of x
	inline int sign(int x) {
		return (x > 0) - (x < 0);
	}

	// swaps two numbers in-place
	template<typename T>
	void swap(T &x, T &y) {
		T t = x; x = y; y = t;
	}

	// Draws a line using the Bresenham's algorithm
	void Renderer::drawLine(const Vector3 &from, const Vector3 &to) {
		int x = from.x, y = from.y;
		Vector3 current(x, y, 0);

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
			drawPoint(x, y);

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

	void Renderer::drawPoint(int x, int y) {
		graphics->FillRectangle(wfBrush, x, y, 1, 1);
	}

	void Renderer::drawPolygon(const Vector3 &first, const Vector3 &second, const Vector3 &third) {
		drawLine(first, second);
		drawLine(second, third);
		drawLine(third, first);
	}

	void Renderer::fillPolygon(const Vector3 &_first, const Vector3 &_second, const Vector3 &_third) {
		// deformed triangles not needed to be rendered
		if (_first.y == _second.y && _first.y == _third.y) return;
		// copy vectors first
		Vector3 first(_first);
		Vector3 second(_second);
		Vector3 third(_third);
		// sort the vertices
		if (first.y > second.y) swap(first, second);
		if (first.y > third.y) swap(first, third);
		if (second.y > third.y) swap(second, third);
		int totalHeight = third.y - first.y;
		for (int i = 0; i < totalHeight; i++) {
			bool secondHalf = i > second.y - first.y || second.y == first.y;
			int segmentHeight = secondHalf ? third.y - second.y : second.y - first.y;
			float alpha = (float)i / totalHeight;
			float beta = (float)(i - (secondHalf ? second.y - first.y : 0)) / segmentHeight;
			Vector3 A = first + (third - first) * alpha;
			Vector3 B = secondHalf ? second + (third - second) * beta : first + (second - first) * beta;
			if (A.x > B.x) swap(A, B);
			for (int j = A.x; j <= B.x; j++) {
				drawPoint(j, first.y + i);
			}
		}
	}

	// Remaps the coordinates from [-1, 1] to the [0, viewport] space. 
	Vector3 Renderer::NDCtoViewport(const Vector3 &vertex) {
		return Vector3((1.0f + vertex.x) * viewportX / 2.0f, (1.0f - vertex.y) * viewportY / 2.0f, vertex.z);
	}
}