/* ***********************************************
Author        :devil
Created Time  :2016/4/26 13:11:52
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
const int N=100005;
int n,a[N],b[N],tree[N<<2];
void build1(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=N;
        return ;
    }
    int m=(l+r)>>1;
    build1(node<<1,l,m);
    build1(node<<1|1,m+1,r);
    tree[node]=min(tree[node<<1],tree[node<<1|1]);
}
void update1(int node,int l,int r,int p)
{
    if(l==r)
    {
        tree[node]=b[p];
        return ;
    }
    int m=(l+r)>>1;
    if(a[p]<=m) update1(node<<1,l,m,p);
    else update1(node<<1|1,m+1,r,p);
    tree[node]=min(tree[node<<1],tree[node<<1|1]);
}
int query1(int node,int l,int r,int p)
{
    if(l>=p) return tree[node];
    int m=(l+r)>>1,ans;
    ans=query1(node<<1|1,m+1,r,p);
    if(p<=m) ans=min(ans,query1(node<<1,l,m,p));
    return ans;
}
void build2(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=0;
        return ;
    }
    int m=(l+r)>>1;
    build2(node<<1,l,m);
    build2(node<<1|1,m+1,r);
    tree[node]=max(tree[node<<1],tree[node<<1|1]);
}
void update2(int node,int l,int r,int p)
{
    if(l==r)
    {
        tree[node]=b[p];
        return ;
    }
    int m=(l+r)>>1;
    if(a[p]<=m) update2(node<<1,l,m,p);
    else update2(node<<1|1,m+1,r,p);
    tree[node]=max(tree[node<<1],tree[node<<1|1]);
}
int query2(int node,int l,int r,int p)
{
    if(r<=p) return tree[node];
    int m=(l+r)>>1,ans;
    ans=query2(node<<1,l,m,p);
    if(p>m) ans=max(ans,query2(node<<1|1,m+1,r,p));
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        int x,flag=1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            a[x]=i;
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            b[x]=i;
        }
        build1(1,1,n);
        for(int i=n; i>0; i--)
        {
            if(a[i]<=b[i]&&b[i]>query1(1,1,n,a[i]))
            {
                flag=0;
                break;
            }
            update1(1,1,n,i);
        }
        if(!flag)
        {
            printf("NO\n");
            continue;
        }
        build2(1,1,n);
        for(int i=1; i<=n; i++)
        {
            if(a[i]>=b[i]&&b[i]<query2(1,1,n,a[i]))
            {
                flag=0;
                break;
            }
            update2(1,1,n,i);
        }
        if(!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
