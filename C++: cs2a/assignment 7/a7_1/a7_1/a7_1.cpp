/*
 
Arman Miri
CS F002A
11/6/21
Harden
a7_1
Assignment 7 Part 1
 
This program asks the user to answer a series of arithmetic problems and evaluates thier responses.
The program asks the user how many problems they want when they are asked a set of problems. Then the programa
asks the user to input hte answer to problems then printing the result if their answer was correct or not. At
the end the results per set the program will write the percentage correct out of each set and the overall
accuracy of the problems
 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


void doOneSet(char setOp, int probsPerSet, int &score);
void doOneProblem(char op, int maxNumber, int &score);
void generateOperands(int &opAndOne, int &opAndTwo, int maxNumPlusOne);
void calculateCorrectAnswer(int firstNum, int secondNum, int &solution, char op);
void checkAnswer(int solution, int answerinput, int &score);
void getProbsPerSet(int &probsPerSet);
void printHeader(char op);
void getMaxNum(int &maxNum);
void printReport(int scoreSetOne, int scoreSetTwo, int scoreSetThree, int numOfProblems);
// declaration of functions for the program

int main()
    {
        int scoreSetOne = 0;
        int scoreSetTwo = 0;
        int scoreSetThree = 0;
        int probsPerSet;
        // declaration of variables
            
        srand(static_cast <unsigned> (time(0)));
        getProbsPerSet(probsPerSet);
        // the function generates the problems the user to answer in the set
    
        doOneSet('+', probsPerSet, scoreSetOne);
        doOneSet('-', probsPerSet, scoreSetTwo);
        doOneSet('*', probsPerSet, scoreSetThree);
        // gets the user to answer questions for 3 sets of problems
    
        printReport(scoreSetOne, scoreSetTwo, scoreSetThree, probsPerSet);
        // writes out the score of each individual set and the overall score with percentages.
    }





// This function prints a header using the printHeader function for the set of problems, then will ask the
// user what they want the greatest number to be in their problems using the getMaxNum function. Then it
// provides user a question meeting their inputs, and continues to do so until the number of problems
// provided meets the user input for porbsPerSet from the getProbsPerSet function.
void doOneSet(char setOp, int probsPerSet, int &score)
    {
        int nummax;
        // declaring the variable nummax
    
        printHeader(setOp);
        // prints the header for the set
    
        getMaxNum(nummax);
        // gets the user input for what they want the max value to be in the set of problems
    
        for (int n = 0; n < probsPerSet; n++)
        // for when the number of problmes is less than the number of problems per set the user inputed
        {
            doOneProblem(setOp, nummax, score);
            // the user is asked a problem and told if their answer is correct or incorrect
        }
    }





// This function asks the user a single problem and then calculates the correct answer for the doOneSet
// function. Then it compares the user input to the correct answer writing out if the user input the correct
// or incorrect answer using the calculateCorrectAnswer and the checkAnswer functions.
void doOneProblem(char op, int maxNumber, int &score)
    {
        int opAndOne;
        int opAndTwo;
        // declaring integers for the problem
    
        int answerinput;
        // declaring the integer to store the user response
    
        int solution;
        // declaring the integer for the correct solution
    
        generateOperands(opAndOne, opAndTwo, maxNumber + 1);
        // generates two numbers for the problem
    
        cout << opAndOne << " " << op << " " << opAndTwo << " = ";
        // asks the user the problem
    
        cin >> answerinput;
        // stores the user input for the answer to the problem
    
        calculateCorrectAnswer(opAndOne, opAndTwo, solution, op);
        // calculates the correct answer to the problem
    
        checkAnswer(solution, answerinput, score);
        // checks the user input with the correct solution and writes if the user was correct or incorrect
    
    }





// This function generates random operands for the problems that will presented to the user in the
// doOneProblem function.
void generateOperands(int &opAndOne, int &opAndTwo, int maxNumPlusOne)
    {
        opAndOne = rand() % (maxNumPlusOne);
        opAndTwo = rand() % (maxNumPlusOne - opAndOne);
        // generate two random operands for the problem
    
    }





// This function calculates the correct answer for problems based on the operator being using in the main
// function in order to solve the problem and check the user input in the check answer function
void calculateCorrectAnswer(int firstNum, int secondNum, int &solution, char op)
    {
        switch (op)
        // based on the operator
        {
            case '+':
            // if op is addition
                
                solution = firstNum + secondNum;
                // solution is the two numbers added together
                
                break;
                // stops the switch statement
                
            case '-':
            // if op is minus
                
                solution = firstNum - secondNum;
                // solution is the first number minus the second number
                
                break;
                // ends the switch statement
                
            case '*':
            // if op is product
                
                solution = firstNum * secondNum;
                // solution is the product of first and second number
                
                break;
                // ends the switch statement
                
            default:
            // if op doesn't match any of the other cases
                
                break;
                // end switch statement
        }
    }





// This function checks the users answer and writes out if the answer was correct or incorrect. This also
// keeps track of the number of correct problems the user has had to write out in the printReport function.
// This function is implemented in the doOneProblem function to tell the user if their input for correct or
// not after they answer the question they are asked.
void checkAnswer(int solution, int answerinput, int &score)
    {
       if(answerinput == solution)
       // if users answer is equal to the correct answer
       {
           cout << "correct \n";
           // writes out correct
           
           score += 1;
           // adds one to the score keep variable
       }
    
       else
       // if the user answer is not equal to the correct answer
       {
           cout << "incorrect \n";
           // writes out incorrect
       }
    
    }





// This function asks and stores the user input for how many problems they want in a set after being
// initiated in the main function. This is then used the doOneSet function to asks the number of questions
// that the user inputed for.
void getProbsPerSet(int &probsPerSet)
    {
        cout << "Enter the number of problems you want per set: ";
        // asks the user the number of problems they want per set
    
        cin >> probsPerSet;
        // stores the user input for the number of problems per set
    }





// This function writes out a header for the set of problems that follow it based on what the operator is for
// that set. This is determined in the main function
void printHeader(char op)
    {
        switch (op)
        // based on the value stored in the op character
        {
            case '+':
            // if op is addition
                
                cout << "\n" << "Set #1" << "\n" << "---------- \n";
                // writes out the header for set 1
                
                break;
                // ends switch statement
                
            case '-':
            // if op is minus
                
                cout << "\n" << "Set #2" << "\n" << "---------- \n";
                // writes out the header for set 2
                
                break;
                // ends switch statement
                
            case '*':
            // if op is product
                
                cout << "\n" << "Set #3" << "\n" << "---------- \n";
                // writes out the header for set 3
                
                break;
                // ends the switch statement
                
            default:
            // if op is not any of the other cases
                
                break;
                // end switch statement
        }
    }





// This function asks and stores the user for they want the maximum number to be for the set, to be used in
// the generate opperands function
void getMaxNum(int &maxNum)
    {
        cout << "What do you want the maximum number for this set to be? ";
        // asks the user what they want the max number for the problems in the set to be
    
        cin >> maxNum;
        // stores the user input for the maximum number in the problems
    
        cout << "\n";
        // creates space in result
    }





// This function writes out the results from the user responses after being prompted to do so in the main
// function. This provides the number of correct answers per set along with its percentage of accuracy. It
// does so for the overall accuracy as well.
void printReport(int scoreSetOne, int scoreSetTwo, int scoreSetThree, int probsPerSet)
    {
        int totalCorrect = scoreSetOne + scoreSetTwo + scoreSetThree;
        // declares totalCorrect variable and calculates the total correct answers inputed
    
        int totalProblems = probsPerSet * 3;
        // declaires totalProblems variable and calculates the total number of problems
        
        cout << "\n";
        // creates space in result
    
        cout << fixed << setprecision(1) << "Set One: Your score was " << scoreSetOne << " out of " <<
        probsPerSet <<  " for " << (static_cast < double > (scoreSetOne) / probsPerSet) * 100 << "%\n";
        // tells the user the score for set one and calculates and writes the percentage of accuracy they had
        
        cout << fixed << setprecision(1) << "Set Two: Your score was " << scoreSetTwo << " out of " <<
        probsPerSet <<  " for " << (static_cast < double > (scoreSetTwo) / probsPerSet) * 100 << "%\n";
        // tells the user the score for set two and calculates and writes the percentage of accuracy they had
    
        cout << fixed << setprecision(1) << "Set Three: Your score was " << scoreSetThree << " out of " <<
        probsPerSet <<  " for " << (static_cast < double > (scoreSetThree) / probsPerSet) * 100 << "%\n";
        // tells the user the score for set three and calcuates and writes the percentage of accuracy they had
     
        cout << "Overall you got " << totalCorrect << " correct out of " << totalProblems << " for "
        << (static_cast<double>(totalCorrect) / totalProblems) * 100 << "%\n\n";
        // tells the user their overall score and calcuates and writes the overall percentage of accuracy they had
    }

    
/*
 
 Enter the number of problems you want per set: 3

 Set #1
 ----------
 What do you want the maximum number for this set to be? 100

 53 + 36 = 86
 incorrect
 34 + 60 = 94
 correct
 61 + 5 = 66
 correct

 Set #2
 ----------
 What do you want the maximum number for this set to be? 75

 53 - 6 = 48
 incorrect
 33 - 22 = 11
 correct
 59 - 1 = 58
 correct

 Set #3
 ----------
 What do you want the maximum number for this set to be? 20

 12 * 3 = 35
 incorrect
 14 * 4 = 3
 incorrect
 0 * 14 = 0
 correct

 Set One: Your score was 2 out of 3 for 66.7%
 Set Two: Your score was 2 out of 3 for 66.7%
 Set Three: Your score was 1 out of 3 for 33.3%
 Overall you got 5 correct out of 9 for 55.6%

 Program ended with exit code: 0
 
*/
    
