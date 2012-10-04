// RX77-2.cpp : ���C�� �v���W�F�N�g �t�@�C���ł��B

#include "stdafx.h"
#include "MainForm.h"

using namespace RX77_2;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��d�N���`�F�b�N
	System::Threading::Mutex^ mutex = gcnew System::Threading::Mutex(true, "RX77-2");
	if (!mutex->WaitOne(0, false))
	{
		Anaheim::Window::WakeupHasStartedWindow();
		return 1;
	}

	// �R���g���[�����쐬�����O�ɁAWindows XP �r�W���A�����ʂ�L���ɂ��܂�
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���C�� �E�B���h�E���쐬���āA���s���܂�
	Application::Run(gcnew MainForm());

	// �~���[�e�b�N�X���
	mutex->ReleaseMutex();

	return 0;
}
