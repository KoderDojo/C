/* ***********************************************
 *
 *  DEVNANO - Homework Assignment - Quiz
 *
 *  This is one of my earlier solutions to the
 *  Quiz problem that uses a struct to keep the
 *  question and answer bundled together.
 *
 *  My background is in C# and OOP, which is why
 *  I was 'desperately' trying to mimic classes.
 *
 *  My first time using typedef and struct.
 *
 * ******************************************** */


#include <stdio.h>
#include <string.h>

#define stringLength 80

typedef struct{
    char text[stringLength];
    char answer[stringLength];
}Question;


int main() {
    int i;
    int totalQuestions;
    int totalCorrectAnswers = 0;


    /* ******************************
     * Get Number of Questions
     * **************************** */

    printf("Enter number of questions: ");
    scanf("%d", &totalQuestions);


    /* ******************************
     * Declare size of array based
     * on variable. This seems to
     * work although more experienced
     * developers were surprised.
     *
     * Might be a C 11 thing.
     * **************************** */

    Question questions[totalQuestions];


    /* ******************************
     * Enter Questions and Answers
     * **************************** */

    printf("\n\n********** Input Questions **********\n\n");

    for(i=0; i<totalQuestions; i++) {
        printf("Enter Question #%d: ", i+1);
        scanf(" %[^\n]", questions[i].text);
        printf("Enter Answer   #%d: ", i+1);
        scanf(" %[^\n]", questions[i].answer);
        printf("\n");
    }


    /* ******************************
     * Take Quiz
     * **************************** */

    char userAnswer[stringLength];

    printf("\n************** Take Quiz *************\n\n");

    for(i=0; i<totalQuestions; i++) {
        printf("%s ", questions[i].text);
        scanf(" %[^\n]", userAnswer);

        if (strcmp(userAnswer, questions[i].answer) == 0) {
            totalCorrectAnswers++;
            printf("\n\nCorrect.");
        } else {
            printf("Incorrect. Answer is %s.", questions[i].answer);
        }

        printf("\n\n");
    }


    /* ******************************
     * Print Results
     * **************************** */

    int percentCorrect = (int)(((float)totalCorrectAnswers / totalQuestions * 100) + 0.5);

    char grade;
    if (percentCorrect > 89)
        grade = 'A';
    else if (percentCorrect > 79)
        grade = 'B';
    else if (percentCorrect > 69)
        grade = 'C';
    else if (percentCorrect > 59)
        grade = 'D';
    else
        grade = 'F';

    printf("\n**************** Results ***************\n\n");
    printf("Total Correct Answers: %d/%d\n", totalCorrectAnswers, totalQuestions);
    printf("Percent Correct: %d%%\n", percentCorrect);
    printf("Letter Grade: %c\n", grade);
}