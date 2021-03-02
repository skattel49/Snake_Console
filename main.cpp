#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include "Board.h"

using namespace std;

//Draw a board, snake and fruit
//make two threads one for the game mechanics
//the other for user input

//send the input from one thread to the other
bool quit_input = false;
char player_movement;

//function for asynchronous calls to find the keyboard inputs
void Input(){
    struct termios old_state, new_state;
   //copy the settings of stdin to old_state
   tcgetattr(STDIN_FILENO, &old_state);

   new_state = old_state;//copy it to the new state for modification
   //turn off canonical mode to stop buffered input
   //turn off Echo to not display the character we input
   new_state.c_lflag &= (~ICANON & ~ECHO);

   //set the new settings to STDIN_FILENO or 0
   //TCSANOW will set the settings immediately
   tcsetattr(STDIN_FILENO, TCSANOW, &new_state);
   
   while(player_movement!='q'){
       cin>>player_movement;
   }

   //after the game is over change the state of the terminal to normal
   tcsetattr(STDIN_FILENO, TCSANOW, &old_state);
}

void Game(){
    int height = 40, width = 50;
    Snake player;
    Fruit fruit(height, width);
    Board board(height, width);
    while(true){
        system("clear");
        //check if the player and fruit coincide and if the 
        //snake is inside the boundary
        if(board.check(player, fruit)){
            quit_input = true;
            break;
        }

        board.Draw(player, fruit);
        
        //get key from threads if there is a input from keyboard
        //else update player with none
        if(player_movement=='w'){
            //update player appropriately
            player.update(DIR::UP);
        }
        else if(player_movement=='a'){
            //update player appropriately
            player.update(DIR::LEFT);
        }
        else if(player_movement=='s'){
            //update player appropriately
            player.update(DIR::DOWN);
        }
        else if(player_movement=='d'){
            //update player appropriately
            player.update(DIR::RIGHT);
        }
        else if(player_movement=='q'){
            //update player appropriately
            break;
        }
        else{
            player.update(DIR::NONE);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main(){
    thread t2(Input);
    thread t1(Game);
    t1.join();
    t2.join();
    system("clear");
    cout<<"The game has ended"<<endl;
}