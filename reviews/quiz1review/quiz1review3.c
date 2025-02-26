#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_null.h>

typedef struct node {
    int data;
    struct node * next;

} node;

typedef struct lQueue {
    struct node * front;
    struct node * back;

} lQueue;

typedef struct aQueue {
    int arr[5];
    int front;
    int back;

} aQueue;

void ainit (aQueue * q) {
    q->front=0;
    q->back=0;

}

int adequeue(aQueue * q) {
    if(q->front==0 && q->back==0) {
        return -1;
    }

    int returnVal = q->arr[q->front];
    q->front+=1;
    return returnVal;

}

aQueue * aenqueue (aQueue * q, int val) {
    if(q->back==5) {
        return q;
    }

    q->arr[q->back] = val;
    q->back+=1;
    return q;

}

void init (lQueue *q) {
    q->front=0;
    q->back=0;

}

int dequeue(lQueue * q) {
    if(q->front==q->back) {
        return -1;
    }

    int returnVal = q->front->data;
    node * n = q->front;
    q->front=q->front->next;
    free(n);
    return returnVal;


}

lQueue * enqueue (lQueue * q, int val) {
    node * n = malloc(sizeof(node));
    n->data = val;
    n->next= NULL;
    q->back->next=n;
    q->back=n;
    return q;

} 

int main () {


}