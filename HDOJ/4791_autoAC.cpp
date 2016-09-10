#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <set>
#define PI acos(-1.0)
#define maxn 100005
#define INF 0x7fffffff
#define eps 1e-8
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
struct aa
{
    LL p,s;
    LL cost;
} a[100005];
struct bb
{
    LL i,q;
    LL cost;
} b[100005];
bool cmp1(bb a,bb b)
{
    return a.i<b.i;
}
bool cmp2(bb a,bb b)
{
    return a.q<b.q;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)
        {
            scanf("%I64d%I64d",&a[i].p,&a[i].s);
        }
        a[m-1].cost=a[m-1].p*a[m-1].s;
        for(int i=m-2; i>=0; i--)
            a[i].cost=min(a[i+1].cost,a[i].p*a[i].s);
        for(int i=0; i<n; i++)
        {
            scanf("%I64d",&b[i].q);
            b[i].i=i;
        }
        sort(b,b+n,cmp2);
        int top1=0;
        for(int i=0; i<n; i++)
        {
            while(b[i].q>=a[top1].p&&top1<m)
                top1++;
            if(top1==m)
                b[i].cost=b[i].q*a[top1-1].s;
            else
                b[i].cost=min(b[i].q*a[top1-1].s,a[top1].cost);
        }
        sort(b,b+n,cmp1);
        for(int i=0; i<n; i++)
            printf("%I64d\n",b[i].cost);
    }
    return 0;
}
