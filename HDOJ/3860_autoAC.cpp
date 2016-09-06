#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define SIZE 250
#define Max 0x7fffffff
struct edge{int to, next, val;}e[10000000];
int t, n, m, P, O, g[SIZE * SIZE][4];
pair<int, int> o[SIZE], p[SIZE];
int mo[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int v[SIZE * SIZE], cnt, len[SIZE * SIZE], dis[SIZE * SIZE];
int que[10000000], vst[SIZE * SIZE], n2, m2, pst, ost;
int GetMove(int a, int b, int c, int d)
{
    if (c < a) return 0;
    if (c > a) return 1;
    if (d < b) return 2;
    return 3;
}
bool judge(int a, int b){return a >= 0 && a < n && b >= 0 && b < m;}
void insert(int from, int to, int val)
{
    e[cnt].val = val; e[cnt].to = to; e[cnt].next = v[from];
    v[from] = cnt++;
    e[cnt].val = val; e[cnt].to = from; e[cnt].next = v[to];
    v[to] = cnt++;
}
int spfa(int s, int t)
{
    memset(dis, -1, sizeof(dis));
    memset(vst, 0, sizeof(vst));
    int head = 0, tail = 0;
    dis[s] = 0;
    que[tail++] = s; vst[s] = 0;
    while(head < tail)
    {
        int id = que[head++];
        vst[id] = 0;
        for(int i = v[id]; i != -1; i = e[i].next)
        {
            if (dis[e[i].to] == -1 || dis[id] + e[i].val < dis[e[i].to])
            {
                dis[e[i].to] = dis[id] + e[i].val;
                if (!vst[e[i].to])
                {
                    vst[e[i].to] = 1;
                    que[tail++] = e[i].to;
                }
            }
        }
    }
    return dis[t];
}
void build_graph(int mid, int s, int t)
{
    memset(v, -1, sizeof(v)); cnt = 0;
    for(int i = 0; i < P - 1; i++)
    {
        int pre, next;
        if (i == 0) pre = s; else pre = pst + i - 1;
        if (i == P - 2) next = t; else next = pst + i + 1;
        insert(pre, pst + i, p[i].second);
        insert(pst + i, next, p[i + 1].second);
        int from = p[i].first, to = p[i + 1].first;
        for(int j = from; j < to; j++)
        {
            int tmp = j * m2;
            int val = g[j * m][1];
            if (val == -1) val = 0;
            val = min(val, len[mid]);
            insert(pst + i, tmp, val);
        }
    }
    for(int i = 0; i < O - 1; i++)
    {
        int pre, next;
        if (i == 0) pre = s; else pre = ost + i - 1;
        if (i == O - 2) next = t; else next = ost + i + 1;
        insert(pre, ost + i, o[i].second);
        insert(ost + i, next, o[i + 1].second);
        int from = o[i].first, to = o[i + 1].first;
        for(int j = from; j < to; j++)
        {
            int tmp = j * m2 + m2 - 1;
            int val = g[j * m + m - 1][1];
            if (val == -1) val = 0;
            val = min(val, len[mid]);
            insert(ost + i, tmp, val);
        }
    }
    for(int i = 0; i < m2; i++)
    {
        int val = g[i][3];
        if (val == -1) val = 0;
        val = min(val, len[mid]);
        insert(s, i, val);
        val = g[(n - 1) * m + i][3];
        if (val == -1) val = 0;
        val = min(val, len[mid]);
        insert(t, (n2 - 1) * m2 + i, val);
    }
    for(int i = 0; i < p[0].first; i++)
    {
        int val = g[i * m][1];
        if (val == -1) val = 0;
        val = min(val, len[mid]);
        insert(s, i * m2, val);
    }
    for(int i = 0; i < o[0].first; i++)
    {
        int val = g[i * m + m - 1][1];
        if (val == -1) val = 0;
        val = min(val, len[mid]);
        insert(s, i * m2 + m2 - 1, val);
    }
    for(int i = p[P - 1].first; i < n2; i++)
    {
        int val = g[i * m][1];
        if (val == -1) val = 0;
        val = min(val, len[mid]);
        insert(t, i * m2, val);
    }
    for(int i = o[O - 1].first; i < n2; i++)
    {
        int val = g[i * m + m - 1][1];
        if (val == -1) val = 0;
        val = min(val, len[mid]);
        insert(t, i * m2 + m2 - 1, val);
    }
    if (P == 1) insert(s, t, p[0].second);
    if (O == 1) insert(s, t, o[0].second);
    for(int i = 0; i < n2; i++)
        for(int j = 0; j < m2; j++)
        {
            int val[4];
            val[0] = g[i * m + j][3];
            val[2] = g[i * m + j][1];
            val[1] = g[(i + 1) * m + j + 1][2];
            val[3] = g[(i + 1) * m + j + 1][0];
            for(int k = 0; k < 4; k++)
            {
                if (val[k] == -1) val[k] = 0;
                val[k] = min(val[k], len[mid]);
                int tmpa = i + mo[k][0], tmpb = j + mo[k][1];
                if (tmpa >= 0 && tmpa < n2 && tmpb >= 0 && tmpb < m2)
                    insert(i * m2 + j, tmpa * m2 + tmpb, val[k]);
            }
        }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        int sum = 0;
        scanf("%d%d", &n, &m);
        scanf("%d", &P);for(int i = 0; i < P; i++)
            scanf("%d%d", &p[i].first, &p[i].second), p[i].first--;
        scanf("%d", &O);for(int i = 0; i < O; i++)
            scanf("%d%d", &o[i].first, &o[i].second), o[i].first--, sum += o[i].second;
        sort(p, p + P); sort(o, o + O);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
            for(int k = 0; k < 4; k++)
            {
                int tmpa = i + mo[k][0], tmpb = j + mo[k][1];
                g[i * m + j][k] = -1;
                if (judge(tmpa, tmpb)) g[i * m + j][k] = Max;
            }
        int tmp;scanf("%d", &tmp);while(tmp--)
        {
            int x1, y1, x2, y2, val;
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &val);
            x1--; y1--; x2--; y2--;
            g[x1 * m + y1][GetMove(x1, y1, x2, y2)] = val;
            g[x2 * m + y2][GetMove(x2, y2, x1, y1)] = val;
        }
        scanf("%d", &tmp); while(tmp--)
        {
            int a, b;scanf("%d%d", &a, &b); a--; b--;
            for(int i = 0; i < 4; i++)
            {
                int tmpa = a + mo[i][0], tmpb = b + mo[i][1];
                if (judge(tmpa, tmpb))
                    g[a * m + b][GetMove(a, b, tmpa, tmpb)] = -1;
            }
        }
        scanf("%d", &tmp);
        for(int i = 0; i < tmp; i++) scanf("%d", &len[i]);
        sort(len, len + tmp);
        n2 = n - 1, m2 = m - 1;
        int l = 0, r = tmp - 1, ans = -1;
        int s = n2 * m2;
        int t = s + 1;
        pst = t + 1, ost = t + P;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            build_graph(mid, s, t);
            int tmp = spfa(s, t);
            if (tmp < sum)
                l = mid + 1;
            else
            {
                if (ans == -1 || mid < ans) ans = mid;
                r = mid - 1;
            }
        }
        if (ans == -1) printf("-1\n");
        else
            printf("%d\n", len[ans]);
    }
    return 0;
}
