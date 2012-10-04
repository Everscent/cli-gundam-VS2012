#pragma once

namespace RX77_2
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
	};
	// ----------------------------------------------------------------------------------------------------
}
