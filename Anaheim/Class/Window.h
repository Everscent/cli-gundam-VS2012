#pragma once

namespace Anaheim
{
	using namespace System;
	using namespace System::Diagnostics;
	using namespace System::Windows::Forms;

	/**
	 * �E�B���h�E����
	 */
	public ref class Window abstract sealed
	{
	/**
	 * ���\�b�h
	 */
	private:
		static Process^ GetPreviousProcess();				///< �N���ς݃v���Z�X�擾
		static void ForegroundWindow(Process^ process);		///< �E�B���h�E�O�ʕ\��

	public:
		/// �N���ς݃E�B���h�E���őO�ʕ\��
		static void WakeupHasStartedWindow();
	};
	// ----------------------------------------------------------------------------------------------------
}
