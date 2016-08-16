/// General includes
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

/// 区间赋值更新, 区间合并, 查找左端
namespace AttributeSumSegmentTree
{

const int MAXN = 100100;
const int MAXTREENODE = MAXN << 3;
const int ATTR_BY_DEFAULT=-1;///默认初始化属性 -1 无需操作 0 子树有住户离开 1 子树有住户进入

struct node
{
    int lt,rt;
    int lsum,rsum,sum;
    int attr;
};

node tree[MAXTREENODE];

void build(int L,int R,int _indexer=1)
{
    tree[_indexer].lt=L;
    tree[_indexer].rt=R;
    tree[_indexer].attr=ATTR_BY_DEFAULT;
    tree[_indexer].lsum=tree[_indexer].rsum=tree[_indexer].sum=R-L+1;
    if(L!=R)
    {
        int mid=(L+R)>>1;
        build(L,mid,_indexer<<1);
        build(mid+1,R,_indexer<<1|1);
    }
}

void update(int L,int R,int NewAttr,int _indexer=1)
{
    if(L==tree[_indexer].lt&&R==tree[_indexer].rt)
    {
        tree[_indexer].lsum=tree[_indexer].rsum=tree[_indexer].sum=
            NewAttr==1 ? 0 : tree[_indexer].rt-tree[_indexer].lt+1 ; /// Same as R-L+1
        tree[_indexer].attr=NewAttr;
        return;
    }

    /// Push Down (updated)
    if(tree[_indexer].attr!=-1)
    {
        /// Sync the Attribute to sub-tree
        tree[_indexer<<1].attr=tree[_indexer<<1|1].attr=tree[_indexer].attr;
        tree[_indexer].attr=-1;
        tree[_indexer<<1].rsum=tree[_indexer<<1].lsum=tree[_indexer<<1].sum= tree[_indexer<<1].attr==1 ? 0 : tree[_indexer<<1].rt-tree[_indexer<<1].lt+1;
        tree[_indexer<<1|1].rsum=tree[_indexer<<1|1].lsum=tree[_indexer<<1|1].sum= tree[_indexer<<1|1].attr==1 ? 0 : tree[_indexer<<1|1].rt-tree[_indexer<<1|1].lt+1;
    }

    int mid=(tree[_indexer].lt+tree[_indexer].rt)>>1;
    if(R<=mid)
    {
        update(L,R,NewAttr,_indexer<<1);
    }
    else if(L>mid)
    {
        update(L,R,NewAttr,_indexer<<1|1);
    }
    else
    {
        update(L,mid,NewAttr,_indexer<<1);
        update(mid+1,R,NewAttr,_indexer<<1|1);
    }

    /// Push Up (updated)
    tree[_indexer].lsum=tree[_indexer<<1].lsum; /// left & left
    tree[_indexer].rsum=tree[_indexer<<1|1].rsum; /// right & right

    if(tree[_indexer<<1].lsum == tree[_indexer<<1].rt-tree[_indexer].lt+1)
    {
        /// Father.LeftSum == RightSon.LeftSum + LeftSon.LeftSum
        tree[_indexer].lsum+=tree[_indexer<<1|1].lsum;
    }

    /// Why tree[_indexer].rsum but not tree[_indexer<<1|1].rsum ???
    if(tree[_indexer].rsum==tree[_indexer<<1|1].rt-tree[_indexer<<1|1].lt+1)
    {
        /// Father.RightSum == LeftSon.RightSum + RightSon.RightSum
        tree[_indexer].rsum+=tree[_indexer<<1].rsum;
    }

    tree[_indexer].sum=max(max(tree[_indexer<<1].sum,tree[_indexer<<1|1].sum),tree[_indexer<<1].rsum+tree[_indexer<<1|1].lsum);


}

int query(int Val,int _indexer=1)
{
    if(tree[_indexer].lt==tree[_indexer].rt)
    {
        return tree[_indexer].lt;
    }
    /// Push Down (updated)
    if(tree[_indexer].attr!=-1)
    {
        /// Sync the Attribute to sub-tree
        tree[_indexer<<1].attr=tree[_indexer<<1|1].attr=tree[_indexer].attr;
        tree[_indexer].attr=-1;
        tree[_indexer<<1].rsum=tree[_indexer<<1].lsum=tree[_indexer<<1].sum= tree[_indexer<<1].attr==1 ? 0 : tree[_indexer<<1].rt-tree[_indexer<<1].lt+1;
        tree[_indexer<<1|1].rsum=tree[_indexer<<1|1].lsum=tree[_indexer<<1|1].sum= tree[_indexer<<1|1].attr==1 ? 0 : tree[_indexer<<1|1].rt-tree[_indexer<<1|1].lt+1;
    }
    int Mid=(tree[_indexer].rt+tree[_indexer].lt)>>1;
    /// Left
    if(tree[_indexer<<1].sum>=Val)
    {
        return query(Val,_indexer<<1);
    }
    /// Both Left and Right
    else if(tree[_indexer<<1].rsum+tree[_indexer<<1|1].lsum >= Val)
    {
        return Mid-tree[_indexer<<1].rsum+1;
    }
    else /// Right
    {
        return query(Val,_indexer<<1|1);
    }
}

}/// End of namespace AttributeSumSegmentTree

int main()
{
    using namespace AttributeSumSegmentTree;
    int N,M;
    scanf("%d %d",&N,&M);
    build(1,N);
    while(M--)
    {
        int op;
        scanf("%d",&op);
        if(op==1) /// Check in
        {
            int x;
            scanf("%d",&x);
            if(tree[1].sum<x)
            {
                printf("0\n");continue;
            }
            int ans=query(x);
            printf("%d\n",ans);
            update(ans,ans+x-1,1);
        }
        else /// Check out
        {
            int a,b;
            scanf("%d %d",&a,&b);
            update(a,a+b-1,0);
        }
    }
    return 0;
}
