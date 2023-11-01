/*
 
Arman Miri
CS F002A
10/12/21
Harden
a4_3
Assignment 4 Part 3
 
This program helps the user analyize information for attendees at an event. The function askss the user to input
the age of the attendee, and then their food preference. While allowing the user to end the program if they enter
a negative number for the age input. The program will repeat as long as the user puts in a positive integer, but
will prompt the user that they can quit if they use a negative integer. Then the program sorts the user inputs for
age by giving the oldest, youngesst, and average age, also, tells the user the number of individuals for each food
preference. The program also writes the number of entered attendees in the age groups of 0-18, 19-30, 31-40, 41-60,
and 60+.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int children = 0;
const int youngadult = 19;
const int adults = 31;
const int middleage = 41;
const int elderly = 60;
// constants for age sorting

int main()
{
    int age;
    // user input for age
    
    int count = 0;
    // counts the while loop
    
    double totalages = 0;
    // stores the total age that is inputed
    
    int youngest;
    // the youngest age input
    
    int oldest;
    // the oldest age input
    
    char foodprefrence;
    // the food prefrenece
    
    int popcorn = 0;
    int bothfood = 0;
    int soda = 0;
    // sum of each input for food prefrences
    
    int group1 = 0;
    int group2 = 0;
    int group3 = 0;
    int group4 = 0;
    int group5 = 0;
    // groups for age sorting
   
  
    cout << "Enter age of attendee (negative number to quit): ";
    // asks the user for the age of the attende they want to input, with option to quit
        
    cin >> age;
    // stores the user input for age

    youngest = age;
    // sets the youngest age
    
    oldest = age;
    // sets the oldest age
    
    while (age >= 0)
    // continues the input for the user if the user input is postiive, if negative it skips sorting
        
    {
        
        if (age < youngadult && age > children)
        // if user is in the age bounds of 0 to 18
            
        {
            group1++;
            // adds one to group 1
        }
        
        else if (age >= youngadult && age < adults)
        // if the user is in the age group 19-30
            
        {
            group2++;
            // adds one to group 2
        }
        
        else if (age >= adults && age < middleage)
        // if the user is in the age bounds of 31-40
        {
            group3++;
            // adds one ot group 3
        }
        
        else if (age >= middleage && age < elderly)
        // if the user is in the age bounds of 41-60

        {
            group4++;
            // adds one to group 4
        }
        
        else if (age >= elderly)
        // if the user is older than 60
            
        {
            group5++;
            // adds one to group 5
        }
        
        if (age < youngest)
        // if new input is less than previous smallest input
        {
            
        youngest = age;
        // new age input becomes youngest
            
        }
        
        if (age > oldest)
        // if new input is more than the previous greatest input
        {
            
        oldest = age;
        // new age input becomes oldest
            
        }
        
        totalages = totalages + age;
        // collects the total age input sum from the user
        
        cout << "Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): ";
        // asks the user the food preference for the attendee
        
        cin >> foodprefrence;
        // stores the user input for food preference
        
        if (foodprefrence == 'p')
        // if the food preference was popcorn
            
        {
            popcorn++;
            // adds one to popcorn
        }
        
        else if (foodprefrence == 's')
        // if the food preference was soda
            
        {
            soda++;
            // adds one to soda
        }
        
        else if (foodprefrence == 'b')
        // if the food preference was both
            
        {
            bothfood++;
            // adds one to both
        }
        
        cout << "Enter age of attendee (negative number to quit): ";
        // asks the user for the age of a new attendee with the option to quit
            
        cin >> age ;
        // stores the user input for age
        
        count++;
        // adds one to the count of the while loop
    }
    
    if (count == 0)
    // if the while loop doesn't run
    {
    
    cout << "\n" << "age 0 to 18: " << group1 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 1
        
    cout << "age 19 to 30: " << group2 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 2
        
    cout << "age 31 to 40: " << group3 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 3
        
    cout << "age 41 to 60: " << group4 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 4
        
    cout << "over 60: " << group5 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 5
        
    cout << "\n" << "There is no food preference because you didn't enter any numbers! \n";
    // writes that there was no input for food preference
        
    cout << "There is no average age becuase you did not enter any numbers! \n";
    // writes that there was no input for there to be an average age
        
    cout << "There is no youngest person in attendance because you didn't enter any numbers! \n";
    // writes that there was no input for there to be an youngest age
        
    cout << "There is no oldest person in attendance because you didn't enter any numbers! \n \n";
    // writes that there was no input for there to be an oldest age
        
    }
    
    else
    {
        
    cout << "\n" << "age 0 to 18: " << group1 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 1
        
    cout << "age 19 to 30: " << group2 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 2
            
    cout << "age 31 to 40: " << group3 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 3
        
    cout << "age 41 to 60: " << group4 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 4
        
    cout << "over 60: " << group5 << "\n";
    // writes the number of attendees input whos age was in the bounds of group 5
        
    cout << "\n" << "food preference popcorn: " << popcorn << "\n";
    // writes the number of attendees who's food preference was popcorn
        
    cout << "food preference soda: " << soda << "\n";
    // writes the number of attendees who's food prefernce was soda
        
    cout << "food preference both: " << bothfood << "\n";
    // writes the number of attendees who's food preference was both
        
    cout << setprecision(1) << fixed << "The average of age was " << totalages/count << "\n";
    // calculates and writes the average age of all attendees rounded to the tenths placee
    
    cout << "The youngest person in attendance was " << youngest << "\n";
    // writes the age of the youngest attendee
        
    cout << "The oldest person in attendance was " << oldest << "\n \n";
    // writes the age of the oldest attendee
        
    }
    
    return 0;
    
}


/*
 
 Enter age of attendee (negative number to quit): 34
 Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
 Enter age of attendee (negative number to quit): 16
 Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
 Enter age of attendee (negative number to quit): 68
 Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): b
 Enter age of attendee (negative number to quit): 53
 Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
 Enter age of attendee (negative number to quit): 39
 Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): p
 Enter age of attendee (negative number to quit): 23
 Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
 Enter age of attendee (negative number to quit): 21
 Enter food preference ('p' for popcorn, 's' for soda, 'b' for both): s
 Enter age of attendee (negative number to quit): -1

 age 0 to 18: 1
 age 19 to 30: 2
 age 31 to 40: 2
 age 41 to 60: 1
 over 60: 1

 food preference popcorn: 1
 food preference soda: 4
 food preference both: 2
 The average of age was 36.3
 The youngest person in attendance was 16
 The oldest person in attendance was 68
  
 Program ended with exit code: 0

*/
