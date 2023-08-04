#include <iostream>
#include "List.h"
#include "Stack.h"

//based on singly linked list

int main()
{
	Stack<int> stack_ob;

	stack_ob.push(7);
	stack_ob.push(8);
	stack_ob.push(9);
	stack_ob.push(3);
	stack_ob.printStack();
	std::cout << stack_ob.getStackLength() << std::endl;

	std::cout << "top " << stack_ob.top() <<std::endl;

	stack_ob.pop();
	stack_ob.printStack();
	std::cout << stack_ob.getStackLength() << std::endl;

	stack_ob.pop();
	stack_ob.printStack();
	std::cout << stack_ob.getStackLength() << std::endl;

	stack_ob.push(342);
	std::cout << stack_ob.getStackLength() << std::endl;
	stack_ob.printStack();

	stack_ob.pop();
	std::cout << stack_ob.getStackLength() << std::endl;
	stack_ob.printStack();

	std::cout << stack_ob.top() << std::endl;

	return 0;
}
