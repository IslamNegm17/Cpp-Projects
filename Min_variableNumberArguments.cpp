#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cstdarg>
//#include <ctime>
//#include <cstring>
//#include <climits>    // The maximum and minimum size of integral values
//#include <conio.h>    // For getch() and putch()
//#include <sstream>
//#include <cmath>
//#include <windows.h>
//#include <fstream>
//#include <typeinfo>
using namespace std;
unsigned int min (unsigned int , ...);
int main ()
{
  cout << min (3,20,1,0) << endl;
    return 0;
}

unsigned int min (unsigned int first , ...)
{
   va_list argptr;
   va_start(argptr , first);
   unsigned int arg2;
   unsigned int min = first;
    while ((arg2 = va_arg(argptr,unsigned int)) != 0)
        if (first > arg2)
            min = arg2;
    va_end(argptr);
    return min;
}

