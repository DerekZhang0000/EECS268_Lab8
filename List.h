/* -----------------------------------------------------------------------------
 *
 * File Name:  List.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 5
 * Description:  This program will create a website simulator.
 * Date: 10/18/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef LIST_H
#define LIST_H
#include "ListInterface.h"
#include "Node.h"
#include <string>

class List : public ListInterface<std::string>
{   //this class is a linked list of strings
    public:
    List();
    ~List();
    /**
    * @pre The index is valid
    * @post The entry is added to the list at the index, increasing length by 1
    * @param index, position to insert at (1 to length+1)
    * @param entry, value/object to add to the list
    * @throw std::runtime_error if the index is invalid
    */
   void insert(int index, std::string entry);
   /**
    * @pre The index is valid
    * @post The entry at given position is removed, reducing length by 1 
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    void remove(int index);
    /**
    * @pre The index is valid
    * @post None 
    * @param index, position to insert at (1 to length)
    * @throw std::runtime_error if the index is invalid
    */
    std::string getEntry(int index) const;
    /**
    * @pre None
    * @post List is empty
    * @throw None
    */
    void clear();
    /**
    * @pre The index is valid (must already exist)
    * @post Given entry overrides the entry at the given index 
    * @param index, position to override at (1 to length)
    * @param entry, value/object to place at given index
    * @throw std::runtime_error if the index is invalid
    */
    void setEntry(int index, std::string entry);
    /**
    * @pre None
    * @post None
    * @return the length of the list is returned
    */
    int getLength() const;
    private:
    int length;
    Node* m_front;
};
#endif