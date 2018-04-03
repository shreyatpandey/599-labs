#include<stdio.h>
#include<stdlib.h>

typedef struct Interval
{
   int start;
   int end;
	
}interval;



int main()
{
   interval array[] = {{4,2},{5,1},{11,6},{15,13}}; 

  int sizeofarray = sizeof(array)/sizeof(array[0]);
  printf("Size of the array is\n");
  printf("%d\n",sizeofarray);
  int* returnsize;
  merge(array,sizeofarray,returnsize);

return(0);

}


