#include<stdlib.h>
#include "d7.h"

//DAY 7
/*1. WAP to store N integer values in an array (use malloc). Perform the following operations:
i. Search an element using linear search
ii. Find maximum and minimum value
iii. Find the sum of all the elements of array
iv. Find the sum of even and odd elements of array
v. Check whether the array in palindrome
vi. Write a function to deallocate the memory using free()*/

int * store_array_dynamically(int size)
{
    int *my_arr, i;

    my_arr = (int *)malloc(sizeof(int) * size);

    if(my_arr == NULL) return NULL; // if memory not allocated

    for(i=0; i< size; i++)
        *(my_arr+i) = i+1; // Store data 1 to size at location 0 to size-1


    return my_arr; // return base address of dynamically allocated memory
}

int linear_search_array(int *arr, int size, int element)
{
    int i;

    for(i = 0; i< size; i++)
    {
        if(*(arr+i) == element)
            return 1;
    }
    return 0;
}

Min_max min_max(int *arr, int size,Min_max result)
{
    int i;

    result.min = result.max = arr[0];

    for(i=1; i<size; i++)
    {
        if(result.min > arr[i]) result.min = arr[i];
        if(result.max < *(arr+i)) result.max = *(arr+i);
    }
    return result;
}

int sum_of_array(int *arr, int size)
{
    int i,sum=0;
    for(i=0; i<size,i++)
    {
        sum=sum+ *(arr+i);
    }
    return sum;
}

Even_odd sum_of_even_odd(int *arr, int size, Even_odd result)
{
    int i;
    result.even=result.odd=0;
    for(i=0; i<size; i++)
    {
        if(*(arr+i)%2==0) result.even= result.even+ *(arr+i);
        else  result.odd= result.odd+ *(arr+i);
    }
    return result;
}

int check_palindrome(int *arr, int size)
{
    int i,*rev;
    for(i=0; i<size; i++)
    {
        *(rev+i)=*(arr+(size-1));
    }
    for(i=0; i<size; i++)
    {
        if(*(rev+i)==*(arr+i))
        }
    return 1;
    else return 0;
}
