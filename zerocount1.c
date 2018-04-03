#include<stdio.h>
#include<stdlib.h>



long int compareresult(long int no_of_twos,long int no_of_fives)
{
   if(no_of_fives<no_of_twos)
   	return(no_of_fives);
   else
   	return(no_of_twos);

}

long int zeros(long int input)
{
   long int count_of_twos;
   count_of_twos = 0;
   while((input%2)==0)
   {
     input=input/2;
     count_of_twos = count_of_twos + 1;
    }
  long int start_three = input;
  while((start_three%3)==0)
  {
  	start_three = start_three/3;
  }
   long int start_five = start_three;
   long int count_of_fives = 0;
   while((start_five % 5)==0)
   {
     start_five = start_five/5;
     count_of_fives = count_of_fives + 1;
    }
   long int result = compareresult(count_of_twos,count_of_fives);
   return(result);

}


int main(int argc,char *argv[])
{
	long int answer;
	if(argv[1]==NULL)
	{
	   printf("there is no input\n");
	}
	char *a = argv[1];
  unsigned long int input = atoi(a);
   if(input<0)
   {
        printf("No cannot be negative\n");
        exit(0);
   }
   long int i;
   long int factorial=1;
   for(i=1;i<=input;i++)
   {
     factorial=factorial*i;  
   }
   
   if(input>10)
   {
       printf("This program is for very small numbers \n");
       exit(0);
   }
   
   answer=zeros(factorial);
  printf("No of trailing zero is %ld\n",answer);

return(0);

}