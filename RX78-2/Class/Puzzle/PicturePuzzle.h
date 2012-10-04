#pragma once

#include "PuzzleBitmap.h"
#include "PuzzleDrag.h"

namespace RX78_2
{
	namespace Puzzle
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Windows::Forms;

		/**
		 * �s�N�`���[�p�Y��
		 */
		ref class PicturePuzzle
		{
		/**
		 * �t�B�[���h
		 */
		private:
			PuzzleBitmap^ bitmap;
			PuzzleDrag^ drag;

			array<Control^>^ correctArray;		///< �����ꏊ
			array<Control^>^ realArray;			///< ���ۂ̏ꏊ
			Point emptyPoint;					///< �󔒏ꏊ

		/**
		 * �R���X�g���N�^
		 */
		public:
			PicturePuzzle();

		/**
		 * ���\�b�h
		 */
		private:
			Point IndexToPoint(int index);
			int PointToIndex(Point point);

		public:
			/// �p�Y���R���g���[���ݒ�
			void SetPuzzleControl(array<Control^, 2>^ puzzle);
			/// �p�Y���V���b�t��
			void Shuffle();
			/// �p�Y�����ړ��\�ӏ��ֈړ�
			bool MovePuzzle(Control^ puzzle);
			/// �������ǂ�������
			bool IsCorrect(Control^ puzzle);
			/// �����|�C���g�擾
			Point GetCorrectPoint(Control^ puzzle);
			/// �p�Y���̏ꏊ�擾
			Point GetRialPoint(Control^ puzzle);
			/// �ړ��\�����擾
			PuzzleDrag::Direction GetDirectionCanMove(Control^ puzzle);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �r�b�g�}�b�v
			property PuzzleBitmap^ Bitmap
			{
				PuzzleBitmap^ get() { return this->bitmap; }
			}
			/// �h���b�O����
			property PuzzleDrag^ Drag
			{
				PuzzleDrag^ get() { return this->drag; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
