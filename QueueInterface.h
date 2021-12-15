/* -----------------------------------------------------------------------------
 *
 * File Name:  QueueInterface.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 8
 * Description:  This program will time functions of data structures.
 * Date: 11/8/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H
#include "Node.h"

#include <stdexcept>

template <typename T>
class QueueInterface
{
	public:
	virtual void enqueue(T entry) = 0;
	virtual void dequeue() = 0;
	virtual T peek_front() const = 0;
	virtual bool isEmpty() const = 0;
    virtual ~QueueInterface() {} //virtual destructor
};

#endif