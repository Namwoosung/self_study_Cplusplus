#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "BoardManage.h"
#include "CursorManage.h"
#include "Block.h"
#include "SetValue.h"

//구조체를 초기화 함
void BoardManage_Init(BoardManager* BoardManager)
{
	int i, j;
	for (i = 0; i < Board_Height; i++)
	{
		for (j = 0; j < Board_Length; j++)
		{
			BoardManager->Board[i][j] = 0;
		}
	}
	for (i = 0; i < Board_Height; i++)
	{
		for (j = 0; j < Board_Length; j++)
		{
			BoardManager->Board_Copy[i][j] = 10;
		}
	}
	BoardManager->Level = 5;
	BoardManager->LeftBlock = 2;
	BoardManager->Score = 0;
	BoardManager->IsNeedBlcok = True;
	BoardManager->Speed = 500;
	BoardManager->IsDoingGame = True;
}

//테트리스판을 설정(바닥인지 벽인지 비어있는지 등)
void BoardManage_SetBoard(BoardManager* BoardManager)
{
	int i;
	for (i = 0; i < Board_Length; i++)
	{
		BoardManager->Board[2][i] = Top_Wall;
		BoardManager->Board[Board_Height - 1][i] = Bottom_Wall;
	}
	for (i = 0; i < Board_Height; i++)
	{
		BoardManager->Board[i][0] = Wall;
		BoardManager->Board[i][Board_Length - 1] = Wall;
	}
}

//콘솔화면에서 테트리스 판을 그리는 역할(블럭 포함)
void BoardManage_DrawBaord(BoardManager* BoardManager)
{
	int i, j;
	
	CursorManage_RemoveCursor();

	for (i = 0; i < Board_Length; i++)
	{
		if (BoardManager->Board[2][i] == Empty)
		{
			BoardManager->Board[2][i] = Top_Wall;
		}
	}

	for (i = 0; i < Board_Height; i++)
	{
		for (j = 0; j < Board_Length; j++)
		{
			CursorManage_SetCursor(Board_X_Stand + j * 2, Board_Y_Stand + i);
			if (BoardManager->Board[i][j] != BoardManager->Board_Copy[i][j])
			{
				switch (BoardManager->Board[i][j])
				{
				case Empty:
					printf("  ");
					break;
				case Top_Wall:
					printf(" -");
					break;
				case Wall:
					printf("▩");
					break;
				case Bottom_Wall:
					printf("▩");
					break;
				case Moving_Block:
					printf("■");
					break;
				case Fixed_Block:
					printf("■");
					break;
				}
			}
		}
		printf("\n");
	}
	for (i = 0; i < Board_Height; i++)
	{
		for (j = 0; j < Board_Length; j++)
		{
			BoardManager->Board_Copy[i][j] = BoardManager->Board[i][j];
		}
	}
}
//보드판 옆 메뉴판들을 출력시키는 함수
void BoardManage_DrawMenu(BoardManager* BoardManager)
{
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand);
	printf("Level: %d", BoardManager->Level);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 1);
	printf("Left Line For Next Level: %d", BoardManager->LeftBlock);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 3); printf("    Next Block ");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 9); printf(" Score :");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 10); printf("        %d", BoardManager->Score);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 14); printf("  ↑   : Lotation");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 15); printf("←  → : Left / Right");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 16); printf("  ↓   : Down");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 18); printf("SPACE : Push Bottom");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 19); printf("P   : Pause");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 20); printf("ESC  : Quit");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 25);
}
void BoardManage_DrawScoreAndLeftBlock(BoardManager BoardManager)
{
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand);
	printf("Level: %d", BoardManager.Level);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 1);
	printf("Left Line For Next Level: %d  ", BoardManager.LeftBlock);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 9); printf(" Score :");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 10); printf("        %d", BoardManager.Score);
}
//다음블럭이 무엇인지 출력하는 함수
void BoardManage_DrawNextBlock(Block block)
{
	int i, j;
	int line = 5;
	CursorManage_SetCursor(Menu_X_Stand + 5, Menu_Y_Stand + 4);
	for (i = 0; i < Block_Size; i++)
	{
		for (j = 0; j < Block_Size; j++)
		{
			if (block.All_Block[block.NextBlock][Up][i][j] == 1)
			{
				printf("■");
			}
			else
			{
				printf("  ");
			}
		}
		CursorManage_SetCursor(Menu_X_Stand + 5, Menu_Y_Stand + line);
		line++;
	}
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 25);
}

//블럭을 보드판에 대입시키는 함수
void BoardManage_SetBlock(BoardManager* BoardManager, Block* block)
{
	int i, j;
	for (i = 0; i < Block_Size; i++)
	{
		for (j = 0; j < Block_Size; j++)
		{
			if (block->All_Block[block->CurrentBlock][block->Direction][i][j] == 1)
			{
				BoardManager->Board[block->Block_Y  + i][block->Block_X + j] = Moving_Block;
			}
		}
	}
	BoardManager->IsNeedBlcok = False;
}
//키를 입력받은 뒤 블럭을 움직이고 보드판에 대입
void BoardManage_MoveBlock(BoardManager* BoardManager, Block* block, int key)
{
	switch (key)
	{
	case Left_Key:
		return BoardManage_BlockMoveToLeft(BoardManager, block);
	case Right_Key:
		return BoardManage_BlockMoveToRight(BoardManager, block);
	case Down_Key:
		return BoardManage_BlockMoveToDown(BoardManager, block);
	case Up_Key:
		return BoardManage_RotateBlock(BoardManager, block);
	}
}
//블럭을 한칸 내리는 행동을 시행, 만약 아래에 바닥 혹은 굳은블럭이 있다면 굳은 블럭으로 만듦
void BoardManage_BlockMoveToDown(BoardManager* BoardManager, Block* block)
{
	int check;
	int i, j;
	check = BoardManage_PreMoveToDown(*BoardManager, *block);
	if (check == True)
	{
		for (i = 0; i < Block_Size; i++)
		{
			for (j = 0; j < Block_Size; j++)
			{
				if (block->All_Block[block->CurrentBlock][block->Direction][i][j] == 1)
				{
					BoardManager->Board[block->Block_Y + i][block->Block_X + j] = Empty;
				}
			}
		}
		Block_MoveToDown(block);
		BoardManage_SetBlock(BoardManager, block);
	}
	else
	{
		for (i = 0; i < Block_Size; i++)
		{
			for (j = 0; j < Block_Size; j++)
			{
				if (block->All_Block[block->CurrentBlock][block->Direction][i][j] == 1)
				{
					BoardManager->Board[block->Block_Y + i][block->Block_X + j] = Fixed_Block;
				}
			}
		}
		BoardManager->IsNeedBlcok = True;
	}
}
//블럭을 한칸 왼쪽으로 이동시키는 작업을 시행, 만약 옆에 벽이 혹은 굳은 블럭이 있다면 시행하지 않음
void BoardManage_BlockMoveToLeft(BoardManager* BoardManager, Block* block)
{
	int check;
	int i, j;
	check = BoardManage_PreMoveToLeft(*BoardManager, *block);
	if (check == True)
	{
		for (i = 0; i < Block_Size; i++)
		{
			for (j = 0; j < Block_Size; j++)
			{
				if (block->All_Block[block->CurrentBlock][block->Direction][i][j] == 1)
				{
					BoardManager->Board[block->Block_Y + i][block->Block_X + j] = Empty;
				}
			}
		}
		Block_MoveToLeft(block);
		BoardManage_SetBlock(BoardManager, block);
	}
}
//블럭을 한칸 오른쪽으로 이동시키는 작업을 시행 만약 옆에 벽 혹은 굳은 블럭이 있다면 시행하지 않음
void BoardManage_BlockMoveToRight(BoardManager* BoardManager, Block* block)
{
	int check;
	int i, j;
	check = BoardManage_PreMoveToRight(*BoardManager, *block);
	if (check == True)
	{
		for (i = 0; i < Block_Size; i++)
		{
			for (j = 0; j < Block_Size; j++)
			{
				if (block->All_Block[block->CurrentBlock][block->Direction][i][j] == 1)
				{
					BoardManager->Board[block->Block_Y + i][block->Block_X + j] = Empty;
				}
			}
		}
		Block_MoveToRight(block);
		BoardManage_SetBlock(BoardManager, block);
	}
}
//블럭을 회전시키는 작업을 시행 만약 회전시키는 과정에서 벽 혹은 굳은 블럭과 겹쳐진다면 시행하지 않음
void BoardManage_RotateBlock(BoardManager* BoardManager, Block* block)
{
	int check;
	int i, j;
	check = BoardManage_PreRotateBlock(*BoardManager, *block);
	if (check == True)
	{
		for (i = 0; i < Block_Size; i++)
		{
			for (j = 0; j < Block_Size; j++)
			{
				if (block->All_Block[block->CurrentBlock][block->Direction][i][j] == 1)
				{
					BoardManager->Board[block->Block_Y + i][block->Block_X + j] = Empty;
				}
			}
		}
		Block_RotateBlock(block);
		BoardManage_SetBlock(BoardManager, block);
	}
}

//블럭이 보드판의 벽 이나 바닥 혹은 굳은 블럭과 부딪혔는지를 판단하여 알려주는 함수. 먼저 시행하는 함수들에서 사용
int BoardManage_CheckCrush(BoardManager BoardManager, Block block)
{
	int i, j;
	for (i = 0; i < Block_Size; i++)
	{
		for (j = 0; j < Block_Size; j++)
		{
			if (block.All_Block[block.CurrentBlock][block.Direction][i][j] == 1 && BoardManager.Board[block.Block_Y + i][block.Block_X + j] > 0 && BoardManager.Board[block.Block_Y + i][block.Block_X + j] < 4)
			{
				return False;
			}
		}
	}
	return True;
}
//블럭을 왼쪽으로 이동시키는 시행을 미리 해본 뒤 결과를 반환(블럭과 보드판의 현재상황은 바뀌지 않도록 포인터가 아닌 구조체 자체를 매개변수로 받음)
int BoardManage_PreMoveToLeft(BoardManager BoardManager, Block block)
{
	block.Block_X--;
	return BoardManage_CheckCrush(BoardManager, block);
}
//블럭을 오른쪽으로 이동시키는 시행을 미리 해본 뒤 결과를 반환(블럭과 보드판의 현재상황은 바뀌지 않도록 포인터가 아닌 구조체 자체를 매개변수로 받음)
int BoardManage_PreMoveToRight(BoardManager BoardManager, Block block)
{
	block.Block_X++;
	return BoardManage_CheckCrush(BoardManager, block);
}
//블럭을 아래쪽으로 이동시키는 시행을 미리 해본 뒤 결과를 반환(블럭과 보드판의 현재상황은 바뀌지 않도록 포인터가 아닌 구조체 자체를 매개변수로 받음)
int BoardManage_PreMoveToDown(BoardManager BoardManager, Block block)
{
	block.Block_Y++;
	return BoardManage_CheckCrush(BoardManager, block);
}
//블럭을 회전시키는 시행을 미리 해본 뒤 결과를 반환(블럭과 보드판의 현재상황은 바뀌지 않도록 포인터가 아닌 구조체 자체를 매개변수로 받음)
int BoardManage_PreRotateBlock(BoardManager BoardManager, Block block)
{
	block.Direction = (block.Direction + 1) % Block_Lotation;
	return BoardManage_CheckCrush(BoardManager, block);
}
//키를 입력받았는 지를 파악. 만약 키가 눌렸다면 해당 입력에 해당하는 작업을 시행, 추가적으로 만약 스페이스키를 눌렀다면 생략한 줄의 수만큼 점수를 플러스
void BoardManage_CheckKey(BoardManager* BoardManager, Block* block)
{
	int Key = 0;
	int JumpLine = 0;

	if (_kbhit())
	{
		Key = _getch();
		if (Key == 224)
		{
			Key = _getch(); //방향키 지시값인 224가 Key에 입력되어있으니 한번 더 입력받아 어떠한 방향키인지 확인
			BoardManage_MoveBlock(BoardManager, block, Key);
		}
		else
		{
			switch (Key)
			{
			case SPACE:
				while (BoardManage_PreMoveToDown(*BoardManager, *block))
				{
					JumpLine++;
					BoardManage_BlockMoveToDown(BoardManager, block);
				}
				BoardManage_BlockMoveToDown(BoardManager, block);
				BoardManager->Score += JumpLine;
				JumpLine = 0;
				break;
			case P:
			case p:
				BoardManage_Pause(*BoardManager, *block);
				break;
			case ESC:
				system("cls");
				exit(0);
			}
		}
	}
}
// P를 입력받았을 때 테트리스를 멈추는 함수
void BoardManage_Pause(BoardManager BoardManager, Block block)
{
	int Check_Key = True;

	int x = 5;
	int y = 5;

	CursorManage_SetCursor(x, y + 0); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	CursorManage_SetCursor(x, y + 1); printf("▤                              ▤");
	CursorManage_SetCursor(x, y + 2); printf("▤  +-----------------------+   ▤");
	CursorManage_SetCursor(x, y + 3); printf("▤  |       P A U S E       |   ▤");
	CursorManage_SetCursor(x, y + 4); printf("▤  +-----------------------+   ▤");
	CursorManage_SetCursor(x, y + 5); printf("▤  Press any key to resume..   ▤");
	CursorManage_SetCursor(x, y + 6); printf("▤                              ▤");
	CursorManage_SetCursor(x, y + 7); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

	_getch();

	system("cls");
	BoardManage_ResetBoardCopy(&BoardManager);
	BoardManage_DrawBaord(&BoardManager);
	BoardManage_DrawMenu(&BoardManager);
	BoardManage_DrawNextBlock(block);
	Sleep(1000);

}
//정지버튼이 눌렸을 경우 새로 판을 그려야하는데 그러기 위해선 copy보드판을 초기화 시켜줄 필요가 있으므로 위와 같은 함수가 필요
void BoardManage_ResetBoardCopy(BoardManager* BoardManager)
{
	int i, j;

	for (i = 0; i < Board_Height; i++)
	{
		for (j = 0; j < Board_Length; j++)
		{
			BoardManager->Board_Copy[i][j] = 10;
		}
	}
}
// 블록이 떨어졌을 때 블록의 위치를 기준으로 4줄중 지워야할 줄이 있는지 판단하여 지우는 역할, 추가로 지워진 줄의 수만큼 점수를 플러스
void BoardManage_DeleteLine(BoardManager* BoardManager, Block block)
{
	int i, j, k, l;
	int Block_amount;
	int DeleteLine_amount = 0;
	//블럭의 위치를 기준으로 4줄을 검사
	for (i = block.Block_Y; i < block.Block_Y + 4; i++)
	{
		//만약 i가 보드판의 높이보다 커진다면 오류를 발생하게 되므로 이경우 반복문을 중단
		if (i >= Board_Height)
		{
			break;
		}
		//한칸씩 검사하며 굳은블럭의 숫자를 셈
		Block_amount = 0;
		for (j = 1; j < Board_Length - 1; j++)
		{
			if (BoardManager->Board[i][j] == 1)
			{
				Block_amount++;
			}
		}
		//만약 굳은블럭이 10개라면 그 라인을 지우는 역할
		if (Block_amount >= Board_Length - 2)
		{
			DeleteLine_amount++;
			for (j = 1; j < Board_Length - 1; j++)
			{
				BoardManager->Board[i][j] = Empty;
			}
			//지워진 줄 위에있는 굳은블럭들을 한칸씩 아래로 내림
			for (k = i; k > 3; k--)
			{
				for (l = 1; l < Board_Length - 1; l++)
				{
					BoardManager->Board[k][l] = BoardManager->Board[k - 1][l];
					if (k == 4)
					{
						BoardManager->Board[k - 1][l] = Empty;
					}
				}
			}
		}
	}
	BoardManage_ScoreUp(BoardManager, DeleteLine_amount);
	BoardManager->LeftBlock -= DeleteLine_amount;
}
//게임을 끝내는 함수
void BoardManage_EndGame(BoardManager* BoardManager, Block block)
{
	if (BoardManage_IsEndGame(*BoardManager, block))
	{
		BoardManager->IsDoingGame = False;
		system("cls");
		printf("Your Score: %d", BoardManager->Score);
		Sleep(5000);
	}
}
//블럭이 천장에 닿았는지 닿지 않았는지 확인하는 함수
int BoardManage_IsEndGame(BoardManager BoardManager, Block block)
{
	int i, j;
	for (i = 0; i < Block_Size; i++)
	{
		if (BoardManager.Board[2][block.Block_X + i] == 1)
		{
			return True;
		}
	}
	return False;
}
//레벨업을 해야하는지 확인하는 함수
int BoardManage_CheckLevelUp(BoardManager BoardManager)
{
	if (BoardManager.LeftBlock <= 0)
	{
		if (BoardManager.Level >= 10)
		{
			BoardManager.LeftBlock = 0;
			return False;
		}
		else
		{
			return True;
		}
	}
	else
	{
		return False;
	}
}
//레벨업을 해야하는지 확인한 뒤 해야한다면 레벨을 하나 올리고 속도를 높이는 역할
void BoardManage_LevelUp(BoardManager* BoardManager)
{
	if (BoardManage_CheckLevelUp(*BoardManager))
	{
		BoardManager->Level++;
		BoardManager->LeftBlock = 2;
		
		switch (BoardManager->Level)
		{
		case 1:
			BoardManager->Speed = 500;
			break;
		case 2:
			BoardManager->Speed = 400;
			break;
		case 3:
			BoardManager->Speed = 300;
			break;
		case 4:
			BoardManager->Speed = 200;
			break;
		case 5:
			BoardManager->Speed = 100;
			break;
		case 6:
			BoardManager->Speed = 80;
			break;
		case 7:
			BoardManager->Speed = 60;
			break;
		case 8:
			BoardManager->Speed = 40;
			break;
		case 9:
			BoardManager->Speed = 20;
			break;
		case 10:
			BoardManager->Speed = 10;
			break;
		}
	}
}

void BoardManage_ScoreUp(BoardManager* BoardManager, int Combo)
{
	switch (Combo)
	{
	case 1:
		BoardManager->Score += 100;
		break;
	case 2:
		BoardManager->Score += 250;
		break;
	case 3:
		BoardManager->Score += 400;
		break;
	case 4:
		BoardManager->Score += 800;
		break;
	}
}
