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
  // Read the Former Data
  ifstream iFile ("STUDENT.DAT");
  list <string> l2;
  istream_iterator<string> iIter (iFile);
  copy (iIter, istream_iterator <string>(), inserter(l2, l2.begin()));
  cout << endl;

  // Display it
  ostream_iterator <string> oIter2 (cout , " ");
  copy (l2.begin() ,l2.end(), oIter2);
    return 0;
}
