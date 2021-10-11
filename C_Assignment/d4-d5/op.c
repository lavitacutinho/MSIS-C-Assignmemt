#include "op.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include<ctype.h>
#include<string.h>
#include<assert.h>

#define SWAP(a,b) a=a^b;      \
b=a^b;      \
a=b^a;                              //Macro definition to swap two no.s

//DAY 4-5
//1. WAP to sort the given array in ascending and descending order.
int sort_array_ascending(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i]>arr[j])            //Comparing the 0th element with the next element.
            {
                SWAP( arr[i], arr[j]);
            }
        }
        printf("%d\t", arr[i]);
    }
    return 1;
}

int sort_array_descending(int arr[], int size)
{
    int i,j;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i]<arr[j])            //Comparing the 0th element with the next element.
            {
                SWAP( arr[i], arr[j]);
            }
        }
        printf("%d\t", arr[i]);
    }
    return 1;
}

int sort_array(int arr[], char choice[], int size)
{
    if(strcmp(choice, "Ascending")==0)
        sort_array_ascending(arr, size);
    else
        sort_array_descending(arr, size);
}

//2. Write a program to swap two numbers using function.
int swap_number(int input1, int input2)
{
    SWAP(input1,input2);               //Using macro SWAP.
    return 1;
}

//3. WAP to find minimum and maximum elements in a given array using the function int find_max_min(int array[], int size, int *max, int *min);
int find_max_min(int arr[], int size, int *min, int *max)
{
    sort_array_ascending(arr, size);  //Calling the ascending function & assigning the max and min value respectively.
    *min=arr[0];
    *max=arr[size-1];
}

/*4. Write a C program that take 2 integer sets A[] and b[] as input and prints results of following set operations:
I. A union B (Write function set_union())
II. A intersection B (Write function set_intersection())
III. A-B and B-A (Write function set_difference()) */

int set_union(int arr1[], int arr2[], int size1, int size2)
{
    int i=0, j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
            printf("%d\t", arr1[i++]);
        else if(arr1[i]>arr2[j])
            printf("%d\t", arr2[j++]);
        else
        {
            printf("%d\t",arr2[j++]);
            i++;
        }

    }
    while(i<size1)
        printf("%d\t",arr1[i++]);
    while(j<size2)
        printf("%d\t",arr2[j++]);
    //}
    //return arr_union;
    return 1;
}

int set_intersection(int arr1[], int arr2[], int size1, int size2)
{
    int i=0, j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
            i++;
        else if(arr1[i]>arr2[j])
            j++;
        else
        {
            printf("%d\t",arr2[j++]);
            i++;
        }
    }
    return 1;
}

int set_difference_(int arr1[],int arr2[],int size1,int size2)
{
    int i=0, j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]!=arr2[j])
            printf("%d\t", arr1[i++]);
        else
        {
            i++;
            j++;
        }

    }
    return 1;
}

//5. WAP to store 10 numbers in an array. Remove the duplicate entries in the array.

int store_data(int data)

{
    int arr;
    arr=data;
    return arr;
}

int check_duplicate(int arr[], int size)
{
    int j,k,temp;
    for(j=0; j<size; j++)
    {
        for(k=j+1; k<size; k++)
        {
            if(arr[j]==arr[k])
            {
                /* temp=arr[k];                //MOVING THE DUPLICTE VALUE TO THE END OF THE STRING AND REDUCING THE SIZE
                  arr[k]=arr[size-1];
                  arr[size-1]=temp;*/
                arr[k]= swap_number(arr[k],arr[size-1]);
                size--;
            }
        }
        printf("%d\t", arr[j]);
    }

    return 1;
}

//6. WAP to search for a given integer in an array using the linear search technique.
int linear_search_array(int arr[], int size, int element)
{
    int i; // int arr[] = 4, 2, 6, 1, 7

    for(i = 0; i< size; i++)
    {
        if(arr[i] == element)
            return 1;
    }
    return 0;
}

//7. WAP to search for a given integer in an array using the binary search technique
int binary_search_array(int arr[], int l,int r, int search)
{
    int mid;
    {
        mid=l+r/2;      //To find the mid point of the arrray.
        if(arr[mid]==search)
            return mid;
        if(arr[mid]>search)
            return binary_search_array(arr, 0, mid,search);   //To search in the lower half
        return binary_search_array(arr,mid+1,r,search);       //To search in the upper half
    }
    return 0;
}

//8. Write a C program, that reads list of n integer and print sum of product of consecutive numbers. if n=7 and numbers are 4,5,2,5,6,4,7 then output is 4*5+5*2+2*5+5*6+6*4+4*7 = 122.
int productsum_of_numbers(int arr[],int size)
{
    int j,sum=0;
    for(j=0; j<size-1; j++)
    {
        sum=sum+(arr[j]*arr[j+1]);
    }
    return sum;
}

//9. WAP to read a string from the user and find the length of string.( Note: Do not use string.h header file)
int string_length(char str[])
{
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

//10. Input date, month and year from the user, and using switch case, display in worded format. e.g. input: d=16, m=7, y=1992
//Output: 16th July, 1992
int date_format(int date, int month, int year)
{
    switch(month)
    {
    case 1:
        printf("Output: %dth January, %d", date,year);
        break;
    case 2:
        printf("Output: %dth February, %d", date,year);
        break;
    case 3:
        printf("Output: %dth March, %d", date,year);
        break;
    case 4:
        printf("Output: %dth April, %d", date,year);
        break;
    case 5:
        printf("Output: %dth May, %d", date,year);
        break;
    case 6:
        printf("Output: %dth June, %d", date,year);
        break;
    case 7:
        printf("Output: %dth July, %d", date,year);
        break;
    case 8:
        printf("Output: %dth August, %d", date,year);
        break;
    case 9:
        printf("Output: %dth September, %d", date,year);
        break;
    case 10:
        printf("Output: %dth October, %d", date,year);
        break;
    case 11:
        printf("Output: %dth November, %d", date,year);
        break;
    case 12:
        printf("Output: %dth December, %d", date,year);
        break;
    }
    return 1;
}

//11. Write a function that will scan a character string passed as an argument and convert all lower-case characters into their upper-case equivalents.
int string_uppercase(char str[])
{
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='a'&& str[i]<='z')
        {
            str[i]=str[i]-32;        //Convert lowercase to uppercase by manipulating ASCII values.
        }
    }
    printf("%s",str);
    return 1;
}

//12. Write a program to read a string from the user and reverse the string.( Note: Do not use string.h header file)
int string_reverse(char str[],char rev_str[])
{
    int i,j;
    j=string_length(str);   //Find the length of entered array.
    int end=j-1;
    for(i=0; i<=end; i++)
    {
        rev_str[i]=str[j-1];   //Store the values in reversing order of index.
        j--;
    }
    rev_str[i]='\0';
    printf("%s",rev_str);
    return 1;
}

//13. WAP to construct 5 * 5 matrix and display the contents. Use functions for construction and display of matrix.
int display_matrix(int arr[][],int row, int column)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 1;
}

//14. WAP to add 2 matrixes.
int add_two(int a[][], int b[][], int row, int column)
{
    int i,j, sum[row][column];
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            sum[i][j]=a[i][j]+b[i][j];
        }
    }
    display_matrix(c[][],row,column);
    return 1;
}

//15. WAP to check whether 2 matrixes are same.
int check_matrices(int a[][], int b[][], int row, int column)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            b[i][j]=a[i][j];
        }
    }
    return 1;
}

//16. WAP program to check if given matrix is a sparse matrix.
int sparse_matrix(int a[][],int row, int column)
{
    int i,j, count=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            if(a([i][j]==0)
        {
            count++;
        }
    }
}
if(count>((row*column)/2))
    {
        printf("Sparse matrix\n");
        return 1;
    }
    else
    {
        printf("Not a Sparse matrix\n");
        return 0;
    }

}


