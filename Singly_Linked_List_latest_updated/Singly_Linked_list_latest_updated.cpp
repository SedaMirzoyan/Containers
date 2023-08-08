
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

public:
	List();
	List(T elem);
	~List();

	Node<T>* createNode(const T& elem);
	void insertAtBeginning(const T& elem);
	void insertAtIndex(const T& elem, int index);
	void insertAtEnd(const T& elem);
	void print();
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
}

template <typename T>
List<T>::List(T elem)
{
	std::cout << __func__ << std::endl;
	m_head = new Node<T>(elem);
}

template <typename T>
List<T>::~List()
{
	std::cout << __func__ << std::endl;
}


template <typename T>
Node<T>* List<T>::createNode(const T& elem)
{
	Node<T>* new_node = new Node<T>;
	if (m_head == nullptr)
	{
		m_head = new_node;
		m_head->next = new_node;
		m_head->val = elem;
	}
	return new_node;
}


template <typename T>
void List<T>::insertAtBeginning(const T& elem)
{
	Node<T>* new_node = createNode(elem);

	new_node->next = m_head;
	new_node->val = elem;
	m_head = new_node;
}



template <typename T>
void List<T>::insertAtEnd(const T& elem)
{
	Node<T>* newNode = new Node<T>;
	newNode->val = elem;
	newNode->next = NULL;

	Node<T>* temp = m_head;
	if (m_head == NULL)
	{
		m_head = newNode;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}


template <typename T>
void List<T>::insertAtIndex(const T& elem, int index)
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
	new_node->val = elem;
}


template <typename T>
void List<T>::removeFromBeginning()
{
	if (m_head == nullptr)
	{
		std::cout << "Nothing to delete, list is empty\n";
	}
	Node<T>* tmp = m_head;

	m_head = m_head->next;
	tmp->next = nullptr;
	tmp = nullptr;
}

template <typename T>
void List<T>::removeAtIndex(int index)
{
	if (m_head == nullptr)
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
	for (int i = 0; i < prev_index; i++)
	{
		prev = prev->next;
	}

	prev->next = tmp->next;
	tmp->next = nullptr;
}


template <typename T>
void List<T>::removeFromEnd()
{
	Node<T>* tmp = m_head;
	Node<T>* prev = m_head;

	if (m_head == nullptr)
	{
		std::cout << "Nothing to delete, list is empty\n";
		return;
	}

	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	prev->next = NULL;
	tmp->next = NULL;
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

	l1.insertAtEnd(-76);
	l1.insertAtBeginning(-2);
	l1.print();

	l1.insertAtIndex(51, 4);
	l1.print();

	//List<int> l_ob(l1);

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

	return 0;
}
