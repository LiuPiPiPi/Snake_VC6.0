// Snake.h: interface for the Snake class.
// Author: YJT

#if !defined(AFX_SNAKE_H__7E850E5E_8C3A_4E1B_9F89_CF25FDB3FC10__INCLUDED_)
#define AFX_SNAKE_H__7E850E5E_8C3A_4E1B_9F89_CF25FDB3FC10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Snake {
public:
    int x;
    int y;
    Snake *next;
    int status;

    void initSnake();

    void createFood();

    void snakeMove();

    Snake();

    virtual ~Snake();

};


#endif // !defined(AFX_SNAKE_H__922926AA_C399_443C_8FCA_EA376F7CE731__INCLUDED_)
