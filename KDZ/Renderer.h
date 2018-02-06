#pragma once

#include "Vector3.h"
#include "SceneObject.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;

	// The Renderer class ???
	ref class Renderer
	{
	public:
		// TODO: pass in graphics and mesh color, I don't know yet
		Renderer(Graphics ^im, Color _bgColor, Color _wfColor, int viewportWidth, int viewportHeight);
		void setViewport(int width, int height);
		void drawAxes(Vector3 origin, Vector3 x_axis, Vector3 y_axis, Vector3 z_axis, bool grid);
		void clearScreen();
		void clearZBuffer();
		void renderObject(const SceneObject &obj, const Matrix4 &transformMatrix);
		void setGraphics(Graphics ^g);

	private:
		Graphics ^graphics;
		Color bgColor;
		Color wfColor;
		Pen ^pen;
		Brush ^brush;
		int viewportX;
		int viewportY;
		array<int, 2> ^zbuffer;
		void drawLine(const Vector3 &from, const Vector3 &to);
		void drawPoint(int x, int y);
		Vector3 NDCtoViewport(const Vector3 &vertex);
	};
}
