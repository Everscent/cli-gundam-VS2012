#include "StdAfx.h"
#include "TetrisRemoteEventArgs.h"

using namespace Anaheim;
using namespace Anaheim::Tetris;

/**
 * �e�g���X�����[�g�C�x���gArgs
 */
TetrisRemoteEventArgs::TetrisRemoteEventArgs(TetrisField ^field, TetrisMino ^mino)
{
	this->field = field;
	this->mino = mino;
}
// ----------------------------------------------------------------------------------------------------
