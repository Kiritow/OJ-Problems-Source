#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 200010;
struct Node
{
    int l,r;
    long long sum;
    int mx;
    int lazy;
}segTree[MAXN*3];
void push_up(int i)
{
    if(segTree[i].l == segTree[i].r)return;
    segTree[i].sum = segTree[i<<1].sum + segTree[(i<<1)|1].sum;
    segTree[i].mx = max(segTree[i<<1].mx,segTree[(i<<1)|1].mx);
}
void Update_Same(int i,int v)
{
    segTree[i].sum = (long long)v*(segTree[i].r - segTree[i].l + 1);
    segTree[i].mx = v;
    segTree[i].lazy = 1;
}
void push_down(int i)
{
    if(segTree[i].l == segTree[i].r)return;
    if(segTree[i].lazy)
    {
        Update_Same(i<<1,segTree[i].mx);
        Update_Same((i<<1)|1,segTree[i].mx);
        segTree[i].lazy = 0;
    }
}
int mex[MAXN];
void Build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].lazy = 0;
    if(l == r)
    {
        segTree[i].mx = mex[l];
        segTree[i].sum = mex[l];
        return;
    }
    int mid = (l + r)>>1;
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid+1,r);
    push_up(i);
}
void Update(int i,int l,int r,int v)
{
    if(segTree[i].l == l && segTree[i].r == r)
    {
        Update_Same(i,v);
        return;
    }
    push_down(i);
    int mid = (segTree[i].l + segTree[i].r)>>1;
    if(r <= mid)
    {
        Update(i<<1,l,r,v);
    }
    else if(l > mid)
    {
        Update((i<<1)|1,l,r,v);
    }
    else
    {
        Update(i<<1,l,mid,v);
        Update((i<<1)|1,mid+1,r,v);
    }
    push_up(i);
}
int Get(int i,int v)
{
    if(segTree[i].l == segTree[i].r)
        return segTree[i].l;
    push_down(i);
    if(segTree[i<<1].mx > v)
        return Get(i<<1,v);
    else return Get((i<<1)|1,v);
}
int a[MAXN];
map<int,int>mp;
int ne[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        mp.clear();
        int tmp = 0;
        for(int i = 1;i <= n;i++)
        {
            mp[a[i]] = 1;
            while(mp.find(tmp) != mp.end())tmp++;
            mex[i] = tmp;
        }
        mp.clear();
        for(int i = n;i >= 1;i--)
        {
            if(mp.find(a[i]) == mp.end())ne[i] = n+1;
            else ne[i] = mp[a[i]];
            mp[a[i]] = i;
        }
        Build(1,1,n);
        long long sum = 0;
        for(int i = 1;i <= n;i++)
        {
            sum += segTree[1].sum;
            if(segTree[1].mx > a[i])
            {
                int l = Get(1,a[i]);
                int r = ne[i];
                if(l < r)
                    Update(1,l,r-1,a[i]);
            }
            Update(1,i,i,0);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
