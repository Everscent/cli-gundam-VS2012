#pragma once

namespace Anaheim
{
	ref class WavPlayerDX;

	namespace Tetris
	{
		namespace View
		{
			using namespace System;
			using namespace System::IO;
			using namespace System::Windows::Forms;

			/**
			 * �e�g���X���y
			 */
			ref class TetrisSound
			{
			/**
			 * �t�B�[���h
			 */
			private:
				bool isON;
				WavPlayerDX^ bgmPlayer;
				WavPlayerDX^ gameoverPlayer;
				WavPlayerDX^ removePlayer;
				WavPlayerDX^ enddownPlayer;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisSound(Control^ owner);

			/**
			 * ���\�b�h
			 */
			private:
				void SetSoundON(bool isON);

			public:
				/// BGM�Đ�
				bool PlayBGM();
				/// BGM�ꎞ��~
				void PauseBGM();
				/// BGM��~
				void StopBGM();
				/// �Q�[���I�[�o�[��
				bool PlayGameOverSound();
				/// �폜��
				bool PlayRemoveSound();
				/// ���ړ��I����
				bool PlayEndDownSound();

			/**
			 * �v���p�e�B
			 */
			public:
				property bool ON
				{
					void set(bool value) { this->SetSoundON(value); }
				}
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
