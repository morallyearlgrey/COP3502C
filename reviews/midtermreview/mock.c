#include <stdio.h>
#include <stdlib.h>

struct queue {
    int* elements;
    int front;
    int noe;
    int queueSize;
   };


void divBy10(int arr[], int n) {
    if(n==0) {
        if(arr[n]%10==0) {
            printf("%d ", arr[n]);
        }
        return;
    }

    divBy10(arr, n-1);
    if(arr[n]%10==0) {
        printf("%d ", arr[n]);
    }

}

int main() {

    int arr[] = {10, 33, 20, 12, 30};
    divBy10(arr, 5);

    struct queue q;
    q.queueSize=5;
    q.elements=malloc(sizeof(int)*q.queueSize);
    q.elements[0]=2;
    q.elements[1]=4;
    q.elements[2]=3;
    for(int i=0; i<q.queueSize; i++) {
        printf("%d ", q.elements[i]);

    }
    q.queueSize*=2;
    q.elements=realloc(q.elements, sizeof(int)*q.queueSize);

    for(int i=0; i<q.queueSize; i++) {
        printf("%d ", q.elements[i]);

    }
   

}