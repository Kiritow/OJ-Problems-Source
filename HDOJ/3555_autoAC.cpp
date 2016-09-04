#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long dp[20][3];
int digit[20];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1; i<20; i++)
    {
        dp[i][0] = dp[i-1][0] * 10 - dp[i-1][1];  
        dp[i][1] = dp[i-1][0]; 
        dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1]; 
    }
    int t;
    cin >> t;
    while(t--)
    {
        int len = 0,last=0;
        long long ans = 0;
        unsigned long long n=0;
        cin >> n;
        n++;
        memset(digit,0,sizeof(digit));
        while(n)
        {
            digit[++len] = n%10;
            n/=10;
        }
        bool flag = false;
        for(int i =len; i>=1; i--)
        {
            ans += dp[i-1][2] * digit[i];
            if(flag)
                ans += dp[i-1][0] * digit[i];
            if(!flag && digit[i] >4)
                ans += dp[i-1][1];
            if(last == 4 && digit[i] == 9)
                flag = true;
            last = digit[i];
        }
        cout << ans << endl;
    }
    return 0;
}
