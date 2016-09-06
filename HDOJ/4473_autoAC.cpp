#include<iostream>
#include<stdio.h>
#include<string.h>
#include<set>
#include <stack>
#include<queue>
#include<algorithm>
#include<cmath>
#define oo 1000000007
#define MAXN 100005
#define ll long long
#define pi acos(-1.0) 
using namespace std;    
ll n,i,j,k,ans=0;
int main()
{         
      int cases=0; 
      while (~scanf("%I64d",&n))
      {
              ans=0;
              for (i=1;i*i*i<=n;i++) ans++;
              for (i=1;i*i<=n;i++)
              {
                      k=n/i/i;
                      if (k>=i) ans+=(k-1)*3; 
                           else ans+=k*3;
              }
              for (i=1;i*i*i<=n;i++) 
                 for (j=i+1;j<=n;j++)
                 {
                          k=n/i/j;
                          if (k>j) ans+=(k-j)*6; 
                              else break;
                 } 
              printf("Case %d: %I64d\n",++cases,ans);
      }
      return 0;
}
