#include "MainForm.h"
#include "Scene.h"
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
	Pen ^pen = gcnew Pen(col->Red);
	GL::Scene sc;
	sc.renderScene(im, col, pen);
	
	//im->Clear(col->White);
	//im->DrawLine(pen, 5, 5, 10, 10);
	//im->DrawLine(pen, 100, 100, 201, 201);
	//im->DrawLine(pen, 102, 102, 102, 102);
}
