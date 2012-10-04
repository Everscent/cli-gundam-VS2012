#pragma once

namespace RX78_2
{
	namespace DirectX
	{
		using namespace System;
		using namespace System::Windows::Forms;
		using namespace System::Drawing;
		using namespace System::ComponentModel;
		using namespace System::Collections::Generic;
		using namespace Microsoft::DirectX;
		using namespace Microsoft::DirectX::Direct3D;

		ref class Lighting;
		ref class Camera;
		ref class Floor;
		ref class RandomMovingCube;
		ref class Deruderu;
		ref class DrawingText;
		ref class XYZAxis;
		interface class IMovable;
		interface class IDrawable;

		/**
		 * �`�搢�E
		 */
		ref class DrawingWorld
		{
		/**
		 * �t�B�[���h
		 */
		private:
			Control^ canvas;
			Device^ device;
			BackgroundWorker^ backWorker;

			Lighting^ lighting;
			Camera^ camera;
			Floor^ floor;
			Deruderu^ deruderu;
			DrawingText^ text;
			XYZAxis^ xyzAxis;

			List<IMovable^>^ movingItems;
			List<IDrawable^>^ drawingItems;

		/**
		 * �R���X�g���N�^
		 */
		public:
			DrawingWorld(Control^ canvas, Control^ keyOwner, Control^ mouseOwner);

		/**
		 * ���\�b�h
		 */
		private:
			bool CreateInstance();
			void DoLoopProcess();
			void Move();
			void Draw();
			void ControlKeyDown(Object^ sender, KeyEventArgs^ e);
			void ControlKeyUp(Object^ sender, KeyEventArgs^ e);
			void ControlMouseMove(Object^ sender, MouseEventArgs^ e);
			void ControlMouseWheel(Object^ sender, MouseEventArgs^ e);
			void BackWorkerDoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
			void SetXYZAxisEnabled(bool enabled);

		public:
			/// ������
			bool Initialize();
			/// �J��
			void Release();
			/// �X�^�[�g
			bool Start();
			/// �X�g�b�v
			bool Stop();

		/**
		 * �v���p�e�B
		 */
		public:
			/// XYZ���L��/����
			property bool XYZAxisEnabled
			{
				void set(bool value) { this->SetXYZAxisEnabled(value); }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
