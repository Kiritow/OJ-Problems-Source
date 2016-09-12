#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define maxn 100000 + 10
#define INF 0x7fffffff
long long  mmap[maxn];
long long  temp[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&mmap[i]);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%lld",&temp[i]);
        }
        sort(mmap,mmap+n);
        sort(temp,temp+m);
        long long sum = 0;
        long long ans = 0;
        int p = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(p>=m) break;
            if(mmap[i] >= temp[p])
            {
               ans += mmap[i] - temp[p];
               sum = max(sum,ans);
               p++;
            }
            else
            {
                p++;
                i++;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
