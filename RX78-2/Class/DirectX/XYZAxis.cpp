#include "StdAfx.h"
#include "XYZAxis.h"

using namespace RX78_2::DirectX;

/**
 * XYZ��
 */
XYZAxis::XYZAxis(Microsoft::DirectX::Direct3D::Device ^device, float length)
{
	this->vertex = gcnew VertexBuffer(
		CustomVertex::PositionColored::typeid, 6, device, Usage::None, CustomVertex::PositionColored::Format, Pool::Managed);

	array<CustomVertex::PositionColored>^ vertices = gcnew array<CustomVertex::PositionColored>(6);
	vertices[0] = CustomVertex::PositionColored(0.0f, 0.f, 0.0f, Color::Red.ToArgb());
	vertices[1] = CustomVertex::PositionColored(length, 0.0f, 0.0f, Color::Red.ToArgb());
	vertices[2] = CustomVertex::PositionColored(0.0f, 0.0f, 0.0f, Color::Green.ToArgb());
	vertices[3] = CustomVertex::PositionColored(0.0f, length, 0.0f, Color::Green.ToArgb());
	vertices[4] = CustomVertex::PositionColored(0.0f, 0.0f, 0.0f, Color::Blue.ToArgb());
	vertices[5] = CustomVertex::PositionColored(0.0f, 0.0f, length, Color::Blue.ToArgb());

	GraphicsStream^ stream = this->vertex->Lock(0, 0, LockFlags::None);
	stream->Write(vertices);
	this->vertex->Unlock();
	delete stream;
}
// ----------------------------------------------------------------------------------------------------

void XYZAxis::Draw(Microsoft::DirectX::Direct3D::Device ^device, RX78_2::DirectX::LightingConfig ^lightingConfig)
{
	if (!this->enabled) return;

	device->RenderState->Lighting = false;

	device->SetTransform(TransformType::World, Matrix::Identity);
	device->SetStreamSource(0, this->vertex, 0);
	device->VertexFormat = CustomVertex::PositionColored::Format;
	device->DrawPrimitives(PrimitiveType::LineList, 0, 3);

	device->RenderState->Lighting = true;
}
// ----------------------------------------------------------------------------------------------------

void XYZAxis::DrawShadow(Microsoft::DirectX::Direct3D::Device ^device, RX78_2::DirectX::LightingConfig ^lightingConfig, Microsoft::DirectX::Plane plane)
{
	// �e�Ȃ�
}
// ----------------------------------------------------------------------------------------------------
