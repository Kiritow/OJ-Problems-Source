#include"stdio.h"
#include"string.h"
#include"stdlib.h"
struct Seg
{
    int l,r,mid;
    int sum;
}T[1111111];
void build(int l,int r,int k)
{
    T[k].l=l;
    T[k].r=r;
    T[k].mid=(l+r)>>1;
    if(l==r)    {T[k].sum=1;return ;}
    build(l,T[k].mid,2*k);
    build(T[k].mid+1,r,2*k+1);
    T[k].sum=T[2*k].sum+T[2*k+1].sum;
}
int find(int tot,int k)
{
    int ans;
    if(T[k].l==T[k].r)  {T[k].sum=0;return T[k].l;}
    if(tot<=T[2*k].sum) ans=find(tot,2*k);
    else                ans=find(tot-T[2*k].sum,2*k+1);
    T[k].sum=T[2*k].sum+T[2*k+1].sum;
    return ans;
}
int main()
{
    int T,Case;
    int n,m;
    int t,temp;
    __int64 ans;
    scanf("%d",&T);
    for(Case=1;Case<=T;Case++)
    {
        scanf("%d%d",&n,&m);
        build(1,n,1);
        ans=0;
        while(m--)
        {
            scanf("%d",&t);
            ans+=find(t,1);
        }
        printf("Case %d: %I64d\n",Case,ans);
    }
    return 0;
}
