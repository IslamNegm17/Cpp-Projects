#ifndef DAYTIME_H
#define DAYTIME_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

class DayTime
{
private:
    short hours , minutes , seconds;
    bool overflow , underflow;
public:
    //Constructor
    DayTime(short h = 0 , short m = 0 , short s = 0)
    {
        overflow = underflow = false;
        if (!setTime(h,m,s))
            hours = minutes = seconds = 0;
    }
    // Access Methods
    bool setTime (short h , short m , short s = 0)
    {
        if ( h >= 0 && h <= 24 &&
             m >= 0 && m <= 60 &&
             s >= 0 && s <= 60 )
        {
            hours = h;
            minutes = m;
            seconds = s;
            return true;
        }
        else
            return false;
    }
    int getHours () const
    {
        return hours;
    }
    int getMinutes () const
    {
        return minutes;
    }
    int getSeconds () const
    {
        return seconds;
    }
    int asSeconds () const
    {
        return ( seconds + (minutes * 60) + (hours * 60 * 60) );
    }

    void increment ()
    {
        if (overflow)
        {
            cerr << "UnderFlow Occurred once time" << endl;
            exit(1);
        }
        ++seconds;
        underflow = false;
        if (seconds >= 60)
        {
            seconds = 0;
            ++minutes;
        }
        if (minutes >= 60)
        {
            minutes = 0;
            ++hours;
        }
        if (hours >= 24)
        {
            hours = 0;
            overflow = true;
        }
    }

    void decrement ()
    {
        if (underflow)
        {
            cerr << "UnderFlow Occurred once time" << endl;
            exit(1);
        }
        else
        {
            --seconds;
            overflow = false;
            if (seconds < 0)
            {
                seconds = 59;
                --minutes;
            }
            if (minutes < 0)
            {
                minutes = 59;
                --hours;
            }
            if (hours < 0)
            {
                hours = 0;
                underflow = true;
            }
        }

    }

    // Overloaded Operator Function (Prefix)
    DayTime& operator++ ()
    {
        increment();
        return *this;
    }

    DayTime& operator-- ()
    {
        decrement();
        return *this;
    }

    // Overloaded Operator Function (Postfix)
    DayTime operator++ (int)
    {
        DayTime temp (*this);
        increment();
        return temp;
    }

    DayTime operator-- (int)
    {
        DayTime temp (*this);
        decrement();
        return temp;
    }
};

// Global Overloaded Operator Function
inline bool operator< (const DayTime& dt1 , const DayTime& dt2)
{
    return (dt1.asSeconds() < dt2.asSeconds());
}

inline bool operator> (const DayTime& dt1 , const DayTime& dt2)
{
    return (dt1.asSeconds() > dt2.asSeconds());
}

inline bool operator<= (const DayTime& dt1 , const DayTime& dt2)
{
    return (dt1.asSeconds() <= dt2.asSeconds());
}

inline bool operator>= (const DayTime& dt1 , const DayTime& dt2)
{
    return (dt1.asSeconds() >= dt2.asSeconds());
}

inline bool operator== (const DayTime& dt1 , const DayTime& dt2)
{
    return (dt1.asSeconds() == dt2.asSeconds());
}

inline bool operator!= (const DayTime& dt1 , const DayTime& dt2)
{
    return (dt1.asSeconds() != dt2.asSeconds());
}

istream& operator>> (istream& is , DayTime& dt1)
{
    short hours , minutes , seconds;
    cout << "Enter Hours: ";    is >> hours;
    cout << "Enter Minutes: ";  is >> minutes;
    cout << "Enter Seconds: ";  is >> seconds;
    if (!dt1.setTime(hours,minutes,seconds))
        is.setstate(ios::failbit);                    //Rise fail-bit if an Error occurred
    return is;
}

ostream& operator<< (ostream& os , const DayTime& dt1)
{
    os << setw(3) << "Time is:  "
       << dt1.getHours()   <<':'
       << dt1.getMinutes() <<':'
       << dt1.getSeconds() << endl;
    return os;
}

#endif

//----------------------------------------------[Main]-------------------------------------------------//
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
#include "DayTime.h"
using namespace std;

int main ()
{
  DayTime cinema (20 , 30 , 59);
  cout << cinema << endl;

  DayTime now;
  cin >> now;

  if ( (cinema >= now) )
      cout << "The Film Begun" << endl;
  else
      cout << "Not yet!" << endl;

  cinema++;
  cout << cinema << endl;

}


