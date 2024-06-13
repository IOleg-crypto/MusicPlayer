#pragma once

#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "mmstream.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <msclr/marshal.h>
//Windows stuff
#include <Windows.h>
#include <mmsystem.h>
#include <string>


#pragma comment(lib, "winmm.lib")

namespace MusicPlayer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Text;
	using namespace System::Media;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;

	using namespace AxWMPLib;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->timer2->Start();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Play;

	protected:

	protected:

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openFileToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ changeBackgroundImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ infoToolStripMenuItem;
	private: System::Windows::Forms::BindingSource^ bindingSource1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: UINT deviceID_music; //Checker
	private: DWORD musicLength; // Store the length of the music

	private: System::Windows::Forms::FontDialog^ fontDialog1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;



	private: System::ComponentModel::IContainer^ components;

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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Play = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeBackgroundImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->SuspendLayout();
			// 
			// Play
			// 
			this->Play->Location = System::Drawing::Point(359, 439);
			this->Play->Name = L"Play";
			this->Play->Size = System::Drawing::Size(150, 56);
			this->Play->TabIndex = 1;
			this->Play->UseVisualStyleBackColor = true;
			this->Play->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->infoToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::Professional;
			this->menuStrip1->Size = System::Drawing::Size(768, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openFileToolStripMenuItem,
					this->changeBackgroundImageToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(60, 24);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::U));
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(362, 26);
			this->openFileToolStripMenuItem->Text = L"Open File";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openFileToolStripMenuItem_Click);
			// 
			// changeBackgroundImageToolStripMenuItem
			// 
			this->changeBackgroundImageToolStripMenuItem->Name = L"changeBackgroundImageToolStripMenuItem";
			this->changeBackgroundImageToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::R));
			this->changeBackgroundImageToolStripMenuItem->Size = System::Drawing::Size(362, 26);
			this->changeBackgroundImageToolStripMenuItem->Text = L"Change background image";
			this->changeBackgroundImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::changeBackgroundImageToolStripMenuItem_Click);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(49, 24);
			this->infoToolStripMenuItem->Text = L"Info";
			this->infoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::infoToolStripMenuItem_Click);
			// 
			// bindingSource1
			// 
			this->bindingSource1->CurrentChanged += gcnew System::EventHandler(this, &MyForm::bindingSource1_CurrentChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(163, 439);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 56);
			this->button1->TabIndex = 5;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// label1
			// 
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(148, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(119, 30);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Unknown";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(61, 55);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(47, 39);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(-28, -52);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(104, 56);
			this->trackBar1->TabIndex = 8;
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(32, 322);
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(672, 56);
			this->trackBar2->SmallChange = 2;
			this->trackBar2->TabIndex = 1000;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// timer2
			// 
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 362);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 16);
			this->label2->TabIndex = 1001;
			this->label2->Text = L"00:00";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(659, 361);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 16);
			this->label3->TabIndex = 1002;
			this->label3->Text = L"00:00";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(768, 507);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackBar2);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->Play);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MusicPlayer";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	System::String^ formatTime(DWORD timeInMilliseconds)
	{
	   int seconds = (timeInMilliseconds / 1000) % 60;
	   int minutes = (timeInMilliseconds / (1000 * 60)) % 60;
	   std::wostringstream oss;
	   oss << std::setfill(L'0') << std::setw(2) << minutes << L":" << std::setfill(L'0') << std::setw(2) << seconds;
	   return gcnew System::String(oss.str().c_str());
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		System::String^ cliFilePath = label1->Text;
		std::wstring filePath = marshal_as<std::wstring>(cliFilePath);

		// Open the MP3 file
		MCI_OPEN_PARMS mciOpenParms;
		mciOpenParms.lpstrDeviceType = L"mpegvideo";
		mciOpenParms.lpstrElementName = filePath.c_str();

		if (mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&mciOpenParms))
		{
			MessageBox::Show("Failed to open the file.");
			return;
		}

		// Store the device ID
		deviceID_music = mciOpenParms.wDeviceID;

		// Play the MP3 file
		MCI_PLAY_PARMS mciPlayParms;
		if (mciSendCommand(mciOpenParms.wDeviceID, MCI_PLAY, 0, (DWORD_PTR)&mciPlayParms))
		{
			MessageBox::Show("Failed to play the file.");
			mciSendCommand(mciOpenParms.wDeviceID, MCI_CLOSE, 0, NULL);
			return;
		}

		// Get the length of the music file
		MCI_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_STATUS_LENGTH;
		mciSendCommand(deviceID_music, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&mciStatusParms);
		musicLength = mciStatusParms.dwReturn;

		// Set the maximum value of the track bar to the length of the music file
		trackBar1->Maximum = musicLength / 1000;// Convert milliseconds to seconds
		label2->Text = formatTime(musicLength);

	}
	private: System::Void openFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Stream^ myStream;

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->Filter = "Audio Files|*.mp3;*.wav;*.wma";
	    openFileDialog1->Title = "Select a Music File";
		openFileDialog1->RestoreDirectory = true;

		

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ filePath = openFileDialog1->FileName;
			this->label1->Text = filePath;
			label1->Height = label1->Font->Height; 
			label1->AutoEllipsis = true; 
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				// Insert code to read the stream here.
				myStream->Close();
			}
		}
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	//load icon for [play button]
	// Load the icon and resize it

	System::Drawing::Icon^ icon_play = gcnew System::Drawing::Icon("images.ico");
	Bitmap^ originalBitmap = icon_play->ToBitmap();
	Bitmap^ resizedBitmap = gcnew Bitmap(originalBitmap, System::Drawing::Size(32, 32)); // Change the size as needed

	// Set the resized bitmap to the button's image
	this->Play->Image = resizedBitmap;
	this->Play->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;

	//icon for button , which is stop playing music

	
	System::Drawing::Icon^ icon_stop = gcnew System::Drawing::Icon("stopicon.ico");
	Bitmap^ originalBitmap_stop = icon_stop->ToBitmap();
	Bitmap^ resizedBitmap_stop = gcnew Bitmap(originalBitmap_stop, System::Drawing::Size(32, 32));
	this->button1->Image = resizedBitmap_stop;
	this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::Overlay;

	pictureBox1->Image = Image::FromFile("dynamic.png");
	pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;

}
private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
}
private: System::Void changeBackgroundImageToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Stream^ myStream;

	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	openFileDialog1->Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp";
	openFileDialog1->Title = "Select a Background Image";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;

	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ filepath = openFileDialog1->FileName;
		//Allocation
		System::Drawing::Image^ backgroundImage = System::Drawing::Image::FromFile(filepath); // Or use the resource method

		// Set the background image of the form
		this->BackgroundImage = backgroundImage;

		// Optional: Adjust the background image layout
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
	
		if ((myStream = openFileDialog1->OpenFile()) != nullptr)
		{
			// Insert code to read the stream here.
			myStream->Close();
		}
	}
}
private: System::Void infoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Music player had been made by i#Oleg 2024" , "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void bindingSource1_CurrentChanged(System::Object^ sender, System::EventArgs^ e) {
}
public: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
	
// Adjust the size of the button based on the form's new size.
	this->Play->Size = Drawing::Size(this->ClientSize.Width / 6, this->ClientSize.Height / 10);

	// Optionally, adjust the location of the button
	this->Play->Location = Point((this->ClientSize.Width - this->Play->Width) / 2, (this->ClientSize.Height - this->Play->Height));

	// Adjust the location
	this->button1->Location= Point((this->ClientSize.Width - this->Play->Width)/  6, (this->ClientSize.Height - this->Play->Height) / 1);
	

	// Optionally, adjust the size          
	this->button1->Size = Drawing::Size(this->ClientSize.Width / 6 ,(this->ClientSize.Height - this->Play->Height) / 10);
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (deviceID_music != 0)
	{
		MCI_GENERIC_PARMS mciGenericParms;
		mciSendCommand(deviceID_music, MCI_STOP, 0, (DWORD_PTR)&mciGenericParms);
		mciSendCommand(deviceID_music, MCI_CLOSE, 0, (DWORD_PTR)&mciGenericParms);
		deviceID_music = 0; // Reset device ID after stopping
		timer2->Stop();
		trackBar1->Value = 0;
		label3->Text = "00:00";
	}
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}

public: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (deviceID_music != 0)
	{
		 // Get the current position of the music file
		MCI_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_STATUS_POSITION;
		mciSendCommand(deviceID_music, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&mciStatusParms);
		DWORD position = mciStatusParms.dwReturn;

		// Update the track bar to reflect the current position
		//trackBar2->Value = position / 1000; // Convert milliseconds to seconds

		trackBar2->Maximum = position / 1000; // Convert milliseconds to seconds

		// Update the total time label
		label2->Text = formatTime(musicLength);
	}
}
private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (deviceID_music != 0)
	{
		MCI_SEEK_PARMS mciSeekParms;
		mciSeekParms.dwTo = trackBar2->Value * 1000; // Convert seconds to milliseconds
		mciSendCommand(deviceID_music, MCI_SEEK, MCI_TO, (DWORD_PTR)&mciSeekParms);

		MCI_PLAY_PARMS mciPlayParms;
		mciSendCommand(deviceID_music, MCI_PLAY, 0, (DWORD_PTR)&mciPlayParms);
	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};

}
