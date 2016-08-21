#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=100010;
struct darling
{
    int s,t,m,mt;
} a[N];
int n;
bool cmp(darling x,darling y)
{
    if(x.m==y.m)
        return x.s<y.s;
    return x.m<y.m;
}
int main()
{
    while(~scanf("%d",&n))
    {
        if(!n)
            break;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a[i].s,&a[i].t);
            a[i].mt=(a[i].t-a[i].s)/2+1;
            a[i].m=a[i].s+a[i].mt;
        }
        sort(a,a+n,cmp);
        int i=0;
        for(int t=0; i<n; i++)
        {
            if(t>a[i].t-a[i].mt)
                break;
            if(t>=a[i].s)
                t+=a[i].mt;
            else
                t=a[i].m;
        }
        if(i==n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
