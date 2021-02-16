#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
using namespace std;
int main(){
    int file_desc;
    int a;
    cin>>a;
    char x;

        //replace file_desc with the input stream
        file_desc = open("asd.txt", O_APPEND | O_RDWR | O_CREAT);
        //copy cin to file_desc
        dup2(file_desc, 0);
        //check for characters in file_desc
        if(read(file_desc, &x, 1)==-1){
            cout<<errno<<endl;
        }
        if(read(file_desc, &x, 1) == 1){
            if(x=='\n'){
                cout<<"haha"<<endl;
            }
            //append new line if there is a character
        }
        //close the file desc
        close(file_desc);
    
}

//writing into cin does not work so what i can do is
//create a file write to it read it and then