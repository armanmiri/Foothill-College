/*
 
Arman Miri
CS F002A
10/06/21
Harden
a3_3
Assignment 3 Part 3
 
This function asks the user for an inital number then the function they want to use to solve, then
the next another number, then calcualtes and writes the reusult. There is inclusion for decimals
 
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char op;
    // variable for operator
        
    double number1;
    double number2;
    // variable for number inputs

    cout << "Enter your inital number for the calculation: ";
    // Asks the user to enter thier inital number for calualtion
    
    cin >> number1;
    // stores the users input for the inital number
    
    cout << "\n";
    // creates space in output
    
    cout << "Enter operator from +, -, *, /: ";
    // asks for the user to enter the operator they want to use
    
    cin >> op;
    // stores the user input for the operator
    
    cout << "\n";
    // creates space in output

    cout << "Enter you second number for the calulation: ";
    // asks the user to enter their second number for calulation
    
    cin >> number2;
    // stores the user input for the second input
    
    cout << "\n";
    // creates space in output
    
    switch(op)
    // switch based on operator
    {
            case '+':
            // if the user enters addition for operator
            
                cout << setprecision(2) << fixed << number1 + number2 << "\n";
                // writes the sum of the two user inputs rounded to 2 decimal points
                
                cout << "\n";
                // creates space in output
            
                break;
                // terminates the case in the switch

            case '-':
            
                cout << setprecision(2) << fixed << number1 - number2 << "\n";
                // writes the difference of the two user inputs rounded to 2 decimal points
            
                cout << "\n";
                // creates space in output
                
                break;
                // terminates the case in the switch

            case '*':
            
                cout << setprecision(2) << fixed << number1 * number2 << "\n";
                // writes the product of the two user inputs rounded to 2 decimal points
            
                cout << "\n";
                // creates space in output
                
                break;
                // terminates the case in the switch

            case '/':
            
                cout << setprecision(2) << fixed << number1 / number2 << "\n";
                // writes the quotient of the two user inputs rounded to 2 decimal points
            
                cout << "\n";
                // creates space in output
            
                break;
                // terminates the case in the switch

            default:
                
                cout << "Error! not a vaild input. \n";
                // tells user the input is not valid
            
                cout << "\n";
                // creates space in output
                
                break;
                // terminates the case in the switch
        }

        return 0;
    }

/*

 Enter your inital number for the calculation: 5

 Enter operator from +, -, *, /: /

 Enter you second number for the calulation: 2

 2.50

 Program ended with exit code: 0
 
*/
