
#include <stdio.h>
#include <math.h>

void rec2(int x) {
    if(x==0) {
        return;
    }
    rec2(x-1);
    printf("%d ", x);
}

int toOctal(int n) {
    if(n==0) {
        return 0;

    }
    return (n%8 + 10 )* toOctal(n/8);

}

void decToOct(int n) {
    if (n == 0) {
        return;  // Base case: if n is 0, stop the recursion
    }
    decToOct(n / 8);  // Recursive call with n divided by 8
    printf("%d", n % 8);     // Print the remainder when n is divided by 8
}

int crazySum(int n) {
    if(n==0) {
        return 0;
    }
    return pow(n, n) + crazySum(n-1);

}

int productDigits(int n) {
    if(n<10) {
        return n;
    }
    return (n%10)*productDigits(n/10);
}

int weightedSum(int numbers[], int n) {
    if(n==1) {
        return (numbers[n-1]*1);
    }
    return(numbers[n-1]*(n)+weightedSum(numbers, n-1));

}

int fun(int x)
{
    if(x==0)
        return 0;
    if(x%3 ==0)
        return fun(x/3);
    return fun(x-1) + x;
}

int question3(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return question3(10*a+b%10, b/10);
}

int main() {
    printf("%d\n", fun(7));
    int numbers[]={7, 6, 9};
    printf("%d\n", weightedSum(numbers, 3));
    printf("%d\n", productDigits(6782));
    printf("%d\n\n", toOctal(20));
    decToOct(20);
    printf("\n");
    printf("%d\n", crazySum(9));
    printf("%d\n", question3(10, 101));
    rec2(5);
    return 0;
}

