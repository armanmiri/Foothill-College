/*
   
    Class Invariant: a fraction object has 2 int data members: numerator, which stores the
    numerator, and denominator which stores the denominator. Internal operations always result in
    valid dates (a denominator greater than 0).  However, no effort is made to prevent the client
    from providing an invalid fraction.
       
   */

#include "fraction.h"
#include <iostream>
#include <cassert>
using namespace std;






Fraction::Fraction()
{
    numerator = 0;
    
    denominator = 1;
    
};






Fraction::Fraction(int numeratr, int denominatr)
{
    numerator = numeratr;
    
    denominator = denominatr;
    
    assert(denominator != 0);
};






Fraction Fraction::addedTo(const Fraction fraction2) const
{
    int newDenom = (denominator * fraction2.getDenominator());
    
    int newNumer = (numerator * fraction2.getDenominator() + denominator * fraction2.getNumerator());
    
    Fraction solution (newDenom, newNumer);
    
    return solution;
};






Fraction Fraction::subtract(const Fraction fraction2) const
{
    int newDenom = (denominator * fraction2.getDenominator());
    
    int newNumer = (numerator * fraction2.getDenominator() - denominator * fraction2.getNumerator());
    
    Fraction solution (newDenom, newNumer);
    
    return solution;
    
};






Fraction Fraction::multipliedBy(const Fraction fraction2) const
{
    int newNumer = numerator * fraction2.getNumerator();
    
    int newDenom = denominator * fraction2.getDenominator();
    
    Fraction solution (newDenom, newNumer);
    
    return solution;
    
};






Fraction Fraction::dividedBy(const Fraction fraction2) const
{
    int newNumer = numerator * fraction2.getDenominator();
    
    int newDenom = denominator * fraction2.getNumerator();
    
    Fraction solution (newDenom, newNumer);
    
    return solution;
    
};






bool Fraction::isEqualTo(const Fraction fraction2) const
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






void Fraction::print() const
{
    cout << numerator << "/" << denominator;
};






int Fraction::getNumerator() const
{
    return numerator;
};






int Fraction::getDenominator() const
{
    return denominator;
};





