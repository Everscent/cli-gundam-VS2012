#include "StdAfx.h"
#include "TetrisScoreEventArgs.h"

using namespace Anaheim;
using namespace Anaheim::Tetris;

/**
 * �e�g���X�����[�g�C�x���gArgs
 */
TetrisScoreEventArgs::TetrisScoreEventArgs(Anaheim::Tetris::PublicTetrisScore ^score)
{
	this->score = score;
}
// ----------------------------------------------------------------------------------------------------
