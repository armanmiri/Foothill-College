/*
 
Arman Miri
CS F002A
10/12/21
Harden
a4_3
Assignment 4 Part 3
 
Fill in when done with summary of program
 
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int children = 0;
const int youngadult = 19;
const int adults = 31;
const int middleage = 41;
const int elderly = 60;

int main()
{
    int age;
    int count = 0;
    int totalages = 0;
    int youngest;
    int oldest;
    int foodprefrence;
    int popcorn = 0;
    int bothfood = 0;
    int soda = 0;
    int group1 = 0;
    int group2 = 0;
    int group3 = 0;
    int group4 = 0;
    int group5 = 0;
    // declaring the variables for calculation
    
  
    cout << "Enter age of attendee (negative number to quit): ";
    // asks the user the weight in pounds they want to convert with the option to stop the program
        
    cin >> age;
    // stores the user input for pounds

    
    youngest = age;
    
    oldest = age;
    
    while (age >= 0)
    // runs the conversion if user input is postiive, if negative it skips conversion
        
    {
        
        if (age < youngadult && age > children)
        {
            group1++;
        }
        
        else if (age >= youngadult && age < adults)
        {
            group2++;
        }
        
        else if (age >= adults && age < middleage)
        {
            group3++;
        }
        
        else if (age >= middleage && age < elderly)
        {
            group4++;
        }
        else if (age >= elderly)
        {
            group5++;
        }
        
        if (age < youngest)
        {
            
        youngest = age;
            
        }
        
        if (age > oldest)
        {
            
        oldest = age;
            
        }
        
        totalages = totalages + age;
        
        cout << "Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): ";
        
        cin >> foodprefrence;
        
        if (foodprefrence == 'p')
        {
            popcorn++;
        }
        
        else if (foodprefrence == 's')
        {
            soda++;
        }
        
        else if (foodprefrence == 'b')
        {
            bothfood++;
        }
        
        
        cout << "Enter age of attendee (negative number to quit): ";
        // asks the user the weight in pounds they want to convert with the option to stop the program
            
        cin >> age ;
        // stores the user input for pounds
        

        count++;
    }
    
  
    if (count == 0)
    {
    
    cout << "\n" << "age 0 to 18: " << group1 << "\n";
        
    cout << "age 19 to 30: " << group2 << "\n";
        
    cout << "age 31 to 40: " << group3 << "\n";
        
    cout << "age 41 to 60: " << group4 << "\n";
        
    cout << "over 60: " << group5 << "\n";
        
    cout << "\n" << "There is no food preference because you didn't enter any numbers! \n";
        
    cout << "There is no average age becuase you did not enter any numbers! \n";
        
    cout << "There is no youngest person in attendance because you didn't enter any numbers! \n";
        
    cout << "There is no oldest person in attendance because you didn't enter any numbers! \n \n";
    
    }
    
    else
    {
        
    cout << "\n" << "age 0 to 18: " << group1 << "\n";
            
    cout << "age 19 to 30: " << group2 << "\n";
            
    cout << "age 31 to 40: " << group3 << "\n";
            
    cout << "age 41 to 60: " << group4 << "\n";
            
    cout << "over 60: " << group5 << "\n";
        
    cout << "\n" << "food preference popcorn: " << popcorn << "\n";
        
    cout << "food preference soda: " << soda << "\n";
        
    cout << "food preference both: " << bothfood << "\n";
        
    cout << setprecision(2) << fixed << "The average of age was " << totalages/count << "\n";
    
    cout << "The youngest person in attendance was " << youngest << "\n";
        
    cout << "The oldest person in attendance was " << oldest << "\n \n";
        
    }
    
    return 0;
    
}


/*
 
 copy the ouput text when done

*/
