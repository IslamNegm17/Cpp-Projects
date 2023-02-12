#include "InhomogeneousList.h"

InhomList::InhomList(const InhomList &src)
{
 first = nullptr;
 Cell *ptr = src.first;
 for (; ptr != nullptr; ptr = ptr->getNext())
 {
     if (typeid(*ptr) == typeid(DerivedEl))
     insert(dynamic_cast<DerivedEl *>(ptr) -> getName() , dynamic_cast<DerivedEl *>(ptr) -> getRem());
     else
     insert(dynamic_cast<DerivedEl *>(ptr) -> getName());
 }
}

InhomList &InhomList::operator=(const InhomList &src)
{
    Cell *ptr = first , *next = first;
    while (ptr != nullptr)
    {
        next = ptr->getNext();
        delete ptr;
        ptr = next;
    }
    first = nullptr;
    ptr = src.first;
    for (; ptr != nullptr; ptr = ptr->getNext())
    {
        if (typeid(*ptr) == typeid(DerivedEl))
            insert(dynamic_cast<DerivedEl *>(ptr) -> getName() , dynamic_cast<DerivedEl *>(ptr) -> getRem());
        else
            insert(dynamic_cast<DerivedEl *>(ptr) -> getName());
    }
    return *this;
}

InhomList::~InhomList()
{
    Cell *ptr = first , *next = first;
    while (ptr != nullptr)
    {
        next = ptr->getNext();
        delete ptr;
        ptr = next;
    }
}

Cell *InhomList::getPrev(const std::string &s)
{
    Cell *ptr = first , *prv = first;
    while (ptr != nullptr)
    {
        if (s > dynamic_cast<BaseEl *>(ptr)->getName())
        {
            prv = ptr;
            ptr = ptr->getNext();
        }
        else
            return prv;
    }
    return prv;
}

Cell *InhomList::getPos(const std::string &s)
{
    Cell *ptr = first;
    while (ptr != nullptr and dynamic_cast<BaseEl *>(ptr)->getName() != s)
        ptr = ptr->getNext();
    if (dynamic_cast<BaseEl *>(ptr)->getName() == s)
        return ptr;
    else
        return nullptr;
}

void InhomList::insertAfter(const std::string &s, Cell *prev)
{
    if (first == nullptr)
        first = new BaseEl(first , s);
    else
    {
        Cell *ptr = new BaseEl(prev->getNext() , s);
        prev->setNext(ptr);
    }
}

void InhomList::insertAfter(const std::string &s, const std::string &b, Cell *prev)
{
    if (first == nullptr)
        first = new DerivedEl(first , s , b);
    else
    {
        Cell *ptr = new DerivedEl(prev->getNext() , s , b);
        prev->setNext(ptr);
    }
}

void InhomList::insert(const std::string &n)
{
    Cell *ptr = getPrev(n);
    insertAfter(n,ptr);
}

void InhomList::insert(const std::string &n, const std::string &b)
{
    Cell *ptr = getPrev(n);
    insertAfter(n, b ,ptr);
}

void InhomList::erasePos(Cell *pos)
{
    Cell* temp;
    if (pos != nullptr)
        if (pos == first)
        {
            temp = first;
            first = first->getNext();
            delete temp;
        }
       else
        {
            temp = getPrev(dynamic_cast<BaseEl *>(pos)->getName());
            if (temp != nullptr)
                     temp->setNext(pos->getNext());
            delete pos;
        }
}

void InhomList::erase(const std::string &s)
{
    erasePos(getPos(s));
}

void InhomList::displayAll() const
{
    Cell* ptr = first;
    while (ptr != nullptr)
    {
        ptr->display();
        ptr = ptr->getNext();
    }

}
