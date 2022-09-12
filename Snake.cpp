// Snake.cpp: implementation of the Snake class.
// Author: YJT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "Snake.h"


#define U 1
#define D 2
#define L 3
#define R 4  // �ߵ�״̬��U:�� D:�� L:�� R:��


Snake::Snake() {}

Snake::~Snake() {}

Snake *head, *food;           // ��ͷָ�룬ʳ��ָ��
Snake *q;                     // �����ߵ�ʱ���õ���ָ��

// ��ʼ������
void Snake::initSnake() {
    Snake *tail;
    int i;
    // ����β��ʼ��ͷ�巨���� x, y �趨��ʼ��λ��
    tail = (Snake *) malloc(sizeof(Snake));
    tail->x = 24;
    tail->y = 5;
    tail->next = NULL;
    for (i = 1; i <= 4; i++) {
        head = (Snake *) malloc(sizeof(Snake));
        head->next = tail;
        head->x = 24 + 2 * i;
        head->y = 5;
        tail = head;
    }
    while (tail != NULL)  // ��ͷ��β���������
    {
        painterUI.Pos(tail->x, tail->y);
        printf("��");
        tail = tail->next;
    }
}

// �������ʳ��
void Snake::createFood() {
    Snake *food_1;
    srand((unsigned) time(NULL));
    food_1 = (Snake *) malloc(sizeof(Snake));
    while ((food_1->x % 2) != 0)  // ��֤��Ϊż����ʹ��ʳ��������ͷ����
    {
        food_1->x = rand() % 52 + 2;
    }
    food_1->y = rand() % 24 + 1;
    q = head;
    while (q->next == NULL) {
        if (q->x == food_1->x && q->y == food_1->y)  // �ж������Ƿ���ʳ���غ�
        {
            free(food_1);
            snake.createFood();
        }
        q = q->next;
    }
    painterUI.Pos(food_1->x, food_1->y);
    food = food_1;
    printf("��");
}

// �ж��Ƿ�ҧ�����Լ�
int biteSelf() {
    Snake *self;
    self = head->next;
    while (self != NULL) {
        if (self->x == head->x && self->y == head->y) {
            return 1;
        }
        self = self->next;
    }
    return 0;
}

// ���ܴ�ǽ
void cantCrossWall() {
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26) {
        painterUI.endGameStatus = 1;
        painterUI.endGame();
    }
}

// ��ǰ��,��U,��D,��L,��R
void Snake::snakeMove() {
    Snake *nextHead;
    cantCrossWall();

    nextHead = (Snake *) malloc(sizeof(Snake));
    if (status == U) {
        nextHead->x = head->x;
        nextHead->y = head->y - 1;
    } else if (status == D) {
        nextHead->x = head->x;
        nextHead->y = head->y + 1;
    } else if (status == L) {
        nextHead->x = head->x - 2;
        nextHead->y = head->y;
    } else if (status == R) {
        nextHead->x = head->x + 2;
        nextHead->y = head->y;
    }
    if (nextHead->x == food->x && nextHead->y == food->y) {
        // �����һ����ʳ��
        nextHead->next = head;
        head = nextHead;
        q = head;
        while (q != NULL) {
            painterUI.Pos(q->x, q->y);
            printf("��");
            q = q->next;
        }
        painterUI.score = painterUI.score + painterUI.add;
        snake.createFood();
    } else {
        // ���û��ʳ��
        nextHead->next = head;
        head = nextHead;
        q = head;
        while (q->next->next != NULL) {
            painterUI.Pos(q->x, q->y);
            printf("��");
            q = q->next;
        }
        painterUI.Pos(q->next->x, q->next->y);
        printf("  ");
        free(q->next);
        q->next = NULL;
    }

    if (biteSelf() == 1) {
        // �ж��Ƿ��ҧ���Լ�
        painterUI.endGameStatus = 2;
        painterUI.endGame();
    }
}