#include "StdAfx.h"
#include "ReportEventArgs.h"

using namespace RX78_2;
using namespace RX78_2::Report;

/**
 * ���|�[�g�ҏW�C�x���g�p�����[�^
 */
ReportEventArgs::ReportEventArgs()
{
	this->IsUndo = true;
	this->Section = String::Empty;
	this->IsEdit = false;
	this->OldValue = nullptr;
	this->NewValue = nullptr;
}
// ----------------------------------------------------------------------------------------------------
