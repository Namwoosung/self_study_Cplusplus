#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "BoardManage.h"
#include "CursorManage.h"
#include "Block.h"
#include "SetValue.h"

//����ü�� �ʱ�ȭ ��
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

//��Ʈ�������� ����(�ٴ����� ������ ����ִ��� ��)
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

//�ܼ�ȭ�鿡�� ��Ʈ���� ���� �׸��� ����(�� ����)
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
					printf("��");
					break;
				case Bottom_Wall:
					printf("��");
					break;
				case Moving_Block:
					printf("��");
					break;
				case Fixed_Block:
					printf("��");
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
//������ �� �޴��ǵ��� ��½�Ű�� �Լ�
void BoardManage_DrawMenu(BoardManager* BoardManager)
{
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand);
	printf("Level: %d", BoardManager->Level);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 1);
	printf("Left Line For Next Level: %d", BoardManager->LeftBlock);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 3); printf("    Next Block ");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 9); printf(" Score :");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 10); printf("        %d", BoardManager->Score);
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 14); printf("  ��   : Lotation");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 15); printf("��  �� : Left / Right");
	CursorManage_SetCursor(Menu_X_Stand, Menu_Y_Stand + 16); printf("  ��   : Down");
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
//�������� �������� ����ϴ� �Լ�
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
				printf("��");
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

//���� �����ǿ� ���Խ�Ű�� �Լ�
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
//Ű�� �Է¹��� �� ���� �����̰� �����ǿ� ����
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
//���� ��ĭ ������ �ൿ�� ����, ���� �Ʒ��� �ٴ� Ȥ�� �������� �ִٸ� ���� ������ ����
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
//���� ��ĭ �������� �̵���Ű�� �۾��� ����, ���� ���� ���� Ȥ�� ���� ���� �ִٸ� �������� ����
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
//���� ��ĭ ���������� �̵���Ű�� �۾��� ���� ���� ���� �� Ȥ�� ���� ���� �ִٸ� �������� ����
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
//���� ȸ����Ű�� �۾��� ���� ���� ȸ����Ű�� �������� �� Ȥ�� ���� ���� �������ٸ� �������� ����
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

//���� �������� �� �̳� �ٴ� Ȥ�� ���� ���� �ε��������� �Ǵ��Ͽ� �˷��ִ� �Լ�. ���� �����ϴ� �Լ��鿡�� ���
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
//���� �������� �̵���Ű�� ������ �̸� �غ� �� ����� ��ȯ(���� �������� �����Ȳ�� �ٲ��� �ʵ��� �����Ͱ� �ƴ� ����ü ��ü�� �Ű������� ����)
int BoardManage_PreMoveToLeft(BoardManager BoardManager, Block block)
{
	block.Block_X--;
	return BoardManage_CheckCrush(BoardManager, block);
}
//���� ���������� �̵���Ű�� ������ �̸� �غ� �� ����� ��ȯ(���� �������� �����Ȳ�� �ٲ��� �ʵ��� �����Ͱ� �ƴ� ����ü ��ü�� �Ű������� ����)
int BoardManage_PreMoveToRight(BoardManager BoardManager, Block block)
{
	block.Block_X++;
	return BoardManage_CheckCrush(BoardManager, block);
}
//���� �Ʒ������� �̵���Ű�� ������ �̸� �غ� �� ����� ��ȯ(���� �������� �����Ȳ�� �ٲ��� �ʵ��� �����Ͱ� �ƴ� ����ü ��ü�� �Ű������� ����)
int BoardManage_PreMoveToDown(BoardManager BoardManager, Block block)
{
	block.Block_Y++;
	return BoardManage_CheckCrush(BoardManager, block);
}
//���� ȸ����Ű�� ������ �̸� �غ� �� ����� ��ȯ(���� �������� �����Ȳ�� �ٲ��� �ʵ��� �����Ͱ� �ƴ� ����ü ��ü�� �Ű������� ����)
int BoardManage_PreRotateBlock(BoardManager BoardManager, Block block)
{
	block.Direction = (block.Direction + 1) % Block_Lotation;
	return BoardManage_CheckCrush(BoardManager, block);
}
//Ű�� �Է¹޾Ҵ� ���� �ľ�. ���� Ű�� ���ȴٸ� �ش� �Է¿� �ش��ϴ� �۾��� ����, �߰������� ���� �����̽�Ű�� �����ٸ� ������ ���� ����ŭ ������ �÷���
void BoardManage_CheckKey(BoardManager* BoardManager, Block* block)
{
	int Key = 0;
	int JumpLine = 0;

	if (_kbhit())
	{
		Key = _getch();
		if (Key == 224)
		{
			Key = _getch(); //����Ű ���ð��� 224�� Key�� �ԷµǾ������� �ѹ� �� �Է¹޾� ��� ����Ű���� Ȯ��
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
// P�� �Է¹޾��� �� ��Ʈ������ ���ߴ� �Լ�
void BoardManage_Pause(BoardManager BoardManager, Block block)
{
	int Check_Key = True;

	int x = 5;
	int y = 5;

	CursorManage_SetCursor(x, y + 0); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");
	CursorManage_SetCursor(x, y + 1); printf("��                              ��");
	CursorManage_SetCursor(x, y + 2); printf("��  +-----------------------+   ��");
	CursorManage_SetCursor(x, y + 3); printf("��  |       P A U S E       |   ��");
	CursorManage_SetCursor(x, y + 4); printf("��  +-----------------------+   ��");
	CursorManage_SetCursor(x, y + 5); printf("��  Press any key to resume..   ��");
	CursorManage_SetCursor(x, y + 6); printf("��                              ��");
	CursorManage_SetCursor(x, y + 7); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");

	_getch();

	system("cls");
	BoardManage_ResetBoardCopy(&BoardManager);
	BoardManage_DrawBaord(&BoardManager);
	BoardManage_DrawMenu(&BoardManager);
	BoardManage_DrawNextBlock(block);
	Sleep(1000);

}
//������ư�� ������ ��� ���� ���� �׷����ϴµ� �׷��� ���ؼ� copy�������� �ʱ�ȭ ������ �ʿ䰡 �����Ƿ� ���� ���� �Լ��� �ʿ�
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
// ����� �������� �� ����� ��ġ�� �������� 4���� �������� ���� �ִ��� �Ǵ��Ͽ� ����� ����, �߰��� ������ ���� ����ŭ ������ �÷���
void BoardManage_DeleteLine(BoardManager* BoardManager, Block block)
{
	int i, j, k, l;
	int Block_amount;
	int DeleteLine_amount = 0;
	//���� ��ġ�� �������� 4���� �˻�
	for (i = block.Block_Y; i < block.Block_Y + 4; i++)
	{
		//���� i�� �������� ���̺��� Ŀ���ٸ� ������ �߻��ϰ� �ǹǷ� �̰�� �ݺ����� �ߴ�
		if (i >= Board_Height)
		{
			break;
		}
		//��ĭ�� �˻��ϸ� �������� ���ڸ� ��
		Block_amount = 0;
		for (j = 1; j < Board_Length - 1; j++)
		{
			if (BoardManager->Board[i][j] == 1)
			{
				Block_amount++;
			}
		}
		//���� �������� 10����� �� ������ ����� ����
		if (Block_amount >= Board_Length - 2)
		{
			DeleteLine_amount++;
			for (j = 1; j < Board_Length - 1; j++)
			{
				BoardManager->Board[i][j] = Empty;
			}
			//������ �� �����ִ� ���������� ��ĭ�� �Ʒ��� ����
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
//������ ������ �Լ�
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
//���� õ�忡 ��Ҵ��� ���� �ʾҴ��� Ȯ���ϴ� �Լ�
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
//�������� �ؾ��ϴ��� Ȯ���ϴ� �Լ�
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
//�������� �ؾ��ϴ��� Ȯ���� �� �ؾ��Ѵٸ� ������ �ϳ� �ø��� �ӵ��� ���̴� ����
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
