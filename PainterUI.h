// PainterUI.h: interface for the PainterUI class.
// Author: YJT

#if !defined(AFX_PAINTERUI_H__3091210D_859C_4330_A618_252DAD2F6124__INCLUDED_)
#define AFX_PAINTERUI_H__3091210D_859C_4330_A618_252DAD2F6124__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EasyXPng.h"

#define WINDOW_WIDTH 1024 // 窗口宽（像素数）
#define WINDOW_HEIGHT 768 // 窗口高（像素数）

#define GRID_SIZE 30 // 棋盘上，每一格的大小（像素数）
#define HALF_GRID (int)(1/2.0 * GRID_SIZE) // 根据上面的宏定义，计算出半格大小

#define OFFSET_X 100 //棋盘及其上面元素的统一偏移量（X）
#define OFFSET_Y 100 //棋盘及其上面元素的统一偏移量（Y）

// 此类是用来绘制界面，加载资源，并创建窗口
class PainterUI {
public:
    // 游戏结束的情况，1：撞到墙；2：咬到自己；3：主动退出游戏。
    int endGameStatus;

    // 总得分
    int score;

    // 每次吃食物得分 =10
    int add;

    void Pos(int x, int y);

    void initPainter();

    void paint();

    void loadImages();

    void createFood();

    void pause();

    void endGame();

    IMAGE pic_back; // 背景图片

    IMAGE_PNG pic_black; // 黑棋图片

    PainterUI();

    virtual ~PainterUI();

};

#endif // !defined(AFX_PAINTERUI_H__3091210D_859C_4330_A618_252DAD2F6124__INCLUDED_)
