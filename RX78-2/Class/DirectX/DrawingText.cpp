#include "StdAfx.h"
#include "DrawingText.h"

using namespace RX78_2::DirectX;

/**
 * �`��e�L�X�g
 */
DrawingText::DrawingText(Microsoft::DirectX::Direct3D::Device ^device, int height, System::String ^fontName)
{
	FontDescription description;
	description.Height = height;
	description.FaceName = fontName;
	this->font = gcnew Microsoft::DirectX::Direct3D::Font(device, description);
}
// ----------------------------------------------------------------------------------------------------

void DrawingText::Write(System::String ^string, int lineIndex, System::Drawing::Color color)
{
	this->font->DrawText(nullptr, string, 2, this->font->Description.Height * lineIndex, color);
}
// ----------------------------------------------------------------------------------------------------
