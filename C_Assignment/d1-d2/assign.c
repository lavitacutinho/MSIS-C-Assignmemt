#include"assign.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>

//DAY 1
char lowercase(char s)
{
    int i;
    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]>=65 && s[i]<=90)
            s[i]=s[i]+32;
    }

    return strlwr(s);
}

// 2. Write a program to calculate the area of circle.
float area_of_circle(float radius)
{
    return 3.14*radius*radius;   //formula for area of circle
}

//3. Write a program to calculate simple and compound interest.
float simple_compound_interest(float principal, float rate, float time)
{
    float SI,CI;
    SI= (principal*time*rate)/100; //simple interest formula
    CI= (principal *( pow(1+(rate/100),time)))- principal; //compound interest formula
    printf("Simple interest= %f \n",SI);
    printf("Compound interest= %f \n",CI);
}

//4. Write a program to convert temperature from Celsius to Fahrenheit and Fahrenheit to Celsius.
float temperature_converter (float value, float temperature)
{
    float celsius, fahrenheit;
    if(value==1)
    {
        celsius=(temperature-32)*(5/9); // formula for Fahrenheit to Celsius.
        return 1;
    }
    else if (value==2)
    {
        fahrenheit=((9/5)*temperature)+32; //formula for Celsius to Fahrenheit.
        return 2;

    }
    return 0;
}

//5. Check if entered number is even or odd.
int even_odd(int number)
{

    if(number%2==0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

//6. Check if entered year is leap year or not.
int leap_year(int year)
{

    if(year%4==0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

//7. WAP to find power of 2^N using left shift operator.
int power_n(int power)
{
    int answer;
    answer=1 << power; // Since x << y i.e the left shift operator, is equivalent to x*(2^y).
    printf("%d", answer);
    return 1;
}

//DAY 2
//1. Enter a 5 digit number and find the sum of its digits. For E.g. if int number = 12345; then sum = 15;
int sum_of_digits(int number)
{

    int  digit, quotient, sum = 0;
    while (number!=0)
    {
        digit= number % 10;
        // printf("%f \t ",10);
        // printf("%d \t",digit);
        quotient= number/ 10;
        sum = sum + digit;
        number=quotient;
    }

    printf("%d",sum);
    return 1;
}

//2. Write a program to reverse the number. For E.g. If int number = 12345; then the output reverse = 54321;
int reverse_number(int number)
{
    int reverse_num=0, digit, quotient;
    while (number!=0)
    {
        digit= number % 10;
        quotient=number/10;
        reverse_num = reverse_num * 10 +digit;
        number=quotient;

    }
    printf("%d", reverse_num);
    return 1;
}

/*
{
    int length, i, output[]={};
    length=sizeof(input);
    for(i=0; i<length; i++)
    {
        output[i]=input[length-1];
        length--;
      //  swap(input[i],input[length-1]);
    }
    printf("%d \t", output[i]);

return 1;
} */

// 3. Write a program to count the occurrences of digit in a number.
int digit_occurence(int check, int number)
{
    int digit,count=0, quotient;
    while (number!=0)
    {
        digit= number % 10;
        if(digit==check)
            count++;
        quotient=number/10;
        number=quotient;
        break;

    }
    return 1;
}

//4. WAP to check if a given number is a palindrome. For e.g. 12321, 56788765;
int is_palindrome (int input)
{
    int number=input, reverse_num=0, digit, quotient; // To find the reverse of a given number.
    while (number!=0)
    {
        digit= number % 10;
        quotient=number/10;
        reverse_num = reverse_num * 10 +digit;
        number=quotient;

    }

    if (reverse_num== input)   // To compare the given number and its reverse.
    {

        printf("The input is a palindrome");
        return 1;
    }
    else
    {
        printf("The input is not a palindrome");
        return 0;
    }
}

//5. Generate the first 'N' prime numbers. For Eg. If N=5 then 2,3,5,7,11
int first_n_prime(int limit)
{
    int input=2, count=1 ;
    while(count<=limit)
    {
        int i;
        for(i=2; i<=input/2; i++)
        {
            if(input%i==0)
                return 0;
        }
        return 1;
        count++;
        input++;
    }
}

//6. Write a C program to display and find the sum of the series 1+11+111+....111 up to n. For eg. if n=4, the series is: 1+11+111+1111. Take the value of 'n' as input from the user

int disp_sum_series( int input)
{
    int i, sum=0, last_digit=0;
    printf("The series is:");
    for(i=0; i<input; i++)
    {
        last_digit= last_digit + pow(10,i); // To evaluate the last digit in the series.
        printf("+%d", last_digit); // To print the series.
        sum=sum+last_digit;
    }
    printf("\n The sum of the series is %d\n",sum);
    return 1;
}

//7. A number is called an Armstrong number if the sum of the cubes of the digits of the number is equal to the number. For example 153 = 1^3 + 5^3 + 3^3. Write a C program that asks the user to enter a number and returns if it is Armstrong or not.
int is_armstrong (int input)
{
    int number= input, arm_sum=0;
    while(number!=0)
    {
        int digit;
        digit= number % 10; // To separate the digits.
        arm_sum=arm_sum+ pow(digit,3);
        number= number/ 10;
    }

    // printf("%d", arm_sum);
    if(arm_sum==input)
    {

        printf("The no. is an Armstrong no.\n");
        return 1;
    }
    else
    {
        printf("The no. is not an Armstrong no.\n");
        return 0;
    }
}

//8. Amicable numbers are found in pairs. A given pair of numbers is Amicable if the sum of the proper divisors (not including itself) of one number is equal to the other number and vice – versa.

int sum_of_divisor(int input)           //Function to find the sum of proper divisors of a given number.
{
    int i, amicable_sum=0;
    for(i=1; i<input; i++)
    {
        if(input%i==0)
        {
            amicable_sum=amicable_sum+ i;
        }
    }
    //  printf("%d", amicable_sum);
    return amicable_sum;
}

int amicable_pair(int input1,int input2)
{
    int ami1=0, ami2=0;
    ami1= sum_of_divisor(input1);  //Calling function to find sum of the divisors for the pair of given numbers.
    ami2=sum_of_divisor(input2);
    //printf("%d \n", input1);
    // printf("%d \n", input2);
    // printf("%d \n", ami1);
    //  printf("%d", ami2);

    if((ami2==input1) && (ami1==input2))   //Comparing the sum of divisors of the no. to the other number and vice versa to check if they are a pair.
    {
        printf("The pairs are amicable");
        return 1;
    }
    else
    {
        printf("The pairs are not amicable");
        return 0;
    }
}

//9. Write a menu driven program to read two integers & find their sum, difference & product.
int menu_driven(int input1,int input2, char operation)
{
    switch(operation)
    {
    case '+':
        printf("Sum: %d", input1+input2);
        return input1+input2;
        break;
    case'-':
        printf("Difference: %d", input1-input2);
        return input1-input2;
        break;
    case '*':
        printf("Product: %d", input1*input2);
        return input1*input2;
        break;
    default:
        printf("Wrong Choice");
    }
}

//10. Write a C program to calculate the volume of the following shapes: Cube, Cuboid, Sphere, Cylinder and Cone. Ask the user which one s/he wants to calculate, and take the appropriate required inputs. Then print the result. The input should be taken in the main function and calculations for every solid should be done in a separate function by passing appropriate arguments.
float volume_calculation(char solid[], int length, int breadth, int height,int radius)
{
    int choice;
    const double pi=22/7;
    {
        if (strcmp(solid,"Cube")==0)   //Comparing the input string for use in switch statement.
        {
            choice=1;
        }
        else if (strcmp (solid,"Cuboid")==0)
        {
            choice=2;
        }
        else if (strcmp(solid,"Sphere")==0)
        {
            choice=3;
        }
        else if (strcmp(solid,"Cylinder")==0)
        {
            choice=4;
        }
        else
        {
            choice=5;
        }
    }
    //const double pi=22/7;
    switch(choice)
    {

    case 1:
        ("Volume of the cube is: %f", pow(length,3));
        return pow(length,3);
        break;
    case 2:
        ("Volume of the cuboid is: %f", length*breadth*height);
        return length*breadth*height;
        break;
    case 3:
        ("Volume of the sphere is: %f", 4*pi* pow(radius,3));
        return 4*pi* pow(radius,3);
        break;
    case 4:
        ("Volume of the Cylinder is: %f", pi*pow(radius,2)*height);
        return pi*pow(radius,2)*height;
        break;
    case 5:
        ("Volume of the cone is: %f", pi*pow(radius,2)*(height/3));
        return pi*pow(radius,2)*(height/3);
        break;
    default:
        printf("Re-enter choice \n");

    }
}

//11. An Electricity board charges the following rates for use of electricity.
//For the First 200 units : Rs 1 per unit
//For the next 100 units : Rs 1.5 per unit
//Beyond 300 units : Rs 2 Per unit.
//Write a C Program to read no of unit consumed and print out total charge amount
float electric_bill(float unit)
{
    if ((unit<=200)==1)
    {
        printf("Total charge: %f", unit*1);
        return unit*1;
    }
    else if ((unit>200 && unit<=300)==1)
    {
        printf("Total charge: %f", unit*1.5);
        return unit*1.5;
    }
    else if ((unit>300)==1)
    {
        printf("Total charge: %f", unit*2);
        return unit*2;
    }
    return 0;
}
