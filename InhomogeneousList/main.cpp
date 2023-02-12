#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>
//#include <cstring>
//#include <climits>  //The maximum and minimum size of integral values
//#include <sstream>
//#include <cmath>
//#include <windows.h>
//#include <fstream>
//#include "Product.h"
#include "InhomogeneousList.h"
using namespace std;


int main ()
{
    InhomList liste1;
    cout << "\nTo test inserting. " << endl;
    liste1.insert("Bully, Max");
    liste1.insert("Cheers, Rita", "always merry");
    liste1.insert("Quick, John", "topfit");
    liste1.insert("Banderas, Antonio");
    liste1.displayAll(); cin.get();
    cout << "\nTo test deleting. " << endl;
    liste1.erase("Banderas, Antonio");
    liste1.erase("Quick, John");
    liste1.erase("Cheers, Rita");
    liste1.displayAll(); cin.get();
    cout << "\n----------------------------------"
         << "\nGenerate a copy and insert an element. "
         << endl;
    InhomList liste2(liste1), // Copy constructor
    liste3; // and an empty list.
    liste2.insert("Chipper, Peter", "in good temper");
    liste3 = liste2; // Assignment
    cout << "\nAfter the assignment: " << endl;
    liste3.displayAll();
    return 0;
}
