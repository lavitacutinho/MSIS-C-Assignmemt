/*void write_a_file(char *file_name)
{
    int i, num;

    FILE *fp;

      fp = open_file(file_name, WRITE_TEXT_MODE);

      printf("Enter the no.s");
    for (i=0;i<10;i++)
    {
        scanf("%d", &num);
        putw(num,fp);
    }
    fclose(fp);
}
int sort_even_odd_files(char *file_name)
{
    FILE *fp;
    FILE *fp_even;
    FILE *fp_odd;   //File pointer to hold reference to the file.

    write_a_file(file_name);



    fp = open_file(file_name, READ_TEXT_MODE);                                   //Open file for reading.
    fp_even = open_file("E:\\Fastrack C\\delete\\even.txt", WRITE_TEXT_MODE  );  //Open file for writing.
    fp_odd= open_file("E:\\Fastrack C\\delete\\odd.txt", WRITE_TEXT_MODE );      //Open file for writing.

	if(fp == NULL) return 0;

while ((num=getw(fp))!= EOF)                    // sizeof(num), fp))
{

    	if(num%2==0)
			putw(num,fp_even);
		 	else
                putw(num, fp_odd);
        }
        fclose(fp);
	fclose(fp_even);
	fclose(fp_odd);

	fp_even = open_file("E:\\Fastrack C\\delete\\even.txt", READ_TEXT_MODE  );
	while((num=getw(fp_even))!= EOF)
        printf("%4d",num);
 printf("\n\n");
    fp_odd= open_file("E:\\Fastrack C\\delete\\odd.txt", READ_TEXT_MODE );      //Open file for writing.
   while((num=getw(fp_odd))!= EOF)
        printf("%4d",num);
  fcloseall;

	return 1;



} */

