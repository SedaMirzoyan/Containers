#ifndef DEQUE_H
#define DEQUE_H

#include "Double_Linked_list.h"

template<typename T>
class Deque : private Double_Linked_List<T>
{
private:
    Node<T>* m_deque_head;
    Node<T>* m_deque_tail;
    int m_deque_length;

public:
    Deque();
    Deque(const T& elem);
    ~Deque();

public:

    void enqueueAtBeginning(const T& elem);
    void enqueueAtEnd(const T& elem);
    void dequeueAtBeginning();
    void dequeueAtEnd();
    Node<T>* createElementsDeque(const T& elem);
    void printDeque();
    int getDequeLength()const;
    void setDequeLength(int l);
    T getFrontElem()const;
    T getBackElem()const;
};


template <class T>
Deque<T>::Deque<T>() :Double_Linked_List<T>(), m_deque_length(0)
{
    std::cout << "Default " << __func__ << std::endl;
    m_deque_head = nullptr;
    m_deque_tail = nullptr;
}

template <class T>
Deque<T>::Deque<T>(const T& elem)
{
    std::cout << "Parametrized " << __func__ << std::endl;

    m_deque_head = new Node<T>(elem);
    m_deque_tail = new Node<T>(elem);

    m_deque_length = m_deque_length++;
}


template <class T>
Deque<T>::~Deque<T>()
{
    std::cout << __func__ << std::endl;
}


template <typename T>
void Deque<T>::enqueueAtEnd(const T& elem)
{
    Double_Linked_List<T>::insertAtEnd(elem);
}


template <typename T>
void Deque<T>::dequeueAtEnd()
{
    return Double_Linked_List<T>::removeFromEnd();
}


template <typename T>
void Deque<T>::enqueueAtBeginning(const T& elem)
{
    Double_Linked_List<T>::insertAtBeginning(elem);
}


template <typename T>
void Deque<T>::dequeueAtBeginning()
{
    return Double_Linked_List<T>::removeFromBeginning();
}


template <typename T>
Node<T>* Deque<T>::createElementsDeque(const T& elem)
{
    return Double_Linked_List<T>::createNode(elem);
}



template <typename T>
void Deque<T>::setDequeLength(int l)
{
    Double_Linked_List<T>::setLength();
}


template <typename T>
int Deque<T>::getDequeLength()const
{
    return Double_Linked_List<T>::getLength();
}


template <typename T>
T Deque<T>::getFrontElem()const
{
    return Double_Linked_List<T>::getLastElem();
}


template <typename T>
T Deque<T>::getBackElem()const
{
    return Double_Linked_List<T>::getLastElem();
}


template <typename T>
void Deque<T>::printDeque()
{
    Double_Linked_List<T>::print();
}

#endif //DEQUE_CLASS_H