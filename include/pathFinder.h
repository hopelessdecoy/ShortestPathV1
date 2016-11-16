#ifndef PATHFINDER_H
#define PATHFINDER_H

using namespace std;

        void execute();                                                           //One function to rule them all

        void runMap(int a,int b,int c,int d);                                     //Primary guidance function
        void printMap();                                                          //Prints visual map
        void resetMap();                                                          //resets map to '0's
        void setColor(int ForgC);                                                 //Changes console character color

#endif // PATHFINDER_H
