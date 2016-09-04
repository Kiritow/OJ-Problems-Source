#include <iostream>
using namespace std;
char a[11][100]={"Yu Jian","Tin O O","I Missed","Stefanie","The Same","About","Honey Honey","Unfinished","Hey Jude","When Winter Fades"};
void fun(int i)
{
 if(i>0 && i<6)
  cout<<a[i-1]<<endl;
 else if(i>7 && i<13)
  cout<<a[i-3]<<endl; 
}
int main()
{
 int t,n;
 cout<<"Best wishes to Stefanie\n\n";
 cin>>t;
 while(t--)
 {
  cin>>n;
        if(n<14)
   fun(n);
  else 
   fun(n%14);
 }
 return 0;
}
