#include "MainForm.h"
#include "Scene.h"
#include "Renderer.h"

#include <Windows.h>

using namespace KDZ;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	return 0;
}

System::Void MainForm::setScene() {
	Graphics ^im = Graphics::FromImage(bm);
	Color ^col = gcnew Color();
	Pen ^pen = gcnew Pen(col->Blue);
	SolidBrush ^br = gcnew SolidBrush(col->Blue);
	GL::Scene sc;
	GL::Renderer rend(im, col, pictureBox->Width, pictureBox->Height);
	try {
		sc.renderScene(%rend);
	}
	finally {
		delete im;
	}
	pictureBox->Refresh();
}

System::Void MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e) {
	setScene();
}
