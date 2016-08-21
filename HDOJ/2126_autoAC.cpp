#include <iostream>
using namespace std;
int main()
{
    int T,i,j,k;
    int N,V,v[31],dp[35][505];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&V);
        for(i=1;i<=N;i++)
            scanf("%d",&v[i]);
        memset(dp,0,sizeof(dp));
        for(j=0;j<=V;j++)
            dp[0][j]=1;
        for(i=1;i<=N;i++)
        {
            for(k=i;k>=1;k--)
            {    for(j=V;j>=v[i];j--)
                    if(dp[k-1][j-v[i]])
                        dp[k][j]+=dp[k-1][j-v[i]];
            }    
        }
        int sel=0,kind=0;
        for(i=N;i>=1;i--)
            for(j=V;j>=0;j--)
                if(dp[i][j]) {sel=dp[i][j];kind=i;goto lab;}
lab:    if(sel)
        printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n",sel,kind);
        else printf("Sorry, you can't buy anything.\n");
    }
    return 0;
}
