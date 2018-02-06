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

System::Void MainForm::changeObjectPosition() {
	mainScene->setObjectPosition(((TrackBar^)objPosXBar)->Value,
								 ((TrackBar^)objPosYBar)->Value, 
							  	 ((TrackBar^)objPosZBar)->Value);
	renderScene();
}

System::Void MainForm::objPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectPosition();
}

System::Void MainForm::objPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectPosition();
}

System::Void MainForm::objPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectPosition();
}

// Object scale scroll bars:

System::Void MainForm::changeObjectScale() {
	mainScene->setObjectScale(((TrackBar^)objScaleXBar)->Value,
							  ((TrackBar^)objScaleYBar)->Value, 
							  ((TrackBar^)objScaleZBar)->Value);
	renderScene();
}

System::Void MainForm::objScaleXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectScale();
}

System::Void MainForm::objScaleYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectScale();
}

System::Void MainForm::objScaleZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectScale();
}

// Object rotation scroll bars:

System::Void MainForm::changeObjectRotation() {
	mainScene->setObjectRotation(((TrackBar^)objRotXBar)->Value,
								 ((TrackBar^)objRotYBar)->Value, 
							  	 ((TrackBar^)objRotZBar)->Value);
	renderScene();
}

System::Void MainForm::objRotXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectRotation();
}

System::Void MainForm::objRotYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectRotation();
}

System::Void MainForm::objRotZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeObjectRotation();
}

// Camera position scroll bars:

System::Void MainForm::changeCameraPosition() {
	mainScene->setCameraPosition(((TrackBar^)camPosXBar)->Value,
								 ((TrackBar^)camPosYBar)->Value, 
							  	 ((TrackBar^)camPosZBar)->Value);
	renderScene();
}

System::Void MainForm::camPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeCameraPosition();
}

System::Void MainForm::camPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeCameraPosition();
}

System::Void MainForm::camPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeCameraPosition();
}

// Camera rotation scroll bars:

System::Void MainForm::changeCameraRotation() {
	mainScene->setCameraRotation(((TrackBar^)camRotPitchBar)->Value,
								 ((TrackBar^)camRotYawBar)->Value, 
							  	 ((TrackBar^)camRotRollBar)->Value);
	renderScene();
}

System::Void MainForm::camRotPitchBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeCameraRotation();
}

System::Void MainForm::camRotYawBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeCameraRotation();
}

System::Void MainForm::camRotRollBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeCameraRotation();
}

// Various buttons:

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

// Object reflection checkboxes:

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
