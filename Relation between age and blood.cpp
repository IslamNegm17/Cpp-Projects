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
int table [3][5] =
        { {25,34,26,12,8},
          {19,27,24,11,4},
          {6,15,35,36,18} };
int sum_rows [3];
int sum_columns [5];
int matrix_sum (const int matrix[3][5] , int s_row[] , int s_columns[]);
int main ()
{

 matrix_sum (table , sum_rows , sum_columns);

for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 6 ; ++j)
        {
            if (i == 3)
            {
                cout << setw(5) << sum_columns[j];
                continue;
            }
            if (j == 5)
            {
                cout << setw(6) << sum_rows[i];
                continue;
            }
             cout << setw(5) << table[i][j];
        }
        cout << endl;
    }



}

int matrix_sum (const int matrix[3][5] , int s_row[] , int s_columns[])
{
    s_row [0] = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            s_row[i] +=  matrix[i][j];
        }
    }
    s_columns [0] = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            s_columns[i] +=  matrix[j][i];
        }
    }
    return (s_row[0] + s_row[1] + s_row[2]);
}
