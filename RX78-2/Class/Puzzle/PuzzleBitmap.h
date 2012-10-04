#pragma once

namespace RX78_2
{
	namespace Puzzle
	{
		using namespace System;
		using namespace System::Drawing;

		/**
		 * �p�Y���r�b�g�}�b�v
		 */
		ref class PuzzleBitmap
		{
		/**
		 * �t�B�[���h
		 */
		private:
			literal int CUT_COUNT_X = 5;
			literal int CUT_COUNT_Y = 5;

			Bitmap^ fileBmp;
			Bitmap^ reverseBmp;
			Bitmap^ resizeFileBmp;
			Bitmap^ resizeReverseBmp;
			Size size;

		/**
		 * �R���X�g���N�^
		 */
		public:
			PuzzleBitmap();

		/**
		 * ���\�b�h
		 */
		private:
			void CreateReverseBmp();

		public:
			/// �t�@�C���ǂݍ���
			bool LoadFile(String^ fileName);
			/// �T�C�Y�ύX
			void ChangeSize(Size size);
			/// �r�b�g�}�b�v�擾�i��/�\�j
			Bitmap^ GetBitmap(bool isReverse);
			/// �r�b�g�}�b�v�i���j�擾�i��/�\�j
			Bitmap^ GetSmallBitmap(Point point, bool isReverse);
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
