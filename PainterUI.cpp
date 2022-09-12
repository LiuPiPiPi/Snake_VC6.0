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

// ���ù��λ��
void PainterUI::Pos(int x, int y) {
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}

// ��ʼ����
void welcomeToGame() {
    painterUI.Pos(40, 12);
    system("LPxz -- ̰������Ϸ");
    printf("��ӭ����̰ʳ����Ϸ��");
    painterUI.Pos(40, 15);
    printf("Author: LPxz");
    painterUI.Pos(40, 25);
    system("pause");
    system("cls");
    painterUI.Pos(25, 12);
    printf("�� w s a d �����ߵ����������ƶ��� F1 Ϊ���٣� F2 Ϊ����");
    painterUI.Pos(25, 14);
    printf("���ٽ��ܵõ����ߵķ�����\n\n\n\n\n\n\n");
    system("pause");
    system("cls");
}

// ���ص�ͼ
void createMap() {
    int i;
    // ��ӡ���±߿�
    for (i = 0; i < 58; i += 2) {
        painterUI.Pos(i, 0);
        printf("��");
        painterUI.Pos(i, 26);
        printf("��");
    }
    // ��ӡ���ұ߿�
    for (i = 1; i < 26; i++) {
        painterUI.Pos(0, i);
        printf("��");
        painterUI.Pos(56, i);
        printf("��");
    }
}

// ��ͣ
void PainterUI::pause() {
    while (true) {
        Sleep(300);
        if (GetAsyncKeyState(VK_SPACE)) {
            break;
        }
    }
}

// ������Ϸ
void PainterUI::endGame() {
    system("cls");
    painterUI.Pos(24, 12);
    if (endGameStatus == 1) {
        printf("�Բ�����ײ��ǽ�ˡ���Ϸ����.");
    } else if (endGameStatus == 2) {
        printf("�Բ�����ҧ���Լ��ˡ���Ϸ����.");
    } else if (endGameStatus == 3) {
        printf("�����Ѿ���������Ϸ��");
    }
    painterUI.Pos(24, 13);
    printf("���ĵ÷���%d\n", score);
    system("pause");
    exit(0);
}


// ��������ͼƬ��Դ
void PainterUI::loadImages() {
    loadimage(&pic_back, "img\\back.jpg", WINDOW_WIDTH, WINDOW_HEIGHT);
    loadimage(&pic_black, "img\\hei.png", GRID_SIZE, GRID_SIZE);
    // loadimage(&pic_white, "img\\bai.png", GRID_SIZE, GRID_SIZE);
    // loadimage(&pic_cursor, "img\\cursor.png", GRID_SIZE, GRID_SIZE);
}

// ���ƽ��漰����������Ԫ��
void PainterUI::paint() {
    BeginBatchDrawEx();
    // �������̱���ͼƬ
    putimage(0, 0, &pic_back);
    putimage(0, 0, &pic_black);
    EndBatchDrawEx();
}

// ������Դ
void PainterUI::initPainter() {
    // ��ʼ����
    welcomeToGame();
    // ���ر���ͼ
//    loadImages();
    system("mode con cols=100 lines=30");
    // ���ص�ͼ
    createMap();
    // ��������
//    initgraphEx(WINDOW_WIDTH, WINDOW_HEIGHT);
}
