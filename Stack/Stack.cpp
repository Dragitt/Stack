#include "Stack.h"


bool Stack::stackEmpty() {
	if (top == bot) return 1;
	else return 0;
}

void Stack::push(char x) {
		top++;
		*top = x;
}

char Stack::pop() {
	char temp;
	temp = *top;
	top--;

	return temp;
}

char Stack::topVal() {
	return *top;
}

void Stack::stackPrint() {
	char* temp = top;

	while (temp != bot) {
		std::cout << *temp << std::endl;
		temp--;
	}

	std::cout << std::endl;

}
