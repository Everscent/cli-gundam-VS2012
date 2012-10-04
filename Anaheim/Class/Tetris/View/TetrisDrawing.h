#pragma once

namespace Anaheim
{
	namespace Tetris
	{
		namespace Model
		{
			ref class TetrisField;
			ref class TetrisMino;
			ref class GhostTetrisMino;
		}

		namespace View
		{
			using namespace System;
			using namespace System::Drawing;
			using namespace System::Windows::Forms;
			using namespace System::Collections::Generic;
			using namespace Model;

			interface class ITetrisDrawAPI;

			/**
			 * �e�g���X�`��
			 */
			ref class TetrisDrawing abstract
			{
			/**
			 * �t�B�[���h
			 */
			protected:
				Control^ canvas;
				ITetrisDrawAPI^ api;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisDrawing(Control^ canvas, ITetrisDrawAPI^ api);

			/**
			 * ���\�b�h
			 */
			protected:
				/// �u���b�N�T�C�Y�擾
				virtual SizeF GetBlockSize() abstract;
				/// �`��
				virtual void DrawCore(TetrisMino^ mino) abstract;

				PointF GetBlockLocation(Point point, SizeF blockSize);
				void DrawBlock(PointF location, SizeF size, Color color);

			public:
				///�@�`��
				void Draw(TetrisMino^ mino);
				/// �N���A
				void Clear();
				/// �L�����o�X�R���g���[���̈�v����
				bool IsMyCanvas(Control^ canvas);
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * ���C���`��
			 */
			ref class MainTetrisDrawing : public TetrisDrawing
			{
			/**
			 * �t�B�[���h
			 */
			private:
				TetrisField^ field;

			/**
			 * �R���X�g���N�^
			 */
			public:
				MainTetrisDrawing(Control^ canvas, ITetrisDrawAPI^ api, TetrisField^ field);

			/**
			 * ���\�b�h
			 */
			private:
				void DrawRemoveBlock(PointF location, SizeF size);
				void DrawMino(TetrisMino^ mino);
				void DrawGhostMino(GhostTetrisMino^ mino);

			protected:
				/// �u���b�N�T�C�Y�擾
				virtual SizeF GetBlockSize() override;
				///�@�`��
				virtual void DrawCore(TetrisMino^ mino) override;

			/**
			 * �v���p�e�B
			 */
			public:
				/// �t�B�[���h
				property TetrisField^ Field
				{
					void set(TetrisField^ value) { this->field = value; }
				}
			};
			// ----------------------------------------------------------------------------------------------------

			/**
			 * �l�N�X�g�`��
			 */
			ref class NextTetrisDrawing : public TetrisDrawing
			{
			/**
			 * �R���X�g���N�^
			 */
			public:
				NextTetrisDrawing(Control^ canvas, ITetrisDrawAPI^ api);

			/**
			 * ���\�b�h
			 */
			protected:
				/// �u���b�N�T�C�Y�擾
				virtual SizeF GetBlockSize() override;
				///�@�`��
				virtual void DrawCore(TetrisMino^ mino) override;
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
