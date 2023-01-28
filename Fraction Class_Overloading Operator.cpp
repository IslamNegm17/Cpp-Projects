#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

class Fraction
{
private:
    long numerator , denominator;
public:
    Fraction (long num = 0 , long den = 1)
    {
        if (denominator == 0)
        {
            std::cerr << "Error in Division by Zero!" << std::endl;
            exit(1);
        }
        else if (den < 0)
        {
            denominator = -den;
            numerator   = -num;
        }
        else
        {
            numerator = num;
            denominator = den;
        }
    }

    // Overloading Operator
    Fraction operator- () const
    {

        return ( Fraction (-numerator , denominator) );
    }

    Fraction& operator++ ()
    {
        numerator += denominator;
        return *this;
    }

    Fraction& operator-- ()
    {
        numerator -= denominator;
        return *this;
    }

    Fraction& operator+= (const Fraction& f2)
    {
        numerator = (numerator * f2.denominator) + (denominator * f2.numerator);
        denominator *= f2.denominator;
        return *this;
    }

    Fraction& operator-= (const Fraction& f2)
    {
        numerator = (numerator * f2.denominator) - (denominator * f2.numerator);
        denominator *= f2.denominator;
        return *this;
    }

    Fraction& operator*= (const Fraction& f2)
    {
        numerator   = numerator     * f2.numerator;
        denominator = denominator * f2.denominator;
        return *this;
    }

    Fraction& operator/= (const Fraction& f2)
    {
        numerator   = numerator     * f2.denominator;
        denominator = denominator * f2.numerator;
        return *this;
    }

    // Friend Functions
    friend Fraction operator+ (const Fraction& f1 , const Fraction& f2);
    friend Fraction operator- (const Fraction& f1 , const Fraction& f2);
    friend Fraction operator* (const Fraction& f1 , const Fraction& f2);
    friend Fraction operator/ (const Fraction& f1 , const Fraction& f2);
    friend std::istream& operator>> (std::istream& is, Fraction& f1);
    friend std::ostream& operator<< (std::ostream& os, const Fraction& f1);
};



#endif


//-------------------------------------------------------------------------------------------------------------------------------


#include "Fraction.h"

// Global Overloading Operator
Fraction operator+ (const Fraction& f1 , const Fraction& f2)
{
    Fraction temp;
    temp.numerator   = (f1.numerator * f2.denominator) + (f1.denominator * f2.numerator);
    temp.denominator = f1.denominator * f2.denominator;
    return temp;
}

Fraction operator- (const Fraction& f1 , const Fraction& f2)
{
    Fraction temp;
    temp.numerator = (f1.numerator * f2.denominator) - (f1.denominator * f2.numerator);
    temp.denominator = f1.denominator * f2.denominator;
    return temp;
}

Fraction operator* (const Fraction& f1 , const Fraction& f2)
{
    Fraction temp;
    temp.numerator   = f1.numerator     * f2.numerator;
    temp.denominator = f1.denominator   * f2.denominator;
    return temp;
}

Fraction operator/ (const Fraction& f1 , const Fraction& f2)
{
    Fraction temp;
    temp.numerator   = f1.numerator     * f2.denominator;
    temp.denominator = f1.denominator   * f2.numerator;
    return temp;
}

std::istream& operator>> (std::istream& is, Fraction& f1)
{
    std::cout << "Enter Object Numerator:";
    is >> f1.numerator;
    std::cout << "Enter Object Denominator:";
    section1:
    is >> f1.denominator;
    if (f1.denominator < 0)
    {
        std::cerr << "Error in Division by Zero!" << std::endl
                  << "Re-Enter Object Denominator:" << std::endl;
        goto section1;
    }
    else if (f1.denominator < 0)
    {
        f1.denominator   = -f1.denominator;
        f1.numerator     = -f1.numerator;
    }
    return is;
}

std::ostream& operator<< (std::ostream& os, const Fraction& f1)
{
    std::cout << std::setw(3) << "Numerator is: "   << f1.numerator
              << " , Denominator is: " << f1.denominator << std::endl;
    return os;
}


//---------------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>
//#include <climits>  //The maximum and minimum size of integral values
//#include <sstream>
//#include <cmath>
//#include <windows.h>
//#include <fstream>
#include "Fraction.h"
using namespace std;

int main ()
{
    Fraction a(1,3), b(4);
    cout << "\nSome test results:\n\n";
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;

    cout << " a + b = " << (a + b) << endl;

    cout << " a - b = " << (a - b) << endl;
    cout << " a * b = " << (a * b) << endl;
    cout << " a / b = " << (a / b) << endl;
    cout << " --a = "   << --a     << endl;
    cout << " ++a = "   << ++a     << endl;

    a += Fraction(1,2);
    cout << " a+= 1/2; a = " << a << endl;

    a -= Fraction(1,2);
    cout << " a-= 1/2; a = " << a << endl;
    cout << "-b = " << -b << endl;
    cout << "\nAnd now an input\n";
    cin >> a;
    cout << "\nYour input: " << a << endl;

    return 0;

}


