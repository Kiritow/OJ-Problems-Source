#pragma comment(linker, "/STACK:16777216")
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define hash hhhhhhh
#define end eeeeend
#define maxn 50010
const lint mod = 1e9 + 7;
const lint A = 233, P = 23333, Q = 1e9 + 1027, B = 50009;
int n, m;
int dis[maxn];
bool flag;
vector<int> dia;
int start, end;
lint hash[maxn], cnt[maxn];
int idx[maxn];
lint fac[maxn];
vector<int> G[maxn];
int center;
void dfs(int now, int fa)
{
    int nex;
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
    {
        dis[nex] = dis[now] + 1;
        dfs(nex, now);
    }
    return;
}
bool getDiameter(int now, int fa)
{
    int nex;
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
        if(getDiameter(nex, now))
        {
            dia.push_back(now);
            return true;
        }
    if(now == end)
    {
        dia.push_back(now);
        return true;
    }
    return false;
}
void diameter()
{
    dis[1] = 0;
    dfs(1, -1);
    start = 1;
    for(int i = 1; i <= n; i++)
        if(dis[start] < dis[i]) start = i;
    dis[start] = 0;
    dfs(start, -1);
    end = start;
    for(int i = 1; i <= n; i++)
        if(dis[end] < dis[i]) end = i;
    dia.clear();
    getDiameter(start, -1);
    if(dis[end] & 1)
    {
        flag = true;
        int centerLeft = dia[(dia.size() >> 1) - 1];
        int centerRight = dia[dia.size() >> 1];
        center = n + 1;
        G[center].push_back(centerLeft);
        G[center].push_back(centerRight);
        for(int i = 0, sz = G[centerLeft].size(); i < sz; i++)
            if(G[centerLeft][i] == centerRight)
            {
                G[centerLeft][i] = center;
                break;
            }
        for(int i = 0, sz = G[centerRight].size(); i < sz; i++)
            if(G[centerRight][i] == centerLeft)
            {
                G[centerRight][i] = center;
                break;
            }
    }
    else
        center = dia[dia.size() >> 1];
    return;
}
lint quick(lint base, lint pow)
{
    lint ret = 1;
    while(pow)
    {
        if(pow & 1) ret = ret*base % mod;
        base = base*base % mod;
        pow >>= 1;
    }
    return ret;
}
lint C(int x, int y)
{
    lint ret = 1;
    for(int i = 1; i + x - y <= x; i++)
        ret = ret*(x - y + i) % mod;
    ret = ret*quick(fac[y], mod - 2) % mod;
    return ret;
}
bool cmp(int x, int y)
{
    return hash[x] < hash[y];
}
void calc(int now, int fa)
{
    int nex;
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
        calc(nex, now);
    if(G[now].size() == 1)
    {
        hash[now] = A*B % Q;//hash间负A*B % Q
        cnt[now] = m;
        return;
    }
    hash[now] = A*B % Q;
    cnt[now] = m;
    int num = 0;
    for(int i = 0, sz = G[now].size(); i < sz; i++) if((nex = G[now][i]) != fa)
        idx[num++] = nex;
    sort(idx, idx + num, cmp);
    for(int i = 0; i < num; i++)
    {
        nex = idx[i];
        hash[now] *= P;
        hash[now] ^= hash[nex];
        hash[now] %= Q;
    }
    hash[now] = hash[now] * B % Q;
    int st = 0;
    while(st < num)
    {
        lint val = hash[idx[st]];
        lint kinds = cnt[idx[st]];
        lint count = 1;
        st++;
        while(st < num && val == hash[idx[st]])
            count++, st++;
        cnt[now] = cnt[now] * C(kinds + count - 1, count) % mod;
    }
    return;
}
int main()
{
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 1; i <= n + 1; i++) G[i].clear();
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        flag = false;
        diameter();
        calc(center, -1);
        if(flag)
            printf("%I64d\n", cnt[center] * quick(m, mod - 2) % mod);
        else printf("%I64d\n", cnt[center]);
    }
    return 0;
}
