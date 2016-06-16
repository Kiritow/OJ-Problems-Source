#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
  int a[1001],n,m,i;
  memset(a,0,sizeof(a));
  cin>>n;
  int count=0;
  for(i=1;i<=n;i++)
  {
    cin>>m;
    a[m]++;
  }
  for(i=1;i<=1000;i++)
    if(a[i]!=0)  count++;
  cout<<count<<endl;
  for(i=1;i<=1000;i++)
    if(a[i]!=0)  cout<<i<<' ';
  return 0;
}

/**
100 765
19485
*/
