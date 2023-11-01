/*
 
Arman Miri
CS F002A
10/06/21
Harden
a3_4
Assignment 3 Part 4
 
This function calculates the price of phone calls from San Francisco to Miami. The function
takes the users input for start time and length of the call. In return the function writes
the gross cost and the net cost.
 
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double grosscost;
    double netcost;
    const int rate = 0.40;
    const int timediscount = 0.5;
    const int federaltax = 0.04;
    const int minutediscount = 0.15;
    int callstart;
    int calltime;
    double startprice;
    double lengthprice;
    
    
    cout << "What was the start time of your call in 24 hour time: ";
    cin >> callstart;
    
    cout << "How long was the call: ";
    cin >> calltime;
    
    if (callstart < 800) && (callstart > 1800)
        {
            startprice = (calltime * federaltax);
            
            lengthprice = (calltime * rate);
            
            grosscost = (startprice + lengthprice);
            
            cout << setprecision(2) << fixed << "Gross cost: $" << grosscost << ". \n";
            
            if (calltime < 60)
        {
            netcost = (startprice * timediscount) + lengthprice ;
        
        cout << setprecision(2) << fixed << "Net cost: $" << netcost << ". \n \n";
        }
            
            else if (calltime >= 60)
            {
            
            netcost = (startprice * timediscount) + (lengthprice * minutediscount);
            
            cout << setprecision(2) << fixed << "Net cost: $" << netcost << ". \n \n";
            
            }
        }
    
    if (callstart > 800 || callstart < 1800)
    {
            startprice = (calltime * federaltax);
            
            lengthprice = (calltime * rate);
            
            grosscost = (startprice + lengthprice);
            
            cout << setprecision(2) << fixed << "Gross cost: $" << grosscost << ". \n";
            
            if (calltime < 60)
        {
            netcost = startprice + lengthprice;
        
        cout << setprecision(2) << fixed << "Net cost: $" << netcost << ". \n \n";
        }
            
            else if (calltime >= 60)
            {
            
            netcost = startprice + (lengthprice * minutediscount);
            
            cout << setprecision(2) << fixed << "Net cost: $" << netcost << ". \n \n";
            
            }
    }
    return 0;
}


/*

 results
 
*/
