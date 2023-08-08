#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <iostream>
#include "List.h"

template <typename T>
void bubbleSortVec(const T& arr, int n)
{
    bool is_swapped = false;
    for (int i = 0; i < n -1 ; i++) 
    {
       is_swapped = false;
      
       for (int j = 0; j < n - i -1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
                is_swapped = true;
            }
        }
       if (is_swapped == false)
       {
           std::cout << "vector is already swapped\n";
           break;
       }
       std::cout << "i = " << i << "\n";
    }

	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
    std::cout << std::endl;
}


template <typename T>
void swapPtr(Node<T>* ptr1, Node<T>* ptr2)
{
    Node<T>* tmp = ptr1->next;
    ptr1 -> next = ptr2;
    ptr2 -> next = tmp;
}

/*
template <typename T>   
void bubbleSortList(const List<T>& list_ob) //not completed
{
    int n = list_ob.getListLength();
    std::cout << "n = " << n << "\n";

    Node<T>* tmp = list_ob.getHeadNode();
    Node<T>* prev = list_ob.getHeadNode();
    Node<T>* head = list_ob.getHeadNode();

    for (int i = 0; i < n - 1; ++i)
    {
        prev = head;

        for (int j = 0; j < n - i - 1; ++j)
        {
            prev = tmp;
            tmp = tmp->next;

            if(prev->val > tmp->val)
            {
                //swapPtr(prev, tmp);
                Node<T>* other_ptr = tmp->next;
                tmp->next = prev;
                prev->next = other_ptr;
            }
        }
    }

    tmp = list_ob.getHeadNode();
    while (tmp != nullptr)
    {
        tmp = tmp->next;
        std::cout << tmp->val << " ";
    }
}*/


#endif //BUBBLE_SORT_H
