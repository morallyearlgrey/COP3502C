// NOTES 1/24
/*

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node * next;

} node;

typedef struct doubleNode {
    int info;
    struct doubleNode * prev, * next; 
} node2; // double nodes

node * delete(node * head, int num) {
    if(head==NULL) {
        return NULL;

    } else if(num==head->info)  {
        node * delete = head;
        head = head->next;
        free(delete);
        return head;

    } else {
        node * walk = head;
        while(walk->next!=NULL && walk->next->info!=num) {
            walk=walk->next;

        }
        if(walk->next==NULL) {
            return head;
        }

        node * delete = walk->next;
        walk->next=walk->next->next;
        free(delete);
        return head;

    }

}

int main() {


    return 0;
}