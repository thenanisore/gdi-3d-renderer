#pragma once

#include "Vector3.h"
#include "SceneObject.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	// The Renderer class contains functions that rasterize SceneObjects on the specified Graphics object.
	ref class Renderer
	{
	public:
		Renderer(Graphics ^im, int viewportWidth, int viewportHeight);
		void setViewport(int width, int height);
		float getViewportAspect();
		void drawAxes(Vector3 origin, Vector3 x_axis, Vector3 y_axis, Vector3 z_axis, bool grid);
		void clearScreen();
		void clearZBuffer();
		void renderObject(const SceneObject &obj, const Matrix4 &transformMatrix, bool wireframe, bool solid);
		void setGraphics(Graphics ^g);

		// color getters/setters:

		Color getBGColor();
		Color getWFColor();
		Color getSelectedColor();
		void setBGColor(Color _col);
		void setWFColor(Color _col);
		void setSelectedColor(Color _col);

	private:
		Graphics ^graphics;
		Color bgColor;
		Color wfColor;
		Color selectedColor;
		Pen ^wfPen;
		Pen ^selectedPen;
		Brush ^wfBrush;
		Brush ^selectedBrush;
		int viewportX;
		int viewportY;
		array<int, 2> ^zbuffer;
		void drawLine(const Vector3 &from, const Vector3 &to);
		void drawPoint(int x, int y);
		void drawPolygon(const Vector3 &first, const Vector3 &second, const Vector3 &third);
		void fillPolygon(const Vector3 &first, const Vector3 &second, const Vector3 &third);
		Vector3 NDCtoViewport(const Vector3 &vertex);
	};
}
