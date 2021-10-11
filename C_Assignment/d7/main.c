

#include<assert.h>
#include<stdlib.h>

#include "d7.h"
#define SIZE_ARRAY_ONE 10
#define SIZE_ARRAY_TWO 20


int main()
{
    int *arr_one, *arr_two;
    int i;
    Min_max test_minmax;
    Even_odd test_evenodd;

    arr_one = store_array_dynamically(SIZE_ARRAY_ONE);
    arr_two = store_array_dynamically(SIZE_ARRAY_TWO);

    assert(arr_one != NULL); // test for memory located successfully

    assert(*(arr_one + 0) == 1);
    assert(*(arr_one + 5) == 6);
    assert(*(arr_one + 9) == 10);


    for(i=0; i< SIZE_ARRAY_ONE;i++)
        assert(*(arr_one+i) == i+1);

    for(i=0; i< SIZE_ARRAY_TWO;i++)
        assert(*(arr_two+i) == i+1);



    assert(linear_search_array(arr_one, SIZE_ARRAY_ONE, 8) == 1);
    assert(linear_search_array(arr_one, SIZE_ARRAY_ONE, 11) == 0);


    test_minmax = min_max(arr_one, SIZE_ARRAY_ONE, test_minmax);
    assert(test_minmax.min == 1);
    assert(test_minmax.max == 10);

    assert(sum_of_array(arr_one, SIZE_ARRAY_ONE)==45);

    test_evenodd = sum_of_even_odd(arr_one, SIZE_ARRAY_ONE, test_evenodd);
    assert(test_evenodd.even == 30);
    assert(test_evenodd.odd == 25);

    assert(check_palindrome(arr_one,SIZE_ARRAY_ONE)==1);

    free(arr_one);
    free(arr_two);

    assert(arr_one != NULL);

    arr_one = arr_two = NULL;

    return 0;
}
