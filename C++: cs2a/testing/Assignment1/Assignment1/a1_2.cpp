//
//  a1_2.cpp
//  Assignment1
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
    
    cout << endl << pounds << " pounds is equal to ";
    cout << ounces << " ounces.";

}

/*
Enter the weight in pounds you want to convert to ounces: 4

 4 pounds is equal to 64 ounces.
*/
