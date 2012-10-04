#pragma once

#include "ReportBook.h"
#include "ReportCommand.h"
#include "ReportEventArgs.h"

namespace RX78_2
{
	namespace Report
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Collections::Generic;

		/**
		 * ���|�[�g�ҏW�N���X
		 */
		ref class ReportEditor
		{
		/**
		 * �t�B�[���h
		 */
		private:
			ReportBook^ report;
			List<ReportCommand^>^ commands;
			int currentIndex;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportEditor(ReportBook^ report);

		/**
		 * ���\�b�h
		 */
		private:
			bool AddCommand(ReportCommand^ command);

		public:
			/// �ҏW
			bool Edit(String^ section, Point point, String^ value);
			/// �}���C�ǉ�
			bool Insert(String^ section, Point point, String^ value);
			/// �폜
			bool Remove(String^ section, Point point);
			/// �s�}���C�ǉ�
			bool InsertStep(String^ section, int index, ReportItem^ item);
			/// �s�폜
			bool RemoveStep(String^ section, int index);
			/// Undo�ł��邩����
			bool CanUndo();
			/// Redo�ł��邩����
			bool CanRedo();
			/// Undo
			bool Undo();
			/// Redo
			bool Redo();
			/// �N���A
			void Clear();

		/**
		 * �C�x���g
		 */
		private:
			void OnEndAction(ReportEventArgs^ e);

		public:
			/// �A�N�V�����㔭�M�C�x���g
			event ReportEventHandler^ EndAction;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
