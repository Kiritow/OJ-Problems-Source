#include<stdio.h>
#include<algorithm>
#define N 100010
int T[N];
int num[N];
int san[N];
int ls[N*20];
int rs[N*20];
int sum[N*20];
int tot,rt;
int n, m;
void Build(int l,int r,int &rt)
{
    rt=++tot;
    sum[rt]=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    Build(l,m,ls[rt]);
    Build(m+1,r,rs[rt]);
}
void Update(int last,int p,int l,int r,int &rt)
{
    rt=++tot;
    ls[rt]=ls[last];
    rs[rt]=rs[last];
    sum[rt]=sum[last]+1;
    if(l==r) return ;
    int m=(l+r)>>1;
    if(p<=m) Update(ls[last],p,l,m,ls[rt]);
    else     Update(rs[last],p,m+1,r,rs[rt]);
}
int Query(int ss,int tt,int l,int r,int k)
{
    if(l==r) return l;
    int m=(l+r)>>1;
    int cnt=sum[ls[tt]]-sum[ls[ss]];
    if(k<=cnt)
        return Query(ls[ss],ls[tt],l,m,k);
    else
        return Query(rs[ss],rs[tt],m+1,r,k-cnt);
}
void gogogo()
{
    int l,r,k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        san[i]=num[i];
    }
    tot=0;
    std::sort(san+1,san+n+1);
    int cnt=std::unique(san+1,san+n+1)-san-1;
    Build(1,cnt,T[0]);
    for(int i=1;i<=n;i++)   num[i]=std::lower_bound(san+1,san+cnt+1,num[i])-san;
    for(int i=1;i<=n;i++)     Update(T[i-1],num[i],1,cnt,T[i]);
    while(m--)
    {
        scanf("%d%d%d",&l,&r,&k);
        int id=Query(T[l-1],T[r],1,cnt,k);
        printf("%d\n",san[id]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        gogogo();
    }
    return 0;
}
