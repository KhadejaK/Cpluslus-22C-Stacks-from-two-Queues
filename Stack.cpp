//============================================================================
// Name        : Stack.cpp
// Author      : Khadeja Khalid and Tiffany Tran
// Version     : CIS 22C Lab 5
//============================================================================

#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;

/************************ Manipulation Procedures *******************************/

//Adds an element to the top of the stack
//Postcondition: an element added to the top of the stack
void Stack::push(string data)
{
	//You want to input new data into an empty q
	//and then if the other q has any data, you want to put that behind the new data
	//Thus, the new data is always on top/at front

	if (q1.isEmpty())
	{
		q1.enqueue(data); //Input data into one q

		//To get stack order:
		while (!q2.isEmpty())
		{
			q1.enqueue(q2.getFront());
			q2.dequeue();
		}
	}
	else
	{
		q2.enqueue(data); //Input 2nd data into 2nd q

		//To get stack order:
		while (!q1.isEmpty())  		    //Put q1 (1st data) behind q2 (2nd data)
		{
			q2.enqueue(q1.getFront());  //Put data from the top of q1 into the back of q2
			q1.dequeue();               //Pop the data from the top of q1
		}

	}

}

//Removes an element from the top of the stack
//Precondition: the stack isn't empty
//Postcondition: an element has been removed from the top of the stack
void Stack::pop()
{
	//Make sure both q's are not empty, precondition
	//Then, remove front element from the not empty q
	if (q2.isEmpty())
	{
		assert (!q1.isEmpty());
		q1.dequeue(); 			//Removes element front the front aka top
	}
	else
	{
		assert (!q2.isEmpty());
		q2.dequeue();
	}


}


/************************ Access Functions ****************************************/

//Returns the element at the top of the stack
//Precondition: the stack is not empty
string Stack::getTop()
{
	//Make sure both q's are not empty, precondition
	//You want to return the top of the not empty queue
	if (q2.isEmpty())
	{
		assert (!q1.isEmpty());
		return q1.getFront();
	}
	else
	{
		assert (!q2.isEmpty());
		return q2.getFront();
	}
}

//Returns the size of the stack
int Stack::getSize()
{
	//want to return the size of the not empty queue
	if (q2.isEmpty())
		return q1.getSize();
	else
		return q2.getSize();
}


//Returns whether the stack is empty
bool Stack::isEmpty()
{
	if (q1.isEmpty())					// if q1 is empty, check size of q2
		return (q2.getSize() == 0);
	else								// if q2 is empty, check size of q1
		return (q1.getSize() == 0);

}


/************************ Additional Queue operations ******************************/

//Prints the elements in the stack to stdout
void Stack::print()
{
	//One queue is always gonna be empty and the other queue will always be in stack order
	//You want to print the queue that isn't empty

	if (q2.isEmpty())
		q1.printQueue();
	else
		q2.printQueue();

}
