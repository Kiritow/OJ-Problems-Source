#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
const int MAX=100+5;
int a[MAX][MAX];
int b[MAX];
void dfs(int j,int jj,int num,int n)
{
    for(int k=jj;k<=n;k++)
    {
        if(a[j][ k ])
        {
            b[num]++;
            dfs(k,1,num,n);
        }
    }
}
int main()
{
    int n,k;
    while(~scanf("%d %d",&n,&k))
    {
        int ans=0;
        int A,B;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&A,&B);
            a[A][B]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j])
                {
            b[i]++;
                    dfs(j,1,i,n);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]==k)
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
