/*
 
Arman Miri
CS F002A
11/26/21
Harden
a10_1
Assignment 10 Part 1
 
This program reads up to 1000 user inputs of positive integers and stores distinct numbers in an array. If a
number is to be repeated the program will not store it. Then the program writes out the distinct numbers the user
entered in the order they were entered.
 
*/

#include <iostream>
using namespace std;

const int MAXNUMINPUTS = 1000;

void getNums(int numsArray[], int &count);
void writeArray(const int numsArray[], int size);
// declaration of fucntions for the program

bool analyzeArray(int number, const int numsArray[], int size);
// declaration of boolean for the program


int main()
{
    int numsArray[MAXNUMINPUTS];
    int count = 0;
    // declartion of varibles for functions

    getNums(numsArray, count);
    // the function asks the user for thier inputs and stores them
    
    writeArray(numsArray, count);
    // the function writes out the users distinct inputs

}





// This function asks the user to enter their non negative integer to start the program or a negative integer to quit.
// When the user enters their number if it is positive the program will analyze the array using the analyzeArray function
// to check if the number is already stored, if the called function returns false then it skips adding it, if it returns
// true the number is added to the array and will be stored in the order of input for ease when printing the array. If
// a negative input is put in the functon quits.
void getNums(int numsArray[], int &count)
{
    int num;
    // declaring the variable for num
    
    cout << "Enter a non-negative integer (negative to quit): ";
    // asks the user to enter a number with the option to quit with a negative number
    
    cin >> num;
    // stores the user input under the integer num
    
    while (num >= 0)
    // runs while the inputed number is greater than 0
    {
        if (analyzeArray(num, numsArray, count))
        // if the numbered entered returns true don't run, if it returns false run
        {
            numsArray[count++] = num;
            // add number to the array
        }
        
        cout << "Enter a non-negative integer (negative to quit): ";
        // asks the user to enter a number with the option to quit with a negative number
        
        cin >> num;
        // stores the user input under the integer num
    }
}





// This function writes out the array that was used to store the distinct numbers that the user inputed,
// in the order the user inputed.
void writeArray(const int numsArray[], int count)
{
    cout << "You entered:" << "\n";
    //starts to write to the user the numbers they entered
    
    for (int n = 0; n < count; n++)
    // for when the numbers placement in the array is less than that of the integer count which represents the number of distinct values in the array
    {
        cout << numsArray[n] << " ";
        // write the value represented by the placement n in the array
    }
    
    cout << "\n \n";
    // creates space in result
}





// This boolean function analyzes the array to check if the number that was inputed is already stored.
// If the number is stored it returns false and if not it returns true for the function calling on it.
bool analyzeArray(int num, const int numsArray[], int count)
{
    for (int n = 0; n < count; n++)
    // for when the numbers placement in the array is less than that of the integer count which represents the number of distinct values in the array
    {
        if (numsArray[n] == num)
        // if the number is in the array
        {
            return false;
            // return false
        }
    }
    return true;
    // if the if loop breaks return true otherwise this line wont be runned
}


/*
 
 Enter a non-negative integer (negative to quit): 1
 Enter a non-negative integer (negative to quit): 2
 Enter a non-negative integer (negative to quit): 3
 Enter a non-negative integer (negative to quit): 2
 Enter a non-negative integer (negative to quit): 1
 Enter a non-negative integer (negative to quit): 6
 Enter a non-negative integer (negative to quit): 3
 Enter a non-negative integer (negative to quit): 4
 Enter a non-negative integer (negative to quit): 5
 Enter a non-negative integer (negative to quit): 2
 Enter a non-negative integer (negative to quit): -4
 You entered:
 1 2 3 6 4 5
  
 Program ended with exit code: 0
 
*/
      
    
