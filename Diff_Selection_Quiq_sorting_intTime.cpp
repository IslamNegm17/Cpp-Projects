#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cstdarg>
#include <ctime>
#include <chrono>
//#include <cstring>
//#include <climits>    // The maximum and minimum size of integral values
//#include <conio.h>    // For getch() and putch()
//#include <sstream>
//#include <cmath>
//#include <windows.h>
//#include <fstream>
//#include <typeinfo>
using namespace std;
using namespace std::chrono;

#define SIZE                                       1000
extern "C" int intcmp (const void* , const void*);
void Swap (int &a , int &b);
void SelectionSort (int* arr , int size);


int main ()
{
    int array1 [SIZE] , array2 [SIZE];
    srand(time(nullptr));
    for (int i = 0; i < SIZE; ++i)
    {
        array1[i] = array2[i] = rand()%100;
    }

    auto time1 = std::chrono::high_resolution_clock::now();
    SelectionSort(array1,SIZE);
    auto time2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(time2 - time1);
    cout << "The Time Taken in Selection Sort is: " << duration.count() << " microseconds" << endl
         << "Dispaly Sorted Array (Y/N): ";
    if (cin.get() == 'Y')
        for (int i = 0; i < SIZE; ++i)
        {
            cout << setw(4) << array1[i] << "  ";
        } cout << endl;


    time1 = high_resolution_clock::now();
    qsort(array2 , SIZE , sizeof (int) ,intcmp);
    time2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(time2 - time1);
    cout << "The Time Taken in Quick Sort is: " << duration.count() << " microseconds" << endl
         << "Dispaly Sorted Array (Y/N): ";   cin.sync();
    if (cin.get() == 'Y')
        for (int i = 0; i < SIZE; ++i)
        {
            cout << setw(4) << array2[i] << "  ";
        } cout << endl;

}


void Swap (int &a , int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void SelectionSort (int* arr , int size)
{
    int index = 0 , j = 0 ;
    for (int k = 0; k < size; ++k)
    {
        for (int i = j; i < size; ++i)
        {
            if (arr[index] > arr[i])
            {
                index = i;
            }
        }
              Swap(arr[j++],arr[index]);
              index = j;
    }

}

extern "C" int intcmp (const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}




/* Output Note: in big size of Array Quiq sort is so good than Selection ,but Selection
                is better in little size
