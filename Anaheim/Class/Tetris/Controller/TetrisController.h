#pragma once

#include "TetrisScoreEventArgs.h"
#include "TetrisFieldEventArgs.h"
#include "TetrisKey.h"

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class TetrisModel;
		}

		namespace View
		{
			ref class TetrisView;
		}

		namespace Controller
		{
			using namespace System;
			using namespace System::Windows::Forms;
			using namespace Model;
			using namespace View;

			/**
			 * �e�g���XController�i���J�p�j
			 */
			public ref class PublicTetrisController abstract
			{
			/**
			 * �R���X�g���N�^
			 */
			public:
				PublicTetrisController();

			/**
			 * ���\�b�h
			 */
			public:
				/// �N���A
				virtual void Clear() abstract;
				/// ������
				virtual void Initialize() abstract;
				/// �X�^�[�g
				virtual bool Start() abstract;
				/// �ꎞ��~
				virtual bool Pause() abstract;
				/// �����[�g�X�^�[�g
				virtual bool StartRemote() abstract;
				/// �����[�g�X�g�b�v
				virtual bool StopRemote() abstract;

			/**
			 * �v���p�e�B
			 */
			public:
				/// ���s��������
				property bool IsRunning
				{
					virtual bool get() abstract;
				}
				/// �L�[
				property PublicTetrisKey^ Key
				{
					virtual PublicTetrisKey^ get() abstract;
				}
				/// ���yON�ݒ�
				property bool SoundON
				{
					virtual void set(bool value) abstract;
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * �e�g���XController
			 */
			ref class TetrisController : public PublicTetrisController
			{
			/**
			 * �t�B�[���h
			 */
			private:
				TetrisModel^ model;
				TetrisView^ view;
				TetrisKey^ key;
				Timer^ timer;
				bool isPause;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisController(TetrisModel^ model, TetrisView^ view, Control^ mainCanvas, array<Control^>^ nextCanvases);

			/**
			 * ���\�b�h
			 */
			private:
				void TimerTick(System::Object^  sender, System::EventArgs^  e);
				void CanvasPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
				void ModelFieldChanged(System::Object^  sender, Anaheim::Tetris::TetrisFieldEventArgs^  e);
				void ModelGameOver(System::Object^  sender, Anaheim::Tetris::TetrisScoreEventArgs^  e);
				void SetSoundON(bool isON);

			public:
				/// �N���A
				virtual void Clear() override;
				/// ������
				virtual void Initialize() override;
				/// �X�^�[�g
				virtual bool Start() override;
				/// �ꎞ��~
				virtual bool Pause() override;
				/// �����[�g�X�^�[�g
				virtual bool StartRemote() override;
				/// �����[�g�X�g�b�v
				virtual bool StopRemote() override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// ���s��������
				property bool IsRunning
				{
					virtual bool get() override { return this->timer->Enabled; }
				}
				/// �L�[
				property PublicTetrisKey^ Key
				{
					virtual PublicTetrisKey^ get() override { return this->key; }
				}
				/// ���yON�ݒ�
				property bool SoundON
				{
					virtual void set(bool value) override { this->SetSoundON(value); }
				}

			/**
			 * �C�x���g
			 */
			protected:
				virtual void OnGameOver(TetrisScoreEventArgs^ e);

			public:
				/// �Q�[���I�[�o�[�C�x���g
				event TetrisScoreEventHandler^ GameOver;
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
