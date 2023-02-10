#include "CityCar.h"

bool CityCar::insert (const std::string &tp, bool sr, long n, const std::string &prod)
{
    if (cnt == 10)
    {
        cerr << "No Enough Space ...!" << std::endl;
        return false;
    }
    carArray[cnt] = new PassCar (tp,sr,n,prod);
    cnt++;
    return true;
}

bool CityCar::insert(int a, double t, long n, const string &prod)
{
    if (cnt == 10)
    {
        cerr << "No Enough Space ...!" << std::endl;
        return false;
    }
    carArray[cnt] = new Truck (a,t,n,prod);
    cnt++;
    return true;
}

void CityCar::display(void) const
{
    for (int i = 0; i < cnt; ++i)
    {
         carArray[i]->display();
    }
}

CityCar::~CityCar()
{
    for (int i = 0; i < cnt; ++i)
    {
        delete carArray[i];
    }
}
