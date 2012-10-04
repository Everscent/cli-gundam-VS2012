#include "StdAfx.h"
#include "Window.h"
#include <windows.h>

using namespace Anaheim;

/**
 * �E�B���h�E����
 */
Process^ Window::GetPreviousProcess()
{
	Process^ myProcess = Process::GetCurrentProcess();
	array<Process^>^ processes = Process::GetProcessesByName(myProcess->ProcessName);

	for each (Process^ pro in processes)
	{
		if (pro->Id != myProcess->Id)	// �������g�ł͂Ȃ��v���Z�X���擾
		{
			return pro;
		}
	}

	return nullptr;
}
// ----------------------------------------------------------------------------------------------------

void Window::ForegroundWindow(Process ^process)
{
	HWND hWnd = (HWND)((void*)process->MainWindowHandle);
	if (hWnd == NULL)
	{
		System::Windows::Forms::MessageBox::Show("���łɋN�����Ă��܂��I", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		if (::IsIconic(hWnd) == TRUE)
		{
			::ShowWindowAsync(hWnd, SW_RESTORE);
		}
		::SetForegroundWindow(hWnd);
	}
}
// ----------------------------------------------------------------------------------------------------

void Window::WakeupHasStartedWindow()
{
	Process^ process = Window::GetPreviousProcess();
	if (process != nullptr)
	{
		Window::ForegroundWindow(process);		
	}
}
// ----------------------------------------------------------------------------------------------------
