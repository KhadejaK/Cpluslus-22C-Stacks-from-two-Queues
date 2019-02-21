//============================================================================
// Name        : Queue.h
// Author      : Khadeja Khalid and Tiffany Tran
// Version     : CIS 22C Lab 5
//============================================================================


#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <cstddef>
#include <assert.h>

using namespace std;

template<class queuedata>
class Queue
{
public:
    /**constructors and destructors*/

    Queue();
    //initializes an empty queue
    //post: an empty queue created with default values for all fields

    Queue(const Queue &Q);
    //initializes queue to have same elements as another queue
    //post: a deep copy of queue

    ~Queue();
    //frees memory allocated to the queue
    //post: memory for queue has been freed

    /**manipulation procedures*/

    void dequeue();
    //removes an element from the front of the queue
    //pre: size!=0
    //post: an element removed from the front of the queue

    void enqueue(queuedata data);
    //adds an element to the end of the queue
    //post: an element added to the end of the queue

    /**accessors*/

    bool operator==(const Queue &Q);
    //returns whether this queue is equal to another queue

    queuedata getFront() const;
    //returns the element at the front of the queue
    //pre: size != 0

    int getSize() const;
    //returns the size of the queue

    bool isEmpty() const;
    //returns whether the queue is empty

    /**additional queue operations*/
    void printQueue() const;
    //prints the elements in the queue separated by a blank space to stdout

private:
    struct Node {

        queuedata data;
        Node* next;
        Node(queuedata d) {
            next = NULL;
            data = d;

        }
    };

    Node* front;
    Node* end;
    int size;

};


template<class queuedata>
Queue<queuedata>::Queue()
{
//initializes an empty queue
//post: an empty queue created with default values for all fields
	front = end = NULL;
	size = 0;

}

template<class queuedata>
Queue<queuedata>::Queue(const Queue &Q)
{
    //initializes queue to have same elements as another queue
    //post: a deep copy of queue

	if(Q.isEmpty()) //If queue is empty, make an empty list
		front = end = NULL;
	else
	{
		front =  new Node(Q.front->data); //Allocating space for a new node and passing data
		Node* temp = Q.front; //Make a temp node and point at front
		Node* iterator = front; //Using an iterator node to go through list

		while(temp->next != NULL) //Check if temp's next is not NULL
		{
			temp = temp->next;  //Move temp to the next in the queue
			iterator->next = new Node(temp->data); //Constructing a new node with a copy of data
			iterator = iterator->next; //Moving through the queue
		}

		end = iterator; //Once orig. queue is copied, set the endptr to the correct node
		iterator = NULL; //Set it to NULL so no longer dangling
	}

	size = Q.size;
}

template<class queuedata>
Queue<queuedata>::~Queue()
{
    //frees memory allocated to the queue
    //post: memory for queue has been freed

	Node* b = front; //Goes through the list, "before"
	Node* a; //Pointing at new node, "after"

	while (b != NULL)
	{
		a = b->next; //a = address of node after b
		delete b; //Removing b
		b = a; //Catching b up with a
	}
}


    /** manipulation procedures */

template<class queuedata>
void Queue<queuedata>::dequeue()
{
    //removes an element from the front of the queue
    //pre: size!=0
    //post: an element removed from the front of the queue

	assert (!isEmpty());	//pre: size!=0

	if(size == 1)
	{
		delete front;
		front = end = NULL;
	}
	else
	{
		Node* temp = front; //Setting temp as first
		front = front->next; //Moving front over to next in queue
		delete temp; //removing temp
	}
	size--;
}

template<class queuedata>
void Queue<queuedata>::enqueue(queuedata data)
{
    //adds an element to the end of the queue
    //post: an element added to the end of the queue

	Node* N = new Node(data);
	if(isEmpty())
		front = end = N;
	else
	{
		end->next = N;
		end = N;
	}
	size++;
}


    /**accessors*/

template<class queuedata>
bool Queue<queuedata>::operator==(const Queue &Q){
    //returns whether this queue is equal to another queue
	if(size != Q.size) //If the size is not the same as our parameter
		return false;

	Node* temp1 = front; //A ptr to front
	Node* temp2 = Q.front; //A ptr to paramater's front
	while(temp1 != NULL) //If not at end of list
	{
		if(temp1->data != temp2->data) //If prt's are not same, return false
			return false;
		temp1 = temp1->next; //Move to next temp1 value
		temp2 = temp2->next; //Move to next temp2 value
	}
	return true;
}

template<class queuedata>
queuedata Queue<queuedata>::getFront() const
{
    //returns the element at the front of the queue
    //pre: size != 0
	assert (!isEmpty());				//pre: size != 0
	return front->data;
}

template<class queuedata>
int Queue<queuedata>::getSize() const
{ //returns the size of the queue
	return size;
}

template<class queuedata>
bool Queue<queuedata>::isEmpty() const
{
    //returns whether the queue is empty
	return (size == 0);
}


    /** additional queue operations */

template<class queuedata>
void Queue<queuedata>::printQueue() const
{
    //prints the elements in the queue separated by a blank space to stdout
	Node* temp = front;
	while(temp != NULL)
	{
		cout << temp->data << " "; //Printing data followed by a space
		temp = temp->next; //Moving temp to next value
	}

	cout << endl; //Printing a new line
}


#endif /* QUEUE_H_ */
