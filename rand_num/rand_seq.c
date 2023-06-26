#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000

int main(int argc, char *argv[])
{
    if(argc == 3)
    {

        int anzahl;

        anzahl = atoi(argv[1]);
        srandom(atoi(argv[2]));

        for(int i = 0; i<anzahl; i++)
        {
            printf("%ld\n", random()%MAXNUM); 
        }
    }
    else
    {
        fprintf(stderr, "Usage: %s [numOfRand] [Seed]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}