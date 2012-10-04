#pragma once

#include "TcpEventArgs.h"

namespace Anaheim
{
	namespace TcpSocket
	{
		using namespace System;
		using namespace System::Net;
		using namespace System::Net::Sockets;
		using namespace System::Collections::Generic;
		using namespace System::ComponentModel;
		using namespace System::Text;

		/**
		 * TCP�N���C�A���g
		 */
		public ref class TcpClientSocket
		{
		/**
		 * �t�B�[���h
		 */
		private:
			TcpClient^ client;
			BackgroundWorker^ receiveWorker;
			Encoding^ encoding;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TcpClientSocket();
			TcpClientSocket(TcpClient^ client);

		/**
		 * ���\�b�h
		 */
		private:
			void ReceiveWorkerDoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
			void ReceiveWorkerProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e);

		public:
			/// �ڑ�
			bool Connect(IPEndPoint^ endPoint);
			/// �ؒf
			bool DisConnect();
			/// �f�[�^���M
			bool SendData(array<Byte>^ bytes);
			/// ���b�Z�[�W���M
			bool SendMessage(String^ message);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �����[�gIP/�|�[�g
			property IPEndPoint^ RemoteEndPoint
			{
				IPEndPoint^ get() { return dynamic_cast<IPEndPoint^>(this->client->Client->RemoteEndPoint); }
			}
			/// ���[�J��IP/�|�[�g
			property IPEndPoint^ LocalEndPoint
			{
				IPEndPoint^ get() { return dynamic_cast<IPEndPoint^>(this->client->Client->LocalEndPoint); }
			}
			/// �ڑ����
			property bool Connected
			{
				bool get() { return this->client->Connected; }
			}
			/// �G���R�[�h
			property System::Text::Encoding^ Encoding
			{
				System::Text::Encoding^ get() { return this->encoding; }
				void set(System::Text::Encoding^ value) { this->encoding = value; }
			}

		/**
		 * �C�x���g
		 */
		protected:
			virtual void OnReceived(TcpEventArgs^ e);
			virtual void OnDisConnected(TcpEventArgs^ e);

		public:
			/// ��M�C�x���g
			event TcpEventHandler^ Received;
			/// �ؒf�C�x���g
			event TcpEventHandler^ DisConnected;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
