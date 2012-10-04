#pragma once

namespace Anaheim
{
	using namespace System;
	using namespace System::Net;
	using namespace System::Net::Sockets;

	/**
	 *	FTP�N���C�A���g
	 */
	public ref class FtpClient
	{
	/**
	 * �t�B�[���h
	 */
	private:
		IPAddress^ ipAddress;
		NetworkCredential^ credential;	///< ���[�U���C�p�X���[�h

	public:
		/// �������[�U��
		literal String^ ANONYMITY_STRING = "anonymous";

	/**
	 * �R���X�g���N�^
	 */
	public:
		FtpClient();

	/**
	 * ���\�b�h
	 */
	private:
		String^ GetRootUri();
		array<String^>^ GetDirectoryAndFileArray(String^ path, bool isDirectory);

	public:
		/// �ڑ�
		bool Connect(IPAddress^ ip, String^ user, String^ pass);
		/// �ڑ��i�����j
		bool Connect(IPAddress^ ip, String^ pass);
		/// �ؒf
		bool DisConnect();
		/// �_�E�����[�h
		bool Download(String^ remotePath, String^ localPath);
		/// �A�b�v���[�h
		bool Upload(String^ remotePath, String^ localPath);
		/// �f�B���N�g���ꗗ�擾
		array<String^>^ GetDirectory(String^ path);
		/// �t�@�C�����ꗗ�擾
		array<String^>^ GetFileName(String^ path);
		/// �t�@�C���T�C�Y�擾
		int GetFileSize(String^ path);
		/// �t�@�C���X�^���v�擾
		DateTime GetFileDateTime(String^ path);

	/**
	 * �v���p�e�B
	 */
	public:
		/// ���[�gURI
		property String^ RootURI
		{
			String^ get() { return this->GetRootUri(); }
		}
	};
	// ----------------------------------------------------------------------------------------------------
}
