//DAY 9
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include "d9.h"

FILE * open_file(char *file_name, char *mode) //Function to open file.
{
    FILE *fp;

    fp = fopen(file_name,mode);

    if(fp == NULL) return NULL;

    return fp;
}

//1. Write a simple program to display the contents of a file.
void display(FILE *fp)
{
    char ch;

    while((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    fclose(fp);
}

//2. Write a program to copy the contents of one file to another.
int copy_file(char *src, char *dst)
{
    FILE *fsrc, *fdst;
    char ch;

    fsrc = open_file(src, READ_TEXT_MODE);
    fdst = open_file(dst, WRITE_TEXT_MODE);

    if(fsrc == NULL || fdst == NULL) return 0;

    while((ch=fgetc(fsrc)) != EOF)
    {
        fputc(ch,fdst);
    }
    fclose(fsrc);
    fclose(fdst);

    return 1;
}

//3. Write a program to count number of characters, spaces tabs and lines in a file.
int count_file_content(char *file_name)
{
    //File pointer to hold reference to the file.
    FILE *fp;
    char ch;
    int tchar=0,tspaces=0,ttabs=0, tlines=0;  //Initializing variables to hold the count.

    fp=open_file(file_name, READ_TEXT_MODE);  //To open the file by calling the function.

    if(fp==NULL) return 0;                   //To check if file is created.

    else
    {

        while((ch=fgetc(fp))!= EOF)
        {
            if(ch== ' ')
                tspaces++;
            if(ch=='\n')
                tlines++;
            if(ch=='\t')
                ttabs++;
            tchar++;

        }
        fclose(fp);
        printf("\nTotal spaces=%d \nTotal lines=%d \nTotal tabs=%d \nTotal char=%d",tspaces,tlines,ttabs,tchar);

    }
    return 1;
}

//4. Read a file which contains one number per line. Check the number is odd or even and write to corresponding odd.txt or even.txt accordingly. Note: Numbers may not be single digit numbers.

/* Function to read a file*/

void write_a_file(char *file_name, int input)
{
    int i, num;
    FILE *fp;

    fp = open_file(file_name, WRITE_TEXT_MODE);  //Open the file for writing.

    printf("Enter the no.s");
    for (i=0; i<input; i++)                      //No. of entries specified by input variable.
    {
        scanf("%d", &num);
        putw(num,fp);
    }
    fclose(fp);
}

/*Function to check for even odd values*/

void check_for_even_odd(char *file_name)
{
    FILE *fp;
    FILE *fp_even;
    FILE *fp_odd;

    int num;

    fp = open_file(file_name, READ_TEXT_MODE);                                   //Open file for reading.
    fp_even = open_file("E:\\Fastrack C\\delete\\even.txt", WRITE_TEXT_MODE  );  //Open file for writing.
    fp_odd= open_file("E:\\Fastrack C\\delete\\odd.txt", WRITE_TEXT_MODE );      //Open file for writing.

    if(fp == NULL) printf("File not created");

    while ((num=getw(fp))!= EOF)                 //Reading the entered data in file.
    {
        if(num%2==0)                         //Checking if the entered value is even or odd.
            putw(num,fp_even);
        else
            putw(num, fp_odd);
    }
    fclose(fp);
    fclose(fp_even);
    fclose(fp_odd);
}

/*Function to display the file.*/

void display_int_file(FILE *fp)
{
    int num;
    while((num=getw(fp))!= EOF)
        printf("%4d",num);
}

int sort_even_odd_files(char *file_name, int input)
{
    // FILE *fp;
    FILE *fp_even;
    FILE *fp_odd;   //File pointer to hold reference to the file.

    write_a_file(file_name, input);            //Function call

    check_for_even_odd(file_name);       //Function call

    fp_even = open_file("E:\\Fastrack C\\delete\\even.txt", READ_TEXT_MODE  );
    display_int_file(fp_even);                                                   //Function call
    printf("\n\n");

    fp_odd= open_file("E:\\Fastrack C\\delete\\odd.txt", READ_TEXT_MODE );
    display_int_file(fp_odd);                                                     //Function call

    //fcloseall;

    return 1;
}

//5. Write a program to create telephone directory. It should include Name, address and telephone number. It should have facilities for adding, deleting, editing and searching any number. Implement using text mode.

void Add_data()
{
    /*File pointer to hold reference to the file.*/
    FILE *fp;
    Person p1;

    /*Open file to be appended.*/
    fp=open_file("E:\\Fastrack C\\delete\\directory.txt", APPEND_TEXT_MODE);

    if (fp==NULL) printf("File not created.\n");

    printf("**********Add new record**********\n");
    printf("Enter Name:");
    scanf("%s", p1.name);
    printf("Enter Address:");
    scanf("%s", p1.address);
    printf("Enter Telephone Number:");
    scanf("%u", &p1.telno);
    fprintf(fp, "%-20s %-20s %10u\n",p1.name, p1.address, p1.telno);
    fclose(fp);
}

void Delete_data()
{
    /*File pointer to hold reference to the file.*/
    FILE *fp, *fpn;
    Person p1;
    char name[20];

    /*Open file to be appended.*/
    fp=open_file("E:\\Fastrack C\\delete\\directory.txt", READ_TEXT_MODE);
    fpn=open_file("E:\\Fastrack C\\delete\\new_directory.txt", WRITE_TEXT_MODE);

    if (fp==NULL) printf("File not created.\n");

    printf("**********Delete Record***********\n");
    printf("\nEnter Name : ");
    scanf("%s",&name);

    /*Read the file with scanf and compare with the input, paste the lines that don't match into a new file (fpn).*/
    while(!feof(fp))
    {
        fscanf(fp, "%20s %20s %10u\n",p1.name, p1.address, &p1.telno);
        if(strcmpi(p1.name,name)!=0)
        {
            fprintf(fpn, "%-20s %-20s %10u\n",p1.name, p1.address, p1.telno);
        }
    }
    fclose(fp);
    fclose(fpn);

}

void findData()
{
    /*File pointer to hold reference to the file.*/
    FILE *fp;
    Person p1;
    char name[20];
    int totrec=0;

    /*Opening the file in read mode.*/
    fp=fopen("E:\\Fastrack C\\delete\\directory.txt",READ_TEXT_MODE);

    /*Read the entry to be searched.*/
    printf("*****Search Records*****\n");
    printf("\nEnter Name : ");
    scanf("%s",&name);

    /*Comparing the name with the name stroed in the file.*/
    /*Alternatively can call the findData with minor changes(i.e. print the data instead of copying the other contents onto other file)*/
    while(!feof(fp))
    {
        fscanf(fp, "%20s %20s %10u\n",p1.name, p1.address, &p1.telno);
        if(strcmpi(p1.name,name)==0)
        {
            printf("\n\nName   :  %s",p1.name);
            printf("\nTelephone No : %u", p1.telno);
            printf("\nAddress : %s", p1.address);
            totrec++;
        }
    }
    if(totrec==0)
        printf("\n\n\nNo Data Found");
    else
        printf("\n\nTotal %d Record found",totrec);
    fclose(fp);
    getch();
}

void Edit_data()
{
    FILE *fp, *fpn;
    Person p1;
    char name[20];

    /*Calling Delete_data and Add_data*/
    fp=open_file("E:\\Fastrack C\\delete\\directory.txt", READ_TEXT_MODE);
    fpn=open_file("E:\\Fastrack C\\delete\\new_directory.txt", WRITE_TEXT_MODE);

    if (fp==NULL) printf("File not created.\n");

    printf("**********Edit Record***********\n");
    printf("\nEnter Name : ");
    scanf("%s",&name);

    while(!feof(fp))
    {
        fscanf(fp, "%20s %20s %10u\n",p1.name, p1.address, &p1.telno);
        if(strcmpi(p1.name,name)!=0)
        {
            fprintf(fpn, "%-20s %-20s %10u\n",p1.name, p1.address, p1.telno);
        }
    }
    fclose(fp);

    printf("**********Add new record**********\n");
    printf("Enter Name:");
    scanf("%s", p1.name);
    printf("Enter Address:");
    scanf("%s", p1.address);
    printf("Enter Telephone Number:");
    scanf("%u", &p1.telno);
    fprintf(fpn, "%-20s %-20s %10u\n",p1.name, p1.address, p1.telno);
    fclose(fpn);
}

//6. Write a program to create telephone directory. It should include Name, address and telephone number. It should have facilities for adding, deleting, editing and searching any number. Implement using binary mode.
void Add_bindata()
{
    /*File pointer to hold reference to the file.*/
    FILE *fp;
    Person p1;

    /*Open file to be appended.*/
    fp=open_file("E:\\Fastrack C\\delete\\directory.txt", APPEND_BIN_MODE);

    if (fp==NULL) printf("File not created.\n");

    printf("**********Add new record**********\n");
    printf("Enter Name:");
    scanf("%s", p1.name);
    printf("Enter Address:");
    scanf("%s", p1.address);
    printf("Enter Telephone Number:");
    scanf("%u", &p1.telno);
    fwrite(&p1, sizeof(p1),1,fp);
    fclose(fp);
}

void Delete_bindata()
{
    /*File pointer to hold reference to the file.*/
    FILE *fp, *fpn;
    Person p1;
    char name[20];

    /*Open file to be appended.*/
    fp=open_file("E:\\Fastrack C\\delete\\directory.txt", READ_BIN_MODE);
    fpn=open_file("E:\\Fastrack C\\delete\\new_directory.txt", WRITE_BIN_MODE);

    if (fp==NULL) printf("File not created.\n");

    printf("**********Delete Record***********\n");
    printf("\nEnter Name : ");
    scanf("%s",&name);

    /*Read the file with scanf and compare with the input, paste the lines that don't match into a new file (fpn).*/
    while(fread(&p1,sizeof(p1),1,fp)!=NULL)
        if(strcmp(p1.name,name)!=0)
        {
            fwrite(&p1, sizeof(p1),1,fpn);
        }
    }
    fclose(fp);
    fclose(fpn);

}

void find_binData()
{
    /*File pointer to hold reference to the file.*/
    FILE *fp;
    Person p1;
    char name[20];
    int totrec=0;

    /*Opening the file in read mode.*/
    fp=fopen("E:\\Fastrack C\\delete\\directory.txt",READ_BIN_MODE);

    /*Read the entry to be searched.*/
    printf("*****Search Records*****\n");
    printf("\nEnter Name : ");
    scanf("%s",&name);

    /*Comparing the name with the name stroed in the file.*/
    /*Alternatively can call the findData with minor changes(i.e. print the data instead of copying the other contents onto other file)*/
    while(fread(&p1,sizeof(p1),1,fp)!=NULL)
    {
    if(strcmp(p1.name,name)!=0)
        {
            printf("\n\nName   :  %s",p1.name);
            printf("\nTelephone No : %u", p1.telno);
            printf("\nAddress : %s", p1.address);
            totrec++;
        }
    }
    if(totrec==0)
        printf("\n\n\nNo Data Found");
    else
        printf("\n\nTotal %d Record found",totrec);
    fclose(fp);
    getch();
}

void Edit_bindata()
{
    FILE *fp, *fpn;
    Person p1;
    char name[20];

    /*Calling Delete_data and Add_data*/
    fp=open_file("E:\\Fastrack C\\delete\\directory.txt", READ_BIN_MODE);
    fpn=open_file("E:\\Fastrack C\\delete\\new_directory.txt", WRITE_BIN_MODE);

    if (fp==NULL) printf("File not created.\n");

    printf("**********Edit Record***********\n");
    printf("\nEnter Name : ");
    scanf("%s",&name);

    while(fread(&p1,sizeof(p1),1,fp)!=NULL)
    {
    if(strcmp(p1.name,name)!=0)
        {
            fwrite(&p1, sizeof(p1),1,fpn);
        }
    }
    fclose(fp);

    printf("**********Add new record**********\n");
    printf("Enter Name:");
    scanf("%s", p1.name);
    printf("Enter Address:");
    scanf("%s", p1.address);
    printf("Enter Telephone Number:");
    scanf("%u", &p1.telno);
    fwrite(&p1, sizeof(p1),1,fpn);
    fclose(fpn);
}








/*int read_file_by_char_reverse(char *file_name)
{
    FILE *fp;
    char ch;
    long int len=0, index=1;

    fp = open_file(file_name, READ_TEXT_MODE);

    if(fp == NULL) return 0;

    fseek(fp, 0, SEEK_END);
    len = ftell(fp); // number of chars in a file

    while(len-- > 0)
    {
        fseek(fp, -index, SEEK_END);
        ch = fgetc(fp);

        printf("%c",ch);
        index++;
    }
    fclose(fp);

    return 1;

}*/



