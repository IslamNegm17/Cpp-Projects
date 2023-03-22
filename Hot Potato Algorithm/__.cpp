#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iomanip>
//#include <stdio.h>
//#include <cstring>
//#include <cstdarg>
//#include <ctime>
//#include <chrono>
//#include <cstring>
//#include <climits>     // The maximum and minimum size of integral values
//#include <conio.h>     // For getch() and putch()
//#include <sstream>
//#include <cmath>
//#include <windows.h>
#include <fstream>
#include <typeinfo>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <utility>
#include <bitset>
#include <queue>
using namespace std;
//using namespace std::chrono;
#include "Router.h"

int main()
{
    const int nQueues = 9;
    VecQueue<int> vq(9); // Vector of 9 queues
    cout << nQueues << " queues have been created." << endl;

    srand(time(NULL));
    cout << "\nThe queues will now be filled "
         << "\nusing the hot potato algorithm." << endl;
    int i;
    for(i = 0; i < 100; i++) // To insert 100 elements
        vq.push(rand()%100);
    

    cout << "\nTo output the queues: " << endl;   // To retrieve, remove
    for( i = 0; i < nQueues; ++i)                 // and display all
    {   // remaining elements.
        cout << "\n" << i+1 << ".Queue: ";
        while( vq.size(i) > 0 )
        {
            cout << setw(4) << vq.pop(i);
        }
        cout << endl;
    }
}
