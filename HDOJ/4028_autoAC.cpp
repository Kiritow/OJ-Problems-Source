#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#define LL long long
using namespace std;
LL m;int n;
typedef map <LL,LL> mp;
mp dp[45];
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a*b/gcd(a,b);
}
void DP()
{
        dp[1][1]=1;
    for(int i=2;i<=40;i++)
    {
        dp[i]=dp[i-1];
        dp[i][i]+=1;
        for(mp::iterator j=dp[i-1].begin();j!=dp[i-1].end();j++)
        {
            LL lc=lcm(i,j->first);
            dp[i][lc]+=j->second;
        }
    }
}
void ANS()
{
    LL ans=0;
    for(mp::iterator i=dp[n].begin();i!=dp[n].end();i++)
        if(i->first>=m)ans+=i->second;
    cout<<ans<<'\n';
}
int main()
{
    int T,t;
    DP();
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        cin>>n>>m;
        printf("Case #%d: ",t);
        ANS();
    }
    return 0;
}
