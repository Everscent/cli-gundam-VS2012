#pragma once

#include "TetrisFieldEventArgs.h"
#include "TetrisScoreEventArgs.h"
#include "TetrisScore.h"

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			using namespace System;
			using namespace System::Collections::Generic;

			ref class TetrisField;
			ref class TetrisMino;
			ref class TetrisRemoting;

			/**
			 * �e�g���XModel
			 */
			ref class TetrisModel
			{
			/**
			 * �t�B�[���h
			 */
			private:
				TetrisField^ field;
				List<TetrisMino^>^ minos;
				TetrisScore^ score;
				TetrisRemoting^ remoting;
				int nextCount;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisModel(TetrisField^ field, List<TetrisMino^>^ minos, TetrisScore^ score, int nextCount);

			/**
			 * ���\�b�h
			 */
			private:
				bool RotateMoveCore(bool isSuccessful);
				void AddNextMinos();
				bool SetNewMino();
				bool EndDown();
				void SendRemote();

			public:
				/// �N���A
				void Clear();
				/// ������
				void Initialize();
				/// �E��]
				bool RotateRight();
				/// ����]
				bool RotateLeft();
				/// �E�ړ�
				bool MoveRight();
				/// ���ړ�
				bool MoveLeft();
				/// ���ړ�
				bool MoveDown();
				/// ���ړ��i�����㏈���j
				bool MoveDownAutomatic();
				/// �n�[�h�h���b�v
				bool HardDrop();
				/// �����[�g�X�^�[�g
				bool StartRemote();
				/// �����[�g�X�g�b�v
				bool StopRemote();

			/**
			 * �v���p�e�B
			 */
			private:
				/// �������Ă���~�m
				property TetrisMino^ CurrentMino
				{
					TetrisMino^ get() { return ((this->minos == nullptr || this->minos->Count == 0) ? nullptr : this->minos[0]); }
				}
			public:
				/// �X�R�A
				property PublicTetrisScore^ Score
				{
					PublicTetrisScore^ get () { return this->score; }
				}

			/**
			 * �C�x���g
			 */
			protected:
				virtual void OnMinoMoved(EventArgs^ e);
				virtual void OnFieldChanged(TetrisFieldEventArgs^ e);
				virtual void OnScoreChanged(TetrisScoreEventArgs^ e);
				virtual void OnTurnEnd(EventArgs^ e);
				virtual void OnGameOver(TetrisScoreEventArgs^ e);
				virtual void OnCleared(EventArgs^ e);

			public:
				/// �~�m�ړ�
				event EventHandler^ MinoMoved;
				/// �t�B�[���h�X�V�C�x���g
				event TetrisFieldEventHandler^ FieldChanged;
				/// �^�[���G���h�C�x���g
				event EventHandler^ TurnEnd;
				/// �X�R�A�X�V�C�x���g
				event TetrisScoreEventHandler^ ScoreChanged;
				/// �Q�[���I�[�o�[�C�x���g
				event TetrisScoreEventHandler^ GameOver;
				/// �N���A�C�x���g
				event EventHandler^ Cleared;
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
