/*
 
Arman Miri
CS F002A
10/06/21
Harden
a3_2
Assignment 3 Part 2
 
This program asks for the user to enter the number of completed educational years,
of the student, for who they want to find out the type of school they are in,
and outputs the type of school the student is in.
 
*/

#include <iostream>
using namespace std;

const int ELEMENTARYSCHOOL = 1  ;
const int MIDDLESCHOOL = 7 ;
const int HIGHSCHOOL = 9 ;
const int COLLEGE = 13 ;
// declaring the cosntant values for the calulation

int main()
{

    int schoolyears;
    // declaring the varible that will be used
    
    cout << "Enter how many years of school the student has completed: ";
    // asks the user for the number of completed school years
    
    cin >> schoolyears;
    // stores the user input for number of completed school years
    
    cout << "\n";
    // creates space in output
    
    if (schoolyears < 0)
    // if the user enters a value that is not valid
        
    {
        
        cout << "years of schools need to be a non-negative integer.";
        // tells the user their input is not valid
        cout << "\n \n";
        // creates space in output
        
    }
    
    if (schoolyears == 0)
    // if the user enters 0 completed years
        
    {
        
        cout << "The student does not go to school.";
        // writes that the student is not in school
        
        cout << "\n \n";
        // creates space in output
        
    }
    
    if ((schoolyears >= ELEMENTARYSCHOOL) && (schoolyears < MIDDLESCHOOL))
    // if the user enters an input ranging from 1-6
        
    {
        
        cout << "The student is in elementary school.";
        // writes that the student is in elementary school
        
        cout << "\n \n";
        // creates space in output
        
    }
    
    if ((schoolyears >= MIDDLESCHOOL) && (schoolyears < HIGHSCHOOL))
    // if the user enters an input ranging from 7-8
        
    {
        
        cout << "The student is in middle school.";
        // writes that the student is in middle school
        
        cout << "\n \n";
        // creates space in output
        
    }
    
    if ((schoolyears >= HIGHSCHOOL) && (schoolyears < COLLEGE))
    // if the user enters an input between 9-12
        
    {
        
        cout << "The student is in high school.";
        // writes that the student is in high school
        
        cout << "\n \n";
        // creates space in output
        
    }
    
    if (schoolyears > COLLEGE)
    // if the user enters an input greater than 12
        
    {
        
        cout << "The student is in college.";
        // writes that the student is in college
        
        cout << "\n \n";
        // creates space in output
        
    }
    
    return 0;
    
}
    
    

/*

 Enter how many years of school the student has completed: 7

 The student is in middle school.
  
 Program ended with exit code: 0
 
*/
