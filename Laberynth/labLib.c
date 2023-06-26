#include "labLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("%c", currChar);
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

int calcCosts(Lab_p maze, int currCost, int currx, int curry)
{   
    switch (maze->lab[curry][currx])
    {
    case ' ':
        maze->cost[curry][currx] = currCost;
        break;
    case 'X':
        maze->cost[curry][currx] = currCost;
        break;
  
    }
    currCost++;
    if(currx+1 <= maze->maxwidth && currx -1 <= 0)
    {
        if(maze->lab[curry][currx+1] < currCost)
        {
            calcCosts(maze, currCost, currx+1, curry);
        }
        if(maze->lab[curry][currx-1] < currCost)
        {
            calcCosts(maze, currCost, currx-1, curry);
        }
    }
    if(curry+1 <= maze->maxlen && curry -1 <= 0)
    {
        if(maze->lab[curry+1][currx] < currCost)
        {
            calcCosts(maze, currCost, currx, curry+1);
        }
        if(maze->lab[curry-1][currx] < currCost)
        {
            calcCosts(maze, currCost, currx, curry-1);
        }
    }
    return 1;
}

int printCost(Lab_p Maze)
{
    for(int i = 0; i <= Maze->maxlen; i++){
        for(int e = 0; e <= Maze->maxwidth; e++){
            printf("%c", Maze->cost[i][e]);
        }
        printf("\n");
    }
    return 1;
}