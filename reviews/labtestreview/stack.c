#include <stdio.h>

typedef struct stack {
    int items[10];
    int top;

} stack;

int push(stack * s, int val) {
    if(s->top==10-1) {
        return -1;
    }
    s->top+=1;
    s->items[s->top]=val;
    return 1;

}

int pop(stack * s) {
    if(s->top==-1) {
        return -1;
    }
    int val = s->items[s->top];
    s->top-=1;
    return val;


}

