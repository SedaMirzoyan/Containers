
#include <iostream>
#include <stack>

template <typename T>
struct Node {
	Node* next;
	T val;

	Node()
	{
		std::cout << __func__ << std::endl;
		this->next = nullptr;
		this->val = 0;
	}

	Node(T elem)
	{
		std::cout << __func__ << std::endl;
		this->next = nullptr;
		this->val = elem;
	}

	~Node()
	{
		std::cout << __func__ << std::endl;
	}
};


template <typename T>
class List {
private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_length;

public:
	List();
	List(T elem);
	~List();

	Node<T>* createNode(T elem);
	void insertAtBeginning(T elem);
	void insertAtIndex(T elem, int index);
	void insertAtEnd(T elem);
	void print();
	int getLength()const;
	void setLength(int l);
	void removeFromEnd();
	void removeFromBeginning();
	void removeAtIndex(int index);
	void reverse();
};

template <typename T>
List<T>::List()
{
	std::cout << __func__ << std::endl;
	m_head = nullptr;
	m_tail = nullptr;
	
	m_length = 0;
}

template <typename T>
List<T>::List(T elem)
{
	std::cout << __func__ << std::endl;
	m_head = new Node<T>(elem);
	m_tail = new Node<T>(elem);

	m_length = m_length++;
}

template <typename T>
List<T>::~List()
{
	std::cout << __func__ << std::endl;
}


template <typename T>
void List<T>::setLength(int l)
{
	if (l < 0)
	{
		std::cout << "size can't be negative\n";
	}	
	m_length = l;
}


template <typename T>
int List<T>::getLength()const
{
	return m_length;
}


template <typename T>
Node<T>* List<T>::createNode(T elem)
{
	Node<T>* new_node = new Node<T>;
	if (m_head == nullptr)
	{
		m_head = new_node;
		m_head->next = new_node;
		m_head->val = elem;
		m_tail = m_head;
	}
	return new_node;
}


template <typename T>
void List<T>::insertAtBeginning(T elem)
{
	Node<T>* new_node = createNode(elem);

	new_node->next = m_head;
	new_node->val = elem;
	m_head = new_node;
	m_length++; 
}

template <typename T>
void List<T>::insertAtEnd(T elem)
{
	Node<T>* new_node = createNode(elem);

	m_tail->next = new_node;
	m_tail = new_node;
	m_tail->next = nullptr;
	new_node->val = elem;
	m_length++;
}


template <typename T>
void List<T>::insertAtIndex(T elem, int index)
{
	Node<T>* new_node = createNode(elem);

	int prev_index = index - 1;
	Node<T>* prev = m_head;

	for (int i = 0; i < prev_index; i++)
	{
		prev = prev->next;
	}

	new_node->next = prev->next;
	prev->next = new_node;
	new_node-> val = elem;
	m_length++;
}


template <typename T>
void List<T>::removeFromBeginning()
{
	if (m_length == 0)
	{
		std::cout << "Nothing to delete, list is empty\n";
	}
	Node<T>* tmp = m_head;
	
	m_head = m_head->next;
	tmp->next = nullptr;
	tmp = nullptr;
	m_length--;
}

template <typename T>
void List<T>::removeAtIndex(int index)
{
	if (m_length == 0)
	{
		std::cout << "Nothing to delete, list is empty\n";
	}

	Node<T>* tmp = m_head;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->next;
	}

	int prev_index = index - 1;
	Node<T>* prev = m_head;
	for (int i = 0; i < prev_index ; i++)
	{
		prev = prev->next;
	}

	prev->next = tmp->next;
	//m_tail = prev;
	//m_tail->next = prev->next;
	tmp->next = nullptr;
	m_length--;
}



template <typename T>		
void List<T>::removeFromEnd()
{
	if (m_length == 0)
	{
		std::cout << "Nothing to delete, list is empty\n";
	}
	Node<T>* tmp = m_head;
	Node<T>* prev = m_head;

	for (int i = 0; i < m_length -1 ; i++)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	m_tail = prev;
	m_tail->next = prev->next;
	tmp->next = nullptr;
	prev->next = nullptr;
	m_length--;
}



template <typename T>
void List<T>::print()
{
	Node<T>* tmp = m_head;
	while (tmp != nullptr)
	{
		std::cout << tmp->val << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}


template <typename T>
void List<T>::reverse() {

	std::stack<Node<T>*> st;
	Node<T>* tmp = m_head;

	while (tmp->next != nullptr)	
	{
		st.push(tmp);
		tmp = tmp->next;
	}

	m_head = tmp;

	while (!st.empty())
	{
		tmp->next = st.top();
		st.pop();
		tmp = tmp->next;
	}

	tmp->next = nullptr; 
}


int main()
{
	List<int> l1;
	
	l1.insertAtEnd(7);
	l1.insertAtEnd(8);
	l1.insertAtEnd(9);
	l1.insertAtEnd(3);
	l1.print();
	std::cout << l1.getLength() << std::endl;

	l1.insertAtBeginning(2);
	std::cout << l1.getLength() << std::endl;
	l1.print();

	l1.insertAtIndex(51, 4);
	l1.print();

	l1.removeFromBeginning();
	l1.print();
	std::cout << l1.getLength() << std::endl;

	l1.removeAtIndex(2);
	l1.print();
	std::cout << l1.getLength() << std::endl;

	l1.insertAtIndex(34, 2);
	std::cout << l1.getLength() << std::endl;
	l1.print();

	l1.removeFromEnd();
	std::cout << l1.getLength() << std::endl;
	l1.print();

	std::cout << "reverse" << std::endl;
	l1.reverse();
	l1.print();

	return 0;
}

