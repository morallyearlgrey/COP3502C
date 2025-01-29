// NOTES 1/29

/*
ARRAY QUEUE:
- All items are NOT removed, still remain in the queue
- However, there is a rear and front index for the front and back of the queue
- When you enqueue, the front is ++ and when you dequeue, the rear is ++
- When front and rear are equal, that means that there is nothing in the queue

LINEAR QUEUE:
- Linear queue size increases with dequeue

CIRCLE QUEUE:
- Circle queue size DOES NOT increase with dequeue
- Use (front+size)%size to get the index to place the item at the beginning/needed index if the list is ful;

*/

#define MAX 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {

    int arr[MAX];
    int rear;
    int front;

} queue;


typedef struct cQueue {
    int arr[MAX];
    int numElements;
    int size;
    int front;

} cqueue;

void init(queue * q) {
    q->front=0;
    q->rear=0;

}

void enqueue(queue *q, int val) {
    if(q->rear>=MAX) {
        printf("FULL\n");
        return;

    }

    q->arr[q->rear]=val;
    q->rear++;

}

int dequeue(queue *q) {
    if(q->front==q->rear) {
        printf("EMPTY\n");
        return -1;

    }
    int saveFront = q->arr[q->front];
    q->front++;
    return saveFront;

}

void display(queue *q) {
    if(q->front==q->rear) {
        printf("EMPTY\n");
        return;

    }


    for(int i=q->front; i<q->rear; i++) {
        printf("%d\n", q->arr[i]);

    }

}

int main() {

    queue q;
    init(&q);

    char * input;
    int val;
    int val2;

    while(strcmp(input, "end")!=0) {
        printf("Enter menu item: ");
        scanf("%d", &val);
        switch(val) {
            case 1:
                init(&q);
                break;
            
            case 2:
                printf("Enter value: ");
                scanf("%d", &val2);
                enqueue(&q, val2);
                break;

            case 3:
                printf("Returned: %d\n", dequeue(&q));
                break;

            case 4:
                display(&q);
                break;

        }

    }


    return 0;

}