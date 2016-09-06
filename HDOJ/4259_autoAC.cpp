#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
const int MAXN = 1805;
int a[2][MAXN], vst[MAXN], cnt;
int myS[MAXN][MAXN], top[MAXN];
void init()
{
    memset(vst, 0, sizeof(vst));
}
void dfs(int x)
{
    cnt++;
    vst[x] = 1;
    int nx = a[1][x];
    if(!vst[nx])
    {
        dfs(nx);
    }
}
__int64 gcd1(__int64 a, __int64 b)
{
    __int64 r = b, t;
    while(r)
    {
        t = r;
        r = a % r;
        a = t;
    }
    return a;
}
__int64 gcd2(__int64 a, __int64 b)
{
    return b == 0 ?  a : gcd2(b, a % b);
}
int main(void)
{
    int n, k;
    while(scanf("%d %d", &n, &k), n || k)
    {
        init();
        for(int i = 0; i < n; i++)
        {
            int in = i % k;
            myS[in][top[in]++] = i;
        }
        int s = 0;
        for(int i = 0; i < n; i++)
            a[0][i] = i;
        for(int in = 0; in < k; in++)
        {
            while(top[in])
            {
                a[1][s++] = myS[in][--top[in]];
            }
        }
        int c = 0;
        __int64 res[MAXN];
        for(int i = 0; i < n; i++)
        {
            if(!vst[i])
            {
                cnt = 0;
                dfs(i);
                res[c++] = cnt;
            }
        }
        __int64 tmp;
        if(c >= 2)
        {
            tmp = res[0] / gcd2(res[0], res[1]) * res[1];
            for(int i = 2; i < c; i++)
                tmp = tmp / gcd2(tmp, res[i]) * res[i];
        }
        else if(c == 1)
            tmp = res[0];
        printf("%I64d\n", tmp);
    }
    return 0;
}
