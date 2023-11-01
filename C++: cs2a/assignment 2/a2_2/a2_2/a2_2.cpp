/*
Arman Miri
CS F002A
09/29/21
Harden
a2_2
Assignment 2 Part 2
 
This program asks the user for the tempuraeture in celcius
then it converts it to fahrenheit.
*/

#include <iostream>
using namespace std;

int main()
{
    int Celcius;
    // input vlaue
    
    int Fahrenheit;
    // output value
  
    cout << "Enter the tempurature in Celcius that you want to convert to Fahrenheit: ";
    cin >> Celcius ;
    //asks user for input and stores it under integer celcius
    
    Fahrenheit = (((9 * Celcius) / 5) + 32);
    //converts the user input from celcius to faherenheit
    
    cout << "\n";
    //creates space in result
    
    cout << Celcius << " degress Celcius is " << Fahrenheit << " degrees Fahrenheit. \n \n";
    //tells the user the final converted tempurature

    return 0;
    
}

/*
 
 Enter the tempurature in Celcius that you want to convert to Fahrenheit: 30

 30 degress Celcius is 86 degrees Fahrenheit.
  
 Program ended with exit code: 0
 
*/
