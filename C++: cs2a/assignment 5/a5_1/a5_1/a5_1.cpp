/*
 
Arman Miri
CS F002A
10/18/21
Harden
a5_1
Assignment 5 Part 1
 
This program asks the user how many numbers will be entered, then lets the user enter those numbers.
After the user is done entering their numbers the program will then write the position of the first and
last 7 that the user entered.
 
*/

#include <iostream>
using namespace std;

const int TARGETNUMBER = 7;
// setting the constant integer for 7/ target number

int main()
{
    
    int numbersentered;
    int inputnumbers;
    // integers for the user input
    
    int firstentry = 0;
    int lastentry = 0;
    int entrycounter = 0;
    int targetsentered = 0;
    // integers for the analysis of the position
    
    do
    // creation of do while loop to make the user run the code
        
    {
        
    cout << "How many numbers will be entered? ";
    // asks the user how many numbers they want to enter
        
    cin >> numbersentered;
    // stores the user input for how many numbers will be entered
        
    for (entrycounter = 0; entrycounter < numbersentered; entrycounter++)
    // for statment to ask the user to input the amount of numbers that they entered and counts the amount of times the code is ran
        
        {
                
        cout << "Enter num: ";
        // tells the user to enter a number
            
        cin >> inputnumbers;
        // stores the user input for number
            
            
        if (inputnumbers == TARGETNUMBER && targetsentered == 0)
        // if the target number is entered and it is the first entry
            
        {
            firstentry = entrycounter + 1;
            lastentry = entrycounter + 1;
            // sets the first and last integer to number of the entry
            
            targetsentered++;
            // counts the number of times the target number was entered
            
        }
            
        if (inputnumbers == TARGETNUMBER && targetsentered > 0)
        // if the target number is entered and it is after the first entry
            
        {
            lastentry = entrycounter + 1;
            // set the last entry to the entry number
        
        }
            
        }
        
        break;
        // breaks the do while loop
        
        } while(entrycounter < numbersentered);
        // condition to run the do while loop as long as the the number of times it is ran is less than the number of times the said they will enter numbers
        
    if (targetsentered > 0)
    // if the number of times 7 was entered is greater than 0
        
    {
        cout << "The first 7 was in position " << firstentry << "\n";
        // writes the position of the first 7
        
        cout << "The last 7 was in position " << lastentry << "\n \n";
        // writes the position of the last 7
    }
    
    else if (targetsentered == 0)
    // if the number of times 7 was entered is equal than 0
        
    {
        cout << "Sorry no 7's were entered. \n \n";
        // tells the user no 7's were entered
    }
      
    return 0;
    
}
    
/*
 
 How many numbers will be entered? 8
 Enter num: 5
 Enter num: 7
 Enter num: 6
 Enter num: 7
 Enter num: 7
 Enter num: 3
 Enter num: 8
 Enter num: 6
 The first 7 was in position 2
 The last 7 was in position 5
  
 Program ended with exit code: 0
 
*/
    
/*
 
 How many numbers will be entered? 8
 Enter num: 5
 Enter num: 2
 Enter num: 6
 Enter num: 7
 Enter num: 1
 Enter num: 3
 Enter num: 8
 Enter num: 6
 The first 7 was in position 4
 The last 7 was in position 4
  
 Program ended with exit code: 0
 
*/

/*
   
 How many numbers will be entered? 8
 Enter num: 5
 Enter num: 1
 Enter num: 6
 Enter num: 5
 Enter num: 9
 Enter num: 3
 Enter num: 8
 Enter num: 6
 Sorry no 7's were entered.
  
 Program ended with exit code: 0
   
  */
      
    
