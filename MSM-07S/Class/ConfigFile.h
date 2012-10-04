#pragma once

namespace MSM_07S
{
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Net;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace Anaheim;

	/**
	 * �R���t�B�O�t�@�C��
	 */
	ref class ConfigFile
	{
	/**
	 * �t�B�[���h
	 */
	private:
		IniFile ^ iniFile;

		literal String^ WINDOW_SECTION    = "WINDOW";			///< Window�֘A �Z�N�V������
		literal String^ TOP_LOCATION_KEY  = "WINDOW_TOP";		///< Window Top
		literal String^ LEFT_LOCATION_KEY = "WINDOW_LEFT";		///< Window Left
		literal String^ WIDTH_SIZE_KEY    = "WINDOW_WIDTH";		///< Window Width
		literal String^ HEIGHT_SIZE_KEY   = "WINDOW_HEIGHT";	///< Window Height
		literal String^ UDP_IP_SECTION    = "UDP_IP";			///< UDP IP�֘A �Z�N�V������
		literal String^ LOCAL_IP_KEY      = "LOCAL_IP";			///< ���[�J��IP�A�h���X
		literal String^ LOCAL_PORT_KEY    = "LOCAL_PORT";		///< ���[�J���|�[�gNo.
		literal String^ REMOTE_IP_KEY     = "REMOTE_IP";		///< ���[���[�gIP�A�h���X
		literal String^ REMOTE_PORT_KEY   = "REMOTE_PORT";		///< ���[���[�g�|�[�gNo.
		literal String^ ENCODING_KEY      = "ENCODING";			///< �G���R�[�h

	/**
	 * �R�X�g���N�^
	 */
	public:
		ConfigFile(String^ fileName);

	/**
	 * ���\�b�h
	 */
	public:
		/// �E�B���h�E�ݒ�

		/// �ʒu�C�T�C�Y�ǂݍ���
		void LoadFormSizeAndLocation(Form^ form);
		/// �ʒu�C�T�C�Y�ۑ�
		void SaveFormSizeAndLocation(Form^ form);


		/// UDP�N���C�A���g

		/// ���[�J��IP�A�h���X�C�|�[�g�ǂݍ���
		IPEndPoint^ GetUdpLocalIPEndPoint();
		/// ���[�J��IP�A�h���X�C�|�[�g�ۑ�
		void SetUdpLocalIPEndPoint(IPEndPoint^ endPoint);
		/// �����[�gIP�A�h���X�C�|�[�g�ǂݍ���
		IPEndPoint^ GetUdpRemoteIPEndPoint();
		/// �����[�gIP�A�h���X�C�|�[�g�ۑ�
		void SetUdpRemoteIPEndPoint(IPEndPoint^ endPoint);
		/// �G���R�[�h�ǂݍ���
		Encoding^ GetUdpEncoding();
		/// �G���R�[�h�ۑ�
		void SetUdpEncoding(Encoding^ encoding);
	};
	// ----------------------------------------------------------------------------------------------------
}
