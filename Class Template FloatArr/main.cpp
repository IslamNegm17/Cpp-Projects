#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdarg>
#include <ctime>
#include <chrono>
//#include <cstring>
//#include <climits>   // The maximum and minimum size of integral values
//#include <conio.h>   // For getch() and putch()
//#include <sstream>
//#include <cmath>
//#include <windows.h>
//#include <fstream>
//#include <typeinfo>
using namespace std;
using namespace std::chrono;
#include "Search.h"

typedef Array<int,100> IntArr;
typedef Array<double> DoubleArr;

int main()
{
    try
    {
        const DoubleArr vd(10, 9.9);
        DoubleArr kd;
        cout << "\nThis is the constant array of doubles: \n";
        cout << vd;
        kd = vd;
        cout << "\nAn array of doubles after the assignment: "
             << endl;
        cout << kd;
        kd.remove(3);   // Delete the element at position 3.
        kd.append(10.0); // Add a new element.
        kd.append(20.0); // And repeat!
        cout << "\nThis is the modified array: "
             << endl;
        cout << setw(8) << kd;
        IntArr vi;
        for(int i = 0; i < 10; i++)
            vi.append(rand()/100);
        cout << "\nThis is the array of int values: \n";
        cout << setw(12) << vi;
        vi += vi;
        cout << "\nAnd append: \n";
        cout << setw(12) << vi;
        IntArr ki(vi);
        cout << "\nThis is the copy of the array: \n";
        cout << setw(12) << ki;
    }
    catch (BadIndex &b)
    {
        cout << "Bad in " << b.getIndex() << " Location" << endl;
        exit(1);
    }
    catch (OutOfRange &o)
    {
        cout << "Out of Range" << endl;
        exit(2);
    }
}
