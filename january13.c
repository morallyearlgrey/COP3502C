// NOTES 1/13
/*
MALLOC AND CALLOC
- void * malloc (unsigned int); // unsigned int is the size in bytes
- void * calloc (how many, size of each); // for arrays, declares size of each var in this arr
- Calloc will initialize allocated memory to 0, BUT Malloc will not

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct NationalPark {
    char * name;
    int lat;
    int lon;

} park;

park * createPark(char name[], int lon, int lat) {
    int size = strlen(name)+1; // add 1 for NULL char \0
    park * p = malloc(sizeof(park)); // question: don't we need to malloc space for the name PRIOR to the struct bc then the struct ptr won't hold enough?
    p->name = malloc(sizeof(char)*size);
    strcpy(p->name, name); // copy name to pname  

    p->lon=lon;
    p->lat=lat;

    return p;
}

void printNP(park * p) {
    printf("%s\n", p->name);
    printf("longitude: %d\n", p->lon);
    printf("latitude: %d\n", p->lat);

}

// Returns a pointer to an allocated spot in heap space for an array
int * arrayFactory(int len) {
    // We need to cast because malloc returns a VOID pointer, we need to tell the compiler it's a specific type of pointer (explicit casting) but without (int*), it's implicit casting 
    // Up to us IG since we do implicit cast it
    int * arr = (int*) malloc(sizeof(int)*len);

    if(arr == NULL) {
        return NULL;
    } else {
        for(int i=0; i<len; i++) {
            arr[i]=1+rand()%100; // rand() goes from 0 to rand_max and then %100 sets it to 0 to 99 (the remainder) and then+1 shifts this to 1-100
        }
        return arr;
        // no need to free() after because return indicates end
    }
}

int main() {
    park * p = createPark("yosemite", 5, 6);
    printNP(p);

    free(p->name);
    free(p);

    int size;
    scanf("%d", &size);
    int * temp = arrayFactory(size);
    for(int i=0; i<size; i++) {
        printf("%d ", temp[i]);
    }

    free(temp); // free memory before making another one
    temp = arrayFactory(1);
    printf("\n");

    for(int i=0; i<1; i++) {
        printf("%d ", temp[i]);
    }

    free(temp);

    return 0;
}