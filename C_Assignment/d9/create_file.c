/*c code to create new files

#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000

int main()
{
    char data[SIZE];  //To store user content.

     FILE * fp;       //File pointer to hold reference to the file.

     fp= fopen("first.txt", "w");

     if(fp== NULL)
     {
         printf("Unable to create file\n");
         exit(EXIT_FAILURE);
         }  //File not created.

     printf("Enter contents to store in file : \n");
     fgets(data, SIZE, stdin);
     fputs(data,fp);    // Enter data to file.
     fclose(fp);
     printf("File created and saved successfully.\n");

     return 0;

} */


