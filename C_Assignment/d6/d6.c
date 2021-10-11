#include "d6.h"
#include <assert.h>
#include <string.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

//DAY 6
//1. Write a program to store and print the roll no., name, age and marks of 10 students using structures.
Student store_data( int reg, char name[], int age, float grade)
{
    Student s1;
    s1.reg_number = reg;
    s1.grade = grade;
    strcpy(s1.name, name);
    s1.age=age;
    return s1;
}

void display_data(Student s2)
{
    printf("Reg. No.= %d\n Student name= %s\n Age= %d\n Grade= %f", s2.reg_number, s2.name,s2.age,s2.grade);
}

//2. Write a program to add, subtract and multiply two complex numbers using structures.
Complexop arithmetic_operation(Complexop a, Complexop b, int choice)
{
    /*Initializing variables required*/
    Complexop c_add, c_sub, c_mul;

    /* Add, subtract or multiply according to choice*/
    if (choice==1)
    {
        c_add.real=a.real+b.real;
        c_add.img=a.img+b.img;
        return c_add;
    }
    else if(choice==2)
    {
        c_sub.real=a.real-b.real;
        c_sub.img=a.img-b.img;
        return c_sub;
    }

    else
    {
        c_mul.real=(a.real*b.real)-(a.img*b.img);
        c_mul.img=(a.real*b.img)+(a.img*b.real);
        return c_mul;
    }
}

//3. Take the price and quantity of items as an input. Write a C function to calculate the sum of the prices.

/*To read purchase details*/
Purchase Enter_details()
{
    Purchase p2;
    printf("\n Enter item name:");
    scanf("%s", &p2.item);
    printf("\n Enter unit price of the item:");
    scanf("%f", &p2.price);
    printf("\nEnter the no. of units purchased:");
    scanf("%d", &p2.quantity);
    return p2;
}

/*To calculate the subtotal price of individual items*/
float sum_of_prices(Purchase p3)
{
    return p3.price*p3.quantity;
}

/*To calculate discount on the grand total as per the instructions*/
float calculate_discount(float total_amount)
{
    float final_amount;

    if (total_amount<1000)
        return final_amount= total_amount - (total_amount*0.05);
    else if (total_amount>1000 && total_amount<5000)
        return final_amount=total_amount- (total_amount*0.1);
    else
        return final_amount=total_amount - (total_amount*0.15);

}

/*To display the detailed entries with the subtotal*/
void display_bill(Purchase p4)
{
    printf("\n%-14s %4f  %4d  %10f",p4.item, p4.price, p4.quantity, p4.price* p4.quantity);
}

/*main function*/
int bill_generator(int input)  //Input is the no. of items purchased.
{
    /*Initializing required variables*/
    int i;
    float total_amount, final_amount;
    float total_price[30];
    Purchase purchase_detail[30];

    /* Calling function to read the entry details*/
    for(i=0; i<input; i++)
    {
        purchase_detail[i]=Enter_details(input);
    }

    /*Calling function to find subtotal and total amount*/
    for(i=0; i<input; i++)
    {
        total_price[i]= sum_of_prices(purchase_detail[i]);
        total_amount=total_amount+total_price[i];
    }
    final_amount=calculate_discount(total_amount);

    /*To print the bill on console*/
    printf("\nItem             Price  Quantity  Subtotal");
    printf("\n___________________________________________");

    /*Calling function to display entries*/
    for(i=0; i<input; i++)
    {
        display_bill(purchase_detail[i]);
    }

    printf("\n___________________________________________");
    printf("\nTOTAL: %35f \nDiscount: %32f ",total_amount, total_amount-final_amount);
    printf("\n___________________________________________");
    printf("\nGRAND TOTAL: %29f ",final_amount);

    return 1;
}

//4. Implement two player snake and ladder game with board size 10x10.
/*Random function to roll the dice*/
int rd()
{
    int rem;
A:
    rem=rand()%7;
    if(rem==0)
        goto A;
    else
        return rem;
}

/*Function to display the player position.*/
void displaychart(int curp,char player[4])
{
    int i,j,t,c,sft=0,diceres,pos1,pos2;

    /*Check if the cursor position is 100(win)*/
    if(curp==100)
    {
        printf("Congratulations!!!!!! \n\nPlayer %s wins\n",player);
        scanf("%*s");
        exit(0);
    }
    /*Compare the diceres variable after the rolling of dice and setting it to cursor position variable.*/
    for(i=10; i>0; i--)
    {
        t=i-1;
        if((sft%2)==0)
        {
            c=0;
            for(j=10; j>=1; j--)
            {
                diceres=(i*j)+(t*c++);

                if(curp==diceres)

                {
                    /*Console to highlight player position*/
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
                    printf("%s\t",player);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED+FOREGROUND_BLUE+FOREGROUND_GREEN);
                }
                else
                {
                    printf("%d\t",diceres);
                }

            }
            sft++;
        }
        else
        {
            c=9;
            for(j=1; j<=10; j++)
            {
                diceres=(i*j)+(t*c--);

                if(curp==diceres)
                {


                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_BLUE);
                    printf("%s\t",player);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED+FOREGROUND_BLUE+FOREGROUND_GREEN);
                }
                else
                    printf("%d\t",diceres);
            }


            sft++;
        }
        printf("\n\n");
    }
    printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
}

int snake_ladder()
{
    int i,dice,cur_pos1=0,cur_pos2=0;
    int ch;
    while(1)
    {
        printf("Snakes: | 25 to 9  | 65 to 40 | 99 to 1  |\nLadder: | 13 to 42 | 60 to 83 | 70 to 93 |\n\n");
        printf("Choose your option\n");
        printf("[1] Roll the dice\n");
        printf("[2] Exit\n");
        scanf("%d",&ch);

        /*If input entered is one play the game by calling the roll dice function.*/
        if(ch==1)
        {
            dice=rd();
            system("cls");
            printf("\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\t    Snakes And Ladders\n");
            printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            cur_pos1=dice+cur_pos1;

            /*Checking if cursor position is at the snake or ladder position, if true return it to the destination
            position by calling the displaychart function which then sets the position as per specifications.*/
            if(cur_pos1<101)
            {
                if(cur_pos1==99)
                {
                    displaychart(1,"-P1-");//snake
                }
                if(cur_pos1==65)
                {
                    displaychart(40,"-P1-");//snake
                }
                if(cur_pos1==25)
                {
                    displaychart(9,"-P1-");//snake
                }
                if(cur_pos1==70)
                {
                    displaychart(93,"-P1-");//ladder
                }
                if(cur_pos1==60)
                {
                    displaychart(83,"-P1-");//ladder
                }
                if(cur_pos1==13)
                {
                    displaychart(42,"-P1-");//ladder
                }
                else
                {
                    /*if its a normal square set cursor position as per the incremented dice roll.*/
                    displaychart(cur_pos1,"-P1-");

                }
                /*To display the dice result.*/
                printf("\t\t\t\tDice = %d\n",dice);
                printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            }
            else
            {
                cur_pos1=cur_pos1-dice;
                printf("Range exceeded of Player 1.\n");
                displaychart(cur_pos1,"-P1-");
            }

            /*To freeze the window.*/
            Sleep(1000);


            /*For the second player, i.e., computer in this case.*/
            goto label;
label:
            dice=rd();
            system("cls");
            printf("\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            printf("\t\t\t    Snakes And Ladders\n");
            printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            cur_pos2=dice+cur_pos2;

            /*Repeat the steps as followed for player 1.*/
            if(cur_pos2<101)
            {
                if(cur_pos2==99)	//snake
                {
                    displaychart(1,"-P2-");
                }
                if(cur_pos2==65)	//snake
                {
                    displaychart(40,"-P2-");
                }
                if(cur_pos2==25)	//snake
                {
                    displaychart(9,"-P2-");
                }
                if(cur_pos2==70)	//ladder
                {
                    displaychart(93,"-P2-");
                }
                if(cur_pos2==60)	//ladder
                {
                    displaychart(83,"-P2-");
                }
                if(cur_pos2==13) 	//ladder
                {
                    displaychart(42,"-P2-");
                }
                else
                {

                    displaychart(cur_pos2,"-P2-");

                }
                printf("\t\t\t\tDice = %d\n",dice);
                printf("\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
            }

            else
            {
                cur_pos2=cur_pos2-dice;
                printf("Range exceeded of Player 2.\n");

                displaychart(cur_pos2,"-P2-");
            }
        }
        else if(ch==2)
        {
            exit(0);
        }
        else
        {

            printf("Incorrect choice.Try Again\n");
        }
    }
    return 1;
}
