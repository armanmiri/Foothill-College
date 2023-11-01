/*
 
Arman Miri
CS F002A
10/12/21
Harden
a4_1
Assignment 4 Part 1
 
This function asks for the user if they want to use the converter to change pounds to
ounces. If the user says yes then it ask the usre to input the weight they want to
convert from pounds to ounces. After conversion it asks the user if they want to convert
again or end the program.
 
*/

#include <iostream>
using namespace std;

int main()
{
    int pounds;
    int ounces;
    // declaring the variables for calculation
    
    char response;
    // stores the user response
    
    cout << "Would you like to use the pound to ounce converter, y for yes and n for no. ";
    // asks the user if they want to use the converter
    
    cin >> response;
    // stores the user response for wanting to use the conveter
    
    while (response == 'y')
    // if the says they want to use the converter
        
    {
        
    cout << "\n" << "Enter the weight in pounds you want to convert to ounces: ";
    // asks the user the weight in pounds they want to convert
        
    cin >> pounds ;
    // stores the user input for pounds
        
    ounces = pounds * 16;
    // converts pounds to ounces
        
    cout << "\n" << pounds << " pounds is equal to ";
    cout << ounces << " ounces." << "\n \n";
    // tells the user the converted weight in ounces
        
    cout << "Would you like to convert another weight, y for yes and n for no? ";
    // asks the user if they want to convert another weight
        
    cin >> response;
    // stores the user response to wanting to use the re-use the converter
        
    }
    
    cout << "\n" << "Thanks for using the pounds to ounces converter. \n \n";
    // thanks the user for using the program
    
    return 0;
    
}


/*
 
 Would you like to use the pound to ounce converter, y for yes and n for no. y

 Enter the weight in pounds you want to convert to ounces: 1

 1 pounds is equal to 16 ounces.
  
 Would you like to convert another weight, y for yes and n for no? y

 Enter the weight in pounds you want to convert to ounces: 2

 2 pounds is equal to 32 ounces.
  
 Would you like to convert another weight, y for yes and n for no? n

 Thanks for using the pounds to ounces converter.
  
 Program ended with exit code: 0
 
*/
