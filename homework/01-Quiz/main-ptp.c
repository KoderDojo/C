/* ***********************************************
 * 
 *  DEVNANO - Homework Assignment - Quiz
 *
 *  This solution to the homework assignment uses
 *  pointer-to-pointer in C, which I believe is
 *  how a 2D Array is modeled under the hood.
 *
 * ******************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define stringLength 80

int main() {
    int totalNumberOfQuestions;
    int totalCorrectAnswers = 0;

    char **questions;
    char **answers;


    /* ******************************
     * Get Number of Questions
     * **************************** */

    printf("Number of questions? ");
    scanf("%d", &totalNumberOfQuestions);


    /* ******************************
     * Allocate Memory
     * **************************** */

    questions = (char **)malloc(totalNumberOfQuestions * sizeof(char *));
    answers = (char **)malloc(totalNumberOfQuestions * sizeof(char *));

    if (questions == NULL || answers == NULL) {
        printf("Error allocating memory.");
        exit(1);
    }

    for(int i=0; i<totalNumberOfQuestions; i++) {
        questions[i] = (char *)malloc(stringLength * sizeof(char));
        answers[i] = (char *)malloc(stringLength * sizeof(char));

        if (questions[i] == NULL || answers[i] == NULL) {
            printf("Error allocating memory.");
            exit(1);
        }
    }


    /* ******************************
     * Enter Questions and Answers
     * **************************** */

    printf("\n\n***** Enter Questions *****");
    for(int i=0; i < totalNumberOfQuestions; i++) {
        printf("\n\nEnter Question %d: ", i+1);
        scanf(" %[^\n]", questions[i]);
        printf("\nEnter Answer: ");
        scanf(" %[^\n]", answers[i]);
    }


    /* ******************************
     * Take Quiz
     * **************************** */

    char userInput[stringLength];

    printf("\n\n***** Take Quiz *****");
    for(int i=0; i < totalNumberOfQuestions; i++) {
        printf("\n\n%d. %s ", i+1, questions[i]);
        scanf(" %[^\n]", userInput);

        if (strcmp(userInput, answers[i]) == 0) {
            printf("\nCorrect.\n");
            totalCorrectAnswers++;
        } else {
            printf("\nIncorrect. Answer is %s.\n", answers[i]);
        }
    }


    /* ******************************
     * Print Results
     * **************************** */

    char letterGrade;
    int percentCorrect = (int)((float) totalCorrectAnswers / totalNumberOfQuestions * 100 + 0.5);

    if (percentCorrect > 89) {
        letterGrade = 'A';
    } else if (percentCorrect > 79) {
        letterGrade = 'B';
    } else if (percentCorrect > 69) {
        letterGrade = 'C';
    } else if (percentCorrect > 59) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    printf("\n\n***** Results *****");
    printf("\n\nTotal Correct Answers: %d/%d\n", totalCorrectAnswers, totalNumberOfQuestions);
    printf("Percent Correct: %d%%\n", percentCorrect);
    printf("Letter Grade: %c\n", letterGrade);
    printf("\n\nGoodbye!\n");


    /* ******************************
     * Free Memory
     * **************************** */

    for(int i=0; i<totalNumberOfQuestions; i++) {
        free(questions[i]);
        free(answers[i]);
    }

    free(questions);
    free(answers);

    return 0;
}
