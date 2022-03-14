#include<iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;

bool gameover;

//game window resolution
const int width =50;
const int length=20;

//snek position
int x,y;

//fruit position
int fruitx,fruity;

//score
int score;

//direction tracking with enums
enum direction {STOP=0,LEFT,RIGHT,UP,DOWN};
direction dir;

void fruitpos(){
    fruitx=rand() % 45+3;
    fruity=rand() % 15+3;
}

void setup(){
    gameover=false;

    dir = STOP;

    x=width/2;
    y=length/2;

    fruitpos();

    score=0;
}
void draw(){

    system("cls");

    //border "#"s
    for(int i=0;i<width;i++){
        cout << "#";
    }
    cout << endl;
    for(int j=1;j<length;j++){
        for(int i=0;i<width;i++){
            if(i==0){
                cout << "#";
            }else if (i==width-1){
                cout << "#";
            }else{
                if(i==x && j==y){
                    cout << "O";
                }else if (i==fruitx && j == fruity){
                    cout << "F";
                }else{
                    cout << " ";
                }   
            }   
        }
        cout << endl;
    }
    for(int i=0;i<width;i++){
        cout << "#";
    }
    cout << endl << "your score is = " << score;


}
void input(){
    if(_kbhit()){
        switch (_getch())
        {
        case 'w':
           dir = UP;
            break;
        case 'a':
           dir = LEFT;
            break;
        case 's':
           dir = DOWN;
            break;
        case 'd':
           dir = RIGHT;
            break;

        case '`':
            gameover=true;
            break;
        }
    }

}
void logic(){
    switch(dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    }

    if(x<1 || x>width-2){
        gameover=true;
    }
    if(y<1 || y>length-1){
        gameover=true;
    }

    if(x==fruitx && y == fruity){
        score++;
        fruitpos();
    }

}

int main(){
    srand((unsigned) time(0));
    setup();
    while(!gameover){
        draw();
        input();
        logic();
        Sleep(3);
    }
    getch();
    return 0;
}