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

struct name
{
    unsigned char b0 :1;
    unsigned char b1 :1;
    unsigned char b2 :1;
    unsigned char b3 :1;
    unsigned char b4 :1;
    unsigned char b5 :1;
    unsigned char b6 :1;
    unsigned char b7 :1;
};

union VarBit
{
    unsigned char b;
    name n;
}V1;

int main ()
{
   V1.b = 50;
   V1.n.b0 = 1;
   cout << (int)V1.b << endl;
     return 0;
}


