/*******************************************************************************
************************************[Header]************************************
********************************************************************************/
#ifndef UNTITLED3_TELEPHONE_LIST_H
#define UNTITLED3_TELEPHONE_LIST_H
#include <iostream>
#include <string>
#define MAX         100
struct Element
{
    std::string name;
    std::string tel_num;
};

class TelList
{
private:
    int counter;
    Element users_array[MAX];
public:
    TelList() {counter = 0;}
    int getCounter () const { return counter; }
    Element *retrieve (int index)
    {
        return ( ( index >= 0 && index < counter)? &users_array[index] : nullptr );
    }
    bool addAppend (const std::string &name , const std:: string &tel_num);
    bool addAppend (const Element &E1)
    {
        return addAppend(E1.name , E1.tel_num);
    }
    bool erase (const std::string &name);
    int search (const std::string &name);
    void print ();
    bool print (const std::string &name);
};
#endif


/*******************************************************************************
************************************[source]************************************
********************************************************************************/
#include <iostream>
#include <string>
#include "Telephone List.h"

bool TelList::addAppend(const std::string &name, const std::string &tel_num)
{
    if ( counter < MAX)
    {
        int i;
        for (i = 0; i < counter ; ++i)
        {
            if (name == users_array [counter].name)
            {
                std::cout << "Please Re-enter other Name because this name already Existed .. !!" << std::endl;
                return false;
            }
        }
        users_array [counter].name = name;
        users_array [counter].tel_num = tel_num;
        counter++;
        return true;
    }
    return false;
}

int TelList::search(const std::string &name)
{
    int i;
    for (i = 0; i < counter ; ++i)
    {
        if (name == users_array [i].name)
        {
            std::cout << "The Name founded and Telephone is: " << users_array [i].tel_num << std::endl;
            return i;
        }
    }
    std::cout << "The Name isn't here !!" << std::endl;
    return 0;
}

bool TelList::erase(const std::string &name)
{
    int founding_result = TelList::search(name);
    if (founding_result == 0)
    {
        std::cout << "The Name isn't here !!" << std::endl;
        return false;
    }
    else
    {

        users_array [founding_result].name    = users_array [counter - 1].name;
        users_array [founding_result].tel_num = users_array [counter - 1].tel_num;
        counter--;
    }
}

void TelList::print()
{
    for (int i = 0; i < counter ; ++i)
    {
        std::cout << "Name: " << users_array[i].name << "\tTelephone: " << users_array[i].tel_num <<std::endl;
    }

}

bool TelList::print(const std::string &name)
{
    for (int i = 0; i < counter ; ++i)
    {
        if (name.compare(0,name.length(),users_array[i].name) < 1)
        {
            std::cout << "Founded" << '\n' << "Name: " << users_array[i].name << "\tTelephone: " << users_array[i].tel_num <<std::endl;
            return true;
        }
    }
    std::cout << "Not-Founded" <<std::endl;
    return false;
}


/*******************************************************************************
************************************[source_]************************************
********************************************************************************/
#include <iostream>
#include <sstream>
#include <climits>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include "Telephone List.h"
using namespace std;


int main ()
{
 TelList myFriends;
 myFriends.addAppend("Ahmed","010662658");
 myFriends.addAppend("Ali","01156455802");
 myFriends.addAppend("Islam","0126588125");
 myFriends.addAppend("Walid","0166832658");
 myFriends.addAppend("Fahim","01550564802");
 myFriends.addAppend("John","00996658125");

 myFriends.print();
 cout << '\n';
 myFriends.search("Ali");
 myFriends.print("Al");

}
