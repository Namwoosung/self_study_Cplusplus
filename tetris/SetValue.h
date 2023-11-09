#pragma once

//��������� �ʿ��� ��ġ ����
#define Block_Shape 7
#define Block_Lotation 4
#define Block_Size 4

// ��Ʈ������ ũ��
#define Board_Length 12
#define Board_Height 24

//�Է¹޴� Ű
#define Left_Key 75
#define Right_Key 77
#define Up_Key 72
#define Down_Key 80
#define SPACE 32
#define P 112
#define p 80
#define ESC 27

// ��Ʈ������ �����ġ ���� ����
#define Board_X_Stand 9
#define Board_Y_Stand 3
#define Menu_X_Stand 50
#define Menu_Y_Stand 5

// ��Ʈ���� ���� ������
enum BoardType
{
	Moving_Block = -1,
	Empty,
	Fixed_Block,
	Wall, Bottom_Wall, Top_Wall
};

//���� ���� ����
enum Direction
{
	Up, Right, Down, Left
};

//����� ��, ����
enum Boolen
{
	False, True
};