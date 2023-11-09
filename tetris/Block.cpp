#include <ctime>
#include <Windows.h>
#include "Block.h"
#include "SetValue.h"

//블럭을 만드는 함수(블럭 구조체의 생성자 역할)
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

//블럭을 오른쪽으로 이동시킴
void Block_MoveToRight(Block* block)
{
	block->Block_X++;
}
//블럭을 왼쪽으로 이동시킴
void Block_MoveToLeft(Block* block)
{
	block->Block_X--;
}
//블럭을 한칸 아래로 이동시킴
void Block_MoveToDown(Block* block)
{
	block->Block_Y++;
}
//블럭을 회전시킴
void Block_RotateBlock(Block* block)
{
	block->Direction = (block->Direction + 1) % Block_Lotation;
}
