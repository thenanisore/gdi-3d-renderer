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

	void Renderer::renderObject(const SceneObject &obj, const Matrix4& transformMatrix) {
		// return if doesn't contain at least a triangle
		if (obj.polygons.size() < 3) return;

		for (GL::Polygon pol : obj.polygons) {
			// the ndc vector memorizes the vectors already in clip space
			std::vector<Vector3> ndc{
				NDCtoViewport((transformMatrix * pol.vertices[0]).fromHomogeneous())
			};
			for (int i = 0; i < pol.vertices.size() - 1; i++) {
				// transform 3D world coordinates to the NDC
				ndc.push_back(NDCtoViewport((transformMatrix * pol.vertices[i + 1]).fromHomogeneous()));
				// draw the lines
				drawLine(ndc[i], ndc[i + 1]);
			}
			// draw the last line
			drawLine(ndc[ndc.size() - 1], ndc[0]);
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

	void Renderer::drawLine(const Vector3 &from, const Vector3 &to) {
		// test code
		// TODO: implement line drawing algorithm
		graphics->DrawLine(wfPen, from.x, from.y, to.x, to.y);
	}

	// TODO: Z-test
	void Renderer::drawPoint(int x, int y) {
		graphics->FillRectangle(wfBrush, x, y, 1, 1);
	}

	// Remaps the coordinates from [-1, 1] to the [0, viewport] space. 
	Vector3 Renderer::NDCtoViewport(const Vector3 &vertex) {
		return Vector3((1.0f + vertex.x) * viewportX / 2.0f, (1.0f - vertex.y) * viewportY / 2.0f, vertex.z);
	}
}