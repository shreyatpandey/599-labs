#include<bits/stdc++.h>
using namespace std;

class input
{
  public:
  	long n,result1,result2,square,calc1,calc2,p,q;
  	input()
  	{
    
    }
};

class checkfibonacci:public input
{
   
   	public:
    checkfibonacci()
    {

    }
    void initialize(int value)
   { 
   	  n = value;
     }
		
    int fib_check() /* taken from stackoveflow */
    {
        square = pow(n,2);
        calc1 = (5*square) + 4;
        calc2 = (5*square) - 4;
        result1 = sqrt(calc1);
        result2 = sqrt(calc2);
        p = pow(result1,2);
        q = pow(result2,2);
       if((p==calc1)||(q==calc2))
       	return (1);
       else
       	return(0);
    }


};

int main()
{
   int result;
   int value;
   checkfibonacci fb;
   cout<<"Input n"<<endl;
   cin>>value;
   fb.initialize(value);
   result = fb.fib_check();
   if(result == 1)
   	cout<<value<<" "<<"is a fibonacci number"<<endl;
   if(result == 0)
   	cout<<value<<" "<<" is not a fibonacci number"<< endl;
   return (0);


}