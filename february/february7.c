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

*/

#include <stdio.h>
#include <math.h>

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


}