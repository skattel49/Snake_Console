#ifndef SNAKE_H
#define SNAKE_H
#include "Snake.h"
#endif

#ifndef FRUIT_H
#define FRUIT_H
#include "Fruit.h"
#endif

#define BOARD_H

class Board{
    public:
        Board(int height, int width);
        void Draw(Snake& player, Fruit& fruit);
        bool check(Snake& player, Fruit& fruit);
        ~Board();
    private:
        char** board;
        int height;
        int width;
        char obstacle = 'O';
};