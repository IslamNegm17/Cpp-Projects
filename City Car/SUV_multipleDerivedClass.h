#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    long nr;
    std::string producer;
public:
    Car( long n = 0L, const string& prod = " "):nr(n),producer(prod){}
    virtual ~Car()
    {
        cout << "Destroyed" << std::endl;
    }
    long getNr() const { return nr; }
    void setNr( long n ) { nr = n; }
    const string& getProd() const{ return producer; }
    void setProd(const string& p){ producer = p; }
    virtual void display() const
    {
        cout << "\nCar number: " << nr
             << "\nProducer: " << producer
             << endl;
    }
};


class PassCar : public virtual Car
{
private:
    std::string passCarType;
    bool sunRoof;
public:
    PassCar(long n = 0L , const string& h = " ", const string& tp = " ", bool sd = false)
            :Car( n, h), passCarType( tp ), sunRoof( sd ){};

    const string& getType() const{ return passCarType; }
    void setType( const string s) { passCarType = s; }
    bool getSunRoof() const { return sunRoof; }
    void setSunRoof( bool b ) { sunRoof = b; }
    void display() const
    {
        Car::display();
        cout << "Type: " << passCarType
             << "\nSunroof: ";
        if(sunRoof)
                cout << "Yes "<< endl;
        else
                cout << "No " << endl;
    }
};

class Van : public virtual Car
{
private:
    double capacity;
public:
    Van(long n = 0L, const string& prod = " ", double l = 0.0):Car(n,prod),capacity(l){}
    void setCapacity (double l)
    {
        if(l > 750)
            capacity= 750;
        else
            capacity = l;
    }
    double getCapacity() const { return capacity; }
    void display() const
    {
        Car::display();
        cout << "Capacity: "
             << capacity << " kg" << endl;
    }
};

class SUV : public PassCar , public Van
{
private:
   int NumberOfSeats;
public:
    SUV (long n = 0L, const string& prod = " ", const string& tp = " ", bool sd = false, double l = 0.0, int ns = 1)
          : PassCar(n,prod,tp,sd),Van(n,prod,l), Car(n,prod), NumberOfSeats(ns){}
    void display() const
    {
        PassCar::display();
        Van::display();
        cout << "Number of seats: " << NumberOfSeats << endl;
    }
};


#endif
