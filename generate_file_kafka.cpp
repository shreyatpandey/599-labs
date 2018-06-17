#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;


int main()
{

  int rand_number = 0;
  int file_selection_number = 0;
  srand(time(NULL));
   
  for(int i=0;i<20;i++)
  {  
      
      rand_number = rand()%10001;
      string name="file_" + to_string(i+1) + ".txt"; 
      string path = "/home/student/Downloads/kafka_2.11-1.1.0/lab10/" + name;
   /*ofstream output("/home/student/Downloads/kafka_2.11-1.1.0/lab10/name");*/
      ofstream output(path);
      file_selection_number = rand()%3;
      
      switch(file_selection_number)
      {
        case 0:  
                {string s1="Topic-1";
                 output<<s1<<endl;
                 }
                 break;
        
        case 1:
                 {string s2="Topic-2";
                 output<<s2<<endl;
                 }
                 break;         
        
        case 2: {
                 string s3="Topic-3";
                 output<<s3<<endl;
                 }
                 break;         
          
       }
       
      output<<rand_number<<endl;
      sleep(5);
  }   
   return 0;
  }
  
