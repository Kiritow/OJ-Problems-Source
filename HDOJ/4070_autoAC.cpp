#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100004
struct node
{
    int s,t;
}ans[N];
bool cmp(node a,node b)
{
    if(a.t!=b.t)return a.t>b.t;
    else a.s>b.s;
}
int main()
{
    int t,c=0,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&ans[i].s,&ans[i].t);
        }
        sort(ans,ans+n,cmp);
        int ans1=0,time=0;
        for(int i =0;i<n;i++)
        {
            time+=ans[i].s;
            ans1=max(time+ans[i].t,ans1);
        }
        printf("Case %d: %d\n",++c,ans1);
    }
    return 0;
}
