#pragma once

namespace RX78_2
{
	namespace Report
	{
		using namespace System;
		using namespace System::IO;
		using namespace System::Collections::Generic;
		using namespace System::Xml;
		using namespace Microsoft::VisualBasic::FileIO;

		/**
		 * ���|�[�g�A�C�e��
		 */
		ref class ReportItem
		{
		/**
		 * �t�B�[���h
		 */
		private:
			List<String^>^ strings;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportItem();
			ReportItem(int count);
			ReportItem(List<String^>^ strigs);
			ReportItem(XmlElement^ xmlElement);

		/**
		 * ���\�b�h
		 */
		public:
			/// �ǂݍ���
			String^ GetValue(int index);
			/// ��������
			bool SetValue(int index, String^ value);
			/// �ǉ�
			void Add(String^ value);
			/// �폜
			bool RemoveAt(int index);
			/// �}��
			bool Insert(int index, String^ value);
			/// �N���A
			void Clear();
			/// �J���}��؂�̕�����擾
			virtual String^ ToString() override;
			/// �������array
			array<String^>^ ToStringArray();
			/// XmlElement��array
			array<XmlElement^>^ ToXmlElement(XmlDocument ^document);

		/**
		 * �v���p�e�B
		 */
		public:
			/// ������
			property int Count
			{
				int get() { return this->strings->Count; }
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * ���|�[�g���X�g
		 */
		ref class ReportList
		{
		/**
		 * �t�B�[���h
		 */
		private:
			String^ section;
			List<ReportItem^>^ items;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportList(String^ section, List<ReportItem^>^ items);
			ReportList(XmlElement^ element);

		/**
		 * ���\�b�h
		 */
		private:
			int GetMaxColCount();

		public:
			/// �ǉ�
			void Add(ReportItem^ item);
			/// �폜
			bool Remove(ReportItem^ item);
			/// �}��
			bool Insert(int index, ReportItem^ item);
			/// �N���A
			void Clear();
			/// �J���}��؂蕶����擾
			array<String^>^ ToCommaStrings();
			/// XmlElement�擾
			XmlElement^ ToXmlElement(XmlDocument ^document);
			
		/**
		 * �v���p�e�B
		 */
		public:
			/// �Z�N�V����
			property String^ Section
			{
				String^ get() { return this->section; }
			}
			/// ReportItem���X�g
			property List<ReportItem^>^ Items
			{
				List<ReportItem^>^ get() { return this->items; }
			}
			/// �ő��
			property int MaxColCount
			{
				int get() { return this->GetMaxColCount(); }
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * ���|�[�g�u�b�N
		 */
		ref class ReportBook
		{
		/**
		 * �t�B�[���h
		 */
		private:
			String^ fileName;
			List<ReportList^>^ lists;

		/**
		 * �R���X�g���N�^
		 */
		public:
			ReportBook();

		/**
		 * ���\�b�h
		 */
		private:
			bool IsSectionString(array<String^>^ strings);
			bool LoadCsvFile(String^ fileName);
			bool LoadXmlFile(String^ fileName);
			bool SaveCsvFile(String^ fileName);
			bool SaveXmlFile(String^ fileName);

		public:
			/// �t�@�C���ǂݍ���
			bool LoadFile(String^ fileName);
			/// �t�@�C���ۑ�
			bool SaveFile();
			/// �t�@�C���ۑ��i�V�K�t�@�C���j
			bool SaveFile(String^ fileName);
			/// �N���A
			void Clear();
			/// ���|�[�g���X�g�擾�i�Z�N�V�����w��j
			ReportList^ Select(String^ section);
			
		/**
		 * �v���p�e�B
		 */
		public:
			/// �S���|�[�g���X�g
			property List<ReportList^>^ Lists
			{
				List<ReportList^>^ get() { return this->lists; }
			}
			/// �t�@�C����
			property String^ FileName
			{
				String^ get() { return this->fileName; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
