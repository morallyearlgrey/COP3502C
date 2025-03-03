// NOTES 3/3

/*
SORTING:
- Where numbers are arranged in an order
- Selection, Bubble, Insertion, Merge, Quick, Heap sorting methods will be taught
- VISUALIZATION => https://www.hackerearth.com/practice/algorithms/sorting/

Merge Sort O(nlog(n))
- Divides the array recursively into two halves until no more ability to be divided
- Each subarray is sorted individually
- The subarrays are then merged together in sorted order
- Logic => Base case of "if list is 0 or 1 length" 
- Sorts after dividing subarrays by comparing the first element of the subarray to the first element of another subarray and then you add it to a sorted array

Bubble Sort O(n^2):
- Not optimal for big lists o(n^2) runtime 
- Swaps and compares adjacent elements 
- Goes through first to last

*/

#include <stdio.h>
#include <stdlib.h>

// left, right, mid are all indices

void merge(int * arr, int left, int mid, int right) {
    // set sizes of the arrays
    int sizeLeft = mid - left + 1; 
    int sizeRight = right - mid;

    // allocate memory to the left and right arrays
    int * L = malloc(sizeLeft * sizeof(int));
    int * R = malloc(sizeRight * sizeof(int));

    // add stuff to the arrays
    for(int i=0; i<sizeLeft; i++) {
        L[i]=arr[left+i];

    }

    for(int i=0; i<sizeRight; i++) {
        R[i]=arr[right+i];

    }

    int i = 0;
    int j = 0;
    int k = left;

    while ( i<sizeLeft && j<sizeRight) {
        if(L[i]<R[j]) {
            arr[k]=L[i];
            i++;
            k++;
    
        } else {
            arr[k]=R[j];
            j++;
            k++;
    
        }

    }

    while(i<sizeLeft) {
        arr[k]=L[i];
        i++;
        k++;

    }

    while(j<sizeRight) {
        arr[k]=R[j];
        j++;
        k++;

    }

    free(L);
    free(R);
    
}

// unfinished lol
void mergeSort(int * arr, int left, int right) {

    if(left<right) {
        int mid = (left+right)/2;
        mergeSort(arr,left, right);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

}

int main() {

    return 0;

}