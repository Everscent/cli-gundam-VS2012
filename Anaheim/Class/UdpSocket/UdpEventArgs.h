#pragma once

namespace Anaheim
{
	namespace UdpSocket
	{
		using namespace System;
		using namespace System::Net;
		using namespace System::Net::Sockets;
		using namespace System::Text;

		/**
		 * UDP�C�x���gArgs
		 */
		public ref class UdpEventArgs : public EventArgs
		{
		/**
		 * �t�B�[���h
		 */
		private:
			IPEndPoint^ remoteEndPoint;
			array<Byte>^ bytes;
			String^ message;

		/**
		 * �R���X�g���N�^
		 */
		public:
			UdpEventArgs(IPEndPoint^ remoteEndPoint, array<Byte>^ bytes, Encoding^ encoding);

		/**
		 * �v���p�e�B
		 */
		public:
			/// �����[�gIP/�|�[�g
			property IPEndPoint^ RemoteEndPoint
			{
				IPEndPoint^ get() { return this->remoteEndPoint; }
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
		 * UDP�C�x���g �f���Q�[�g
		 */
		public delegate void UdpEventHandler(Object^ sender, UdpEventArgs^ e);
		// ----------------------------------------------------------------------------------------------------
	}
}
