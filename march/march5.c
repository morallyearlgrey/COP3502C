// NOTES 3/5

/*
Insertion Sort o(n^2):
- Like sorting books on your bookshelf
- Go through each index and compare with the previous book
- If less, swap and then keep on moving down the previous indices until you encounter a case where you don't need to swap
- Fast for small arrays

Selection Sort ():
- Find min and keep swapping  i+1 index

*/

#include <stdio.h>

void insertionSort(int * arr, int n) {
    int j;
    for(int i=1; i<n; i++) {
        int cur = arr[i];

        for(j=i-1; j>=0; j--) {
            if(arr[j]>cur) {
                arr[j+1]=arr[j];

            } else {
                break;

            }
            
        }
        arr[j+1]=cur;


    }

}

void selectionSort(int * arr, int n) {
    for(int i=0; i<n-1; i++) {
        int min = i;

        for(int j=i; j<n; j++) {
            if(arr[j]<arr[min]) {
                min=j;

            }

        }
        // swap arr[i] with arr[min]
        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]=temp;

    }

}