#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <windows.h>
using namespace std;
void swap (int &num1 , int &num2);
void selectionSort ( int *int_array , int len);
int main ()
{
    int array [] = {100,50,10,30,70,200};
    selectionSort(array,6);
    for (int j : array)
    {
        cout << j << '\t';
    }

}

void swap (int &num1 , int &num2)
{
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
}

void selectionSort ( int *int_array , int len)
{
     int *ptr = int_array , i = 0;
     bool condition = true;
    while (condition)
    {
        condition = false;
        for (; ptr < (int_array + len); ++ptr)
        {
            if (*(int_array + i) > *ptr)
            {
                swap(*(int_array + i), *ptr);
                condition = true;
            }
        }
        i++;
        ptr = int_array + i;
    }
}
