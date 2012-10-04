#pragma once

#include "ReportBook.h"
#include "ReportEventArgs.h"

namespace RX78_2
{
	namespace Report
	{
		using namespace System;
		using namespace System::Drawing;

		/**
		 * ���|�[�g�ҏW�R�}���h�i���ۃN���X�j
		 */
		ref class ReportCommand abstract
		{
		/**
		 * �t�B�[���h
		 */
		protected:
			ReportList^ report;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportCommand(ReportList^ report);

		/**
		 * ���\�b�h
		 */
		public:
			/// ���s�iRedo�j
			virtual bool Execute() abstract;
			/// Undo
			virtual bool Undo() abstract;
			/// �C�x���g�p�p�����[�^�擾
			virtual ReportEventArgs^ GetEventArgs();

		/**
		 * �v���p�e�B
		 */
		public:
			/// �Z�N�V����
			property String^ Section
			{
				String^ get() { return this->report->Section; }
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * ���|�[�g�ҏW�R�}���h�i�ҏW�j
		 */
		ref class ReportEdit : public ReportCommand
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Point point;
			String^ oldValue;
			String^ newValue;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportEdit(ReportList^ report, Point point, String^ value);

		/**
		 * ���\�b�h
		 */
		public:
			/// ���s�iRedo�j
			virtual bool Execute() override;
			/// Undo
			virtual bool Undo() override;
			/// �C�x���g�p�p�����[�^�擾
			virtual ReportEventArgs^ GetEventArgs() override;
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * ���|�[�g�ҏW�R�}���h�i�}���j
		 */
		ref class ReportInsert : public ReportCommand
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Point point;
			String^ value;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportInsert(ReportList^ report, Point point, String^ value);

		/**
		 * ���\�b�h
		 */
		public:
			/// ���s�iRedo�j
			virtual bool Execute() override;
			/// Undo
			virtual bool Undo() override;
			/// �C�x���g�p�p�����[�^�擾
			virtual ReportEventArgs^ GetEventArgs() override;
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * ���|�[�g�ҏW�R�}���h�i�폜�j
		 */
		ref class ReportRemove : public ReportCommand
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Point point;
			String^ value;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportRemove(ReportList^ report, Point point);

		/**
		 * ���\�b�h
		 */
		public:
			/// ���s�iRedo�j
			virtual bool Execute() override;
			/// Undo
			virtual bool Undo() override;
			/// �C�x���g�p�p�����[�^�擾
			virtual ReportEventArgs^ GetEventArgs() override;
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * ���|�[�g�ҏW�R�}���h�i�X�e�b�v�}���j
		 */
		ref class ReportInsertStep : public ReportCommand
		{
		/**
		 * �t�B�[���h
		 */
		private:
			int index;
			ReportItem^ item;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportInsertStep(ReportList^ report, int index, ReportItem^ item);

		/**
		 * ���\�b�h
		 */
		public:
			/// ���s�iRedo�j
			virtual bool Execute() override;
			/// Undo
			virtual bool Undo() override;
			/// �C�x���g�p�p�����[�^�擾
			virtual ReportEventArgs^ GetEventArgs() override;
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * ���|�[�g�ҏW�R�}���h�i�X�e�b�v�폜�j
		 */
		ref class ReportRemoveStep : public ReportCommand
		{
		/**
		 * �t�B�[���h
		 */
		private:
			int index;
			ReportItem^ item;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportRemoveStep(ReportList^ report, int index);

		/**
		 * ���\�b�h
		 */
		public:
			/// ���s�iRedo�j
			virtual bool Execute() override;
			/// Undo
			virtual bool Undo() override;
			/// �C�x���g�p�p�����[�^�擾
			virtual ReportEventArgs^ GetEventArgs() override;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
