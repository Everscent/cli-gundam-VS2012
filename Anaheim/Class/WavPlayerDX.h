#pragma once

namespace Anaheim
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Windows::Forms;
	using namespace Microsoft::DirectX;
	using namespace Microsoft::DirectX::DirectSound;

	/**
	 * ���y�v���C���[�iDirectX�Łj
	 */
	public ref class WavPlayerDX
	{
	/**
	 * �t�B�[���h
	 */
	private:
		Device^ device;
		SecondaryBuffer^ buffer;

	/**
	 * �R���X�g���N�^
	 */
	public:
		WavPlayerDX(Control^ owner, Stream^ stream);

	/**
	 * ���\�b�h
	 */
	public:
		/// �Đ�
		void Play();
		/// �Đ��i���[�v�j
		void PlayLoop();
		/// �ꎞ��~
		void Pause();
		/// ��~
		void Stop();
	};
	// ----------------------------------------------------------------------------------------------------
}