#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXN 11000
int n, sum[MAXN], num[MAXN],tn[MAXN];
void init()
{
    int i;
    for (i = 1; i * 2 <= n * (n - 1); ++i) 
        scanf("%d", &sum[i]);
}
void work()
{
    int i,j,k;
    for (num[1] = 1; num[1] * 2 <= sum[1]; ++num[1])
    {
        j=2;
        memset(tn, 0, sizeof(tn));
        for(i=1;i*2<=n*(n-1);i++)
        {
            tn[sum[i]]++;
        }
        for(i=1;i*2<=n*(n-1);i++)
        {
            if(tn[sum[i]]>0)
            {
                num[j]=sum[i]-num[1];
                for(k=1;k<j;k++)
                {
                    if(tn[num[k]+num[j]]==0)
                        break;
                    else
                        tn[num[k]+num[j]]--;
                }
                if(k==j)
                    j++;
                else
                    break;
            }
        }
        if(j>n)
            break;
    }
    if(j<=n)
        return ;
    for(i=1;i<n;i++)
        printf("%d ",num[i]);
    printf("%d\n",num[n]);
}
int main()
{
    while (scanf("%d", &n) != EOF && n)
    {
        init();
        work();
    }
    return 0;
}
