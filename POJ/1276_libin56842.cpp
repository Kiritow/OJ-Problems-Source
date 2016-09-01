#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct node
{
    int n,v;
} a[20];

int dp[100010];

int main()
{
    int sum,n,i,j,k;
    while(~scanf("%d%d",&sum,&n))
    {
        for(i = 1; i<=n; i++)
            scanf("%d%d",&a[i].n,&a[i].v);
        if(!sum)
        {
            printf("0\n");
            continue;
        }
        if(!n)
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int MAX = 0,tem;
        for(i = 1; i<=n; i++)
        {
            for(j = MAX;j>=0;j--)
            {
                if(dp[j])
                {
                    for(k = 1;k<=a[i].n;k++)
                    {
                        tem = j+k*a[i].v;
                        if(tem>sum)
                        continue;
                        dp[tem] = 1;
                        if(tem>MAX)
                        MAX = tem;
                    }
                }
            }
        }
        printf("%d\n",MAX);
    }

    return 0;
}
