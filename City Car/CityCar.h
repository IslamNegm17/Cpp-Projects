#ifndef CITYCAR_H
#define CITYCAR_H

#include "Car.h"

class CityCar
{
private:
    Car *carArray[10];
    int cnt;
public:
    CityCar():cnt(0){};
    ~CityCar();
    bool insert(const string& tp, bool sr,long n, const string& prod);   //Adding New PassCar
    bool insert(int a, double t, long n,const string& prod);             //Adding new Truck
    void display (void) const;
};


#endif
