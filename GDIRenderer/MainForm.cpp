/*
* Copyright © 2018 Oleg Ivanov
* Licensed under the MIT license.
*/

#include "MainForm.h"
#include "About.h"
#include "Scene.h"
#include "Light.h"
#include "Shapes.h"
#include "Renderer.h"

#include <Windows.h>

using namespace GDIRenderer;

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	return 0;
}

System::Void MainForm::setScene() {
	checkButtons();
	updateObjectParams();
	updateMaterialParams();
	updateCameraParams();
	updateOtherParams();
	updateLightParams();
	renderScene();
}

System::Void MainForm::renderScene() {
	Graphics ^gr = Graphics::FromImage(bm);
	try {
		renderer->setGraphics(gr);
		mainScene->renderScene(renderer);
		updateStatusBar();
	}
	finally {
		delete gr;
	}
	pictureBox->Refresh();
}

System::Void MainForm::checkButtons() {
	if (mainScene->isEmpty()) {
		prevObjButton->Enabled = false;
		nextObjButton->Enabled = false;
		resetObjButton->Enabled = false;
		deleteObjButton->Enabled = false;
		objPosXBar->Enabled = false;
		objPosYBar->Enabled = false;
		objPosZBar->Enabled = false;
		objRotXBar->Enabled = false;
		objRotYBar->Enabled = false;
		objRotZBar->Enabled = false;
		objScaleXBar->Enabled = false;
		objScaleYBar->Enabled = false;
		objScaleZBar->Enabled = false;
		objReflectionXYCheckbox->Enabled = false;
		objReflectionXZCheckbox->Enabled = false;
		objReflectionYZCheckbox->Enabled = false;
		resetMatButton->Enabled = false;
		matColorButton->Enabled = false;
		ambiMatBar->Enabled = false;
		diffMatBar->Enabled = false;
		specMatBar->Enabled = false;
		shineMatBar->Enabled = false;
		loadTextureButton->Enabled = false;
		removeTextureButton->Enabled = false;
	}
	else {
		prevObjButton->Enabled = mainScene->objectCount() > 1 && !mainScene->isSelectedFirst();
		nextObjButton->Enabled = mainScene->objectCount() > 1 && !mainScene->isSelectedLast();
		resetObjButton->Enabled = true;
		deleteObjButton->Enabled = true;
		objPosXBar->Enabled = true;
		objPosYBar->Enabled = true;
		objPosZBar->Enabled = true;
		objRotXBar->Enabled = true;
		objRotYBar->Enabled = true;
		objRotZBar->Enabled = true;
		objScaleXBar->Enabled = true;
		objScaleYBar->Enabled = true;
		objScaleZBar->Enabled = true;
		objReflectionXYCheckbox->Enabled = true;
		objReflectionXZCheckbox->Enabled = true;
		objReflectionYZCheckbox->Enabled = true;
		resetMatButton->Enabled = true;
		matColorButton->Enabled = true;
		ambiMatBar->Enabled = true;
		diffMatBar->Enabled = true;
		specMatBar->Enabled = true;
		shineMatBar->Enabled = true;
		loadTextureButton->Enabled = true;
		removeTextureButton->Enabled = mainScene->getTexture() >= 0 || mainScene->getTexture() < renderer->getTextureNumber();
	}
}

System::Void MainForm::updateStatusBar() {
	String^ info = "Objects : " + mainScene->objectCount() + " | ";
	// get the current object's and camera's info
	if (!mainScene->isEmpty()) {
		GL::Vector3 pos = mainScene->getObjectPosition(true);
		info += "Pos : (" + pos.x + ", " + pos.y + ", " + pos.z + ") | ";
		GL::Vector3 rot = mainScene->getObjectRotation(true);
		info += "Rot : (" + rot.x + ", " + rot.y + ", " + rot.z + ") | ";
		GL::Vector3 sca = mainScene->getObjectScale(true);
		info += "Scale : (" + sca.x + ", " + sca.y + ", " + sca.z + ") | ";
	}
	GL::Vector3 camPos = mainScene->getCameraPosition(true);
	info += "Camera | Pos : (" + camPos.x + ", " + camPos.y + ", " + camPos.z + ") | ";
	GL::Vector3 camRot = mainScene->getCameraRotation(true);
	info += "Pitch : " + camRot.x + " | Yaw : " + camRot.y + " | ";
	GL::Vector3 lightPos = mainScene->getLightPosition(true);
	info += "Light | Pos : (" + lightPos.x + ", " + lightPos.y + ", " + lightPos.z + ") | ";
	objCountLabel->Text = info;
}

System::Void MainForm::openToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (openFileDialog->ShowDialog() == ::DialogResult::OK) {
		IO::StreamReader ^sr = gcnew IO::StreamReader(openFileDialog->FileName);
		try {
			if (mainScene->fromFile(sr->ReadToEnd())) {
				// object loaded successfully
				checkButtons();
				updateObjectParams();
				updateMaterialParams();
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

System::Void GDIRenderer::MainForm::aboutToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	Form^ aboutForm = gcnew About();
	aboutForm->ShowDialog();
}

System::Void MainForm::exitToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	Application::Exit();
}

// Object generation menu:

System::Void MainForm::addObject(GL::Objects::Shape shape, int precision) {
	mainScene->addObject(GL::Objects::generateObject(shape, precision));
	checkButtons();
	updateObjectParams();
	updateMaterialParams();
	renderScene();
}

System::Void MainForm::cubeToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::CUBE, 1);
}

System::Void MainForm::pyramidToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::PYRAMID, 1);
}

System::Void MainForm::tetrahedronToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::TETRAHEDRON, 1);
}

System::Void MainForm::octahedronToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::OCTAHEDRON, 1);
}

System::Void MainForm::sphere0MenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::SPHERE, 0);
}

System::Void MainForm::sphere1MenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::SPHERE, 1);
}

System::Void MainForm::sphere2MenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::SPHERE, 2);
}

System::Void MainForm::sphere3MenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::SPHERE, 3);
}

System::Void MainForm::sphere4MenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::SPHERE, 4);
}

System::Void MainForm::sphere5MenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
	addObject(GL::Objects::Shape::SPHERE, 5);
}

System::Void MainForm::setObjectsParams(int objPosX, int objPosY, int objPosZ, int objScaleX, int objScaleY, int objScaleZ, int objRotX, int objRotY, int objRotZ, bool objReflXY, bool objReflXZ, bool objReflYZ) {
	isSettingParams = true;
	// set object's trackbars
	objPosXBar->Value = objPosX;
	objPosYBar->Value = objPosY;
	objPosZBar->Value = objPosZ;
	objScaleXBar->Value = objScaleX;
	objScaleYBar->Value = objScaleY;
	objScaleZBar->Value = objScaleZ;
	objRotXBar->Value = objRotX;
	objRotYBar->Value = objRotY;
	objRotZBar->Value = objRotZ;
	objReflectionXYCheckbox->Checked = objReflXY;
	objReflectionXZCheckbox->Checked = objReflXZ;
	objReflectionYZCheckbox->Checked = objReflYZ;
	isSettingParams = false;
}

System::Void MainForm::setCameraParams(int camPosX, int camPosY, int camPosZ, int camPitch, int camYaw, bool perspective) {
	// set camera's trackbars
	isSettingParams = true;
	camPosXBar->Value = camPosX;
	camPosYBar->Value = camPosY;
	camPosZBar->Value = camPosZ;
	camRotPitchBar->Value = camPitch;
	camRotYawBar->Value = camYaw;
	perspectiveButton->Checked = perspective;
	orthoButton->Checked = !perspective;
	isSettingParams = false;
}

System::Void MainForm::setOtherParams(Color bgColor, Color wfColor, Color selectedColor, bool wfMode,
	bool solidMode, bool faceCull, GL::TextureWrapMode wrapMode) {
	// set other parameters
	isSettingParams = true;
	wfColorButton->BackColor = wfColor;
	bgColorButton->BackColor = bgColor;
	selectedColorButton->BackColor = selectedColor;
	if (wfMode && solidMode) {
		bothRadioButton->Checked = true;
	}
	else {
		wfRadioButton->Checked = wfMode;
		solidRadioButton->Checked = solidMode;
	}
	cullOnRadioButton->Checked = faceCull;
	cullOffRadioButton->Checked = !faceCull;
	switch (wrapMode) {
	case GL::TextureWrapMode::REPEAT:
		wrapRepeatRButton->Checked = true;
		break;
	case GL::TextureWrapMode::MIRRORED_REPEAT:
		wrapMRepeatRButton->Checked = true;
		break;
	case GL::TextureWrapMode::CLAMP_TO_EDGE:
		wrapClampEdgeRButton->Checked = true;
		break;
	}
	isSettingParams = false;
}

System::Void MainForm::updateObjectParams() {
	if (!mainScene->isEmpty()) {
		GL::Vector3 pos = mainScene->getObjectPosition(false);
		GL::Vector3 rot = mainScene->getObjectRotation(false);
		GL::Vector3 sc = mainScene->getObjectScale(false);
		GL::Vector3 refl = mainScene->getObjectReflection();
		setObjectsParams(pos.x, pos.y, pos.z, sc.x, sc.y, sc.z, rot.x, rot.y, rot.z, refl.z, refl.y, refl.x);
	}
}

System::Void MainForm::updateCameraParams() {
	GL::Vector3 pos = mainScene->getCameraPosition(false);
	GL::Vector3 rot = mainScene->getCameraRotation(false);
	bool perspective = mainScene->isPerspective();
	setCameraParams(pos.x, pos.y, pos.z, rot.x, rot.y, perspective);
}

System::Void MainForm::updateOtherParams() {
	Color bg = renderer->getBGColor();
	Color wfCol = renderer->getWFColor();
	Color sel = renderer->getSelectedColor();
	bool wf = mainScene->isWireframeMode();
	bool solid = mainScene->isSolidMode();
	bool cull = mainScene->isCulling();
	GL::TextureWrapMode wrapMode = mainScene->getWrapMode();
	setOtherParams(bg, wfCol, sel, wf, solid, cull, wrapMode);
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
	checkButtons();
	updateObjectParams();
	updateMaterialParams();
	renderScene();
}

System::Void MainForm::prevObjButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->selectPreviousObject();
	checkButtons();
	updateObjectParams();
	updateMaterialParams();
	renderScene();
}

System::Void MainForm::deleteObjButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->deleteObject();
	checkButtons();
	updateObjectParams();
	updateMaterialParams();
	renderScene();
}

System::Void MainForm::resetObjButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->resetObject();
	updateObjectParams();
	renderScene();
}

System::Void MainForm::resetCamButton_Click(System::Object^  sender, System::EventArgs^  e) {
	mainScene->resetCamera();
	updateCameraParams();
	renderScene();
}

// Object reflection checkboxes:

System::Void MainForm::changeObjectReflection() {
	if (!isSettingParams) {
		mainScene->setObjectReflection(objReflectionXYCheckbox->Checked, objReflectionXZCheckbox->Checked, objReflectionYZCheckbox->Checked);
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

System::Void MainForm::perspectiveButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeProjectionMode();
}

System::Void MainForm::orthoButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeProjectionMode();
}

// Drawing mode radio buttons:

System::Void MainForm::changeDrawingMode() {
	if (wfRadioButton->Checked) mainScene->setDrawingMode(true, false);
	else if (solidRadioButton->Checked) mainScene->setDrawingMode(false, true);
	else if (bothRadioButton->Checked) mainScene->setDrawingMode(true, true);
	renderScene();
}

System::Void MainForm::wfRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeDrawingMode();
}

System::Void MainForm::solidRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeDrawingMode();
}

System::Void MainForm::bothRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeDrawingMode();
}

// Culling:

System::Void MainForm::changeCulling() {
	if (cullOnRadioButton->Checked) mainScene->setCulling(true);
	else if (cullOffRadioButton->Checked) mainScene->setCulling(false);
	renderScene();
}

System::Void MainForm::cullOnRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeCulling();
}

System::Void MainForm::cullOffRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeCulling();
}

// Lighting:

System::Void MainForm::setLightParams(int lightPosX, int lightPosY, int lightPosZ, bool isOn,
	GL::LightMode mode, Color lightColor, int ambi, int diff, int spec) {
	// set lighting parameters
	isSettingParams = true;
	lightColorButton->BackColor = lightColor;
	lightPosXBar->Value = lightPosX;
	lightPosYBar->Value = lightPosY;
	lightPosZBar->Value = lightPosZ;
	lightAmbiTrackBar->Value = ambi;
	lightDiffuseBar->Value = diff;
	lightSpecBar->Value = spec;
	noLightRadioButton->Checked = !isOn;
	phongLightRadioButton->Checked = isOn && mode == GL::LightMode::PHONG;
	gouraudLightRadioButton->Checked = isOn && mode == GL::LightMode::GOURAUD;
	flatLightRadioButton->Checked = isOn && mode == GL::LightMode::FLAT;
	isSettingParams = false;
}

System::Void MainForm::updateLightParams() {
	GL::Vector3 pos = mainScene->getLightPosition(false);
	Color lightColor = mainScene->getLightColor();
	bool isOn = mainScene->isLightOn();
	GL::LightMode mode = mainScene->getLightMode();
	GL::Vector3 params = mainScene->getLightParams(false);
	setLightParams(pos.x, pos.y, pos.z, isOn, mode, lightColor, (int)params.x, (int)params.y, (int)params.z);
}

System::Void MainForm::changeLightPosition() {
	mainScene->setLightPosition(lightPosXBar->Value, lightPosYBar->Value, lightPosZBar->Value);
	renderScene();
}

System::Void MainForm::changeLightParams() {
	mainScene->setLightParams(lightAmbiTrackBar->Value, lightDiffuseBar->Value, lightSpecBar->Value);
	renderScene();
}

System::Void MainForm::lightPosXBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeLightPosition();
}

System::Void MainForm::lightPosYBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeLightPosition();
}

System::Void MainForm::lightPosZBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeLightPosition();
}

System::Void GDIRenderer::MainForm::lightAmbiTrackBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeLightParams();
}

System::Void MainForm::lightDiffuseBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeLightParams();
}

System::Void MainForm::lightSpecBar_Scroll(System::Object^  sender, System::EventArgs^  e) {
	changeLightParams();
}

System::Void MainForm::lightColorButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	ColorDialog ^dialog = gcnew ColorDialog();
	dialog->ShowHelp = true;
	dialog->Color = mainScene->getLightColor();
	// Update the text box color if the user clicks OK
	if (dialog->ShowDialog(this) == ::DialogResult::OK) {
		mainScene->setLightColor(dialog->Color);
		lightColorButton->BackColor = dialog->Color;
		renderScene();
	}
}

System::Void MainForm::changeLightingMode() {
	if (noLightRadioButton->Checked) {
		mainScene->setLightOn(false);
	}
	else {
		mainScene->setLightOn(true);
		if (phongLightRadioButton->Checked) {
			mainScene->setLightMode(GL::LightMode::PHONG);
		}
		else if (flatLightRadioButton->Checked) {
			mainScene->setLightMode(GL::LightMode::FLAT);
		}
		else if (gouraudLightRadioButton->Checked) {
			mainScene->setLightMode(GL::LightMode::GOURAUD);
		}
	}
	renderScene();
}

System::Void MainForm::lightResetButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	mainScene->resetLighting();
	updateLightParams();
	renderScene();
}

System::Void MainForm::noLightRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeLightingMode();
}

System::Void MainForm::phongLightRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeLightingMode();
}

System::Void MainForm::gouraudLightRadioButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeLightingMode();
}

System::Void MainForm::flatLightRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	changeLightingMode();
}

// Material parameters:

System::Void MainForm::setMaterialParams(int ambi, int diff, int spec, int shine, Color matColor, int iTex) {
	// set material parameters
	isSettingParams = true;
	ambiMatBar->Value = ambi;
	diffMatBar->Value = diff;
	specMatBar->Value = spec;
	shineMatBar->Value = shine;
	matColorButton->BackColor = matColor;
	loadTextureButton->BackgroundImage = (iTex < 0 || iTex > renderer->getTextureNumber()) ? noTexture : renderer->getTexture(iTex);
	isSettingParams = false;
}

System::Void MainForm::updateMaterialParams() {
	if (!mainScene->isEmpty()) {
		GL::Vector4 params = mainScene->getMaterialParams();
		Color matColor = mainScene->getMaterialColor();
		int iTex = mainScene->getTexture();
		setMaterialParams(params.x, params.y, params.z, params.w, matColor, iTex);
	}
}

System::Void MainForm::resetMatButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	mainScene->resetMaterial();
	mainScene->removeTexture();
	updateMaterialParams();
	renderScene();
}

System::Void MainForm::matColorButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	ColorDialog ^dialog = gcnew ColorDialog();
	dialog->ShowHelp = true;
	dialog->Color = mainScene->getMaterialColor();
	// Update the text box color if the user clicks OK
	if (dialog->ShowDialog(this) == ::DialogResult::OK) {
		mainScene->setMaterialColor(dialog->Color);
		matColorButton->BackColor = dialog->Color;
		renderScene();
	}
}

System::Void MainForm::changeMaterialParams() {
	mainScene->setMaterialParams(ambiMatBar->Value, diffMatBar->Value, specMatBar->Value, shineMatBar->Value);
	renderScene();
}

System::Void MainForm::ambiMatBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeMaterialParams();
}

System::Void MainForm::diffMatBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeMaterialParams();
}

System::Void MainForm::specMatBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeMaterialParams();
}

System::Void MainForm::shineMatBar_Scroll(System::Object ^ sender, System::EventArgs ^ e) {
	changeMaterialParams();
}

// Textures

System::Void MainForm::loadTextureButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (loadTextureDialog->ShowDialog() == ::DialogResult::OK) {
		try {
			Bitmap^ b = (Bitmap^)Image::FromFile(loadTextureDialog->FileName);
			renderer->addTexture(b);
			mainScene->setTexture(renderer->getTextureNumber() - 1);
			loadTextureButton->BackgroundImage = b;
			checkButtons();
			updateMaterialParams();
			renderScene();
		}
		catch (const std::exception& e) {
			// something went wrong
			MessageBox::Show(L"Can't load texture", L"Error");
		}
	}
}

System::Void MainForm::removeTextureButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
	mainScene->removeTexture();
	checkButtons();
	updateMaterialParams();
	renderScene();
}

// Texture wrapping params:

System::Void MainForm::changeWrappingMode() {
	if (wrapRepeatRButton->Checked) {
		mainScene->setWrapMode(GL::TextureWrapMode::REPEAT);
	}
	else if (wrapMRepeatRButton->Checked) {
		mainScene->setWrapMode(GL::TextureWrapMode::MIRRORED_REPEAT);
	}
	else if (wrapClampEdgeRButton->Checked) {
		mainScene->setWrapMode(GL::TextureWrapMode::CLAMP_TO_EDGE);
	}
	renderScene();
}

System::Void MainForm::wrapRepeatRButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeWrappingMode();
}

System::Void MainForm::wrapMRepeatRButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeWrappingMode();
}

System::Void MainForm::wrapClampEdgeRButton_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
	changeWrappingMode();
}


