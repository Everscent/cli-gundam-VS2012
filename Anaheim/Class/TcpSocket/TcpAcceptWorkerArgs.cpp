#include "StdAfx.h"
#include "TcpAcceptWorkerArgs.h"

using namespace Anaheim;
using namespace Anaheim::TcpSocket;

/**
 * �ڑ����󂯓n���p�����[�^
 */
TcpAcceptWorkerArgs::TcpAcceptWorkerArgs(Anaheim::TcpSocket::TcpEventArgs ^tcpArgs, System::Net::Sockets::TcpClient ^client)
{
	this->tcpArgs = tcpArgs;
	this->client = client;
}
// ----------------------------------------------------------------------------------------------------