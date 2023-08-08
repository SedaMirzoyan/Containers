#include <iostream>
#include "Vector.h"
#include "List.h"
#include "Bubble_sort.h"


int main()
{
    int n;
    std::cout << "Enter the number of elements\n";
    std::cin >> n;

    Vector<int> ob(n);
    ob.genElements();
    ob.printVector();
    ob.getElement(2);

    ob.pushBack(9);
    ob.popBack();
    ob.printVector();

	List<int> l1;
	l1.insertAtEnd(7);
	l1.insertAtEnd(8);
	l1.insertAtEnd(9);
	l1.insertAtEnd(3);
	l1.print();

	l1.insertAtEnd(-76);
	l1.insertAtBeginning(-2);
	l1.print();

	l1.insertAtIndex(51, 4);
	l1.print();

	l1.removeFromBeginning();
	l1.print();

	l1.removeAtIndex(2);
	l1.print();

	l1.insertAtIndex(34, 2);
	l1.print();

	l1.removeFromEnd();
	l1.print();

	std::cout << "reverse" << std::endl;
	l1.reverse();
	l1.print();

	std::cout << "Bubble sort for Vector\n";
    bubbleSortVec(ob, n);
	std::cout << "Bubble sort for List\n";
    //bubbleSortList(l1);

    return 0;
}
