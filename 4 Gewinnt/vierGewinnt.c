#include <stdio.h>
#include <stdlib.h>
#include "vierGewinnt.h"

field initField()
{
    field board = malloc(sizeof(char)*6);
    
    int i,j =0;
    
    for(i = 0; i < 6; i++)
    {
        board[i] = malloc(sizeof(char)*7);
        for(j = 0; j < 7; j++)
        {
            board[i][j] ='*';
        }
    }
    return board;
}
void printField(field board)
{
    int i,j =0;

    for(i = 0; i< 6; i++)
    {
        printf("|");
        for(j = 0; j < 7; j++)
        {
            printf("%c", board[i][j]);
        }
        
        printf("|\n");
    }
    printf("+");
    for(i = 0; i<= 6; i++)
    {
        printf("=");
    }
    printf("+\n");
    
    return;
}