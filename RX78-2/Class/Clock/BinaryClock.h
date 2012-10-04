#pragma once

namespace RX78_2
{
	namespace Clock
	{
		using namespace System;
		using namespace System::Drawing;
		using namespace System::Windows::Forms;

		/**
		 * �o�C�i���N���b�N
		 */
		ref class BinaryClock
		{
		/**
		 * �t�B�[���h
		 */
		private:
			array<Control^, 2>^ panelsSec;
			array<Control^, 2>^ panelsMin;
			array<Control^, 2>^ panelsHour;
			Color onColor;
			Color offColor;

			DateTime endTime;

		/**
		 * �R���X�g���N�^
		 */
		public:
			BinaryClock(array<Control^, 2>^ sec, array<Control^, 2>^ min, array<Control^, 2>^ hour);

		/**
		 * ���\�b�h
		 */
		public:
			/// �\��
			String^ Display();
			/// �^�C�}�[�c�莞�Ԏ擾
			TimeSpan GetTimerSpan();

		/**
		 * �v���p�e�B
		 */
		public:
			/// ON�J���[
			property Color OnColor
			{
				Color get() { return this->onColor; }
				void set(Color value) { this->onColor = value; }
			}
			/// OFF�J���[
			property Color OffColor
			{
				Color get() { return this->offColor; }
				void set(Color value) { this->offColor = value; }
			}
			/// �I������
			property DateTime EndTime
			{
				DateTime get() { return this->endTime; }
				void set(DateTime value) { this->endTime = value; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
