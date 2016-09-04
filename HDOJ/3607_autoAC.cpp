#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 100005
struct Node
{
    int l,r;
    int max_gold;
}tree[maxn*4];
struct Box
{
    int height;
    int gold;
    int li;
    int id;
}box[maxn];
int N,ans,cnt;
void build(int id,int l,int r)
{
    tree[id].l=l;
    tree[id].r=r;
    tree[id].max_gold=0;
    if(r>l)
    {
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
    }
}
void update(int id,int idx,int val)
{
    if(tree[id].l==tree[id].r)
    {
        tree[id].max_gold=max(tree[id].max_gold,val);
        return;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(idx<=mid)
    {
        update(id*2,idx,val);
    }
    else
    {
        update(id*2+1,idx,val);
    }
    tree[id].max_gold=max(tree[id*2].max_gold,tree[id*2+1].max_gold);
}
int query(int id,int l,int r)
{
    if(tree[id].l==l&&tree[id].r==r)
    {
        return tree[id].max_gold;
    }
    int mid=(tree[id].l+tree[id].r)/2;
    if(r<=mid)
    {
        return query(id*2,l,r);
    }
    else if(l>mid)
    {
        return query(id*2+1,l,r);
    }
    else
    {
        return max(query(id*2,l,mid),query(id*2+1,mid+1,r));
    }
}
int cmp1(Box a,Box b)
{
    return a.height<b.height;
}
int cmp2(Box a,Box b)
{
    return a.id<b.id;
}
void lisan()
{
    sort(box,box+N,cmp1);
    cnt=0;
    box[0].li=0;
    for(int i=1;i<N;i++)
    {
        if(box[i].height!=box[i-1].height)
        {
            cnt++;
            box[i].li=cnt;
        }
        else
        {
            box[i].li=cnt;
        }
    }
    sort(box,box+N,cmp2);
}
void solve()
{
    lisan();
    build(1,0,cnt);
    ans=0;
    for(int i=0;i<N;i++)
    {
        if(box[i].li==0)
        {
            update(1,0,box[i].gold);
            ans=max(ans,box[i].gold);
        }
        else
        {
            int t=query(1,0,box[i].li-1);
            update(1,box[i].li,t+box[i].gold);
            ans=max(ans,t+box[i].gold);
        }
    }
}
int main()
{
    while(scanf("%d",&N)==1)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&box[i].height,&box[i].gold);
            box[i].id=i;
        }
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
