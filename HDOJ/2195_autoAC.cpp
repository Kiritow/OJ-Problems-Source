#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX=250;
int L;
char s[MAX];
int dp[MAX][1010];
void gs()
{
    int i,j;
    int tt=s[1]=='0'?0:1000;
    for(i=0;i<=1000;i++) dp[1][i]=(tt-i)*(tt-i);
    int small;
    for(i=2;i<=L;i++)
    {
        small=0x5fffffff;
        tt=s[i]=='0'?0:1000;
        for(j=0;j<=1000;j++)
        {
            if(small>dp[i-1][j]) small=dp[i-1][j];
            dp[i][j]=small+(tt-j)*(tt-j);
        }
    }
}
int main()
{
    while(scanf("%s",s+1)==1)
    {
        L=strlen(s+1);
        gs();
        int ans=0x5fffffff;
        for(int i=0;i<=1000;i++) ans=min(ans,dp[L][i]);
        double aa=(double)ans/1000000;
        printf("%.3lf\n",aa);
    }
    return 0;
}
