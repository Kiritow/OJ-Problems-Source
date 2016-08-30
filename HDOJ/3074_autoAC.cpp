#include <iostream>
#include <algorithm>
using namespace std;
#define N 50005
const int MOD = 1000000007;
#define LL(x) ((x)<<1)
#define RR(x) ((x)<<1|1)
struct Seg_Tree
{
    int left,right,mid;
    __int64 num;
}bt[3*N];
__int64 num[N];
void build(int l,int r,int nid)
{
    bt[nid].left=l;
    bt[nid].right=r;
    bt[nid].mid=(l+r)>>1;
    if(l!=r)
    {
        build(l,bt[nid].mid,LL(nid));
        build(bt[nid].mid+1,r,RR(nid));
        bt[nid].num=(bt[LL(nid)].num%MOD)*(bt[RR(nid)].num%MOD)%MOD;
    }
    else
        bt[nid].num=num[l];
}
void update(int id,int x,int nid)
{
    if(bt[nid].left==bt[nid].right)
    {
        bt[nid].num=x;
        return ;
    }
    if(id<=bt[nid].mid)
        update(id,x,LL(nid));
    else
        update(id,x,RR(nid));
    bt[nid].num=(bt[2*nid].num*bt[2*nid+1].num)%MOD;
}
__int64 query(int l,int r,int nid)
{
    if(l==bt[nid].left&&r==bt[nid].right)
        return bt[nid].num%MOD;
    if(r<=bt[nid].mid)
        return query(l,r,LL(nid))%MOD;
    else if(l>bt[nid].mid)
        return query(l,r,RR(nid))%MOD;
    else
        return (query(l,bt[nid].mid,LL(nid))%MOD)*(query(bt[nid].mid+1,r,RR(nid))%MOD)%MOD;
}
int main() 
{
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(i = 1 ; i <= n; i ++) 
            scanf("%I64d",&num[i]);
        build(1,n,1);
        int cas,oper,a,b;
        scanf("%d",&cas);
        while(cas--)
        {
            scanf("%d",&oper);
            scanf("%d%d",&a,&b);
            switch(oper)
            {
                case 0:
                    printf("%I64d\n",query(a,b,1));
                    break;
                case 1:
                    update(a,b,1);
                    break;
                default:
                    break;                
            }
        }
    }
    return 0;
}
