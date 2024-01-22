#include <windows.h>
#include "TetrisManage.h"

void TetrisManager_StartGame()
{
	TetrisManager TetrisManager;
	TetrisManager_StartTetris(&TetrisManager);
	TetrisManager_ProcessTetris(&TetrisManager);
}

void TetrisManager_StartTetris(TetrisManager* TetrisManager)
{
	BoardManager BoardManager = {0,};
	Block block;

	TetrisManager->BoardManager = BoardManager;
	TetrisManager->block = block;

	BoardManage_Init(&TetrisManager->BoardManager);
	BoardManage_SetBoard(&TetrisManager->BoardManager);
	BoardManage_DrawBaord(&TetrisManager->BoardManager);
	BoardManage_DrawMenu(&TetrisManager->BoardManager);
	Sleep(1000);
	Block_MakeBlock(true, &TetrisManager->block);
	BoardManage_DrawNextBlock(TetrisManager->block);
	BoardManage_SetBlock(&TetrisManager->BoardManager, &TetrisManager->block);
	BoardManage_DrawBaord(&TetrisManager->BoardManager);

}

void TetrisManager_ProcessTetris(TetrisManager* TetrisManager)
{
	while (TetrisManager->BoardManager.IsDoingGame)
	{
		for (int i = 0; i < 5; i++)
		{
			BoardManage_CheckKey(&TetrisManager->BoardManager, &TetrisManager->block);
			BoardManage_DrawBaord(&TetrisManager->BoardManager);
			Sleep(TetrisManager->BoardManager.Speed / 5);
		}
		BoardManage_BlockMoveToDown(&TetrisManager->BoardManager, &TetrisManager->block);
		BoardManage_DrawBaord(&TetrisManager->BoardManager);
		Sleep(TetrisManager->BoardManager.Speed);
		if (TetrisManager->BoardManager.IsNeedBlcok)
		{
			BoardManage_DeleteLine(&TetrisManager->BoardManager, TetrisManager->block);
			BoardManage_LevelUp(&TetrisManager->BoardManager);
			BoardManage_DrawScoreAndLeftBlock(TetrisManager->BoardManager);
			Block_MakeBlock(false, &TetrisManager->block);
			BoardManage_DrawNextBlock(TetrisManager->block);
			BoardManage_SetBlock(&TetrisManager->BoardManager, &TetrisManager->block);
			BoardManage_DrawBaord(&TetrisManager->BoardManager);
			BoardManage_EndGame(&TetrisManager->BoardManager, TetrisManager->block);
		}
	}
}