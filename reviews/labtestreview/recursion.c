#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;

} node;

node * insert(node * root, int val) {
    if(root==NULL || root->val>val) {
        node * newNode = malloc(sizeof(node));
        newNode->next=root;
        newNode->val=val;
        return newNode;

    }
    root->next = insert(root->next, val);
    return root;

}

node * del(node * root, int val) {
    if(root==NULL) {
        return root;

    } else if(root->val==val) {
        node * del = root;
        root=root->next;
        free(del);
        return root;

    }
    root->next = del(root->next, val);
    return root;

}

int main() {
    return 0;

}