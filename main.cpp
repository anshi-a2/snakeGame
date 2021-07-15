#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameover;
const int width=30;
const int height = 30;
int x,y, fruitX, fruitY, score;
enum eDir{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDir dir;
int tailX[100];
int tailY[100];
int lentail;

void setup(){
    gameover= false;
    dir= STOP;
    x=width/2;
    y=height/2;
    fruitX = rand()%width;
    fruitY = rand()% height;
    score =0;
    //int lentail;

}

void draw(){

    system("cls");
    for(int i=0; i<width+1; i++){
        cout<<"#";

    }
    cout<<endl;

    for(int i=0 ; i< height; i++){
        for(int j=0; j<=width; j++){
            if(j==0 or j==width)
                cout<<"#";
            if(i==y && j==x)
                cout<<"O";
            else if(i==fruitY && j==fruitX)
                cout<<"F";
            else{
                bool print = false;
                for(int k = 0 ; k<lentail ;k++){

                    if(tailX[k]==j and tailY[k]==i){
                        cout<<"o";
                        print = true;
                    }

                }
                if(!print){
                        cout<<" ";
                    }


            }

        }

        cout<<endl;
    }

    for(int i=0; i<width+1; i++){
        cout<<"#";

    }

   cout<<endl;

   cout<<" score is : " << score << endl;

}

void input(){

    if(_kbhit())
    {
        switch(_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'w':
                dir = UP;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameover= true;
                break;

        }
    }

}

void logic(){

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    //tailX[0]= x;
    //tailY[0] = y;

    for(int i =0 ; i<lentail ;i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY= prev2Y;
      //  tailX[i]=tailX[i-1];
      //  tailY[i]=tailY[i-1];
    }
   tailX[0]=x;
    tailY[0]=y;

    switch(dir){
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    if(x==fruitX and y==fruitY){
        score+=20;
        fruitX=rand()%width;
        fruitY =rand()%height;
        lentail++;
    }

    for(int i = 0 ; i<lentail ; i++){
        if(tailX[i]==x and tailY[i]==y){
            gameover = true;
        }
    }
//can use it when want to end game if snake strikes the wall
    //if(x>width or x<0 or y>height or y<0){
    //    gameover= true;
    //}

    if(x>=width) x=0;
    else if(x<0) x=width-1;

    if(y>=height) y=0;
    else if(y<0) y=width-1;
}


int main() {

    setup();
    while(!gameover){
        draw();
        input();
        logic();
    }
	return 0;
}
