#ifndef STACK_H
#define STACK_H

#include "List.h"

template<typename T>
class Stack : private List<T>
{
private:
    Node<T>* m_stack_head;
    Node<T>* m_stack_tail;
    int m_stack_length;

public:
    Stack();
    Stack(const T& elem);
    ~Stack();

public:

    void push(const T& elem);
    T top()const;
    void pop();
    Node<T>* createElements(const T& elem);
    void printStack();
    int getStackLength()const;
    void setStackLength(int l);
};


template <class T>
Stack<T>::Stack<T>() :List<T>(), m_stack_length(0)
{
    std::cout << "Default " << __func__ << std::endl;
    m_stack_head = nullptr;
    m_stack_tail = nullptr;
}

template <class T>
Stack<T>::Stack<T>(const T& elem)
{
    std::cout << "Parametrized " << __func__ << std::endl;

    m_stack_head = new Node<T>(elem);
    m_stack_tail = new Node<T>(elem);

    m_stack_length = m_stack_length++;
}


template <class T>
Stack<T>::~Stack<T>()
{
    std::cout << __func__ << std::endl;
}



template <typename T>
void Stack<T>::push(const T& elem)
{
    List<T>::insertAtEnd(elem);
}


template <typename T>
void Stack<T>::pop()
{
    return List<T>::removeFromEnd();
}


template <typename T>
Node<T>* Stack<T>::createElements(const T& elem)
{
    return List<T>::createNode(elem);
}



template <typename T>
void Stack<T>::setStackLength(int l)
{
    List::setLength();
}


template <typename T>
int Stack<T>::getStackLength()const
{
    return List<T>::getLength();
}


template <typename T>
T Stack<T>::top()const
{
    return List<T>::getLastElem();
}


template <typename T>
void Stack<T>::printStack()
{
    List<T>::print();
}

#endif //STACK_CLASS_H