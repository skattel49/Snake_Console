#include "Snake.h"

Snake::Snake(){
    this->head.first = 0;
    this->head.second = 0;
    prev = RIGHT;
}

void Snake::update(DIR x){
    //copy the previous position of head to temporary variables
    int tmp_x = this->head.first;
    int tmp_y = this->head.second;

    if(x == NONE){
        x = prev;
    }

    switch(x){
        case UP:
            prev = UP;
            this->head.second--;
            break;
        case DOWN:
            prev = DOWN;
            this->head.second++;
            break;
        case LEFT:
            prev = LEFT;
            this->head.first--;
            break;
        case RIGHT:
            prev = RIGHT;
            this->head.first++;
            break;
    }
    
    //temp variables for exchanging values
    int tmp1_x, tmp1_y;

    for(int i = 0; i<tail.size(); i++){
        //copy the position of tails to temp variable
        tmp1_x = tail[i].first;
        tmp1_y = tail[i].second;
        //copy the position of previous tail node
        tail[i].first = tmp_x;
        tail[i].second = tmp_y;
        //copy the current position to a temp variable for the next node
        tmp_x = tmp1_x;
        tmp_y = tmp1_y;
    }
}

void Snake::addTail(){
    tail.push_back(head);
}