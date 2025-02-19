// NOTES 1/27
/*

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;

} node;

node * createNode(int data) {
    node * temp = malloc(sizeof(node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}

node * insertFront(node *head, int data) {
    node * node = createNode(data);
    
    node->next = head; // connects regardless if the head is null or not
    
    if(head) {
        head->prev=node;
    }
    head = node;
    return head;

}

node * insertEnd(node *head, int data) {
    node * n = createNode(data);
    if(!head) {
        head = n;
        return head;

    } else {
        node * w = head;
        while(w->next) {
            w = w->next;
        }
        n->prev = w;
        w->next = n;
        return head;


    }

}

void display(node* t)
{
    printf("\nPrinting your link list.......");
    while(t!=NULL)
    {
    printf("%d ",t->data);
    t=t->next;
    }
}

int main() {
    node * root = NULL;
    node *t,del;
    int ch,ele,v;
    while(1)
    {
        printf("\nMenu: 1. insert at front, 2. insert at end, 3. Delete 4. exit: ");
        scanf("%d",&ch);
    if(ch==4)
    {
        printf("\nGOOD BYE>>>>\n");
        break;
    }
    if(ch==1)
    {
        printf("\nEnter information(an integer): ");
        scanf("%d",&ele);
        root = insertFront(root, ele);
        display(root);
    }
    if(ch==2)
    {
        printf("\nEnter information(an integer): ");
        scanf("%d",&ele);
        root = insertEnd(root, ele);
        display(root);
    }
    // if(ch==3)
    // {
    // printf("\nEnter info which u want to DELETE: ");
    // scanf("%d",&ele);
    // root=DelListDoubly(root, ele);
    // display(root);
    // }
    }
    return 0;

}