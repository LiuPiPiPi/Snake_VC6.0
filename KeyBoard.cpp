// KeyBoard.cpp: implementation of the KeyBoard class.
// Author: YJT

#include <stdio.h>
#include <windows.h>

#include "main.h"
#include "KeyBoard.h"


#define U 1
#define D 2
#define L 3
#define R 4  // 蛇的状态，U:上 D:下 L:左 R:右


// 每次运行的时间间隔
int sleepTime = 200;

KeyBoard::KeyBoard() {}

KeyBoard::~KeyBoard() {}

// 控制游戏
void KeyBoard::playGame() {
    painterUI.Pos(64, 15);
    printf("不能穿墙，不能咬到自己\n");
    painterUI.Pos(64, 16);
    printf("用 ↑.↓.←.→ 分别控制蛇的移动.");
    painterUI.Pos(64, 17);
    printf("F1 为加速，F2 为减速\n");
    painterUI.Pos(64, 18);
    printf("ESC: 退出游戏.");
    painterUI.Pos(64, 19);
    printf("Space: 暂停游戏.");
    snake.status = R;
    while (true) {
		// 绘制界面内容
//		painterUI.paint();
        painterUI.Pos(64, 10);
        printf("得分：%d ", painterUI.score);
        painterUI.Pos(64, 11);
        printf("每个食物得分：%d分", painterUI.add);
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
                    painterUI.add = 2;  // 防止减到1之后再加回来有错
                }
            }
        } else if (GetAsyncKeyState(VK_F2)) {
            if (sleepTime < 350) {
                sleepTime = sleepTime + 30;
                painterUI.add = painterUI.add - 2;
                if (sleepTime == 350) {
                    painterUI.add = 1;  // 保证最低分为1
                }
            }
        }
        Sleep(sleepTime);
        snake.snakeMove();
    }
}
