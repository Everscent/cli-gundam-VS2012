#pragma once

#include "TetrisController.h"
#include "TetrisScoreEventArgs.h"

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

		using namespace System;
		using namespace System::Windows::Forms;
		using namespace System::Collections::Generic;
		using namespace Model;
		using namespace View;
		using namespace Controller;

		/**
		 * �e�g���X�p�b�P�[�W
		 */
		public ref class TetrisPackage
		{
		/**
		 * �t�B�[���h
		 */
		private:
			TetrisModel^ model;
			TetrisView^ view;
			TetrisController^ controller;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TetrisPackage(Control^ mainCanvas, array<Control^>^ nextCanvases);

		/**
		 * ���\�b�h
		 */
		private:
			void ModelScoreChanged(System::Object^  sender, Anaheim::Tetris::TetrisScoreEventArgs^  e);
			void ModelGameOver(System::Object^  sender, Anaheim::Tetris::TetrisScoreEventArgs^  e);
			void ControllerGameOver(System::Object^  sender, Anaheim::Tetris::TetrisScoreEventArgs^  e);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �R���g���[��
			property PublicTetrisController^ Controller
			{
				PublicTetrisController^ get() { return this->controller; }
			}

		/**
		 * �C�x���g
		 */
		protected:
			virtual void OnScoreChanged(TetrisScoreEventArgs^ e);
			virtual void OnGameOver(TetrisScoreEventArgs^ e);

		public:
			/// �X�R�A�X�V�C�x���g
			event TetrisScoreEventHandler^ ScoreChanged;
			/// �Q�[���I�[�o�[�C�x���g
			event TetrisScoreEventHandler^ GameOver;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
