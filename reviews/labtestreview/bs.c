#include <stdio.h>
#include <stdlib.h>


int binarySearch(int * arr, int size, int val) {
    int high = size-1;
    int low = 0;
    int mid;
    int found = 0;

    while(low<=high) {
        mid = (low+high)/2;
        if(arr[mid]==val) {
            found=1;
            return mid;

        } else if(val<arr[mid]) {
            high = mid-1;

        } else {
            low = mid+1;

        }


    }
    if(found==0) {
        return -1;

    }
    
    return mid;

}