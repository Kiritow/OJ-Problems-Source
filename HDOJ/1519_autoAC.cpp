#include<iostream>
using namespace std;
int main()
{
  int size;
  cin>>size;
  for(int l=0;l<size;l++)
 {
   int  n;
   cin>>n;
   int sum=0;
   for(int i=0;i<n;i++)
    {
      int temp;
      cin>>temp;
      sum+=temp;
    }
    if(sum>=0)
    cout<<sum<<endl;
     else cout<<0<<endl;
 }
}
