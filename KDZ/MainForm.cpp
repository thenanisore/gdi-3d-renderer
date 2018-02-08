#include "MainForm.h"
#include "Scene.h"
#include "Renderer.h"

#include <Windows.h>

using namespace KDZ;

[STAThread]
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
	Graphics ^gr = Graphics::FromImage(bm);
	try {
		renderer->setGraphics(gr);
		mainScene->renderScene(renderer);
	}
	finally {
		delete gr;
	}
	pictureBox->Refresh();
}

System::Void MainForm::openToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (openFileDialog->ShowDialog() == ::DialogResult::OK) {
		IO::StreamReader ^sr = gcnew IO::StreamReader(openFileDialog->FileName);
		try {;
			if (mainScene->fromFile(sr->ReadToEnd())) {
				// object loaded successfully
				renderScene();
			}
			else {
				// something went wrong
				MessageBox::Show(L"Invalid file format.", L"Error");
			}
		}
		finally {
			sr->Close();
		}
	}
}

// Sets scene after the MainForm is shown.
System::Void MainForm::MainForm_Shown(System::Object^  sender, System::EventArgs^  e) {
	setScene();
}

System::Void MainForm::MainForm_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
	bm = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	renderer->setGraphics(Graphics::FromImage(bm));
	renderer->setViewport(pictureBox->Width, pictureBox->Height);
	pictureBox->Image = bm;
	renderScene();
}

// Object position scroll bars:

System::Void MainForm::changeObjectPosition() {
	mainScene->setObjectPosition(objPosXBar->Value, objPosYBar->Value, objPosZBar->Value);
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
	mainScene->setObjectScale(objScaleXBar->Value, objScaleYBar->Value, objScaleZBar->Value);
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
	mainScene->setObjectRotation(objRotXBar->Value, objRotYBar->Value, objRotZBar->Value);
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
	mainScene->setCameraPosition(camPosXBar->Value, camPosYBar->Value, camPosZBar->Value);
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
	mainScene->setCameraRotation(camRotPitchBar->Value, camRotYawBar->Value, 0.0f);
	renderScene();
}

System::Void MainForm::camRotPitchBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeCameraRotation();
}

System::Void MainForm::camRotYawBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
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

	isResettingScene = true;
	// reset object's trackbars
	objPosXBar->Value = 0;
	objPosYBar->Value = 0;
	objPosZBar->Value = 0;
	objScaleXBar->Value = 10;
	objScaleYBar->Value = 10;
	objScaleZBar->Value = 10;
	objRotXBar->Value = 0;
	objRotYBar->Value = 0;
	objRotZBar->Value = 0;
	objReflectionXYCheckbox->Checked = false;
	objReflectionXZCheckbox->Checked = false;
	objReflectionYZCheckbox->Checked = false;
	isResettingScene = false;

	renderScene();
}

System::Void MainForm::resetCamButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->resetCamera();

	// reset camera's trackbars
	isResettingScene = true;
	camPosXBar->Value = 0;
	camPosYBar->Value = 0;
	camPosZBar->Value = 10;
	camRotPitchBar->Value = 0;
	camRotYawBar->Value = 180;
	isResettingScene = false;

	renderScene();
}

// Object reflection checkboxes:

System::Void MainForm::changeObjectReflection() {
	if (!isResettingScene) {
		mainScene->setObjectReflection(objReflectionXYCheckbox->Checked, 
									   objReflectionXZCheckbox->Checked,
									   objReflectionYZCheckbox->Checked);
		renderScene();
	}
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

// Color pickers:

System::Void MainForm::bgColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	ColorDialog ^dialog = gcnew ColorDialog();
	dialog->ShowHelp = true;
	dialog->Color = renderer->getBGColor();
	// Update the text box color if the user clicks OK 
	if (dialog->ShowDialog(this) == ::DialogResult::OK) {
		renderer->setBGColor(dialog->Color);
		bgColorButton->BackColor = dialog->Color;
		renderScene();
	}
}

System::Void MainForm::wfColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	ColorDialog ^dialog = gcnew ColorDialog();
	dialog->ShowHelp = true;
	dialog->Color = renderer->getWFColor();
	// Update the text box color if the user clicks OK 
	if (dialog->ShowDialog(this) == ::DialogResult::OK) {
		renderer->setWFColor(dialog->Color);
		wfColorButton->BackColor = dialog->Color;
		renderScene();
	}
}

System::Void MainForm::selectedColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	ColorDialog ^dialog = gcnew ColorDialog();
	dialog->ShowHelp = true;
	dialog->Color = renderer->getSelectedColor();
	// Update the text box color if the user clicks OK 
	if (dialog->ShowDialog(this) == ::DialogResult::OK) {
		renderer->setSelectedColor(dialog->Color);
		selectedColorButton->BackColor = dialog->Color;
		renderScene();
	}
}

// Projection radio buttons:

System::Void MainForm::changeProjectionMode() {
	mainScene->setProjectionMode(perspectiveButton->Checked);
	renderScene();
}

System::Void KDZ::MainForm::perspectiveButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeProjectionMode();
}

System::Void KDZ::MainForm::orthoButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeProjectionMode();
}

// Drawing mode radio buttons:

System::Void MainForm::changeDrawingMode() {
	if (wfRadioButton->Checked) mainScene->setDrawingMode(true, false);
	else if (solidRadioButton->Checked) mainScene->setDrawingMode(false, true);
	else if (bothRadioButton->Checked) mainScene->setDrawingMode(true, true);
	renderScene();
}

System::Void KDZ::MainForm::wfRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeDrawingMode();
}

System::Void KDZ::MainForm::solidRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeDrawingMode();
}

System::Void KDZ::MainForm::bothRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeDrawingMode();
}
