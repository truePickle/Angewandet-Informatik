#ifndef SORTLIB_H
#define SORTLIB_H
#include <stdio.h>
#include <stdbool.h>

void fillArr(FILE *in, int *list, int *length);
bool checkSorted(int *list, int length, bool (*comp)(int, int));
void printList(int *list, int length);
bool bubleSortList(int *list, int length, bool (*comp)(int, int));
bool compare(int a, int b);
void mergeSort(int arr[], int lLeng, int rLeng, bool (*comp)(int, int));
void merge(int *list, int l, int m, int r);
void copyArr(int *toCopylist, int *list, int length);
void swap(int *a, int *b);
void heapify(int arr[], int len, int i);
void heapSort(int arr[], int len);
int min(int x, int y);
void bottomMerge(int A[], int temp[], int from, int mid, int to);
void BottomMergesort(int A[], int temp[], int low, int high);

#endif