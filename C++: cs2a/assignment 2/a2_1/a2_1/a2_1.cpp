/*
Arman Miri
CS F002A
09/29/21
Harden
a2_1
Assignment 2 Part 1
 
This program asks the user for the number of cents they want change for,
then it converts to coins.
 */

#include <iostream>
using namespace std;

const int NICKELVALUE = 5;
const int DIMEVALUE = 10;
const int QUARTERVALUE = 25;
// constant values for coins


int main()
{
  
    int cents;
    
    cout << "Enter the number cents do you want to convert to change: ";
    // asks the user for their input of cents
    
    cin >> cents ;
    //stores user input for cents under integer cents
    
    cout << "\n";
    //creates space
    
    cout << "You will need \n";
    
    cout << "Pennies: " << cents % NICKELVALUE << "\n";
    // prints and calculates pennies
    
    cout << "Nickels: " << (((cents % QUARTERVALUE) % DIMEVALUE) / NICKELVALUE) << "\n";
    // prints and calculates nickels
    
    cout << "Dimes: " << ((cents % QUARTERVALUE) / DIMEVALUE) << "\n";
    // prints and calculates dimes
    
    cout << "Quarters: " << cents / QUARTERVALUE << "\n \n";
    // prints and calculates quarters

    return 0;
}

/*
 
 Enter the number cents do you want to convert to change: 119

 You will need
 Pennies: 4
 Nickels: 1
 Dimes: 1
 Quarters: 4
  
 Program ended with exit code: 0
 
*/
