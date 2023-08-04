#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<typename T>

class Array {
private:
    T* m_ptr = nullptr;
    int m_size;
    int m_capacity;

public:
    Array();
    Array(int n);
    virtual ~Array();
    Array(const Array& ob);
    Array(Array&& ob);
    Array& operator=(const Array& ob);
    Array& operator =(Array&& ob);
    T& operator[](int index) const;
    T& at(int index) const;
    bool operator >(const Array& ob);
    bool operator <(const Array& ob);
    bool operator ==(const Array& ob);
    T* genElements();
    T getElement(int index);
    void printArray();
    int getSize()const;
    int getCapacity()const;
    void pushBack(const T& elem);
    T popBack();
    bool isEmpty();
    bool isFull();
    void setSize(int s);
    void erase(int index);
    void clear();
    int reserve();
    T getBackElement()const;
};

template <typename T>
Array<T>::Array<T>()
{
    std::cout << "Default " << __func__ << "\n";
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
Array<T>::Array<T>(int n)
{
    std::cout << "Parametrized " << __func__ << "\n";
    m_size = n;
    m_capacity = n;
    m_ptr = new T[m_size];
}

template <typename T>
Array<T>::~Array()
{
    std::cout << __func__ << "\n";
    delete[] m_ptr;
}

template <typename T>
Array<T>::Array<T>(const Array& ob) :m_size(ob.m_capacity), m_capacity(ob.m_capacity)
{
    std::cout << "Copy " << __func__ << "\n";

    this->m_ptr = new T[m_size];

    for (int i = 0; i < m_size; i++)
    {
        this->m_ptr[i] = ob.m_ptr[i];
    }
}


template <typename T>
Array<T>::Array<T>(Array&& ob) :m_size(ob.m_size), m_capacity(ob.m_capacity)
{
    std::cout << "Move " << __func__ << "\n";

    if (this != &ob)
    {
        this->m_ptr = ob.m_ptr;

        ob.m_ptr = nullptr;
        ob.m_size = 0;
        ob.m_capacity = 0;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& ob)
{
    std::cout << __func__ << "\n";

    if (this != &ob)
    {
        std::cout << __func__ << "\n";
        this->m_size = ob.m_size;
        this->m_capacity = ob.m_capacity;
        delete[] m_ptr;

        this->m_ptr = new T[this->m_size];

        for (int i = 0; i < m_size; i++)
        {
            this->m_ptr[i] = ob.m_ptr[i];
        }
    }
    return *this;
}


template <typename T>
Array<T>& Array<T>::operator =(Array&& ob)
{
    std::cout << "Move " << __func__ << "\n";

    if (this != &ob)
    {
        delete this->m_ptr;
        this->m_size = ob.m_size;
        this->m_capacity = ob.m_capacity;

        this->m_ptr = ob.m_ptr;

        ob.m_ptr = nullptr;
        ob.m_size = 0;
        ob.m_capacity = 0;
    }
    return *this;
}


template <typename T>
T& Array<T>::operator[](int index) const
{
    return m_ptr[index];
}

template <typename T>
T& Array<T>::at(int index) const
{
    if (index < 0 || index >= m_size)
    {
        std::cout << "Out of range\n";
    }
    //std::cout << "Element with index " << index << " and with value " << ptr[index] << std::endl;
    return m_ptr[index];
}


template <typename T>
bool Array<T>::operator >(const Array& ob)
{
    bool flag = false;
    if (this->m_size > ob.m_size)
    {
        flag = true;
    }
    std::cout << std::boolalpha << flag << std::endl;
    return flag;
}


template <typename T>
bool Array<T>::operator <(const Array& ob)
{
    bool flag = false;
    if (this->m_size < ob.m_size)
    {
        flag = true;
    }
    std::cout << std::boolalpha << flag << std::endl;
    return flag;
}


template <typename T>
bool Array<T>::operator ==(const Array& ob)
{
    bool flag = false;
    if (this->m_size == ob.m_size)
    {
        flag = true;
    }
    std::cout << std::boolalpha << flag << std::endl;
    return flag;
}


template <typename T>
T* Array<T>::genElements()
{
    for (int i = 0; i < m_size; i++)
    {
        m_ptr[i] = rand() % 100 + 1;
    }
    return m_ptr;
}


template <typename T>
T Array<T>::getElement(int index)
{
    if (index > m_size || m_size < 0)
    {
        std::cout << "Out of range\n";
    }
    else
    {
        std::cout << "Element with value " << m_ptr[index] << " was returned\n";
    }
    return m_ptr[index];
}

template <typename T>
void Array<T>::printArray()
{
    for (int i = 0; i < m_size; i++)
    {
        std::cout << "element[" << i << "] = " << m_ptr[i] << std::endl;
    }
}


template <typename T>
int Array<T>::getSize()const
{
    return m_size;
}


template <typename T>
void Array<T>::setSize(int s)
{
    if (m_size < 0)
    {
        std::cout << "Size can't be negative\n";
        throw std::logic_error("Negative size");
    }
    m_size = s;
}

template <typename T>
bool Array<T>::isEmpty()
{
    if (m_size == 0)
    {
        std::cout << "Array is empty\n";
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
bool Array<T>::isFull()
{
    if (m_size == m_capacity)
    {
        std::cout << "Array is full\n";
        return true;
    }
    else
    {
        return false;
    }
}



template <typename T>
void Array<T>::pushBack(const T& elem)
{
    bool b = isFull();
    //std::cout << std::boolalpha << b << std::endl;

    if (isFull())
    {
        m_capacity = reserve();
    }

    T* new_ptr = new T[m_capacity];

    for (int i = 0; i < m_capacity; i++)
    {
        new_ptr[i] = m_ptr[i];
    }

    int current_ind = m_size + 1;
    new_ptr[current_ind - 1] = elem;

    m_ptr = new T[m_capacity];

    for (int i = 0; i < m_capacity; i++)
    {
        m_ptr[i] = new_ptr[i];
    }
    m_size = current_ind;

    delete[]new_ptr;
}

template <typename T>
T Array<T>::popBack()
{
    T elem;
    int current_ind;

    if (m_size > 0)
    {
        elem = m_ptr[m_size - 1];
        this->m_size--;
        current_ind = m_size;
    }
    else
    {
        throw std::logic_error("empty Array");
    }
    return elem;
}


template <typename T>
int Array<T>::reserve()
{
    if (m_size >= m_capacity)
    {
        m_capacity = 2 * m_size;
    }
    else
    {
        m_capacity = m_size;
    }
    return m_capacity;
}


template <typename T>
int Array<T>::getCapacity()const
{
    return m_capacity;
}


template <typename T>
void Array<T>::erase(int index)
{
    if (index > m_size || index < 0)
    {
        std::cout << "Invalid index\n";
    }
    else if (index == m_size - 1)
    {
        T elem = popBack();
    }
    else
    {
        for (int i = index; i <= m_size; i++)
        {
            m_ptr[i] = m_ptr[i + 1];
        }
        m_size--;
    }
}

template <typename T>
void Array<T>::clear()
{
    for (int i = 0; i < m_size; i++)
    {
        m_ptr[i] = NULL;
    }
    m_size = 0;
    m_capacity = 0;
}



template <typename T>
T Array<T>::getBackElement()const
{
    return m_ptr[m_size - 1];
}

#endif //ARRAY_CLASS_H
