#pragma once

namespace RX78_2
{
	namespace DirectX
	{
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		ref class LightingConfig;

		/**
		 * �`��\
		 */
		interface class IDrawable
		{
		/**
		 * ���\�b�h
		 */
		public:
			/// �`��
			virtual void Draw(Device^ device, LightingConfig^ lightingConfig) abstract;
			/// �e�`��
			virtual void DrawShadow(Device^ device, LightingConfig^ lightingConfig, Plane plane) abstract;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
