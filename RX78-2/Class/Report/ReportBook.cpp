#include "StdAfx.h"
#include "ReportBook.h"

using namespace RX78_2;
using namespace RX78_2::Report;

/**
 * ���|�[�g�A�C�e��
 */
ReportItem::ReportItem()
{
	this->strings = gcnew List<String^>;
}
// ----------------------------------------------------------------------------------------------------

ReportItem::ReportItem(int count)
{
	this->strings = gcnew List<String^>(count);
	for (int i = 0; i < count; i++)
	{
		this->strings->Add(String::Empty);
	}
}
// ----------------------------------------------------------------------------------------------------

ReportItem::ReportItem(System::Collections::Generic::List<String^> ^strigs)
{
	this->strings = strigs;
}
// ----------------------------------------------------------------------------------------------------

ReportItem::ReportItem(System::Xml::XmlElement ^xmlElement)
{
	this->strings = gcnew List<String^>;
	for each (XmlElement^ ele in xmlElement->ChildNodes)
	{
		if (ele->HasChildNodes)
		{
			this->strings->Add(ele->FirstChild->Value);
		}
		else
		{
			this->strings->Add(String::Empty);
		}
	}
}
// ----------------------------------------------------------------------------------------------------

String^ ReportItem::GetValue(int index)
{
	if (this->strings->Count <= index) return String::Empty;

	return this->strings[index];
}
// ----------------------------------------------------------------------------------------------------

bool ReportItem::SetValue(int index, System::String ^value)
{
	if (this->strings->Count <= index) return false;

	this->strings[index] = value;
	return true;
}
// ----------------------------------------------------------------------------------------------------

void ReportItem::Add(System::String ^value)
{
	this->strings->Add(value);
}
// ----------------------------------------------------------------------------------------------------

bool ReportItem::RemoveAt(int index)
{
	if (this->strings->Count <= index) return false;

	this->strings->RemoveAt(index);
	return true;
}
// ----------------------------------------------------------------------------------------------------

bool ReportItem::Insert(int index, System::String ^value)
{
	if (index < this->strings->Count)
	{
		this->strings->Insert(index, value);
	}
	else if (index == this->strings->Count)
	{
		this->Add(value);
	}
	else
	{
		return false;
	}
	return true;
}
// ----------------------------------------------------------------------------------------------------

void ReportItem::Clear()
{
	this->strings->Clear();
}
// ----------------------------------------------------------------------------------------------------

String^ ReportItem::ToString()
{
	String^ result = String::Empty;

	bool isFirst = true;
	for each (String^ item in this->strings)
	{
		String^ str = "\"" + item->Replace("\"", "\"\"") + "\"";

		if (isFirst)
		{
			result += str;
			isFirst = false;
		}
		else
		{
			result += "," + str;
		}
	}

	return result;
}
// ----------------------------------------------------------------------------------------------------

array<String^>^ ReportItem::ToStringArray()
{
	return this->strings->ToArray();
}
// ----------------------------------------------------------------------------------------------------

array<XmlElement^>^ ReportItem::ToXmlElement(System::Xml::XmlDocument ^document)
{
	array<XmlElement^>^ result = gcnew array<XmlElement^>(this->strings->Count);

	int count = 0;
	for each (String^ item in this->strings)
	{
		XmlElement^ element = document->CreateElement("Col");
		element->SetAttribute("No.", count.ToString());
		element->AppendChild(document->CreateTextNode(item));
		result[count] = element;
		count++;
	}

	return result;
}
// ----------------------------------------------------------------------------------------------------

/**
 * ���|�[�g���X�g
 */
ReportList::ReportList(System::String ^section, System::Collections::Generic::List<ReportItem^> ^items)
{
	this->section = section;
	this->items = items;
}
// ----------------------------------------------------------------------------------------------------

ReportList::ReportList(System::Xml::XmlElement ^element)
{
	this->section = element->GetAttribute("Section");

	this->items = gcnew List<ReportItem^>;
	for each (XmlElement^ ele in element->ChildNodes)
	{
		this->items->Add(gcnew ReportItem(ele));
	}
}
// ----------------------------------------------------------------------------------------------------

int ReportList::GetMaxColCount()
{
	int result = 0;

	for each (ReportItem^ item in this->items)
	{
		result = Math::Max(item->Count, result);
	}

	return result;
}
// ----------------------------------------------------------------------------------------------------

void ReportList::Add(RX78_2::Report::ReportItem ^item)
{
	this->items->Add(item);
}
// ----------------------------------------------------------------------------------------------------

bool ReportList::Remove(RX78_2::Report::ReportItem ^item)
{
	return this->items->Remove(item);
}
// ----------------------------------------------------------------------------------------------------

bool ReportList::Insert(int index, RX78_2::Report::ReportItem ^item)
{
	if (index < this->items->Count)
	{
		this->items->Insert(index, item);
	}
	else if (index == this->items->Count)
	{
		this->Add(item);
	}
	else
	{
		return false;
	}
	return true;
}
// ----------------------------------------------------------------------------------------------------

void ReportList::Clear()
{
	this->items->Clear();
}
// ----------------------------------------------------------------------------------------------------

array<String^>^ ReportList::ToCommaStrings()
{
	array<String^>^ result = gcnew array<String^>(this->Items->Count + 1);

	// �Z�N�V����
	result[0] = "\"" + this->Section->Replace("\"", "\"\"") + "\"";
	
	// �f�[�^
	int count = 0;
	for each (ReportItem^ item in this->items)
	{
		result[count + 1] = item->ToString();
		count++;
	}

	return result;
}
// ----------------------------------------------------------------------------------------------------

XmlElement^ ReportList::ToXmlElement(System::Xml::XmlDocument ^document)
{
	XmlElement^ result = document->CreateElement("Report");
	result->SetAttribute("Section", this->Section);

	int count = 0;
	for each (ReportItem^ item in this->items)
	{
		XmlElement^ element = document->CreateElement("Row");
		element->SetAttribute("No.", count.ToString());

		array<XmlElement^>^ eles = item->ToXmlElement(document);
		for each (XmlElement^ e in eles)
		{
			element->AppendChild(e);
		}

		result->AppendChild(element);
		count++;
	}

	return result;
}
// ----------------------------------------------------------------------------------------------------

/**
 * ���|�[�g�u�b�N
 */
ReportBook::ReportBook()
{
	this->fileName = String::Empty;
	this->lists = gcnew List<ReportList^>;
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::IsSectionString(cli::array<System::String ^,1> ^strings)
{
	if (strings->Length == 1 && strings[0]->IndexOf(":") == 0)
	{
		return true;
	}
	return false;
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::LoadCsvFile(System::String ^fileName)
{
	if (!System::IO::File::Exists(fileName)) return false;

	this->Clear();

	try
	{
		// �p�[�T
		TextFieldParser^ parser = gcnew TextFieldParser(fileName, System::Text::Encoding::GetEncoding("Shift_JIS"));
		parser->TextFieldType = FieldType::Delimited;
		array<String^>^ separators = { "," };
		parser->SetDelimiters(separators);

		String^ section = nullptr;
		List<ReportItem^>^ items = gcnew List<ReportItem^>;
		while (!parser->EndOfData)
		{
			array<String^>^ strings = parser->ReadFields();

			if (this->IsSectionString(strings))
			{
				if (section == nullptr)	// �܂��Z�N�V������ǂ�łȂ�
				{
					if (items->Count == 0)		// �f�[�^���ǂ�łȂ�
					{
						section = strings[0];
					}
					else						// �t�@�C���̐擪�Ƀ��x�������̃f�[�^���������ꍇ�́C�_�~�[�Z�N�V�����œǂݍ���
					{
						this->lists->Add(gcnew ReportList(":NON_SECTION", items));

						section = strings[0];
						items = gcnew List<ReportItem^>;	// ���X�g���Ȃ���
					}
				}
				else					// �Z�N�V�����ǂݍ��ݍς�
				{
					ReportList^ reportList = this->Select(section);
					if (reportList == nullptr)	// �V�K�Z�N�V����
					{
						this->lists->Add(gcnew ReportList(section, items));
					}
					else						// ���ɓ������x�����������ꍇ�͒ǋL
					{
						reportList->Items->AddRange(items);
					}
					section = strings[0];
					items = gcnew List<ReportItem^>;		// ���X�g���Ȃ���
				}
			}
			else
			{
				List<String^>^ slist = gcnew List<String^>(strings);
				items->Add(gcnew ReportItem(slist));
			}
		}

		// �Ō�̃f�[�^�Q
		if (section == nullptr)	// �܂��Z�N�V������ǂ�łȂ�
		{
			if (items->Count != 0)		// �t�@�C���̐擪�Ƀ��x�������̃f�[�^���������ꍇ�́C�_�~�[�Z�N�V�����œǂݍ���
			{
				this->lists->Add(gcnew ReportList(":NON_SECTION", items));
			}
		}
		else					// �Z�N�V�����ǂݍ��ݍς�
		{
			ReportList^ reportList = this->Select(section);
			if (reportList == nullptr)	// �V�K�Z�N�V����
			{
				this->lists->Add(gcnew ReportList(section, items));
			}
			else						// ���ɓ������x�����������ꍇ�͒ǋL
			{
				reportList->Items->AddRange(items);
			}
		}

		parser->Close();
	}
	catch (Exception^)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::LoadXmlFile(System::String ^fileName)
{
	try
	{
		this->Clear();

		XmlDocument^ document = gcnew XmlDocument();
		document->Load(fileName);
		XmlElement^ element = document->DocumentElement;

		for each (XmlElement^ ele in element->ChildNodes)
		{
			this->lists->Add(gcnew ReportList(ele));
		}
	}
	catch (Exception^)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::SaveCsvFile(System::String ^fileName)
{
	try
	{
		StreamWriter^ writer = gcnew StreamWriter(fileName, false, System::Text::Encoding::GetEncoding("Shift_JIS"));

		for each (ReportList^ list in this->lists)
		{
			array<String^>^ strings = list->ToCommaStrings();
			for each (String^ st in strings)
			{
				writer->WriteLine(st);
			}
			writer->WriteLine(String::Empty);
		}

		writer->Close();	// �N���[�Y
	}
	catch (Exception^)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::SaveXmlFile(System::String ^fileName)
{
	try
	{
		XmlDocument^ document = gcnew XmlDocument();
		document->AppendChild(document->CreateXmlDeclaration("1.0", "UTF-8", nullptr));
		XmlElement^ root = document->CreateElement("RX78-2");
		document->AppendChild(root);

		for each (ReportList^ list in this->lists)
		{
			root->AppendChild(list->ToXmlElement(document));
		}

		document->Save(fileName);
	}
	catch (Exception^)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::LoadFile(System::String ^fileName)
{
	if (!System::IO::File::Exists(fileName)) return false;

	String^ extension = System::IO::Path::GetExtension(fileName)->ToLower();
	if (String::Compare(extension, ".csv", true) == 0)
	{
		this->fileName = fileName;
		return this->LoadCsvFile(fileName);
	}
	else if (String::Compare(extension, ".xml", true) == 0)
	{
		this->fileName = fileName;
		return this->LoadXmlFile(fileName);
	}

	return false;
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::SaveFile()
{
	return this->SaveFile(this->fileName);
}
// ----------------------------------------------------------------------------------------------------

bool ReportBook::SaveFile(System::String ^fileName)
{
	String^ extension = System::IO::Path::GetExtension(fileName);
	if (String::Compare(extension, ".csv", true) == 0)
	{
		this->fileName = fileName;
		return this->SaveCsvFile(fileName);
	}
	else if (String::Compare(extension, ".xml", true) == 0)
	{
		this->fileName = fileName;
		return this->SaveXmlFile(fileName);
	}

	return false;
}
// ----------------------------------------------------------------------------------------------------

void ReportBook::Clear()
{
	this->lists->Clear();
}
// ----------------------------------------------------------------------------------------------------

ReportList^ ReportBook::Select(System::String ^section)
{
	for each (ReportList^ list in this->lists)
	{
		if (list->Section->Equals(section))
		{
			return list;
		}
	}
	return nullptr;
}
// ----------------------------------------------------------------------------------------------------
