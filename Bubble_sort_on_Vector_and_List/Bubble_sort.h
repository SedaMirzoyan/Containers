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
       //std::cout << "i = " << i << "\n";
    }

	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
    std::cout << std::endl;
}


template <typename T>
void bubbleSortList(const List<T>& list_ob)
{
    Node<T>* head = list_ob.getHeadNode();

    Node<T>* prev = nullptr;
    Node<T>* curr = nullptr;
    Node<T>* swp_ptr = list_ob.getHeadNode();
    bool swapped;
    T swp_data;

    do {
        swapped = false;
        prev = list_ob.getHeadNode();

        while (prev != nullptr && prev->next != NULL)
        {
            curr = prev->next;

            if (prev->val > curr->val)
            {
                swp_data = prev->val;
                prev->val = curr->val;
                curr->val = swp_data;

                swapped = true;
            }
            prev = prev->next;
        }
    } while (swapped);
}


#endif //BUBBLE_SORT_H
