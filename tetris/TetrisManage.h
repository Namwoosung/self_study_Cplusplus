#pragma once

#include "Block.h"
#include "BoardManage.h"

struct TetrisManager
{
	BoardManager BoardManager;
	Block block;
};

void TetrisManager_StartGame();
void TetrisManager_StartTetris(TetrisManager* TetrisManager);
void TetrisManager_ProcessTetris(TetrisManager* TetrisManager);
