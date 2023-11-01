/*
 
Arman Miri
CS F002A
10/18/21
Harden
a5_2
Assignment 5 Part 2
 
This program asks the user to input the value for which they want the sum of squares for. The
program then calculates the sum of squares and tells the user. Then asks the user for a new input value
for which they want the some of squares for. At any point in the code when the user is asked to input the user
can enter a value less than 1 to stop the program.
 
*/

#include <iostream>
using namespace std;


int main()
{

    int numinput;
    // integer for user input
    
    int squaresum = 0;
    // the total for sum of squares
    
    int n;
    // integer for calculation in for loop
    
    cout << "Enter a number greater than 0 (less than 1 to quit): ";
    // asks the user to enter a number
    
    cin >> numinput;
    // stores user input for number

    while (numinput > 0)
    // while loop to caluclate the sum or sqaures as long as user input is greater than 0
        
    {
   
    for (n=1; n<=numinput; n++)
    // for statment to calculate the sum of squares based on the user input
    {
        
        squaresum += (n * n);
        // calculates the square and then adds it to the squaresum integer as long as the for loop runs
        
    }
        
    
    cout << "The sum of squares from 1 to " << numinput << " is " << squaresum << "\n";
    // tells the user the sum of squares

    squaresum = 0;
    // resets the sum of sqaures to 0
        
    cout << "Enter a number greater than 0 (less than 1 to quit): ";
    // asks the user to enter a number to continue or less than 1 to stop the loop
        
    cin >> numinput;
    // stores user input for number
        
    }
        
    cout << "\n";
    // creates space in result
    
    return 0;
    
}
    
/*
 
 Enter a number greater than 0 (less than 1 to quit): 4
 The sum of squares from 1 to 4 is 30
 Enter a number greater than 0 (less than 1 to quit): 1
 The sum of squares from 1 to 1 is 1
 Enter a number greater than 0 (less than 1 to quit): 0

 Program ended with exit code: 0
 
*/
    
