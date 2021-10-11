#include "op.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//#include<ctype.h>
#include<math.h>

#define SIZE1 5
#define SIZE2 5
#define SIZE 4

int main()
{
    int arr1[SIZE1]= {1,2,3,4,8};
    int arr2[SIZE2]= {2,3,5,7,6};
    int arr[SIZE]= {1,2,3,4} ;

    int arr_union[SIZE];

    assert(sort_array(arr,"Ascending", SIZE)==1);

    assert(swap_number(4,7)==1);

    int min, max;
    find_max_min(arr, SIZE, &min,&max);
    assert(min==1);
    assert(max==8);

    assert(search_data(arr,SIZE,8)==1);
    assert(insert_data(arr,SIZE,2)==1);

    assert(array_union(arr1,arr2,SIZE1,SIZE2)==1);
    assert(array_intersection(arr1,arr2,SIZE1,SIZE2)==1);
    assert(set_difference_(arr1,arr2, SIZE1,SIZE2)==1);

    assert(search_data(arr1,SIZE1,7)==1);

    store_data(arr,7);
    store_data(arr,8);
    store_data(arr,9);
    store_data(arr,2);
    assert(check_duplicate(arr, SIZE)==1);

    assert(linear_search_array(arr,SIZE,7)==1);

    assert(binary_search_array(arr,0,4,5)==2);    // arr[SIZE]= {2,3,5,7,6};

    assert( store_data(2)==2);
    assert( store_data(3)==3);
    assert( store_data(4)==4);
    assert( store_data(5)==5);
    assert(productsum_of_numbers(arr,SIZE)==20);  //arr[SIZE]={1,2,3,4}

    assert(string_length("Information") == 10);

    assert(date_format(28,9,2021)==1);

    assert(string_uppercase("seat")== 1);
    */

    assert(string_reverse("tar","rat")==1);

    return 0;
}
