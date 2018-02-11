/*
* Студент: Иванов Олег Владимирович
* Группа: 141/1, 4 курс
* КДЗ #1, Вариант 1: 3D-сцена в GDI.
*
* Класс Renderer: растеризатор, содержит функции перевода 3D-объектов в 2D-изображения (преобразование вершин, затенение).
*/

#pragma once

#include "Vector3.h"
#include "Light.h"
#include "Material.h"
#include "SceneObject.h"

namespace GL {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	// The Renderer class contains functions that rasterize SceneObjects on the specified Graphics object.
	ref class Renderer
	{
	public:
		Renderer(Graphics ^im, int viewportWidth, int viewportHeight);
		void setViewport(int width, int height);
		// Returns a width/height ratio.
		float getViewportAspect();
		// Clears a screen with a current background color.
		void clearScreen();
		// Clears a depth buffer.
		void clearZBuffer();
		// Transforms, renders and shades a SceneObject.
		void renderObject(const SceneObject &obj, const Matrix4 &model, const Matrix4 &view,
			const Matrix4 &proj, const Light &light, bool wireframe, bool solid);
		void setGraphics(Graphics ^g);
		// Loads a texture to the renderer.
		void addTexture(Bitmap ^tex);
		// Returns the number of the currently loaded textures.
		size_t getTextureNumber();
		// Returns a selected texture.
		Bitmap^ getTexture(int iTex);
		// Sets a current texture.
		void setTextureIndex(int iTex);
		// Returns the background color.
		Color getBGColor();
		// Returns the wireframe color.
		Color getWFColor();
		// Returns the wireframe color of the selected object.
		Color getSelectedColor();
		// Sets the background color.
		void setBGColor(Color _col);
		// Sets the wireframe color.
		void setWFColor(Color _col);
		// Sets the wireframe color of the selected object.
		void setSelectedColor(Color _col);
		// If true, the renderer uses the brush for selected objects, otherwise the wireframe brush.
		bool isSelectedObject;
		// Switches a current projection mode (perspective, if true).
		void setProjection(bool _perspective);
		// Switches back-face culling.
		void setFaceCulling(bool _cullFace);

		const Color DEFAULT_BG_COLOR = Color::Black;
		const Color DEFAULT_WF_COLOR = Color::White;
		const Color DEFAULT_SELECTED_COLOR = Color::Blue;

	private:
		// The graphics objects to render on.
		Graphics ^graphics;
		// The background color.
		Color bgColor;
		// The brush for wireframe drawing.
		SolidBrush ^wfBrush;
		// The brush for wireframe drawing of the currently selected object.
		SolidBrush ^selectedBrush;
		// The brush for the surface drawing.
		SolidBrush ^surfaceBrush;
		// True, if a perspective projection is set, otherwise orthographics.
		bool perspective;
		// True, is back-face culling is set.
		bool cullFace;
		// The width of the viewport (screen).
		int viewportX;
		// The height of the viewport (screen).
		int viewportY;
		// Depth buffer (width X height).
		array<float, 2>^ zbuffer;
		// Loaded textures.
		List<Bitmap^>^ textures;
		// Selected texture.
		int iTexture;
		// True, if a polygon is entirely off the screen.
		bool toClip(const Polygon & poly);
		// True, if a polygon is back-faced.
		bool isVisible(const Polygon & poly);
		// Calculates the colors in the vertices of a polygon using the Gouraud shading.
		std::vector<Vector4> getGouraudColors(const GL::Polygon &poly, Light lightSource, Material material);
		// Draws a line using the Bresenham's algorithm.
		void drawLine(const Vector3 &from, const Vector3 &to);
		// Draw a single pixel with a Z-test.
		void drawPoint(int x, int y, float z, SolidBrush ^b);
		// Draws a wireframe of a polygon.
		void drawPolygon(const GL::Polygon &poly);
		// Fills and shades a polygon.
		void fillPolygon(const GL::Polygon &poly, const GL::Polygon &worldPoly, const Light &lightSource, 
			const Material &material, std::vector<Vector4> gouraudColors);
		// Translate from homonegenous coordinates of the vector (w-division) and map to the viewport.
		void viewportTransform(GL::Polygon & poly);
		// Remaps coordinates from [-1, 1] to the [0, viewportX(Y)] space. 
		Vector3 NDCtoViewport(const Vector3 &vertex);
	};
}
