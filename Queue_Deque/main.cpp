#include <iostream>
#include "Double_Linked_list.h"
#include "Queue.h"
#include "Deque.h"

int main()
{
	//Deque
	std::cout << "Deque" << std::endl;
	Deque<int> dq_ob;

	dq_ob.enqueueAtEnd(12);
	dq_ob.enqueueAtEnd(98);
	dq_ob.enqueueAtEnd(99);
	dq_ob.enqueueAtEnd(101);
	dq_ob.printDeque();
	std::cout << dq_ob.getDequeLength() << std::endl;

	dq_ob.enqueueAtBeginning(8);
	std::cout << dq_ob.getDequeLength() << std::endl;
	dq_ob.printDeque();

	dq_ob.dequeueAtBeginning();
	dq_ob.printDeque();
	std::cout << dq_ob.getDequeLength() << std::endl;

	dq_ob.dequeueAtEnd();
	dq_ob.printDeque();
	std::cout << dq_ob.getDequeLength() << std::endl;

	dq_ob.dequeueAtBeginning();
	std::cout << dq_ob.getDequeLength() << std::endl;
	dq_ob.printDeque();


	//Queue
	std::cout << "Queue" << std::endl;
	Queue<int> q_ob;

	q_ob.enqueue(7);
	q_ob.enqueue(3);
	q_ob.enqueue(514);
	q_ob.printQueue();
	std::cout << q_ob.getQueueLength() << std::endl;


	q_ob.dequeue();
	q_ob.printQueue();
	std::cout << q_ob.getQueueLength() << std::endl;

	q_ob.enqueue(245);
	q_ob.printQueue();

	q_ob.dequeue();
	std::cout << q_ob.getQueueLength() << std::endl;
	q_ob.printQueue();

	return 0;
}