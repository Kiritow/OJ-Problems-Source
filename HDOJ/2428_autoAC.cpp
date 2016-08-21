#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N = 2005;
struct pp
{
    int x, y;
    friend bool operator < (pp A, pp B)
    {
        if(A.x != B.x)
        {
            return A.x < B.x;
        }
        else return A.y < B.y;
    }
} p[N];
bool mp[N][N];
int n, a[N], has[N];
vector<pp>v[N];
map<int,int>g;
void init()
{
    int tp = 0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
        a[++tp] = p[i].x;
        a[++tp] = p[i].y;
    }
    sort(a+1, a+tp+1);
    g.clear();
    tp = 0;
    for(int i=1; i<=2*n; i++)
    {
        if(g.find(a[i]) == g.end())
        {
            g[a[i]] = ++tp;
            has[tp] = a[i];
        }
        v[i].clear();
    }
    memset(mp,0,sizeof(mp));
    for(int i=1; i<=n; i++)
    {
        p[i].x = g[p[i].x];
        p[i].y = g[p[i].y];
        v[p[i].x].push_back(p[i]);
        mp[p[i].x][p[i].y] = 1;
    }
}
void solve()
{
    int x1,y1, x2, y2,s,x;
    int ans = 0;
    for(int i=1; i<=2*n; ++i)
    {
        if(v[i].size() < 2) continue;
        sort(v[i].begin(),v[i].end());
        for(int j=0; j<v[i].size(); j++)
        {
            x1 = v[i][j].x;
            y1 = v[i][j].y;
            for(int k=j+1; k<v[i].size(); k++)
            {
                x2 = v[i][k].x;
                y2 = v[i][k].y;
                s = has[y2] - has[y1];
                x = has[x1] + s;
                x = g[x];
                if(mp[x][y1] && mp[x][y2])
                    ans++;
            }
        }
    }
    printf("%d\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        init();
        solve();
    }
    return 0;
}
