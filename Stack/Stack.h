#ifndef _Stack_h_
#define _Stack_h_

#include <iostream>
#include <string>
#include <cstdlib>

const int MAX_S = 100;

class Stack
{
private:

	char *top = new char[MAX_S];
	char* bot = top;

public:

	bool stackEmpty();

	void push(char x);

	char pop();

	char topVal();

	void stackPrint();



};

#endif