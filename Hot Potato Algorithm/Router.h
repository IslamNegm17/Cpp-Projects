#ifndef UNTITLED3_ROUTER_H
#define UNTITLED3_ROUTER_H

#include <algorithm>
#include <vector>
#include <queue>
#include <stdexcept>

template <typename T>
class VecQueue
{
private:
    std::vector<std::queue<T>> v;
    int numberOfQueues = 0;
public:
    VecQueue(int n = 0);
    int size (void) const;
    int size (int n) const   { return v[n].size(); };
    bool empty (void) const  { return v.empty(); }
    bool empty (int n) const { return v[n].empty(); };
    void push (const T&);
    const T& pop (int i) throw(std::out_of_range);
};

template<typename T>
VecQueue<T>::VecQueue(int n)
{
  if (n > 0)
      v.resize(n);
  numberOfQueues = n;
}


template<typename T>
void VecQueue<T>::push(const T& n)
{
    int indexMin = 0;
    for (int i = 0; i < numberOfQueues; i++)
    {
        if (v[indexMin].size() > v[i].size())
            indexMin = i;
    }
    v[indexMin].push(n);
}

template<typename T>
const T& VecQueue<T>::pop(int i) throw(std::out_of_range)
{
    static T temp = 0;
    if (i >= 0 and i < numberOfQueues )
    {
        temp = v[i].front();
        v[i].pop();
    }
    else
        throw std::out_of_range("Out of Range!");
    return temp;
}

template<typename T>
int VecQueue<T>::size(void) const
{
    T counter = 0;
    for (int i = 0; i < numberOfQueues; ++i)
    {
        counter += v[i].size();
    }
    return counter;
}


#endif
