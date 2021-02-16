#include <utility>
#include <random>
#ifndef SNAKE_H
#define SNAKE_H
#include "Snake.h"
#endif
#define FRUIT_H
class Fruit{
    private:
        std::pair<int, int> pos;
        std::pair<int, int> board;
        int score;
    public:
        Fruit(int height, int width);
        void update(Snake& player);
        int getScore();
        friend class Board;
};