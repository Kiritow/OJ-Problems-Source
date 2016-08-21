#include<iostream>
using namespace std;
const int maxn=32;
int arr[maxn]={0,1,3};
void func( void )
{
    for(int i=3;i<=maxn;i++ )
       arr[i]=arr[i-1]+2*arr[i-2];
}
int main( void )
{
   int t,n;
   func();
   cin>>t;
   while(t--)
   {
       cin>>n;
      cout<<arr[n]<<endl;
   }
   return 0;
}
