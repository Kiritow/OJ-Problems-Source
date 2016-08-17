#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 1000100
#define MAXTREENODE MAXN<<2

#ifndef __int64
#define __int64 long long
#endif // __int64
#define LL __int64

struct node
{
    __int64 l;
    __int64 r;
    __int64 add;
    __int64 value;

}tree[MAXTREENODE];
__int64 a[MAXTREENODE],n;
void build( __int64 v, __int64 l,__int64 r )  //对节点v进行建立，区间为l到r
{
    tree[v].l=l;
    tree[v].r=r;
    if( l == r )
    {
        tree[v].value=a[r];   //完全二叉树
        return;
    }
    __int64 mid=( l+r )/2;
    build( v*2,l,mid );    //左儿子
    build( v*2+1,mid+1,r );   //右儿子
    tree[v].value=tree[v*2].value+tree[v*2+1].value;  //根据左右儿子更新当前节点
}
void update(__int64 v,__int64 l,__int64 r,__int64 m)  //更新区间l-r加上m
{
    tree[v].value+=m*(r-l+1);     //更新v点value
    if (tree[v].l==l && tree[v].r==r)    //找到了，更新并记录增量
    {
        tree[v].add+=m;
        return ;
    }

    if (tree[v].l==tree[v].r) return ;

    __int64 mid=(tree[v].l+tree[v].r)/2;

    if (tree[v].add)           //下边没更新，传递增量
    {
        tree[v*2].add+=tree[v].add;     //+=注意儿子本身可能就有原来未传递的增量
        tree[v*2+1].add+=tree[v].add;
        tree[v*2].value+=tree[v].add*(tree[v*2].r-tree[v*2].l+1);   //对value更新
        tree[v*2+1].value+=tree[v].add*(tree[v*2+1].r-tree[v*2+1].l+1);
        tree[v].add=0;         //传递完成
    }
    if (r<=mid)
    {
        update(v*2,l,r,m);   //只更新左儿子
        return;
    }
    if (l>mid)
    {
        update(v*2+1,l,r,m);  //只更新右儿子
        return;
    }

    update(v*2,l,mid,m);     //左右儿子都更新
    update(v*2+1,mid+1,r,m);

}
__int64 query( __int64 v,__int64 l,__int64 r)     //查询l-r上的v值
{
    if (l==tree[v].l&&r==tree[v].r)    //找到了
        return tree[v].value;
    __int64 mid=(tree[v].l+tree[v].r)/2;

    if (tree[v].add)
    {
        tree[v*2].add+=tree[v].add;
        tree[v*2+1].add+=tree[v].add;
        tree[v*2].value+=tree[v].add*(tree[v*2].r-tree[v*2].l+1);
        tree[v*2+1].value+=tree[v].add*(tree[v*2+1].r-tree[v*2+1].l+1);
        tree[v].add=0;
    }

    if (r<=mid)
        return query(v*2,l,r);    //要查询的区间全在左儿子
    if (l>mid)
        return query(v*2+1,l,r);    //全在右边

    return query(v*2,l,mid)+query(v*2+1,mid+1,r);   //横跨左右边
}

#define build(x,y) build(1,x,y)
#define query(x,y) query(1,x,y)
#define update(x,y,c) update(1,x,y,c)

char _bar[4];
char& option=_bar[0];
int main()
{
    LL N,Q;
    scanf("%I64d %I64d",&N,&Q);
    n=N;
    for (int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    build(1,N);
    for(int i=0;i<Q;i++)
    {
        scanf("%s",_bar);
        switch(option)
        {
        case 'Q':
            {
                int x,y;
                scanf("%d %d",&x,&y);
                LL ans=query(x,y);
                printf("%I64d\n",ans);
            }
            break;
        case 'C':
            {
                int x,y;
                LL c;
                scanf("%d %d %I64d",&x,&y,&c);
                update(x,y,c);
            }
            break;
        }
    }
    return 0;
}
