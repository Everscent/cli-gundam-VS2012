#include "StdAfx.h"
#include "IniFile.h"
#include <windows.h>
#include <vcclr.h>

using namespace Anaheim;

IniFile::IniFile(System::String ^fileName)
{
	this->fileName = fileName;
}
// ----------------------------------------------------------------------------------------------------

String^ IniFile::GetString(System::String ^section, System::String ^key, System::String ^defValue)
{
	if (!System::IO::File::Exists(this->fileName))
	{
		return defValue;
	}

	LPCTSTR lpAppName;				// �Z�N�V������
	LPCTSTR lpKeyName;				// �L�[��
	LPCTSTR lpDefault;				// �L�[����������Ȃ��ꍇ�̃f�t�H���g�̕�����
	LPTSTR  lpReturnedString;		// (�߂�l)��������󂯎��o�b�t�@
	DWORD   nSize;					// (�߂�l)��������󂯎��T�C�Y
	LPCTSTR lpFileName;				// INI�t�@�C����

	const int buffSize = 1024;

	// System::String^ �� wchar_t*
	pin_ptr<const wchar_t> wBuff = ::PtrToStringChars(section);
	lpAppName = wBuff;

	wBuff = ::PtrToStringChars(key);
	lpKeyName = wBuff;

	wBuff = ::PtrToStringChars(defValue);
	lpDefault = wBuff;

	lpReturnedString = new wchar_t[buffSize + 1];
	memset(lpReturnedString, 0, sizeof(lpReturnedString));

	nSize = sizeof(wchar_t) * buffSize;

	wBuff = ::PtrToStringChars(this->fileName);
	lpFileName = wBuff;

	DWORD returnSize = ::GetPrivateProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName);

	String^ result = String::Empty;
	if (0 < returnSize)
	{
		//�@wchar_t* �� System::String^
		result = gcnew String(lpReturnedString);
	}

	delete [] lpReturnedString;

	return result;
}
// ----------------------------------------------------------------------------------------------------

bool IniFile::SetString(System::String ^section, System::String ^key, System::String ^value)
{
	bool result = false;

	LPCTSTR lpAppName;		// �Z�N�V������
	LPCTSTR lpKeyName;		// �L�[��
	LPCTSTR lpString;		// �L�[�̒l�ɂȂ镶����
	LPCTSTR lpFileName;		// INI�t�@�C����

	pin_ptr<const wchar_t> wBuff = ::PtrToStringChars(section);
	lpAppName = wBuff;

	wBuff = ::PtrToStringChars(key);
	lpKeyName = wBuff;

	wBuff = ::PtrToStringChars(value);
	lpString = wBuff;

	wBuff = ::PtrToStringChars(this->fileName);
	lpFileName = wBuff;

	BOOL answer = ::WritePrivateProfileString(lpAppName, lpKeyName, lpString, lpFileName);

	if (answer == 0)
	{
		return false;
	}

	return true;
}
// ----------------------------------------------------------------------------------------------------

bool IniFile::GetBoolean(System::String ^section, System::String ^key, bool defValue)
{
	String^ value = this->GetString(section, key, defValue.ToString());
	return bool::Parse(value);
}
// ----------------------------------------------------------------------------------------------------

bool IniFile::SetBoolean(System::String ^section, System::String ^key, bool value)
{
	return this->SetString(section, key, value.ToString());
}
// ----------------------------------------------------------------------------------------------------

int IniFile::GetInteger(System::String ^section, System::String ^key, int defValue)
{
	String^ value = this->GetString(section, key, defValue.ToString());
	return int::Parse(value);
}
// ----------------------------------------------------------------------------------------------------

bool IniFile::SetInteger(System::String ^section, System::String ^key, int value)
{
	return this->SetString(section, key, value.ToString());
}
// ----------------------------------------------------------------------------------------------------
