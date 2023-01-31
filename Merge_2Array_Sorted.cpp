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

inline void Swap (int &a , int &b);
void SelectionSort (int *const array , int len);
int* Merge (const int *array1 , int len1 ,const int *array2 , int len2);

int main ()
{
    int len1 = 5 , len2 = 7;
    int *array1 = new int [len1],
        *array2 = new int [len2],
        *array3 = new int [len1 + len2];
    srand(time(nullptr));
    for (int i = 0; i < len1; ++i)
    {
        array1[i] = rand();
    }
    for (int i = 0; i < len2; ++i)
    {
        array2[i] = rand();
    }
    cout << "first Array is: ";
    for (int i = 0; i < len1; ++i)
    {
        cout << setw(8) << array1[i];
    }
    cout << "\nSecond Array is: ";
    for (int i = 0; i < len2; ++i)
    {
        cout << setw(8) << array2[i];
    }

    SelectionSort (array1 , len1);
    SelectionSort (array2 , len2);

    cout << "\nAfter Sorting first Array is: ";
    for (int i = 0; i < len1; ++i)
    {
        cout << setw(8) << array1[i];
    }
    cout << "\nAfter Sorting Second Array is: ";
    for (int i = 0; i < len2; ++i)
    {
        cout << setw(8) << array2[i];
    }

    array3 = Merge (array1 ,len1 ,array2 ,len2);
    cout << "\nAfter Merging Array is: ";
    for (int i = 0; i < len1 + len2; ++i)
    {
        cout << setw(15) << array3[i];
    }

    delete [] array1;
    delete [] array2;
    delete [] array3;
    return 0;
}
inline void Swap (int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort (int *const array , int len)
{
    int *a = array , *b = a + 1 , *last = array + len -1;
    bool con = true;
    while (con)
    {
        con = false;
        for (; a < last;)
        {
            if (*a > *b)
            {
                Swap(*a , *b);
                con = true;
            }
            a++ , b++;
        }
        a = array , b = a + 1;
    }
}

int* Merge (const int *array1 , int len1 ,const int *array2 , int len2)
{
    int *array = new int [len1 + len2];
    for (int i = 0; i < len1; ++i)
    {
         array[i] = array1[i] ;
    }
    for (int i = len1 , j = 0; i < len1 + len2; ++i , j++)
    {
        array[i] = array2[j] ;
    }
    return array;
}

