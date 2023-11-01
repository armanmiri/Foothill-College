//
//  main.cpp
//  a8_1
//
//  Created by Arman miri on 11/13/21.
//

#include <iostream>
using namespace std;

class Fraction
{
    public:
    
        void set (int numeratr, int denominatr);
   
        Fraction addedTo (Fraction fraction2);

        Fraction subtract (Fraction fraction2);
    
        Fraction multipliedBy (Fraction fraction2);
    
        Fraction dividedBy (Fraction fraction2);
    
        bool isEqualTo (Fraction fraction2);
        
        void print();
        
        int getNumerator();
        
        int getDenominator();
    
    private:
        
        int numerator;
    
        int denominator;
    
};






void Fraction::set (int numeratr, int denominatr)
{
    numerator = numeratr;
    
    denominator = denominatr;
}






Fraction Fraction::addedTo(Fraction fraction2)
{
    Fraction solution;
    
    int newDenom = (denominator * fraction2.getDenominator());
    
    int newNumer = (numerator * fraction2.getDenominator() + denominator * fraction2.getNumerator());
    
    solution.set(newNumer, newDenom);
    
    return solution;
};






Fraction Fraction::subtract(Fraction fraction2)
{
    Fraction solution;
    
    int newDenom = (denominator * fraction2.getDenominator());
    
    int newNumer = (numerator * fraction2.getDenominator() - denominator * fraction2.getNumerator());
    
    solution.set(newNumer, newDenom);
    
    return solution;
    
};






Fraction Fraction::multipliedBy(Fraction fraction2)
{
    
    Fraction solution;
    
    int newNumer = numerator * fraction2.getNumerator();
    
    int newDenom = denominator * fraction2.getDenominator();
    
    solution.set(newNumer, newDenom);
    
    return solution;
    
};






Fraction Fraction::dividedBy(Fraction fraction2)
{
    
    Fraction solution;
    
    int newNumer = numerator * fraction2.getDenominator();
    
    int newDenom = denominator * fraction2.getNumerator();
    
    solution.set(newNumer, newDenom);
    
    return solution;
    
};






bool Fraction::isEqualTo(Fraction fraction2)
{
    
    int f1 = numerator * fraction2.getDenominator();
    
    int f2 = denominator * fraction2.getNumerator();
    
    if(f1 == f2)
    {
        return f1 == f2;
    }
    
    else
    {
        return 0;
    }
    
};






void Fraction::print()
{
    cout << numerator << "/" << denominator;
};

int Fraction::getNumerator()
{
    return numerator;
};

int Fraction::getDenominator()
{
    return denominator;
};






int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}

/*
 
 The product of 9/8 and 2/3 is 18/24
 The quotient of 9/8 and 2/3 is 27/16
 The sum of 9/8 and 2/3 is 43/24
 The difference of 9/8 and 2/3 is 11/24
 The two Fractions are not equal.
 Program ended with exit code: 0
 
*/
