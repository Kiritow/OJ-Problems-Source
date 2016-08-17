/// HDU 1394

/// General includes
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

///求数列逆序数
inline int GetInversionNumberOfSequence(int* seq,int len)
{
    int ans=0;
    for(int i=0;i<len-1;i++)
    {
        for(int j=i;j<len;j++)
        {
            if(seq[i]>seq[j])ans++;
        }
    }
    return ans;
}



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
        ///scanf("%d",&tree[_internal_v].val);
        tree[_internal_v].val = 0;
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,_internal_v<<1);
    build(mid+1,R,_internal_v<<1|1);/// x<<1 == x*2; x<<1|1 == x*2+1; (faster == slower)
    /// SegmentTree Main Algorithm
    tree[_internal_v].val=tree[_internal_v<<1].val+tree[_internal_v<<1|1].val;
}

void update(int Pos,int _internal_v=1)/// Update a position, _internal_v is 1 by default.
{
    if(tree[_internal_v].lt==tree[_internal_v].rt)
    {
        tree[_internal_v].val=1;
        return;
    }
    /// Update Deep-Loop
    if(Pos <= tree[_internal_v<<1].rt) update(Pos,_internal_v<<1);
    if(Pos >= tree[_internal_v<<1|1].lt) update(Pos,_internal_v<<1|1);
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

const int MAXN = 5005;
int a[MAXN];

int main()
{
    using namespace SegmentTree;
    int n;
    while(scanf("%d",&n)==1)
    {
        build(1,n);
        int TSum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            //a[i]+=1; /// From 0 to 1, ... From n-1 to n (Understand)
            ///Query ? Why ??
            TSum+=query(a[i]+1,n);
            update(a[i]+1);
        }
        int MinSum=TSum;
        for(int i=0;i<n;i++)
        {
            /// 当a[i]由第一个变为最后一个时,
            /// 要加上a[i]后面大于a[i]的数的个数,
            /// 有n-1-a[i]个，要减去a[i]后面小于a[i]的数的个数,
            /// 有a[i]个（注意i是从0开始的）
            TSum=TSum+n - 2*a[i] -1;
            MinSum=min(MinSum,TSum);
        }

        printf("%d\n",MinSum);
    }
    return 0;
}
