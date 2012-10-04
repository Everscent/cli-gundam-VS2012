#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class PublicTetrisScore;
		}

		using namespace System;
		using namespace Model;

		/**
		 * �e�g���X���_�C�x���gArgs
		 */
		public ref class TetrisScoreEventArgs : public EventArgs
		{
		/**
		 * �t�B�[���h
		 */
		private:
			PublicTetrisScore^ score;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TetrisScoreEventArgs(PublicTetrisScore^ score);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �X�R�A
			property PublicTetrisScore^ Score
			{
				PublicTetrisScore^ get() { return this->score; }
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * �e�g���X���_�C�x���g �f���Q�[�g
		 */
		public delegate void TetrisScoreEventHandler(Object^ sender, TetrisScoreEventArgs^ e);
		// ----------------------------------------------------------------------------------------------------
	}
}
