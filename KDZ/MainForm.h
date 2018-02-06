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
			pictureBox->Image = bm;
		}

	private: 
		Bitmap^ bm;
		// Main scene
		GL::Scene *mainScene;
		System::Void setScene();
		System::Void renderScene();
		// Events
		System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e);
		System::Void objPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objScaleXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objScaleYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objScaleZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objRotXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objRotYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void objRotZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camPosXBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camPosYBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camPosZBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camRotPitchBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camRotYawBar_Scroll(System::Object^  sender, System::EventArgs^  e);
		System::Void camRotRollBar_Scroll(System::Object^  sender, System::EventArgs^  e);

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
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel;
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
	private: System::Windows::Forms::TrackBar^  camRotRollBar;

	private: System::Windows::Forms::Label^  camRollLabel;
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
private: System::Windows::Forms::ToolStripMenuItem^  testToolStripMenuItem;










































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
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->objectTabPage = (gcnew System::Windows::Forms::TabPage());
			this->objFlowLayoutPanet = (gcnew System::Windows::Forms::FlowLayoutPanel());
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
			this->camRotRollBar = (gcnew System::Windows::Forms::TrackBar());
			this->camRollLabel = (gcnew System::Windows::Forms::Label());
			this->camRotYawBar = (gcnew System::Windows::Forms::TrackBar());
			this->camYawLabel = (gcnew System::Windows::Forms::Label());
			this->camRotPitchBar = (gcnew System::Windows::Forms::TrackBar());
			this->camPitchLabel = (gcnew System::Windows::Forms::Label());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip->SuspendLayout();
			this->tableLayoutPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->tabControl->SuspendLayout();
			this->objectTabPage->SuspendLayout();
			this->objFlowLayoutPanet->SuspendLayout();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotRollBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotYawBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotPitchBar))->BeginInit();
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
					this->exitToolStripMenuItem, this->testToolStripMenuItem
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
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(129, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(129, 26);
			this->testToolStripMenuItem->Text = L"test";
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
			this->objPosGroupBox->Location = System::Drawing::Point(3, 3);
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
			this->objScaleGroupBox->Location = System::Drawing::Point(3, 245);
			this->objScaleGroupBox->Name = L"objScaleGroupBox";
			this->objScaleGroupBox->Size = System::Drawing::Size(224, 236);
			this->objScaleGroupBox->TabIndex = 4;
			this->objScaleGroupBox->TabStop = false;
			this->objScaleGroupBox->Text = L"Scale";
			// 
			// objScaleZBar
			// 
			this->objScaleZBar->Location = System::Drawing::Point(6, 159);
			this->objScaleZBar->Maximum = 100;
			this->objScaleZBar->Minimum = -100;
			this->objScaleZBar->Name = L"objScaleZBar";
			this->objScaleZBar->Size = System::Drawing::Size(212, 56);
			this->objScaleZBar->TabIndex = 10;
			this->objScaleZBar->TickStyle = System::Windows::Forms::TickStyle::None;
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
			this->objScaleYBar->Maximum = 100;
			this->objScaleYBar->Minimum = -100;
			this->objScaleYBar->Name = L"objScaleYBar";
			this->objScaleYBar->Size = System::Drawing::Size(212, 56);
			this->objScaleYBar->TabIndex = 8;
			this->objScaleYBar->TickStyle = System::Windows::Forms::TickStyle::None;
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
			this->objScaleXBar->Maximum = 100;
			this->objScaleXBar->Minimum = -100;
			this->objScaleXBar->Name = L"objScaleXBar";
			this->objScaleXBar->Size = System::Drawing::Size(212, 56);
			this->objScaleXBar->TabIndex = 6;
			this->objScaleXBar->TickStyle = System::Windows::Forms::TickStyle::None;
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
			this->objRotationGroupBox->Location = System::Drawing::Point(3, 487);
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
			this->objReflectionGroupBox->Location = System::Drawing::Point(3, 729);
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
			this->cameraPosGroupBox->Location = System::Drawing::Point(3, 3);
			this->cameraPosGroupBox->Name = L"cameraPosGroupBox";
			this->cameraPosGroupBox->Size = System::Drawing::Size(224, 236);
			this->cameraPosGroupBox->TabIndex = 3;
			this->cameraPosGroupBox->TabStop = false;
			this->cameraPosGroupBox->Text = L"Position";
			// 
			// camPosZBar
			// 
			this->camPosZBar->Location = System::Drawing::Point(6, 159);
			this->camPosZBar->Maximum = 100;
			this->camPosZBar->Minimum = -100;
			this->camPosZBar->Name = L"camPosZBar";
			this->camPosZBar->Size = System::Drawing::Size(212, 56);
			this->camPosZBar->TabIndex = 10;
			this->camPosZBar->TickStyle = System::Windows::Forms::TickStyle::None;
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
			this->camProjectionGroupBox->Location = System::Drawing::Point(3, 245);
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
			// 
			// camRotationGroupBox
			// 
			this->camRotationGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->camRotationGroupBox->AutoSize = true;
			this->camRotationGroupBox->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->camRotationGroupBox->Controls->Add(this->camRotRollBar);
			this->camRotationGroupBox->Controls->Add(this->camRollLabel);
			this->camRotationGroupBox->Controls->Add(this->camRotYawBar);
			this->camRotationGroupBox->Controls->Add(this->camYawLabel);
			this->camRotationGroupBox->Controls->Add(this->camRotPitchBar);
			this->camRotationGroupBox->Controls->Add(this->camPitchLabel);
			this->camRotationGroupBox->Location = System::Drawing::Point(3, 344);
			this->camRotationGroupBox->Name = L"camRotationGroupBox";
			this->camRotationGroupBox->Size = System::Drawing::Size(224, 236);
			this->camRotationGroupBox->TabIndex = 4;
			this->camRotationGroupBox->TabStop = false;
			this->camRotationGroupBox->Text = L"Rotation";
			// 
			// camRotRollBar
			// 
			this->camRotRollBar->Location = System::Drawing::Point(6, 159);
			this->camRotRollBar->Maximum = 360;
			this->camRotRollBar->Name = L"camRotRollBar";
			this->camRotRollBar->Size = System::Drawing::Size(212, 56);
			this->camRotRollBar->TabIndex = 10;
			this->camRotRollBar->TickStyle = System::Windows::Forms::TickStyle::None;
			this->camRotRollBar->Scroll += gcnew System::EventHandler(this, &MainForm::camRotRollBar_Scroll);
			// 
			// camRollLabel
			// 
			this->camRollLabel->AutoSize = true;
			this->camRollLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->camRollLabel->Location = System::Drawing::Point(6, 136);
			this->camRollLabel->Name = L"camRollLabel";
			this->camRollLabel->Size = System::Drawing::Size(32, 17);
			this->camRollLabel->TabIndex = 11;
			this->camRollLabel->Text = L"Roll";
			this->camRollLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// camRotYawBar
			// 
			this->camRotYawBar->Location = System::Drawing::Point(6, 100);
			this->camRotYawBar->Maximum = 360;
			this->camRotYawBar->Name = L"camRotYawBar";
			this->camRotYawBar->Size = System::Drawing::Size(212, 56);
			this->camRotYawBar->TabIndex = 8;
			this->camRotYawBar->TickStyle = System::Windows::Forms::TickStyle::None;
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
			this->camRotPitchBar->Maximum = 360;
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
			// statusStrip
			// 
			this->statusStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel });
			this->statusStrip->Location = System::Drawing::Point(0, 671);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->statusStrip->Size = System::Drawing::Size(914, 25);
			this->statusStrip->TabIndex = 3;
			this->statusStrip->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel
			// 
			this->toolStripStatusLabel->Name = L"toolStripStatusLabel";
			this->toolStripStatusLabel->Size = System::Drawing::Size(74, 20);
			this->toolStripStatusLabel->Text = L"Objects: 0";
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
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MainForm";
			this->Text = L"КДЗ 1 по Компьютерной графике. Иванов О. 2018";
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->tableLayoutPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->tabControl->ResumeLayout(false);
			this->objectTabPage->ResumeLayout(false);
			this->objFlowLayoutPanet->ResumeLayout(false);
			this->objFlowLayoutPanet->PerformLayout();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotRollBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotYawBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->camRotPitchBar))->EndInit();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
};
}
