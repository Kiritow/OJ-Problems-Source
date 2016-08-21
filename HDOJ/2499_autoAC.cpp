#include <cstdio>
#include <cstring>
const int N = 100010;
int n, root, f[N], l[N], r[N], d[N], w[N];
int max(int x, int y)
{
    return  x > y ? x : y;
}
void init(int u)
{
    if(u == 0)  return;
    init(l[u]);
    init(r[u]);
    d[u] = max(d[l[u]], d[r[u]])+1;
}
void dp(int x, int &lt, int &rt)
{
    int p;
    p = f[x];
    if(x == root)  return;
    if(l[p] == x)
    {
        w[p] = max(lt+1, max(rt, d[r[p]])+2);
        rt = max(rt, d[r[p]])+1;
    }
    else
    {
        w[p] = max(rt+1, max(d[l[p]], lt)+2);
        lt = max(d[l[p]], lt)+1;
    }
    dp(p, lt, rt);
}
int main()
{
    int i, a, b;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)  break;
        for(i = 1; i <= n; i++)  f[i] = i;
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &a, &b);
            f[a] = f[b] = i;
            l[i] = a;
            r[i] = b;
        }
        root = 1;
        while(f[root] != root)  root = f[root];
        d[0] = 0;
        init(root);
        for(i = 1; i <= n; i++)
        {
            w[0] = 0;
            a = d[l[i]];
            b = d[r[i]];
            if(i == root)  w[root] = max(d[l[root]], d[r[root]])+1;
            else  dp(i, a, b);
            printf("%d\n", w[root]);
        }
    }
    return  0;
}
