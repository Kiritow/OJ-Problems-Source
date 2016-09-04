#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 105;
int T, n, m, x, y, t, tot, mp[maxn][maxn];
inline void read(int &ret)
{
    char c;
    do {
        c = getchar();
    } while (c < '0' || c > '9');
    ret = c - '0';
    while ((c = getchar()) >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
}
struct DLX
{
#define maxn 500005
#define F(i,A,s) for (int i=A[s];i!=s;i=A[i])
    int L[maxn], R[maxn], U[maxn], D[maxn];
    int row[maxn], col[maxn], ans[maxn], cnt[maxn];
    int n, m, num, sz;
    void add(int now, int l, int r, int u, int d, int x, int y)
    {
        L[now] = l;    R[now] = r;    U[now] = u;
        D[now] = d;   row[now] = x;  col[now] = y;
    }
    void reset(int n, int m)
    {
        num = 0x7FFFFFFF;
        this->n = n;    this->m = m;
        for (int i = 0; i <= m; i++)
        {
            add(i, i - 1, i + 1, i, i, 0, i);
            cnt[i] = 0;
        }
        L[0] = m;     R[m] = 0;     sz = m + 1;
    }
    void insert(int x, int y)
    {
        int ft = sz - 1;
        if (row[ft] != x)
        {
            add(sz, sz, sz, U[y], y, x, y);
            U[D[sz]] = sz; D[U[sz]] = sz;
        }
        else
        {
            add(sz, ft, R[ft], U[y], y, x, y);
            R[L[sz]] = sz; L[R[sz]] = sz;
            U[D[sz]] = sz; D[U[sz]] = sz;
        }
        ++cnt[y];    ++sz;
    }
    void remove(int now)
    {
        R[L[now]] = R[now];
        L[R[now]] = L[now];
        F(i, D, now) F(j, R, i)
        {
            D[U[j]] = D[j];
            U[D[j]] = U[j];
            --cnt[col[j]];
        }
    }
    void resume(int now)
    {
        F(i, U, now)    F(j, L, i)
        {
            D[U[j]] = j;
            U[D[j]] = j;
            ++cnt[col[j]];
        }
        R[L[now]] = now;
        L[R[now]] = now;
    }
    bool dfs(int x)
    {
        if (!R[0]) { num = min(num, x); return true; }
        int now = R[0];
        F(i, R, 0) if (cnt[now]>cnt[i]) now = i;
        remove(now);
        F(i, D, now)
        {
            ans[x] = row[i];
            F(j, R, i) remove(col[j]);
            if (dfs(x + 1)) return true;
            F(j, L, i) resume(col[j]);
        }
        resume(now);
        return false;
    }
    void Remove(int now)
    {
        F(i, D, now)
        {
            L[R[i]] = L[i];
            R[L[i]] = R[i];
        }
    }
    void Resume(int now)
    {
        F(i, U, now) L[R[i]] = R[L[i]] = i;
    }
    int vis[maxn];
    int flag[maxn];
    int A()
    {
        int dis = 0;
        F(i, R, 0) vis[i] = 0;
        F(i, R, 0) if (!vis[i])
        {
            dis++;    vis[i] = 1;
            F(j, D, i) F(k, R, j) vis[col[k]] = 1;
        }
        return dis;
    }
    void Dfs(int x)
    {
        if (!R[0]) num = min(num, x);
        else if (x + A()<num)
        {
            int now = R[0];
            F(i, R, 0) if (cnt[now]>cnt[i]) now = i;
            F(i, D, now)
            {
                Remove(i); F(j, R, i) Remove(j);
                Dfs(x + 1);
                F(j, L, i) Resume(j); Resume(i);
            }
        }
    }
}dlx;
int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(mp, 0, sizeof(mp));
        dlx.reset(n, n);
        while (m--)
        {
            scanf("%d%d", &x, &y);
            mp[x][y] = mp[y][x] = 1;
        }
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
                if (i == j || mp[i][j]) dlx.insert(i, j);
        dlx.Dfs(0);
        printf("%d\n", dlx.num);
    }
    return 0;
}
