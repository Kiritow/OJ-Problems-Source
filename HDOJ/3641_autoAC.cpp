#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define MAXN 205
#define INF 100000000
#define eps 1e-9
#define L(x) x<<1
#define R(x) x<<1|1
using namespace std;
bool tag[101];
__int64 p[101];
int cnt = 0;
void get_prime()
{
    cnt = 0;
    for (__int64 i = 2; i < 101; i++)
    {
        if (!tag[i])
        p[cnt++] = i;
        for (__int64 j = 0; j < cnt && p[j] * i < 101; j++)
        {
            tag[i*p[j]] = 1;
            if (i % p[j] == 0)
            break;
        }
    }
}
__int64 a[105];
__int64 b[105];
__int64 num[105];
__int64 tmp[105];
int main()
{
    __int64 sum = 0;
    __int64 i, j;
    int t, n;
    scanf("%d", &t);
    get_prime();
    while(t--)
    {
        memset(num, 0, sizeof(num));
        __int64 high = 96000000099999999LL; 
        __int64 low = 0LL;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%I64d%I64d", &a[i], &b[i]);
            for(j = 0; j < cnt && p[j] * p[j] <= a[i]; j++) 
            {
                __int64 ct = 0;
                if(a[i] % p[j] == 0)
                {
                    while(a[i] % p[j] == 0)
                    {
                        ct++;
                        a[i] /= p[j];
                    }
                }
                num[p[j]] += ct * b[i];
            }
            if(a[i] > 1)
            {
                num[a[i]] += b[i];
            }
        }
        __int64 ans = 0;
        while(low <= high)
        {
            __int64 mid = (low + high) / 2;
            memset(tmp, 0, sizeof(tmp));
            for(i = 0; i < cnt && p[i] < 100; i++)
            {
                for(j = p[i]; j <= mid; j *= p[i])
                {
                    tmp[p[i]] += mid / j;
                }
            }
            int big = 0;
            for(i = 0; p[i] < 100; i++)
            {
                if(num[p[i]] == 0) continue;
                if(num[p[i]] > tmp[p[i]])
                {
                    big = -1;
                    break;
                }
            }
            int cn = 0;
            for(i = 0; p[i] < 100; i++)
            if(num[p[i]] > 0) cn++;
            int nc = 0;
            for(i = 0; p[i] < 100; i++)
            {
                if(num[p[i]] == 0) continue;
                if(tmp[p[i]] >= num[p[i]]) nc++;
            }
            if(nc == cn) big = 1;
            if(big == 0)
            break;
            else if(big == -1)
            {
                low = mid + 1;
            }
            else if(big == 1)
            {
                high = mid - 1;
            }
        }
        printf("%I64d\n", low);
    }
    return 0;
}
