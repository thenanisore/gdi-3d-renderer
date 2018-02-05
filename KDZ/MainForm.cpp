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

System::Void MainForm::button1_Click(System::Object ^sender, System::EventArgs ^e) {
	Graphics ^im = pictureBox->CreateGraphics();
	Color ^col = gcnew Color();
	Pen ^pen = gcnew Pen(col->Blue);
	SolidBrush ^br = gcnew SolidBrush(col->Blue);
	GL::Scene sc;
	GL::Renderer rend(im, col, pictureBox->Width, pictureBox->Height);
	sc.renderScene(%rend);
}
