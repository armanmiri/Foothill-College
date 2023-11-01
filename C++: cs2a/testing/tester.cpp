//
//  tester.cpp
//  Assignment1
//
//  Created by Arman miri on 9/21/21.
//

#include <iostream>
    using namespace std;

    int main()
    {
        int hoursWorked;
        int paycheckAmount;

        cout << "Enter hours worked: ";
        cin >> hoursWorked;
        paycheckAmount = hoursWorked * 12;
        cout << "The amount of the paycheck is $"
             << paycheckAmount << endl;
    }
