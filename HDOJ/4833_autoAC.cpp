#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct NN1
{
    int d,e;
    void input()
    {
        scanf("%d%d",&d,&e);
    }
}node1[3000];
struct NN2
{
    int start,finish;
    int r;
    void input()
    {
        scanf("%d%d%d",&start,&finish,&r);
    }
}node2[3000];
int a[5010];
long long f[100010];
long long f2[5010];
int dp[5010];
vector<int>vec[5010];
vector<int>vec2[5010];
int main()
{
    int T;
    int iCase = 0;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        printf("Case #%d:\n",iCase);
        scanf("%d%d",&n,&m);
        int cnt = 0;
        memset(f,0,sizeof(f));
        for(int i = 0;i < n;i++)
        {
            node1[i].input();
            f[node1[i].d] += node1[i].e;
        }
        for(int i = 1;i <= 100000;i++)
            f[i] += f[i-1];
        for(int i = 0;i < m;i++)
        {
            node2[i].input();
            a[cnt++] = node2[i].start;
            a[cnt++] = node2[i].finish;
        }
        sort(a,a+cnt);
        cnt = unique(a,a+cnt) - a;
        map<int,int>mp;
        for(int i = 0;i < cnt;i++)
            mp[a[i]] = i;
        f2[0] = f[a[0]];
        for(int i = 1;i < cnt;i++)
            f2[i] = f[a[i]] - f[a[i-1]];
        for(int i = 0;i < cnt;i++)
        {
            vec[i].clear();
            vec2[i].clear();
        }
        for(int i = 0;i < m;i++)
        {
            node2[i].start = mp[node2[i].start];
            node2[i].finish = mp[node2[i].finish];
            vec[node2[i].start].push_back(node2[i].finish);
            vec2[node2[i].start].push_back(node2[i].r);
        }
        memset(dp,0,sizeof(dp));
        for(int i = cnt-1;i >= 0;i--)
        {
            dp[i] = dp[i+1];
            int sz = vec[i].size();
            for(int j = 0;j < sz;j++)
                dp[i] = max(dp[i],dp[vec[i][j]] + vec2[i][j]);
        }
        long long ans ;
        ans = 0;
        for(int i = 0;i < cnt;i++)
        {
            ans += (long long)dp[i]*f2[i];
        }
        printf("%.2lf\n",(double)ans/100);
    }
    return 0;
}
