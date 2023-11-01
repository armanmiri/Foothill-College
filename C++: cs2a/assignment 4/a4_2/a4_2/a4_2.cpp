/*
 
Arman Miri
CS F002A
10/12/21
Harden
a4_2
Assignment 4 Part 2
 
This function asks for the user to input the weight they want to convert from pounds to ounces,
with the ability stop the function from converting the pounds to ounces before conversion by
entering a negative number. After an inital conversion the function asks for a new weight in
pounds, allowing the user to end the program or continue on.
 
*/

#include <iostream>
using namespace std;

int main()
{
    int pounds;
    int ounces;
    // declaring the variables for calculation
    
    cout << "Enter the weight in pounds you want to convert to ounces (negative number to quit): ";
    // asks the user the weight in pounds they want to convert with the option to stop the program
        
    cin >> pounds ;
    // stores the user input for pounds
    
    while (pounds >= 0)
    // runs the conversion if user input is postiive, if negative it skips conversion
        
    {
        
    ounces = pounds * 16;
    // converts pounds to ounces
        
    cout << "\n" << pounds << " pounds is equal to ";
    cout << ounces << " ounces." << "\n \n";
    // tells the user the converted weight in ounces
    
    cout << "Enter the weight in pounds you want to convert to ounces (negative number to quit): ";
    // asks the user the weight in pounds they want to convert
            
    cin >> pounds ;
    // stores the user input for pounds
        
    }
    
    cout << "\n" << "Thanks for using the pounds to ounces converter. \n \n";
    // thanks the user for using the program
    
    return 0;
    
}


/*
 
 Enter the weight in pounds you want to convert to ounces (negative number to quit): 1

 1 pounds is equal to 16 ounces.
  
 Enter the weight in pounds you want to convert to ounces (negative number to quit): -1

 Thanks for using the pounds to ounces converter.
  
 Program ended with exit code: 0

*/
