#pragma once

#include "Insect.h"

namespace RX78_2
{
	namespace Arrow
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Windows::Forms;

		/**
		 * Arrow�`��
		 */
		ref class ArrowDrawing
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Control^ canvas;
			Bitmap^ bitmap;
			Graphics^ graphics;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ArrowDrawing(Control^ canvas);

		/**
		 * ���\�b�h
		 */
		public:
			/// �`��J�n
			void BeginDraw();
			/// �`��
			void Draw(Insect^ insect);
			/// �`��I��
			void EndDraw();
		};
		// ----------------------------------------------------------------------------------------------------
	}
}