/* -----------------------------------------------------------------------------
 *
 * File Name:  List.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 5
 * Description:  This program will create a website simulator.
 * Date: 10/18/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include "List.h"
#include "Node.h"
#include <string>
#include <stdexcept>
#include <iostream>

List::List()
{   //constructor
    length = 0;
    m_front = nullptr;
}
List::~List()
{   //destructor
    delete m_front;
}
void List::insert(int index, std::string entry)
{   //insert entry at a specified index
    if (index > length || index < 0)
    {   //if index is out of bounds
        throw(std::runtime_error("Invalid index"));
    }
    else if (index == 0 && length == 0)
    {   //if list is empty
        Node* tempNode = new Node(entry);
        m_front = tempNode;
        length++;
    }
    else if (index == 0)
    {
        Node* tempNode = new Node(entry);
        tempNode->setNext(m_front);
        m_front = tempNode;
        length++;
    }
    else
    {   //adds to list
        Node* oneBefore = m_front;
        Node* target = nullptr;
        Node* newNode = new Node(entry);
        for (int x = 0; x < index - 1; x++)
        {
            oneBefore = oneBefore->getNext();
        }
        target = oneBefore->getNext();
        newNode->setNext(target);
        oneBefore->setNext(newNode);
        length++;
    }
}
void List::remove(int index)
{   //removes entry at a specified index
    Node* tempNode = m_front;
    Node* oneBefore = m_front;
    Node* oneAfter = nullptr;
    if (index >= length || index < 0)
    {   //if index is out of bounds
        throw(std::runtime_error("Invalid index"));
    }
    else if (index == 0)
    {   //if first entry is going to be deleted
        m_front = m_front->getNext();
        length--;
    }
    else
    {   //removes from list
        for (int x = 0; x < index - 1; x++)
        {
            oneBefore = oneBefore->getNext();
        }
        tempNode = oneBefore->getNext();
        oneAfter = tempNode->getNext();
        oneBefore->setNext(oneAfter);
        length--;
    }
}
std::string List::getEntry(int index) const
{   //gets entry at index
    Node* tempNode = m_front;
    if (index >= length || length == 0)
    {   //if index is out of bounds
        throw(std::runtime_error("Invalid index"));
    }
    else
    {   //returns entry at index
        for (int x = 0; x < index; x++)
        {
            tempNode = tempNode->getNext();
        }
        return (tempNode->getEntry());
    }
}
void List::setEntry(int index, std::string entry)
{   //sets entry at index
    Node* tempNode = m_front;
    if (index >= length || length == 0)
    {   //if index is out of bounds
        throw(std::runtime_error("Invalid index"));
    }
    else
    {   //sets entry at index
        for (int x = 0; x < index; x++)
        {
            tempNode = tempNode->getNext();
        }
        tempNode->setEntry(entry);
    }
}
void List::clear()
{   //clears list
    while (m_front != nullptr)
    {
        Node* tempNode = m_front;
        m_front = m_front->getNext();
        delete tempNode;
    }
}
int List::getLength() const
{   //returns length
    return length;
}