//============================================================================
// Name        : StackTest.cpp
// Author      : Khadeja Khalid and Tiffany Tran
// Version     : CIS 22C Lab 5
//============================================================================

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main()
{

	Stack s;

	cout << "\nCurrent stack should be empty: ";
	s.print();
	cout << endl;

	cout << "Add an element to the top: \n";
	cout << "=============================== \n\n";

	cout << "Should print lol: ";
	s.push("lol");
	s.print();
	cout << endl;

	cout << "Current size should be 1: ";
	cout << s.getSize() << endl;
	cout << endl;

	cout << "Should print haha lol: ";
	s.push("haha");
	s.print();
	cout << endl;

	cout << "Should print nice haha lol: ";
	s.push("nice");
	s.print();
	cout << endl;

	cout << "Should print ok nice haha lol: ";
	s.push("ok");
	s.print();
	cout << endl;

	cout << "=============================== \n\n";

	cout << "The top element should be ok: ";
	cout << s.getTop() << endl;
	cout << endl;

	cout << "Current size should be 4: ";
	cout << s.getSize() << endl;
	cout << endl;

	cout << "Stack should not be empty: ";
	if (s.isEmpty())
	{
		cout << "Stack is empty!\n";
	}
	else
	{
		cout << "Stack is not empty!\n";
	}

	cout << endl;

	cout << "Remove top of stack: \n";
	cout << "=============================== \n\n";

	cout << "Should print nice haha lol: ";
	s.pop();
	s.print();
	cout << endl;

	cout << "Current size should be 3: ";
	cout << s.getSize() << endl;
	cout << endl;

	cout << "The top element should be nice: ";
	cout << s.getTop() << endl;
	cout << endl;

	cout << "Stack should not be empty: ";
	if (s.isEmpty())
	{
		cout << "Stack is empty!\n";
	}
	else
	{
		cout << "Stack is not empty!\n";
	}

	cout << endl;

	cout << "Remove top of stack: \n";
	cout << "=============================== \n\n";

	cout << "Should print haha lol: ";
	s.pop();
	s.print();
	cout << endl;

	cout << "Current size should be 2: ";
	cout << s.getSize() << endl;
	cout << endl;

	cout << "The top element should be haha: ";
	cout << s.getTop() << endl;
	cout << endl;


	cout << "Stack should not be empty: ";
	if (s.isEmpty())
	{
		cout << "Stack is empty!\n";
	}
	else
	{
		cout << "Stack is not empty!\n";
	}

	cout << endl << endl;


	cout << "Clear stack: \n";
	cout << "=============================== \n\n";
	//Empty the stack
	s.pop();
	s.pop();

	cout << "Stack should be empty: ";
	if (s.isEmpty())
	{
		cout << "Stack is empty!\n";
	}
	else
	{
		cout << "Stack is not empty!\n";
	}

	cout << "Current size should be 0: ";
	cout << s.getSize() << endl;
	cout << endl;

	//cout << s.getTop() << endl; //Testing assert

	//s.pop(); //Testing assert


	return 0;
}

/*

Current stack should be empty:

Add an element to the top:
===============================

Should print lol: lol

Current size should be 1: 1

Should print haha lol: haha lol

Should print nice haha lol: nice haha lol

Should print ok nice haha lol: ok nice haha lol

===============================

The top element should be ok: ok

Current size should be 4: 4

Stack should not be empty: Stack is not empty!

Remove top of stack:
===============================

Should print nice haha lol: nice haha lol

Current size should be 3: 3

The top element should be nice: nice

Stack should not be empty: Stack is not empty!

Remove top of stack:
===============================

Should print haha lol: haha lol

Current size should be 2: 2

The top element should be haha: haha

Stack should not be empty: Stack is not empty!


Clear stack:
===============================

Stack should be empty: Stack is empty!
Current size should be 0: 0


*/
