#pragma once

#include "Scene.h"

namespace KDZ {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			mainScene = new GL::Scene();
			bm = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
			renderer = gcnew GL::Renderer(Graphics::FromImage(bm), pictureBox->Width, pictureBox->Height);
			pictureBox->Image = bm;
			isSettingParams = false;
		}

	private: 
		GL::Renderer ^renderer;
		Bitmap^ bm;
	private: System::Windows::Forms::TabPage^  otherTabPage;
	private: System::Windows::Forms::FlowLayoutPanel^  otherFlowLayoutPanel;
	private: System::Windows::Forms::GroupBox^  colorGroupBox;
	private: System::Windows::Forms::Button^  selectedColorButton;

	private: System::Windows::Forms::Label^  selectedColorLabel;
	private: System::Windows::Forms::Button^  wfColorButton;

	private: System::Windows::Forms::Label^  wfColorLabel;
	private: System::Windows::Forms::Button^  bgColorButton;
	private: System::Windows::Forms::Label^  bgColorLabel;
	private: System::Windows::Forms::ColorDialog^  bgColorDialog;
	private: System::Windows::Forms::ColorDialog^  wfColorDialog;
	private: System::Windows::Forms::ColorDialog^  selectedColorDialog;
	private: System::Windows::Forms::GroupBox^  drawingModeGroupBox;
	private: System::Windows::Forms::RadioButton^  bothRadioButton;
	private: System::Windows::Forms::RadioButton^  solidRadioButton;
	private: System::Windows::Forms::RadioButton^  wfRadioButton;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::GroupBox^  cullGroupBox;
	private: System::Windows::Forms::RadioButton^  cullOffRadioButton;
	private: System::Windows::Forms::RadioButton^  cullOnRadioButton;
	private: System::Windows::Forms::TabPage^  lightingTabPage;
	private: System::Windows::Forms::FlowLayoutPanel^  lightFlowLayoutPanel;
	private: System::Windows::Forms::GroupBox^  lightParamsGroupBox;
	private: System::Windows::Forms::Button^  lightColorButton;

	private: System::Windows::Forms::Label^  lightColorLabel;
	private: System::Windows::Forms::GroupBox^  lightModeGroupBox;
	private: System::Windows::Forms::RadioButton^  gouraudLightRadioButton;
	private: System::Windows::Forms::RadioButton^  phongLightRadioButton;
	private: System::Windows::Forms::RadioButton^  noLightRadioButton;
	private: System::Windows::Forms::GroupBox^  lightPosGroupBox;
	private: System::Windows::Forms::TrackBar^  lightPosZBar;
	private: System::Windows::Forms::Label^  lightPosZLabel;
	private: System::Windows::Forms::TrackBar^  lightPosYBar;
	private: System::Windows::Forms::Label^  lightPosYLabel;
	private: System::Windows::Forms::TrackBar^  lightPosXBar;
	private: System::Windows::Forms::Label^  lightPosXLabel;
	private: System::Windows::Forms::TrackBar^  lightAmbiTrackBar;
	private: System::Windows::Forms::Label^  lightAmbiLabel;
	private: System::Windows::Forms::TrackBar^  lightDiffuseBar;
	private: System::Windows::Forms::Label^  lightDiffuseLabel;
	private: System::Windows::Forms::ColorDialog^  lightColorDialog;
	private: System::Windows::Forms::TrackBar^  lightSpecBar;

	private: System::Windows::Forms::Label^  specLightLabel;
	private: System::Windows::Forms::Button^  lightResetButton;
	private: System::Windows::Forms::RadioButton^  flatLightRadioButton;
	private: System::Windows::Forms::TabPage^  matTabPage;
	private: System::Windows::Forms::FlowLayoutPanel^  matFlowLayoutPanel;
	private: System::Windows::Forms::Button^  resetMatButton;
	private: System::Windows::Forms::GroupBox^  matParamsGroupBox;
	private: System::Windows::Forms::TrackBar^  specMatBar;
	private: System::Windows::Forms::Label^  specMatLabel;
	private: System::Windows::Forms::TrackBar^  diffMatBar;
	private: System::Windows::Forms::Label^  diffMatLabel;
	private: System::Windows::Forms::TrackBar^  ambiMatBar;
	private: System::Windows::Forms::Label^  ambiMatLabel;
	private: System::Windows::Forms::Button^  matColorButton;
	private: System::Windows::Forms::Label^  matColorLabel;
	private: System::Windows::Forms::TrackBar^  shineMatBar;
	private: System::Windows::Forms::Label^  shineMatLabel;





		 // Main scene
		GL::Scene *mainScene;
		System::Void setScene();
		System::Void renderScene();
		System::Void checkButtons();
		System::Void updateStatusBar();
		// menu strip
		System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		// mainform events
		System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e);
		System::Void MainForm_ResizeEnd(System::Object^  sender, System::EventArgs^  e);
		// object scroll bars
		System::Void changeObjectPosition();
		System::Void objPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void changeObjectScale();
		System::Void objScaleXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objScaleYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objScaleZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void changeObjectRotation();
		System::Void objRotXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objRotYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objRotZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		// camera scroll bars
		System::Void changeCameraPosition();
		System::Void camPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void changeCameraRotation();
		System::Void camRotPitchBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camRotYawBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void updateObjectParams();
		System::Void updateCameraParams();
		System::Void updateLightParams();
		System::Void updateOtherParams();
		// buttons
		System::Void nextObjButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void prevObjButton_Click(System::Object^  sender, System::EventArgs^  e); 
		System::Void deleteObjButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void setObjectsParams(int objPosX, int objPosY, int objPosZ, int objScaleX, int objScaleY, int objScaleZ, int objRotX, int objRotY, int objRotZ, bool objReflXY, bool objReflXZ, bool objReflYZ);
		System::Void setCameraParams(int camPosX, int camPosY, int camPosZ, int camPitch, int camYaw, bool perspective);
		System::Void setLightParams(int lightPosX, int lightPosY, int lightPosZ, bool isOn, GL::LightMode mode, Color lightColor, int ambi, int diff, int spec);
		System::Void setOtherParams(Color bgColor, Color wfColor, Color selectedColor, bool wfMode, bool solidMode, bool faceCull);
		System::Void resetObjButton_Click(System::Object^  sender, System::EventArgs^  e); 
		System::Void resetCamButton_Click(System::Object^  sender, System::EventArgs^  e); 
		// object reflection checkboxes:
		bool isSettingParams;
		System::Void changeObjectReflection();
		System::Void objReflectionXYCheckbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void objReflectionXZCheckbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void objReflectionYZCheckbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		// color pickers
		System::Void bgColorButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void wfColorButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void selectedColorButton_Click(System::Object^  sender, System::EventArgs^  e);
		// projection radio buttons
		System::Void changeProjectionMode();
		System::Void perspectiveButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void orthoButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void changeCulling();
		// drawing mode radio buttons
		System::Void changeDrawingMode();
		System::Void wfRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void solidRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void bothRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		// culling radio buttons
		System::Void cullOnRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void cullOffRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void changeLightPosition();
		System::Void changeLightParams();
		// light source control
		System::Void changeLightingMode();
		System::Void lightResetButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void lightPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void lightPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void lightPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void lightColorButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void lightAmbiTrackBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void lightDiffuseBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void lightSpecBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void noLightRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void phongLightRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void gouraudLightRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void flatLightRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void setMaterialParams(int ambi, int diff, int spec, int shine, Color matColor);
		System::Void updateMaterialParams();
		// material control
		System::Void resetMatButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void matColorButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void changeMaterialParams();
		System::Void ambiMatBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void diffMatBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void specMatBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void shineMatBar_Scroll(System::Object^  sender, System::EventArgs^  e);

	private: System::Windows::Forms::Button^  prevObjButton;
	private: System::Windows::Forms::Button^  nextObjButton;
	private: System::Windows::Forms::Button^  deleteObjButton;
	private: System::Windows::Forms::Button^  resetObjButton;
	private: System::Windows::Forms::TableLayoutPanel^  selectionTableLayoutPanel;
	private: System::Windows::Forms::Button^  resetCamButton;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			delete mainScene;
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip;
	protected:


	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel;
	private: System::Windows::Forms::PictureBox^  pictureBox;
















	private: System::Windows::Forms::StatusStrip^  statusStrip;
private: System::Windows::Forms::ToolStripStatusLabel^  objCountLabel;

	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
private: System::Windows::Forms::TabControl^  tabControl;







	private: System::Windows::Forms::TabPage^  objectTabPage;

















	private: System::Windows::Forms::TabPage^  cameraTabPage;
	private: System::Windows::Forms::GroupBox^  cameraPosGroupBox;
	private: System::Windows::Forms::Label^  camPosXLabel;
	private: System::Windows::Forms::TrackBar^  camPosXBar;
	private: System::Windows::Forms::TrackBar^  camPosZBar;








	private: System::Windows::Forms::Label^  camPosZLabel;
	private: System::Windows::Forms::TrackBar^  camPosYBar;

	private: System::Windows::Forms::Label^  camPosYLabel;
	private: System::Windows::Forms::GroupBox^  camRotationGroupBox;



	private: System::Windows::Forms::TrackBar^  camRotYawBar;

	private: System::Windows::Forms::Label^  camYawLabel;
	private: System::Windows::Forms::TrackBar^  camRotPitchBar;

	private: System::Windows::Forms::Label^  camPitchLabel;
	private: System::Windows::Forms::FlowLayoutPanel^  camFlowLayoutPanel;
	private: System::Windows::Forms::GroupBox^  camProjectionGroupBox;
	private: System::Windows::Forms::RadioButton^  orthoButton;
	private: System::Windows::Forms::RadioButton^  perspectiveButton;
private: System::Windows::Forms::FlowLayoutPanel^  objFlowLayoutPanet;


private: System::Windows::Forms::GroupBox^  objPosGroupBox;
private: System::Windows::Forms::TrackBar^  objPosZBar;
private: System::Windows::Forms::Label^  objPosZLabel;


private: System::Windows::Forms::TrackBar^  objPosYBar;
private: System::Windows::Forms::Label^  objPosYLabel;


private: System::Windows::Forms::TrackBar^  objPosXBar;
private: System::Windows::Forms::Label^  objPosXLabel;
private: System::Windows::Forms::GroupBox^  objScaleGroupBox;



private: System::Windows::Forms::TrackBar^  objScaleZBar;
private: System::Windows::Forms::Label^  objScaleZLabel;


private: System::Windows::Forms::TrackBar^  objScaleYBar;
private: System::Windows::Forms::Label^  objScaleYLabel;


private: System::Windows::Forms::TrackBar^  objScaleXBar;
private: System::Windows::Forms::Label^  objScaleXLabel;
private: System::Windows::Forms::GroupBox^  objRotationGroupBox;
private: System::Windows::Forms::TrackBar^  objRotZBar;
private: System::Windows::Forms::Label^  objRotZLabel;


private: System::Windows::Forms::TrackBar^  objRotYBar;
private: System::Windows::Forms::Label^  objRotYLabel;


private: System::Windows::Forms::TrackBar^  objRotXBar;
private: System::Windows::Forms::Label^  objRotXLabel;
private: System::Windows::Forms::GroupBox^  objReflectionGroupBox;




private: System::Windows::Forms::CheckBox^  objReflectionYZCheckbox;

private: System::Windows::Forms::CheckBox^  objReflectionXZCheckbox;

private: System::Windows::Forms::CheckBox^  objReflectionXYCheckbox;











































	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->objectTabPage = (gcnew System::Windows::Forms::TabPage());
			this->objFlowLayoutPanet = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->selectionTableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->nextObjButton = (gcnew System::Windows::Forms::Button());
			this->prevObjButton = (gcnew System::Windows::Forms::Button());
			this->deleteObjButton = (gcnew System::Windows::Forms::Button());
			this->resetObjButton = (gcnew System::Windows::Forms::Button());
			this->objPosGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->objPosZBar = (gcnew System::Windows::Forms::TrackBar());
			this->objPosZLabel = (gcnew System::Windows::Forms::Label());
			this->objPosYBar = (gcnew System::Windows::Forms::TrackBar());
			this->objPosYLabel = (gcnew System::Windows::Forms::Label());
			this->objPosXBar = (gcnew System::Windows::Forms::TrackBar());
			this->objPosXLabel = (gcnew System::Windows::Forms::Label());
			this->objScaleGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->objScaleZBar = (gcnew System::Windows::Forms::TrackBar());
			this->objScaleZLabel = (gcnew System::Windows::Forms::Label());
			this->objScaleYBar = (gcnew System::Windows::Forms::TrackBar());
			this->objScaleYLabel = (gcnew System::Windows::Forms::Label());
			this->objScaleXBar = (gcnew System::Windows::Forms::TrackBar());
			this->objScaleXLabel = (gcnew System::Windows::Forms::Label());
			this->objRotationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->objRotZBar = (gcnew System::Windows::Forms::TrackBar());
			this->objRotZLabel = (gcnew System::Windows::Forms::Label());
			this->objRotYBar = (gcnew System::Windows::Forms::TrackBar());
			this->objRotYLabel = (gcnew System::Windows::Forms::Label());
			this->objRotXBar = (gcnew System::Windows::Forms::TrackBar());
			this->objRotXLabel = (gcnew System::Windows::Forms::Label());
			this->objReflectionGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->objReflectionYZCheckbox = (gcnew System::Windows::Forms::CheckBox());
			this->objReflectionXZCheckbox = (gcnew System::Windows::Forms::CheckBox());
			this->objReflectionXYCheckbox = (gcnew System::Windows::Forms::CheckBox());
			this->cameraTabPage = (gcnew System::Windows::Forms::TabPage());
			this->camFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->resetCamButton = (gcnew System::Windows::Forms::Button());
			this->cameraPosGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->camPosZBar = (gcnew System::Windows::Forms::TrackBar());
			this->camPosZLabel = (gcnew System::Windows::Forms::Label());
			this->camPosYBar = (gcnew System::Windows::Forms::TrackBar());
			this->camPosYLabel = (gcnew System::Windows::Forms::Label());
			this->camPosXBar = (gcnew System::Windows::Forms::TrackBar());
			this->camPosXLabel = (gcnew System::Windows::Forms::Label());
			this->camProjectionGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->orthoButton = (gcnew System::Windows::Forms::RadioButton());
			this->perspectiveButton = (gcnew System::Windows::Forms::RadioButton());
			this->camRotationGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->camRotYawBar = (gcnew System::Windows::Forms::TrackBar());
			this->camYawLabel = (gcnew System::Windows::Forms::Label());
			this->camRotPitchBar = (gcnew System::Windows::Forms::TrackBar());
			this->camPitchLabel = (gcnew System::Windows::Forms::Label());
			this->lightingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->lightFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->lightResetButton = (gcnew System::Windows::Forms::Button());
			this->lightParamsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->lightSpecBar = (gcnew System::Windows::Forms::TrackBar());
			this->specLightLabel = (gcnew System::Windows::Forms::Label());
			this->lightDiffuseBar = (gcnew System::Windows::Forms::TrackBar());
			this->lightDiffuseLabel = (gcnew System::Windows::Forms::Label());
			this->lightAmbiTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->lightAmbiLabel = (gcnew System::Windows::Forms::Label());
			this->lightColorButton = (gcnew System::Windows::Forms::Button());
			this->lightColorLabel = (gcnew System::Windows::Forms::Label());
			this->lightModeGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->flatLightRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->gouraudLightRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->phongLightRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->noLightRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->lightPosGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->lightPosZBar = (gcnew System::Windows::Forms::TrackBar());
			this->lightPosZLabel = (gcnew System::Windows::Forms::Label());
			this->lightPosYBar = (gcnew System::Windows::Forms::TrackBar());
			this->lightPosYLabel = (gcnew System::Windows::Forms::Label());
			this->lightPosXBar = (gcnew System::Windows::Forms::TrackBar());
			this->lightPosXLabel = (gcnew System::Windows::Forms::Label());
			this->matTabPage = (gcnew System::Windows::Forms::TabPage());
			this->matFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->resetMatButton = (gcnew System::Windows::Forms::Button());
			this->matParamsGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->shineMatBar = (gcnew System::Windows::Forms::TrackBar());
			this->shineMatLabel = (gcnew System::Windows::Forms::Label());
			this->specMatBar = (gcnew System::Windows::Forms::TrackBar());
			this->specMatLabel = (gcnew System::Windows::Forms::Label());
			this->diffMatBar = (gcnew System::Windows::Forms::TrackBar());
			this->diffMatLabel = (gcnew System::Windows::Forms::Label());
			this->ambiMatBar = (gcnew System::Windows::Forms::TrackBar());
			this->ambiMatLabel = (gcnew System::Windows::Forms::Label());
			this->matColorButton = (gcnew System::Windows::Forms::Button());
			this->matColorLabel = (gcnew System::Windows::Forms::Label());
			this->otherTabPage = (gcnew System::Windows::Forms::TabPage());
			this->otherFlowLayoutPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->colorGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->selectedColorButton = (gcnew System::Windows::Forms::Button());
			this->selectedColorLabel = (gcnew System::Windows::Forms::Label());
			this->wfColorButton = (gcnew System::Windows::Forms::Button());
			this->wfColorLabel = (gcnew System::Windows::Forms::Label());
			this->bgColorButton = (gcnew System::Windows::Forms::Button());
			this->bgColorLabel = (gcnew System::Windows::Forms::Label());
			this->drawingModeGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->bothRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->solidRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->wfRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->cullGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->cullOffRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->cullOnRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->objCountLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->bgColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->wfColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->selectedColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lightColorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->menuStrip->SuspendLayout();
			this->tableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->tabControl->SuspendLayout();
			this->objectTabPage->SuspendLayout();
			this->objFlowLayoutPanet->SuspendLayout();
			this->selectionTableLayoutPanel->SuspendLayout();
			this->objPosGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objPosZBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objPosYBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objPosXBar))->BeginInit();
			this->objScaleGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objScaleZBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objScaleYBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objScaleXBar))->BeginInit();
			this->objRotationGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objRotZBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objRotYBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objRotXBar))->BeginInit();
			this->objReflectionGroupBox->SuspendLayout();
			this->cameraTabPage->SuspendLayout();
			this->camFlowLayoutPanel->SuspendLayout();
			this->cameraPosGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPosZBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPosYBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPosXBar))->BeginInit();
			this->camProjectionGroupBox->SuspendLayout();
			this->camRotationGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotYawBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotPitchBar))->BeginInit();
			this->lightingTabPage->SuspendLayout();
			this->lightFlowLayoutPanel->SuspendLayout();
			this->lightParamsGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightSpecBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightDiffuseBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightAmbiTrackBar))->BeginInit();
			this->lightModeGroupBox->SuspendLayout();
			this->lightPosGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightPosZBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightPosYBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightPosXBar))->BeginInit();
			this->matTabPage->SuspendLayout();
			this->matFlowLayoutPanel->SuspendLayout();
			this->matParamsGroupBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->shineMatBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specMatBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->diffMatBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ambiMatBar))->BeginInit();
			this->otherTabPage->SuspendLayout();
			this->otherFlowLayoutPanel->SuspendLayout();
			this->colorGroupBox->SuspendLayout();
			this->drawingModeGroupBox->SuspendLayout();
			this->cullGroupBox->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(914, 28);
			this->menuStrip->TabIndex = 1;
			this->menuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->aboutToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(129, 26);
			this->openToolStripMenuItem->Text = L"Open...";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(129, 26);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::aboutToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(129, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// tableLayoutPanel
			// 
			this->tableLayoutPanel->ColumnCount = 2;
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				273)));
			this->tableLayoutPanel->Controls->Add(this->pictureBox, 0, 0);
			this->tableLayoutPanel->Controls->Add(this->tabControl, 1, 0);
			this->tableLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel->Location = System::Drawing::Point(0, 28);
			this->tableLayoutPanel->Name = L"tableLayoutPanel";
			this->tableLayoutPanel->RowCount = 2;
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel->Size = System::Drawing::Size(914, 668);
			this->tableLayoutPanel->TabIndex = 2;
			// 
			// pictureBox
			// 
			this->pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox->Location = System::Drawing::Point(3, 3);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(635, 642);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->objectTabPage);
			this->tabControl->Controls->Add(this->cameraTabPage);
			this->tabControl->Controls->Add(this->lightingTabPage);
			this->tabControl->Controls->Add(this->matTabPage);
			this->tabControl->Controls->Add(this->otherTabPage);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(644, 3);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(267, 642);
			this->tabControl->TabIndex = 1;
			// 
			// objectTabPage
			// 
			this->objectTabPage->BackColor = System::Drawing::SystemColors::Control;
			this->objectTabPage->Controls->Add(this->objFlowLayoutPanet);
			this->objectTabPage->Location = System::Drawing::Point(4, 25);
			this->objectTabPage->Name = L"objectTabPage";
			this->objectTabPage->Padding = System::Windows::Forms::Padding(3);
			this->objectTabPage->Size = System::Drawing::Size(259, 613);
			this->objectTabPage->TabIndex = 0;
			this->objectTabPage->Text = L"Object";
			// 
			// objFlowLayoutPanet
			// 
			this->objFlowLayoutPanet->AutoScroll = true;
			this->objFlowLayoutPanet->BackColor = System::Drawing::SystemColors::Control;
			this->objFlowLayoutPanet->Controls->Add(this->selectionTableLayoutPanel);
			this->objFlowLayoutPanet->Controls->Add(this->deleteObjButton);
			this->objFlowLayoutPanet->Controls->Add(this->resetObjButton);
			this->objFlowLayoutPanet->Controls->Add(this->objPosGroupBox);
			this->objFlowLayoutPanet->Controls->Add(this->objScaleGroupBox);
			this->objFlowLayoutPanet->Controls->Add(this->objRotationGroupBox);
			this->objFlowLayoutPanet->Controls->Add(this->objReflectionGroupBox);
			this->objFlowLayoutPanet->Dock = System::Windows::Forms::DockStyle::Fill;
			this->objFlowLayoutPanet->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->objFlowLayoutPanet->Location = System::Drawing::Point(3, 3);
			this->objFlowLayoutPanet->Name = L"objFlowLayoutPanet";
			this->objFlowLayoutPanet->Size = System::Drawing::Size(253, 607);
			this->objFlowLayoutPanet->TabIndex = 6;
			this->objFlowLayoutPanet->WrapContents = false;
			// 
			// selectionTableLayoutPanel
			// 
			this->selectionTableLayoutPanel->ColumnCount = 2;
			this->selectionTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->selectionTableLayoutPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->selectionTableLayoutPanel->Controls->Add(this->nextObjButton, 1, 0);
			this->selectionTableLayoutPanel->Controls->Add(this->prevObjButton, 0, 0);
			this->selectionTableLayoutPanel->Location = System::Drawing::Point(3, 3);
			this->selectionTableLayoutPanel->Name = L"selectionTableLayoutPanel";
			this->selectionTableLayoutPanel->RowCount = 1;
			this->selectionTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->selectionTableLayoutPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				46)));
			this->selectionTableLayoutPanel->Size = System::Drawing::Size(224, 46);
			this->selectionTableLayoutPanel->TabIndex = 18;
			// 
			// nextObjButton
			// 
			this->nextObjButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->nextObjButton->Location = System::Drawing::Point(115, 3);
			this->nextObjButton->Name = L"nextObjButton";
			this->nextObjButton->Size = System::Drawing::Size(106, 40);
			this->nextObjButton->TabIndex = 14;
			this->nextObjButton->Text = L"Next";
			this->nextObjButton->UseVisualStyleBackColor = true;
			this->nextObjButton->Click += gcnew System::EventHandler(this, &MainForm::nextObjButton_Click);
			// 
			// prevObjButton
			// 
			this->prevObjButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->prevObjButton->Location = System::Drawing::Point(3, 3);
			this->prevObjButton->Name = L"prevObjButton";
			this->prevObjButton->Size = System::Drawing::Size(106, 40);
			this->prevObjButton->TabIndex = 15;
			this->prevObjButton->Text = L"Previous";
			this->prevObjButton->UseVisualStyleBackColor = true;
			this->prevObjButton->Click += gcnew System::EventHandler(this, &MainForm::prevObjButton_Click);
			// 
			// deleteObjButton
			// 
			this->deleteObjButton->Location = System::Drawing::Point(3, 55);
			this->deleteObjButton->Name = L"deleteObjButton";
			this->deleteObjButton->Size = System::Drawing::Size(224, 23);
			this->deleteObjButton->TabIndex = 13;
			this->deleteObjButton->Text = L"Delete";
			this->deleteObjButton->UseVisualStyleBackColor = true;
			this->deleteObjButton->Click += gcnew System::EventHandler(this, &MainForm::deleteObjButton_Click);
			// 
			// resetObjButton
			// 
			this->resetObjButton->Location = System::Drawing::Point(3, 84);
			this->resetObjButton->Name = L"resetObjButton";
			this->resetObjButton->Size = System::Drawing::Size(224, 23);
			this->resetObjButton->TabIndex = 16;
			this->resetObjButton->Text = L"Reset";
			this->resetObjButton->UseVisualStyleBackColor = true;
			this->resetObjButton->Click += gcnew System::EventHandler(this, &MainForm::resetObjButton_Click);
			// 
			// objPosGroupBox
			// 
			this->objPosGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->objPosGroupBox->AutoSize = true;
			this->objPosGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->objPosGroupBox->Controls->Add(this->objPosZBar);
			this->objPosGroupBox->Controls->Add(this->objPosZLabel);
			this->objPosGroupBox->Controls->Add(this->objPosYBar);
			this->objPosGroupBox->Controls->Add(this->objPosYLabel);
			this->objPosGroupBox->Controls->Add(this->objPosXBar);
			this->objPosGroupBox->Controls->Add(this->objPosXLabel);
			this->objPosGroupBox->Location = System::Drawing::Point(3, 113);
			this->objPosGroupBox->Name = L"objPosGroupBox";
			this->objPosGroupBox->Size = System::Drawing::Size(224, 236);
			this->objPosGroupBox->TabIndex = 3;
			this->objPosGroupBox->TabStop = false;
			this->objPosGroupBox->Text = L"Position";
			// 
			// objPosZBar
			// 
			this->objPosZBar->Location = System::Drawing::Point(6, 159);
			this->objPosZBar->Maximum = 100;
			this->objPosZBar->Minimum = -100;
			this->objPosZBar->Name = L"objPosZBar";
			this->objPosZBar->Size = System::Drawing::Size(212, 56);
			this->objPosZBar->TabIndex = 10;
			this->objPosZBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objPosZBar->Scroll += gcnew System::EventHandler(this, &MainForm::objPosZBar_Scroll);
			// 
			// objPosZLabel
			// 
			this->objPosZLabel->AutoSize = true;
			this->objPosZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objPosZLabel->Location = System::Drawing::Point(6, 136);
			this->objPosZLabel->Name = L"objPosZLabel";
			this->objPosZLabel->Size = System::Drawing::Size(46, 17);
			this->objPosZLabel->TabIndex = 11;
			this->objPosZLabel->Text = L"Z Axis";
			this->objPosZLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objPosYBar
			// 
			this->objPosYBar->Location = System::Drawing::Point(6, 100);
			this->objPosYBar->Maximum = 100;
			this->objPosYBar->Minimum = -100;
			this->objPosYBar->Name = L"objPosYBar";
			this->objPosYBar->Size = System::Drawing::Size(212, 56);
			this->objPosYBar->TabIndex = 8;
			this->objPosYBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objPosYBar->Scroll += gcnew System::EventHandler(this, &MainForm::objPosYBar_Scroll);
			// 
			// objPosYLabel
			// 
			this->objPosYLabel->AutoSize = true;
			this->objPosYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objPosYLabel->Location = System::Drawing::Point(6, 77);
			this->objPosYLabel->Name = L"objPosYLabel";
			this->objPosYLabel->Size = System::Drawing::Size(46, 17);
			this->objPosYLabel->TabIndex = 9;
			this->objPosYLabel->Text = L"Y Axis";
			this->objPosYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objPosXBar
			// 
			this->objPosXBar->Location = System::Drawing::Point(6, 41);
			this->objPosXBar->Maximum = 100;
			this->objPosXBar->Minimum = -100;
			this->objPosXBar->Name = L"objPosXBar";
			this->objPosXBar->Size = System::Drawing::Size(212, 56);
			this->objPosXBar->TabIndex = 6;
			this->objPosXBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objPosXBar->Scroll += gcnew System::EventHandler(this, &MainForm::objPosXBar_Scroll);
			// 
			// objPosXLabel
			// 
			this->objPosXLabel->AutoSize = true;
			this->objPosXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objPosXLabel->Location = System::Drawing::Point(6, 18);
			this->objPosXLabel->Name = L"objPosXLabel";
			this->objPosXLabel->Size = System::Drawing::Size(46, 17);
			this->objPosXLabel->TabIndex = 7;
			this->objPosXLabel->Text = L"X Axis";
			this->objPosXLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objScaleGroupBox
			// 
			this->objScaleGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->objScaleGroupBox->AutoSize = true;
			this->objScaleGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->objScaleGroupBox->Controls->Add(this->objScaleZBar);
			this->objScaleGroupBox->Controls->Add(this->objScaleZLabel);
			this->objScaleGroupBox->Controls->Add(this->objScaleYBar);
			this->objScaleGroupBox->Controls->Add(this->objScaleYLabel);
			this->objScaleGroupBox->Controls->Add(this->objScaleXBar);
			this->objScaleGroupBox->Controls->Add(this->objScaleXLabel);
			this->objScaleGroupBox->Location = System::Drawing::Point(3, 355);
			this->objScaleGroupBox->Name = L"objScaleGroupBox";
			this->objScaleGroupBox->Size = System::Drawing::Size(224, 236);
			this->objScaleGroupBox->TabIndex = 4;
			this->objScaleGroupBox->TabStop = false;
			this->objScaleGroupBox->Text = L"Scale";
			// 
			// objScaleZBar
			// 
			this->objScaleZBar->Location = System::Drawing::Point(6, 159);
			this->objScaleZBar->Maximum = 20;
			this->objScaleZBar->Minimum = 1;
			this->objScaleZBar->Name = L"objScaleZBar";
			this->objScaleZBar->Size = System::Drawing::Size(212, 56);
			this->objScaleZBar->TabIndex = 10;
			this->objScaleZBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objScaleZBar->Value = 10;
			this->objScaleZBar->Scroll += gcnew System::EventHandler(this, &MainForm::objScaleZBar_Scroll);
			// 
			// objScaleZLabel
			// 
			this->objScaleZLabel->AutoSize = true;
			this->objScaleZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objScaleZLabel->Location = System::Drawing::Point(6, 136);
			this->objScaleZLabel->Name = L"objScaleZLabel";
			this->objScaleZLabel->Size = System::Drawing::Size(46, 17);
			this->objScaleZLabel->TabIndex = 11;
			this->objScaleZLabel->Text = L"Z Axis";
			this->objScaleZLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objScaleYBar
			// 
			this->objScaleYBar->Location = System::Drawing::Point(6, 100);
			this->objScaleYBar->Maximum = 20;
			this->objScaleYBar->Minimum = 1;
			this->objScaleYBar->Name = L"objScaleYBar";
			this->objScaleYBar->Size = System::Drawing::Size(212, 56);
			this->objScaleYBar->TabIndex = 8;
			this->objScaleYBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objScaleYBar->Value = 10;
			this->objScaleYBar->Scroll += gcnew System::EventHandler(this, &MainForm::objScaleYBar_Scroll);
			// 
			// objScaleYLabel
			// 
			this->objScaleYLabel->AutoSize = true;
			this->objScaleYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objScaleYLabel->Location = System::Drawing::Point(6, 77);
			this->objScaleYLabel->Name = L"objScaleYLabel";
			this->objScaleYLabel->Size = System::Drawing::Size(46, 17);
			this->objScaleYLabel->TabIndex = 9;
			this->objScaleYLabel->Text = L"Y Axis";
			this->objScaleYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objScaleXBar
			// 
			this->objScaleXBar->Location = System::Drawing::Point(6, 41);
			this->objScaleXBar->Maximum = 20;
			this->objScaleXBar->Minimum = 1;
			this->objScaleXBar->Name = L"objScaleXBar";
			this->objScaleXBar->Size = System::Drawing::Size(212, 56);
			this->objScaleXBar->TabIndex = 6;
			this->objScaleXBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objScaleXBar->Value = 10;
			this->objScaleXBar->Scroll += gcnew System::EventHandler(this, &MainForm::objScaleXBar_Scroll);
			// 
			// objScaleXLabel
			// 
			this->objScaleXLabel->AutoSize = true;
			this->objScaleXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objScaleXLabel->Location = System::Drawing::Point(6, 18);
			this->objScaleXLabel->Name = L"objScaleXLabel";
			this->objScaleXLabel->Size = System::Drawing::Size(46, 17);
			this->objScaleXLabel->TabIndex = 7;
			this->objScaleXLabel->Text = L"X Axis";
			this->objScaleXLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objRotationGroupBox
			// 
			this->objRotationGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->objRotationGroupBox->AutoSize = true;
			this->objRotationGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->objRotationGroupBox->Controls->Add(this->objRotZBar);
			this->objRotationGroupBox->Controls->Add(this->objRotZLabel);
			this->objRotationGroupBox->Controls->Add(this->objRotYBar);
			this->objRotationGroupBox->Controls->Add(this->objRotYLabel);
			this->objRotationGroupBox->Controls->Add(this->objRotXBar);
			this->objRotationGroupBox->Controls->Add(this->objRotXLabel);
			this->objRotationGroupBox->Location = System::Drawing::Point(3, 597);
			this->objRotationGroupBox->Name = L"objRotationGroupBox";
			this->objRotationGroupBox->Size = System::Drawing::Size(224, 236);
			this->objRotationGroupBox->TabIndex = 5;
			this->objRotationGroupBox->TabStop = false;
			this->objRotationGroupBox->Text = L"Rotation";
			// 
			// objRotZBar
			// 
			this->objRotZBar->Location = System::Drawing::Point(6, 159);
			this->objRotZBar->Maximum = 360;
			this->objRotZBar->Name = L"objRotZBar";
			this->objRotZBar->Size = System::Drawing::Size(212, 56);
			this->objRotZBar->TabIndex = 10;
			this->objRotZBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objRotZBar->Scroll += gcnew System::EventHandler(this, &MainForm::objRotZBar_Scroll);
			// 
			// objRotZLabel
			// 
			this->objRotZLabel->AutoSize = true;
			this->objRotZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objRotZLabel->Location = System::Drawing::Point(6, 136);
			this->objRotZLabel->Name = L"objRotZLabel";
			this->objRotZLabel->Size = System::Drawing::Size(118, 17);
			this->objRotZLabel->TabIndex = 11;
			this->objRotZLabel->Text = L"Z Axis (XY Plane)";
			this->objRotZLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objRotYBar
			// 
			this->objRotYBar->Location = System::Drawing::Point(6, 100);
			this->objRotYBar->Maximum = 360;
			this->objRotYBar->Name = L"objRotYBar";
			this->objRotYBar->Size = System::Drawing::Size(212, 56);
			this->objRotYBar->TabIndex = 8;
			this->objRotYBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objRotYBar->Scroll += gcnew System::EventHandler(this, &MainForm::objRotYBar_Scroll);
			// 
			// objRotYLabel
			// 
			this->objRotYLabel->AutoSize = true;
			this->objRotYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objRotYLabel->Location = System::Drawing::Point(6, 77);
			this->objRotYLabel->Name = L"objRotYLabel";
			this->objRotYLabel->Size = System::Drawing::Size(118, 17);
			this->objRotYLabel->TabIndex = 9;
			this->objRotYLabel->Text = L"Y Axis (XZ Plane)";
			this->objRotYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objRotXBar
			// 
			this->objRotXBar->Location = System::Drawing::Point(6, 41);
			this->objRotXBar->Maximum = 360;
			this->objRotXBar->Name = L"objRotXBar";
			this->objRotXBar->Size = System::Drawing::Size(212, 56);
			this->objRotXBar->TabIndex = 6;
			this->objRotXBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->objRotXBar->Scroll += gcnew System::EventHandler(this, &MainForm::objRotXBar_Scroll);
			// 
			// objRotXLabel
			// 
			this->objRotXLabel->AutoSize = true;
			this->objRotXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->objRotXLabel->Location = System::Drawing::Point(6, 18);
			this->objRotXLabel->Name = L"objRotXLabel";
			this->objRotXLabel->Size = System::Drawing::Size(118, 17);
			this->objRotXLabel->TabIndex = 7;
			this->objRotXLabel->Text = L"X Axis (YZ Plane)";
			this->objRotXLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// objReflectionGroupBox
			// 
			this->objReflectionGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->objReflectionGroupBox->AutoSize = true;
			this->objReflectionGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->objReflectionGroupBox->Controls->Add(this->objReflectionYZCheckbox);
			this->objReflectionGroupBox->Controls->Add(this->objReflectionXZCheckbox);
			this->objReflectionGroupBox->Controls->Add(this->objReflectionXYCheckbox);
			this->objReflectionGroupBox->Location = System::Drawing::Point(3, 839);
			this->objReflectionGroupBox->Name = L"objReflectionGroupBox";
			this->objReflectionGroupBox->Size = System::Drawing::Size(224, 117);
			this->objReflectionGroupBox->TabIndex = 12;
			this->objReflectionGroupBox->TabStop = false;
			this->objReflectionGroupBox->Text = L"Reflection";
			// 
			// objReflectionYZCheckbox
			// 
			this->objReflectionYZCheckbox->AutoSize = true;
			this->objReflectionYZCheckbox->Location = System::Drawing::Point(6, 75);
			this->objReflectionYZCheckbox->Name = L"objReflectionYZCheckbox";
			this->objReflectionYZCheckbox->Size = System::Drawing::Size(95, 21);
			this->objReflectionYZCheckbox->TabIndex = 14;
			this->objReflectionYZCheckbox->Text = L"Across YZ";
			this->objReflectionYZCheckbox->UseVisualStyleBackColor = true;
			this->objReflectionYZCheckbox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::objReflectionYZCheckbox_CheckedChanged);
			// 
			// objReflectionXZCheckbox
			// 
			this->objReflectionXZCheckbox->AutoSize = true;
			this->objReflectionXZCheckbox->Location = System::Drawing::Point(6, 48);
			this->objReflectionXZCheckbox->Name = L"objReflectionXZCheckbox";
			this->objReflectionXZCheckbox->Size = System::Drawing::Size(95, 21);
			this->objReflectionXZCheckbox->TabIndex = 13;
			this->objReflectionXZCheckbox->Text = L"Across XZ";
			this->objReflectionXZCheckbox->UseVisualStyleBackColor = true;
			this->objReflectionXZCheckbox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::objReflectionXZCheckbox_CheckedChanged);
			// 
			// objReflectionXYCheckbox
			// 
			this->objReflectionXYCheckbox->AutoSize = true;
			this->objReflectionXYCheckbox->Location = System::Drawing::Point(6, 21);
			this->objReflectionXYCheckbox->Name = L"objReflectionXYCheckbox";
			this->objReflectionXYCheckbox->Size = System::Drawing::Size(95, 21);
			this->objReflectionXYCheckbox->TabIndex = 12;
			this->objReflectionXYCheckbox->Text = L"Across XY";
			this->objReflectionXYCheckbox->UseVisualStyleBackColor = true;
			this->objReflectionXYCheckbox->CheckedChanged += gcnew System::EventHandler(this, &MainForm::objReflectionXYCheckbox_CheckedChanged);
			// 
			// cameraTabPage
			// 
			this->cameraTabPage->BackColor = System::Drawing::SystemColors::Control;
			this->cameraTabPage->Controls->Add(this->camFlowLayoutPanel);
			this->cameraTabPage->Location = System::Drawing::Point(4, 25);
			this->cameraTabPage->Name = L"cameraTabPage";
			this->cameraTabPage->Padding = System::Windows::Forms::Padding(3);
			this->cameraTabPage->Size = System::Drawing::Size(259, 613);
			this->cameraTabPage->TabIndex = 1;
			this->cameraTabPage->Text = L"Camera";
			// 
			// camFlowLayoutPanel
			// 
			this->camFlowLayoutPanel->AutoScroll = true;
			this->camFlowLayoutPanel->Controls->Add(this->resetCamButton);
			this->camFlowLayoutPanel->Controls->Add(this->cameraPosGroupBox);
			this->camFlowLayoutPanel->Controls->Add(this->camProjectionGroupBox);
			this->camFlowLayoutPanel->Controls->Add(this->camRotationGroupBox);
			this->camFlowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->camFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->camFlowLayoutPanel->Location = System::Drawing::Point(3, 3);
			this->camFlowLayoutPanel->Name = L"camFlowLayoutPanel";
			this->camFlowLayoutPanel->Size = System::Drawing::Size(253, 607);
			this->camFlowLayoutPanel->TabIndex = 5;
			this->camFlowLayoutPanel->WrapContents = false;
			// 
			// resetCamButton
			// 
			this->resetCamButton->Location = System::Drawing::Point(3, 3);
			this->resetCamButton->Name = L"resetCamButton";
			this->resetCamButton->Size = System::Drawing::Size(224, 23);
			this->resetCamButton->TabIndex = 17;
			this->resetCamButton->Text = L"Reset";
			this->resetCamButton->UseVisualStyleBackColor = true;
			this->resetCamButton->Click += gcnew System::EventHandler(this, &MainForm::resetCamButton_Click);
			// 
			// cameraPosGroupBox
			// 
			this->cameraPosGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cameraPosGroupBox->AutoSize = true;
			this->cameraPosGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->cameraPosGroupBox->Controls->Add(this->camPosZBar);
			this->cameraPosGroupBox->Controls->Add(this->camPosZLabel);
			this->cameraPosGroupBox->Controls->Add(this->camPosYBar);
			this->cameraPosGroupBox->Controls->Add(this->camPosYLabel);
			this->cameraPosGroupBox->Controls->Add(this->camPosXBar);
			this->cameraPosGroupBox->Controls->Add(this->camPosXLabel);
			this->cameraPosGroupBox->Location = System::Drawing::Point(3, 32);
			this->cameraPosGroupBox->Name = L"cameraPosGroupBox";
			this->cameraPosGroupBox->Size = System::Drawing::Size(224, 236);
			this->cameraPosGroupBox->TabIndex = 3;
			this->cameraPosGroupBox->TabStop = false;
			this->cameraPosGroupBox->Text = L"Position";
			// 
			// camPosZBar
			// 
			this->camPosZBar->Location = System::Drawing::Point(6, 159);
			this->camPosZBar->Maximum = 300;
			this->camPosZBar->Minimum = 30;
			this->camPosZBar->Name = L"camPosZBar";
			this->camPosZBar->Size = System::Drawing::Size(212, 56);
			this->camPosZBar->TabIndex = 30;
			this->camPosZBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->camPosZBar->Value = 100;
			this->camPosZBar->Scroll += gcnew System::EventHandler(this, &MainForm::camPosZBar_Scroll);
			// 
			// camPosZLabel
			// 
			this->camPosZLabel->AutoSize = true;
			this->camPosZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->camPosZLabel->Location = System::Drawing::Point(6, 136);
			this->camPosZLabel->Name = L"camPosZLabel";
			this->camPosZLabel->Size = System::Drawing::Size(46, 17);
			this->camPosZLabel->TabIndex = 11;
			this->camPosZLabel->Text = L"Z Axis";
			this->camPosZLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// camPosYBar
			// 
			this->camPosYBar->Location = System::Drawing::Point(6, 100);
			this->camPosYBar->Maximum = 100;
			this->camPosYBar->Minimum = -100;
			this->camPosYBar->Name = L"camPosYBar";
			this->camPosYBar->Size = System::Drawing::Size(212, 56);
			this->camPosYBar->TabIndex = 8;
			this->camPosYBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->camPosYBar->Scroll += gcnew System::EventHandler(this, &MainForm::camPosYBar_Scroll);
			// 
			// camPosYLabel
			// 
			this->camPosYLabel->AutoSize = true;
			this->camPosYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->camPosYLabel->Location = System::Drawing::Point(6, 77);
			this->camPosYLabel->Name = L"camPosYLabel";
			this->camPosYLabel->Size = System::Drawing::Size(46, 17);
			this->camPosYLabel->TabIndex = 9;
			this->camPosYLabel->Text = L"Y Axis";
			this->camPosYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// camPosXBar
			// 
			this->camPosXBar->Location = System::Drawing::Point(6, 41);
			this->camPosXBar->Maximum = 100;
			this->camPosXBar->Minimum = -100;
			this->camPosXBar->Name = L"camPosXBar";
			this->camPosXBar->Size = System::Drawing::Size(212, 56);
			this->camPosXBar->TabIndex = 6;
			this->camPosXBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->camPosXBar->Scroll += gcnew System::EventHandler(this, &MainForm::camPosXBar_Scroll);
			// 
			// camPosXLabel
			// 
			this->camPosXLabel->AutoSize = true;
			this->camPosXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->camPosXLabel->Location = System::Drawing::Point(6, 18);
			this->camPosXLabel->Name = L"camPosXLabel";
			this->camPosXLabel->Size = System::Drawing::Size(46, 17);
			this->camPosXLabel->TabIndex = 7;
			this->camPosXLabel->Text = L"X Axis";
			this->camPosXLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// camProjectionGroupBox
			// 
			this->camProjectionGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->camProjectionGroupBox->AutoSize = true;
			this->camProjectionGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->camProjectionGroupBox->Controls->Add(this->orthoButton);
			this->camProjectionGroupBox->Controls->Add(this->perspectiveButton);
			this->camProjectionGroupBox->Location = System::Drawing::Point(3, 274);
			this->camProjectionGroupBox->Name = L"camProjectionGroupBox";
			this->camProjectionGroupBox->Size = System::Drawing::Size(224, 93);
			this->camProjectionGroupBox->TabIndex = 12;
			this->camProjectionGroupBox->TabStop = false;
			this->camProjectionGroupBox->Text = L"Projection";
			// 
			// orthoButton
			// 
			this->orthoButton->AutoSize = true;
			this->orthoButton->Location = System::Drawing::Point(6, 51);
			this->orthoButton->Name = L"orthoButton";
			this->orthoButton->Size = System::Drawing::Size(112, 21);
			this->orthoButton->TabIndex = 1;
			this->orthoButton->Text = L"Orthographic";
			this->orthoButton->UseVisualStyleBackColor = true;
			this->orthoButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::orthoButton_CheckedChanged);
			// 
			// perspectiveButton
			// 
			this->perspectiveButton->AutoSize = true;
			this->perspectiveButton->Checked = true;
			this->perspectiveButton->Location = System::Drawing::Point(6, 24);
			this->perspectiveButton->Name = L"perspectiveButton";
			this->perspectiveButton->Size = System::Drawing::Size(103, 21);
			this->perspectiveButton->TabIndex = 0;
			this->perspectiveButton->TabStop = true;
			this->perspectiveButton->Text = L"Perspective";
			this->perspectiveButton->UseVisualStyleBackColor = true;
			this->perspectiveButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::perspectiveButton_CheckedChanged);
			// 
			// camRotationGroupBox
			// 
			this->camRotationGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->camRotationGroupBox->AutoSize = true;
			this->camRotationGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->camRotationGroupBox->Controls->Add(this->camRotYawBar);
			this->camRotationGroupBox->Controls->Add(this->camYawLabel);
			this->camRotationGroupBox->Controls->Add(this->camRotPitchBar);
			this->camRotationGroupBox->Controls->Add(this->camPitchLabel);
			this->camRotationGroupBox->Location = System::Drawing::Point(3, 373);
			this->camRotationGroupBox->Name = L"camRotationGroupBox";
			this->camRotationGroupBox->Size = System::Drawing::Size(224, 177);
			this->camRotationGroupBox->TabIndex = 4;
			this->camRotationGroupBox->TabStop = false;
			this->camRotationGroupBox->Text = L"Rotation";
			// 
			// camRotYawBar
			// 
			this->camRotYawBar->Location = System::Drawing::Point(6, 100);
			this->camRotYawBar->Maximum = 269;
			this->camRotYawBar->Minimum = 91;
			this->camRotYawBar->Name = L"camRotYawBar";
			this->camRotYawBar->Size = System::Drawing::Size(212, 56);
			this->camRotYawBar->TabIndex = 8;
			this->camRotYawBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->camRotYawBar->Value = 180;
			this->camRotYawBar->Scroll += gcnew System::EventHandler(this, &MainForm::camRotYawBar_Scroll);
			// 
			// camYawLabel
			// 
			this->camYawLabel->AutoSize = true;
			this->camYawLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->camYawLabel->Location = System::Drawing::Point(6, 77);
			this->camYawLabel->Name = L"camYawLabel";
			this->camYawLabel->Size = System::Drawing::Size(34, 17);
			this->camYawLabel->TabIndex = 9;
			this->camYawLabel->Text = L"Yaw";
			this->camYawLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// camRotPitchBar
			// 
			this->camRotPitchBar->Location = System::Drawing::Point(6, 41);
			this->camRotPitchBar->Maximum = 45;
			this->camRotPitchBar->Minimum = -45;
			this->camRotPitchBar->Name = L"camRotPitchBar";
			this->camRotPitchBar->Size = System::Drawing::Size(212, 56);
			this->camRotPitchBar->TabIndex = 6;
			this->camRotPitchBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->camRotPitchBar->Scroll += gcnew System::EventHandler(this, &MainForm::camRotPitchBar_Scroll);
			// 
			// camPitchLabel
			// 
			this->camPitchLabel->AutoSize = true;
			this->camPitchLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->camPitchLabel->Location = System::Drawing::Point(6, 18);
			this->camPitchLabel->Name = L"camPitchLabel";
			this->camPitchLabel->Size = System::Drawing::Size(39, 17);
			this->camPitchLabel->TabIndex = 7;
			this->camPitchLabel->Text = L"Pitch";
			this->camPitchLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lightingTabPage
			// 
			this->lightingTabPage->BackColor = System::Drawing::SystemColors::Control;
			this->lightingTabPage->Controls->Add(this->lightFlowLayoutPanel);
			this->lightingTabPage->Location = System::Drawing::Point(4, 25);
			this->lightingTabPage->Name = L"lightingTabPage";
			this->lightingTabPage->Padding = System::Windows::Forms::Padding(3);
			this->lightingTabPage->Size = System::Drawing::Size(259, 613);
			this->lightingTabPage->TabIndex = 3;
			this->lightingTabPage->Text = L"Lighting";
			// 
			// lightFlowLayoutPanel
			// 
			this->lightFlowLayoutPanel->AutoScroll = true;
			this->lightFlowLayoutPanel->Controls->Add(this->lightResetButton);
			this->lightFlowLayoutPanel->Controls->Add(this->lightParamsGroupBox);
			this->lightFlowLayoutPanel->Controls->Add(this->lightModeGroupBox);
			this->lightFlowLayoutPanel->Controls->Add(this->lightPosGroupBox);
			this->lightFlowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lightFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->lightFlowLayoutPanel->Location = System::Drawing::Point(3, 3);
			this->lightFlowLayoutPanel->Name = L"lightFlowLayoutPanel";
			this->lightFlowLayoutPanel->Size = System::Drawing::Size(253, 607);
			this->lightFlowLayoutPanel->TabIndex = 1;
			this->lightFlowLayoutPanel->WrapContents = false;
			// 
			// lightResetButton
			// 
			this->lightResetButton->Location = System::Drawing::Point(3, 3);
			this->lightResetButton->Name = L"lightResetButton";
			this->lightResetButton->Size = System::Drawing::Size(224, 23);
			this->lightResetButton->TabIndex = 18;
			this->lightResetButton->Text = L"Reset";
			this->lightResetButton->UseVisualStyleBackColor = true;
			this->lightResetButton->Click += gcnew System::EventHandler(this, &MainForm::lightResetButton_Click);
			// 
			// lightParamsGroupBox
			// 
			this->lightParamsGroupBox->Controls->Add(this->lightSpecBar);
			this->lightParamsGroupBox->Controls->Add(this->specLightLabel);
			this->lightParamsGroupBox->Controls->Add(this->lightDiffuseBar);
			this->lightParamsGroupBox->Controls->Add(this->lightDiffuseLabel);
			this->lightParamsGroupBox->Controls->Add(this->lightAmbiTrackBar);
			this->lightParamsGroupBox->Controls->Add(this->lightAmbiLabel);
			this->lightParamsGroupBox->Controls->Add(this->lightColorButton);
			this->lightParamsGroupBox->Controls->Add(this->lightColorLabel);
			this->lightParamsGroupBox->Location = System::Drawing::Point(3, 32);
			this->lightParamsGroupBox->Name = L"lightParamsGroupBox";
			this->lightParamsGroupBox->Size = System::Drawing::Size(218, 256);
			this->lightParamsGroupBox->TabIndex = 0;
			this->lightParamsGroupBox->TabStop = false;
			this->lightParamsGroupBox->Text = L"Parameters";
			// 
			// lightSpecBar
			// 
			this->lightSpecBar->Location = System::Drawing::Point(9, 196);
			this->lightSpecBar->Maximum = 100;
			this->lightSpecBar->Minimum = 10;
			this->lightSpecBar->Name = L"lightSpecBar";
			this->lightSpecBar->Size = System::Drawing::Size(212, 56);
			this->lightSpecBar->TabIndex = 12;
			this->lightSpecBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->lightSpecBar->Value = 80;
			this->lightSpecBar->Scroll += gcnew System::EventHandler(this, &MainForm::lightSpecBar_Scroll);
			// 
			// specLightLabel
			// 
			this->specLightLabel->AutoSize = true;
			this->specLightLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->specLightLabel->Location = System::Drawing::Point(6, 173);
			this->specLightLabel->Name = L"specLightLabel";
			this->specLightLabel->Size = System::Drawing::Size(122, 17);
			this->specLightLabel->TabIndex = 13;
			this->specLightLabel->Text = L"Specular Strength";
			this->specLightLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lightDiffuseBar
			// 
			this->lightDiffuseBar->Location = System::Drawing::Point(9, 134);
			this->lightDiffuseBar->Maximum = 90;
			this->lightDiffuseBar->Minimum = 10;
			this->lightDiffuseBar->Name = L"lightDiffuseBar";
			this->lightDiffuseBar->Size = System::Drawing::Size(212, 56);
			this->lightDiffuseBar->TabIndex = 10;
			this->lightDiffuseBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->lightDiffuseBar->Value = 50;
			this->lightDiffuseBar->Scroll += gcnew System::EventHandler(this, &MainForm::lightDiffuseBar_Scroll);
			// 
			// lightDiffuseLabel
			// 
			this->lightDiffuseLabel->AutoSize = true;
			this->lightDiffuseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->lightDiffuseLabel->Location = System::Drawing::Point(6, 111);
			this->lightDiffuseLabel->Name = L"lightDiffuseLabel";
			this->lightDiffuseLabel->Size = System::Drawing::Size(110, 17);
			this->lightDiffuseLabel->TabIndex = 11;
			this->lightDiffuseLabel->Text = L"Diffuse Strength";
			this->lightDiffuseLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lightAmbiTrackBar
			// 
			this->lightAmbiTrackBar->Location = System::Drawing::Point(6, 72);
			this->lightAmbiTrackBar->Maximum = 90;
			this->lightAmbiTrackBar->Minimum = 10;
			this->lightAmbiTrackBar->Name = L"lightAmbiTrackBar";
			this->lightAmbiTrackBar->Size = System::Drawing::Size(212, 56);
			this->lightAmbiTrackBar->TabIndex = 8;
			this->lightAmbiTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->lightAmbiTrackBar->Value = 10;
			this->lightAmbiTrackBar->Scroll += gcnew System::EventHandler(this, &MainForm::lightAmbiTrackBar_Scroll);
			// 
			// lightAmbiLabel
			// 
			this->lightAmbiLabel->AutoSize = true;
			this->lightAmbiLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lightAmbiLabel->Location = System::Drawing::Point(6, 49);
			this->lightAmbiLabel->Name = L"lightAmbiLabel";
			this->lightAmbiLabel->Size = System::Drawing::Size(128, 17);
			this->lightAmbiLabel->TabIndex = 9;
			this->lightAmbiLabel->Text = L"Ambience Strength";
			this->lightAmbiLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lightColorButton
			// 
			this->lightColorButton->BackColor = System::Drawing::Color::White;
			this->lightColorButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->lightColorButton->Location = System::Drawing::Point(87, 19);
			this->lightColorButton->Name = L"lightColorButton";
			this->lightColorButton->Size = System::Drawing::Size(125, 23);
			this->lightColorButton->TabIndex = 1;
			this->lightColorButton->UseVisualStyleBackColor = false;
			this->lightColorButton->Click += gcnew System::EventHandler(this, &MainForm::lightColorButton_Click);
			// 
			// lightColorLabel
			// 
			this->lightColorLabel->AutoSize = true;
			this->lightColorLabel->Location = System::Drawing::Point(7, 22);
			this->lightColorLabel->Name = L"lightColorLabel";
			this->lightColorLabel->Size = System::Drawing::Size(41, 17);
			this->lightColorLabel->TabIndex = 0;
			this->lightColorLabel->Text = L"Color";
			// 
			// lightModeGroupBox
			// 
			this->lightModeGroupBox->Controls->Add(this->flatLightRadioButton);
			this->lightModeGroupBox->Controls->Add(this->gouraudLightRadioButton);
			this->lightModeGroupBox->Controls->Add(this->phongLightRadioButton);
			this->lightModeGroupBox->Controls->Add(this->noLightRadioButton);
			this->lightModeGroupBox->Location = System::Drawing::Point(3, 294);
			this->lightModeGroupBox->Name = L"lightModeGroupBox";
			this->lightModeGroupBox->Size = System::Drawing::Size(221, 131);
			this->lightModeGroupBox->TabIndex = 1;
			this->lightModeGroupBox->TabStop = false;
			this->lightModeGroupBox->Text = L"Mode";
			// 
			// flatLightRadioButton
			// 
			this->flatLightRadioButton->AutoSize = true;
			this->flatLightRadioButton->Location = System::Drawing::Point(6, 103);
			this->flatLightRadioButton->Name = L"flatLightRadioButton";
			this->flatLightRadioButton->Size = System::Drawing::Size(106, 21);
			this->flatLightRadioButton->TabIndex = 3;
			this->flatLightRadioButton->TabStop = true;
			this->flatLightRadioButton->Text = L"Flat Lighting";
			this->flatLightRadioButton->UseVisualStyleBackColor = true;
			this->flatLightRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::flatLightRadioButton_CheckedChanged);
			// 
			// gouraudLightRadioButton
			// 
			this->gouraudLightRadioButton->AutoSize = true;
			this->gouraudLightRadioButton->Checked = true;
			this->gouraudLightRadioButton->Location = System::Drawing::Point(6, 76);
			this->gouraudLightRadioButton->Name = L"gouraudLightRadioButton";
			this->gouraudLightRadioButton->Size = System::Drawing::Size(139, 21);
			this->gouraudLightRadioButton->TabIndex = 2;
			this->gouraudLightRadioButton->TabStop = true;
			this->gouraudLightRadioButton->Text = L"Gouraud Lighting";
			this->gouraudLightRadioButton->UseVisualStyleBackColor = true;
			this->gouraudLightRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::gouraudLightRadioButton_CheckedChanged);
			// 
			// phongLightRadioButton
			// 
			this->phongLightRadioButton->AutoSize = true;
			this->phongLightRadioButton->Location = System::Drawing::Point(6, 49);
			this->phongLightRadioButton->Name = L"phongLightRadioButton";
			this->phongLightRadioButton->Size = System::Drawing::Size(124, 21);
			this->phongLightRadioButton->TabIndex = 1;
			this->phongLightRadioButton->Text = L"Phong Lighting";
			this->phongLightRadioButton->UseVisualStyleBackColor = true;
			this->phongLightRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::phongLightRadioButton_CheckedChanged);
			// 
			// noLightRadioButton
			// 
			this->noLightRadioButton->AutoSize = true;
			this->noLightRadioButton->Location = System::Drawing::Point(7, 22);
			this->noLightRadioButton->Name = L"noLightRadioButton";
			this->noLightRadioButton->Size = System::Drawing::Size(63, 21);
			this->noLightRadioButton->TabIndex = 0;
			this->noLightRadioButton->Text = L"None";
			this->noLightRadioButton->UseVisualStyleBackColor = true;
			this->noLightRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::noLightRadioButton_CheckedChanged);
			// 
			// lightPosGroupBox
			// 
			this->lightPosGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lightPosGroupBox->AutoSize = true;
			this->lightPosGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->lightPosGroupBox->Controls->Add(this->lightPosZBar);
			this->lightPosGroupBox->Controls->Add(this->lightPosZLabel);
			this->lightPosGroupBox->Controls->Add(this->lightPosYBar);
			this->lightPosGroupBox->Controls->Add(this->lightPosYLabel);
			this->lightPosGroupBox->Controls->Add(this->lightPosXBar);
			this->lightPosGroupBox->Controls->Add(this->lightPosXLabel);
			this->lightPosGroupBox->Location = System::Drawing::Point(3, 431);
			this->lightPosGroupBox->Name = L"lightPosGroupBox";
			this->lightPosGroupBox->Size = System::Drawing::Size(224, 236);
			this->lightPosGroupBox->TabIndex = 4;
			this->lightPosGroupBox->TabStop = false;
			this->lightPosGroupBox->Text = L"Position";
			// 
			// lightPosZBar
			// 
			this->lightPosZBar->Location = System::Drawing::Point(6, 159);
			this->lightPosZBar->Maximum = 300;
			this->lightPosZBar->Minimum = -100;
			this->lightPosZBar->Name = L"lightPosZBar";
			this->lightPosZBar->Size = System::Drawing::Size(212, 56);
			this->lightPosZBar->TabIndex = 10;
			this->lightPosZBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->lightPosZBar->Value = 100;
			this->lightPosZBar->Scroll += gcnew System::EventHandler(this, &MainForm::lightPosZBar_Scroll);
			// 
			// lightPosZLabel
			// 
			this->lightPosZLabel->AutoSize = true;
			this->lightPosZLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lightPosZLabel->Location = System::Drawing::Point(6, 136);
			this->lightPosZLabel->Name = L"lightPosZLabel";
			this->lightPosZLabel->Size = System::Drawing::Size(46, 17);
			this->lightPosZLabel->TabIndex = 11;
			this->lightPosZLabel->Text = L"Z Axis";
			this->lightPosZLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lightPosYBar
			// 
			this->lightPosYBar->Location = System::Drawing::Point(6, 100);
			this->lightPosYBar->Maximum = 100;
			this->lightPosYBar->Minimum = -100;
			this->lightPosYBar->Name = L"lightPosYBar";
			this->lightPosYBar->Size = System::Drawing::Size(212, 56);
			this->lightPosYBar->TabIndex = 8;
			this->lightPosYBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->lightPosYBar->Scroll += gcnew System::EventHandler(this, &MainForm::lightPosYBar_Scroll);
			// 
			// lightPosYLabel
			// 
			this->lightPosYLabel->AutoSize = true;
			this->lightPosYLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lightPosYLabel->Location = System::Drawing::Point(6, 77);
			this->lightPosYLabel->Name = L"lightPosYLabel";
			this->lightPosYLabel->Size = System::Drawing::Size(46, 17);
			this->lightPosYLabel->TabIndex = 9;
			this->lightPosYLabel->Text = L"Y Axis";
			this->lightPosYLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lightPosXBar
			// 
			this->lightPosXBar->Location = System::Drawing::Point(6, 41);
			this->lightPosXBar->Maximum = 100;
			this->lightPosXBar->Minimum = -100;
			this->lightPosXBar->Name = L"lightPosXBar";
			this->lightPosXBar->Size = System::Drawing::Size(212, 56);
			this->lightPosXBar->TabIndex = 6;
			this->lightPosXBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->lightPosXBar->Scroll += gcnew System::EventHandler(this, &MainForm::lightPosXBar_Scroll);
			// 
			// lightPosXLabel
			// 
			this->lightPosXLabel->AutoSize = true;
			this->lightPosXLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lightPosXLabel->Location = System::Drawing::Point(6, 18);
			this->lightPosXLabel->Name = L"lightPosXLabel";
			this->lightPosXLabel->Size = System::Drawing::Size(46, 17);
			this->lightPosXLabel->TabIndex = 7;
			this->lightPosXLabel->Text = L"X Axis";
			this->lightPosXLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// matTabPage
			// 
			this->matTabPage->BackColor = System::Drawing::SystemColors::Control;
			this->matTabPage->Controls->Add(this->matFlowLayoutPanel);
			this->matTabPage->Location = System::Drawing::Point(4, 25);
			this->matTabPage->Name = L"matTabPage";
			this->matTabPage->Padding = System::Windows::Forms::Padding(3);
			this->matTabPage->Size = System::Drawing::Size(259, 613);
			this->matTabPage->TabIndex = 4;
			this->matTabPage->Text = L"Material";
			// 
			// matFlowLayoutPanel
			// 
			this->matFlowLayoutPanel->AutoScroll = true;
			this->matFlowLayoutPanel->Controls->Add(this->resetMatButton);
			this->matFlowLayoutPanel->Controls->Add(this->matParamsGroupBox);
			this->matFlowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->matFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->matFlowLayoutPanel->Location = System::Drawing::Point(3, 3);
			this->matFlowLayoutPanel->Name = L"matFlowLayoutPanel";
			this->matFlowLayoutPanel->Size = System::Drawing::Size(253, 607);
			this->matFlowLayoutPanel->TabIndex = 2;
			this->matFlowLayoutPanel->WrapContents = false;
			// 
			// resetMatButton
			// 
			this->resetMatButton->Location = System::Drawing::Point(3, 3);
			this->resetMatButton->Name = L"resetMatButton";
			this->resetMatButton->Size = System::Drawing::Size(222, 23);
			this->resetMatButton->TabIndex = 18;
			this->resetMatButton->Text = L"Reset";
			this->resetMatButton->UseVisualStyleBackColor = true;
			this->resetMatButton->Click += gcnew System::EventHandler(this, &MainForm::resetMatButton_Click);
			// 
			// matParamsGroupBox
			// 
			this->matParamsGroupBox->Controls->Add(this->shineMatBar);
			this->matParamsGroupBox->Controls->Add(this->shineMatLabel);
			this->matParamsGroupBox->Controls->Add(this->specMatBar);
			this->matParamsGroupBox->Controls->Add(this->specMatLabel);
			this->matParamsGroupBox->Controls->Add(this->diffMatBar);
			this->matParamsGroupBox->Controls->Add(this->diffMatLabel);
			this->matParamsGroupBox->Controls->Add(this->ambiMatBar);
			this->matParamsGroupBox->Controls->Add(this->ambiMatLabel);
			this->matParamsGroupBox->Controls->Add(this->matColorButton);
			this->matParamsGroupBox->Controls->Add(this->matColorLabel);
			this->matParamsGroupBox->Location = System::Drawing::Point(3, 32);
			this->matParamsGroupBox->Name = L"matParamsGroupBox";
			this->matParamsGroupBox->Size = System::Drawing::Size(222, 319);
			this->matParamsGroupBox->TabIndex = 0;
			this->matParamsGroupBox->TabStop = false;
			this->matParamsGroupBox->Text = L"Parameters";
			// 
			// shineMatBar
			// 
			this->shineMatBar->Location = System::Drawing::Point(9, 258);
			this->shineMatBar->Maximum = 8;
			this->shineMatBar->Minimum = 1;
			this->shineMatBar->Name = L"shineMatBar";
			this->shineMatBar->Size = System::Drawing::Size(212, 56);
			this->shineMatBar->TabIndex = 14;
			this->shineMatBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->shineMatBar->Value = 4;
			this->shineMatBar->Scroll += gcnew System::EventHandler(this, &MainForm::shineMatBar_Scroll);
			// 
			// shineMatLabel
			// 
			this->shineMatLabel->AutoSize = true;
			this->shineMatLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->shineMatLabel->Location = System::Drawing::Point(6, 235);
			this->shineMatLabel->Name = L"shineMatLabel";
			this->shineMatLabel->Size = System::Drawing::Size(69, 17);
			this->shineMatLabel->TabIndex = 15;
			this->shineMatLabel->Text = L"Shininess";
			this->shineMatLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// specMatBar
			// 
			this->specMatBar->Location = System::Drawing::Point(9, 196);
			this->specMatBar->Maximum = 100;
			this->specMatBar->Name = L"specMatBar";
			this->specMatBar->Size = System::Drawing::Size(212, 56);
			this->specMatBar->TabIndex = 12;
			this->specMatBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->specMatBar->Value = 80;
			this->specMatBar->Scroll += gcnew System::EventHandler(this, &MainForm::specMatBar_Scroll);
			// 
			// specMatLabel
			// 
			this->specMatLabel->AutoSize = true;
			this->specMatLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->specMatLabel->Location = System::Drawing::Point(6, 173);
			this->specMatLabel->Name = L"specMatLabel";
			this->specMatLabel->Size = System::Drawing::Size(122, 17);
			this->specMatLabel->TabIndex = 13;
			this->specMatLabel->Text = L"Specular Strength";
			this->specMatLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// diffMatBar
			// 
			this->diffMatBar->Location = System::Drawing::Point(9, 134);
			this->diffMatBar->Maximum = 100;
			this->diffMatBar->Name = L"diffMatBar";
			this->diffMatBar->Size = System::Drawing::Size(212, 56);
			this->diffMatBar->TabIndex = 10;
			this->diffMatBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->diffMatBar->Value = 50;
			this->diffMatBar->Scroll += gcnew System::EventHandler(this, &MainForm::diffMatBar_Scroll);
			// 
			// diffMatLabel
			// 
			this->diffMatLabel->AutoSize = true;
			this->diffMatLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->diffMatLabel->Location = System::Drawing::Point(6, 111);
			this->diffMatLabel->Name = L"diffMatLabel";
			this->diffMatLabel->Size = System::Drawing::Size(110, 17);
			this->diffMatLabel->TabIndex = 11;
			this->diffMatLabel->Text = L"Diffuse Strength";
			this->diffMatLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ambiMatBar
			// 
			this->ambiMatBar->Location = System::Drawing::Point(6, 72);
			this->ambiMatBar->Maximum = 100;
			this->ambiMatBar->Name = L"ambiMatBar";
			this->ambiMatBar->Size = System::Drawing::Size(212, 56);
			this->ambiMatBar->TabIndex = 8;
			this->ambiMatBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->ambiMatBar->Value = 10;
			this->ambiMatBar->Scroll += gcnew System::EventHandler(this, &MainForm::ambiMatBar_Scroll);
			// 
			// ambiMatLabel
			// 
			this->ambiMatLabel->AutoSize = true;
			this->ambiMatLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ambiMatLabel->Location = System::Drawing::Point(6, 49);
			this->ambiMatLabel->Name = L"ambiMatLabel";
			this->ambiMatLabel->Size = System::Drawing::Size(128, 17);
			this->ambiMatLabel->TabIndex = 9;
			this->ambiMatLabel->Text = L"Ambience Strength";
			this->ambiMatLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// matColorButton
			// 
			this->matColorButton->BackColor = System::Drawing::Color::White;
			this->matColorButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->matColorButton->Location = System::Drawing::Point(87, 19);
			this->matColorButton->Name = L"matColorButton";
			this->matColorButton->Size = System::Drawing::Size(125, 23);
			this->matColorButton->TabIndex = 1;
			this->matColorButton->UseVisualStyleBackColor = false;
			this->matColorButton->Click += gcnew System::EventHandler(this, &MainForm::matColorButton_Click);
			// 
			// matColorLabel
			// 
			this->matColorLabel->AutoSize = true;
			this->matColorLabel->Location = System::Drawing::Point(7, 22);
			this->matColorLabel->Name = L"matColorLabel";
			this->matColorLabel->Size = System::Drawing::Size(41, 17);
			this->matColorLabel->TabIndex = 0;
			this->matColorLabel->Text = L"Color";
			// 
			// otherTabPage
			// 
			this->otherTabPage->BackColor = System::Drawing::SystemColors::Control;
			this->otherTabPage->Controls->Add(this->otherFlowLayoutPanel);
			this->otherTabPage->Location = System::Drawing::Point(4, 25);
			this->otherTabPage->Name = L"otherTabPage";
			this->otherTabPage->Padding = System::Windows::Forms::Padding(3);
			this->otherTabPage->Size = System::Drawing::Size(259, 613);
			this->otherTabPage->TabIndex = 2;
			this->otherTabPage->Text = L"Other";
			// 
			// otherFlowLayoutPanel
			// 
			this->otherFlowLayoutPanel->AutoScroll = true;
			this->otherFlowLayoutPanel->Controls->Add(this->colorGroupBox);
			this->otherFlowLayoutPanel->Controls->Add(this->drawingModeGroupBox);
			this->otherFlowLayoutPanel->Controls->Add(this->cullGroupBox);
			this->otherFlowLayoutPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->otherFlowLayoutPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->otherFlowLayoutPanel->Location = System::Drawing::Point(3, 3);
			this->otherFlowLayoutPanel->Name = L"otherFlowLayoutPanel";
			this->otherFlowLayoutPanel->Size = System::Drawing::Size(253, 607);
			this->otherFlowLayoutPanel->TabIndex = 0;
			// 
			// colorGroupBox
			// 
			this->colorGroupBox->Controls->Add(this->selectedColorButton);
			this->colorGroupBox->Controls->Add(this->selectedColorLabel);
			this->colorGroupBox->Controls->Add(this->wfColorButton);
			this->colorGroupBox->Controls->Add(this->wfColorLabel);
			this->colorGroupBox->Controls->Add(this->bgColorButton);
			this->colorGroupBox->Controls->Add(this->bgColorLabel);
			this->colorGroupBox->Location = System::Drawing::Point(3, 3);
			this->colorGroupBox->Name = L"colorGroupBox";
			this->colorGroupBox->Size = System::Drawing::Size(241, 119);
			this->colorGroupBox->TabIndex = 0;
			this->colorGroupBox->TabStop = false;
			this->colorGroupBox->Text = L"Colors";
			// 
			// selectedColorButton
			// 
			this->selectedColorButton->BackColor = System::Drawing::Color::Yellow;
			this->selectedColorButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->selectedColorButton->Location = System::Drawing::Point(91, 78);
			this->selectedColorButton->Name = L"selectedColorButton";
			this->selectedColorButton->Size = System::Drawing::Size(144, 23);
			this->selectedColorButton->TabIndex = 5;
			this->selectedColorButton->UseVisualStyleBackColor = false;
			this->selectedColorButton->Click += gcnew System::EventHandler(this, &MainForm::selectedColorButton_Click);
			// 
			// selectedColorLabel
			// 
			this->selectedColorLabel->AutoSize = true;
			this->selectedColorLabel->Location = System::Drawing::Point(7, 81);
			this->selectedColorLabel->Name = L"selectedColorLabel";
			this->selectedColorLabel->Size = System::Drawing::Size(63, 17);
			this->selectedColorLabel->TabIndex = 4;
			this->selectedColorLabel->Text = L"Selected";
			// 
			// wfColorButton
			// 
			this->wfColorButton->BackColor = System::Drawing::Color::Black;
			this->wfColorButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->wfColorButton->Location = System::Drawing::Point(91, 48);
			this->wfColorButton->Name = L"wfColorButton";
			this->wfColorButton->Size = System::Drawing::Size(144, 23);
			this->wfColorButton->TabIndex = 3;
			this->wfColorButton->UseVisualStyleBackColor = false;
			this->wfColorButton->Click += gcnew System::EventHandler(this, &MainForm::wfColorButton_Click);
			// 
			// wfColorLabel
			// 
			this->wfColorLabel->AutoSize = true;
			this->wfColorLabel->Location = System::Drawing::Point(7, 51);
			this->wfColorLabel->Name = L"wfColorLabel";
			this->wfColorLabel->Size = System::Drawing::Size(73, 17);
			this->wfColorLabel->TabIndex = 2;
			this->wfColorLabel->Text = L"Wireframe";
			// 
			// bgColorButton
			// 
			this->bgColorButton->BackColor = System::Drawing::Color::White;
			this->bgColorButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bgColorButton->Location = System::Drawing::Point(91, 19);
			this->bgColorButton->Name = L"bgColorButton";
			this->bgColorButton->Size = System::Drawing::Size(144, 23);
			this->bgColorButton->TabIndex = 1;
			this->bgColorButton->UseVisualStyleBackColor = false;
			this->bgColorButton->Click += gcnew System::EventHandler(this, &MainForm::bgColorButton_Click);
			// 
			// bgColorLabel
			// 
			this->bgColorLabel->AutoSize = true;
			this->bgColorLabel->Location = System::Drawing::Point(7, 22);
			this->bgColorLabel->Name = L"bgColorLabel";
			this->bgColorLabel->Size = System::Drawing::Size(84, 17);
			this->bgColorLabel->TabIndex = 0;
			this->bgColorLabel->Text = L"Background";
			// 
			// drawingModeGroupBox
			// 
			this->drawingModeGroupBox->Controls->Add(this->bothRadioButton);
			this->drawingModeGroupBox->Controls->Add(this->solidRadioButton);
			this->drawingModeGroupBox->Controls->Add(this->wfRadioButton);
			this->drawingModeGroupBox->Location = System::Drawing::Point(3, 128);
			this->drawingModeGroupBox->Name = L"drawingModeGroupBox";
			this->drawingModeGroupBox->Size = System::Drawing::Size(241, 110);
			this->drawingModeGroupBox->TabIndex = 1;
			this->drawingModeGroupBox->TabStop = false;
			this->drawingModeGroupBox->Text = L"Drawing Mode";
			// 
			// bothRadioButton
			// 
			this->bothRadioButton->AutoSize = true;
			this->bothRadioButton->Checked = true;
			this->bothRadioButton->Location = System::Drawing::Point(7, 76);
			this->bothRadioButton->Name = L"bothRadioButton";
			this->bothRadioButton->Size = System::Drawing::Size(58, 21);
			this->bothRadioButton->TabIndex = 2;
			this->bothRadioButton->TabStop = true;
			this->bothRadioButton->Text = L"Both";
			this->bothRadioButton->UseVisualStyleBackColor = true;
			this->bothRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::bothRadioButton_CheckedChanged);
			// 
			// solidRadioButton
			// 
			this->solidRadioButton->AutoSize = true;
			this->solidRadioButton->Location = System::Drawing::Point(6, 49);
			this->solidRadioButton->Name = L"solidRadioButton";
			this->solidRadioButton->Size = System::Drawing::Size(60, 21);
			this->solidRadioButton->TabIndex = 1;
			this->solidRadioButton->Text = L"Solid";
			this->solidRadioButton->UseVisualStyleBackColor = true;
			this->solidRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::solidRadioButton_CheckedChanged);
			// 
			// wfRadioButton
			// 
			this->wfRadioButton->AutoSize = true;
			this->wfRadioButton->Location = System::Drawing::Point(7, 22);
			this->wfRadioButton->Name = L"wfRadioButton";
			this->wfRadioButton->Size = System::Drawing::Size(94, 21);
			this->wfRadioButton->TabIndex = 0;
			this->wfRadioButton->Text = L"Wireframe";
			this->wfRadioButton->UseVisualStyleBackColor = true;
			this->wfRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::wfRadioButton_CheckedChanged);
			// 
			// cullGroupBox
			// 
			this->cullGroupBox->Controls->Add(this->cullOffRadioButton);
			this->cullGroupBox->Controls->Add(this->cullOnRadioButton);
			this->cullGroupBox->Location = System::Drawing::Point(3, 244);
			this->cullGroupBox->Name = L"cullGroupBox";
			this->cullGroupBox->Size = System::Drawing::Size(241, 80);
			this->cullGroupBox->TabIndex = 2;
			this->cullGroupBox->TabStop = false;
			this->cullGroupBox->Text = L"Face Culling";
			// 
			// cullOffRadioButton
			// 
			this->cullOffRadioButton->AutoSize = true;
			this->cullOffRadioButton->Location = System::Drawing::Point(6, 49);
			this->cullOffRadioButton->Name = L"cullOffRadioButton";
			this->cullOffRadioButton->Size = System::Drawing::Size(48, 21);
			this->cullOffRadioButton->TabIndex = 1;
			this->cullOffRadioButton->TabStop = true;
			this->cullOffRadioButton->Text = L"Off";
			this->cullOffRadioButton->UseVisualStyleBackColor = true;
			this->cullOffRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cullOffRadioButton_CheckedChanged);
			// 
			// cullOnRadioButton
			// 
			this->cullOnRadioButton->AutoSize = true;
			this->cullOnRadioButton->Location = System::Drawing::Point(7, 22);
			this->cullOnRadioButton->Name = L"cullOnRadioButton";
			this->cullOnRadioButton->Size = System::Drawing::Size(48, 21);
			this->cullOnRadioButton->TabIndex = 0;
			this->cullOnRadioButton->TabStop = true;
			this->cullOnRadioButton->Text = L"On";
			this->cullOnRadioButton->UseVisualStyleBackColor = true;
			this->cullOnRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cullOnRadioButton_CheckedChanged);
			// 
			// statusStrip
			// 
			this->statusStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->objCountLabel });
			this->statusStrip->Location = System::Drawing::Point(0, 671);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(914, 25);
			this->statusStrip->TabIndex = 3;
			this->statusStrip->Text = L"statusStrip";
			// 
			// objCountLabel
			// 
			this->objCountLabel->Name = L"objCountLabel";
			this->objCountLabel->Size = System::Drawing::Size(74, 20);
			this->objCountLabel->Text = L"Objects: 0";
			// 
			// openFileDialog
			// 
			this->openFileDialog->Filter = L"3D Object files|*.object|Text files|*.txt|All files|*.*";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(914, 696);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->tableLayoutPanel);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"КДЗ 1 по Компьютерной графике. Иванов О. 2018";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->ResizeEnd += gcnew System::EventHandler(this, &MainForm::MainForm_ResizeEnd);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->tableLayoutPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->tabControl->ResumeLayout(false);
			this->objectTabPage->ResumeLayout(false);
			this->objFlowLayoutPanet->ResumeLayout(false);
			this->objFlowLayoutPanet->PerformLayout();
			this->selectionTableLayoutPanel->ResumeLayout(false);
			this->objPosGroupBox->ResumeLayout(false);
			this->objPosGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objPosZBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objPosYBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objPosXBar))->EndInit();
			this->objScaleGroupBox->ResumeLayout(false);
			this->objScaleGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objScaleZBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objScaleYBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objScaleXBar))->EndInit();
			this->objRotationGroupBox->ResumeLayout(false);
			this->objRotationGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objRotZBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objRotYBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->objRotXBar))->EndInit();
			this->objReflectionGroupBox->ResumeLayout(false);
			this->objReflectionGroupBox->PerformLayout();
			this->cameraTabPage->ResumeLayout(false);
			this->camFlowLayoutPanel->ResumeLayout(false);
			this->camFlowLayoutPanel->PerformLayout();
			this->cameraPosGroupBox->ResumeLayout(false);
			this->cameraPosGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPosZBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPosYBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camPosXBar))->EndInit();
			this->camProjectionGroupBox->ResumeLayout(false);
			this->camProjectionGroupBox->PerformLayout();
			this->camRotationGroupBox->ResumeLayout(false);
			this->camRotationGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotYawBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotPitchBar))->EndInit();
			this->lightingTabPage->ResumeLayout(false);
			this->lightFlowLayoutPanel->ResumeLayout(false);
			this->lightFlowLayoutPanel->PerformLayout();
			this->lightParamsGroupBox->ResumeLayout(false);
			this->lightParamsGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightSpecBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightDiffuseBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightAmbiTrackBar))->EndInit();
			this->lightModeGroupBox->ResumeLayout(false);
			this->lightModeGroupBox->PerformLayout();
			this->lightPosGroupBox->ResumeLayout(false);
			this->lightPosGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightPosZBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightPosYBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->lightPosXBar))->EndInit();
			this->matTabPage->ResumeLayout(false);
			this->matFlowLayoutPanel->ResumeLayout(false);
			this->matParamsGroupBox->ResumeLayout(false);
			this->matParamsGroupBox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->shineMatBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specMatBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->diffMatBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ambiMatBar))->EndInit();
			this->otherTabPage->ResumeLayout(false);
			this->otherFlowLayoutPanel->ResumeLayout(false);
			this->colorGroupBox->ResumeLayout(false);
			this->colorGroupBox->PerformLayout();
			this->drawingModeGroupBox->ResumeLayout(false);
			this->drawingModeGroupBox->PerformLayout();
			this->cullGroupBox->ResumeLayout(false);
			this->cullGroupBox->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
};
}
