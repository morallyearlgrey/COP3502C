// NOTES 2/19
/*
BIG O NOTATION
- Analyzes the time complexity of C code (specifically loops)
- Always the "worst" case automatically but do "best" case if asked to

Common orders (slowest to fastest growth):
- 1 => constant (one operation, like ex: enqueue)
= log(n) => logarithmic 
- n => linear
- n log(n) => poly log
- n^2 => quadratic
- n^3 => cubic
- 2^n => exponential
- n! => factorial

Solving for Runtime:
1. Algorithm A runs in O(n^2) time, for an input size of 4, the running time is 10 milliseconds. How long does it take for an input size of 16?
T(n)=C(n^2)
T(4)=C(4^2)
T(4)=C*16
10=C*16
C=10/16

T(16)=(10/16)*(16^2)
T(16)=160

Explanation of O(log n):
- Time goes up linearly while n goes up exponentially
- Ex: 1 second for 10 elements, 2 seconds for 100 elements
- Divide and conquer types of algorithms (binary search or quick sort)

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int sum=0;

    printf("Enter n: ");
    scanf("%d", &n);

    // O(n/2)
    for(int i=0; i<=n/2; i++) {
        sum+=1;

    } 

    // O(n^2)
    for(int i=0; i<n*n; i++) {
        sum+=5;

    }


}