#include "Stack.h"
#include "Stack.cpp"

int main() {

	Stack<char> stack;
	Stack<int> pfStack;

	std::string infix, postfix;

	std::cout << "Unesite izraz koji zelite da izracunate: " << std::endl;
	std::cin >> infix;

	int n = infix.length();
	int i = 0;
	char cTemp;

	while ( i != n) {

		switch (infix[i]) {

		default :
			//std::cout << infix[i];
			postfix.push_back(infix[i]);
			pfStack.push(infix[i] - '0');
			break;

		case '-':
		case '+':
			if (stack.stackEmpty()) stack.push(infix[i]);
			else {

				while (!stack.stackEmpty()) {

					if (stack.topVal() == '*' || stack.topVal() == '/' || stack.topVal() == '+' || stack.topVal() == '-') {
						//std::cout << stack.pop();
						cTemp = stack.pop();
						postfix.push_back(cTemp);
						pfStack.push(static_cast<int>(cTemp));
					}
					else break;
				}

				stack.push(infix[i]);
				
			}
			break;

		case '*':
		case '/':

			if (stack.stackEmpty()) stack.push(infix[i]);
			else {

				while (!stack.stackEmpty()) {

					if (stack.topVal() == '*' || stack.topVal() == '/') {
						//std::cout << stack.pop();
						cTemp = stack.pop();
						postfix.push_back(cTemp);
						pfStack.push(static_cast<int>(cTemp));
					}
					else {
						stack.push(infix[i]);
						break;
					}
				}

			}
			break;

		case '(':
			stack.push(infix[i]);
			break;
		case ')' :
			while (stack.topVal() != '(') {
				//std::cout << stack.pop();
				cTemp = stack.pop();
				postfix.push_back(cTemp);
				pfStack.push(static_cast<int>(cTemp));
			}
			stack.pop();
		}


		i++;
	}

	while (!stack.stackEmpty()) {
		//std::cout << stack.pop();
		cTemp = stack.pop();
		postfix.push_back(cTemp);
		pfStack.push(static_cast<int>(cTemp));
	}

	std::cout << "Izgled ovog izraza u postfiksnom obliku je: " << std::endl << postfix << std::endl;

	pfStack.stackReverse();
	pfStack.stackPrint();
	
	Stack<int> stack1;

	for (i = 0; i < postfix.length(); i++) {
		if (isdigit(postfix[i])) stack1.push(postfix[i] - '0');
		else {
			int op1 = stack1.pop();
			int op2 = stack1.pop();

			switch (postfix[i]) {
			case '+':
				stack1.push(op1 + op2);
				break;
			case '-':
				stack1.push(op2 - op1);
				break;
			case '*':
				stack1.push(op1 * op2);
				break;
			case '/':
				stack1.push(op2 / op1);
				break;

			}
		}
	}


	/*
	
	Stack<char> stack1;

	for (i = 0; i < postfix.length(); i++) {
		if (isdigit(postfix[i])) stack1.push(postfix[i]);
		else {
			int op1 = stack1.pop() - '0';
			int op2 = stack1.pop() - '0';
			int temp1;
			char c;

			switch (postfix[i]) {
			case '+':
				temp1 = op1 + op2;
				c = static_cast<char>(temp1) + 48;
				stack1.push(c);
				break;
			case '-':
				temp1 = op2 - op1;
				c = static_cast<char>(temp1) + 48;
				stack1.push(c);
				break;
			case '*':
				temp1 = op1 * op2;
				c = static_cast<char>(temp1) + 48;
				stack1.push(c);
				break;
			case '/':
				temp1 = op2 / op1;
				c = static_cast<char>(temp1) + 48;
				stack1.push(c);
				break;

			}
		}
	}
	*/

	std::cout << "Rezultat ovog izraza je: " << std::endl << stack1.pop() << std::endl;
}