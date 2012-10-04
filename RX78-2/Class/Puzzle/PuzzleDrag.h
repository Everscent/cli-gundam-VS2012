#pragma once

namespace RX78_2
{
	namespace Puzzle
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Windows::Forms;

		/**
		 * �p�Y���h���b�O�N���X
		 */
		ref class PuzzleDrag
		{
		/**
		 * enum class
		 */
		public:
			enum class Direction
			{
				Up,
				Down,
				Left,
				Right,
				Non,
			};

		/**
		 * �t�B�[���h
		 */
		private:
			Control^ dragObject;
			Point clickPoint;
			Direction direction;

			Point startPoint;
			Point endPoint;

		/**
		 * �R���X�g���N�^
		 */
		public:
			PuzzleDrag();

		/**
		 * ���\�b�h
		 */
		private:
			void Clear();

		public:
			/// �h���b�O�J�n
			void Begin(Control^ dragObject, Point clickPoint, Direction direction);
			/// �h���b�O
			void Move(Point mousePoint);
			/// �h���b�O�I��
			bool End();
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
