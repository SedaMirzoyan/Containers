#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

template <typename T>
struct Node {
	Node* next;
	Node* prev;
	T val;

	Node()
	{
		std::cout << __func__ << std::endl;
		this->next = nullptr;
		this->prev = nullptr;
		this->val = 0;
	}

	Node(T elem)
	{
		std::cout << __func__ << std::endl;
		this->next = nullptr;
		this->prev = nullptr;
		this->val = elem;
	}

	~Node()
	{
		std::cout << __func__ << std::endl;
	}
};


template <typename T>
class Double_Linked_List {
private:
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_length;

public:
	Double_Linked_List();
	Double_Linked_List(T elem);
	virtual ~Double_Linked_List();

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
	T getLastElem()const;
	T getFirstElem()const;
};

template <typename T>
Double_Linked_List<T>::Double_Linked_List()
{
	std::cout << __func__ << std::endl;
	m_head = nullptr;
	m_tail = nullptr;

	m_length = 0;
}

template <typename T>
Double_Linked_List<T>::Double_Linked_List(T elem)
{
	std::cout << __func__ << std::endl;
	m_head = new Node<T>(elem);
	m_tail = new Node<T>(elem);

	m_length = m_length++;
}

template <typename T>
Double_Linked_List<T>::~Double_Linked_List()
{
	std::cout << __func__ << std::endl;
}


template <typename T>
void Double_Linked_List<T>::setLength(int l)
{
	if (l < 0)
	{
		std::cout << "size can't be negative\n";
	}
	m_length = l;
}


template <typename T>
int Double_Linked_List<T>::getLength()const
{
	return m_length;
}


template <typename T>
Node<T>* Double_Linked_List<T>::createNode(T elem)
{
	Node<T>* new_node = new Node<T>;
	if (m_head == nullptr)
	{
		m_head = new_node;
		m_head->next = new_node;
		m_head->prev = nullptr;
		m_head->val = elem;
		m_tail = m_head;
	}
	return new_node;
}


template <typename T>
void Double_Linked_List<T>::insertAtBeginning(T elem)
{
	Node<T>* new_node = createNode(elem);

	m_head->prev = new_node;
	new_node->next = m_head;
	new_node->prev = nullptr;
	new_node->val = elem;
	m_head = new_node;
	m_length++;
}

template <typename T>
void Double_Linked_List<T>::insertAtEnd(T elem)
{
	Node<T>* new_node = createNode(elem);

	m_tail->next = new_node;
	new_node->prev = m_tail;
	new_node->next = nullptr;
	new_node->val = elem;
	m_tail = new_node;
	m_length++;
}


template <typename T>
void Double_Linked_List<T>::insertAtIndex(T elem, int index)
{
	Node<T>* new_node = createNode(elem);

	int prev_index = index - 1;
	Node<T>* prev_ptr = m_head;

	for (int i = 0; i < prev_index; i++)
	{
		prev_ptr = prev_ptr->next;
	}

	new_node->next = prev_ptr->next;
	prev_ptr->next = new_node;
	new_node->prev = prev_ptr;
	new_node->val = elem;
	m_length++;
}


template <typename T>
void Double_Linked_List<T>::removeFromBeginning()
{
	if (m_length == 0)
	{
		std::cout << "Nothing to delete, list is empty\n";
	}
	Node<T>* tmp = m_head;

	m_head = m_head->next;
	m_head->prev = nullptr;
	tmp->next = nullptr;
	tmp = nullptr;
	m_length--;
}

template <typename T>
void Double_Linked_List<T>::removeAtIndex(int index)
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
	Node<T>* prev_ptr = m_head;
	for (int i = 0; i < prev_index; i++)
	{
		prev_ptr = prev_ptr->next;
	}

	prev_ptr->next = tmp->next;
	tmp->next = nullptr;
	tmp->prev = nullptr;
	m_length--;
}



template <typename T>
void Double_Linked_List<T>::removeFromEnd()
{
	if (m_length == 0)
	{
		std::cout << "Nothing to delete, list is empty\n";
	}
	Node<T>* tmp = m_head;
	Node<T>* prev_ptr = m_head;

	for (int i = 0; i < m_length - 1; i++)
	{
		prev_ptr = tmp;
		tmp = tmp->next;
	}

	m_tail->prev = prev_ptr;
	m_tail = prev_ptr;
	m_tail->next = nullptr;
	tmp->next = nullptr;
	tmp->prev = nullptr;
	prev_ptr->next = nullptr;
	prev_ptr->prev = nullptr;
	m_length--;
}



template <typename T>
void Double_Linked_List<T>::print()
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
T Double_Linked_List<T>::getLastElem()const
{
	return m_tail->val;
}


template <typename T>
T Double_Linked_List<T>::getFirstElem()const
{
	return m_head->val;
}

#endif //DOUBLE_LINKED_LIST_H



