#pragma once

#include "Block.h"
#include "SetValue.h"

//테트리스 판을 관리하기 위해 필요한 변수들을 구조체로 선언
struct BoardManager
{
	int Board[Board_Height][Board_Length];
	int Board_Copy[Board_Height][Board_Length];
	int Level;
	int LeftBlock;
	int Score;
	int IsNeedBlcok;
	int Speed;
	int IsDoingGame;
};


void BoardManage_Init(BoardManager* BoardManager);
void BoardManage_SetBoard(BoardManager* BoardManager);

void BoardManage_DrawBaord(BoardManager* BoardManager);
void BoardManage_DrawMenu(BoardManager* BoardManager);
void BoardManage_DrawScoreAndLeftBlock(BoardManager BoardManager);
void BoardManage_DrawNextBlock(Block block);

void BoardManage_SetBlock(BoardManager* BoardManager, Block* block);

void BoardManage_MoveBlock(BoardManager* BoardManager, Block* blcok, int key);
void BoardManage_BlockMoveToDown(BoardManager* BoardManager, Block* block);
void BoardManage_BlockMoveToLeft(BoardManager* BoardManager, Block* block);
void BoardManage_BlockMoveToRight(BoardManager* BoardManager, Block* block);
void BoardManage_RotateBlock(BoardManager* BoardManager, Block* block);

int BoardManage_CheckCrush(BoardManager BoardManager, Block block);
int BoardManage_PreMoveToLeft(BoardManager BoardManager, Block block);
int BoardManage_PreMoveToRight(BoardManager BoardManager, Block block);
int BoardManage_PreMoveToDown(BoardManager BoardManager, Block block);
int BoardManage_PreRotateBlock(BoardManager BoardManager, Block block);

void BoardManage_CheckKey(BoardManager* BoardManager, Block* block);
void BoardManage_Pause(BoardManager BoardManager, Block block);
void BoardManage_ResetBoardCopy(BoardManager* BoardManager);

void BoardManage_DeleteLine(BoardManager* BoardManager, Block block);

void BoardManage_EndGame(BoardManager* BoardManager, Block block);
int BoardManage_IsEndGame(BoardManager BoardManager, Block block);
int BoardManage_CheckLevelUp(BoardManager BoardManager);
void BoardManage_LevelUp(BoardManager* BoardManager);
void BoardManage_ScoreUp(BoardManager* BoardManager, int Combo);