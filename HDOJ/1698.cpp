/// General includes
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

/// 延迟更新: 区间赋值更新, 区间运算(求和)
namespace AttributeSegmentTree
{

const int MAXN = 100100;
const int MAXTREENODE = MAXN << 2;
const int ATTR_BY_DEFAULT=1;///默认初始化属性

struct node
{
    int lt,rt;
    int attr;
};

node tree[MAXTREENODE];

void build(int L,int R,int _indexer=1)
{
    tree[_indexer].lt=L;
    tree[_indexer].rt=R;
    tree[_indexer].attr=ATTR_BY_DEFAULT;
    if(L!=R)
    {
        int mid=(L+R)>>1;
        build(L,mid,_indexer<<1);
        build(mid+1,R,_indexer<<1|1);
    }
}

void update(int L,int R,int NewAttr,int _indexer=1)
{
    if(tree[_indexer].attr==NewAttr) return; /// Same Attribute. Don't Need Change.
    if(tree[_indexer].lt==L&&tree[_indexer].rt==R)
    {
        /// Right this segment. Update.
        tree[_indexer].attr=NewAttr;
        return;
    }
    /// This segment has only 1 attribute. New attribute is different.
    /// So change this segment's manager's attribute to -1 ( Different Attribute in this segment )
    if(tree[_indexer].attr!=-1)
    {
        tree[_indexer<<1].attr=tree[_indexer<<1|1].attr=tree[_indexer].attr;
        tree[_indexer].attr=-1;
    }
    /// If This segment has already had several attributes, operate its subtree by Deep-Loop.
    int mid=(tree[_indexer].lt+tree[_indexer].rt)>>1;
    if(L>mid)
    {
        update(L,R,NewAttr,_indexer<<1|1);
    }
    else if(R<=mid)
    {
        update(L,R,NewAttr,_indexer<<1);
    }
    else
    {
        update(L,mid,NewAttr,_indexer<<1);
        update(mid+1,R,NewAttr,_indexer<<1|1);
    }
}

#define ValueOfAttr(Attr) (Attr)
int AttrSumUp(int _indexer=1)
{
    if(tree[_indexer].attr!=-1)
    {
        return ValueOfAttr(tree[_indexer].attr)*(tree[_indexer].rt-tree[_indexer].lt+1);
    }
    else
    {
        return AttrSumUp(_indexer<<1)+AttrSumUp(_indexer<<1|1);
    }
}
}
//
int main()
{
    int t;
    scanf("%d",&t);
    for(int ct=1;ct<=t;ct++)
    {
        int n;
        scanf("%d",&n);
        AttributeSegmentTree::build(1,n);
        int q;
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int l,r,v;
            scanf("%d %d %d",&l,&r,&v);
            AttributeSegmentTree::update(l,r,v);
        }
        printf("Case %d: The total value of the hook is %d.\n",ct,AttributeSegmentTree::AttrSumUp());
    }

    return 0;
}
