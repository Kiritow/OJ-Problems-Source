#include <iostream>
#include <string.h>
using namespace std;
#define MAX(a,b) (a>b?a:b)
struct Student 
{
    int j,r;
}b[110];
int a[110][110];
int main()
{
    int i,j,n,m,s,k,t,ji;
    while(~scanf("%d %d %d %d",&n,&m,&k,&s))
    {
        for(i=1;i<=k;i++)
        {
            scanf("%d %d",&b[i].j,&b[i].r);
        }
        memset(a,0,sizeof(a));
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=s;j++)
            {
                for(t=b[i].r;t<=m;t++)
                {
                    a[j][t]=MAX(a[j-1][t-b[i].r]+b[i].j,a[j][t]);
                }
            }
        }
        ji=n;
        for(i=0;i<=m;i++)
        {
            if(ji<=a[s][i])
            {
                break;
            }
        }
        if(i==m+1)printf("-1\n");
        else
        {
            printf("%d\n",m-i);
        }
    }
    return 0;
}
