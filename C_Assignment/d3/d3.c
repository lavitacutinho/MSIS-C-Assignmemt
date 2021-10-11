#include"d3.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>


//DAY 3
//1. WAP to convert a binary number to decimal and vice versa.
int binary_to_decimal(int input[])
{
    int i, size, decimal=0;
    size=sizeof(input)/sizeof(input[0]); //To find size of the input array.
    // printf("%d \n",size);
    for(i=0; i<=size; i++)
    {
        decimal=decimal+input[i]*pow(2,i); // Formula to convert the given binary to decimal form.
    }
    printf("%d",decimal);
    return decimal;
}

int decimal_to_binary(int input)
{
    int i=0,j, size;
    int arr[]= {},arr1[]= {};
    while (input>0)
    {
        arr[i]= input%2;
        // printf("%d\t",arr[i]); //Formula to convert decimal to binary.
        input=input/2;
        i++;
    }

    size=i+1;
// printf("%d",size);
    for(j=0; j<size; j++)
    {
        arr1[j]=arr[size-1-j]; // To reverse the output for readability.
    }

    printf("%d\t", arr[1]);
    // i--;*/

    return 1;
}

//2. Generate a sequence of numbers such that every number in the sequence is the sum of the previous three numbers. The first three numbers are 0,0,1.
int sum_of_3(int size)
{
    int arr[size],i, j,l;
    arr[0]=0, arr[1]=0, arr[2]=1; //Initializing the starting values.

    /*printf("%d\t", arr[0]);
    printf("%d\t", arr[1]);
    printf("%d\t", arr[2]);*/
    for (i=3; i<size; i++)     //To calculate the sum upto  previous N values (Here N=3).
    {
        int sum=0, k=i-3;
        for(j=k; j<i; j++)
        {
            sum=sum+arr[j];
        }
        arr[i]=sum;           //Store the sum in the required variable.
        //  printf("%d \t", arr[i]);

    }
    for(l=0; l<size; l++)
    {
        printf("%d \t", arr[l]);  //To print the sequence.
    }
    return 1;
}

/*3. WAP to print the following sketch by taking in N as number of rows
* * * *
* * *
* *
*                    */
int pattern_print(int N)
{
    int i,j;
    for(i=0; i<N; i++)
    {
        for(j=i; j<N; j++)
        {
            printf("*\t");
        }
        printf("\n");
    }
    return 1;
}

//4. Write a C program, which will print two digit numbers whose sum of both digit is multiple of seven. e.g. 16,25,34......
int digit_seven_divisor(int limit)
{
    int i,j,count=0,digit;
    for(i=1; i<=9; i++)       //Start looping from tens place.
    {
        for(j=0; j<=9; j++)  //Looping for unit place.
        {
            if((i+j)%7==0 && count<limit)   //Check whether the sum of digits is divisible by 7.
            {
                digit=(i*10)+j;              //Store digits in tens and unit place.
                printf("%d\t",digit);
                count++;                   //To keep count of no. of digits.
                //  printf("%d\t",count);

            }
        }
    }
    return 1;
}

//5. Write a recursive function for calculating power of a number. Take base number and exponent from user.
double power_recursive(int base, int exponent)
{
    if(exponent==0)
        return 1;
    if (base==0)
        return 0;
    return base* power_recursive(base, exponent-1);
}

//6. Write a recursive function for calculating factorial of a number.
double factorial(int input)
{
    if (input==0)
        return 1;
    return input*factorial(input-1);
}

//7. Use recursive calls to evaluate F(x) = x + x3/3! + x5/5! + x7/7!+ …
int series_recursion(int input,int limit)
{
    int i,j;
    double sum=0;
    j=2*limit;           //The limit is doubled since only odd power terms are required.
    for(i=0 ; i<j; i++)
    {
        if((i%2)!=0)
        {
            sum=sum + power_recursive(input,i)/factorial(i);  //The sequence terms are calculated by calling the power function and dividing it by the factorial function.
        }
    }
    printf("%f", sum);
    return 1;
}

//8. Concatenate two integer values using macros

#define RESULT strcat(s1,s2)    //Macro definition.

int concat(int input1, int input2)
{
    char s1[20], s2[20];
    int result;
    sprintf(s1, "%d", input1);  //Converting the given integer values into string.
    sprintf(s2, "%d", input2);
    return result= atoi(RESULT);    //Converting the result into integer form.
}

//9. Find square of a number using macros.
#define SQUARE(a) (a*a)
int square_of(int input)
{
    return SQUARE(input);
}

//10. Write a menu driven program to display the mathematical functions like square root, natural log, log10x, power(x,n), Cos(x). (use math.h)
float math_function(char operation[], double input, int exponent)
{
    int choice;
    {
        if (strcmp(operation,"Square Root")==0)   //Comparing the input string for use in switch statement.
            choice=1;
        else if (strcmp (operation,"Natural log")==0)
            choice=2;
        else if (strcmp(operation,"Log 10")==0)
            choice=3;
        else if (strcmp(operation,"Power")==0)
            choice=4;
        else choice=5;
    }
    switch(choice)
    {

    case 1:
        return sqrt(input);
        break;
    case 2:
        return log(input);
        break;
    case 3:
        return log10(input);
        break;
    case 4:
        return pow(input, exponent);
        break;
    case 5:
return cos(input);
        break;
    default:
        printf("Re-enter choice \n");

    }
}
