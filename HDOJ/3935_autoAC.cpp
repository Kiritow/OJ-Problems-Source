#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 105
int g[maxn];
int x[maxn];
int n,m;
int inf=100*100;
int all;
int Get(int n)
{
     n=(n&0x55555555)+((n>>1)&0x55555555);  
     n=(n&0x33333333)+((n>>2)&0x33333333);  
     n=(n&0x0f0f0f0f)+((n>>4)&0x0f0f0f0f);  
     n=(n&0x00ff00ff)+((n>>8)&0x00ff00ff);  
     n=(n&0x0000ffff)+((n>>16)&0x0000ffff);  
     return n;
}
void heng(int &x,int i)
{
    x^=i;x^=i<<1;x^=i>>1;  
    x=x&all;
}
int main()
{
    int i, j,k;
    while(scanf("%d%d", &n,&m) != EOF)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                int tmp;
                scanf("%d",&tmp);
                g[i]=g[i]<<1|tmp;
            }
        }
        all=(1<<m)-1;
        int ans=inf;
        for(i=0;i<(1<<m);i++)
        {    
            for(k=0;k<n;k++)x[k]=g[k];
            int t=Get(i);
            heng(x[0],i);
            x[1]^=i;
            for(j=1;j<n;j++)
            {
                int k=x[j-1]^all;
                heng(x[j],k);
                x[j+1]^=k;
                t+=Get(k);
            }
            if(t<ans&&x[n-1]==all)ans=t;
        }
        if(ans==inf)printf("no solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}
