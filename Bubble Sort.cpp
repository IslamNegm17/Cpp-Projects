#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include "Articel.h"
using namespace std;

long array_numbers [100];
int index_pointer ,index_pointer_2 ;
void swap (int & , int &);
void BubbleSort (long array[]);

int main ()
{
 cout << "Enter The Numbers ..... [enter any special character to terminate]!" << endl;
 for (index_pointer = 0; index_pointer < 100 && cin >> array_numbers[index_pointer]; index_pointer++);
 cout << "the Numbers u entered is: ";
 for (index_pointer_2 = 0; index_pointer_2 < index_pointer ; index_pointer_2++)
     cout << setw(4) <<array_numbers [index_pointer_2];
 BubbleSort(array_numbers);
 cout << '\n' << "the Array after Sorted is: ";
 for (index_pointer_2 = 0; index_pointer_2 < index_pointer ; index_pointer_2++)
     cout << setw(4) <<array_numbers [index_pointer_2];
}


void swap (int &num1 , int &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
void BubbleSort (long array[])
{
    bool condition = false;
    while (!condition)
    {
        condition = true;
        for (int i = 0; i < (index_pointer - 1); ++i)
        {
            if (array_numbers[i] > array_numbers[i + 1])
            {
                swap (array_numbers[i] , array_numbers[i + 1]);
                condition = false;
            }
        }
    }
}
