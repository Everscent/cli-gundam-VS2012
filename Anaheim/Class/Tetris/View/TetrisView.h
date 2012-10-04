#pragma once

#include "TetrisSound.h"
#include "TetrisScoreEventArgs.h"
#include "TetrisFieldEventArgs.h"

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class TetrisField;
			ref class TetrisMino;
			ref class TetrisModel;
		}

		namespace View
		{
			using namespace System;
			using namespace System::Windows::Forms;
			using namespace System::Collections::Generic;
			using namespace Model;

			ref class TetrisDrawing;

			/**
			 * �e�g���XView
			 */
			ref class TetrisView
			{
			/**
			 * �t�B�[���h
			 */
			private:
				array<TetrisDrawing^>^ drawings;
				TetrisSound^ sound;
				TetrisField^ field;
				List<TetrisMino^>^ minos;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisView(Control^ mainCanvas, array<Control^>^ nextCanvases, TetrisModel^ model, TetrisField^ field, List<TetrisMino^>^ minos);

			/**
			 * ���\�b�h
			 */
			private:
				void ModelMinoMoved(System::Object^  sender, System::EventArgs^  e);
				void ModelFieldChanged(System::Object^  sender, Anaheim::Tetris::TetrisFieldEventArgs^  e);
				void ModelTurnEnd(System::Object^  sender, System::EventArgs^  e);
				void ModelGameOver(System::Object^  sender, Anaheim::Tetris::TetrisScoreEventArgs^  e);
				void ModelCleared(System::Object^  sender, System::EventArgs^  e);

			public:
				/// �N���A
				void Clear();
				/// �`��i�S�`��j
				bool Draw();
				/// �`��i�w��j
				bool Draw(Control^ canvas);
				/// BGM�Đ�
				bool PlayBGM();
				/// BGM�ꎞ��~
				void PauseBGM();
				/// BGM��~
				void StopBGM();

			/**
			 * �v���p�e�B
			 */
			public:
				/// ���yON�ݒ�
				property bool SoundON
				{
					void set(bool value) { this->sound->ON = value; }
				}
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
