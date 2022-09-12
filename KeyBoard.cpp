// KeyBoard.cpp: implementation of the KeyBoard class.
// Author: YJT

#include <stdio.h>
#include <windows.h>

#include "main.h"
#include "KeyBoard.h"


#define U 1
#define D 2
#define L 3
#define R 4  // �ߵ�״̬��U:�� D:�� L:�� R:��


// ÿ�����е�ʱ����
int sleepTime = 200;

KeyBoard::KeyBoard() {}

KeyBoard::~KeyBoard() {}

// ������Ϸ
void KeyBoard::playGame() {
    painterUI.Pos(64, 15);
    printf("���ܴ�ǽ������ҧ���Լ�\n");
    painterUI.Pos(64, 16);
    printf("�� ��.��.��.�� �ֱ�����ߵ��ƶ�.");
    painterUI.Pos(64, 17);
    printf("F1 Ϊ���٣�F2 Ϊ����\n");
    painterUI.Pos(64, 18);
    printf("ESC: �˳���Ϸ.");
    painterUI.Pos(64, 19);
    printf("Space: ��ͣ��Ϸ.");
    snake.status = R;
    while (true) {
		// ���ƽ�������
//		painterUI.paint();
        painterUI.Pos(64, 10);
        printf("�÷֣�%d ", painterUI.score);
        painterUI.Pos(64, 11);
        printf("ÿ��ʳ��÷֣�%d��", painterUI.add);
        if (GetAsyncKeyState(VK_UP) && snake.status != D) {
            snake.status = U;
        } else if (GetAsyncKeyState(VK_DOWN) && snake.status != U) {
            snake.status = D;
        } else if (GetAsyncKeyState(VK_LEFT) && snake.status != R) {
            snake.status = L;
        } else if (GetAsyncKeyState(VK_RIGHT) && snake.status != L) {
            snake.status = R;
        } else if (GetAsyncKeyState(VK_SPACE)) {
            painterUI.pause();
        } else if (GetAsyncKeyState(VK_ESCAPE)) {
            painterUI.endGameStatus = 3;
            break;
        } else if (GetAsyncKeyState(VK_F1)) {
            if (sleepTime >= 50) {
                sleepTime = sleepTime - 30;
                painterUI.add = painterUI.add + 2;
                if (sleepTime == 320) {
                    painterUI.add = 2;  // ��ֹ����1֮���ټӻ����д�
                }
            }
        } else if (GetAsyncKeyState(VK_F2)) {
            if (sleepTime < 350) {
                sleepTime = sleepTime + 30;
                painterUI.add = painterUI.add - 2;
                if (sleepTime == 350) {
                    painterUI.add = 1;  // ��֤��ͷ�Ϊ1
                }
            }
        }
        Sleep(sleepTime);
        snake.snakeMove();
    }
}
