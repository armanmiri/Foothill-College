/*

This is a fraction class that can be used to find the product, quotient, sum, and difference of
two fractions.
The following functions are available:
 
Fraction (int numeratr, int denominatr)
Pre: None
Post: A fraction object whos denominator is denominatr and its numerator is numeratr
 
Fraction ()
Pre: None
Post: A fraction oject whos denominator is 1 and its numerator is 0
 
addedTo (const Fraction fraction2) const
Pre: None
Post: gets the sum of the two stored fractions to give a new initalized fraction
 
Fraction subtract (const Fraction fraction2) const
Pre: None
Post: gets the difference of the two stored fractions to give a new initalized fraction
 
Fraction multipliedBy (const Fraction fraction2) const
Pre: None
Post: gets the product of the two stored fractions to give a new initalized fraction
  
Fraction dividedBy (const Fraction fraction2) const
Pre: None
Post: gets the quotient of the two stored fractions to give a new initalized fraction

isEqualTo (const Fraction fraction2) const
Pre: None
Post: Returns the inital condition if true or returns 0 if false after comparing the two fractions
 
print()const
Pre: None
Post: The called function is printed in the form of numerator/denominator
 
getNumerator() const
Pre: None
Post: The numerator is called and printed
  
getDenominator() const
Pre: None
Post: The denominator is called and printed
  
 
 */
#ifndef Fuction_h
#define Fuction_h

class Fraction
{
    public:
    
        Fraction(int numeratr, int denominatr);
    
        Fraction ();
   
        Fraction addedTo (const Fraction fraction2) const;

        Fraction subtract (const Fraction fraction2) const;
    
        Fraction multipliedBy (const Fraction fraction2) const;
    
        Fraction dividedBy (const Fraction fraction2) const;
    
        bool isEqualTo (const Fraction fraction2) const;
        
        void print()const;
        
        int getNumerator() const;
        
        int getDenominator() const;
    
    private:
    
        int numerator;
    
        int denominator;
    
};

#endif 
