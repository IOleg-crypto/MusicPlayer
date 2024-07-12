#pragma once

//include headers
#include "Library.h"
#include "Function.h"
#include "CustomWaveformControl.h"

#pragma comment(lib, "winmm.lib")
#pragma comment (lib,"Gdiplus.lib")

namespace MusicPlayer {

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
			//array<float>^ sampleData = gcnew array<float>{ 0.1f, 0.2f, 0.5f, -0.3f, -0.4f, 0.2f, 0.1f, 0.0f };

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

	private: System::Windows::Forms::FontDialog^ fontDialog1;
		   //private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	public: System::Windows::Forms::Label^ currentTimeLabel;
	public: System::Windows::Forms::Label^ totalTimeLabel;

	public: UINT deviceID_music; //Checker
	public: DWORD musicLength; // Store the length of the music
	public: System::String^ directory_path;
	private: bool isButtonClicked;
	private: DWORD currentPlaybackPosition;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::ComponentModel::IContainer^ components;

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
			   this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->currentTimeLabel = (gcnew System::Windows::Forms::Label());
			   this->totalTimeLabel = (gcnew System::Windows::Forms::Label());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			   this->panel1->SuspendLayout();

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
			   // trackBar2
			   // 
			   this->trackBar2->Location = System::Drawing::Point(12, 17);
			   this->trackBar2->Name = L"trackBar2";
			   this->trackBar2->RightToLeftLayout = true;
			   this->trackBar2->Size = System::Drawing::Size(671, 56);
			   this->trackBar2->SmallChange = 2;
			   this->trackBar2->TabIndex = 1000;
			   this->trackBar2->TickStyle = System::Windows::Forms::TickStyle::Both;
			   this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			   // 
			   // timer2
			   // 
			   this->timer2->Interval = 1000;
			   this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			   // 
			   // currentTimeLabel
			   // 
			   this->currentTimeLabel->AutoSize = true;
			   this->currentTimeLabel->Location = System::Drawing::Point(9, 76);
			   this->currentTimeLabel->Name = L"currentTimeLabel";
			   this->currentTimeLabel->Size = System::Drawing::Size(38, 16);
			   this->currentTimeLabel->TabIndex = 1001;
			   this->currentTimeLabel->Text = L"00:00";
			   this->currentTimeLabel->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			   // 
			   // totalTimeLabel
			   // 
			   this->totalTimeLabel->AutoSize = true;
			   this->totalTimeLabel->Location = System::Drawing::Point(645, 76);
			   this->totalTimeLabel->Name = L"totalTimeLabel";
			   this->totalTimeLabel->Size = System::Drawing::Size(38, 16);
			   this->totalTimeLabel->TabIndex = 1002;
			   this->totalTimeLabel->Text = L"00:00";
			   this->totalTimeLabel->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->Controls->Add(this->trackBar2);
			   this->panel1->Controls->Add(this->totalTimeLabel);
			   this->panel1->Controls->Add(this->currentTimeLabel);
			   this->panel1->Location = System::Drawing::Point(36, 316);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(698, 99);
			   this->panel1->TabIndex = 1003;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->AutoSize = true;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(768, 507);
			   this->Controls->Add(this->panel1);
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
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion


	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Stop any currently playing music and store the current position
		if (deviceID_music != 0) {
			MCI_STATUS_PARMS mciStatusParms;
			mciStatusParms.dwItem = MCI_STATUS_POSITION;
			mciSendCommand(deviceID_music, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&mciStatusParms);
			currentPlaybackPosition = mciStatusParms.dwReturn;

			mciSendCommand(deviceID_music, MCI_STOP, 0, NULL);
			mciSendCommand(deviceID_music, MCI_CLOSE, 0, NULL);
			deviceID_music = 0;
		}

		System::String^ cliFilePath = label1->Text;
		std::wstring filePath = marshal_as<std::wstring>(cliFilePath);

		// Open the MP3 file
		MCI_OPEN_PARMS mciOpenParms;
		mciOpenParms.lpstrDeviceType = L"mpegvideo";
		mciOpenParms.lpstrElementName = filePath.c_str();

		if (mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&mciOpenParms)) {
			MessageBox::Show("Failed to open the file.");
			return;
		}

		// Store the device ID
		deviceID_music = mciOpenParms.wDeviceID;

		// Play the MP3 file from the stored position
		MCI_PLAY_PARMS mciPlayParms;
		mciPlayParms.dwFrom = currentPlaybackPosition;
		if (mciSendCommand(mciOpenParms.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD_PTR)&mciPlayParms)) {
			MessageBox::Show("Failed to play the file.");
			mciSendCommand(mciOpenParms.wDeviceID, MCI_CLOSE, 0, NULL);
			return;
		}

		// Get the length of the music file
		MCI_STATUS_PARMS mciStatusParmsLength;
		mciStatusParmsLength.dwItem = MCI_STATUS_LENGTH;
		mciSendCommand(deviceID_music, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&mciStatusParmsLength);
		musicLength = mciStatusParmsLength.dwReturn;

		// Set the maximum value of the track bar to the length of the music file
		trackBar2->Maximum = musicLength / 1000; // Convert milliseconds to seconds
		timer2->Start();
		totalTimeLabel->Text = formatTime(musicLength);
		isButtonClicked = true;
	}


	private: System::Void openFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Stream^ myStream;

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->Filter = "Audio Files|*.mp3;*.wav;*.wma";
		openFileDialog1->Title = "Select a Music File";
		//openFileDialog1->RestoreDirectory = true;




		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			directory_path = openFileDialog1->FileName;
			this->label1->Text = directory_path;
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
		MessageBox::Show("Music player had been made by i#Oleg 2024", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void bindingSource1_CurrentChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {

		this->Play->Size = Drawing::Size(this->ClientSize.Width / 6, this->ClientSize.Height / 10);
		this->Play->Location = Point((this->ClientSize.Width - this->Play->Width) / 2, (this->ClientSize.Height - this->Play->Height));

		// Resize and position button1
		this->button1->Size = Drawing::Size(this->ClientSize.Width / 6, (this->ClientSize.Height - this->Play->Height) / 8);
		this->button1->Location = Point((this->ClientSize.Width - this->Play->Width) / 6, (this->ClientSize.Height - this->Play->Height) / 1);

		// Resize the panel to occupy the desired portion of the form
		this->panel1->Size = Drawing::Size(this->ClientSize.Width / 2, this->ClientSize.Height / 4);

		// Center the panel within the form and adjust its vertical position to be above the buttons
		this->panel1->Location = Point((this->ClientSize.Width - this->panel1->Width) / 2, this->button1->Location.Y - this->panel1->Height - 10);

		//trackbar resize
		this->trackBar2->Size = Drawing::Size(this->panel1->Width - 20, this->panel1->Height / 3);
		this->trackBar2->Location = Point((this->panel1->Width - this->trackBar2->Width) / 2, (this->panel1->Height - this->trackBar2->Height) / 2);
		//labels
		currentTimeLabel->AutoSize = true;
		currentTimeLabel->Location = Point(10, 10); // Adjust as needed


		totalTimeLabel->AutoSize = true;
		totalTimeLabel->Location = Point(this->panel1->Width - totalTimeLabel->Width - 10, 10); // Adjust as needed
		this->panel1->Controls->Add(totalTimeLabel);

	}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (deviceID_music != 0)
	{
		MCI_GENERIC_PARMS mciGenericParms;
		// Stop the music playback without closing the device
		mciSendCommand(deviceID_music, MCI_STOP, 0, (DWORD_PTR)&mciGenericParms);
		// Keep the device open to retain the current playback position

		// Stop the timer to halt any ongoing updates related to the playback
		timer2->Stop();

		// Retrieve the current playback position
		MCI_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_STATUS_POSITION;
		mciSendCommand(deviceID_music, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD_PTR)&mciStatusParms);
		DWORD currentPosition = mciStatusParms.dwReturn;

		// Convert the current position from milliseconds to minutes and seconds
		DWORD minutes = currentPosition / 60000; // Convert milliseconds to minutes
		DWORD seconds = (currentPosition / 1000) % 60; // Convert milliseconds to seconds
		currentTimeLabel->Text = String::Format("{0:D2}:{1:D2}", minutes, seconds);

		// Optionally, update the trackBar2 value if it is linked to playback position
		// trackBar2->Value = ...; // Set the value based on the current position

		// Optionally, you can handle any other UI updates or state changes
		// isButtonClicked = false; // if needed
	}
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}

public: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (deviceID_music != 0)
	{
		MCI_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_STATUS_POSITION;
		mciSendCommand(deviceID_music, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&mciStatusParms);

		// Calculate current position in seconds
		DWORD currentPosition = mciStatusParms.dwReturn / 1000;

		// Update track bar position
		trackBar2->Value = currentPosition;

		// Update current time label
		currentTimeLabel->Text = formatTime(mciStatusParms.dwReturn);

		// Calculate remaining time and update remaining time label
		DWORD remainingTime = musicLength - mciStatusParms.dwReturn;
		totalTimeLabel->Text = formatTime(remainingTime);
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
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};

}
