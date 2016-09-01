#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#define cler(arr, val)    memset(arr, val, sizeof(arr))
typedef long long  LL;
const int MAXN = 15;
const int MAXM = 6000010;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
int val[MAXN],cost[1<<MAXN],E[MAXN],last[MAXN];
int dp[1<<MAXN];
vector<int>G[MAXN];
int n,m;
void init()
{
    cler(last,0);
    cler(cost,0);
    cler(dp,-1);
    for(int i=0;i<n;i++)
        G[i].clear();
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
                cost[i]+=E[j];
        }
    }
}
bool ok(int x,int p)
{
    if((x&last[p])==last[p]&&cost[x]+E[p]<=m)
        return true;                        
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>val[i];
        for(int i=0;i<n;i++) cin>>E[i];
        init();
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d",&x);
            while(x--)
            {
                cin>>y;
                y--;
                last[i]|=1<<y;
            }
        }
        int ans=0;
        dp[0]=0;
        for(int i=0;i<(1<<n);i++)
        {
            if(dp[i]==-1) continue;
            for(int j=0;j<n;j++)
            {
                if(ok(i,j)&&(i&(1<<j))==0)
                {
                    dp[(1<<j)|i]=dp[i]+val[j];
                    ans=max(dp[(1<<j)|i],ans);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
