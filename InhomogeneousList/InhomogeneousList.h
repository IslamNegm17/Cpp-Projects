#ifndef INHOMOGENEOUSLIST_H
#define INHOMOGENEOUSLIST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <typeinfo>

class Cell
{
private:
    Cell *next;
protected:
    Cell(Cell *sec = nullptr) : next(sec) {}

public:
    Cell *getNext() const
    {
        return next;
    }
    void setNext (Cell *sec)
    {
        next = sec;
    }
    virtual ~Cell(){};
    virtual void display () const = 0;
};

class BaseEl : public Cell
{
private:
    std::string name;
public:
    BaseEl(Cell *sec = nullptr, const std::string &s = " ") : Cell(sec), name(s) {}
    void setName(const std::string &s)
    {
        name = s;
    }
    const std::string &getName() const
    {
        return name;
    }
    void display() const
    {
        std::cout << "\n--------------------------------"
                  << "\nName: " << name << std::endl;
    }
};

class DerivedEl : public BaseEl
{
private:
    std::string rem;
public:
    DerivedEl(Cell* suc = NULL, const std::string& s = " ", const std::string& b = " "): BaseEl(suc, s), rem(b){}
    void setRem(const std::string& b)
    {
        rem = b;
    }
    const std::string& getRem() const
    {
        return rem;
    }
    void display() const
    {
        BaseEl::display();
        std::cout << "Remark: " << rem << std::endl;
    }
};

class InhomList
{
private:
    Cell* first;
protected:
    Cell* getPrev(const std::string& s);
    Cell* getPos( const std::string& s);
    void insertAfter(const std::string& s, Cell* prev);
    void insertAfter(const std::string& s,const std::string& b,Cell* prev);
    void erasePos(Cell* pos);
public:
    InhomList(){ first = NULL; }
    InhomList(const InhomList& src);
    ~InhomList();
    InhomList& operator=( const InhomList& src);
    void insert(const std::string& n);
    void insert(const std::string& n, const std::string& b);
    void erase(const std::string& s);
    void displayAll() const;
};


#endif
