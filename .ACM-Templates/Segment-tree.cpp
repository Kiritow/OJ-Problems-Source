/// General includes
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

/// 最基础的线段树: 单点更新,区间运算(求和)
namespace SegmentTree
{

const int MAXN = 1000100;
const int MAXTREENODE = MAXN<<2;

struct node
{
    int lt,rt;
    int val;
};

node tree[MAXTREENODE];

/// _internal_v is a indexer of SegmentTree. It guides the procedure to the right node.

void build(int L,int R,int _internal_v=1) /// Build a tree, _internal_v is 1 by default.
{
    tree[_internal_v].lt=L;
    tree[_internal_v].rt=R;
    if(L==R)
    {
        scanf("%d",&tree[_internal_v].val);
        /// Or: tree[_internal].val = VAL_BY_DEFAULT
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,_internal_v<<1);
    build(mid+1,R,_internal_v<<1|1);/// x<<1 == x*2; x<<1|1 == x*2+1; (faster == slower)
    /// SegmentTree Main Algorithm
    tree[_internal_v].val=tree[_internal_v<<1].val+tree[_internal_v<<1|1].val;
}

void update(int Pos,int Val,int _internal_v=1)/// Update a position, _internal_v is 1 by default.
{
    if(tree[_internal_v].lt==tree[_internal_v].rt)
    {
        tree[_internal_v].val=Val;
        return;
    }
    /// Update Deep-Loop
    if(Pos <= tree[_internal_v<<1].rt) update(Pos,Val,_internal_v<<1);
    if(Pos >= tree[_internal_v<<1|1].lt) update(Pos,Val,_internal_v<<1|1);
    /// SegmentTree Main Algorithm
    tree[_internal_v].val = tree[_internal_v<<1].val+tree[_internal_v<<1|1].val;
}

int _internal_ans;
inline void _internal_clear_ans()
{
    _internal_ans=0;
}
inline int _internal_get_ans()
{
    return _internal_ans;
}
void basic_query(int L,int R,int _internal_v=1)/// Query A Segment [L,R] , _internal_v is 1 by default.
{
    if(tree[_internal_v].lt >= L && tree[_internal_v].rt <= R)
    {
        _internal_ans+=tree[_internal_v].val;
        return;
    }
    if(L <= tree[_internal_v<<1].rt) basic_query(L,R,_internal_v<<1);
    if(R >= tree[_internal_v<<1|1].lt) basic_query(L,R,_internal_v<<1|1);
}

int query(int L,int R)
{
    _internal_clear_ans();
    basic_query(L,R);
    return _internal_get_ans();
}

}/// End of namespace SegmentTree

/// 延迟更新: 区间运算更新(加法), 区间运算(求和)
namespace LazySegmentTree
{

const int MAXN = 100100;
const int MAXTREENODE = MAXN << 2;

struct node
{
    int lt,rt;
    int val;
    int add;
};

node tree[MAXTREENODE];

void _internal_PushUp(int _indexer)
{
    tree[_indexer].val=tree[_indexer<<1].val+tree[_indexer<<1|1].val;
}
void _internal_PushDown(int _indexer)
{
    if(tree[_indexer].add!=0)
    {
        /// Broadcast this add value to Left and Right sub-tree node.
        tree[_indexer<<1].add+=tree[_indexer].add;
        tree[_indexer<<1|1].add+=tree[_indexer].add;
        /// Confirm this change by calculate and add changes to sub-trees.
        tree[_indexer<<1].val+=tree[_indexer].add * (tree[_indexer<<1].rt-tree[_indexer<<1].lt+1);
        tree[_indexer<<1|1].val+=tree[_indexer].add *(tree[_indexer<<1|1].rt-tree[_indexer<<1|1].lt+1);
        /// Now Clear this node's add value.
        tree[_indexer].add=0;
    }
}

void build(int L,int R,int _indexer=1)
{
    tree[_indexer].lt=L;
    tree[_indexer].rt=R;
    tree[_indexer].add=0;/// This must be set to 0.
    if(L==R)
    {
        //scanf("%d",&tree[_indexer].val);
        tree[_indexer].val = 0;
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,_indexer<<1);
    build(mid+1,R,_indexer<<1|1);
    /// Update this val from down to up. (>.<)
    _internal_PushUp(_indexer);
}

void update(int L,int R,int ValToAdd,int _indexer=1)
{
    /// Return when L or R exceeds range. So smart !
    if(R<tree[_indexer].lt||L>tree[_indexer].rt) return;
    if(L<=tree[_indexer].lt&&R>=tree[_indexer].rt)
    {
        /// This range is covered. So just add the 'add' value, which is called "LAZY"
        tree[_indexer].add+=ValToAdd;
        tree[_indexer].val+=ValToAdd*(tree[_indexer].rt-tree[_indexer].lt+1);
        return;
    }
    _internal_PushDown(_indexer);
    /// This ... Hum.. Seems not so clever...
    update(L,R,ValToAdd,_indexer<<1);
    update(L,R,ValToAdd,_indexer<<1|1);
    _internal_PushUp(_indexer);
}

int ans;
void basic_query(int L,int R,int _indexer=1)
{
    /// Data to find is not in this range.
    if(R<tree[_indexer].lt||L>tree[_indexer].rt) return;
    /// Data to find is right in this range , or covers this range.
    if(L<=tree[_indexer].lt&&R>=tree[_indexer].rt)
    {
        ans+=tree[_indexer].val;
        return ;
    }
    _internal_PushDown(_indexer);
    int mid=(tree[_indexer].lt+tree[_indexer].rt)>>1;
    if(R<=mid)
        basic_query(L,R,_indexer<<1);
    else if(L>mid)
        basic_query(L,R,_indexer<<1|1);
    else
    {
        basic_query(L,mid,_indexer<<1);
        basic_query(mid+1,R,_indexer<<1|1);
    }
}
int query(int L,int R)
{
    ans=0;
    basic_query(L,R);
    return ans;
}

}/// End of namespace LazySegmentTree

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

}/// End of namespace AttributeSegmentTree
