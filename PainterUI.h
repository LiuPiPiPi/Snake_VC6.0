// PainterUI.h: interface for the PainterUI class.
// Author: YJT

#if !defined(AFX_PAINTERUI_H__3091210D_859C_4330_A618_252DAD2F6124__INCLUDED_)
#define AFX_PAINTERUI_H__3091210D_859C_4330_A618_252DAD2F6124__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "EasyXPng.h"

#define WINDOW_WIDTH 1024 // ���ڿ���������
#define WINDOW_HEIGHT 768 // ���ڸߣ���������

#define GRID_SIZE 30 // �����ϣ�ÿһ��Ĵ�С����������
#define HALF_GRID (int)(1/2.0 * GRID_SIZE) // ��������ĺ궨�壬���������С

#define OFFSET_X 100 //���̼�������Ԫ�ص�ͳһƫ������X��
#define OFFSET_Y 100 //���̼�������Ԫ�ص�ͳһƫ������Y��

// �������������ƽ��棬������Դ������������
class PainterUI {
public:
    // ��Ϸ�����������1��ײ��ǽ��2��ҧ���Լ���3�������˳���Ϸ��
    int endGameStatus;

    // �ܵ÷�
    int score;

    // ÿ�γ�ʳ��÷� =10
    int add;

    void Pos(int x, int y);

    void initPainter();

    void paint();

    void loadImages();

    void createFood();

    void pause();

    void endGame();

    IMAGE pic_back; // ����ͼƬ

    IMAGE_PNG pic_black; // ����ͼƬ

    PainterUI();

    virtual ~PainterUI();

};

#endif // !defined(AFX_PAINTERUI_H__3091210D_859C_4330_A618_252DAD2F6124__INCLUDED_)
