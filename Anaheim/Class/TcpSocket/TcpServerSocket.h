#pragma once

#include "TcpEventArgs.h"
#include "TcpClientSocket.h"

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
		 * TCP�T�[�o
		 */
		public ref class TcpServerSocket
		{
		/**
		 * �t�B�[���h
		 */
		private:
			TcpListener^ server;
			List<TcpClientSocket^>^ clients;
			bool started;
			BackgroundWorker^ acceptWorker;
			Encoding^ encoding;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TcpServerSocket();

		/**
		 * ���\�b�h
		 */
		private:
			void AcceptWorkerDoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
			void AcceptWorkerProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e);

			void ReceivedClient(System::Object^ sender, TcpEventArgs^ e);
			void DisConnectedClient(System::Object^ sender, TcpEventArgs^ e);

			bool IsEnabledEndPoint(IPEndPoint^ endPoint);
			void SetEncoding(System::Text::Encoding^ encoding);

		public:
			/// ������
			bool Initialize(IPEndPoint^ endPoint);
			/// �X�^�[�g
			bool Start();
			/// �X�g�b�v
			bool Stop();
			/// �ؒf
			bool DisConnect(IPEndPoint^ endPoint);
			/// ���b�Z�[�W���M
			bool SendMessage(String^ message, IPEndPoint^ endPoint);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �N���C�A���g���X�g
			property List<TcpClientSocket^>^ Clients
			{
				List<TcpClientSocket^>^ get() { return this->clients; }
			}
			/// �J�n���
			property bool Started
			{
				bool get() { return this->started; }
			}
			/// �G���R�[�_
			property System::Text::Encoding^ Encoding
			{
				System::Text::Encoding^ get() { return this->encoding; }
				void set(System::Text::Encoding^ value) { this->SetEncoding(value); }
			}

		/**
		 * �C�x���g
		 */
		protected:
			virtual void OnConnected(TcpEventArgs^ e);
			virtual void OnDisConnected(TcpEventArgs^ e);
			virtual void OnReceived(TcpEventArgs^ e);

		public:
			/// �ڑ��C�x���g
			event TcpEventHandler^ Connected;
			/// �ؒf�C�x���g
			event TcpEventHandler^ DisConnected;
			/// ��M�C�x���g
			event TcpEventHandler^ Received;
		};
		// ----------------------------------------------------------------------------------------------------
	}
}
