#include "labLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

int checkLab(FILE *Lab, int *maxWid, int *maxLeng){
    bool hasEnd = false;
    bool hasStart = false;
    int maxLength = 0;
    int maxWidth = 0;
    int tempWidth = 0;
    
    char currChar;

    while((currChar = fgetc(Lab)) != EOF){
        
        if(currChar == '\n'){
            if(maxWidth < tempWidth){
                maxWidth = tempWidth;
            }
            maxLength++;
            tempWidth = 0;
        }
        else{
            tempWidth++;

            if(currChar == 'X')
            {  
                if(hasEnd){
                    return 0;
                }
                hasEnd = true;
            }
            else if (currChar == 'S')
            {
                if(hasStart){
                    return 0;
                }
                hasStart = true;
            }
        }
    }

    *maxWid = maxWidth;
    *maxLeng = maxLength; 
    rewind(Lab);
    return 1;
    
}

Lab_p createLab(FILE *Lab, int maxWid, int maxLen){

    char currChar;
    int xindex=0;
    int yindex=0;
    Lab_p Maze;
    Maze = malloc(sizeof(LabCell));
    Maze->maxlen = maxLen;
    Maze->maxwidth = maxWid;

    while((currChar = fgetc(Lab)) != EOF){
        if(currChar == '\n'){
            yindex++;
            xindex = 0;
        }
        else{

            if(currChar == 'X')
            {  
                Maze->endx = xindex;
                Maze->endy = yindex;
            }
            else if (currChar == 'S')
            {
                Maze->startx = xindex;
                Maze->starty =yindex;
            }
            Maze->lab[yindex][xindex] = currChar;
            xindex++;

        }
    }
    rewind(Lab);
    return Maze;
}
int printLab(Lab_p Maze)
{
    for(int i = 0; i <= Maze->maxlen; i++){
        for(int e = 0; e <= Maze->maxwidth; e++){
            printf("%c", Maze->lab[i][e]);
        }
        printf("\n");
    }
    return 1;
}

void calcCosts(Lab_p maze, int currCost, int currx, int curry)
{   
    switch (maze->lab[curry][currx])
    {
    case ' ':
        maze->cost[curry][currx] = currCost;
        break;
    case 'S':
        maze->cost[curry][currx] = 0;
        break;
    case '#':
        maze->cost[curry][currx] = 999;
        return;
    case 'X':
        maze->cost[curry][currx] = currCost;
        break;
  
    }
    currCost++;
    if(currx+1 <= maze->maxwidth && currx -1 >= 0)
    {
        if(maze->cost[curry][currx+1] > currCost)
        {
            calcCosts(maze, currCost, currx+1, curry);
        }
        if(maze->cost[curry][currx-1] > currCost)
        {
            calcCosts(maze, currCost, currx-1, curry);
        }
    }
    if(curry+1 <= maze->maxlen && curry -1 >= 0)
    {
        if(maze->cost[curry+1][currx] > currCost)
        {
            calcCosts(maze, currCost, currx, curry+1);
        }
        if(maze->cost[curry-1][currx] > currCost)
        {
            calcCosts(maze, currCost, currx, curry-1);
        }
    }
    //unten Links
    if(curry+1 <= maze->maxlen && currx -1 >= 0)
    {
        if(maze->cost[curry+1][currx-1] > currCost)
        {
            calcCosts(maze, currCost, currx-1, curry+1);
        }
    }
    //oben Links
    if(curry-1 >= 0 && currx -1 >= 0)
    {
        if(maze->cost[curry-1][currx-1] > currCost)
        {
            calcCosts(maze, currCost, currx-1, curry-1);
        }
    }
    //unten rechts
    if(curry+1 <= maze->maxlen && currx +1 <= maze->maxwidth)
    {
        if(maze->cost[curry+1][currx+1] > currCost)
        {
            calcCosts(maze, currCost, currx+1, curry+1);
        }
    }
    //oben Rechts
    if(curry-1 >= 0 && currx +1 <= maze->maxwidth)
    {
        if(maze->cost[curry-1][currx+1] > currCost)
        {
            calcCosts(maze, currCost, currx+1, curry-1);
        }
    }
    return;
}

int printCost(Lab_p Maze)
{
    for(int i = 0; i <= Maze->maxlen; i++){
        for(int e = 0; e <= Maze->maxwidth; e++){
            printf("%03d ", Maze->cost[i][e]);
        }
        printf("\n");
    }
    return 1;
}


int initCost(Lab_p Maze){
    for(int i = 0; i <= Maze->maxlen; i++){
        for(int e = 0; e <= Maze->maxwidth; e++){
            Maze->cost[i][e]=998;
        }
    }
    return 1;
}

void showWay(Lab_p Maze, int endx, int endy, bool printSteps)
{
    int currCost = Maze->cost[endy][endx];
    if(printSteps)
    {
        printLab(Maze);
        delay(3);
    }
    if(Maze->lab[endy][endx] == 'S')
    {
        printf("Maze solved\n");
        return;
    }
    else if(Maze->lab[endy][endx] != 'X')
    {
        Maze->lab[endy][endx] = '.';
    }

    //oben
    if(Maze->cost[endy-1][endx] == currCost-1)
    {
        showWay(Maze, endx, endy-1, printSteps);
    }
    //unten
    else if(Maze->cost[endy+1][endx] == currCost-1)
    {
        showWay(Maze, endx, endy+1, printSteps);
    }
    //Links
    else if(Maze->cost[endy][endx-1] == currCost-1)
    {
        showWay(Maze, endx-1, endy, printSteps);
    }
    //Rechts
    else if(Maze->cost[endy][endx+1] == currCost-1)
    {
        showWay(Maze, endx+1, endy, printSteps);
    }
    //unten Links
    else if(Maze->cost[endy+1][endx-1] == currCost-1)
    {
        showWay(Maze, endx-1, endy+1, printSteps);
    }
    //oben Links
    else if(Maze->cost[endy-1][endx-1] == currCost-1)
    {
        showWay(Maze, endx-1, endy-1, printSteps);
    }
    //unten Rechts
    else if(Maze->cost[endy+1][endx+1] == currCost-1)
    {
        showWay(Maze, endx+1, endy+1, printSteps);
    }
    //oben Rechts
    else if(Maze->cost[endy-1][endx+1] == currCost-1)
    {
        showWay(Maze, endx+1, endy-1, printSteps);
    }
    else
    {
        printf("Maze is unsolvable\n");
    }
    return;
}
