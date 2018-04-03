#include<stdio.h>
#include<stdlib.h>

int trailing_zero(long int input) /*Done with the help from geekforgeeks */
{
   int count_of_zeros;
   count_of_zeros=0;
	while(input>0)
	{
	  input=input/5;
	  count_of_zeros = count_of_zeros + input;

	}
return(count_of_zeros);

}



int main(int argc,char *argv[])
{
	int answer;
	if(argv[1]==NULL)
	{
	   printf("there is no input\n");
	}
	char *a = argv[1];
  unsigned long int input = atoi(a);
   if(input<0)
   {
        printf("No cannot be negative\n");
   }
   if(input<100)
   {
       printf("Test case is for no greater than 100\n");
   }
  answer=trailing_zero(input);
  printf("No of trailing zeros are:%d\n",answer);

}
