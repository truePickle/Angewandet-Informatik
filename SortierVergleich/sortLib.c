#include "sortLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fillArr(FILE *in, int *list, int *length)
{
    printf("reading numbers\n");
    for (; fscanf(in, "%d", &list[*length]) != EOF; *length= *length +1);

    printf("finished reading\n");

}

bool checkSorted(int *list, int length, bool (*comp)(int, int))
{
    int lastNum = list[0];
    for (int i = 1; i < length; i++)
    {
        if(comp(lastNum, list[i]) == false)
        {
            //printf("lastNum:%d secondNum:%d\n", lastNum, list[i]);
            return false;
        }
        lastNum = list[i];
    }
    return true;
    
}
void printList(int *list, int length)
{
    for(int i =0; i<length; i++)
    {
        printf("%d\n", list[i]);
    }
}

bool bubleSortList(int *list, int length, bool (*comp)(int, int))
{
    int temp;
    for(int j = 0; j<length-1; j++)
    {
        for(int i = 1; i <length; i++)
        {
            if(comp(list[i-1], list[i]) == false)
            {
                temp = list[i-1];
                list[i-1] = list[i];
                list [i] = temp;
            }
        }
    }
    return true;
}

bool compare(int a, int b)
{
    if(a <= b)
    {
        return true;
    }
    return false;
}

void mergeSort(int arr[], int lLeng, int rLeng, bool (*comp)(int, int))
{
    if (lLeng < rLeng) {
        int m = lLeng + (rLeng - lLeng) / 2;
 
        // Sort first and second halves
        mergeSort(arr, lLeng, m, compare);
        mergeSort(arr, m + 1, rLeng, compare);
 
        merge(arr, lLeng, m, rLeng);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            arr[k] = L[i];
            i++;
            }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void copyArr(int *toCopylist, int *list, int length) {

    int i=0;
    for(i=0; i<length; i++){
        list[i] = toCopylist[i];
    }
    return;

}
//heap Sort
// Function to swap the the position of two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
  void heapify(int arr[], int len, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < len && arr[left] > arr[largest])
      largest = left;
  
    if (right < len && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, len, largest);
    }
  }
  
  void heapSort(int arr[], int len) {
    // Build max heap
    for (int i = len / 2 - 1; i >= 0; i--)
      heapify(arr, len, i);
  
    // Heap sort
    for (int i = len - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

//bottomUpMerge
int min(int a, int b)
{
    return (a < b) ? a : b;
}

void bottomMerge(int *list, int length)
{
    int width, j =0;
    for(width=1; width <= length; width=width*2)
    {
        for(j=0; j <= length+width; j=j+2*width)
        {
            merge(list, j, min(j+width, length), min(j+2*width, length));
        }
    }
}