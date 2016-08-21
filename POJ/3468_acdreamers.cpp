#include <stdio.h>
#define N 111111

#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

LL add[N<<2];
LL sum[N<<2];

void PushUP(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void PushDown(int rt,int m)
{
    if(add[rt])
    {
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        sum[rt<<1]+=(m-(m>>1))*add[rt];
        sum[rt<<1|1]+=(m>>1)*add[rt];
        add[rt]=0;
    }
}

void Build(int l,int r,int rt)
{
    add[rt]=0;
    if(l==r)
    {
        scanf("%I64d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    Build(lson);
    Build(rson);
    PushUP(rt);
}

void Update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&R>=r)
    {
        add[rt]+=c;
        sum[rt]+=(LL)c*(r-l+1);
        return;
    }
    PushDown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m)
        Update(L,R,c,lson);
    if(R>m)
        Update(L,R,c,rson);
    PushUP(rt);
}

LL Query(int L,int R,int l,int r,int rt)
{
    if(L<=l&&R>=r)
        return sum[rt];
    PushDown(rt,r-l+1);
    int m=(l+r)>>1;
    LL ret=0;
    if(L<=m)   ret+=Query(L,R,lson);
    if(R>m)    ret+=Query(L,R,rson);
    return ret;
}

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    Build(1,n,1);
    while(m--)
    {
        char s[5];
        int a,b,c;
        scanf("%s",s);
        if(s[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            printf("%I64d\n",Query(a,b,1,n,1));
        }
        else
        {
            scanf("%d%d%d",&a,&b,&c);
            Update(a,b,c,1,n,1);
        }
    }
    return 0;
}
