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
#include <typeinfo>
using namespace std;
void printcpp (char *str,...);
int main ()
{
    int x = 10 ; float f = 10.2395; char *name = "Negm";
    printcpp ("Islam %d %f5,2 %s",x,f,name);            //  5->number of spaces , 2->number of digits after sign
    return 0;

}

void printcpp (char *str,...)
{
    va_list ptr;
    va_start(ptr,str);
    int i = 0;
    while (str[i] != '\0')
    {
        cout << str[i];
        i++;
        if (str[i] == '%')
        {
            switch (str[++i])
            {
                case 'd':
                {
                    cout << va_arg(ptr,int);
                    break;
                }
                case 'f':
                {
                    char *p = &str[i];
                    ++p;
                    string line (*p -'0',' ');
                    cout << line;
                    p += 2;
                    cout << fixed << setprecision(*p - '0') << va_arg(ptr,double);
                    i += 3;
                    break;
                }
                case 's':
                {
                    cout << va_arg(ptr,char*);
                    break;
                }
            }
            ++i;                               // For not-display character after (%)
        }
    }
}


/* Output:
   Islam 10      10.24 Negm
*/
