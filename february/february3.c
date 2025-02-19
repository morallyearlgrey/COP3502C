// NOTES 2/3
// ARRAY STACKS

/*
STACK
- Last in, first out
- Like a stack of pancakes
- Implemented through array or linked list
- Can be used for the parenthesis leetcode question ({]})

STACK FUNCTIONS
- Push (add item to top)
- Pop (get and remove item added most recently)
- IsEmpty (see if the stack is empty)
- IsFull (see if stack is full)
- Peek (look at the most recently added item)

STACK ARRAY IMPLEMENTATION
- Uses an items array

*/

#include <stdio.h>

// stack struct with array implementation
typedef struct stack {
    int items[10]; // array of items
    int top; // index for top

} stack;

// sees if the stack's index is equal to size-1
int full(struct stack* stackPtr) {
    return (stackPtr->top == 10-1); // size minus 1
}

// sees if stack's index is -1
int empty(struct stack* stackPtr) {
    return (stackPtr->top == -1);

}

// sets new stack
void initialize(stack * s) {
    s->top=-1;

}

// pushes a val onto a stack using an index
int push(stack * s, int val) {

    if(full(s)) {
        return -1;
    }

    s->items[s->top+1]=val;
    s->top+=1;
    return 1;

}

// gets rid of top value
int pop(stack *s) {
    if (empty(s)) {
        return -1;  
    }

    int val = s->items[s->top]; 
    s->top -= 1; 
    return val;  

}

// returns top value
int peek(struct stack* stackPtr) {
    if (empty(stackPtr))
        return -1;
    return stackPtr->items[stackPtr->top];

}

// prints the entire stack
void display(struct stack* stackPtr) {
    printf("\nPrinting the Current stack...");
    for(int i=0; i<=stackPtr->top; i++) {
        printf("%d ", stackPtr->items[i]);
    }
}

// lets us control the stack and test it
int main() {
    int i;
    stack s;
    //declare a stack
    // Set up the stack and push a couple items, then pop one.
    initialize(&s); //call this function appropriately
    int ele;
    int ch;
    while(1)
    {
        printf("\nMenu:\n 1: Stack 1 push\n 3: Stack 1 Pop\n \n 5: Stack 1 display\n 7: Exit\nEnter your choice: ");
        scanf("%d",&ch);

        if(ch==7) {
            printf("<<EXIT>>");
            break;
        } else if (ch==1) {
            printf("Enter an element to PUSH in the stack1: ");
            scanf("%d",&ele);
            push(&s, ele);

        } else if (ch==3) {
            ele = pop(&s);
            if(ele!=0 ) {
                printf(" ITEM POPPED from Stack 1: %d ",ele);
                display(&s);
        
            }
        } else if(ch==5) {
            display(&s);

        } 

    }
    return 0;


}