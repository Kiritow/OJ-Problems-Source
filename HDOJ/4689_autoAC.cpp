#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
char a[100];
ll dp[22][22][22];
int main ()
{
    while(scanf("%s",a)!=EOF)
    {
        if(a[0]=='-')
        {
            printf("0\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[1][0][1]=1;
        int cnt=0;
        for(int i=1;i<strlen(a);++i)
        {
            if(a[i]=='-')
            {
                cnt++;
                for(int j=0;j<i;++j)
                    for(int k=0;k<=i;++k)
                {
                    if(i-j-k>0)
                        dp[i+1][j+1][k]+=dp[i][j][k]*(i-j-k);
                    if(k)
                        dp[i+1][j+1][k-1]+=dp[i][j][k]*k;
                }
            }
            else
            {
                for(int j=0;j<=i;++j)
                    for(int k=0;k<=i;++k)
                    {
                        dp[i+1][j][k+1]+=dp[i][j][k];
                        if(i-j-k>0)
                            dp[i+1][j][k+1]+=dp[i][j][k]*(i-j-k);
                        dp[i+1][j][k]+=dp[i][j][k]*k;
                    }
            }
        }
        cout<<dp[strlen(a)][cnt][0]<<endl;
    }
    return 0;
}
