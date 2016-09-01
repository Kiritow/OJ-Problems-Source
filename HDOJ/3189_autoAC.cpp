#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#define maxn 1005
using namespace std;
int a[maxn];
void csh()
{
    int i;
    for(int i=1;i<=1000;i++)
    {
        int p=(int) sqrt(i);
        for(int j=1;j<=p;j++)
        {
            if(i%j==0)
            {
                if(j==i/j)
                a[i]++;
                else
                a[i]+=2;
            }
        }
    }
}
int answer(int b)
{
    for(int i=1;i<=1000;i++)
    {
      if(a[i]==b)
      return i;
    }
    return -1;
}
int main()
{
    int t;
    memset(a,0,sizeof(a));
    csh();
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int ans=answer(k);
        cout<<ans<<endl;
    }
    return 0;
}
