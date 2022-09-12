// PainterUI.cpp: implementation of the PainterUI class.
// Author: YJT

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "main.h"
#include "PainterUI.h"


PainterUI::PainterUI() {
    this->add = 10;
}

PainterUI::~PainterUI() {}

// 设置光标位置
void PainterUI::Pos(int x, int y) {
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}

// 开始界面
void welcomeToGame() {
    painterUI.Pos(40, 12);
    system("LPxz -- 贪吃蛇游戏");
    printf("欢迎来到贪食蛇游戏！");
    painterUI.Pos(40, 15);
    printf("Author: LPxz");
    painterUI.Pos(40, 25);
    system("pause");
    system("cls");
    painterUI.Pos(25, 12);
    printf("用 w s a d 控制蛇的上下左右移动， F1 为加速， F2 为减速");
    painterUI.Pos(25, 14);
    printf("加速将能得到更高的分数。\n\n\n\n\n\n\n");
    system("pause");
    system("cls");
}

// 加载地图
void createMap() {
    int i;
    // 打印上下边框
    for (i = 0; i < 58; i += 2) {
        painterUI.Pos(i, 0);
        printf("■");
        painterUI.Pos(i, 26);
        printf("■");
    }
    // 打印左右边框
    for (i = 1; i < 26; i++) {
        painterUI.Pos(0, i);
        printf("■");
        painterUI.Pos(56, i);
        printf("■");
    }
}

// 暂停
void PainterUI::pause() {
    while (true) {
        Sleep(300);
        if (GetAsyncKeyState(VK_SPACE)) {
            break;
        }
    }
}

// 结束游戏
void PainterUI::endGame() {
    system("cls");
    painterUI.Pos(24, 12);
    if (endGameStatus == 1) {
        printf("对不起，您撞到墙了。游戏结束.");
    } else if (endGameStatus == 2) {
        printf("对不起，您咬到自己了。游戏结束.");
    } else if (endGameStatus == 3) {
        printf("您的已经结束了游戏。");
    }
    painterUI.Pos(24, 13);
    printf("您的得分是%d\n", score);
    system("pause");
    exit(0);
}


// 加载所有图片资源
void PainterUI::loadImages() {
    loadimage(&pic_back, "img\\back.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
    loadimage(&pic_black, "img\\hei.png", GRID_SIZE, GRID_SIZE);
    // loadimage(&pic_white, "img\\bai.png", GRID_SIZE, GRID_SIZE);
    // loadimage(&pic_cursor, "img\\cursor.png", GRID_SIZE, GRID_SIZE);
}

// 绘制界面及界面内所有元素
void PainterUI::paint() {
    BeginBatchDrawEx();
    // 绘制棋盘背景图片
    putimage(0, 0, &pic_back);
    putimage(0, 0, &pic_black);
    EndBatchDrawEx();
}

// 加载资源
void PainterUI::initPainter() {
    // 开始界面
    welcomeToGame();
    // 加载背景图
//    loadImages();
    system("mode con cols=100 lines=30");
    // 加载地图
    createMap();
    // 打开主窗口
//    initgraphEx(WINDOW_WIDTH, WINDOW_HEIGHT);
}
