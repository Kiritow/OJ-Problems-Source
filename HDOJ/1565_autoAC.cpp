#include<iostream>
using namespace std;
const int Max = 25;
int num[Max][Max];
int s[20000];
int dp[Max][20000];
void get_s()
{
     int cnt = 0;
     for (int i=0;i<(1<<20);++i)
         if ( ( i&(i<<1) )==0)
            s[cnt++] = i;
}
int main()
{
    get_s();
    int n;
    while (cin>>n)
    {
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                cin>>num[i][j];        
        memset(dp,0,sizeof(dp));
        for (int i=0;i<n;++i)
        {
             for (int j=0;s[j]<(1<<n);++j)
             {
                 for (int k=0;k<n;++k)
                     if ( ( (s[j]>>k)&1)==1 )
                          dp[i][j] += num[i][k];
                  if (i)
                  { 
                        int mx = 0; 
                        for (int k=0;s[k]<(1<<n);++k)
                            if ( (s[k]&s[j])==0 && dp[i-1][k]>mx )
                               mx = dp[i-1][k];
                        dp[i][j] += mx;
                  }
             }
        }
        int ans = 0;
        for (int i=0;s[i]<(1<<n);++i)
            ans = dp[n-1][i]>ans?dp[n-1][i]:ans;
        cout<<ans<<endl;
    }
    return 0;
}
