#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define typev int 
#define N 200000
typev ar[N]; 
int lowb(int t) { return t & (-t) ; }
void add(int i, typev v)
{for ( ; i < N; ar[i] += v, i += lowb(i));}
typev sum(int i)
{
    typev s = 0;
    for ( ; i > 0; s += ar[i], i -= lowb(i));
    return s;
}
int n, m, k;
long long nowans;
int x[N], L[N], R[N], sta[N];
void init()
{
    memset(L, -1, sizeof(L)); memset(R, -1, sizeof(R));
    memset(ar, 0, sizeof(ar));
    for(int i = 1; i <= n; i++) if (x[i] < k)
        for(int j = i + 1; j <= n && x[j] >= k; j++)
            L[j] = i;
    for(int i = n; i >= 1; i--) if (x[i] < k)
        for(int j = i - 1; j >= 1 && x[j] >= k; j--)
            R[j] = i;
}
int Get(int l, int r, int now)
{
    if (l > r) return 0;
    if (l == -1 || r == -1) return 0;
    if (now == 0) return r - l + 1 - (sum(r) - sum(l - 1));
    return sum(r) - sum(l - 1);
}
int main()
{
    int t;scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
        init();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &sta[i]);
            if (sta[i]) add(i, 1);
        }
        nowans = 0;
        for(int i = 1; i <= n; i++)
            if (x[i] < k) nowans += Get(i + 1, n, !sta[i]);
            else nowans += Get(R[i], n, !sta[i]);
        while(m--)
        {
            int tmp;scanf("%d", &tmp);
            if (tmp == 1) cout << nowans << endl;
            else
            {
                scanf("%d", &tmp);
                int before = 0, after = 0;
                int i = tmp;
                if (x[tmp] < k)
                {
                    before += Get(1, i - 1, !sta[i]) + Get(i + 1, n, !sta[i]);
                    after += Get(1, i - 1, sta[i]) + Get(i + 1, n, sta[i]);
                }else
                {
                    before += Get(1, L[i], !sta[i]) + Get(R[i], n, !sta[i]);
                    after += Get(1, L[i], sta[i]) + Get(R[i], n, sta[i]);
                }
                if (sta[i] == 0) add(i, 1), sta[i] = 1;
                else add(i, -1), sta[i] = 0;
                nowans += (after - before);
            }
        }
    }
    return 0;
}
