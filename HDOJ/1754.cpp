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
    tree[_internal_v].val=max(tree[_internal_v<<1].val,tree[_internal_v<<1|1].val);
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
    tree[_internal_v].val = max(tree[_internal_v<<1].val,tree[_internal_v<<1|1].val);
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
        _internal_ans=max(_internal_ans,tree[_internal_v].val);
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

char str[8];
int main()
{
    using namespace SegmentTree;
    int n,q;
    while(scanf("%d %d",&n,&q)==2)
    {
        build(1,n);
        for(int i=0; i<q; i++)
        {
            int a,b;
            scanf("%s %d %d",str,&a,&b);
            switch(str[0])
            {
            case 'Q':
            {
                int ans=query(a,b);
                printf("%d\n",ans);
            }
            break;
            case 'U':
            {
                update(a,b);
            }
            }
        }
    }
    return 0;
}
