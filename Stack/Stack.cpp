#include "Stack.h"

template<typename T>
bool Stack<T>::stackEmpty() {
	if (top == bot) return 1;
	else return 0;
}

template<typename T>
void Stack<T>::push(T x) {
		top++;
		*top = x;
}

template<typename T>
T Stack<T>::pop() {
	T temp;
	temp = *top;
	top--;

	return temp;
}

template<typename T>
T Stack<T>::topVal() {
	return *top;
}

template<typename T>
void Stack<T>::stackPrint() {
	T* temp = top;

	std::cout << "---STACK---" << std::endl;

	while (temp != bot) {
		std::cout << *temp << std::endl << "----------" << std::endl;
		temp--;
	}

	std::cout << std::endl;

}

template<typename T>
void Stack<T>::stackReverse() {
	T* p1 = bot + 1, * p2 = top;
	T temp;

	while (p1 != p2) {
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;

		p1++;
		p2--;
	}
}