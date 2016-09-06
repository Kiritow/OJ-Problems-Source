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
const double INF = 1e20;
int n;
pair<int,int> p[100];
double dis(pair<int,int>a,pair<int,int>b)
{
    return sqrt((double)(1.0 * a.first - b.first) * (1.0 * a.first - b.first) + (double)(1.0 * a.second - b.second)*(1.0 * a.second - b.second));
}
double dp[55][1000];
void CheckMin(double &a,double b)
{
    a = min(a,b);
}
struct Trie
{
    int next[1000][55],fail[1000],end[1000];
    int root,L;
    int newnode()
    {
        for(int i = 1; i <= n;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(int a[],int cnt)
    {
        int now = root;
        for(int i  = 0;i < cnt;i++)
        {
            if(next[now][a[i]] == -1)
                next[now][a[i]] = newnode();
            now = next[now][a[i]];
        }
        end[now] = 1;
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 1;i <= n;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else 
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            end[now] |= end[fail[now]];
            for(int i = 1;i <= n;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void solve()
    {
        for(int i = 1;i <= n;i++)
            for(int j = 0;j < L;j++)
                dp[i][j] = INF;
        dp[1][next[root][1]] = 0;
        for(int i = 1;i < n;i++)
            for(int j = 0;j < L;j++)
                if(dp[i][j] < INF)
                {
                    for(int k = i+1;k <= n;k++)
                    {
                        int ss = next[j][k];
                        if(end[ss])continue;
                        CheckMin(dp[k][ss],dp[i][j] + dis(p[i],p[k]));
                    }
                }
        double ans = INF;
        for(int i = 0;i < L;i++)
            if(dp[n][i] < INF)
                CheckMin(ans,dp[n][i]);
        if(ans == INF)printf("Can not be reached!\n");
        else printf("%.2f\n",ans);
    }
}ac;
int a[10];
int main()
{
    int m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)break;
        for(int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].first,&p[i].second);
        ac.init();
        int k;
        while(m--)
        {
            scanf("%d",&k);
            for(int i = 0;i < k;i++)
                scanf("%d",&a[i]);
            ac.insert(a,k);
        }
        ac.build();
        ac.solve();
    }
    return 0;
}
