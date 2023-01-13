#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;


int main (int argc , char *argv[])
{
  if ( argc != 2 )
  {
      cerr << "Use: show file name: " << endl;
      return 1;
  }
  ifstream file (argv[1]);
  if (file.fail())
  {
      cerr << "Error in Opining the File" << endl;
      return 2;
  }

  char line [100];
  char c;

    while (file.get(c))
    {
        cout << c <<"";
        Sleep(100);
        if (file.eof())
        {
            cout << "Done!" << endl;
        }
    }

  if (!file.eof())
  {
      cerr << "Error in Reading the File" << endl;
      return 3;
  }
}
