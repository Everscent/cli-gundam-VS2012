#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			using namespace System;
			using namespace System::Drawing;

			/**
			 * �e�g���X �X�R�A�i���J�p�j
			 */
			public ref class PublicTetrisScore abstract
			{
			/**
			 * �R���X�g���N�^
			 */
			public:
				PublicTetrisScore();

			/**
			 * �v���p�e�B
			 */
			public:
				/// �X�R�A
				property int Score
				{
					virtual int get() abstract;
				}
				/// Single�J�E���g
				property int SingleCount
				{
					virtual int get() abstract;
				}
				/// Double�J�E���g
				property int DoubleCount
				{
					virtual int get() abstract;
				}
				/// Triple�J�E���g
				property int TripleCount
				{
					virtual int get() abstract;
				}
				/// TETRiS�J�E���g
				property int TetrisCount
				{
					virtual int get() abstract;
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * �e�g���X �X�R�A
			 */
			ref class TetrisScore : public PublicTetrisScore
			{
			/**
			 * �t�B�[���h
			 */
			private:
				int score;
				int singleCount;
				int doubleCount;
				int tripleCount;
				int tetrisCount;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisScore();

			/**
			 * ���\�b�h
			 */
			public:
				/// �N���A
				void Clear();

				/// �X�V
				bool UpdateScore(int removeCount, bool isPerfect);

			/**
			 * �v���p�e�B
			 */
			public:
				/// �X�R�A
				property int Score
				{
					virtual int get() override { return this->score; }
				}
				/// Single�J�E���g
				property int SingleCount
				{
					virtual int get() override { return this->singleCount; }
				}
				/// Double�J�E���g
				property int DoubleCount
				{
					virtual int get() override { return this->doubleCount; }
				}
				/// Triple�J�E���g
				property int TripleCount
				{
					virtual int get() override { return this->tripleCount; }
				}
				/// TETRiS�J�E���g
				property int TetrisCount
				{
					virtual int get() override { return this->tetrisCount; }
				}
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
