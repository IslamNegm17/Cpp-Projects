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

#include "Car.h"
#include "CityCar.h"
using namespace std;

char menu ();
void getPassCar (string& , bool& ,long& , string&);
void getTruck (int& , double& ,long& , string& );

int main ()
{
    CityCar carExpress;
    string tp, prod; bool sr;
    int a; long n; double t;

    carExpress.insert(6, 9.5, 54321, "Ford");
    carExpress.insert("A-class", true, 54320, "Mercedes");

    char choice;
    do
    { choice = menu();
        switch( choice )
        {
            case 'Q':
            case 'q': cout << "Bye Bye!" << endl;
                break;
            case 'P':
            case 'p': getPassCar(tp, sr, n, prod);
                carExpress.insert(tp, sr, n, prod );
                break;
            case 'T':
            case 't': getTruck(a, t, n, prod);
                carExpress.insert(a, t, n, prod);
                break;
            case 'D':
            case 'd': carExpress.display();
                cin.get();
                break;
            default: cout << "\a"; // Beep
                break;
        }
    }while( choice != 'Q' && choice != 'q');
    return 0;
}

void getPassCar (string& tp, bool& sr,long& n, string& prod)
{
    cin.sync();  cin.clear();
    cout << "\nEnter Car Data .. Please!" << endl;
    cout << "Car Type: ";
    getline(cin,tp);

    cout << "SunRoof (Y/N): ";
    char c = '\0';
    cin >> c;
    (c == 'Y' or c == 'y')?(sr = true):(sr = false);

    cout << "Number: ";
    cin >> n;

    cout << "Enter The Producer Name: ";
    cin.sync();                           // synchronize the input stream with whatever has been entered
    getline(cin,prod);
    cin.sync();  cin.clear();
}

void getTruck (int& a, double& t,long& n, string& prod)
{
    cin.sync();  cin.clear();
    cout << "\nEnter Truck Data .. Please!" << endl;
    cout << "Number of Axis: ";
    cin >> a;

    cout << "Weigh in Tons: ";
    cin >> t;

    cout << "Number: ";
    cin >> n;

    cout << "Enter The Producer Name: ";
    cin.sync();
    getline(cin,prod);
    cin.sync();  cin.clear();
}

char menu ()
{
    cout << "\n * * * Car Rental Management * * *\n\n";
    char c;
    cout << "\n P = Add a passenger car "
         << "\n T = Add a truck "
         << "\n D = Display all cars "
         << "\n Q = Quit the program "
         << "\n\nYour choice: ";
    cin >> c;
    return c;
}

