#pragma once

namespace Anaheim
{
	using namespace System;

	/**
	 * INI�t�@�C��
	 */
	public ref class IniFile
	{
	/**
	 * �t�B�[���h
	 */
	private:
		String^ fileName;

	/**
	 * �R���X�g���N�^
	 */
	public:
		IniFile(String^ fileName);

	/**
	 * ���\�b�h
	 */
	public:
		/// String�ǂݍ���
		String^ GetString(String^ section, String^ key, String^ defValue);
		/// String��������
		bool SetString(String^ section, String^ key, String^ value);
		/// bool�ǂݍ���
		bool GetBoolean(String^ section, String^ key, bool defValue);
		/// bool��������
		bool SetBoolean(String^ section, String^ key, bool value);
		/// int�ǂݍ���
		int GetInteger(String^ section, String^ key, int defValue);
		/// int��������
		bool SetInteger(String^ section, String^ key, int value);
	};
	// ----------------------------------------------------------------------------------------------------
}
