#pragma once

#include "TetrisRemoteEventArgs.h"

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class TetrisMino;
			ref class TetrisRemoting;
		}

		namespace View
		{
			ref class MainTetrisDrawing;
		}

		using namespace System;
		using namespace System::Windows::Forms;
		using namespace Model;
		using namespace View;

		/**
		 * �e�g���X�����[�g
		 */
		public ref class TetrisRemotePackage
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Control^ canvas;
			TetrisRemoting^ remoting;
			MainTetrisDrawing^ drawing;
			TetrisMino^ mino;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TetrisRemotePackage(Control^ canvas);

		/**
		 * ���\�b�h
		 */
		private:
			void RemoteReceived(System::Object^ sender, TetrisRemoteEventArgs^ e);
			void CanvasPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
			void CanvasResize(System::Object^  sender, System::EventArgs^  e);
			bool Draw();

		public:
			/// �����[�g�X�^�[�g
			bool StartRemote();
			/// �����[�g�X�g�b�v
			bool StopRemote();
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
