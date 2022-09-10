#include "Stack.h"
#include "Stack.cpp"

int main() {

	Stack<char> stack;
	Stack<int> pfStack;
	Stack<int> mapStack;

	std::string infix, postfix;

	std::cout << "Unesite izraz koji zelite da izracunate: " << std::endl;
	std::cin >> infix;

	int n = infix.length();
	int i = 0;
	char cTemp;

	while ( i != n) {

		switch (infix[i]) {

		default :
			postfix.push_back(infix[i]);
			pfStack.push(infix[i] - '0');
			mapStack.push(0);
			break;

		case '-':
		case '+':
			if (stack.stackEmpty()) stack.push(infix[i]);
			else {

				while (!stack.stackEmpty()) {

					if (stack.topVal() == '*' || stack.topVal() == '/' || stack.topVal() == '+' || stack.topVal() == '-') {
						cTemp = stack.pop();
						postfix.push_back(cTemp);
						pfStack.push(static_cast<int>(cTemp));
						mapStack.push(1);
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
						cTemp = stack.pop();
						postfix.push_back(cTemp);
						pfStack.push(static_cast<int>(cTemp));
						mapStack.push(1);
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
				cTemp = stack.pop();
				postfix.push_back(cTemp);
				pfStack.push(static_cast<int>(cTemp));
				mapStack.push(1);
			}
			stack.pop();
		}


		i++;
	}

	while (!stack.stackEmpty()) {
		cTemp = stack.pop();
		postfix.push_back(cTemp);
		pfStack.push(static_cast<int>(cTemp));
		mapStack.push(1);
	}

	std::cout << "Izgled ovog izraza u postfiksnom obliku je: " << std::endl << postfix << std::endl;

	pfStack.stackReverse();
	mapStack.stackReverse();
	//pfStack.stackPrint();
	
	Stack<int> stack1;

	while (!pfStack.stackEmpty()) {

		if (!mapStack.pop()) stack1.push(pfStack.pop());
		else {
			int op1 = stack1.pop();
			int op2 = stack1.pop();

			switch (static_cast<char>(pfStack.pop())) {

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




	/*for (i = 0; i < postfix.length(); i++) {
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
	}*/

	std::cout << "Rezultat ovog izraza je: " << std::endl << stack1.pop() << std::endl;
}