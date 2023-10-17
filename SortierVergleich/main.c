#include "sortLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );}

int main(int argc, char *argv[])
{
    FILE *in = NULL;
    bool buble = false;
    bool merge = false;
    bool heap = false;
    bool quick = false;
    bool bottom = false;

    /*
    in = fopen("longList.txt", "w");
    srand(4156848564);
    for(int i = 0; i<=1000000; i++)
    {
        fprintf(in, "%d\n", rand());
    }
    return 0;
    */
    

    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s [<file>] [<sort method(buble/merge \n", argv[0]);
        exit(EXIT_FAILURE);
    }   
    if(argc == 3)
    {
        in = fopen(argv[1], "r");
        if(!in)
        {
            perror(argv[1]);
            printf("File not readable\n");
            exit(EXIT_FAILURE);
        }
        if(strcmp(argv[2], "buble")==0)
        {
            buble = true; 
        }
        else if(strcmp(argv[2], "merge")==0)
        {
            merge = true;
        }
        else if(strcmp(argv[2], "heap")==0)
        {
            heap = true;
        }
        else if(strcmp(argv[2], "quick")==0)
        {
            quick = true;
        }
        else if(strcmp(argv[2], "bottom")==0)
        {
            bottom = true;
        }
        
        
    }
    int list[1000000];
    //int temp[1000000];
    int length = 0;

    fillArr(in , list, &length);
    if(buble){
        clock_t timeBeforeBuble = clock();
        bubleSortList(list, length, compare);
        clock_t timeAfterBuble = clock();
        double timeToSortBuble = ((double)timeAfterBuble - timeBeforeBuble)/CLOCKS_PER_SEC;

        if(checkSorted(list, length, compare) ==true)
        {
            printf("list is sorted\n");
        }
        else
        {
            printf("list is not sorted\n");
        }
        printf("Time to bubleSort:%f\n", timeToSortBuble);
    }
    else if(merge)
    {
        clock_t timeBefore = clock();
        mergeSort(list, 0, length-1, compare);
        clock_t timeAfter = clock();
        double timeToSort = ((double)timeAfter - timeBefore)/CLOCKS_PER_SEC;

        if(checkSorted(list, length, compare) ==true)
        {
            printf("list is sorted\n");
        }
        else
        {
            printf("list is not sorted\n");
        }
        printf("Time to mergeSort:%f\n", timeToSort);
    }
    else if(heap)
    {
        clock_t timeBefore = clock();
        heapSort(list, length);
        clock_t timeAfter = clock();
        double timeToSort = ((double)timeAfter - timeBefore)/CLOCKS_PER_SEC;

        if(checkSorted(list, length, compare) ==true)
        {
            printf("list is sorted\n");
        }
        else
        {
            printf("list is not sorted\n");
        }
        printf("Time to heapSort:%f\n", timeToSort);
    }
    else if (quick)
    {
        clock_t timeBefore = clock();
        qsort(list, length, sizeof(int), cmpfunc);
        clock_t timeAfter = clock();
        double timeToSort = ((double)timeAfter - timeBefore)/CLOCKS_PER_SEC;

        if(checkSorted(list, length, compare) ==true)
        {
            printf("list is sorted\n");
        }
        else
        {
            printf("list is not sorted\n");
        }
        printf("Time to quickSort:%f\n", timeToSort);
    }
    else if (bottom)
    {
        clock_t timeBefore = clock();
        bottomMerge(list, length-1);
        clock_t timeAfter = clock();
        double timeToSort = ((double)timeAfter - timeBefore)/CLOCKS_PER_SEC;

        if(checkSorted(list, length, compare) ==true)
        {
            printf("list is sorted\n");
        }
        else
        {
            printf("list is not sorted\n");
        }
        printf("Time to bottomMergeSort:%f\n", timeToSort);
    }
    printList(list, length);
    

}