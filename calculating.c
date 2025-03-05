#include <stdio.h>

int main() {
    double quizzes[5] = {70, 70, 70, 70, 70};
    double quizzesGrade = 0;
    for(int i=0; i<5; i++) {
        quizzesGrade+=quizzes[i];

    }
    quizzesGrade/=5;

    double hw = 98; // gotta get hw to 100%....
    double midterm1 = 51; 
    double midterm2 = 75;
    double final = 70;

    double total = (quizzesGrade*0.25)+(midterm1*0.2)+(midterm2*0.2)+(final*0.25)+(hw*0.10);
    printf("Grade: %lf", total);


}
//f uck