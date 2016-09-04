#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define MAXN 100005
#define MAXM 400005
#define INF 1000000011
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define eps 1e-7
using namespace std;
bool tag[10001];
int p[10001];
int cnt;
void get_prime()
{
    cnt = 0;
    tag[1] = 1;
    for (int i = 2; i < 10000; i++)
    {
        if (!tag[i])
        p[cnt++] = i;
        for (int j = 0; j < cnt && p[j] * i < 10000; j++)
        {
            tag[i*p[j]] = 1;
            if (i % p[j] == 0)
            break;
        }
    }
}
int n, m;
int a[11005], b[11005];
int numa[10005], numb[10005];
int ans[1000005];
int num[1001111];
void get(int *x, int n, int *num)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < cnt; j++)
        {
            int tn = x[i];
            if(tn < p[j]) break;
            while(tn){num[j] += tn / p[j]; tn /= p[j];}
        }
    }
}
bool ok()
{
    for(int i = 0; i < cnt; i++)
        if(numb[i] > numa[i]) return 0;
    return 1;
}
int main()
{
    int T;
    get_prime();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
        memset(numa, 0, sizeof(numa));
        memset(numb, 0, sizeof(numb));
        get(a, n, numa);
        get(b, m, numb);
        if(!ok())
        {
            printf("-1\n");
            continue;
        }
        for(int i = 0; i < cnt; i++) numa[i] -= numb[i];
        int tp = 0;
        memset(num, 0, sizeof(num));
        while(1)
        {
            int low = 2, high = 10006;
            int can = 0;
            while(low <= high)
            {
                int mid = (low + high) >> 1;
                int fg = 1;
                for(int j = 0; j < cnt; j++)
                {
                    int tn = mid;
                    if(tn < p[j]) break;
                    int sum = 0;
                    while(tn){sum += tn / p[j]; tn /= p[j];}
                    if(sum > numa[j])
                    {
                        fg = 0;
                        break;
                    }
                }
                if(fg) {low = mid + 1; can = max(can, mid);}
                else high = mid - 1;
            }
            int x = can;
            if(x == 0) break;
            ans[tp] = x;
            int ot = INF;
            for(int j = 0; j < cnt; j++)
            {
                int tn = x;
                if(tn < p[j]) break;
                int sum = 0;
                while(tn){sum += tn / p[j]; tn /= p[j];}
                if(sum > 0) ot = min(ot, numa[j] / sum);
            }
            num[tp] += ot;
            tp++;
            for(int j = 0; j < cnt; j++)
            {
                int tn = x;
                if(tn < p[j]) break;
                int sum = 0;
                while(tn){sum += tn / p[j]; tn /= p[j];}
                numa[j] -= ot * sum;
            }
        }
        printf("%d\n", tp);
        for(int i =0; i < tp; i++) printf("%d %d\n", ans[i], num[i]);
    }
    return 0;
}
