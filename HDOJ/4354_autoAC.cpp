#include<cstdio>
#include<cstring>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
const int C = 5005;
const int N = 2005;
const int M = 1005;
int cnt[N]; 
int vis[C];
int dp[C][2];
int c, n, k, m;
vector<int>v[N];
struct city
{
    int x, y;
    bool operator<(const city &a) const
    {
        return x<a.x;
    }
}ct[C];
int min(int x, int y)
{
    if(x==-1) return y;
    return x<y?x:y;
}
void dfs(int s)
{
    vis[s] = 1;
    dp[s][1] = 1;
    dp[s][0] = 0;
    for(int i=0; i<v[s].size(); i++)
    {
        int ss = v[s][i];
        if(vis[ss]==1 || cnt[ss]==0) continue;
        dfs(ss);
        dp[s][1] += dp[ss][0];
        dp[s][0] += max(dp[ss][1], dp[ss][0]);
    }
}
bool ok(int l, int r)
{
    int res = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = l; i<=r; i++)
    if(vis[ ct[i].y ]==0)
    {
        dfs( ct[i].y );
        res += max( dp[ ct[i].y ][0], dp[ ct[i].y ][1] );
    }
    if(res>=k) return true;
    else return false;
}
int solve()
{
    int kk, l, r;
    kk = l = r = 1;
    cnt[ ct[1].y ]++;
    int ans = -1;
    while(r<=c)
    {
        if(kk>=k && ok(l, r))
        {
            ans = min(ans, ct[r].x - ct[l].x);
            cnt[ ct[l].y ]--;
            if( cnt[ ct[l].y ]==0 ) kk--;
            l++;
        }
        else
        {
            r++;
            cnt[ ct[r].y ]++;
            if( cnt[ ct[r].y ]==1 ) kk++;
        }
    }
    return ans;
}
int main()
{
    int t, tt=0, i, x, y;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d", &c, &n, &k, &m);
        for(i=1; i<=n; i++) v[i].clear();
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        for(i=1; i<=c; i++) scanf("%d%d", &ct[i].x, &ct[i].y);
        sort(ct+1, ct+1+c);
        for(i=1; i<=m; i++)
        {
            scanf("%d%d", &x, &y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        printf("Case #%d: %d\n", ++tt, solve());
    }
    return 0;
}
