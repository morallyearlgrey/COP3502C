// NOTES 2/10

/*
BINARY SEARCH:
- Runs in O of log n
- Keeps on halfing lists until it finds the value

SLMP (Sorted List Matching Problem):
- Given two sorted lists, output the numbers common to both lists

*/

#include <stdio.h>

int binarySearch(int * list, int item, int len) {
    int low = 0;
    int high = len-1;
    int mid;
    while(low<=high) {
        mid = (low+high)/2;

        if(list[mid]==item) {
            return mid;
        }

        if(list[mid]<item) {
            low = mid + 1;

        } else {
            high = mid-1;

        }

    }
    return -1;

}

int recursiveBinSearch(int * list, int low, int high, int item) {
    if(low<=high) {
        int mid=(low+high)/2;
        if(item < list[mid]) {
            recursiveBinSearch(list, low, mid+1, item);

        } else if(item > list[mid]) {
            recursiveBinSearch(list, mid-1, high, item);

        } else {
            return mid;
        }

    }
    return -1;

}

