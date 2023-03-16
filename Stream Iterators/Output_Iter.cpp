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
//#include <climits>   // The maximum and minimum size of integral values
//#include <conio.h>     // For getch() and putch()
//#include <sstream>
//#include <cmath>
//#include <windows.h>
#include <fstream>
//#include <typeinfo>
using namespace std;
//using namespace std::chrono;

#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

int main ()
{
  ofstream oFile ("STUDENT.DAT");
  char* name[] = {"Islam" , "Yasein" , "Nejm"};
  list <char*> l1;

  // Fill The List ,Then Out it to File
  copy (name, name+3, inserter(l1, l1.begin()));
  ostream_iterator <char*> oIter (oFile , " ");
  copy (l1.begin(), l1.end(), oIter);
    return 0;
}
