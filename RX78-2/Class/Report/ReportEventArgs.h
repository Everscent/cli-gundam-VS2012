#pragma once

#include "ReportBook.h"

namespace RX78_2
{
	namespace Report
	{
		using namespace System;
		using namespace System::Drawing;

		/**
		 * ���|�[�g�ҏW�C�x���g�p�����[�^
		 */
		ref class ReportEventArgs : public EventArgs
		{
		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportEventArgs();
		/**
		 * �v���p�e�B
		 */
		public:
			/// Undo or Redo
			property bool IsUndo;
			/// �ҏW�̂������Z�N�V������
			property String^ Section;
			/// �ҏW�R�}���h�t���O
			property bool IsEdit;
			/// �ҏW�|�C���g
			property Point Point;
			/// �ύX�O����
			property String^ OldValue;
			/// �ύX�㕶��
			property String^ NewValue;
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * �ҏW�C�x���g �f���Q�[�g
		 */
		delegate void ReportEventHandler(Object^ sender, ReportEventArgs^ e);
		// ----------------------------------------------------------------------------------------------------
	}
}
