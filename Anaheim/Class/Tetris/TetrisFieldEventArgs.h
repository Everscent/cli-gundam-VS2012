#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class TetrisField;
		}

		using namespace System;
		using namespace Model;

		/**
		 * �e�g���X�t�B�[���h�C�x���gArgs
		 */
		ref class TetrisFieldEventArgs
		{
		/**
		 * �t�B�[���h
		 */
		private:
			TetrisField^ field;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TetrisFieldEventArgs(TetrisField^ field);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �t�B�[���h
			property TetrisField^ Field
			{
				TetrisField^ get() { return this->field; }
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * �e�g���X�����[�g�C�x���g �f���Q�[�g
		 */
		delegate void TetrisFieldEventHandler(Object^ sender, TetrisFieldEventArgs^ e);
		// ----------------------------------------------------------------------------------------------------
	}
}
