#pragma once

namespace RX78_2
{
	namespace Arrow
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Windows::Forms;

		/**
		 * ���N���X
		 */
		ref class Insect
		{
		/**
		 * �t�B�[���h
		 */
		protected:
			literal int WIDTH = 30;
			literal int HEIGHT = 45;
			literal int LEG_LENGTH = 10;
			literal int LEG_COUNT = 4;
			literal int MOVE_COUNT_MAX = 10;

			PointF location;				///< �ʒu
			array<PointF>^ legLocations;	///< �����W	
			double degree;					///< ��]�p�x�idegree�j

			int moveCount;					///< ���[�u�J�E���g
			PointF moveLocation;			///< �ړ���
			int movingLegNo;				///< ��������No.
			PointF moveLegLocatin;			///< ���ړ���
			double moveDegree;				///< ��]��

			Point targetPoint;				///< �ړ���ʒu�i�}�E�X���W�j

			int speed;						///< �ړ��X�s�[�h��炬
			int skipMoveCount;				///< �ړ��X�L�b�v��

			Control^ canvas;				///< �L�����o�X
			Random^ random;					///< ����

		/**
		 * �R���X�g���N�^
		 */
		public:
			Insect(Control^ canvas, Random^ random);

		/**
		 * ���\�b�h
		 */
		protected:
			PointF GetLegPoint(int index);
			PointF GetLegDefaultPoint(int index);
			PointF GetLegPointCore(int index, Point jitter);
			void ChangeMoveCondition();
			void MoveCore();
			virtual void CalcSpeed();
			virtual System::Drawing::Color GetColor();

		public:
			/// �ړ�
			void Move();
			/// �ʒu�C�p�x���Z�b�g
			void Reset();
			/// �{�f�B�[�ʒu�擾
			array<PointF>^ GetBodyPoints();
			/// ���ʒu�擾
			array<PointF>^ GetLegPoints();
			/// Arrow�ʒu�擾
			array<PointF>^ GetArrowPoints();

		/**
		 * �v���p�e�B
		 */
		public:
			/// �`��F
			property System::Drawing::Color Color
			{
				System::Drawing::Color get() { return this->GetColor(); } 
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * �V���A
		 */
		ref class CharInsect : public Insect
		{
		/**
		 * �R���X�g���N�^
		 */
		public:
			CharInsect(Control^ canvas, Random^ random);

		/**
		 * ���\�b�h
		 */
		protected:
			virtual void CalcSpeed() override;
			virtual System::Drawing::Color GetColor() override;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
