// NOTES 1/10
// C REVIEW + DYNAMIC MEMORY ALLOCATION

/*
DYNAMIC MEMORY ALLOCATION:
- Number of values is allowed to be changed
- Not static
- Memory storage takes place in heap space
- Memory requirements are unknown at COMPILE TIME
- No name directly to the allocated memory BUT the pointer has a name
- Isn't freed AUTOMATICALLY
- Takes space in heap space
- Computer warns if there's no space when we're trying to malloc
- Requires stdlib.h

STATIC MEMORY:
- Space is known during COMPILE TIME
- Name of var is required
- Takes up space regardless of whether it was used or not, may hold garbage values though
- Memory storage takes place in stack space
- If value is declared in function, its memory and values are destroyed (freed) once the function is finished running (poof!)
- Freed automatically once the function ends

WHY WE CANNOT RETURN STATIC ARRAYS:
- Because after the function is ran, the array's data is freed, all the new value in the main function holds is the memory address of that array, which has no more values! 
- SOOOO we can't return static array

*/

#include <stdio.h>
#include <sys/_types/_null.h>
#include <stdlib.h> // HOLDS DYNAMIC MEMORY FUNCTIONS

void makeNULLTest(int **p) {
    *p = NULL;
}

void mainTest() {
    int *q;
    makeNULLTest(&q);

}

// IMPOSSIBLE, CANT DO
// int * returnArr() {
//     int arr[10];
//     arr[0]=4;
//     return arr; 

// }

int main() {
    // Making Q ptr NULL
    mainTest();

    // int arr[10] = returnArr();

    /*
    STATIC MEMORY AND SCANF
    - We don't know what size is
    - Uses memory pool called STACK to store this memory and it is actually limited
    - Likely the program would crash if too big
    - Similar to other statically allocated memory, the var would be freed after the function is ran
    */
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    // DYNAMIC MEMORY ALLOCATION
    int * test = malloc(sizeof(int)*10); // Requires bytes in parameter, makes test point to a space in the heap space with 40 bytes
    test[0] = 7;
    int * test2 = calloc(10, sizeof(int)); // Allocates to an arr ptr with size 10 and sizeof(int) for each element; Everything in the array is initialized to 0
    // Sometimes, in old compilers, casting for ptrs to arrs is required bc a void ptr is returned and the compiler doesn't know what type of arr it is
    // Example of casting:
    int * test3 = (int*) calloc(10, sizeof(int));
    free(test);
    free(test2);
    free(test3);

    return 0;


}