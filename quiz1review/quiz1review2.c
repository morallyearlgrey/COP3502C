// LAB 2 REVIEW

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char *lname; //this will require DMA to store a string
    int assignment;
    int finalExam;
    int total;
    int *quizzes;//this will require DMA to store quizzes
    
} student;

// Displays the student with the highest total score 
// Total score = sum of scores from M quizzes + score in the assignment + score in the final exam

// C is number of courses
// N is number of students
// M is number of quizzes
student** readCourses(int * C, int * N, int * M) {
    student ** courses = malloc(sizeof(student*) * (*C));

    // scanning input
    for(int i=0; i<*C; i++) {
        courses[i] = malloc(sizeof(student)* (*N));

        for(int x=0; x<*N; x++) {
            student stud;

            char lname[21];
            scanf("%s", lname);

            int assignment;
            scanf("%d", &assignment);

            for(int y=0; y<*M; y++) {
                int quiz;
                scanf("%d", &quiz);
                stud.quizzes[y]=quiz;

            }

            int finalExam;
            scanf("%d", &finalExam);

            strcpy(lname, stud.lname);
            stud.assignment=assignment;
            stud.finalExam=finalExam;


            courses[i][x] = stud;

        }

        printf("\n");

    }

    // max student

    int maxScore = 0;
    int maxCourseIndex = 0;
    int maxStudentIndex = 0;
    // Total score = sum of scores from M quizzes + score in the assignment + score in the final exam

    for(int i=0; i<*C; i++) {
        for(int x=0; x<*N; x++) {
            int score = courses[i][x].assignment+courses[i][x].finalExam;

            for(int y=0; y<*M; y++) {
                score+=courses[i][x].quizzes[y];

            }

            if(score>maxScore) {
                maxScore=score;
                maxCourseIndex=i;
                maxStudentIndex=i;

            }

        }

    }

    student returnStud = courses[maxCourseIndex][maxStudentIndex];

    return courses;


}

void release_memroy(student ** st, int C, int N, int M) {


}

int main () {

    int C, N, M;
    scanf("%d %d %d", &C, &N, &M);
    student ** courseList = readCourses(&C, &N, &M);

    return 0;
}