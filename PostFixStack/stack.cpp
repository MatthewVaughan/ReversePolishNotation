#include "stack.h"


void myStack::push(const char& entry)
{
	data[used] = entry;
	++used;
}

void myStack::pop()
{
	if (used != 0)
	{
		--used;
	}
	data[used] = 0;
}

char myStack::top() const
{
	return data[used - 1];
}

bool myStack::empty() const
{
	if (used == 0)
		return true;
	else
		return false;
}
