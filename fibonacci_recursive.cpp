#include<bits/stdc++.h>
using namespace std;

class input
{
protected:
	int m,n,p;
};
class recursive:public input
{
	public:
	recursive()
	{

	}
  public:
  	int fibo_recur(int n)   /*Taken from geeks for geeks */
  	{
      if (n<=1)
      	return (n);
      else
      	return fibo_recur(n-1) + fibo_recur(n-2);

  	}


};

int main()
{
    int value;
    cout<<"Input the no of terms"<<endl;
    cin>>value;
    recursive r;
    int result = r.fibo_recur(value);
    cout<<"Ouput:"<<" "<<result<<endl;

  return(0);

}