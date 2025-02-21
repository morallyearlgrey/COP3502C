// NOTES 2/12
/*
ARRAY-BASED QUEUES:
- Use queues
- Circle queues use greyed out numbers
- Use % size to figure out "true" index

*/

#include <stdio.h>

typedef struct cqueue {
    char items[10];
    int front;
    int rear;
    int noe; // number of elements
    int size;

} cqueue;

void enqueue(cqueue * q, char ltr) {
    if(q->noe==q->size) {
        printf("FULL");
    } else {
        q->rear = ((q->front+q->noe)%q->size); // or q->rear = (q->rear+1)%size
        q->items[q->rear]=ltr;

    }

}

char dequeue(cqueue * q) {
    char value = q->items[q->front];
    q->front=(q->front+1)%q->size;
    return value;

}