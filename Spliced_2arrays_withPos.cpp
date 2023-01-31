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
//#include "Fraction.h"
using namespace std;

int* splice (const int* a1 , const int* a2 , int len1 , int len2 , int pos);

int main ()
{
  int len1 = 4 , len2 = 5 , len3 = len1 + len2;
  int *array1 = new int [len1] , *array2 = new int [len2];
  srand(time(nullptr));

    for (int i = 0; i < len1; ++i)
    {
     array1[i] = rand();
    }
    for (int i = 0; i < len2; ++i)
    {
        array2[i] = rand();
    }

    cout << "First array is: ";
    for (int i = 0; i < len1; ++i)
    {
        cout << setw(8) <<array1[i];
    }
    cout << "\n\nSecond array is: ";
    for (int i = 0; i < len2; ++i)
    {
        cout << setw(8) << array2[i];
    }

    int *array3 =  splice (array1 , array2 , len1 , len2 , 4);

    cout << "\n\nSpliced array is: ";
    for (int i = 0; i < len3; ++i)
    {
        cout << setw(8) << array3[i];
    }

    delete [] array1;
    delete [] array2;
    delete [] array3;

    return 0;
}

int* splice (const int* a1 , const int* a2 , int len1 , int len2 , int pos)
{
    int *spliced_array = new int [len1 + len2];
    for (int i = pos , j = 0; i < len2 + pos; ++i , j++)
    {
         spliced_array[i] =  a2[j];
    }
    for (int i = 0, j = 0; i < len1 + len2; ++i , j++)
    {
        if (i == pos)
            i += len2;
        spliced_array[i] =  a1[j];
    }
    return spliced_array;
}

