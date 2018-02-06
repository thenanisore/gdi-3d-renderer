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
	// TODO: init code
	renderScene();
}

System::Void MainForm::renderScene() {
	Graphics ^im = Graphics::FromImage(bm);
	Color ^col = gcnew Color();
	Pen ^pen = gcnew Pen(col->Blue);
	SolidBrush ^br = gcnew SolidBrush(col->Blue);
	GL::Renderer rend(im, col, pictureBox->Width, pictureBox->Height);
	try {
		mainScene->renderScene(%rend);
	}
	finally {
		delete im;
	}
	pictureBox->Refresh();
}

// Sets scene after the MainForm is shown.
System::Void MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e) {
	setScene();
}

// Object position scroll bars:

System::Void MainForm::objPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	TrackBar ^tb = (TrackBar^)sender;
	tb->Value;
}

System::Void MainForm::objPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::objPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

// Object scale scroll bars:

System::Void MainForm::objScaleXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::objScaleYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::objScaleZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

// Object rotation scroll bars:

System::Void MainForm::objRotXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::objRotYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::objRotZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

// Camera position scroll bars:

System::Void MainForm::camPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::camPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::camPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

// Camera rotation scroll bars:

System::Void MainForm::camRotPitchBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::camRotYawBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

System::Void MainForm::camRotRollBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
}

// Buttons:

System::Void MainForm::nextObjButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->selectNextObject();
	renderScene();
}

System::Void MainForm::prevObjButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->selectPreviousObject();
	renderScene();
}

System::Void MainForm::deleteObjButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->deleteObject();
	renderScene();
}

System::Void MainForm::resetObjButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->resetObject();
	renderScene();
}

System::Void MainForm::resetCamButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->resetCamera();
	renderScene();
}

System::Void MainForm::changeObjectReflection() {
	mainScene->setObjectReflection(objReflectionXYCheckbox->Checked, 
		                           objReflectionXZCheckbox->Checked,
		                           objReflectionYZCheckbox->Checked);
	renderScene();
}

System::Void MainForm::objReflectionXYCheckbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	changeObjectReflection();
}

System::Void MainForm::objReflectionXZCheckbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	changeObjectReflection();
}

System::Void MainForm::objReflectionYZCheckbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	changeObjectReflection();
}
