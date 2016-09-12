#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
#define MAXN 100005
vector<int>vec[MAXN];
queue<int>q;
int n,d[MAXN];
inline double f(double a,double b)
{
    return a * b / (a + b);
}
double solve()
{
    double ans = 0;
    for(int i = n - 1;i >= max(n - 100,0);i--)
        for(int j = n - 1;j > i;j--)
            ans += f(d[i],d[j]) / (pow(2.0,n - i) - (n + 1) / pow(2.0,i));
    return ans;
}
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0;i <= n;i++)vec[i].clear();
        for(int i = 1;i < n;i++)
        {
            int u;
            scanf("%d",&u);
            vec[u - 1].push_back(i);
        }
        d[0] = 1;
        q.push(0);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0;i < vec[u].size();i++)
            {
                int v = vec[u][i];
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        sort(d,d + n);
        double ans = solve();
        printf("%.6f\n",ans);
    }
}
