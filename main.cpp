/*  Paul R Birkholtz
    Pathfinder V1
    6/26/2016      */
#include <iostream>
#include "pathFinder.h"

using namespace std;

int main(){
    signed int choice= 1;	//Users choice to re-run program

    try{
        while(choice== 1){
            setColor(15);
            if(choice== 1){
                cout<< "Run Pathfinder? (1= yes)\n";
                cin>> choice;
                execute();
            }else{
                break;
            }
        }
        return 0;
    }catch(...){
        cerr<< "ERROR: An unknown error has occurred, please reset Pathfinder and try again."<< endl;
        return -1;
    }
}

