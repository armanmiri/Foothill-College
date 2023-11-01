// student id: 20481838

#include "Complex.h"

#include <iostream>
#include <string>

using namespace std;

string Complex::to_string() const
{
    char buf[50];
    
    sprintf(buf, "(%.11g,%.11g)", _real, _imag);
    
    return string(buf);
}

Complex Complex::reciprocal() const
{
    if (norm_squared() <= Complex::FLOOR)
    {
        throw Div_By_Zero_Exception();
    }

    return Complex(_real / norm_squared(), -1 * _imag / norm_squared());
}

Complex& Complex::operator=(const Complex& rhs)
{
    _real = rhs._real;
    
    _imag = rhs._imag;
    
    return *this;
}

string Complex::Div_By_Zero_Exception::to_string()
{
    return "Divide by zero exception";
}

string Complex::Div_By_Zero_Exception::what()
{
    return to_string();
}

Complex Complex::operator+(const Complex& that) const
{
    return Complex(_real + that._real, _imag + that._imag);
}

Complex Complex::operator-(const Complex& that) const
{
    return Complex(_real - that._real, _imag - that._imag);
}

Complex Complex::operator*(const Complex& that) const
{
    return Complex(_real * that._real - _imag * that._imag, _real * that._imag + _imag * that._real);
}

Complex Complex::operator/(const Complex& that) const
{
    return *this * that.reciprocal();
}

bool Complex::operator==(const Complex& that) const
{
    if (_real == that._real && _imag == that._imag)
    {
        return true;
    }
    
    return false;
    
}

bool Complex::operator<(const Complex& that) const
{
    return norm() < that.norm();
}

ostream& operator<<(ostream& os, const Complex& x)
{
    return os << x.to_string();
}
