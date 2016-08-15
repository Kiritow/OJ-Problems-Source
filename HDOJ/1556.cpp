/// General includes
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;
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


int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        LazySegmentTree::build(1,n);
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            LazySegmentTree::update(x,y,1);
        }
        printf("%d",LazySegmentTree::query(1,1));
        for(int i=2;i<=n;i++)
        {
            printf(" %d",LazySegmentTree::query(i,i));
        }
        printf("\n");
    }
    return 0;
}
