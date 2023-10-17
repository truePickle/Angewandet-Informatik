#include <stdio.h>
#include "vierGewinnt.h"

int main(int argc,char **argv)
{
    
    printf("created Array\n");
    field board = initField();
    printf("init Array\n");
    printField(board);
    printf("finished \n");
    return 1;
}