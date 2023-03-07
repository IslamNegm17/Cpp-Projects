#include "Search.h"
template<typename T, int n>
std::ostream& operator<<(std::ostream &os, const Array<T, n> &a)
{
    for (int i = 0; i < a.cnt; ++i)
        os << a.array[i];
    os << std::endl;
    return os;
}

template <typename T , int n>
Array<T,n>& Array<T,n>::operator= (const Array<T, n> &a)
{
    cnt = a.cnt;
    for (int i = 0; i < cnt; ++i)
        this->array[i] = a[i];
    return *this;
}

template <typename T , int n>
T Array<T,n>::operator[](int i) const throw(BadIndex)
{
    if (i < 0 || i >= cnt)
        throw BadIndex(i);
    return array[i];
}
