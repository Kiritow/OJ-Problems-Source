#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100010
using namespace std;
struct point{long long x,y;}a[MAXN];
bool cmp(point A,point B)
{
    if(A.x<B.x) return true;
    if(A.x==B.x&&A.y<B.y) return true;
    return false;
}
long long ABS(long long A)
{
    if(A<0) A=-A;
    return A;
}
long long work(int k,int n)
{
    int i;
    long long ans=0;
    for(i=0;i<n;i++)
    {
        ans+=ABS(a[k].x-a[i].x);
        ans+=ABS(a[k].y-a[i].y);
    }
    return ans;
}
int main()
{
    int test,n,s,e,i;
    long long ans,t;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&a[i].x,&a[i].y);
        }
        sort(a,a+n,cmp);
        s=n/2-250;e=n/2+250;
        if(s<0) s=0;
        if(e>n-1) e=n-1;
        ans=1;ans<<=60;
        for(i=s;i<=e;i++)
        {
            t=work(i,n);
            if(ans>t) ans=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
