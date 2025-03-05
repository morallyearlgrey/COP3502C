// NOTES 2/7

/*

RECURSION
- Definition is a function calling itself
- Runtime is so BAD
- Requires a base case to prevent the function from being called again

Types of Recursive Functions:
- Forward => doing THEN recursion
- Backwards => recursion THEN doing

FORWARDS REC:
- Does lines then rec calls
- Ex: x=5 and rec(x-1) => 5 4 3 2 1

BACKWARDS REC:
- Adds lines after call to a stack and then pops lines after returned
- Ex: x=5 and rec(x-1) => 1 2 3 4 5

INGREDIENTS TO RECURSION:
- Break it down into chunks!
- Break it down into equations (ex: x^y is x * x^(y-1))
- Think of it as a loop
- Use if statements!
- Figure out base case first

Two constructs:
1) 
if(terminating condition):
do final action
else:
take one more step to terminating condition and rec
* usually return functions do this

2)
if(!(terminating condition)):
do one more step to terminatig condition and rec
* usually void functions do this

RECURSIVE TREES
- Each leaf is a different recursion call
- Evaluate from the bottom to the top and draw from the top to the bottom

*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// forwards rec
void forwards(int x) {
    // base case
    if(x==0) {
        return;
    }
    printf("%d ", x);
    forwards(x-1);

}

// backwards rec
void backwards(int x) {
    // base case
    if(x==0) {
        return;
    }
    backwards(x-1);
    printf("%d ", x); // adds to a stack
 
}

int power(int base, int exp) {
    if(exp==0) {
        return 1;
    }
    return(base * power(base, exp-1));
}

int sum(int n) {
    if(n==0) {
        return 0;
    }
    return (n + sum(n-1));
}

int factorial(int n) {
    if(n==0) {
        return 1;
    }
    return(n * factorial(n-1));
} // does f(10) => f(9) => f(8).... 

int fibonacci(int n) {
    if(n<=1) {
        return n;
    }
    return(fibonacci(n-1)+fibonacci(n-2));

}

void reverseString(char * string, int len) {
    if(len==1) {
        printf("%c", string[0]);
        return;
    }
    printf("%c", string[len-1]);
    reverseString(string, len-1);

}

void reverseString2(char * string, int len) {
    if(len>0) {
        printf("%c", string[len-1]);
        reverseString2(string, len-1);
    }
}
// 13 for instance to binary
// 13/2=6 (remainder 1) => 6/2=3 (remainder 0) => 3/2=1 (remainder 1) => 1/2=0 (remainder 1)
// stack it and do backwards
// 1101

// 16/2=8 (remainder 0) => 8/2=4 (remainder 0) => 4/2=2 (remainder 0) => 2/2=1 (remainder 0) => 1/2=0 (remainder 1)
// 10000
void decToBinary(int n) {
    if(n<2) {
        printf("%d", n);
        return;
    }
    decToBinary(n/2);
    printf("%d", n%2);

} // since we have to do it backwards, we want to STACK it and so that's why print is AFTER the rec call

// pattern
// shift n-1 disks from a to b
// shift last disk from a to c
// shift n-1 disks from b to c
// requires 2(^n) -1 moves
void towersOfHanoi(int n, char from, char to, char aux) {
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from, to);
        return;
    }
    towersOfHanoi(n-1, from, aux, to);
    printf("\n Move disk %d from rod %c to rod %c", n, from, to);
    towersOfHanoi(n-1, aux, to, from);

}

void exchange(char * string, int i, int j) {
    char temp = string[i];
    string[i] = string[j];
    string[j] = temp;

}

// permutations
// combinations of words
void perm(char * string, int i) {
    // base case
    if(i==(strlen(string))) {
        printf("%s\n", string);
        return;

    } else {
        for(int j=i; j<strlen(string); j++) { // repeats three times for CAT, trying to put each letter in the first spot
            exchange(string, i, j); // will run twice (CAT and CTA)
            perm(string, i+1); // 
            exchange(string, j, i);

        }

    }

}



// permutations but with array
// permutations; indicating which indices used; how many ints filled; length
void perm2(int * perm, int * used, int k, int n) {
    if(k==n) { // if k is equal to lengtj
        for(int i=0; i<n; i++) {
            printf("%d", perm[i]);
        }
        printf("\n");
        return;

    }
    for(int i=0; i<n; i++) {
        if(used[i]==0) { // if i wasn't used yet
            used[i]=1; // set to used
            perm[k]=i; // transfer to perm array at spot
            perm2(perm, used, k+1, n); // increase k
            used[i]=0; // unmark for NEXT process

        }
    }

}


int main() {
    printf("Testing out recursion with (x-1)...\n");
    printf("Enter a value: ");
    int val;
    scanf("%d", &val);

    printf("Forwards: ");
    forwards(val);
    printf("\n");
    printf("Backwards: ");
    backwards(val);
    printf("\n");

    printf("Factorial for 5: ");
    printf("%d", factorial(5)); // returns f(0)=>f(1)>f(2)... (rebound)
    printf("\n");
    printf("Fibonacci for 5: ");
    printf("%d", fibonacci(5));
    printf("\n");

    printf("Reversing CAT construct 1: ");
    char * string = "CAT\0";
    reverseString(string, 3);
    printf("\n");
    printf("Reversing CAT construct 2: ");
    reverseString2("CAT", 3);
    printf("\n");

    printf("5 to binary: ");
    decToBinary(5);
    printf("\n");

    printf("Permutations 1:\n");
    perm(string, 1);


}