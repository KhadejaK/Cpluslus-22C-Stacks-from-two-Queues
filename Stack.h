//============================================================================
// Name        : Stack.h
// Author      : Khadeja Khalid and Tiffany Tran
// Version     : CIS 22C Lab 5
//============================================================================
#ifndef STACK_H_
#define STACK_H_


#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;

class Stack
{
    public:

        /**manipulation procedures*/

        void pop();
        //removes an element from the top of the stack
        //precondition: the stack isn't empty
        //postcondition: an element has been removed from the top of the stack

        void push(string data);
        //adds an element to the top of the stack
        //postcondition: an element added to the top of the stack

        /**accessors*/

        string getTop();
        //returns the element at the top of the stack
        //precondition: the stack is not empty

        int getSize();
        //returns the size of the stack

        bool isEmpty();
        //returns whether the stack is empty

        /**additional queue operations*/
        void print();
        //prints the elements in the stack to stdout


    private:
        Queue<string> q1;	// maintain order
        Queue<string> q2;	// used to push/pop elements

};



#endif /* STACK_H_ */
