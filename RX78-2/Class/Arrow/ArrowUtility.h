#pragma once

namespace RX78_2
{
	namespace Arrow
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Windows::Forms;

		/**
		 * Arrow���[�e�B���e�B
		 */
		ref class ArrowUtility abstract sealed
		{
		/**
		 * ���\�b�h
		 */
		public:
			/// �}�E�X�J�[�\���ʒu�擾�i�L�����o�X�̍��W�n�j
			static Point GetMousePoint(Control^ canvas);
			/// 0�`360���ɕϊ�
			static double ConvertDegree(double degree);
			/// �|�C���g�Ԃ̊p�x
			static double GetAngle(PointF point1, PointF point2);
			/// ���Ԋp�x�擾
			static double GetHalfAngle(double degree1, double degree2);
			/// ���W��]
			static PointF RotatePoint(PointF point, PointF center, double degree);
			/// ���W�ړ�
			static PointF MovePoint(PointF point, int distance, double degree);
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
