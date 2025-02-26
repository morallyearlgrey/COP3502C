#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;

} node;

typedef struct llqueue {
    struct node * front;
    struct node * rear;

} llqueue;

typedef struct cqueue {
    int items[10];
    int front;
    int rear;
    int noe;

} cqueue;

void displayQueue(cqueue * q) {
    printf("Queue: ");
    int i = q->front;
    for (int c = 0; c < q->noe; c++) {
        printf("%d ", q->items[i]);
        i = (i + 1) % 10; // Circular increment
    }
    printf("\n");

}

void enqueue(cqueue * q, int val) {
    if(q->noe==10) {
        printf("FULL\n");

    } else {
        if(q->front==-1) {
            q->front=0;
            q->rear=0;

        } else {
            q->rear = (q->rear+1)%10; // or q->rear = (q->front+q->noe)%10;

        }
        q->items[q->rear]=val;
        q->noe+=1;

    }

}

int dequeue(cqueue * q) {
    int val = q->items[q->front];
    q->front=(q->front+1)%10;
    q->noe-=1;
    return val;

}

int pop(llqueue * queue) {
    if((queue->front)==NULL) {
        return -1;

    }

    if(queue->front==queue->rear) {
        node * del = queue->front;
        (queue->front)=(queue->front)->next;
        queue->rear=queue->rear->next;
        int val = del->val;
        free(del);
    
        return val;

    }

    node * del = queue->front;
    (queue->front)=(queue->front)->next;
    int val = del->val;
    free(del);

    return val;


}

llqueue * push(llqueue * queue, int val) {
    node * newNode = malloc(sizeof(node));
    newNode->val=val;
    newNode->next=NULL;

    if((queue->front)==NULL) {
        (queue->front)=newNode;
        (queue->rear)=newNode;
        return queue;

    }

    queue->rear->next=newNode;
    queue->rear=newNode;
    return queue;

    // while((queue->front)->next!=NULL) {
    //     (queue->front)=(queue->front)->next;

    // }

    // (queue->front)->next=newNode;
    // return queue;


}

void display(llqueue * queue) {
    node * cur = queue->front;
    if(cur==NULL) {
        printf("EMPTY\n\n");
        return;
    }

    while(cur!=NULL) {
        printf("%d ", cur->val);
        cur=cur->next;
    }

    printf("\n\n");

}

int main () {

    cqueue * c = malloc(sizeof(cqueue));
    c->front=-1;
    c->rear=-1;
    c->noe=0;

    llqueue * queue = malloc(sizeof(llqueue));
    node * node = NULL;
    queue->front= node;
    queue->rear= node;

    int input;

    int stop = 0;

    // Menu

    printf("Menu:\n1. Circular Queue\n2. Linked List Queue\n");
    scanf("%d", &input);
    switch(input) {
        case 1:
            while(stop!=1)
            {
                printf("Menu:\n0. Exit\n1. Push\n2. Pop\n");
                printf("Instruction: ");
                scanf("%d", &input);
                printf("\n");
        
                int data;
                int index;
        
                // Get input and pass along to functions based off input
                switch(input) {
                    // QUIT
                    case(0):
                        printf("\nGOOD BYE>>>>");
                        stop=1;
                        break;
        
                    case(1):
                        printf("PUSH:\n");
                        printf("Enter integer: ");
                        scanf("%d", &data);
                        queue = push(queue, data);
                        display(queue);
        
                        break;
        
                    case(2):
                        printf("POP:\n");
                        int val = pop(queue);
                        printf("Returned: %d\n", val);
                        display(queue);
        
                        break;
                    
                
                }
        
        
            }
            break;

        case 2:
            while(stop!=1) {
                printf("Menu:\n0. Exit\n1. Push\n2. Pop\n");
                printf("Instruction: ");
                scanf("%d", &input);
                printf("\n");
        
                int data;
                int index;

                switch(input) {
                    // QUIT
                    case(0):
                        printf("\nGOOD BYE>>>>");
                        stop=1;
                        break;
        
                    case(1):
                        printf("PUSH:\n");
                        printf("Enter integer: ");
                        scanf("%d", &data);
                        enqueue(c, data);
                        displayQueue(c);
                        break;
        
                    case(2):
                        printf("POP:\n");
                        int val = dequeue(c);
                        printf("Returned: %d\n", val);
                        displayQueue(c);
                        break;
                    
                
                }

            }
            break;
    }

	

}