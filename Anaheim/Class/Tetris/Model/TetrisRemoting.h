#pragma once

#include "TetrisRemoteEventArgs.h"
#include "UdpEventArgs.h"

namespace Anaheim
{
	namespace UdpSocket
	{
		ref class UdpClientSocket;
	}

	namespace Tetris
	{
		namespace Model
		{
			using namespace System;
			using namespace System::Net;
			using namespace Model;
			using namespace Anaheim::UdpSocket;

			ref class TetrisField;
			ref class TetrisMino;
			
			/**
			 * �e�g���X�����[�g����
			 */
			ref class TetrisRemoting
			{
			/**
			 * �t�B�[���h
			 */
			private:
				UdpClientSocket^ udpSocket;
				bool isRunning;

			/**
			 * �R���X�g���N�^
			 */
			public:
				TetrisRemoting();

			/**
			 * ���\�b�h
			 */
			private:
				void UdpClientSocketReceived(System::Object^ sender, UdpEventArgs^ e);
				TetrisMino^ CreateMino(array<Byte>^ bytes, TetrisField^ field);

			public:
				/// �X�^�[�g
				bool Start(IPEndPoint^ endPoint);
				/// �X�g�b�v
				bool Stop();
				/// �f�[�^���M
				bool Send(TetrisField^ field, TetrisMino^ mino, IPEndPoint^ endPoint);

			/**
			 * �C�x���g
			 */
			protected:
				virtual void OnReceived(TetrisRemoteEventArgs^ e);

			public:
				/// ��M�C�x���g
				event TetrisRemoteEventHandler^ Received;
			};
			// ----------------------------------------------------------------------------------------------------
		}
	}
}
