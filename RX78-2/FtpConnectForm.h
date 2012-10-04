#pragma once

#include "ConfigFile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Anaheim;

namespace RX78_2
{
	/// <summary>
	/// FtpConnectForm �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public ref class FtpConnectForm : public System::Windows::Forms::Form
	{
	private: ConfigFile^ config;		///< �R���t�B�O�t�@�C��

	private: System::Windows::Forms::Button^  buttonOk;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Label^  labelAddress;
	private: System::Windows::Forms::Label^  labelUser;
	private: System::Windows::Forms::Label^  labelPassword;
	private: System::Windows::Forms::TextBox^  textAddress;
	private: System::Windows::Forms::TextBox^  textUser;
	private: System::Windows::Forms::TextBox^  textPassword;
	private: System::Windows::Forms::CheckBox^  checkAnonymity;
	private: System::Windows::Forms::CheckBox^  checkPassword;

	public:
		FtpConnectForm(RX78_2::ConfigFile^ config)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^ �R�[�h��ǉ����܂�
			//
			this->config = config;
			this->Initialize();
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~FtpConnectForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonOk = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->labelUser = (gcnew System::Windows::Forms::Label());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->textAddress = (gcnew System::Windows::Forms::TextBox());
			this->textUser = (gcnew System::Windows::Forms::TextBox());
			this->textPassword = (gcnew System::Windows::Forms::TextBox());
			this->checkAnonymity = (gcnew System::Windows::Forms::CheckBox());
			this->checkPassword = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// buttonOk
			// 
			this->buttonOk->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->buttonOk->Location = System::Drawing::Point(64, 138);
			this->buttonOk->Name = L"buttonOk";
			this->buttonOk->Size = System::Drawing::Size(75, 23);
			this->buttonOk->TabIndex = 0;
			this->buttonOk->Text = L"OK";
			this->buttonOk->UseVisualStyleBackColor = true;
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(205, 138);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(75, 23);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"�L�����Z��";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Location = System::Drawing::Point(17, 25);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(51, 12);
			this->labelAddress->TabIndex = 2;
			this->labelAddress->Text = L"IP�A�h���X";
			// 
			// labelUser
			// 
			this->labelUser->AutoSize = true;
			this->labelUser->Location = System::Drawing::Point(12, 58);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(56, 12);
			this->labelUser->TabIndex = 3;
			this->labelUser->Text = L"���[�U�[ID";
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(16, 93);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(52, 12);
			this->labelPassword->TabIndex = 4;
			this->labelPassword->Text = L"�p�X���[�h";
			// 
			// textAddress
			// 
			this->textAddress->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->textAddress->Location = System::Drawing::Point(80, 22);
			this->textAddress->Name = L"textAddress";
			this->textAddress->Size = System::Drawing::Size(200, 19);
			this->textAddress->TabIndex = 5;
			// 
			// textUser
			// 
			this->textUser->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->textUser->Location = System::Drawing::Point(80, 55);
			this->textUser->Name = L"textUser";
			this->textUser->Size = System::Drawing::Size(100, 19);
			this->textUser->TabIndex = 6;
			// 
			// textPassword
			// 
			this->textPassword->ImeMode = System::Windows::Forms::ImeMode::Disable;
			this->textPassword->Location = System::Drawing::Point(80, 90);
			this->textPassword->Name = L"textPassword";
			this->textPassword->PasswordChar = '*';
			this->textPassword->Size = System::Drawing::Size(100, 19);
			this->textPassword->TabIndex = 7;
			// 
			// checkAnonymity
			// 
			this->checkAnonymity->AutoSize = true;
			this->checkAnonymity->Location = System::Drawing::Point(208, 57);
			this->checkAnonymity->Name = L"checkAnonymity";
			this->checkAnonymity->Size = System::Drawing::Size(72, 16);
			this->checkAnonymity->TabIndex = 8;
			this->checkAnonymity->Text = L"�����ڑ�";
			this->checkAnonymity->UseVisualStyleBackColor = true;
			this->checkAnonymity->CheckedChanged += gcnew System::EventHandler(this, &FtpConnectForm::checkAnonymity_CheckedChanged);
			// 
			// checkPassword
			// 
			this->checkPassword->AutoSize = true;
			this->checkPassword->Location = System::Drawing::Point(208, 92);
			this->checkPassword->Name = L"checkPassword";
			this->checkPassword->Size = System::Drawing::Size(95, 16);
			this->checkPassword->TabIndex = 9;
			this->checkPassword->Text = L"�p�X���[�h�ۑ�";
			this->checkPassword->UseVisualStyleBackColor = true;
			// 
			// FormFtpConnect
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::GhostWhite;
			this->ClientSize = System::Drawing::Size(344, 173);
			this->ControlBox = false;
			this->Controls->Add(this->checkPassword);
			this->Controls->Add(this->checkAnonymity);
			this->Controls->Add(this->textPassword);
			this->Controls->Add(this->textUser);
			this->Controls->Add(this->textAddress);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelUser);
			this->Controls->Add(this->labelAddress);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOk);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormFtpConnect";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RX78-2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/// ������
	private: void Initialize()
			 {
				 IPAddress^ address = this->config->GetFtpAddress();
				 if (address != nullptr)
				 {
					 this->textAddress->Text = address->ToString();
				 }
				 String^ user = this->config->GetFtpUserName();
				 if (user == FtpClient::ANONYMITY_STRING)
				 {
					 this->checkAnonymity->Checked = true;
				 }else
				 {
					 this->textUser->Text = this->config->GetFtpUserName();
				 }
				 String^ pass = this->config->GetFtpPassword();
				 if (!pass->Equals(String::Empty))
				 {
					 this->textPassword->Text = pass;
					 this->checkPassword->Checked = true;
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// �`�F�b�N�{�b�N�X
	private: System::Void checkAnonymity_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (this->checkAnonymity->Checked)
				 {
					 this->textUser->Text = FtpClient::ANONYMITY_STRING;
					 this->textUser->Enabled = false;
				 }
				 else
				 {
					 this->textUser->Text = String::Empty;
					 this->textUser->Enabled = true;
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// �A�h���X
	public: property IPAddress^ IpAddress
			 {
				 IPAddress^ get()
				 {
					 IPAddress^ address = nullptr;
					 try
					 {
						 address = IPAddress::Parse(this->textAddress->Text);
					 }
					 catch (Exception^)
					 {
						 return nullptr;
					 }
					 return address;
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// ���[�U��
	public: property String^ UserName
			 {
				 String^ get() { return this->textUser->Text; }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// �p�X���[�h
	public: property String^ Password
			 {
				 String^ get() { return this->textPassword->Text; }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// �p�X���[�h�ۑ�
	public: property bool SavePassword
			 {
				 bool get() { return this->checkPassword->Checked; }
			 }
			 // ----------------------------------------------------------------------------------------------------
	};
}
