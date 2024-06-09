#pragma once

#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include "mmstream.h"
#include <string>
#include <iostream>
#include <msclr/marshal.h>
//Windows stuff
#include <Windows.h>

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
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// Play
			// 
			this->Play->Location = System::Drawing::Point(291, 423);
			this->Play->Name = L"Play";
			this->Play->Size = System::Drawing::Size(150, 56);
			this->Play->TabIndex = 1;
			this->Play->Text = L"Play";
			this->Play->UseVisualStyleBackColor = true;
			this->Play->Anchor = static_cast<AnchorStyles>(AnchorStyles::Bottom);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(768, 507);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		SoundPlayer^ sound = gcnew SoundPlayer;
		String^ filePath = openFileDialog1->FileName;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		     sound->SoundLocation = filePath;
		     sound->Load();
		     sound->Play();
	    }
	}
	private: System::Void openFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		Stream^ myStream;

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->Filter = "Audio Files|*.mp3;*.wav;*.wma";
	    openFileDialog1->Title = "Select a Music File";
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			
			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				// Insert code to read the stream here.
				myStream->Close();
			}
		}
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
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
	//this->Play->Location = Point((this->ClientSize.Width - this->Play->Width) / 2, (this->ClientSize.Height - this->Play->Height) / 2);
}
};
}
