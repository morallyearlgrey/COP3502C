#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node * next;
    int val;

} node;

node * createNode(int val) {
    node * newNode = malloc(sizeof(node));
    newNode->next=NULL;
    newNode->val=val;
    return newNode;

}

node * insertIndex(node * root, int val, int index) {
    node * newNode = createNode(val);

    if(root==NULL || index==0) {
        newNode->next=root;
        root=newNode;
        return root;

    } 

    node * cur = root;
    int cunt = 0;

    while(cur->next!=NULL && cunt!=(index-1)) {
        cur=cur->next;
        cunt+=1;

    }

    newNode->next=cur->next;
    cur->next=newNode;
    return root;
 
}

int deleteIndex(node * root, int index) {

    if(root==NULL) {
        return -1;

    } else if(index==0) {
        node * temp = root;
        int val = temp->val;
        root=root->next;
        free(temp);

        return val;

    }

    node * cur = root;
    int i = 0;

    while(cur!=NULL && i!=index-1) {
        cur=cur->next;
        i+=1;
    }

    if(cur==NULL) {
        return -1;

    } else {
        node * temp = cur;
        cur=cur->next;
        node * del = cur;
        temp->next=cur->next;
        int val = del->val;
        free(del);
        return val;

    }

}


int main() {
    return 0;

}