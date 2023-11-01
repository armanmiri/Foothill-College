/*
 
Arman Miri
CS F002A
10/06/21
Harden
a3_1
Assignment 3 Part 1
 
This program asks the user if they want to caluclate the area for a square or triangle,
then it asks for the necessary componets of base, height, side length in order to calculate the area.
 
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    char figure;
    double side;
    double base;
    double height;
    // declaring the variables that will be used
   
    cout << "Enter the type of figure s for square or t for triangle): ";
    // asks the user what figure they want to calculate the area for
   
    cin >> figure;
    // stores the figure to be calulated
    
    cout << "\n";
    // creates space in output
    
    if (figure == 's')
    // if user enters s for square
    {
            cout << "Enter side length: ";
            // asks user for side length of square
        
            cin >> side;
            // stores the user input for side length
            
            cout << "\n";
            // creates space in output
            
            cout << fixed << setprecision(1) << "The area is " << (side * side) << ". \n \n";
            // calulates and writes the area of the square rounded to one deicmal place
            
    }
     
    if (figure == 't')
    // if user enters t for triangele
    {
            cout << "Enter base length: ";
            // asks user for base length of triangle
        
            cin >> base;
            // stores the user input for base length
        
            cout << "\n";
            //c reates space in output
        
            cout << "Enter height: ";
            // asks user for height
        
            cin >> height;
            // stores user input for height
        
            cout << "\n";
            // creates space in output
            
            cout << fixed << setprecision(1) << "The area is " << ((base * height) * 0.5) << ". \n \n";
            // calulates and writes the area of the triangle rounded to one deicmal place
        
    }
    
    return 0;
    
}

/*

 Enter the type of figure s for square or t for triangle): t

 Enter base length: 7

 Enter height: 3

 The area is 10.5.
  
 Program ended with exit code: 0
 
*/

/*
 
 Enter the type of figure s for square or t for triangle): s

 Enter side length: 9

 The area is 81.0.
  
 Program ended with exit code: 0
 
 */
