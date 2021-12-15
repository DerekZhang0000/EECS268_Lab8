/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 BLOBLAB
 * Description:  This program will create a blob simulator.
 * Date: 11/8/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include <time.h>
#include "Queue.h"
#include "Stack.h"
#include "List.h"

clock_t t;
clock_t reset();
clock_t popStack(int n);
clock_t destructStack(int n);
clock_t enQ(int n);
clock_t getFirst(int n);
clock_t getLast(int n);
clock_t printAll(int n);
void run();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main(int argc, char** argv)
{   
    run();
}
void run()
{
    std::cout << "Testing...\n\n";
    test1();    //stack pop test
    test2();    //stack destruct test
    test3();    //queue enqueue test
    test4();    //linked list get first entry test
    test5();    //linked list get last entry test
    test6();      //linked list print all test
    std::cout << "...End\n";
}
clock_t reset(clock_t t)
{   //resets clock ticks
    return clock();
}
clock_t popStack(int n)
{
    Stack* st = new Stack();
    for(int x = 1; x <= n; x++)
    {
        st->push("");
    }
    t = reset(t);
    for(int x = 1; x <= n; x++)
    {
        st->pop();
    }
    t = clock() - t;
    return t;
}
void test1()
{   //timing pops for different stacks
    std::cout << "TEST 1: Time for a stack of n length to pop all elements\n===========================================================================\n";
    for(int k = 1; k <= 100; k++)
    {   //thousand multiplier runs from 1 to 100
        t = popStack(k * 1000);
        std::cout << (float)t/CLOCKS_PER_SEC << " seconds to pop a stack of " << k * 1000 << " elements\n";
    }
    std::cout << "===========================================================================\n\n";
}
clock_t destructStack(int n)
{   //creates a new stack of n elements and returns the time for it to delete
    Stack* st = new Stack();
    for (int i = 1; i <= n; i++)
    {
        st->push("");
    }
    t = reset(t);
    delete st;
    t = clock() - t;
    return t;
}
void test2()
{   //timing delete for different stacks
    std::cout << "TEST 2: Time for a stack of n elements to fully destruct\n===========================================================================\n";
    for(int k = 1; k <= 100; k++)
    {   //thousand multiplier runs from 1 to 100
        t = destructStack(k * 1000);
        std::cout << (float)t/CLOCKS_PER_SEC << " seconds for a stack of " << k * 1000 << " elements to destruct\n";
    }
    std::cout << "===========================================================================\n\n";
}
clock_t enQ(int n)
{   //returns the time to enqueue a queue of n elements
    Queue* q = new Queue();
    t = reset(t);
    for (int i = 1; i <= n; i++)
    {
        q->enqueue("");
    }
    t = clock() - t;
    return t;
}
void test3()
{   //timing enqueues for different queues
    std::cout << "TEST 3: Time for a queue of n elements to enqueue\n===========================================================================\n";
    for(int k = 1; k <= 100; k++)
    {   //thousand multiplier runs from 1 to 100
        t = enQ(k * 1000);
        std::cout << (float)t/CLOCKS_PER_SEC << " seconds for a queue of " << k * 1000 << " elements to be enqueued\n";
    }
    std::cout << "===========================================================================\n\n";
}
clock_t getFirst(int n)
{   //returns the time to get the first entry of a linked list of n elements
    List* l = new List();
    for (int i = 1; i <= n; i++)
    {
        l->insert(0, "");
    }
    t = reset(t);
    std::string tempString = l->getEntry(0);
    t = clock() - t;
    return t;
}
void test4()
{   //timing getting the first entry for different linked lists
    std::cout << "TEST 4: Time to get the first entry of a linked list of n elements\n===========================================================================\n";
    for(int k = 1; k <= 100; k++)
    {   //thousand multiplier runs from 1 to 100
        t = getFirst(k * 1000);
        std::cout << (float)t/CLOCKS_PER_SEC << " seconds to get the first element of a linked list of " << k * 1000 << " elements\n";
    }
    std::cout << "===========================================================================\n\n";
}
clock_t getLast(int n)
{   //returns the time to get the last entry of a linked list of n elements
    List* l = new List();
    for (int i = 1; i <= n; i++)
    {
        l->insert(0, "");
    }
    t = reset(t);
    std::string tempString = l->getEntry(n - 1);
    t = clock() - t;
    return t;
}
void test5()
{   //timing getting the last entry for different linked lists
    std::cout << "TEST 5: Time to get the last entry of a linked list of n elements\n===========================================================================\n";
    for(int k = 1; k <= 100; k++)
    {   //thousand multiplier runs from 1 to 100
        t = getLast(k * 1000);
        std::cout << (float)t/CLOCKS_PER_SEC << " seconds to get the last element of a linked list of " << k * 1000 << " elements\n";
    }
    std::cout << "===========================================================================\n\n";
}
clock_t printAll(int n)
{   //returns time to print all elements of a linked list
    List* l = new List();
    for (int i = 1; i <= n; i++)
    {
        l->insert(0, "");
    }
    std::string tempEntry = "";
    t = reset(t);
    for (int i = 1; i <= n; i++)
    {
        tempEntry = l->getEntry(i - 1);
        std::cout << tempEntry;
    }
    t = clock() - t;
    return t;
}
void test6()
{
    std::cout << "TEST 6: Time to print all entries of a linked list of n elements\n===========================================================================\n";
    for(int k = 1; k <= 100; k++)
    {   //thousand multiplier runs from 1 to 100
        t = printAll(k * 1000);
        std::cout << (float)t/CLOCKS_PER_SEC << " seconds to print all entries of a linked list of " << k * 1000 << " elements\n";
    }
    std::cout << "===========================================================================\n\n";
}