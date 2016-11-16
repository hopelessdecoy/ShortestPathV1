/*
    This page is used for storing experimental code to possibly improve/clean up the original program.

    WARNING!!! Code on this page is not expected to be good, good looking or even working.
               Code on this page is also not compiled.
*/



switch(){
step1:  //Diagonal down right movement
            case xAxis< destinationX && yAxis< destinationY:
                xAxis++;
                yAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;

step2:  //Diagonal up left movement
            case xAxis> destinationX && yAxis> destinationY:
                xAxis--;
                yAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;

step3:  //Diagonal down left movement
            case xAxis> destinationX && yAxis< destinationY:
                xAxis--;
                yAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;

step4:  //Diagonal up right movement
            case xAxis< destinationX && yAxis> destinationY:
                xAxis++;
                yAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;

step5:  //Right movement
            case xAxis< destinationX:
                xAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;

step6:  //Left movement
            case xAxis> destinationX:
                xAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;

step7:  //Up movement
            case yAxis< destinationY:
                yAxis++;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;

step8:  //Down movement
            case yAxis> destinationY:
                yAxis--;
                moveCounter++;
                pathMap[xAxis][yAxis]+= 1;
                continue;
            }
