#pragma once

namespace Anaheim
{
	using namespace System;

	/**
	 * �V���[�g�J�b�g�t�@�C��
	 */
	public ref class ShortcutFile
	{
	/**
	 * �t�B�[���h
	 */
	private:
		String^ fileName;
		String^ linkPath;
		String^ argument;
		String^ workDirectory;
		String^ comment;

	/**
	 * �R���X�g���N�^
	 */
	public:
		ShortcutFile(String^ fileName, String^ linkPath);

	/**
	 * ���\�b�h
	 */
	public:
		/// �V���[�g�J�b�g�쐬
		void Save();

	/**
	 * �v���p�e�B
	 */
	public:
		/// �R�}���h�p�����[�^
		property String^ Argument
		{
			void set(String^ value) { this->argument = value; }
		}
		/// ��ƃf�B���N�g��
		property String^ WorkDirectory
		{
			void set(String^ value) { this->workDirectory = value; }
		}
		/// �R�����g
		property String^ Comment
		{
			void set(String^ value) { this->comment = value; }
		}
	};
	// ----------------------------------------------------------------------------------------------------
}
