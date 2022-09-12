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
#define R 4  // 蛇的状态，U:上 D:下 L:左 R:右


Snake::Snake() {}

Snake::~Snake() {}

Snake *head, *food;           // 蛇头指针，食物指针
Snake *q;                     // 遍历蛇的时候用到的指针

// 初始化蛇身
void Snake::initSnake() {
    Snake *tail;
    int i;
    // 从蛇尾开始，头插法，以 x, y 设定开始的位置
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
    while (tail != NULL)  // 从头到尾，输出蛇身
    {
        painterUI.Pos(tail->x, tail->y);
        printf("■");
        tail = tail->next;
    }
}

// 随机出现食物
void Snake::createFood() {
    Snake *food_1;
    srand((unsigned) time(NULL));
    food_1 = (Snake *) malloc(sizeof(Snake));
    while ((food_1->x % 2) != 0)  // 保证其为偶数，使得食物能与蛇头对齐
    {
        food_1->x = rand() % 52 + 2;
    }
    food_1->y = rand() % 24 + 1;
    q = head;
    while (q->next == NULL) {
        if (q->x == food_1->x && q->y == food_1->y)  // 判断蛇身是否与食物重合
        {
            free(food_1);
            snake.createFood();
        }
        q = q->next;
    }
    painterUI.Pos(food_1->x, food_1->y);
    food = food_1;
    printf("■");
}

// 判断是否咬到了自己
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

// 不能穿墙
void cantCrossWall() {
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26) {
        painterUI.endGameStatus = 1;
        painterUI.endGame();
    }
}

// 蛇前进,上U,下D,左L,右R
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
        // 如果下一个有食物
        nextHead->next = head;
        head = nextHead;
        q = head;
        while (q != NULL) {
            painterUI.Pos(q->x, q->y);
            printf("■");
            q = q->next;
        }
        painterUI.score = painterUI.score + painterUI.add;
        snake.createFood();
    } else {
        // 如果没有食物
        nextHead->next = head;
        head = nextHead;
        q = head;
        while (q->next->next != NULL) {
            painterUI.Pos(q->x, q->y);
            printf("■");
            q = q->next;
        }
        painterUI.Pos(q->next->x, q->next->y);
        printf("  ");
        free(q->next);
        q->next = NULL;
    }

    if (biteSelf() == 1) {
        // 判断是否会咬到自己
        painterUI.endGameStatus = 2;
        painterUI.endGame();
    }
}