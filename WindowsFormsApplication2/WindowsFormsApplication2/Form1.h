#pragma once
#include <string>

namespace WindowsFormsApplication2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonOpen;
	protected: 
	private: System::Windows::Forms::TextBox^  textBoxFile;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::CheckBox^  checkBoxEncrypt;
	private: System::Windows::Forms::WebBrowser^  webBrowser1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->textBoxFile = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->checkBoxEncrypt = (gcnew System::Windows::Forms::CheckBox());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->SuspendLayout();
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(82, 218);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(75, 23);
			this->buttonOpen->TabIndex = 0;
			this->buttonOpen->Text = L"Open";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &Form1::buttonOpen_Click);
			// 
			// textBoxFile
			// 
			this->textBoxFile->Location = System::Drawing::Point(53, 58);
			this->textBoxFile->Name = L"textBoxFile";
			this->textBoxFile->Size = System::Drawing::Size(317, 20);
			this->textBoxFile->TabIndex = 1;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// checkBoxEncrypt
			// 
			this->checkBoxEncrypt->AutoSize = true;
			this->checkBoxEncrypt->Location = System::Drawing::Point(53, 120);
			this->checkBoxEncrypt->Name = L"checkBoxEncrypt";
			this->checkBoxEncrypt->Size = System::Drawing::Size(62, 17);
			this->checkBoxEncrypt->TabIndex = 2;
			this->checkBoxEncrypt->Text = L"Encrypt";
			this->checkBoxEncrypt->UseVisualStyleBackColor = true;
			this->checkBoxEncrypt->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBoxEncrypt_CheckedChanged);
			// 
			// webBrowser1
			// 
			this->webBrowser1->Location = System::Drawing::Point(12, 12);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(768, 379);
			this->webBrowser1->TabIndex = 3;
			this->webBrowser1->Url = (gcnew System::Uri(L"http://www.google.com", System::UriKind::Absolute));
			this->webBrowser1->DocumentCompleted += gcnew System::Windows::Forms::WebBrowserDocumentCompletedEventHandler(this, &Form1::webBrowser1_DocumentCompleted);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(736, 346);
			this->Controls->Add(this->webBrowser1);
			this->Controls->Add(this->checkBoxEncrypt);
			this->Controls->Add(this->textBoxFile);
			this->Controls->Add(this->buttonOpen);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonOpen_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->openFileDialog1->ShowDialog();
				 IO::Stream ^input;
				 input = this->openFileDialog1->OpenFile();

				 int byteRead;
				 byteRead = input->ReadByte();
				 this->textBoxFile->Text = Convert::ToString(Convert::ToChar(byteRead));
			 }
	private: System::Void checkBoxEncrypt_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 static bool checked;
				 if(checked == false)
				 {
					 this->textBoxFile->Text = this->textBoxFile->Text->ToUpper();
					 checked = true;
				 }
				 else
				 {
					 this->textBoxFile->Text = this->textBoxFile->Text->ToLower();
					 checked = false;
				 }
			 }

private: System::Void webBrowser1_DocumentCompleted(System::Object^  sender, System::Windows::Forms::WebBrowserDocumentCompletedEventArgs^  e) {
			

		 }
};
}

