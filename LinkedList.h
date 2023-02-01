#ifndef UNTITLED3_LIST_H
#define UNTITLED3_LIST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>

class Node
{
private:
    int data;
public:
    Node *next;
    int getData () const { return data;}
    friend class LinkedLists;
};

class LinkedLists
{
private:
    Node *head , *last;
public:
    LinkedLists():head(NULL),last(NULL){}
    void InsertFirst (int d)
    {
        Node *newnode = new Node;
        newnode -> data = d;
        if (head == NULL)
        {
            newnode -> next = NULL;
            head = last = newnode;
        }
        else
        {
           newnode -> next = head;
           head = newnode;
        }
    }

    void InsertAppend (int d)
    {
        Node *newnode = new Node;
        newnode -> data = d;
        newnode -> next = NULL;
        last -> next = newnode;
        last = newnode;
    }

    void DeleteFirst ()
    {
        Node *dltptr = head;
        head = head -> next;
        delete dltptr;
    }

    void DeleteAppend ()
    {
        Node *tempptr = head;
        while (tempptr -> next != last)
            tempptr = tempptr -> next;
        tempptr -> next = NULL;
        delete last;
        last = tempptr;
    }

    void DeleteNodes ()
    {
        Node *tempptr = head;
        while (head != NULL)
        {
            tempptr = head;
            head = head -> next;
            delete tempptr;
        }
        if (head == NULL)
        {
            std::cout << "Empty Linkedlist" << std::endl;
            return;
        }
    }

    friend std::ostream& operator<< (std::ostream& os , const LinkedLists& L1);
};
std::ostream& operator<< (std::ostream& os , const LinkedLists& L1)
{
    Node *tempptr = L1.head;
    while (tempptr != NULL)
    {
        os << tempptr->getData() << "  ";
        tempptr = tempptr -> next;
    }
    return os;
}

#endif
