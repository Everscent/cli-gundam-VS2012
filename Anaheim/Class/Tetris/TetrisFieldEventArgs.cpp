#include "StdAfx.h"
#include "TetrisFieldEventArgs.h"

using namespace Anaheim;
using namespace Anaheim::Tetris;

/**
 * �e�g���X�t�B�[���h�C�x���gArgs
 */
TetrisFieldEventArgs::TetrisFieldEventArgs(Anaheim::Tetris::Model::TetrisField ^field)
{
	this->field = field;
}
// ----------------------------------------------------------------------------------------------------
