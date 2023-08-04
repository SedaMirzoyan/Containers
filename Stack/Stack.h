#ifndef STACK_CLASS_H
#define STACK_CLASS_H

#include "Array.h"

template<typename T>
class Stack : private Array<T>
{
private:
    int m_stack_size;
    int m_stack_capacity;
    T* m_stack_ptr = nullptr;

public:
    Stack();
    Stack(int stack_size);
    ~Stack();
    Stack(const Stack& ob);
    Stack(Stack&& ob);
    Stack& operator=(const Stack& ob);
    Stack& operator =(Stack&& ob);

    T pop();
    void push(const T& elem);
    T top()const;
       
    T* genElementsStack();
    T getElementStack(int index);
    void printStack();
    int getSizeStack()const;
    void setSizeStack(int s);
    int getCapacityStack()const;
    bool isEmptyStack();
    bool isFullStack();
    void eraseStack(int index);
    void clearStack();
    int reserveStack();
   
};


template <class T>
Stack<T>::Stack<T>() :Array<T>(), m_stack_size(0), m_stack_capacity(0)
{
    std::cout << "Default " << __func__ << std::endl;

}

template <class T>
Stack<T>::Stack<T>(int stack_size) :Array<T>(stack_size), m_stack_size(stack_size), m_stack_capacity(stack_size)
{
    std::cout << "Parametrized " << __func__ << std::endl;
    m_stack_ptr = new T[m_stack_size];
}


template <class T>
Stack<T>::~Stack<T>()
{
    std::cout << __func__ << std::endl;
    delete[]m_stack_ptr;
}


template <typename T>
Stack<T>::Stack<T>(const Stack& ob) :m_stack_size(ob.m_stack_size), m_stack_capacity(ob.m_stack_capacity)
{
    std::cout << "Copy " << __func__ << "\n";

    this->m_stack_ptr = new T[m_stack_size];

    for (int i = 0; i < m_stack_size; i++)
    {
        this->m_stack_ptr[i] = ob.m_stack_ptr[i];
    }
}


template <typename T>
Stack<T>::Stack<T>(Stack&& ob) :m_stack_size(ob.m_stack_size), m_stack_capacity(ob.m_stack_capacity)
{
    std::cout << "Move " << __func__ << "\n";

    if (this != &ob)
    {
        this->m_stack_ptr = ob.m_stack_ptr;

        ob.m_stack_ptr = nullptr;
        ob.m_stack_size = 0;
        ob.m_stack_capacity = 0;
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& ob)
{
    std::cout << __func__ << "\n";

    if (this != &ob)
    {
        std::cout << __func__ << "\n";
        this->m_stack_size = ob.m_stack_size;
        this->m_stack_capacity = ob.m_stack_capacity;
        delete[] m_stack_ptr;

        this->m_stack_ptr = new T[this->m_stack_size];

        for (int i = 0; i < m_stack_size; i++)
        {
            this->m_stack_ptr[i] = ob.m_stack_ptr[i];
        }
    }
    return *this;
}


template <typename T>
Stack<T>& Stack<T>::operator =(Stack&& ob)
{
    std::cout << "Move " << __func__ << "\n";

    if (this != &ob)
    {
        delete this->m_stack_ptr;
        this->m_stack_size = ob.m_stack_size;
        this->m_stack_capacity = ob.m_stack_capacity;

        this->m_stack_ptr = ob.m_stack_ptr;

        ob.m_stack_ptr = nullptr;
        ob.m_stack_size = 0;
        ob.m_stack_capacity = 0;
    }
    return *this;
}


template <typename T>
T* Stack<T>::genElementsStack()
{
    return Array<T>::genElements();
}


template <typename T>
T Stack<T>::getElementStack(int index)
{
    return Array<T>::getElement();
}

template <typename T>
void Stack<T>::printStack()
{
    Array<T>::printArray();
}


template <typename T>
int Stack<T>::getSizeStack()const
{
    return Array<T>::getSize();
}


template <typename T>
void Stack<T>::setSizeStack(int s)
{
    Array<T>::setSize();
}

template <typename T>
bool Stack<T>::isEmptyStack()
{
    return Array<T>::isEmpty();
}

template <typename T>
bool Stack<T>::isFullStack()
{
    return Array<T>::isFull();
}


template <typename T>
void Stack<T>::push(const T& elem)
{
    Array<T>::pushBack(elem);
}


template <typename T>
T Stack<T>::pop()
{
    return Array<T>::popBack();
}


template <typename T>
int Stack<T>::reserveStack()
{
    return Array<T>::reserve();
}


template <typename T>
int Stack<T>::getCapacityStack()const
{
    return Array<T>::getCapacity();
}


template <typename T>
void Stack<T>::eraseStack(int index)
{
    Array<T>::erase();
}

template <typename T>
void Stack<T>::clearStack()
{
    Array<T>::clear();
}


template <typename T>
T Stack<T>::top()const
{
    return Array<T>::getBackElement();
}


#endif //STACK_CLASS_H