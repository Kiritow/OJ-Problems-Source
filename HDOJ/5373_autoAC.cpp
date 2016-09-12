#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <malloc.h>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define MAX 999999999
#define LL long long
#define M 6666666
using namespace std;
int main()
{
    int n,m,i,j,k,l,cas=1;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==-1&&m==-1)break;
         if(m==0)
         {
              if(n%11==0)printf("Case #%d: Yes\n",cas++);
            else printf("Case #%d: No\n",cas++);
            continue;
         }
        k=n;
        l=0;
        while(k>0)
        {
            l+=k%10;
            k/=10;
        }
        while(m--)
        {
            k=l;
            while(k>0)
            {
                k/=10;
                n*=10;
            }
            n=(n+l)%11;
            k=l;
            while(k>0)
            {
                l+=k%10;
                k/=10;
            }
        }
        if(n==0)printf("Case #%d: Yes\n",cas++);
        else printf("Case #%d: No\n",cas++);
    }
    return 0;
}
