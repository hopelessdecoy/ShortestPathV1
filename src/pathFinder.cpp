#include "pathFinder.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

static const signed int MAP_SIZE_X= 51;                                         //Defines map X size
static const signed int MAP_SIZE_Y= 51;                                         //Defines map Y size
signed int pathMap[MAP_SIZE_X][MAP_SIZE_Y];                                     //Builds blank path map

//Execution of Pathfinder function///////////////////////////////////////////////////////////////
void execute(){
    signed int xStemp= 0;                                                       //X start coordinate
    signed int yStemp= 0;                                                       //Y start coordinate
    signed int xDtemp= 2;                                                       //X destination coordinate
    signed int yDtemp= 2;                                                       //Y destination coordinate

    cout<< "\nplease select a start point x-coordinate(0-50):\n";
        cin>> xStemp;
    cout<< "please select a start point y-coordinate(0-50):\n";
        cin>> yStemp;
    cout<< "please select a destination point x-coordinate(0-50):\n";
        cin>> xDtemp;
    cout<< "please select a destination point y-coordinate(0-50):\n";
        cin>> yDtemp;

    if(xStemp> MAP_SIZE_X- 1 || yStemp> MAP_SIZE_Y- 1 || xStemp< 0 || yStemp< 0 || xDtemp> MAP_SIZE_X- 1 || yDtemp> MAP_SIZE_Y- 1 || xDtemp< 0 || yDtemp< 0){
        cerr<< "ERROR: One or more coordinates exceed the size of the grid or is not a valid integer. Please try again";
    }else{
        runMap(xStemp, yStemp, xDtemp, yDtemp);
        printMap();
        resetMap();
    }
}

//Traversal function///////////////////////////////////////////////////////////////
void runMap(int a,int b,int c,int d){

	signed int xAxis= a;                                 //X start coordinate
	signed int yAxis= b;                                 //Y start coordinate
	signed int destinationX= c;                          //X destination coordinate
	signed int destinationY= d;                          //Y destination coordinate
    signed int moveCounter= 0;                           //tracks spaces Pathfinder has traversed

    /*Traversal Logic= Starts at 3 adds 1 to each multiD Array element
    traversed upon the destination ends on 6. 0's represent empty
    movable spaces on the grid.
    */
    pathMap[xAxis][yAxis]+= 3;
    if(xAxis== destinationX && yAxis== destinationY){
    }else{
        while(xAxis!= destinationX || yAxis!= destinationY){
            //Diagonal down right movement
            if(xAxis< destinationX && yAxis< destinationY){
                xAxis++;
                yAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
            //Diagonal up left movement
            if(xAxis> destinationX && yAxis> destinationY){
                xAxis--;
                yAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
            //Diagonal down left movement
            if(xAxis> destinationX && yAxis< destinationY){
                xAxis--;
                yAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
            //Diagonal up right movement
            if(xAxis< destinationX && yAxis> destinationY){
                xAxis++;
                yAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
            //Right movement
            if(xAxis< destinationX){
                xAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
            //Left movement
            if(xAxis> destinationX){
                xAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
            //Up movement
            if(yAxis< destinationY){
                yAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
            //Down movement
            if(yAxis> destinationY){
                yAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
        }
        pathMap[xAxis][yAxis]= 6;
    }

        //Moves used//
        setColor(14);
        cout<< "\n\n Moves Used: " << moveCounter<< "\n";
        setColor(15);

        //X axis column numbering//
        cout << "  ";
        for(signed int i= 1; i<= MAP_SIZE_X; i++){
            if(i> 10){
                setColor(i);
                cout<< i- 1;
            }else{
                cout<< i- 1<< " ";
            }
        }
        cout<< "\n"<< "  ";
        setColor(15);
        for(signed int i= 0; i<= MAP_SIZE_X; i++){
            cout<< "--";
        }
        cout<< "\n";
    }

//print map function//////////////////////////////////////////////////////////////
void printMap(){
    signed int counterX= 0;
    signed int counterY= 0;

    for(signed int i= 1; i<= MAP_SIZE_Y; i++){
            cout<< "| ";
            counterX= 0;
            for(signed int j= 1; j<= MAP_SIZE_X; j++){
                if(pathMap[counterX][counterY]> 0){
                    setColor(12);
                }else{
                    setColor(15);
                }
                cout<< pathMap[counterX][counterY] << " ";
                counterX= j;
        }
        counterY= i;
        setColor(7);
        cout<< "| "<< i- 1<< "\n";
    }
    setColor(7);
}

//Reset map function///////////////////////////////////////////////////////////////
void resetMap(){
    signed int resetX= 0;
    signed int resetY= 0;

    for(signed int i= 0; i<= MAP_SIZE_Y; i++){
        for(signed int j= 0; j<= MAP_SIZE_X; j++){
            pathMap[resetX][resetY]= 0;
            resetX= j;
        }
    resetY= i;
    }
    setColor(14);
    cout<< "_________________\n"<< "Map data cleared\n"<< "-----------------\n"<< endl;
}


//Color text function//////////////////////////////////////////////////////////////
void setColor(int ForgC){
    WORD wColor;

    //Retrieves current background attribute//
    HANDLE hStdOut= GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //csbi is used for  the wAttributes word//
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        //Masks all but background attributes, adds foreground color//
        wColor= (csbi.wAttributes& 0xF0)+ (ForgC& 0x0f);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

