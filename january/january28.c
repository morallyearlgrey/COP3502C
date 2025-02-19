// NOTES 1/27
/*
QUEUE
- First in first out data type
- Anything removed is taken from the front
- Things are removed in the same order that they were inserted
- Applied in Breadth First Search too

QUEUE OPERATIONS:
- enQueue (add an item at the BACK)
- deQueue (get and remove from the front)
- isEmpty (see if queue is empty)
- isFull (see if queue is full)
- Peek (get the element at the front of the queue without removing it)

QUEUE IMPLEMENTATION:
- Arrays or linked lists

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;

} node;

typedef struct queue {

    struct node *front;
    struct node * back;

} queue;

// checks if empty
int empty(queue * q) {
    if(q->front==NULL) {
        return 1;
    } else {
        return 0;
    }
}

// move front forward to next node
// save the node's data to an int return
// free node and return int
int dequeue(queue *q) {
    if(empty(q)) {
        return -1;
    }
    int saveData = q->front->data;
    node * n = q->front;
    q->front = q->front->next;
    free(n);

    // checks to make sure if we dequeue if it makes the queue empty
    if(empty(q)) {
        q->back=NULL;
    }

    return saveData;

}

int peek(queue * q) {
    if(q->front!=NULL) {
        return q->front->data;

    } else {
        return -1;

    }
}

// receives item and adds to the back
int enqueue(queue * q, int item) {
    node * n = malloc(sizeof(node));
    n->data = item;
    n->next = NULL; // we're putting it in the back so obv it's null
    
    if(empty(q)==1) {
        q->front = n;
        q->back = n;
        return 1;
    } 
    q->back->next = n;
    q->back = n;
    return 1; // 1 is just to return that we did it successfully

}

// Makes front and back null, resets queue
void init(queue * q) {
    q->front = NULL;
    q->back = NULL;

}

void display(queue * queue) {
    node * node = queue->front;
    if(queue->front==NULL) {
        printf("EMPTY\n");
        return;

    } 

    while(node!=NULL) {
        printf("%d ", node->data);
        node=node->next;
    }

}

int main() {
    queue * qarr = malloc(sizeof(queue)*3);
    queue q;
    init(&q);
    qarr[0]=q;

    queue q2;
    init(&q2);
    qarr[1]=q2;

    enqueue(&qarr[0], 2);
    enqueue(&qarr[1], 3);

    display(&qarr[1]);

    return 0;
}