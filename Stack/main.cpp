#include <iostream>
#include <string>
#include "Stack.h"
#include "Array.h"

int main()
{
    int n;
    std::cout << "Enter the number of elements\n";
    std::cin >> n;

    Array<int> ob(n);
    ob.genElements();
    ob.printArray();
    ob.getElement(2);

    ob[3];
    ob[2] = 45;
    std::cout << "After operator []\n";
    ob.printArray();

    std::cout << "At\n";
    ob.at(2);
    ob.at(1) = 8;
    ob.printArray();

    /*Array<int> ob_cp(ob);
    ob > ob_cp;

    Array<int> ob1;
    ob1 = ob_cp;

    Array<double> m_ob1(3);
    m_ob1 = std::move(Array<double>(5));

    Array<std::string> m_ob2 = std::move(Array<std::string>(2)); */

    ob.pushBack(9);
    ob.printArray();
    std::cout << "after pushBack (size is " << ob.getSize() << ")\n";
    ob.popBack();
    std::cout << "after popBack (size = " << ob.getSize() << ")\n";
    ob.printArray();

    Array<int> ob_empty;
    try
    {
        ob_empty.popBack();
    }
    catch (...)
    {
        std::cout << "Array is empty";
    }

    //Stack
    Stack<int> ob_stack(4);
    ob_stack.genElementsStack();
    std::cout << "size of the stack is " << ob_stack.getSizeStack() << std::endl;
    
    ob_stack.push(9);
    ob_stack.push(2);
    ob_stack.push(-3);
    ob_stack.printStack();
    std::cout << std::endl;
    ob_stack.pop();
    ob_stack.printStack();
    std::cout << "last element of the stack is " << ob_stack.top() << std::endl;

    Stack<int> ob_cp1(ob_stack);

    Stack<double> m_ob_stack(3);
    m_ob_stack = std::move(Stack<double>(5));

    Stack<std::string> m_ob2 = std::move(Stack<std::string>(2));

    return 0;
}