/* ***********************************************
 *
 *  DEVNANO - Homework Assignment - Quiz
 *
 *  This is based on the original assignment (v1)
 *  where we didn't have to ask the user to input
 *  questions. We were told to just 'hardcode'
 *  the questions.
 *
 *  I wrote this based on a question on Slack to
 *  help another developer. I wanted to show how
 *  he could use a for loop to generate the
 *  questions dynamically as opposed to creating
 *  them in multiple variables statically.
 *
 *  I used functions to clarify responsibilities
 *  and maintainability although they weren't
 *  taught yet.
 *
 * ******************************************** */


#include <stdio.h>


// Forward declare functions.
int askQuestions(int);
void printResults(int, int);


int main() {

    // Per the assignment, just hardcode
    // number of questions.
    const int TOTAL_QUESTIONS = 3;

    int totalCorrectAnswers = askQuestions(TOTAL_QUESTIONS);
    printResults(totalCorrectAnswers, TOTAL_QUESTIONS);

    return 0;
}


/**
    Asks the user questions and returns the number of correct answers.

    @param totalQuestions The total number of questions to ask.
    @return The total number of correct answers.
 */
int askQuestions(int totalQuestions) {
    int i = 0;
    int totalCorrectAnswers = 0;
    char userAnswer;

    while (i < totalQuestions) {
        printf("%d. What is the letter at position %d in the alphabet? ", i+1, i+1);
        scanf(" %c", &userAnswer);
        if (userAnswer == ('a' + i) || userAnswer == ('A' + i)) {
            printf("\nCorrect!\n\n");
            totalCorrectAnswers++;
        } else {
            printf("\nIncorrect! Answer is %c.\n\n", ('a' + i));
        }
        i++;
    }

    return totalCorrectAnswers;
}


/**
    Prints the total number of correct answers, percentage correct,
    and a letter grade based on percentage correct.

    @param totalCorrectAnswers The total number of correct answers.
    @param totalQuestions The total number of questions.
    @return void
 */
void printResults(int totalCorrectAnswers, int totalQuestions) {
    char letterGrade;

    int percentCorrect = (int)(100*(float)totalCorrectAnswers/totalQuestions+0.5);
    if (percentCorrect > 89)
        letterGrade = 'A';
    else if (percentCorrect > 79)
        letterGrade = 'B';
    else if (percentCorrect > 69)
        letterGrade = 'C';
    else if (percentCorrect > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';

    printf("Total Correct Answers: %d/%d.\n", totalCorrectAnswers, totalQuestions);
    printf("Percentage: %d%%.\n", percentCorrect);
    printf("Grade: %c\n\n", letterGrade);
}