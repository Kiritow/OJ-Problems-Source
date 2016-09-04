#include <stdio.h>
#include <iostream>
using namespace std;
const int N=100001;
int a, n, f[N];
__int64 ans, tmp, tmp1;
void insert(int i)
{
    for(; i<=n; i+=i&(-i))
        f[i] += 1;
}
int query(int i)
{
    int tmp=0;
    for(; i>0; i-=i&(-i))
        tmp += f[i];
    return tmp;
}
int main()
{
    int i, cas, cas1=1;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d", &n);
        ans = 0;
        for(i=1; i<=n; i++)
            f[i] = 0;
        for(i=1; i<=n; i++)
        {
            scanf("%d", &a);
            insert(a);
            tmp = query(a-1);
            tmp1 = (n-a)-(i-1-tmp);
            ans -= tmp*tmp1;
            if(tmp1>=2)
                ans += tmp1*(tmp1-1)/2;
        }
        printf("Case #%d: %I64d\n", cas1++, ans%100000007);
    }
    return 0;
}
