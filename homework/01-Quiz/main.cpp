/* ***********************************************
 *
 *  DEVNANO - Homework Assignment - Quiz
 *
 *  In this solution I am using C++, which we
 *  haven't talked about in class, but I think is
 *  worth learning.
 *
 *  Being able to use vector and string removes
 *  chunks of code.
 *
 *  I could change the 'for' loop to for_each
 *  when iterating the vectors, but I'm leaving
 *  it because that is what I used originally.
 *
 * ******************************************** */


#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> questions;
    vector<string> answers;

    int totalNumberOfQuestions = 0;
    int totalCorrectAnswers = 0;

    int i;
    string userInput;


    /* ******************************
     * Enter Questions and Answers
     * **************************** */

    cout << "***** Enter Questions *****";

    i = 1;
    while (true) {
        cout << endl << endl << "Enter Question " << i << " or Q)uit: ";
        cin >> userInput;
        if (userInput.compare("Q") == 0) {
            break;
        }
        questions.push_back(userInput);
        cout << endl << "Enter Answer: ";
        cin >> userInput;
        answers.push_back(userInput);

        totalNumberOfQuestions++;
        i++;
    }

    if (totalNumberOfQuestions == 0) {
        cout << endl << endl << "Goodbye!" << endl;
        return 0;
    }


    /* ******************************
     * Take Quiz
     * **************************** */

    cout << endl << endl << "***** Take Quiz *****";

    i = 0;
    for (std::vector<string>::iterator it = questions.begin() ; it != questions.end(); ++it) {
        cout << endl << endl << i+1 << ". " << *it << " ";
        cin >> userInput;
        if (answers[i].compare(userInput) == 0) {
            cout << endl << "Correct.";
            totalCorrectAnswers++;
        } else {
            cout << endl << "Incorrect. Answer is " << answers[i] << ".";
        }
        i++;
    }


    /* ******************************
     * Print Results
     * **************************** */

    char letterGrade;
    int percentCorrect = (int)(((float)totalCorrectAnswers / totalNumberOfQuestions) * 100 + 0.5);

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

    cout << endl << endl << endl << "***** Print Results *****" << endl << endl;
    cout << "Total Correct Answers: " << totalCorrectAnswers << "/" << totalNumberOfQuestions << endl;
    cout << "Percent Correct: " << percentCorrect << "%%" << endl;
    cout << "Letter Grade: " << letterGrade << endl;
    cout << endl << endl << "Goodbye!" << endl;

    return 0;
}
