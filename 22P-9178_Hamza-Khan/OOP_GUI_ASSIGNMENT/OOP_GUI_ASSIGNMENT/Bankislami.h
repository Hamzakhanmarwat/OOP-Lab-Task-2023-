#pragma once
#include "HomePage.h"


namespace OOPGUIASSIGNMENT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary forBankislami
	/// </summary>
	public ref class Bankislami : public System::Windows::Forms::Form
	{
	public:
		Bankislami(void)
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
		~Bankislami()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  password;

	private: System::Windows::Forms::Label^  Username;

	private: System::Windows::Forms::TextBox^  UsernameTextBox;
	private: System::Windows::Forms::TextBox^  PasswordTextbox;



	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	protected:

	private:
		String^ User_name = "Hamza Khan";
		String^ Password = "exam123";
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Bankislami::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->password = (gcnew System::Windows::Forms::Label());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->UsernameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PasswordTextbox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(184, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(244, 282);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Bankislami::pictureBox1_Click);
			// 
			// password
			// 
			this->password->AutoSize = true;
			this->password->Font = (gcnew System::Drawing::Font(L"Unispace", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password->Location = System::Drawing::Point(76, 416);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(155, 25);
			this->password->TabIndex = 1;
			this->password->Text = L"Password : ";
			this->password->Click += gcnew System::EventHandler(this, &Bankislami::label1_Click);
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Font = (gcnew System::Drawing::Font(L"Unispace", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username->Location = System::Drawing::Point(63, 370);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(168, 25);
			this->Username->TabIndex = 2;
			this->Username->Text = L"User Name : ";
			// 
			// UsernameTextBox
			// 
			this->UsernameTextBox->AccessibleDescription = L"username";
			this->UsernameTextBox->AccessibleName = L"username";
			this->UsernameTextBox->Font = (gcnew System::Drawing::Font(L"NSimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UsernameTextBox->Location = System::Drawing::Point(216, 370);
			this->UsernameTextBox->Name = L"UsernameTextBox";
			this->UsernameTextBox->Size = System::Drawing::Size(303, 26);
			this->UsernameTextBox->TabIndex = 3;
			// 
			// PasswordTextbox
			// 
			this->PasswordTextbox->AccessibleName = L"password";
			this->PasswordTextbox->Font = (gcnew System::Drawing::Font(L"NSimSun", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordTextbox->Location = System::Drawing::Point(216, 415);
			this->PasswordTextbox->Name = L"PasswordTextbox";
			this->PasswordTextbox->Size = System::Drawing::Size(303, 26);
			this->PasswordTextbox->TabIndex = 4;
			this->PasswordTextbox->TextChanged += gcnew System::EventHandler(this, &Bankislami::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->AccessibleName = L"LoginButton";
			this->button1->BackColor = System::Drawing::SystemColors::Highlight;
			this->button1->Font = (gcnew System::Drawing::Font(L"MV Boli", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(270, 477);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 50);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Log In";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Bankislami::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Cascadia Code", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(403, 444);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(144, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Forget Password";
			// 
			//Bankislami
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 565);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->PasswordTextbox);
			this->Controls->Add(this->UsernameTextBox);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->password);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Bankislami";
			this->Text = L"Bankislami";
			this->Load += gcnew System::EventHandler(this, &Bankislami::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
		if (UsernameTextBox->Text == User_name && PasswordTextbox->Text==Password)
		{
			MessageBox::Show("Login Successful!");
			this->Hide();
			HomePage obj;
			obj.ShowDialog();
		}
		else if (UsernameTextBox->Text != User_name || PasswordTextbox->Text != Password)
		{
			MessageBox::Show("Login Failed Due to invalid Password or Username");
		}

	
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
