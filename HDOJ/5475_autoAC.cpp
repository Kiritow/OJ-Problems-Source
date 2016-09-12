#include <cstdio>
#include <cstring>
#include <algorithm>
#include  <iostream>
using namespace std;
typedef long long ll;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=155555;
ll sum[maxn*4+4];
int add;
int a[maxn];
int L,R;
int MOD;
int p;
void pushup(int rt){
    sum[rt]=sum[rt<<1]*sum[rt<<1|1]%MOD;
}
void build(int l,int r,int rt){
    if(l==r){
        sum[rt]=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int l,int r,int rt){
    if(l==r){
        sum[rt]=add;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(lson);
    else
        update(rson);
    pushup(rt);
}
ll query(int l,int r,int rt){
    ll ret=1;
    if(L<=l&&R>=r)
        return sum[rt];
    int m=(l+r)>>1;
    if(L<=m)
        ret*=query(lson)%MOD;
    if(R>m)
        ret*=query(rson)%MOD;
    return ret%MOD;
}
int main()
{
    int n,m;
    int op,u,q;
    int t;
    scanf("%d",&t);
    for(int case1=1;case1<=t;case1++){
        printf("Case #%d:\n",case1);
        scanf("%d%d",&q,&MOD);
        build(1,q,1);
        for(int i=1;i<=q;i++){
            scanf("%d%d",&op,&u);
            if(op==1){
                p=i;
                add=u;
                update(1,q,1);
                L=1;
                R=i;
                printf("%I64d\n",query(1,q,1)%MOD);
            }
            else{
                p=u;
                add=1;
                update(1,q,1);
                L=1;
                R=i;
                printf("%I64d\n",query(1,q,1)%MOD);
            }
        }
    }
    return 0;
}
