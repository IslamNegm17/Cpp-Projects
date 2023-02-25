#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cstdarg>
#include <ctime>
//#include <chrono>
//#include <cstring>
//#include <climits>   // The maximum and minimum size of integral values
//#include <conio.h>   // For getch() and putch()
//#include <sstream>
//#include <cmath>
//#include <windows.h>
//#include <fstream>
//#include <typeinfo>
using namespace std;
//using namespace std::chrono;


void putBits (unsigned int number);
int main ()
{
    int x , y , count = 0;
    cout << "\n    ****** BITWISE OPERATOR ******\n\n"
         << "Please Enter Two Integers ^.^" << endl
         << "1st Number --> ";      cin >> x;
    cout << "2st Number --> ";      cin >> y;
    cout << "\nThe bit pattern of " << x << " is: ";        putBits(x);
    cout << "\nThe bit pattern of " << y << " is: ";        putBits(y);
    cout << "\nThe bit pattern of " << "x & y" << " is: ";  putBits(x & y);
    cout << "\nThe bit pattern of " << "x | y" << " is: ";  putBits(x | y);
    cout << "\nThe bit pattern of " << "x ^ y" << " is: ";  putBits(x ^ y);
    cout << "\nHow many bit Position wanted to be shifted ^.^" << endl
         << "Count --> ";           cin >> count;
    cout << "\nThe bit pattern of " << "x << " << count << " is: ";  putBits(x << count);
    cout << "\nThe bit pattern of " << "x >> " << count << " is: ";  putBits(x >> count);

     return 0;
}

void putBits (unsigned int number)
{
    for (int i = 15; i >= 0; --i)       // Only 16 LSBits
    {
        cout << ( (number >> i) & 1 );
        if (i % 4 == 0)
             cout << ' ';
    }
}

