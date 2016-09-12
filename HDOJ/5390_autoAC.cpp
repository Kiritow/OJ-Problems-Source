#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 100005
using namespace std;
struct OP
{
    int op, id, x;
}op[maxn];
struct Seg
{
    int l, r;
    int root;
    Seg() {}
    Seg(int _l, int _r, int _ro)
    {
        l = _l;
        r = _r;
        root = _ro;
    }
};
vector<Seg> T[20];
void build(int L, int R, int dep)
{
    T[dep].push_back(Seg(L, R, 0));
    if (L != R)
    {
        int mid = L + R >> 1;
        build(L, mid, dep + 1);
        build(mid + 1, R, dep + 1);
    }
}
int ch[4000000][2];
int num[4000000];
int cnt;
void insert_Dic(int root, int x)
{
    num[root]++;
    for (int i = 30; i >= 0; i--)
    {
        int c = (x&(1 << i)) ? 1 : 0;
        if (!ch[root][c]) ch[root][c] = ++cnt;
        root = ch[root][c];
        num[root]++;
    }
}
void erase_Dic(int root, int x)
{
    num[root]--;
    for (int i = 30; i >= 0; i--)
    {
        int c = (x&(1 << i)) ? 1 : 0;
        root = ch[root][c];
        num[root]--;
    }
}
int find_Dic(int root, int x)
{
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = (x&(1 << i)) ? 1 : 0;
        if (ch[root][c ^ 1] && num[ch[root][c ^ 1]])
        {
            res |= 1 << i;
            root = ch[root][c ^ 1];
        }
        else root = ch[root][c];
    }
    return res;
}
vector<Seg> Q;
void Select(int L, int R, int l, int r, int dep, int deep)
{
    if (dep > deep) return;
    if (l <= L&&R <= r)
    {
        if(dep==deep)
            Q.push_back(Seg(L, R, 0));
    }
    else
    {
        int mid = L + R >> 1;
        if (l <= mid) Select(L, mid, l, r, dep + 1, deep);
        if (mid < r) Select(mid + 1, R, l, r, dep + 1, deep);
    }
}
struct EDGE
{
    int to, next;
    EDGE() {}
    EDGE(int _t, int _n) { to = _t, next = _n; }
}edge[maxn];
int head[maxn], edgecnt;
void init_edge()
{
    memset(head, -1, sizeof(head));
    edgecnt = 0;
}
void add(int s, int t)
{
    edge[edgecnt] = EDGE(t, head[s]);
    head[s] = edgecnt++;
}
int dfs_clk;
int Left[maxn], Right[maxn];
void dfs(int u)
{
    Left[u] = ++dfs_clk;
    for (int i = head[u]; ~i; i = edge[i].next)
        dfs(edge[i].to);
    Right[u] = dfs_clk;
}
int val[maxn], _val[maxn];
int ans[maxn];
int bin(int idx, int x)
{
    int L = 0, R = T[idx].size();
    while (L < R)
    {
        int mid = (L + R) >> 1;
        if (T[idx][mid].l <= x) L = mid + 1;
        else R = mid;
    }
    return L - 1;
}
int main()
{
    int Ts;
    scanf("%d", &Ts);
    while (Ts--)
    {
        init_edge();
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 2; i <= n; i++)
        {
            int fa;
            scanf("%d", &fa);
            add(fa, i);
        }
        dfs_clk = 0;
        dfs(1);
        for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
        int Qc = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d", &op[i].op, &op[i].id);
            if (op[i].op == 0) scanf("%d", &op[i].x);
            else Qc++;
        }
        for (int i = 0; i < 20; i++) T[i].clear();
        build(1, dfs_clk, 0);
        memset(ans, 0, sizeof(ans));
        for (int i = 19; i >= 0; i--)
            if (T[i].size())
            {
                int Tsize = T[i].size();
                memcpy(_val, val, sizeof(_val));
                memset(ch, 0, sizeof(ch));
                memset(num, 0, sizeof(num));
                cnt = 0;
                for (int j = 0; j < Tsize; j++) T[i][j].root = ++cnt;
                for (int j = 1; j <= n; j++)
                {
                    Q.clear();
                    Select(1, dfs_clk, Left[j], Right[j], 0, i);
                    for (int k = 0; k < Q.size(); k++)
                    {
                        int pos = bin(i, Q[k].l);
                        insert_Dic(T[i][pos].root, _val[j]);
                    }
                }
                int quecnt = 0;
                for (int j = 1; j <= m;j++)
                    if (op[j].op == 0)
                    {
                        Q.clear();
                        Select(1, dfs_clk, Left[op[j].id], Right[op[j].id], 0, i);
                        for (int k = 0; k < Q.size(); k++)
                        {
                            int pos = bin(i, Q[k].l);
                            erase_Dic(T[i][pos].root, _val[op[j].id]);
                            insert_Dic(T[i][pos].root, op[j].x);
                        }
                        _val[op[j].id] = op[j].x;
                    }
                    else
                    {
                        quecnt++;
                        int pos = bin(i, Left[op[j].id]);
                        if (pos >= 0 && T[i][pos].l <= Left[op[j].id] && Left[op[j].id] <= T[i][pos].r)
                        {
                            ans[quecnt] = max(ans[quecnt], find_Dic(T[i][pos].root, _val[op[j].id]));
                        }
                    }
            }
        for (int i = 1; i <= Qc; i++) printf("%d\n", ans[i]);
    }
    return 0;
}
