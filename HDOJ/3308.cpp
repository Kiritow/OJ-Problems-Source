/// General includes
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;


/// 单点更新合并线段树: 单点更新,区间合并
namespace MergeSegmentTree
{

const int MAXN = 1000100;
const int MAXTREENODE = MAXN<<2;


int seq[MAXN];

struct node
{
    /// Be Sure That "BounderLen" always equal to "RightBounder - LeftBounder + 1"
    /// And Bounder Never change in one single test.
    int leftbounder,rightbounder,bounderlen;
    int leftseqlen,rightseqlen,mergedseqlen; /// From HDU 3308
    int leftvalue,rightvalue;
};

node tree[MAXTREENODE];

/// _internal_v is a indexer of SegmentTree. It guides the procedure to the right node.

void pushup(int _internal_v)
{
    /// Left == Left.Left
    tree[_internal_v].leftseqlen=tree[_internal_v<<1].leftseqlen;
    tree[_internal_v].leftvalue=tree[_internal_v<<1].leftvalue;

    /// Right == Right.Right
    tree[_internal_v].rightseqlen=tree[_internal_v<<1|1].rightseqlen;
    tree[_internal_v].rightvalue=tree[_internal_v<<1|1].rightvalue;

    /// Merged SeqLen is the max one of two sub-tree.MergedSeqLen
    tree[_internal_v].mergedseqlen=max(tree[_internal_v<<1].mergedseqlen,tree[_internal_v<<1|1].mergedseqlen);

    /// If LeftSon.RightValue < RightSon.LeftValue, a longer Seq may exist.
    if(tree[_internal_v<<1].rightvalue<tree[_internal_v<<1|1].leftvalue)
    {
        /// If LeftSon.LeftSeqLen == LeftSon.BounderLen ...
        if(tree[_internal_v<<1].leftseqlen == tree[_internal_v<<1].bounderlen )
        {
            /// ... ThisNode.LeftSeqLen += RightSon.LeftSeqLen
            tree[_internal_v].leftseqlen+=tree[_internal_v<<1|1].leftseqlen;
        }

        /// If RightSon.RightSeqLen == RightSon.BounderLen ...
        if(tree[_internal_v<<1|1].rightseqlen == tree[_internal_v<<1|1].bounderlen )
        {
            /// ... ThisNode.RightSeqLen += Left.RightSeqLen
            tree[_internal_v].rightseqlen+=tree[_internal_v<<1].rightseqlen;
        }

        /// ThisNode.MergedSeqLen is the max one between itself and ...
        /// ... LeftSon.RightSeqLen + RightSon.LeftSeqLen
        tree[_internal_v].mergedseqlen=
            max(tree[_internal_v].mergedseqlen,
                tree[_internal_v<<1].rightseqlen+tree[_internal_v<<1|1].leftseqlen);
    }
}

void build(int L,int R,int _internal_v=1) /// Build a tree, _internal_v is 1 by default.
{
    tree[_internal_v].leftbounder=L;
    tree[_internal_v].rightbounder=R;
    tree[_internal_v].bounderlen=R-L+1;
    if(L==R)
    {
        tree[_internal_v].leftvalue=tree[_internal_v].rightvalue=seq[L];
        /** SeqLen of Single Position is 1 , of course*/
        tree[_internal_v].leftseqlen=
            tree[_internal_v].rightseqlen=
            tree[_internal_v].mergedseqlen=1;
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,_internal_v<<1);
    build(mid+1,R,_internal_v<<1|1);/// x<<1 == x*2; x<<1|1 == x*2+1; (faster == slower)

    /// Push Up
    pushup(_internal_v);
}

void update(int Pos,int Val,int _internal_v=1)/// Update a position, _internal_v is 1 by default.
{
    /// Reach a clearly node with same LeftBounder and RightBounder
    if(tree[_internal_v].leftbounder==tree[_internal_v].rightbounder)
    {
        tree[_internal_v].leftvalue=tree[_internal_v].rightvalue=Val;
        return;
    }
    /// Calculate Mid
    int mid=(tree[_internal_v].leftbounder+tree[_internal_v].rightbounder)>>1;
    /// If in left then try update in left
    if(Pos <= mid)
        update(Pos,Val,_internal_v<<1);
    else /// Else try update in right
        update(Pos,Val,_internal_v<<1|1);
    /// And then push it up !
    pushup(_internal_v);
}

int query(int L,int R,int _internal_v=1)
{
    /// This Node ( and the segment which is under its control )
    ///   is included in query area.
    if(L<=tree[_internal_v].leftbounder && tree[_internal_v].rightbounder <= R)
    {
        return tree[_internal_v].mergedseqlen;
    }
    /// Calculate Mid
    int mid=(tree[_internal_v].leftbounder+tree[_internal_v].rightbounder)>>1;
    /// Answer saved in 'ans'
    int ans=0;

    /// Query If Segment L~R has common area with ThisNode.LeftBounder~Mid
    if(L<=mid)
    {
        ans=max(ans,query(L,R,_internal_v<<1));
    }

    /// Query If Segment L~R has common area with Mid+1 ~ ThisNode.RightBounder
    if(mid<R)
    {
        ans=max(ans,query(L,R,_internal_v<<1|1));
    }

    /// Besides these conditions, the following condition is more complex...
    /// If LeftNode.RightValue < RightNode.LeftValue
    ///     (looks like Push Up, but why not push up here ?
    ///      Is the amount of query action so huge ? )
    if(tree[_internal_v<<1].rightvalue<tree[_internal_v<<1|1].leftvalue)
    {
        /// Here comes the most complex logic.
        /// Answer is the max one of ...
        ans=max(ans,
                /// the minimum one of "Mid - L + 1" (Actually Left Bounder)
                ///     and LeftSon.RightSeqLen
                min(mid-L+1,tree[_internal_v<<1].rightseqlen)
                /// and
                +
                /// the minimum one of "R - Mid" (Actually Right Bounder)
                ///     and RightSon.LeftSeqLen
                min(R-mid,tree[_internal_v<<1|1].leftseqlen)
               );
    }

    /// Return ans. Ans is at least 1
    return ans;
}

}/// End of namespace MergeSegmentTree

using namespace MergeSegmentTree;

char _buff[8];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N,Q;
        scanf("%d %d",&N,&Q);
        for(int i=1; i<=N; i++)
        {
            scanf("%d",&seq[i]);
        }
        build(1,N);
        while(Q--)
        {
            int a,b;
            scanf("%s %d %d",_buff,&a,&b);
            switch(_buff[0])
            {
            case 'Q':
            {
                int ans=query(a+1,b+1);
                printf("%d\n",ans);
            }
            break;
            case 'U':
                update(a+1,b);
                break;
            }
        }
    }
    return 0;
}
