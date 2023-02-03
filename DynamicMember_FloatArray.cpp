#ifndef UNTITLED3_FLOATARR_H
#define UNTITLED3_FLOATARR_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

class FloatArr
{
private:
    float *arrptr;
    int cnt , max;

    void expand (int newMax);

public:
    FloatArr(int size);
    FloatArr(int size , float value);
    ~FloatArr();
    int length () const {return cnt;}
    float operator[] (int i);
    void append (float value);
    void append (const FloatArr& f);
    bool remove (int pos);
    FloatArr& operator+= (float value);
    FloatArr& operator+= (const FloatArr& f);
    friend std::ostream& operator<< (std::ostream& os , const FloatArr& f);
};


#endif



//---------------------------------------------------------------------------------------------------------------------------



#include "FloatArr.h"
FloatArr::FloatArr(int size)
{
    max = size;
    cnt = 0;
    arrptr = new float [size];
}

FloatArr::FloatArr(int size, float value)
{
    max = cnt = size;
    arrptr = new float [size];
    for (int i = 0; i < cnt; ++i)
    {
         arrptr[i] = value;
    }
}

FloatArr::~FloatArr()
{
    delete [] arrptr;
}

void FloatArr::append(float value)
{
   if (cnt+1 > max)
   {
       expand(cnt+1);
   }
   arrptr[cnt++] = value;
}

bool FloatArr::remove(int pos)
{
    if (pos >= 0 and pos < cnt)
    {
        for (int i = pos; i < cnt - 1 ; ++i)
        {
          arrptr[i] = arrptr[i+1];
        }
        cnt--;
        return true;
    }
    return false;
}

float FloatArr::operator[](int i)
{
    if (i < 0 or i > cnt )
    {
        std::cerr << "No Enough Space" << std::endl;
        return false;
    }
    return arrptr[i];
}

void FloatArr::expand(int newMax)
{
  max = newMax;
  if (max > newMax)
      return;
  float *temp = new float [newMax];
    for (int i = 0; i < cnt; ++i)
    {
        temp[i] = arrptr[i];
    }
    delete[] arrptr;
    arrptr = temp;
}

void FloatArr::append(const FloatArr &f)
{
    int freespace = max - cnt;
    if (freespace >= f.cnt)
    {
        for (int i = cnt , j = 0; i < max and j < f.cnt; ++i , j++)
        {
            arrptr[cnt++] = f.arrptr[j];
        }
    }
    else
    {
        int spacenedded = ( abs(f.cnt - freespace) + max );
        float *temp = new float [spacenedded];
        for (int i = 0; i < cnt; ++i)
        {
             temp[i] = arrptr[i];
        }
        for (int i = cnt, j = 0; i < f.cnt + cnt or j < f.cnt; ++i, ++j)
        {
             temp[i] = f.arrptr[j];
        }
        delete[] arrptr;
        arrptr = temp;
    }
}

FloatArr& FloatArr::operator+= (float value)
{
    append(value);
    return *this;
}

FloatArr &FloatArr::operator+= (const FloatArr &f)
{
    append(f);
    return *this;
}

std::ostream& operator<< (std::ostream& os , const FloatArr& f)
{

    for (int i = 0; i < f.cnt; ++i)
    {

       os << std::setw(5) << f.arrptr[i];
    }
    return os;
}
