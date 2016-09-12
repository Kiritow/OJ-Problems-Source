#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=100000+100;
const LL LL_INF=numeric_limits<LL>::max();
#define lson L,mid,rt<<1
#define rson mid+1,R,rt<<1|1
long long X[4],Y[4];
long long tx[MAXN],ty[MAXN];
struct Tree {
    long long maX[4],maY[4],addx,addy,sum[4];
}tr[MAXN<<2];
void pushup(int rt){
    for(int i=0;i<4;i++){
        tr[rt].maX[i]=max(tr[rt<<1].maX[i],tr[rt<<1|1].maX[i]);
        tr[rt].maY[i]=max(tr[rt<<1].maY[i],tr[rt<<1|1].maY[i]);
        tr[rt].sum[i]=tr[rt<<1].sum[i]+tr[rt<<1|1].sum[i];
    }
}
void pushdown(int rt){
    if(tr[rt].addx){
        tr[rt<<1].addx+=tr[rt].addx;
        tr[rt<<1|1].addx+=tr[rt].addx;
        for(int i=0;i<4;i++){
            tr[rt<<1].maX[i]+=tr[rt].addx;
            tr[rt<<1|1].maX[i]+=tr[rt].addx;
        }
        tr[rt].addx=0;
    }
    if(tr[rt].addy){
        tr[rt<<1].addy+=tr[rt].addy;
        tr[rt<<1|1].addy+=tr[rt].addy;
        for(int i=0;i<4;i++){
            tr[rt<<1].maY[i]+=tr[rt].addy;
            tr[rt<<1|1].maY[i]+=tr[rt].addy;
        }
        tr[rt].addy=0;
    }
}
void build(int L,int R,int rt){
    tr[rt].addy=tr[rt].addx=0;
    if(L==R){
        for(int i=0;i<4;i++){
            tr[rt].maX[i]=tx[L];
            tr[rt].maY[i]=ty[L];
            tr[rt].sum[i]=1;
        }
        return ;
    }
    int mid=(L+R)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int rt,int l,int r,long long v,int flag){
    if(l<=L&&R<=r){
        if(flag==0){
            for(int i=0;i<4;i++) tr[rt].maX[i]+=v;
            tr[rt].addx+=v;
        }
        else {
            for(int i=0;i<4;i++) tr[rt].maY[i]+=v;
            tr[rt].addy+=v;
        }
        return ;
    }
    pushdown(rt);
    int mid=(L+R)>>1;
    if(l<=mid)update(lson,l,r,v,flag);
    if(r>mid)update(rson,l,r,v,flag);
    pushup(rt);
}
void adjust(int L,int R,int rt){
    int mid=(L+R)>>1;
    for(int i=0;i<4;i++){
        if(tr[rt].maX[i]>X[i]||tr[rt].maY[i]>Y[i]){
            if(L==R){
                tr[rt].maX[i]=LL_INF+1;
                tr[rt].maY[i]=LL_INF+1;
                tr[rt].sum[i]=0;
                continue;
            }
            pushdown(rt);
            adjust(lson);adjust(rson);
            pushup(rt);
        }
    }
}
LL query(int L,int R,int rt,int l,int r,int f){
    if(l<=L&&R<=r)return tr[rt].sum[f];
    int mid=(L+R)>>1;
    LL ans=0;
    if(l<=mid)ans+=query(lson,l,r,f);
    if(r>mid)ans+=query(rson,l,r,f);
    return ans;
}
int main()
{
    int n,m,t;
    int xx1,xx2,yy1,yy2;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d%d%d%d",&xx1,&yy1,&xx2,&yy2);
        X[0]=xx2;Y[0]=yy2;
        X[1]=xx1-1;Y[1]=yy2;
        X[2]=xx2;Y[2]=yy1-1;
        X[3]=xx1-1;Y[3]=yy1-1;
        for(int i=1;i<=n;i++){
            scanf("%I64d%I64d",&tx[i],&ty[i]);
        }
        build(1,n,1);
        int type,d,tl,tr;
        scanf("%d",&m);
        while(m--){
            scanf("%d",&type);
            if(type==1){
                scanf("%d%d%d",&tl,&tr,&d);
                update(1,n,1,tl,tr,(LL)d,0);
            }
            if(type==2){
                scanf("%d%d%d",&tl,&tr,&d);
                update(1,n,1,tl,tr,(LL)d,1);
            }
            if(type==3){
                adjust(1,n,1);
                scanf("%d%d",&tl,&tr);
                LL ans=query(1,n,1,tl,tr,0)-query(1,n,1,tl,tr,1)-query(1,n,1,tl,tr,2)+query(1,n,1,tl,tr,3);
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
