#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    long nr;
    string producer;
public:
    Car( long n = 0L, const string& prod = "");
    virtual ~Car();
    long getNr(void) const { return nr; }
    void setNr( long n ) { nr = n; }
    const string& getProd() const{ return producer; }
    void setProd(const string& p){ producer = p; }
    virtual void display( void ) const;
};


class PassCar : public Car
{
private:
    string passCarType;
    bool sunRoof;
public:
    PassCar( const string& tp, bool sd, int n = 0 , const string& h = "");
    ~PassCar();
    const string& getType() const{ return passCarType; }
    void setType( const string s) { passCarType = s; }
    bool getSunRoof() const { return sunRoof; }
    void setSunRoof( bool b ) { sunRoof = b; }
    void display() const;
};

class Truck : public Car
{
private:
    int axles;
    double tons;
public:
    Truck( int a, double t, int n, const string& hs);
    ~Truck();
    void setAxles(int l){ axles = l;}
    int getAxles() const { return axles; }
    void setCapacity( double t) { tons = t;}
    double getCapacity() const { return tons; }
    void display() const;
};

#endif
