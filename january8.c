// NOTES 1/8
// C REVIEW

/*
MEMORY STORAGE:
- Max memory depends on RAM storage
- 1 byte has 8 bits
- Every row in the stack space is 1 byte 
- For instance, the int will take up 4 addresses (4 byte rows) but it selects the first of the four to showcase when printed 

*/

#include <stdio.h>
#include <string.h>

int main() {
    // STRING INPUTS
    char str[100];
    printf("Enter input: ");
    // scanf("%[^n]s", str); // [^\n] makes it equivalent to fgets but may crash if string is too large; DON'T USE
    // printf("%s\n", str);
    // printf("test\n");
    fgets(str, 99, stdin);
    str[strcspn(str, "\n")] = '\0'; // strcspn returns length until \n and this sets the last character to \0
    printf("%s\n", str);

    // SIZEOF()
    int a; // garbage values 
    a = 5;
    printf("%lu", sizeof(a)); // %lu is unsigned long integer, the return value of sizeof operator

    // MEMORY
    printf("%p", &a); // %, %x could be used (unsigned and integers in hexadecimal form)
    int b=4, c=4, *d=&c; // you can declare integer and pointer on same line
    printf("printing %p and %d", d, *d);

    


    return 0;
}