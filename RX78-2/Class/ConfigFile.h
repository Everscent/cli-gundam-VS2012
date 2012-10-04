#pragma once

namespace RX78_2
{
	using namespace System;
	using namespace System::Xml;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;
	using namespace System::Net;
	using namespace System::Text;

	/**
	 * �R���t�B�O�t�@�C��
	 */
	public ref class ConfigFile
	{
	/**
	 * �t�B�[���h
	 */
	private:
		XmlDocument^ xmlDoc;
		String^ fileName;

	/**
	 * �R���X�g���N�^
	 */
	public:
		ConfigFile(String^ fileName);

	/**
	 * ���\�b�h
	 */
	private:
		XmlElement^ GetRootElement();
		XmlElement^ GetElement(XmlElement^ parent, String^ name);
		XmlElement^ GetElement(XmlElement^ parent, String^ name, String^ attrName, String^ attrValue);

		String^ GetValue(XmlElement^ parent, String^ name, String^ defValue);
		String^ GetValue(XmlElement^ parent, String^ name, String^ attrName, String^ attrValue, String^ defValue);
		void SetValue(XmlElement^ parent, String^ name, String^ value);
		void SetValue(XmlElement^ parent, String^ name, String^ attrName, String^ attrValue, String^ value);

		XmlElement^ GetWindowElement(String^ name);
		XmlElement^ GetReportElement();
		XmlElement^ GetTcpServerElement();
		XmlElement^ GetFtpClientElement();
		XmlElement^ GetPicturePuzzleElement();
		XmlElement^ GetBinaryClockElement();
		XmlElement^ GetTetrisElement();
		XmlElement^ GetDirectXElement();

	public:
		/// �ۑ�
		void Save();


		/// �E�B���h�E�ݒ�

		/// �ʒu�C�T�C�Y�ǂݍ���
		void LoadFormSizeAndLocation(Form^ form);
		/// �ʒu�C�T�C�Y�ۑ�
		void SaveFormSizeAndLocation(Form^ form);


		/// ���|�[�g�ҏW

		/// �t�@�C�����ǂݍ���
		String^ GetReportFileName();
		/// �t�@�C�����ۑ�
		void SetReportFileName(String^ fileName);


		/// TCP�T�[�o

		/// IP�A�h���X�C�|�[�g�ǂݍ���
		IPEndPoint^ GetTcpIPEndPoint();
		/// IP�A�h���X�C�|�[�g�ۑ�
		void SetTcpIPEndPoint(IPEndPoint^ endPoint);
		/// �G���R�[�h�ǂݍ���
		Encoding^ GetTcpEncoding();
		/// �G���R�[�h�ۑ�
		void SetTcpEncoding(Encoding^ encoding);


		/// FTP�N���C�A���g

		/// �����[�g�p�X�ǂݍ���
		String^ GetFtpRemotePath();
		/// �����[�g�p�X�ۑ�
		void SetFtpRemotePath(String^ path);
		/// ���[�J���p�X�ǂݍ���
		String^ GetFtpLocalPath();
		/// ���[�J���p�X�ۑ�
		void SetFtpLocalPath(String^ path);
		/// FTP�T�[�oIP�A�h���X�ǂݍ���
		IPAddress^ GetFtpAddress();
		/// FTP�T�[�oIP�A�h���X�ۑ�
		void SetFtpAddress(IPAddress^ address);
		/// ���[�U���ǂݍ���
		String^ GetFtpUserName();
		/// ���[�U���ۑ�
		void SetFtpUserName(String^ user);
		/// �p�X���[�h�ǂݍ���
		String^ GetFtpPassword();
		/// �p�X���[�h�ۑ�
		void SetFtpPassword(String^ password);


		/// �ʐ^�p�Y��

		/// �t�@�C���p�X�ǂݍ���
		String^ GetPicturePath();
		/// �t�@�C���p�X�ۑ�
		void SetPicturePath(String^ path);


		/// �o�C�i���N���b�N

		/// �^�C�}�[�����ǂݍ���
		String^ GetTimerDateTime();
		/// �^�C�}�[�����ۑ�
		void SetTimerDateTime(String^ time);
		/// �^�C�}�[���ԓǂݍ���
		String^ GetTimetTimeSpan();
		/// �^�C�}�[���ԕۑ�
		void SetTimerTimeSpan(String^ span);
		/// ���� or ���ԓǂݍ���
		bool GetTimerIsSpan();
		/// ���� or ���ԕۑ�
		void SetTimerIsSpan(bool isSpan);


		/// �e�g���X

		/// �����L���O�ǂݍ���
		int GetTetrisScore(int ranking);
		/// �����L���O�ۑ�
		void SetTetrisScore(int score);
		/// �T�E���hON�ǂݍ���
		bool GetTetrisSoundON();
		/// �T�E���hON�ۑ�
		void SetTetrisSoundON(bool isON);
		/// �����[�g�L���ǂݍ���
		bool GetTetrisRemoteEnabled();
		/// �����[�g�L���ۑ�
		void SetTetrisRemoteEnabled(bool enabled);


		/// DirectX

		/// XYZ���\��ON�ǂݍ���
		bool GetDirectXXYZAxisON();
		/// XYZ���\��ON�ۑ�
		void SetDirectXXYZAxisON(bool isON);
	};
	// ----------------------------------------------------------------------------------------------------
}
