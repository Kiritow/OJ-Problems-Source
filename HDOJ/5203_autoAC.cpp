#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int l,r,x,n,m;
int ok(int a,int b,int c) 
{
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    if(b+c>a) return true;
    else return false;
}
long long calc2(int x,int y) 
{
    long long tot=0;
    for(int i=1;i<x;i++)
        if(ok(i,x-i,y)) tot++;
    for(int i=1;i<y;i++)
        if(ok(i,y-i,x)) tot++;
    return tot;
}
long long calc1(int n) 
{
    long long tot=0;
    for(int i=1;i<=n-2;i++) 
        if(2*i<n) 
        {
            tot+=(n-1)/2-(n/2-i);
        }
    return tot;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        l=n,r=1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            l=min(l,x);
            r=max(r,x);
        }
        if(r==n) printf("%lld\n",calc1(l-1));
        else if(l==1)  printf("%lld\n",calc1(n-r));
        else printf("%lld\n",calc2(l-1,n-r));
    }
    return 0;
}
