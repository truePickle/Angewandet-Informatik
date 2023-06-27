#ifndef LABLIB_H
#define LABLIB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Laberynth
{
    char lab[258][256];
    int cost[256][256];
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
void calcCosts(Lab_p maze, int currCost, int currx, int curry);
int printCost(Lab_p Maze);
int initCost(Lab_p Maze);
void showWay(Lab_p Maze, int endx, int endy, bool printSteps);

#endif