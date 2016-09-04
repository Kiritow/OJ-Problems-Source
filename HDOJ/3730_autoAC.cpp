#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 1000001
#define ll __int64
struct Node
{
    ll a,b;
};
Node no[maxn];
bool cmp(Node x,Node y)
{
    return x.a<y.a;
}
int main()
{
    ll i,n;
    while(scanf("%I64d",&n)!=EOF)
    {
        for(i=0;i<n;i++)scanf("%I64d",&no[i].a);
        for(i=0;i<n;i++)scanf("%I64d",&no[i].b);
        sort(no,no+n,cmp);
        ll ans=0;
        for(i=0;i<n-1;i++)ans+=no[i].a;
        if((ans+1)*no[i].b>=no[i].a)ans+=no[i].a;
        else ans+=(ans+1)*no[i].b;
        printf("%I64d\n",ans);
    }
    return 0;
}
