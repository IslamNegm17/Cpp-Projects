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
#include "Matrices.h"
void display( Matrices& m);

int main ()
{

    Matrices m (4,5);
    try
    {
        int i,j;
        for( i=0; i < m.getLines(); i++)
            for( j=0; j < m.getColomn(); j++)
                m[i][j] = (double)i + j/ 100.0;
        cout << "Matrix created" << endl;
        display(m);
        Matrices cop(m);
        cout << "Copy generated." << endl;
        display(cop);
        cop += m;
        cout << "Compute the sum:" << endl;
        display(cop);
        Matrices m1(4, 5, 0.0);
        cout << "Initializing a matrix with 0:" << endl;
        display(m1);
        m = m1;
        cout << "Matrix assigned:" << endl;
        display(m);
    }
    catch(out_of_range& err)
    { cerr << err.what() << endl; exit(1); }
    return 0;
}

void display( Matrices& m)
{
    for(int i=0; i < m.getLines(); i++)
    {
        for(int j=0; j < m.getColomn(); j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    cin.get();
}
