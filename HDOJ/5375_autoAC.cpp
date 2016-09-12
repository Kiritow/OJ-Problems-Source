#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
const int maxn = 2e5+10 ;
const int inf = 0x3f3f3f3f ;
int dp[maxn][2] ;
char str[maxn] ;
int a[maxn] ;
int main()
{
    int t  ;int cas = 0 ;
    scanf("%d" , &t) ;
    while(t--)
    {
        scanf("%s" , str) ;
        int n = strlen(str) ;
        for(int i = 0 ;i < n;i++)
        scanf("%d" , &a[i]) ;
        dp[0][1] = dp[0][0] = -inf ;
        if(str[0] == '1' || str[0] == '?')
            dp[0][1] = a[0] ;
        if(str[0] == '0' || str[0] == '?')
            dp[0][0] = 0 ;
        for(int i = 1;i < n;i++)
        {
            dp[i][0] = dp[i][1] = -inf ;
            if(str[i] == '0' || str[i] == '?')
            dp[i][0] = max(dp[i-1][0] , dp[i-1][1] + a[i]) ;
            if(str[i] == '1' || str[i] == '?')
            dp[i][1] = max(dp[i-1][1] , dp[i-1][0] + a[i]) ;
        }
        printf("Case #%d: " , ++cas) ;
        cout<<max(dp[n-1][0] , dp[n-1][1])<<endl;
    }
    return 0 ;
}
