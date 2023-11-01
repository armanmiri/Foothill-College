//
//  a1_2.cpp
//  a1_2
//
//  Created by Arman miri on 9/21/21.
//

#include <iostream>
using namespace std;

int main()
{
    int pounds;
    int ounces;
    
    cout << "Enter the weight in pounds you want to convert to ounces: ";
    cin >> pounds ;
    
    ounces = pounds * 16;
    
    cout << "\n" << pounds << " pounds is equal to ";
    cout << ounces << " ounces." << "\n \n";

    return 0;
    
}

/*
 Enter the weight in pounds you want to convert to ounces: 4

 4 pounds is equal to 64 ounces.

 Program ended with exit code: 0
*/

