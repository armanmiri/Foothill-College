/*
 
Arman Miri
CS F002A
10/06/21
Harden
a3_4
Assignment 3 Part 4
 
This function calculates the price of phone calls from San Francisco to Miami. The function
takes the users input for start time and length of the call. In return the function writes
the gross cost and the net cost calulated with the rate of 40 cents a minute and 4 percent
federal tax. This also takes into account the discount for calls during the hours of 6pm to 8am
and 15% if the call is over 60 minutes.
 
*/

#include <iostream>
#include <iomanip>
using namespace std;

const double rate = 0.40;
const double timediscount = 0.5;
const double federaltax = 0.04;
const double minutediscount = 0.15;
// declaring the constants for calculation

int main()
{
    double grosscost;
    double netcost;
    // declaring the variables for calualtion
   
    int callstart;
    int calltime;
    // declaring the variables for user input
    
    cout << "What was the start time of your call in 24 hour time: ";
    // asks the user for the start time of their call in 24 hour time
    
    cin >> callstart;
    // stores the user input under the callstart variable
    
    cout << "How long was the call: ";
    // asks the user for the length of their call
    
    cin >> calltime;
    // stores user input for call length under calltime variable
    
    grosscost = calltime * rate;
    // calulates the grosscost of the call
    
    netcost = grosscost;
    // sets up the netcost variable to be altered
    
    if ((callstart <= 800) || (callstart >= 1800))
    // if the call is during the hours for discount
        
        {
            netcost = netcost * timediscount;
            // calulates the discount for the time of day
        }
    
    if (calltime > 60)
    // if the call was long enough for discount
        
        {
            netcost = netcost - (netcost * minutediscount);
            // calculates the discount for length of call
        }
        
    netcost = netcost + (netcost * federaltax);
    // calulates the final price including federal tax
    
    cout << setprecision(2) << fixed << "The gross cost is: $" << grosscost << ". \n";
    // writes out the gross cost rounded to two decimal places
    
    cout << setprecision(2) << fixed << "The net cost is: $" << netcost << ". \n \n";
    // writes out the net cost rounded to two decimal places
            
    return 0;
}


/*

 What was the start time of your call in 24 hour time: 2322
 How long was the call: 67
 The gross cost is: $26.80.
 The net cost is: $11.85.
  
 Program ended with exit code: 0
 
*/
/*

 What was the start time of your call in 24 hour time: 759
 How long was the call: 10
 The gross cost is: $4.00.
 The net cost is: $2.08.
  
 Program ended with exit code: 0
 
*/
/*
 
What was the start time of your call in 24 hour time: 1300
How long was the call: 100
The gross cost is: $40.00.
The net cost is: $35.36.
 
Program ended with exit code: 0

*/
/*

 What was the start time of your call in 24 hour time: 1300
 How long was the call: 10
 The gross cost is: $4.00.
 The net cost is: $4.16.
  
 Program ended with exit code: 0
 
*/
