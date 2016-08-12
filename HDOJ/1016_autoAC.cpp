#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int ans[25];
int f[25];
int n;
int isprime(int x)
{
    for(int i=2;i<=x/2;i++)
    {
            if(x%i==0)
                      return 0;
    }
    return 1;
}
void dfs(int k,int now)
{
    if(k==n)
    {
            if(isprime(now+1))
            {
                              ans[k]=now;
                              for(int i=0;i<n;i++)
                              {
                                      printf("%d%c",ans[i],i==n-1?'\n':' ');
                              }
            }
            return;
    }
    for(int i=2;i<=n;i++)
    {
            if(!f[i]&&isprime(now+i))
            {
                                     f[i]=1;
                                     ans[k]=i;
                                     dfs(k+1,i);
                                     f[i]=0;
            }
    }
}
int main()
{
    int ncas=1;
    while(scanf("%d",&n)!=EOF)
    {
                              printf("Case %d:\n",ncas++);
                              memset(f,0,sizeof(f));
                              ans[0]=1;
                              dfs(1,1);
                              putchar('\n');
    }
    return 0;
}
