#pragma once

#include "UdpEventArgs.h"

namespace Anaheim
{
	namespace UdpSocket
	{
		using namespace System;
		using namespace System::Net;
		using namespace System::Net::Sockets;
		using namespace System::ComponentModel;
		using namespace System::Text;

		/**
		 * UDP�N���C�A���g
		 */
		public ref class UdpClientSocket
		{
		/**
		 * �t�B�[���h
		 */
		private:
			UdpClient^ client;
			BackgroundWorker^ receiveWorker;
			Encoding^ encoding;
			bool connected;

		/**
		 * �R���X�g���N�^
		 */
		public:
			UdpClientSocket();

		/**
		 * ���\�b�h
		 */
		private:
			void ReceiveWorkerDoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
			void ReceiveWorkerProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e);

		public:
			/// �X�^�[�g
			bool Start(IPEndPoint^ endPoint);
			/// �X�g�b�v
			bool Stop();
			/// �f�[�^���M
			bool SendData(array<Byte>^ bytes, IPEndPoint^ endPoint);
			/// ���b�Z�[�W���M
			bool SendMessage(String^ message, IPEndPoint^ endPoint);

		/**
		 * �v���p�e�B
		 */
		public:
			/// ���[�J��IP/�|�[�g
			property IPEndPoint^ LocalEndPoint
			{
				IPEndPoint^ get() { return (this->connected) ? dynamic_cast<IPEndPoint^>(this->client->Client->LocalEndPoint) : nullptr; }
			}
			/// �ڑ����
			property bool Connected
			{
				bool get() { return this->connected; }
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
			virtual void OnReceived(UdpEventArgs^ e);

		public:
			/// ��M�C�x���g
			event UdpEventHandler^ Received;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
