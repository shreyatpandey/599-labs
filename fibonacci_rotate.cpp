#include<bits/stdc++.h>
using namespace std;

class Puzzle
{
public:
   int N,k,Y,X;
   int sum=0;
   int f0=0;
    int f1=1;
    int count;
    int new_sum;
   Puzzle()
   {

   }
  
    void read()
    {
      cout<<"Input N"<<endl;
      cin>>N;
      cout<<"Bob your answer"<<endl;
      cin>>Y;
    }
    int random()
    {
      srand(time(0));
      k=rand()%10 ;
    }

  int checkfornumber()
  {
    
      for(int i = 2;i <=N; i++)
    {
       sum = f0+f1;
       new_sum = 0;
       int j = 0;
        count = 0; 
        int c = sum;
        int m=sum;
       while(c != 0)
       {
        c = c/10;
        count++;
      }

         while(m>0 && j<=(count-1))
         {
             int onesDigit = m%10;
              m = m/10;
             onesDigit = onesDigit + k;
           while(onesDigit>=10)
          {
            onesDigit = onesDigit%10;
            }

          new_sum = new_sum + ((pow(10,j))*onesDigit);
         j++;
        }
        //cout<<new_sum<<endl;
        sum = new_sum;
        f0 =f1;
        f1=sum;
        sum = f0+f1;
       }
      return(new_sum);  
  }
  void print()
  {
     X =checkfornumber();
    if(X == Y )
      cout<<"Congratulations! Item "<<" "<<N<<" "<<" of the "<<k<<"-"<<"step rotated Fibonacci sequence is "<<Y<<"!"<<endl;
    else
      cout<<"Sorry! The"<<" "<<N<<" item "<<" of "<<k<<"-"<<"step rotated Fibonacci sequence is "<<X<<"!"<<endl;
    
  }

};


  
int main()
{
   Puzzle pz;
   pz.random();
   pz.read();
   pz.print();
   return(0);
}


