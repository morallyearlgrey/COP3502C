// QUIZ 1
/*
linked lists:
deletion, insertion, insert at front, insert at end, reverse

queues:
dequeue, enqueue, arrays v linked lists, circular queues(1/29 lecture)?

*/

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

node * createNode(int val) {
    node * n = malloc(sizeof(node));
    n->data = val;
    n->next = NULL;
    return n;

}

node * insertFront(node * root, int val) {
    node * newNode = createNode(val);

    if(root==NULL) {
        root=newNode;
        return root;

    }

    newNode->next=root;
    root=newNode;

    return root;


}

node * insertEnd(node * root, int val) {
    node * newNode = createNode(val);

    if(root == NULL) {
        root=newNode;
        return root;

    }

    node * cur = root;
    while(cur->next!=NULL) {
        cur=cur->next;

    }

    cur->next=newNode;
    return root;

}

node * insertIndex(node * root, int val, int index) {
    node * newNode = createNode(val);
    
    if(root==NULL) {
        root = newNode;
        return root;

    } else if(index==0) {
        newNode->next = root;
        root = newNode;
        return root;
    }

    node * cur = root;
    int i = 0;

    while(cur->next!=NULL && i!=(index-1)) {
        cur=cur->next;
        i+=1;

    }
    newNode->next=cur->next;
    cur->next=newNode;
    return root;


}

node * insertPlace(node * root, int val, int index) {
    node * newNode = createNode(val);
    
    if(root==NULL) {
        root = newNode;
        return root;

    } else if(index==1) {
        newNode->next = root;
        root = newNode;
        return root;
    }

    node * cur = root;
    int i = 0;

    while(cur->next!=NULL && i!=(index-2)) {
        cur=cur->next;
        i+=1;

    }
    newNode->next=cur->next;
    cur->next=newNode;
    return root;

}

node * deleteFirst(node * root) {
    if(root==NULL) {
        root = NULL;
        return root;

    }

    root=root->next;
    return root;


}

node * deleteEnd(node * root) {
    node * cur = root;

    if(root==NULL) {
        root=NULL;
        return root;

    }

    while(cur->next->next!=NULL) {
        cur=cur->next;

    }
    cur->next = NULL;
    return root;

}

node * deleteIndex(node * root, int index) {
    if(root==NULL) {
        root = NULL;
        return root;

    } else if(index==0) {
        root = root->next;
        return root;

    }

    node * cur = root;

    int i=0;

    while(cur->next!=NULL && i!=(index-1)) {
        cur=cur->next;
        i+=1;

    }

    if(cur->next==NULL) {
        return root;
    }

    node * temp = cur;
    cur = cur->next;
    node * del = cur;
    temp->next = cur->next;
    free(del);
    return root;

}

node * deletePlace(node * root, int index) {
    if(root==NULL) {
        root = NULL;
        return root;

    } else if(index==1) {
        root = root->next;
        return root;

    }

    node * cur = root;

    int i=0;

    while(cur->next!=NULL && i!=(index-2)) {
        cur=cur->next;
        i+=1;

    }

    if(cur->next==NULL) {
        return root;
    }

    node * temp = cur;
    cur = cur->next;
    node * del = cur;
    temp->next = cur->next;
    free(del);
    return root;

}

node * reverseList(node * root) {
    node * reverse = NULL;
    node * cur = root;
    node * next = NULL;

    if(root==NULL) {
        return root;

    }

    while(cur!=NULL) {
        next = cur->next;
        cur->next = reverse;
        reverse = cur;
        cur = next;

    }

    return reverse;

}

node * copyList(node *root) {
    node * copy = malloc(sizeof(node));
    copy->data = root->data;
    copy->next=NULL;
    node * indx = copy;
    node * cur = root->next;

    while(cur!=NULL) {
        node * new = malloc(sizeof(node));
        new->data = cur->data;
        new->next = NULL;
        indx->next = new;
        indx = new;
        cur = cur->next;

    }
    
    return copy;


}

int checkSorted(node * root) {
    node * cur = root;
    int sorted = 1;

    if(root==NULL || root->next==NULL) {
        return sorted;
    }

    int val = 0;
    while(cur->next!=NULL && sorted!=0) {
        val = cur->data;
        cur=cur->next;
        if(val>cur->data) {
            sorted = 0;
        }

    }

    return sorted;

}

node * frontToBack(node * root) {

    if(root==NULL || root->next==NULL) {
        return root;
    }

    node * cur = root;
    node * front = malloc(sizeof(node)); // if you point to root, points to the same linked list and will mess things up if you edit too severely
    front->data=cur->data;
    front->next=NULL;

    while(cur->next!=NULL) {
        cur=cur->next;

    }
    cur->next = front;
    root=root->next;

    return root;


}

int returnIndex(node * root, int val) {
    node * cur = root;
    int i = 0;

    if (root == NULL) {
        return -1; 
    }

    while (cur != NULL) {
        if (cur->data == val) {
            return i;  
        }
        cur = cur->next;
        i += 1;
    }

    return -1;
    
}

void display(node *root) {
    printf("\nLIST:\n");
    if(root==NULL) {
        printf("EMPTY\n\n");
        return;
    }
    node * cur = root;
    while(cur->next!=NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d\n\n", cur->data);

}


int main()
{	
    node * root = NULL;

    int input;

    int stop = 0;

    // Menu
	while(stop!=1)
	{
		printf("Menu:\n1. Insert at front\n2. Insert at end\n3. Insert at index\n4. Insert at place\n5. Delete first\n6. Delete last\n7. Delete index\n8. Delete place\n9. Reverse the list\n10. Copy the list\n11. Check for sorted\n12. Move front to back\n13. Search for value\n");
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
                printf("INSERT (START):\n");
                printf("Enter integer: ");
                scanf("%d", &data);
                root = insertFront(root, data);
                display(root);

                break;

            case(2):
                printf("INSERT (END):\n");
                printf("Enter integer: ");
                scanf("%d", &data);
                root = insertEnd(root, data);
                display(root);

                break;
            
            case(3):
                printf("INSERT (INDEX):\n");
                printf("Enter integer and index: ");
                scanf("%d %d", &data, &index);
                root = insertIndex(root, data, index);
                display(root);
                break;
            
            case(4):
                printf("INSERT (PLACE):\n");
                printf("Enter integer and place: ");
                scanf("%d %d", &data, &index);
                root = insertPlace(root, data, index);
                display(root);
                break;
            
            case(5):
                printf("DELETE (FIRST):\n");
                root = deleteFirst(root);
                display(root);
                break;
            
             case(6):
                printf("DELETE (LAST):\n");
                root = deleteEnd(root);
                display(root);
                break;

            case(7):
                printf("DELETE (INDEX):\n");
                printf("Enter index: ");
                scanf("%d", &index);
                root = deleteIndex(root, index);
                display(root);
                break;

            case(8):
                printf("DELETE (PLACE):\n");
                printf("Enter place: ");
                scanf("%d", &index);
                root = deletePlace(root, index);
                display(root);
                break;

            case(9):
                printf("REVERSE:\n");
                root = reverseList(root);
                display(root);
                break;

            case(10):
                printf("COPY:\n");
                root = copyList(root);
                display(root);
                break;

            case(11):
                printf("CHECK SORTED:\n");
                int sorted = checkSorted(root);
                printf("1 for sorted and 0 for not sorted: %d\n", sorted);
                break;

            case(12):
                printf("FRONT TO BACK:\n");
                root = frontToBack(root);
                display(root);
                break;

            case(13):
                printf("CHECK ITEM:\n");
                int val = 0;
                printf("Enter val: ");
                scanf("%d", &val);
                int index = returnIndex(root, val);
                printf("Index is: %d\n", index);
                display(root);
                break;

           
        }


    }
}