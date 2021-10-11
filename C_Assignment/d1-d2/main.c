
#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
#include<assert.h>
//#include<ctype.h>
#include<math.h>
#include"assign.h"

int main()
{
    assert(tolower("HELLO")== "hello");
    assert(area_of_circle(4)==50.24);
    simple_compound_interest(100,7,3);
    assert(temperature_converter (1, 104)== 1);
    assert(temperature_converter (2, 45)== 2);
    assert (even_odd(26)==1); //return 1 if number entered is even.
    assert (leap_year(2026)==2); //return 1 if number entered is leap year.
    assert( power_n (10)==1);

    assert(sum_of_digits (3,123) ==1);
    assert(reverse_number(123)==1);
    assert( digit_occurence(2,1225)==1);// return 1 if the digit occurs twice.
    assert( is_palindrome (12321)==1);
    assert(first_n_prime(10)==1);
    assert(disp_sum_series(4)==1);
    assert(is_armstrong(151)==1);
    assert(sum_of_divisor(220)==284);
    assert (amicable_pair(220,284)==1);
    assert(menu_driven(2,3,'+')==5);
    assert(volume_calculation("Cube",2,0,0,0)==8);
    assert (electric_bill(250.5)==375.75);

    return 0;
}

