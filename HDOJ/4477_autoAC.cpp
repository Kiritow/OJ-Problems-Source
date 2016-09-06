#include <stdio.h>  
#define N 50000  
#define M 1000000  
#define K 316  
int main()  
{  
    int dp[2][N+2];  
    int ans[N+2];  
    for(int i=3;i<=N;i++)  
    {  
        ans[i]=dp[0][i]=dp[0][i-2]+1;  
    }  
    for(int k=3;k<=K;k++)  
    {  
        int *p1=dp[k&1];int *p2=dp[(k+1)&1];  
        for(int i=0;i<=k*(k+1)/2-1;i++) p1[i]=0;  
        for(int i=k*(k+1)/2;i<=N;i++)  
        {  
            p1[i]=p1[i-k]+p2[i-k];  
            if(p1[i]>=M)  
            p1[i]-=M;  
            ans[i]+=p1[i];  
            if(ans[i]>=M)  
            ans[i]-=M;  
        }  
    }  
    int t,n;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        printf("%d\n",ans[n]);  
    }  
}
