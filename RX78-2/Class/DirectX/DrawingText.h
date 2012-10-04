#pragma once

#include "IDrawable.h"

namespace RX78_2
{
	namespace DirectX
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		/**
		 * �`��e�L�X�g
		 */
		ref class DrawingText
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Microsoft::DirectX::Direct3D::Font^ font;

		/**
		 * �R���X�g���N�^
		 */
		public:
			DrawingText(Device^ device, int height, String^ fontName);

		/**
		 * ���\�b�h
		 */
		public:
			/// ��������
			void Write(String^ string, int lineIndex, Color color);
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
