#pragma once

namespace Anaheim
{
	using namespace System;
	using namespace System::IO;
	using namespace System::Threading;

	/**
	 * ���y�v���C���[
	 */
	public ref class WavPlayer
	{
	/**
	 * �t�B�[���h
	 */
	private:
		array<Byte>^ waveBuffer;
		System::Runtime::InteropServices::GCHandle gcHandle;

	/**
	 * �R���X�g���N�^
	 */
	public:
		WavPlayer();

	/**
	 * ���\�b�h
	 */
	private:
		static void DoWork(Object^ data);

	public:
		/// �Đ�
		bool Play(Stream^ stream);
		/// �Đ��i���[�v�j
		bool PlayLoop(Stream^ stream);
		/// ��~
		bool Stop();
		/// �Đ��i�ȈՔŁj
		static void PlaySimple(Stream^ stream);
	};
	// ----------------------------------------------------------------------------------------------------
}
