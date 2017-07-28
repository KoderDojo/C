/* ***********************************************
 *
 *  DEVNANO - Homework Assignment - Quiz
 *
 *  A solution for the homework using another
 *  C-based language, called C#. Kept it simple
 *  and similar to other solutions.
 *  
 *  C# is very similar to C++.
 *  
 *    - 'List' in C# is similar to 'vector' in C++
 *    - Both use 'string' class.
 *    
 *  I am using 'ValueTuple' to return questions
 *  and answers. Also using string interpolation
 *  in Console.Write statements. These are fairly
 *  new to C#.
 *
 * ******************************************** */

using System;
using System.Collections.Generic;

namespace Quiz {
    class Program {
        static void Main(string[] args) {
            var (questions, answers) = CreateQuestionsAndAnswers();

            if (questions.Count > 0) {
                var totalCorrectAnswers = TakeQuiz(questions, answers);
                PrintResults(totalCorrectAnswers, questions.Count);
            }
        }

        /// <summary>
        /// Asks the user for a list of questions and answers.
        /// </summary>
        /// <returns>A ValueTuple with questions and answers.</returns>
        static (List<string>, List<string>) CreateQuestionsAndAnswers() {
            var questions = new List<string>();
            var answers = new List<string>();

            var i = 1;
            Console.WriteLine("*********** Enter Questions **************");
            while (true) {
                Console.Write($"\n\nEnter Question #{i} or Q(uit): ");
                var input = Console.ReadLine();
                if (input == null || input.ToLower() == "q")
                    break;
                questions.Add(input);

                Console.Write($"\nEnter Answer #{i}: ");
                answers.Add(Console.ReadLine());

                i++;
            }
            return (questions, answers);
        }

        /// <summary>
        /// Asks the user the questions and returns the total
        /// number of correct answers.
        /// </summary>
        /// <param name="questions">The list of questions.</param>
        /// <param name="answers">The list of answers.</param>
        /// <returns>The total number of correct answers.</returns>
        static int TakeQuiz(List<string> questions, List<string> answers) {
            var totalCorrectAnswers = 0;

            Console.WriteLine("\n\n*************** Take Quiz ******************");
            for (int i = 0; i < questions.Count; i++) {
                Console.Write($"\n\n{i}. {questions[i]} ");
                var userAnswer = Console.ReadLine();
                if (userAnswer == answers[i]) {
                    Console.WriteLine("\nCorrect!");
                    totalCorrectAnswers++;
                }
                else {
                    Console.WriteLine($"\nIncorrect. Answer is {answers[i]}.");
                }
            }

            return totalCorrectAnswers;
        }

        /// <summary>
        /// Prints total correct answers, percent correct, and letter grade.
        /// </summary>
        /// <param name="totalCorrectAnswers">Total number of correct answers.</param>
        /// <param name="totalQuestions">Total number of questions.</param>
        static void PrintResults(int totalCorrectAnswers, int totalQuestions) {
            int percentCorrect = (int) ((float)totalCorrectAnswers / totalQuestions * 100 + 0.5);

            char letterGrade;
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

            Console.WriteLine("\n\n*************** Results ******************\n\n");
            Console.WriteLine($"Total Correct Answers: {totalCorrectAnswers}/{totalQuestions}");
            Console.WriteLine($"Percent Correct: {percentCorrect}%");
            Console.WriteLine($"Letter Grade: {letterGrade}");

            Console.WriteLine("\n\nPress enter key to quit.");
            Console.Read();
        }
    }
}
