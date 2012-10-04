#pragma once

#include "TcpEventArgs.h"

namespace Anaheim
{
	namespace TcpSocket
	{
		using namespace System;
		using namespace System::Net;
		using namespace System::Net::Sockets;

		/**
		 * �ڑ����󂯓n���p�����[�^
		 */
		private ref class TcpAcceptWorkerArgs
		{
		/**
		 * �t�B�[���h
		 */
		private:
			TcpEventArgs^ tcpArgs;
			TcpClient^ client;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TcpAcceptWorkerArgs(TcpEventArgs^ tcpArgs, TcpClient^ client);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �C�x���g�p�p�����[�^
			property TcpEventArgs^ TcpArgs
			{
				TcpEventArgs^ get() { return this->tcpArgs; }
			}
			/// TCP�N���C�A���g
			property TcpClient^ Client
			{
				TcpClient^ get() { return this->client; }
			}
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
