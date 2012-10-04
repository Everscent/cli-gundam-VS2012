#pragma once

#include "Insect.h"
#include "ArrowDrawing.h"

namespace RX78_2
{
	namespace Arrow
	{
		using namespace System;
		using namespace System::Windows::Forms;

		/**
		 * Arrow��
		 */
		ref class ArrowInsectCage
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Control^ canvas;
			Random^ random;
			array<Insect^>^ insects;
			ArrowDrawing^ drawing;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ArrowInsectCage(Control^ canvas, int count);

		/**
		 * ���\�b�h
		 */
		private:
			Insect^ CreateInsect();

		public:
			/// �ړ�
			void Move();
			/// �`��
			void Draw();
			/// �ʒu�C�p�x���Z�b�g
			void Reset();
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
