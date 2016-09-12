#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX = 1000000+50;
int arr[MAX],prime[MAX];
int dp[MAX][9];
void init()
{
    int n=1000000;
    int flag = 0;
    prime[2]=1;
    for(int i=3;i<=n;i++)
    {
        if(i%2==0)
        {
            flag=1;
        }
        else
        {
            for(int j=3;j*j<=i;j=j+2)
            {
                if(i%j==0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag==0)
        {
            prime[i]=1;
        }
        flag=0;
    }
    for(int i = 2;i<=n;i++)
    {
        if(prime[i])
        {
            for(int j=i;j<=n;j+=i)
            {
                arr[j]++;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        dp[i][arr[i]]++;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<8;j++)
        {
            dp[i][j]+=dp[i-1][j];
        }
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int L,R;
        scanf("%d %d",&L,&R);
        int ans=1;
        for(int j=2;j<8;j++)
        {
            if(dp[R][j]-dp[L-1][j]>=2)
            {
                ans=max(ans,j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
