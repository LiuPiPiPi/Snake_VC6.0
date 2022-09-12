// Author: YJT

#include <conio.h>
#include "EasyXPng.h"

#include "main.h"

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

KeyBoard keyBoard;
Snake snake;
PainterUI painterUI;

int main(){
    mciSendString("play music\\111.mp3 repeat",NULL,0,NULL);
	painterUI.initPainter();
    snake.initSnake();
    snake.createFood();
    keyBoard.playGame();
    painterUI.endGame();
	return 0;
}