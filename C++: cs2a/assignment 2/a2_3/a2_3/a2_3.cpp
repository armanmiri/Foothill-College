/*
 
Arman Miri
CS F002A
09/29/21
Harden
a2_3
Assignment 2 Part 3
 
This program asks the user for thier name in First Middle Last format,
then procedes to print it first, middle, last, initals, first 3 of middle name,
8th character of name, number of characters in full name.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

    string firstname;
    string middlename;
    string lastname;
    string fullname;
    //defining the strings for the function
    
    cout << "Enter a name in the format First Middle Last: ";
    //asks the user for their name
    
    cin >> firstname ;
    //stores users first name under string
    
    cin >> middlename ;
    //stores users middle name under string
    
    cin >> lastname ;
    //stores users last name under string
    
    fullname = firstname + " " +middlename + " " + lastname;
    // combines the users full name into one string

    cout << "\n";
    //creates space in result
    
    cout << firstname << "\n";
    //writes users first name
    
    cout << middlename << "\n";
    //writes users middle name
    
    cout << lastname << "\n";
    //writes users last name
    
    cout << firstname.substr(0,1) << middlename.substr(0,1) << lastname.substr(0,1) << "\n";
    //finds the intials of the user and writes them
    
    cout << middlename.substr(0,3) << "\n";
    //writes the first 3 letters of users middle name
    
    cout << fullname.substr(7, 1) << "\n";
    //writes the 8th letter of the users name
    
    cout << fullname.length() << "\n";
    //calculates and writes the number of characters in the users name
    
    cout << "\n";
    //creates space in result
    
    return 0;
    
}

/*

 Enter a name in the format First Middle Last: James Tiberius Kirk

 James
 Tiberius
 Kirk
 JTK
 Tib
 i
 19

 Program ended with exit code: 0

*/
