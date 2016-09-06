#include <stdio.h>
#include <string.h>
#include <algorithm>
#define mem(a) memset(a,0,sizeof(a))
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std;
struct QUERY
{
    int a,b;
    int index;
}query[200005];
__int64 c[50005],  ans[200005];
int last[1000005], value[50005], N, M, T;
int cmp(QUERY x, QUERY y)
{
    return x.b < y.b;
}
int lowbit(int x)
{
    return x & (-x);
}
__int64 getSum(int k)
{
    __int64 sum = 0;
    while(k>=1)
    {
        sum += c[k];
        k -= lowbit(k);
    }
    return sum;
}
void edit(int k, int val)
{
    while(k<=N)
    {
        c[k] += val;
        k += lowbit(k);
    }
}
int main()
{
    while(~scanf("%d", &T))while(T--)
    {
        mem(query);  mem(c);
        mem(last);   mem(ans);
        mem(value);
        scanf("%d", &N);
        for(int i=1;i<=N;i++)
        {
            scanf("%d", &value[i]);
            edit(i, value[i]);
            if(!last[value[i]]) last[value[i]] = i;
        }
        scanf("%d", &M);
        for(int i=1;i<=M;i++)
        {
            scanf("%d%d", &query[i].a, &query[i].b);
            query[i].index = i;
        }
        sort(query+1, query+M+1, cmp);
        int lastRight = 1;
        for(int i = 1; i <= M; i ++)
        {
            for(int j = lastRight; j <= query[i].b; j ++)
            {
                if(last[value[j]] != j)
                {
                    edit(last[value[j]], -value[j]);
                    last[value[j]] = j;
                }
            }
            lastRight = query[i].b;
            ans[query[i].index] = getSum(query[i].b) - getSum(query[i].a-1);
        }
        for(int i=1;i<=M;i++)
        {
            printf("%I64d\n", ans[i]);
        }
    }
    return 0;
}
