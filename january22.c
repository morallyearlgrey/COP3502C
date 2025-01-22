// NOTES 1/22
/*
LINKED LISTS:
- Sequence of connected nodes containing data items
- Data items point to another data item
- Singly linked lists (forward navigation) x -> x -> x
- Doubly linked lists (forward and backward navigation) x -> <- x -> <- x
- Circular linked lists (last item contains link of the first item and vice versa)

WHY USE LINKED LISTS:
- Arrays are fixed and it's difficult to insert items (995 items would need to be shifted for instance in an array of 1000 when you're inserting a 5th item)
- Each node in an array is stored in contigious spaces
- Dynamic, length can be increased/decreased
- Insertion and deletion is EASY and CHEAP

BASIC OPERATIONS:
- Insertion (adding an item)
- Deletion (deletes an item)
- Display (displays the complete list in a forward manner)
- Search (look for a given item)

NODE:
- Has info (holds the data you want) and link (a pointer) to the next node

HEAD:
- Pointer pointing to the first node
- First "node" in the linked list
- If you lose the head, you lose the list

INSERTION OF LINKED LISTS:
1. Create a temporary node with data and next
2. Look for position where to insert
3. Link the temporary node into the list
- Check to make sure head is NOT null (make sure there is content)

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;

} node; 

void display(node*t) {
    printf("Linked List:\n");
    while(t->next!=NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
    printf("%d", t->data);
}

node * createNode(int item) {
    node * temp = malloc(sizeof(node));
    temp->data=item;
    temp->next=NULL;
    return temp;

}

node * insertFront(node*head, int item) {
    node * temp = createNode(item);
    // No linked list?
    if(head==NULL) {
        head = temp; // Point head to temp
        return head;

    // Already have linked list?
    } else {
        temp->next=head; // make temp point to whatever head was pointing to
        head=temp; // make head point to temp
        return head; // return head

    }

}

node * insertEnd(node * head, int item) {
    node * temp = createNode(item);
    if(head==NULL) {
        head = temp;
        return head;

    } else {
        node * walker = head;
        while(walker->next) { // while walker's next exists
            walker=walker->next; // make walker next node
        }
        walker->next=temp; // point to new node
        return head;

    }

}

// Insert into a sorted list
node * insertSorted(node * head, int item) {
    node * temp = createNode(item);
    if(head == NULL || head->data>item) { // NULL must be asked first due to short circuit evaluation
        temp->next = head;
        head = temp;
    } else {
        node * walker = head;
        while(walker->next != NULL && walker->data<item) {
            walker = walker->next;
        }
        temp->next = walker->next; // Make temp point to whatever walker was originally pointing to (DON'T FORGET TO CONNECT TO THE NEXT ITEM IN LINE AFTER THE INSERT, don't half the linked list)
        walker->next=temp; // Now make walker point to temp

    }
    return head;

}

int main() {
    node * root = NULL; // NULL is important, you need it or else it won't work
    root = insertFront(root, 5);
    root = insertFront(root, 10);
    display(root);
    
    // Skips the last item because the last item's next is NULL

    return 0;
}