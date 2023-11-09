#include <ctime>
#include <Windows.h>
#include "Block.h"
#include "SetValue.h"

//���� ����� �Լ�(�� ����ü�� ������ ����)
void Block_MakeBlock(bool isFirst, Block* block)
{
	srand(time(NULL));
	if (isFirst)
	{
		block->CurrentBlock = rand() % Block_Shape;
	}
	else
	{
		block->CurrentBlock = block->NextBlock;
	}
	block->NextBlock = rand() % Block_Shape;
	block->Direction = Up;
	block->Block_X = Board_Length / 2 - 1;
	block->Block_Y = 0;
}

//���� ���������� �̵���Ŵ
void Block_MoveToRight(Block* block)
{
	block->Block_X++;
}
//���� �������� �̵���Ŵ
void Block_MoveToLeft(Block* block)
{
	block->Block_X--;
}
//���� ��ĭ �Ʒ��� �̵���Ŵ
void Block_MoveToDown(Block* block)
{
	block->Block_Y++;
}
//���� ȸ����Ŵ
void Block_RotateBlock(Block* block)
{
	block->Direction = (block->Direction + 1) % Block_Lotation;
}
