#pragma once

namespace Anaheim
{
	namespace TcpSocket
	{
		using namespace System;
		using namespace System::Net;
		using namespace System::Net::Sockets;
		using namespace System::Text;

		/**
		 * TCP�C�x���gArgs
		 */
		public ref class TcpEventArgs : public EventArgs
		{
		/**
		 * �t�B�[���h
		 */
		private:
			IPEndPoint^ remoteEndPoint;
			IPEndPoint^ localEndPoint;
			array<Byte>^ bytes;
			String^ message;

		/**
		 * �R���X�g���N�^
		 */
		public:
			TcpEventArgs(IPEndPoint^ remoteEndPoint, IPEndPoint^ localEndPoint, array<Byte>^ bytes, Encoding^ encoding);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �����[�gIP/�|�[�g
			property IPEndPoint^ RemoteEndPoint
			{
				IPEndPoint^ get() { return this->remoteEndPoint; }
			}
			/// ���[�J��IP/�|�[�g
			property IPEndPoint^ LocalEndPoint
			{
				IPEndPoint^ get() { return this->localEndPoint; }
			}
			/// ��M�f�[�^
			property array<Byte>^ Bytes
			{
				array<Byte>^ get() { return this->bytes; }
			}
			/// ��M���b�Z�[�W
			property String^ Message
			{
				String^ get() { return this->message; }
			}
		};
		// ----------------------------------------------------------------------------------------------------

		/**
		 * TCP�C�x���g �f���Q�[�g
		 */
		public delegate void TcpEventHandler(Object^ sender, TcpEventArgs^ e);
		// ----------------------------------------------------------------------------------------------------
	}
}
