#ifndef QUEUE_H
#define QUEUE_H

#include "Double_Linked_list.h"

template<typename T>
class Queue : private Double_Linked_List<T>
{
private:
    Node<T>* m_queue_head;
    Node<T>* m_queue_tail;
    int m_queue_length;

public:
    Queue();
    Queue(const T& elem);
    ~Queue();

public:

    void enqueue(const T& elem);
    T getFrontElem()const;
    T getBackElem()const;
    void dequeue();
    Node<T>* createElementsQueue(const T& elem);
    void printQueue();
    int getQueueLength()const;
    void setQueueLength(int l);
};


template <class T>
Queue<T>::Queue<T>() :Double_Linked_List<T>(), m_queue_length(0)
{
    std::cout << "Default " << __func__ << std::endl;
    m_queue_head = nullptr;
    m_queue_tail = nullptr;
}

template <class T>
Queue<T>::Queue<T>(const T& elem)
{
    std::cout << "Parametrized " << __func__ << std::endl;

    m_queue_head = new Node<T>(elem);
    m_queue_tail = new Node<T>(elem);

    m_queue_length = m_queue_length++;
}


template <class T>
Queue<T>::~Queue<T>()
{
    std::cout << __func__ << std::endl;
}


template <typename T>
void Queue<T>::enqueue(const T& elem)
{
    Double_Linked_List<T>::insertAtEnd(elem);
}


template <typename T>
void Queue<T>::dequeue()
{
    return Double_Linked_List<T>::removeFromBeginning();
}


template <typename T>
Node<T>* Queue<T>::createElementsQueue(const T& elem)
{
    return Double_Linked_List<T>::createNode(elem);
}



template <typename T>
void Queue<T>::setQueueLength(int l)
{
    Double_Linked_List<T>::setLength();
}


template <typename T>
int Queue<T>::getQueueLength()const
{
    return Double_Linked_List<T>::getLength();
}


template <typename T>
T Queue<T>::getFrontElem()const
{
    return Double_Linked_List<T>::getFirstElem();
}


template <typename T>
T Queue<T>::getBackElem()const
{
    return Double_Linked_List<T>::getLastElem();
}



template <typename T>
void Queue<T>::printQueue()
{
    Double_Linked_List<T>::print();
}

#endif //QUEUE_CLASS_H