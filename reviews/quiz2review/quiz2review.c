#include <stdio.h>
#include <stdlib.h>

// A 
// Derive the runtime of binary search
// At each step, the size of search space is reduced by half 
// n/(2^k) is the runtime with k being the steps/iterations taken to reduce the search space
// so k=log2(n)

// SLMP
// Find common elements between elements of two lists
// Approaches: 
// 1) brute force (two loops) with o(n^2) or o(n*m)
// 2) binary search (passing each i target to binary search and returning 1 for here or 0 for not) with o(n* log n) or o(n *log m)
// 3) two pointer approach (pointer for each list and move respective pointer based off whose value is less or greater than the other) with o(2n) or o(n+m) time

int binarySearch(int * list, int len, int item) {
    int high = len-1;
    int low = 0;
    int mid;

    while(low<=high) {
        mid = (low+high)/2;
        if(list[mid]==item) {
            return mid;

        } else if(list[mid]<item) {
            low=mid+1;

        } else {
            high=mid-1;

        }

    }
    return mid;

}

int recBinarySearch(int * list, int low, int high, int item) {
    if(low<=high) {
        int mid = (low+high)/2;
        if(list[mid]==item) {
            return mid;
        } else if(list[mid]<item) {
            low=mid+1;
            recBinarySearch(list, low, high, item);
        } else if(list[mid]>item) {
            high=mid-1;
            recBinarySearch(list, low, high, item);
        }

    }
    return -1;

}

// B
// STACKS

typedef struct node {
    struct node * next;
    int val;

} node;

typedef struct stack {
    node * root;
    int top;

} stack;

int pop(stack * s) {
    if(s->root==NULL) {
        return -1;

    }
    node * popThing = s->root;
    s->root = s->root->next;
    int val = popThing->val;
    free(popThing);
    return val;

}

stack * push(stack * s, int item) {
    node * newNode = malloc(sizeof(node));
    newNode->val=item;
    if(s->root==NULL) {
        s->root=newNode;
        newNode->next=NULL;
        return s;
    }

    newNode->next=s->root;
    s->root=newNode;

    return s;

}

// Recursion and Linked Lists
// insert into sorted link list
struct node * insert(node * root, int val) {
    if(root==NULL || val<=root->val) {
        node * newNode = malloc(sizeof(node));
        newNode->val = val;
        newNode->next=root;
        return newNode;

    }
    root->next = insert(root->next, val);
    return root;

}

struct node * del(node * root, int val) {
    if(root==NULL) {
        return root;

    } else if(root->val==val) {
        node * getRidOf = root;
        root = root->next;
        free(getRidOf);
        return root; 

    }
    root->next = del(root->next, val);
    return root;

}

// C
// binary to decimal
// 11100010
// 2^7 2^6 2^5 2^4 2^3 2^2 2^1 2^0
// 1*128 + 1*64 + 1*32 + 0*16 + 0*8 + 0*4 + 2*2 + 0*1
// 226

// decimal to octal
// 226%8=2
// 28%8=4
// 3%8=3
// go backwards (add to a stack)
// 342

// Permutations

void perm(int * arr, int n, int val) {
    if(val==n) {
        for(int i=0; i<n; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
        return;
    }
    for(int i=0; i<n; i++) {
        if(arr[i]!=-1) {
            continue;
        }
        arr[i]=val;
        perm(arr, n, val+1);
        arr[i]=-1;

    }

}

// l for start index and h for high index
void perm2(char * arr, int l, int h) {
    

}

int main() {
    int arr[4] = {-1, -1, -1, -1};
    perm(arr, 4, 0l);

}