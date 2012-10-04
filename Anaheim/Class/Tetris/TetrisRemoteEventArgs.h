#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class TetrisField;
			ref class TetrisMino;
		}

		using namespace System;
		using namespace Model;

		/**
		 * �e�g���X�����[�g�C�x���gArgs
		 */
		public ref class TetrisRemoteEventArgs : public EventArgs
		{
		/**
		 * �t�B�[���h
		 */
		private:
			TetrisField^ field;
			TetrisMino^ mino;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TetrisRemoteEventArgs(TetrisField^ field, TetrisMino^ mino);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �t�B�[���h
			property TetrisField^ Field
			{
				TetrisField^ get() { return this->field; }
			}
			/// �~�m
			property TetrisMino^ Mino
			{
				TetrisMino^ get() { return this->mino; }
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * �e�g���X�����[�g�C�x���g �f���Q�[�g
		 */
		public delegate void TetrisRemoteEventHandler(Object^ sender, TetrisRemoteEventArgs^ e);
		// ----------------------------------------------------------------------------------------------------
	}
}
