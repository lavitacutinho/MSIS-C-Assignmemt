#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include "d8.h"

//DAY 8
//1. Write a program to store roll no., name, age and marks of N students dynamically. Perform the following operations
Student *store_stud_dynamically(int record)
{
    Student *stud_detail;
    int i;
    stud_detail=(Student *)malloc(sizeof(Student)*record);

    /*To check if memory has been allocated*/
    if(stud_detail==NULL) return NULL;

    /*Read the student details*/
    for(i=0; i<record; i++)
    {
        printf("Enter student details:\n");
        scanf("%d %s %d %d", &(stud_detail+i)->reg, &(stud_detail+i)->name, &(stud_detail+i)->age,&(stud_detail+i)->marks);
    }

    /*Displaying student detail*/
    printf("Display student details:\n");
    for(i=0; i<record; i++)
    {
        printf("%d \t%s \t%d \t%d \n", (stud_detail+i)->reg, (stud_detail+i)->name, (stud_detail+i)->age, (stud_detail+i)->marks);
    }
    return stud_detail;
}

/*i. Search student by roll no.*/
int search_by_roll(Student *stud_detail, int record, int search)
{
    int i;

    /*For loop to check for the given roll no(i.e. search)*/
    for(i=0; i<record; i++)
    {
        if((stud_detail+i)->reg==search) return 1;
    }
    return 0;
}

/*ii. Search student by name*/
int search_by_name(Student *stud_detail, int record, char *searchn)
{
    int i;
    for(i=0; i<record; i++)
    {
        if(strcmp((stud_detail+i)->name, searchn))
            return 0;
    }
}

/*iii. Return student details who have scored highest marks.*/
int highest_mark(Student *stud_detail, int record)
{
    int i, max;

    /*Assign the marks of 1st student to max and compare it to the rest.*/
    max=(stud_detail+0)->marks;

    for(i=1; i<record; i++)
    {
        if(((stud_detail+i)->marks)>max)
            max=(stud_detail+i)->marks;
    }
    printf("%d", max);
    return 1;
}

/*iv. Display the details of the students whose name begins with ‘A’.*/
int search_a(Student *stud_detail, int record, char letter)
{
    int i, j;
    // printf("%c\n",*((stud_detail+0)->name+0));
    /*Compare the first character with the search and display the details if true.*/
    for(i=0; i<record; i++)
    {
        if(*((stud_detail+i)->name+0)== letter)
        {
            printf("%d \t%s \t%d \t%d \n", (stud_detail+i)->reg, (stud_detail+i)->name, (stud_detail+i)->age, (stud_detail+i)->marks);
            return 1;
        }
    }

    return 0;
}

/*v. Deallocate all the memory before exiting the program.*/
Student * deallocate(Student *stud_detail)
{
    // deallocate structure variable
    free(stud_detail);
    return NULL;

}

/*2. In an X-Y Plane there are N numbers of points at location (x,y). Each point has a weight associated with it.
Define the structure for the above problem.
Find the point with maximum weight.
Assuming all points are connected, count the number of vertical and horizontal lines.*/
Coord *read_coord_dynamically(int row)
{
    Coord **c, *p;
    int i,j, column=2, len, h_line=0, v_line=0;

    /*Dynamically allocate 2D array*/
    len=sizeof(int *)*row+sizeof(int)*column*row;
    c=(int **)malloc(len);

    /*Points to the 1st row*/
    p=(int *) (c+row);

    for(i=0; i<row; i++)
        c[i]=(p+column*i);

    /*For loop to read coordinates*/
    for (i=0; i<row; i++)
    {
        printf("Enter the coordinates:");
        for (j=0; j<column; j++)
        {
            scanf("%d", &(*(c+i)+j)->x);
        }
        printf("Enter the weight associated with the point:");
        scanf("%d", &(p+i)->weight);
    }
    printf("\n");

    /*Display the coordinates*/
    for (i=0; i<row; i++)
    {
        printf("Displaying the coordinates:");
        for (j=0; j<column; j++)
        {
            printf("%d\t", *(*(c+i)+j)->x);
        }
        printf("The weight associated with the point:");
        printf("%d", (p+i)->weight);
        printf("\n");
    }

    /*Check for the maximum weight.*/
    int max= (p+0)->weight;
    for (i=0; i<row; i++)
    {
        if((p+i)->weight >=max)
        {
            max=(p+i)->weight;
            printf("\nThe point corresponding to max weight %d is:",max);
            for (j=0; j<column; j++)
            {
                printf("%d\t", *(*(c+i)+j)->x);
            }
        }
    }
    return c;
}

int find_lines(Coord **c)
{
    int i,j, row;
    int column=2, h_line=0, v_line=0;

    /*Compare the coordinates to find the no. of lines*/
    for (i=0; i<row; i++)
    {
        for (j=0; j<column; j++)
        {
            if(j%2==0)
            {
                if( *(*(c+i)+j)->x==*(*(c+i+1)+j)->x)
                    h_line=h_line+1;
            }
            else
            {
                if( *(*(c+i)+j)->x==*(*(c+i+1)+j)->x)
                    v_line=v_line+1;
            }

        }
        printf("\nThe no. of horizontal lines:%d", h_line);
        printf("\nThe no. of vertical lines:%d", v_line);
    }
    return 1;
}



