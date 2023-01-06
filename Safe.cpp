#include <iostream>
#include <climits>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

int TimeCalc (void);
string Password ("hack");
string pass;
int Limits = 15;                // 15 Seconds
bool pass_ok = false;
int attempts = 3 , Time = 0;

int main ()
{
    TimeCalc();   // Start Timing
    while (--attempts >= 0 && pass_ok != true)
    {
        cout << "Please Enter the Password: " ;
        cin.sync();
        cin >> setw(10) >> pass;
        Time += TimeCalc();
        if (Time >= Limits)
        {
            cout << "Time OUT !!" << endl << "Please Re-start the Safe" << endl;
            break;
        }
        else
        {
            if (pass == Password)
            {
                pass_ok = true;
                cout << "Get Accessed" << endl;
            }
            else
                cout << "Incorrect Password and still have " << attempts << " Attempts" << endl;
        }
    }
}

int TimeCalc (void)
{
    static long sec1 = 0;       // The Time Running
    long sec2 = sec1;           // Put the Old Seconds in sec2
    sec1 = time (NULL);   // Get the New Seconds
    return (sec1- sec2);        // Return the Difference
}
