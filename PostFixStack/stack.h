// CS2420 Programming Project #03
// Copyright 2014, Utah Valley University
//Author: Matthew Vaughan
// Date last modified: Sept 2016
// Header file for main - constants and function prologues
// =================================================

/*I Matthew Vaughan have not used any code other than my own(or that in the textbook)
for this project.I also have not used any function or data - structure from
the Standard - Template Library.I understand that any violation of this
disclaimer will result in a 0 for the project.*/

#pragma once
#include <cstdlib>
using namespace std;

class myStack
{
public:
	typedef char value_type;
	static const int CAPACITY = 30;
	myStack() { used = 0; }
	void push(const char& entry);
	void pop();
	bool empty() const;
	int size() const { return used; }
	char top() const;
private:
	char data[CAPACITY];
	int used;
};

