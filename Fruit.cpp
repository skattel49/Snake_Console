#ifndef FRUIT_H
#define FRUIT_H
#include "Fruit.h"
#endif
Fruit::Fruit(int height, int width){
    score = 0;
    //set the size of the board
    board.first = height;
    board.second = width;

    srand(time(0));
    //random position inside the board
    //such that it is not equal to (0, 0)
    pos.first = rand()%(board.first-1) + 1;
    pos.second = rand()%board.second;
}

void Fruit::update(Snake& player){
    pos.first = rand()%board.first;
    pos.second = rand()%board.second;
}

int Fruit::getScore(){
    return this->score;
}