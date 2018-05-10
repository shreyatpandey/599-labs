/*Give a nxn matrix where n is even, find a pooling layer matrix */

#include<bits/stdc++.h>
using namespace std;
int Max = 0;
int Rows=0; int Cols=0;


int Maximum(int m, int n, int p,int q)
{
  int max = m;
   if(n>max)
      max =n;
    if(p>max)
     max =p;
   if(q>max)
     max = q;
   return max;
  }


void pooling(int **A,int m,int n)
{
   int sub[m/2][n/2];
   int k=0;
   int sub_size = (m*n)/2;
   int arr_sub[sub_size];
   for(int i=0;i<m;i=i+2)
   {
     for(int j=0;j<n;j=j+2)
    {
      int value_insert = Maximum(A[i][j],A[i][j+1],A[i+1][j],A[i+1][j+1]);
      arr_sub[k] = value_insert;
      k++;
    }
  }
 int kstart =0;
for(int m=0;m<Rows/2;m++)
 {
    for(int n=0;n<Cols/2;n++)
    {
      cout<<arr_sub[kstart]<<" ";
      kstart++;
     }
  cout<<endl;
 }

}

int main()
{
   cout<<"Input Rows"<<endl;
   cin>>Rows;
   cout<<"Input Cols"<<endl;
   cin>>Cols;

   int** Arr = new int*[Rows];
   for(int i=0;i<Rows;i++)
   {
     Arr[i] = new int[Cols];
    }
   cout<<"Input elements in array"<<endl;
   int value;
   for(int i=0;i<Rows;i++)
   {
     for(int j=0;j<Cols;j++)
     {
       cin>>value;
       Arr[i][j] = value;
      }
    }
  cout<<"Elements in matrix form:"<<endl;
   for(int i=0;i<Rows;i++)
   {
     for(int j=0;j<Cols;j++)
     {
       cout<<Arr[i][j]<<" ";
      }
    cout<<endl;
   }
cout<<"Pooling matrix is:"<<endl;
   pooling(Arr,Rows,Cols);
  return 0;
}


