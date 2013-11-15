#pragma once


#include "Compiler.h"
#include "InfixToPostfix.h"
#include "Simpletron.h"
#include "SimpletronSimulator.h"
#include "Stack.h"

namespace Onorati_PA7 {

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
			pCompiler = new Compiler();
			pProgram = new Simpletron();
			pComputer = new SimpletronSimulator();
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
	private: System::Windows::Forms::Button^  buttonLoadSL;
			 Compiler *pCompiler;
			 Simpletron *pProgram;
			 SimpletronSimulator *pComputer;
	private: System::Windows::Forms::Button^  buttonRun;
	private: System::Windows::Forms::TextBox^  textBoxInput;

	protected: 

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
			this->buttonLoadSL = (gcnew System::Windows::Forms::Button());
			this->buttonRun = (gcnew System::Windows::Forms::Button());
			this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// buttonLoadSL
			// 
			this->buttonLoadSL->BackColor = System::Drawing::SystemColors::Desktop;
			this->buttonLoadSL->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonLoadSL->Location = System::Drawing::Point(69, 37);
			this->buttonLoadSL->Name = L"buttonLoadSL";
			this->buttonLoadSL->Size = System::Drawing::Size(154, 23);
			this->buttonLoadSL->TabIndex = 0;
			this->buttonLoadSL->Text = L"Compile Program";
			this->buttonLoadSL->UseVisualStyleBackColor = false;
			this->buttonLoadSL->Click += gcnew System::EventHandler(this, &Form1::buttonLoadSL_Click);
			// 
			// buttonRun
			// 
			this->buttonRun->BackColor = System::Drawing::SystemColors::Desktop;
			this->buttonRun->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->buttonRun->Location = System::Drawing::Point(69, 88);
			this->buttonRun->Name = L"buttonRun";
			this->buttonRun->Size = System::Drawing::Size(154, 23);
			this->buttonRun->TabIndex = 1;
			this->buttonRun->Text = L"Run SML Program";
			this->buttonRun->UseVisualStyleBackColor = false;
			this->buttonRun->Click += gcnew System::EventHandler(this, &Form1::buttonRun_Click);
			// 
			// textBoxInput
			// 
			this->textBoxInput->BackColor = System::Drawing::SystemColors::InfoText;
			this->textBoxInput->ForeColor = System::Drawing::SystemColors::Info;
			this->textBoxInput->Location = System::Drawing::Point(69, 151);
			this->textBoxInput->Name = L"textBoxInput";
			this->textBoxInput->Size = System::Drawing::Size(154, 20);
			this->textBoxInput->TabIndex = 2;
			this->textBoxInput->TextChanged += gcnew System::EventHandler(this, &Form1::textBoxInput_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(506, 358);
			this->Controls->Add(this->textBoxInput);
			this->Controls->Add(this->buttonRun);
			this->Controls->Add(this->buttonLoadSL);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonLoadSL_Click(System::Object^  sender, System::EventArgs^  e) {
				 ifstream inFile;
				 ofstream outFile;
				 inFile.open("SimpleProgram.txt", ios::in);
				 outFile.open("SMLProgram.txt");
				 if(inFile.is_open())
				 {
					 pCompiler->compileFirstPass(inFile, *pProgram);
					 pCompiler->compileSecondPass(outFile, *pProgram);
				 }
				 inFile.close();
				 outFile.close();
			 }
	private: System::Void buttonRun_Click(System::Object^  sender, System::EventArgs^  e) {
				 pComputer->runProgram(*pProgram);
			 }
private: System::Void textBoxInput_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		 }
};
}

