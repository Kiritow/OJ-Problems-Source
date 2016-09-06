#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 1005
using namespace std;
int N, G[MAXN][MAXN], c[MAXN], idx;
int dgn[MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN], u[MAXN][MAXN], d[MAXN][MAXN];
struct Node
{
    int x, sign, key;
    bool operator < (Node temp) const
    {
        if (x != temp.x) {
            return x < temp.x;
        }    
        else {
            return sign < temp.sign;    
        }
    }
}p[MAXN<<1];  
int lowbit(int x)
{
    return x  & -x;
}
void addpoint(int a, int b)
{ 
    ++idx;
    p[idx].x = a, p[idx].sign = 0;
    p[idx].key = a;
    ++idx;
    p[idx].x = b, p[idx].sign = 1;
    p[idx].key = a;
}
void add(int x)
{
    for (int i = x; i <= N; i += lowbit(i)) {
        c[i] += 1;    
    }
}
int sum(int x)
{
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        ret += c[i];
    }    
    return ret;
}
int solve()
{
    int ret = 0;
    for (int i = N; i >= 1; --i) {
        idx = -1;
        for (int j = 1; j <= (N-i+1); ++j) {  
            if (G[i+j-1][j]) {
                addpoint(j, j+min(r[i+j-1][j], d[i+j-1][j])-1);
                dgn[j] = j - min(u[i+j-1][j], l[i+j-1][j])+1;
            }
        }
        if (idx == -1) { continue; }
        sort(p, p+idx+1);  
        memset(c, 0, sizeof (c));
        for (int k = 0; k <= idx; ++k) {
            if (!p[k].sign) {  
                ret -= sum(p[k].key);
                add(dgn[p[k].x]);
            }
            else {  
                ret += sum(p[k].key);
            }
        }
    }
    for (int j = 2; j <= N; ++j) {
        idx = -1;
        for (int i = 1; i <= (N-j+1); ++i) {
            if (G[i][j+i-1]) {
                addpoint(i, i+min(r[i][j+i-1], d[i][j+i-1])-1);
                dgn[i] = i - min(u[i][j+i-1], l[i][j+i-1])+1;
            }    
        }
        if (idx == -1) { continue; }
        sort(p, p+idx+1);
        memset(c, 0, sizeof (c));
        for (int k = 0; k <= idx; ++k) {
            if (!p[k].sign) {
                ret -= sum(p[k].key);
                add(dgn[p[k].x]);
            }
            else {
                ret += sum(p[k].key);
            }
        }
    }
    return ret;
}
int main()
{
    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        memset(d, 0, sizeof (d));
        memset(r, 0, sizeof (r));
        for (int i = 1;  i<= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                scanf("%d", &G[i][j]);
                if (G[i][j]) {
                    u[i][j] = G[i-1][j] ? u[i-1][j] + 1 : 1;
                    l[i][j] = G[i][j-1] ? l[i][j-1] + 1 : 1;
                }
            }
        }
        for (int  i = N; i >= 1; --i) {
            for (int j = N; j >= 1; --j) {
                if (G[i][j]) {
                    d[i][j] = G[i+1][j] ? d[i+1][j] + 1 : 1;
                    r[i][j] = G[i][j+1] ? r[i][j+1] + 1 : 1;    
                }
            }
        }
        printf("Case %d: %d\n", ++ca, solve());
    }
    return 0;    
}
