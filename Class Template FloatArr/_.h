#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

class BadIndex
{
private:
    int index;
public:
    BadIndex(int n):index(n){}
    int getIndex () const { return index; }
};

class OutOfRange { /*Without Data Members*/ };

template <typename T , int n = 256>
class Array
{
private:
    T array[n];
    int cnt;
public:
    Array() { cnt = 0; };
    Array(int c , T val)
    {
        cnt = c;
        for (int i = 0; i < cnt; ++i)
            array[i] = val;
    }
    Array(Array<T,n> &a)
    {
        cnt = a.cnt;
        for (int i = 0; i < cnt; ++i)
            array[i] = a.array[i];
    }
    Array<T,n>& operator= (const Array<T,n> &);
    int length () const  { return cnt; }
    int size () const  { return n; }
    T operator[] (int i) const throw(BadIndex);
    void append (T val) throw(OutOfRange);
    void append (const Array<T,n>&);
    const Array<T,n>& operator+= (T val)
    {
        append(val);
        return *this;
    }
    const Array<T,n>& operator+= (const Array<T,n>&);
    void insert (Array<T,n>& a , int pos) throw (OutOfRange , BadIndex);
    void insert (T val , int pos) throw (OutOfRange , BadIndex)
    {
        insert( Array<T,n>(1,val) , pos);
    }
    void remove (int pos) throw (BadIndex);
    friend std::ostream& operator<< (std::ostream& ,const Array<T,n>&);
};


template <typename T , int n>
const Array<T,n>& Array<T,n>::operator+=(const Array<T, n> &a)
{
    append(a);
    return *this;
}

template<typename T, int n>
void Array<T, n>::append(T val) throw(OutOfRange)
{
    if (cnt < n)
        array[cnt++] = val;
    else
        throw OutOfRange ();
}

template<typename T, int n>
void Array<T, n>::append(const Array<T, n> &a)
{
    if (n > (cnt + a.cnt))
        for (int i = cnt , j = 0; i < a.cnt || j < a.cnt; ++i , j++)
            array[i] = a.array[j];
    else
        throw OutOfRange ();
}

template<typename T, int n>
void Array<T, n>::insert(Array<T, n> &a, int pos) throw (OutOfRange , BadIndex)
{
    if (pos < 0 || pos >= cnt)
        throw BadIndex(pos);
    if (n < cnt + a.cnt)
        throw OutOfRange();

    for (int i = cnt - 1; i >= pos; --i)
    {
        array[a.cnt++] = array[i];
    }

    for (int j = 0; j < a.cnt; j++)
    {
        array[j+pos] = a.array[j];
    }
}

template<typename T, int n>
void Array<T, n>::remove(int pos) throw(BadIndex)
{
    if (pos < 0 || pos >= cnt)
        throw BadIndex(pos);
    for (int i = pos+1; i < cnt; ++i)
        array[i-1] = array[i];
}



#endif
