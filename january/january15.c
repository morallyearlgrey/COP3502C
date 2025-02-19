// NOTES 1/15
/*

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NationalPark {
    char * name;
    int lat;
    int lon;

} park;

park * createArrayOfNP(int n, char names[][50])
{
    park * arr = malloc(n*sizeof(park));
    for(int i=0; i<n; i++) {
        arr[i].lat=4;
        arr[i].lon=5;
        int len = strlen(names[i]);
        arr[i].name = malloc(sizeof(char)*len);
        strcpy(arr[i].name, names[i]);

    }
    return arr;
}

// //receives an array of NP and print them
void displayArrayNPV1(park *p, int size)
{
  for(int i=0; i<size; i++) {
    printf("name: %s\nlongitude: %d\nlatitude: %d\n", p[i].name, p[i].lon, p[i].lat);
  }

}

// void displayArrayNPV2(park **p, int size)
// {
//   //to be written in the class
// }


// //receive an array of national park names, and return an array of national park pointers where each pointer is pointing to a dynamically allocated national park
// park** createArrayofNPPtr(int n, char names[][50])
// {
//     park ** p = malloc(n*sizeof(park));
//     // continue later (,:
//     // did not continue later


// }

//given an array of national park pointers where each pointer points to a national park. Free all the allocated memory
void releaseNP(park *p, int size)
{
    for(int i=0; i<size; i++) {
        free(p[i].name);
    }
    free(p);

}

park * createPark(char name[], int lon, int lat) {
    int size = strlen(name)+1; // add 1 for NULL char \0
    park * p = malloc(sizeof(park)); 
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

int main() {
    int * ptr = malloc(sizeof(int));
    int * ptr2 = ptr;
    free(ptr); 
    // seg fault bc ptr's heap memory no longer exists: *ptr2 = 20;
    // memory corruption: free(ptr2)
    park * p = createPark("yosemite", 5, 6);
    printNP(p);

    char parkNames[5][50] = {"zion park", "yosemite", "apple", "orange", "strawberry"};

    park * pArr = createArrayOfNP(5, parkNames);
    displayArrayNPV1(pArr, 5);
    releaseNP(pArr, 5);

    free(p->name);
    free(p);

    int * arr = malloc(sizeof(int)*3);
    arr[0]=4; arr[1]=2; arr[2]=1; arr[3]=4;

    // resizing without realloc()
    int * arr2 = malloc(sizeof(int)*6);
    for(int i=0; i<((int)sizeof(arr)/sizeof(int)); i++) {
        arr2[i]=arr[i];
    }

    // realloc()
    // used in cases where allocated array size is not enough and size needs to be resized
    arr = realloc(arr, (3*2)*sizeof(int));
    arr[5]=0;
    printf("%d", arr[5]);

    return 0;
}