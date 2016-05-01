#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <cstdio>

using namespace std;
const int maxn=100010;

struct Q{
    int l,r,a,b,sum;
}tr[maxn*20];

int fir[maxn],cnt;
int n,k,Sot[maxn],h[maxn],pos;

void Build(int a,int b,int &rt)
{
    int md=(a+b)>>1;
    rt=++cnt;
    tr[rt].a=a;
    tr[rt].b=b;
    if(a==b)return;
    Build(a,md,tr[rt].l);
    Build(md+1,b,tr[rt].r);
}

void Add(int pre,int &rt,int a,int b)
{
    rt=++cnt;
    tr[rt].l=tr[pre].l;
    tr[rt].r=tr[pre].r;
    tr[rt].a=tr[pre].a;
    tr[rt].b=tr[pre].b;

    tr[rt].sum=tr[pre].sum+1;

    if(a<b){
        int md=(a+b)>>1;

        if(pos<=md)Add(tr[pre].l,tr[rt].l,a,md);
        else Add(tr[pre].r,tr[rt].r,md+1,b);
    }
}
#define Cmp(x) tr[tr[x].l].sum
int Query(int pre,int rt,int a,int b,int K)
{
    if(a==b) return Sot[a]; 

    int md=(a+b)>>1;

    int D=Cmp(rt)-Cmp(pre);
    if(D<K){
        return Query(tr[pre].r,tr[rt].r,md+1,b,K-D);
    }
    else{
        return Query(tr[pre].l,tr[rt].l,a,md,K);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;Sot[i]=h[i],i++)scanf("%d",&h[i]);
    sort(Sot+1,Sot+n+1);
    Build(1,n,fir[0]);
    for(int i=1;i<=n;i++){
        pos=lower_bound(Sot+1,Sot+n+1,h[i])-Sot;
        Add(fir[i-1],fir[i],1,n);
    }
    for(int i=1;i<=k;i++)
    {
        int l,r,ks;
        scanf("%d%d%d",&l,&r,&ks);
        printf("%d\n",Query(fir[l-1],fir[r],1,n,ks));
    }
    return 0;
}
