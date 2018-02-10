#pragma once

#include "Vector3.h"
#include "Light.h"
#include "Material.h"
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
		void renderObject(const SceneObject &obj, const Matrix4 &model, const Matrix4 &view,
			const Matrix4 &proj, const Light &light, bool wireframe, bool solid);
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

		const Color DEFAULT_BG_COLOR = Color::Black;
		const Color DEFAULT_WF_COLOR = Color::White;
		const Color DEFAULT_SELECTED_COLOR = Color::Blue;

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
		bool toClip(const Polygon & poly);
		bool isVisible(const Polygon & poly);
		std::vector<Vector4> getGouraudColors(const GL::Polygon &poly, Light lightSource, Material material);
		void drawLine(const Vector3 &from, const Vector3 &to);
		void drawPoint(int x, int y, float z, SolidBrush ^b);
		void drawPolygon(const GL::Polygon &poly);
		void fillPolygon(const GL::Polygon &poly, const GL::Polygon &worldPoly, const Light &lightSource, 
			const Material &material, std::vector<Vector4> gouraudColors);
		void viewportTransform(GL::Polygon & poly);
		Vector3 NDCtoViewport(const Vector3 &vertex);
	};
}
