#include "Matrices.h"

Matrices &Matrices::operator= (const Matrices &m)
{
    // Free old Storage
    for (int i = 0; i < lines; ++i)
    {
        delete mat[i];
    }
     delete [] mat;

    // Add new Storage
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
    return *this;
}

Matrices &Matrices::operator+= (const Matrices &m)
{
    if (lines == m.lines and colomn == m.colomn)
        for (int i = 0; i < lines; ++i)
            for (int j = 0; j < colomn; ++j)
                (*this)[i][j] += m[i][j];
    return *this;
}
