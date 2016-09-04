#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int v1,v2;
    int w;
} s[100005],t[100005];
int n,m,k,cnts,cntt;
int father[100005],sum;
int cmp(const node a,const node b)
{
    if(a.w<b.w)
        return 1;
    else
        return 0;
}
int find(int x)
{
    int i=x,root;
    while(x!=father[x])
        x=father[x];
    root=x;
    x=i;
    while(x!=father[x])
    {
        i=father[x];
        father[x]=root;
        x=i;
    }
    return root;
}
int deal(int x)
{
    for(int i=0; i<=n; i++)
        father[i]=i;
    int lens=0,lent=0,pp=0;
    sum=0;
    while(lens<cnts||lent<cntt)
    {
        if(s[lens].w+x<=t[lent].w)
        {
            int s1=find(s[lens].v1);
            int s2=find(s[lens].v2);
            if(s1!=s2)
            {
                father[s1]=s2;
                sum+=s[lens].w+x;
                pp++;
            }
            lens++;
        }
        else
        {
            int s1=find(t[lent].v1);
            int s2=find(t[lent].v2);
            if(s1!=s2)
            {
                father[s1]=s2;
                sum+=t[lent].w;
            }
            lent++;
        }
    }
    if(pp>=k)   return 1;
    else    return 0;
}
int main()
{
    int text=0;
    while(scanf("%d%d%d",&n,&m,&k)>0)
    {
        cnts=0,cntt=0;
        for(int i=0; i<m; i++)
        {
            int v1,v2,w,tmp;
            scanf("%d%d%d%d",&v1,&v2,&w,&tmp);
            if(tmp==0)
            {
                s[cnts].v1=v1;
                s[cnts].v2=v2;
                s[cnts].w=w;
                cnts++;
            }
            if(tmp==1)
            {
                t[cntt].v1=v1;
                t[cntt].v2=v2;
                t[cntt].w=w;
                cntt++;
            }
        }
        sort(s,s+cnts,cmp);
        sort(t,t+cntt,cmp);
        t[cntt].w=s[cnts].w=(1<<29);
        printf("Case %d: ",++text);
        int l=-1000,r=1000;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(deal(mid))
            {
                l=mid+1;
                ans=sum-mid*k;
            }
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
