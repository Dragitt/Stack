#ifndef _Stack_h_
#define _Stack_h_

#include <iostream>
#include <string>
#include <cstdlib>

const int MAX_S = 100;

template <typename T>
class Stack
{
private:

	T *top = new T[MAX_S];
	T* bot = top;

public:

	bool stackEmpty();

	void push(T x);

	T pop();

	T topVal();

	void stackPrint();

	void stackReverse();



};

#endif