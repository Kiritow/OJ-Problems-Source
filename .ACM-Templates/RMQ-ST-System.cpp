#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn = 10010;
struct node
{
    int lt,rt,v;
};
node tree[maxn<<2];

/** ========== Conditional =========== */
using ValueType = int;

inline ValueType algo_delegate(ValueType a,ValueType b)
{
    return min(a,b);
}
/****************************************/

void build(int lt,int rt,int v)
{
    tree[v].lt = lt;
    tree[v].rt = rt;
    if(lt == rt)
    {
        scanf("%d",&tree[v].v);
        return;
    }
    int mid = (lt + rt)>>1;
    build(lt,mid,v<<1);
    build(mid+1,rt,v<<1|1);
    tree[v].v = algo_delegate(tree[v<<1].v,tree[v<<1|1].v);
}
void update(int p,int val,int v)
{
    if(tree[v].lt == tree[v].rt)
    {
        tree[v].v = val;
        return;
    }
    if(p <= tree[v<<1].rt) update(p,val,v<<1);
    if(p >= tree[v<<1|1].lt) update(p,val,v<<1|1);
    tree[v].v = algo_delegate(tree[v<<1].v,tree[v<<1|1].v);
}
int query(int lt,int rt,int v)
{
    if(tree[v].lt >= lt && tree[v].rt <= rt)
        return tree[v].v;
    int a = INF,b = INF;
    if(lt <= tree[v<<1].rt) a = query(lt,rt,v<<1);
    if(rt >= tree[v<<1|1].lt) b = query(lt,rt,v<<1|1);
    return algo_delegate(a,b);
}
