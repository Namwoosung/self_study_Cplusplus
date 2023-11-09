#pragma once

//블록제조시 필요한 수치 설정
#define Block_Shape 7
#define Block_Lotation 4
#define Block_Size 4

// 테트리스판 크기
#define Board_Length 12
#define Board_Height 24

//입력받는 키
#define Left_Key 75
#define Right_Key 77
#define Up_Key 72
#define Down_Key 80
#define SPACE 32
#define P 112
#define p 80
#define ESC 27

// 테트리스판 출력위치 기준 설정
#define Board_X_Stand 9
#define Board_Y_Stand 3
#define Menu_X_Stand 50
#define Menu_Y_Stand 5

// 테트리스 판의 구조물
enum BoardType
{
	Moving_Block = -1,
	Empty,
	Fixed_Block,
	Wall, Bottom_Wall, Top_Wall
};

//블럭의 방향 설정
enum Direction
{
	Up, Right, Down, Left
};

//결과의 참, 거짓
enum Boolen
{
	False, True
};