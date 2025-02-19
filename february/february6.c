// NOTES 2/6
// LINKED LIST STACKS

/*

LINKED LIST STACKS
- Used linked lists instead of the items array
- Basically insertFront and deleteFront functions are applied and our stack is just a node

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;

} node;

node * createNode(int val) {
    node * n = malloc(sizeof(node));
    n->data = val;
    n->next = NULL;
    return n;

}

node * pop(node * root) {
    if(root==NULL) {
        root = NULL;
        return root;

    }
    node * temp = root;
    root = root->next;
    free(temp);

    return root;

}

node * push(node * root, int val) {
    node * newNode = createNode(val);

    if(root==NULL) {
        root=newNode;
        return root;

    }

    newNode->next=root;
    root=newNode;

    return root;

}

void display(node * root) {

    printf("LINKED LIST STACK\n");

    if(root==NULL) {
        printf("EMPTY\n\n");
        return;
    }

    node * cur = root;
    while(cur!=NULL) {
        printf("%d ", cur->data);
        cur=cur->next;
    }

    printf("\n\n");

}

int main() {

    node * root = NULL;

    int input;

    int stop = 0;

    // Menu
	while(stop!=1)
	{
		printf("Menu:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Instruction: ");
	    scanf("%d", &input);
        printf("\n");

        int value;
        switch(input) {
            case (1):
                printf("Enter value: ");
                scanf("%d", &value);
                root = push(root, value);
                display(root);
                break;

            case (2):
                root = pop(root);
                display(root);
                break;

            case (3):
                display(root);
                break;

            case (4):
                stop=1;
                break;
            
        }
    
    }


}