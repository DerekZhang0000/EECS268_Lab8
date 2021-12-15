/* -----------------------------------------------------------------------------
 *
 * File Name:  StackInterface.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 8
 * Description:  This program will time functions of data structures.
 * Date: 11/8/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include "Node.h"

#include <stdexcept>

template <typename T>
class StackInterface
{
	public:
	virtual void push(T entry) = 0;
	virtual void pop() = 0;
	virtual T peek() const = 0;
	virtual bool isEmpty() const = 0;
    virtual ~StackInterface() {} //virtual destructor

};

#endif