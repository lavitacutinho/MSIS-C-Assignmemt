#include <stdio.h>
#include <stdlib.h>
#include "d6.h"
#include <assert.h>
#include <string.h>


int main()
{
    Student student1= store_data(2100, "Dorothy", 26, 8.2);
    assert(strcmp(student1.name, "Dorothy")==0);
    display_data(student1);

    Complexop a1={3,1};
    Complexop b1={2,1};
    Complexop c_op=arithmetic_operation(a1,b1,1);
    assert(c_op.real==5);*/

    assert(bill_generator(2)==1);

    rd();
    displaychart(int curp,char player[4]);
    assert(snake_ladder()==1);
    return 0;
}
