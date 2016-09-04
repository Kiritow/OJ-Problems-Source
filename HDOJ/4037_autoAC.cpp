#include<algorithm>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=100010;
typedef long long ll;
const ll mod=20110911*2;
#define lson L,mid,ls
#define rson mid+1,R,rs
ll sm[maxn],ss[maxn],sc[maxn<<2],sd[maxn<<2],siid[maxn<<2];
ll sic[maxn<<2],sid[maxn<<2],ac[maxn<<2],ad[maxn<<2];
ll asc,aic,asd,aid,aiid;
void addc(int L,int R,int rt,ll d)
{
    ac[rt]=(ac[rt]+d)%mod;
    sc[rt]=(sc[rt]+(R-L+1)*d)%mod;
    sic[rt]=(sic[rt]+(sm[R]-sm[L-1])*d)%mod;
}
void addd(int L,int R,int rt,ll d)
{
    ad[rt]=(ad[rt]+d)%mod;
    sd[rt]=(sd[rt]+(R-L+1)*d)%mod;
    sid[rt]=(sid[rt]+(sm[R]-sm[L-1])*d)%mod;
    siid[rt]=(siid[rt]+(ss[R]-ss[L-1])*d)%mod;
}
void PushDown(int L,int R,int rt)
{
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    if(ad[rt])
        addd(lson,ad[rt]),addd(rson,ad[rt]),ad[rt]=0;
    if(ac[rt])
        addc(lson,ac[rt]),addc(rson,ac[rt]),ac[rt]=0;
}
void PushUp(int rt)
{
    int ls=rt<<1,rs=ls|1;
    sc[rt]=(sc[ls]+sc[rs])%mod;
    sic[rt]=(sic[ls]+sic[rs])%mod;
    sd[rt]=(sd[ls]+sd[rs])%mod;
    sid[rt]=(sid[ls]+sid[rs])%mod;
    siid[rt]=(siid[ls]+siid[rs])%mod;
}
void build(int L,int R,int rt)
{
    ac[rt]=ad[rt]=0;
    if(L==R)
    {
        scanf("%I64d%I64d",&sc[rt],&sd[rt]);
        sic[rt]=(L*sc[rt])%mod;
        sid[rt]=(L*sd[rt])%mod;
        siid[rt]=(sid[rt]*L)%mod;
        return;
    }
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int rt,int l,int r,ll d,int op)
{
    if(l<=L&&R<=r)
    {
        if(op)
            addd(L,R,rt,d);
        else
            addc(L,R,rt,d);
        return;
    }
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    PushDown(L,R,rt);
    if(l<=mid)
        update(lson,l,r,d,op);
    if(r>mid)
        update(rson,l,r,d,op);
    PushUp(rt);
}
void qu(int L,int R,int rt,int l,int r)
{
    if(l<=L&&R<=r)
    {
        asc=(asc+sc[rt])%mod;
        aic=(aic+sic[rt])%mod;
        asd=(asd+sd[rt])%mod;
        aid=(aid+sid[rt])%mod;
        aiid=(aiid+siid[rt])%mod;
        return;
    }
    int ls=rt<<1,rs=ls|1,mid=(L+R)>>1;
    PushDown(L,R,rt);
    if(l<=mid)
        qu(lson,l,r);
    if(r>mid)
        qu(rson,l,r);
    PushUp(rt);
}
int main()
{
    int i,t,n,q,x,y,z,cas=1;
    char cmd[20];
    for(i=1;i<maxn;i++)
    {
        sm[i]=(sm[i-1]+i)%mod;
        ss[i]=(ss[i-1]+(ll)i*i)%mod;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        build(1,n,1);
        scanf("%d",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            asc=aic=asd=aid=aiid=0;
            scanf("%s%d%d",cmd,&x,&y);
            if(cmd[0]!='Q')
                scanf("%d",&z);
            if(cmd[2]=='s')
                update(1,n,1,x,y,z,0);
            else if(cmd[2]=='l')
                update(1,n,1,x,y,z,1);
            else
            {
                qu(1,n,1,x,y);
                ll ans=((ll)y*(y+1)*asd-(2*y+1)*aid+aiid)%mod;
                ans-=2*((y+1)*asc-aic);
                ans%=mod;
                ans=(ans+mod)%mod;
                printf("%I64d\n",ans/2);
            }
        }
    }
    return 0;
}
