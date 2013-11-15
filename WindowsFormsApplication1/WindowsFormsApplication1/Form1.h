#pragma once

#include "Calculator.h"

namespace WindowsFormsApplication1 {

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
			pCalculator = new Calculator;
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
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;

	private: Calculator *pCalculator;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  buttonAdd;
	private: System::Windows::Forms::Button^  buttonEqual;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  buttonSub;
	private: System::Windows::Forms::Button^  buttonMultiply;

	private: System::Windows::Forms::Button^  buttonDivide;
	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::PictureBox^  pictureBox1;





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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->buttonEqual = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->buttonSub = (gcnew System::Windows::Forms::Button());
			this->buttonMultiply = (gcnew System::Windows::Forms::Button());
			this->buttonDivide = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(72, 205);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"0";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 89);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(235, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(72, 176);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(153, 176);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(315, 118);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(75, 23);
			this->buttonAdd->TabIndex = 4;
			this->buttonAdd->Text = L"+";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &Form1::buttonAdd_Click);
			// 
			// buttonEqual
			// 
			this->buttonEqual->Location = System::Drawing::Point(153, 205);
			this->buttonEqual->Name = L"buttonEqual";
			this->buttonEqual->Size = System::Drawing::Size(156, 23);
			this->buttonEqual->TabIndex = 5;
			this->buttonEqual->Text = L"=";
			this->buttonEqual->UseVisualStyleBackColor = true;
			this->buttonEqual->Click += gcnew System::EventHandler(this, &Form1::buttonEqual_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(234, 176);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(72, 147);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(152, 147);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 8;
			this->button6->Text = L"5";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(233, 147);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 9;
			this->button7->Text = L"6";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(70, 118);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 10;
			this->button8->Text = L"7";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(151, 118);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 11;
			this->button9->Text = L"8";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(232, 118);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 12;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// buttonSub
			// 
			this->buttonSub->Location = System::Drawing::Point(315, 147);
			this->buttonSub->Name = L"buttonSub";
			this->buttonSub->Size = System::Drawing::Size(75, 23);
			this->buttonSub->TabIndex = 13;
			this->buttonSub->Text = L"-";
			this->buttonSub->UseVisualStyleBackColor = true;
			this->buttonSub->Click += gcnew System::EventHandler(this, &Form1::buttonSub_Click);
			// 
			// buttonMultiply
			// 
			this->buttonMultiply->Location = System::Drawing::Point(315, 176);
			this->buttonMultiply->Name = L"buttonMultiply";
			this->buttonMultiply->Size = System::Drawing::Size(75, 23);
			this->buttonMultiply->TabIndex = 14;
			this->buttonMultiply->Text = L"*";
			this->buttonMultiply->UseVisualStyleBackColor = true;
			this->buttonMultiply->Click += gcnew System::EventHandler(this, &Form1::buttonMultiply_Click);
			// 
			// buttonDivide
			// 
			this->buttonDivide->Location = System::Drawing::Point(315, 205);
			this->buttonDivide->Name = L"buttonDivide";
			this->buttonDivide->Size = System::Drawing::Size(75, 23);
			this->buttonDivide->TabIndex = 15;
			this->buttonDivide->Text = L"/";
			this->buttonDivide->UseVisualStyleBackColor = true;
			this->buttonDivide->Click += gcnew System::EventHandler(this, &Form1::buttonDivide_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(314, 89);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 23);
			this->buttonClear->TabIndex = 16;
			this->buttonClear->Text = L"C";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &Form1::buttonClear_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(125, 28);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(415, 272);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->buttonDivide);
			this->Controls->Add(this->buttonMultiply);
			this->Controls->Add(this->buttonSub);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->buttonEqual);
			this->Controls->Add(this->buttonAdd);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text = "0";
			 }
	private: System::Void buttonAdd_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox1->Text += "+";
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "1";
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "2";
		 }
private: System::Void buttonEqual_Click(System::Object^  sender, System::EventArgs^  e) {
			 switch(this->textBox1->Text[1])
			 {
			 case '+': this->pCalculator->addition(this->textBox1->Text[0] - '0', this->textBox1->Text[2] - '0');
				 break;
			 case '-': this->pCalculator->subtraction(this->textBox1->Text[0] - '0', this->textBox1->Text[2] - '0');
				 break;
			 case '*': this->pCalculator->multiplication(this->textBox1->Text[0] - '0', this->textBox1->Text[2] - '0');
				 break;
			 case '/': this->pCalculator->division(this->textBox1->Text[0] - '0', this->textBox1->Text[2] - '0');
				 break;
			 }
			 this->textBox1->Text = this->pCalculator->getAccumulator().ToString();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "3";
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "4";
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "5";
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "6";
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "7";
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "8";
		 }
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "9";
		 }
private: System::Void buttonSub_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "-";			 
		 }
private: System::Void buttonMultiply_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "*";
		 }
private: System::Void buttonDivide_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text += "/";
		 }
private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->textBox1->Text = "";
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

