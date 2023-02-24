#ifndef UNTITLED3_MATRICES_H
#define UNTITLED3_MATRICES_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdarg>

class Row
{
private:
    double *rowptr;
    int size;
public:
    Row(int s):size(s){ rowptr = new double [s];}
    ~Row() { delete [] rowptr;}
    double& operator[] (int i)  throw(std::out_of_range)
    {
        if (i < 0 or i > size)
            throw std::out_of_range ("Colomn Index: Out of Range!");
        else
            return rowptr[i];
    }
    const double& operator[] (int i) const throw(std::out_of_range)
    {
        if (i < 0 or i > size)
            throw std::out_of_range ("Colomn Index: Out of Range!");
        else
            return rowptr[i];
    }
};

class Matrices
{
private:
    int lines , colomn;
    Row **mat;
public:
    Matrices(int l , int c):lines(l),colomn(c)
    {
        mat = new Row*[lines];
        for (int i = 0; i < lines; ++i)
        {
            mat[i] = new Row(colomn);
        }
    }
    Matrices(int l , int c , double val):lines(l),colomn(c)
    {
        mat = new Row*[lines];
        for (int i = 0; i < lines; ++i)
        {
            mat[i] = new Row(colomn);
            for (int j = 0; j < colomn; ++j)
            {
                (*this)[i][j] = val;
            }
        }
    }
    Matrices (const Matrices& m)
    {
        lines = m.lines;    colomn = m.colomn;
        mat = new Row*[lines];
        for (int i = 0; i < lines; ++i)
        {
            mat[i] = new Row(colomn);
            for (int j = 0; j < colomn; ++j)
            {
                (*this)[i][j] = m[i][j];
            }
        }
    }
    ~Matrices()
    {
        for (int i = 0; i < lines; ++i)
        {
           delete mat[i];
        }
        delete [] mat;
    }
    int getLines ()  { return lines; }
    int getColomn () { return colomn; }

    Row& operator[] (int i)  throw(std::out_of_range)
    {
        if (i < 0 or i > colomn)
            throw std::out_of_range ("Colomn Index: Out of Range!");
        else
            return *mat[i];
    }

    const Row& operator[] (int i) const throw(std::out_of_range)
    {
        if (i < 0 or i > colomn)
            throw std::out_of_range ("Colomn Index: Out of Range!");
        else
            return *mat[i];
    }

    Matrices& operator= (const Matrices& m);
    Matrices& operator+= (const Matrices& m);
};


#endif
