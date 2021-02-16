#include <iostream>

#ifndef BOARD_H
#define BOARD_H
#include "Board.h"
#endif

Board::Board(int height, int width){
    this->height = height;
    this->width = width;
    board = new char*[height];
    for(int i = 0; i<height; i++){
        board[i] = new char[width];
    }

}

void Board::Draw(Snake& player, Fruit& fruit){
    std::cout<<"Controls UP:w+Enter DOWN: s+Enter LEFT: a+Enter RIGHT: d+Enter"<<std::endl;
    std::cout<<"fruit: "<<fruit.pos.second<< " "<<fruit.pos.first<<std::endl;
    //upper border
    for(int i = 0; i<width+2; i++){
        std::cout<<"#";
    }
    std::cout<<std::endl;
    
    
    //set the tails in correct position
    for(int i = 0; i<player.tail.size(); i++){
        board[player.tail[i].second][player.tail[i].first] = 'o';
    }
    //set the head of the matrix to the snake's head
    board[player.head.second][player.head.first] = 'O';
    board[fruit.pos.first][fruit.pos.second] = 'F';
    
    for(int i =0; i<height; i++){
        for(int j= 0; j<width; j++){
            if(j==0)
                std::cout<<"#";

            if(board[i][j]=='O'){
                std::cout<<"O";
            }
            else if(board[i][j]=='o'){
                std::cout<<"o";
            }
            else if(board[i][j]=='F'){
                std::cout<<"F";
            }
            else{
                std::cout<<" ";
            }

            if(j==width-1)
                std::cout<<"#";
        }
        std::cout<<std::endl;
    }

    //lower border
    for(int i = 0; i<width+2; i++){
        std::cout<<"#";
    }
    std::cout<<std::endl;

    std::cout<<"Score: "<<fruit.score*10<<std::endl;

    board[player.head.second][player.head.first] = 0;
    for(int i = 0; i<player.tail.size(); i++){
        board[player.tail[i].second][player.tail[i].first] = 0;
    }
}

bool Board::check(Snake& player, Fruit& fruit){
    if(player.head.first<0 || player.head.first>=width || player.head.second<0 || player.head.second>=height){
        return true;
    }

    if(player.head.first == fruit.pos.second && player.head.second==fruit.pos.first){
        fruit.update(player);
        player.addTail();
        fruit.score++;
    }
    return false;
}

Board::~Board(){
    for(int i = 0; i<height; i++){
        delete[] board[i];
    }
    delete[] board;
}