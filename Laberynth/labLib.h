#ifndef LABLIB_H
#define LABLIB_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Laberynth
{
    char lab[258][256];
    char cost[256][256];
    int maxwidth;
    int maxlen;
    int startx;
    int starty;
    int endx;
    int endy;

}LabCell, *Lab_p;

int checkLab(FILE *Lab, int *maxWid, int *maxLeng);
Lab_p createLab(FILE *Lab, int maxWid, int maxLen);
int printLab(Lab_p Maze);
int calcCosts(Lab_p maze, int currCost, int currx, int curry);
int printCost(Lab_p Maze);

#endif