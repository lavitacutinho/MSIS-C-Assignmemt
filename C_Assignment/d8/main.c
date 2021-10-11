#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<assert.h>
#include "d8.h"

int main()
{
    Student *s1, *s2, *s3, *s4;
    s1=store_stud_dynamically(2);
    assert(search_by_roll(s1, 2, 211)==1);
    assert(search_by_name(s1, 2, "Meg")==1);
    assert(highest_mark(s1,2)==1);
    assert(search_a(s1,2,'A')==1);
    stud_detail = deallocate(stud_detail);
    assert(stud_detail == NULL);


    Coord **c1;
    c1=read_coord_dynamically(3);

    assert(find_lines(c1)==1);
    return 0;
}
