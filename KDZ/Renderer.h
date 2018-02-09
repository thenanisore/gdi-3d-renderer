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
		void drawAxes(Matrix4 transformMatrix, bool grid);
		void clearScreen();
		void clearZBuffer();
		void renderObject(const SceneObject &obj, const Matrix4 &proj, 
			const Matrix4 &modelView, const Matrix3 &normalMatrix, bool wireframe, bool solid);
		void ztofile();
		void setGraphics(Graphics ^g);

		// color getters/setters:

		Color getBGColor();
		Color getWFColor();
		Color getSelectedColor();
		void setBGColor(Color _col);
		void setWFColor(Color _col);
		void setSelectedColor(Color _col);
		bool isSelectedObject;
		void setProjection(bool _perspective);
		void setFaceCulling(bool _cullFace);

	private:
		Graphics ^graphics;
		Color bgColor;
		SolidBrush ^wfBrush;
		SolidBrush ^selectedBrush;
		SolidBrush ^surfaceBrush;
		bool perspective;
		bool cullFace;
		int viewportX;
		int viewportY;
		array<float, 2> ^zbuffer;
		bool toClip(const Polygon & pol);
		bool isVisible(const Polygon & pol);
		void drawLine(const Vector3 &from, const Vector3 &to);
		void drawPoint(int x, int y, float z, SolidBrush ^b);
		void drawPolygon(const GL::Polygon &pol);
		void fillPolygon(const GL::Polygon &pol);
		void viewportTransform(GL::Polygon & poly);
		Vector3 NDCtoViewport(const Vector3 &vertex);
	};
}
