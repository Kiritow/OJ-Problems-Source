#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define lson u<<1
#define rson u<<1|1
#define MAXN 100010
int dat[MAXN];
struct Node {
    int lef,rig;
    int lsum,rsum,msum;
    int lz,rz,mz;
    int sum;
    int COVER,XOR;
}T[MAXN<<2];
void makeXOR(int u){
    swap(T[u].lsum,T[u].lz);
    swap(T[u].rsum,T[u].rz);
    swap(T[u].msum,T[u].mz);
    T[u].sum=T[u].rig-T[u].lef+1-T[u].sum;
}
void PushUp(int u){
    if(T[u].lef==T[u].rig)return;
    int len=T[u].rig-T[u].lef+1;
    T[u].lsum=T[lson].lsum;
    T[u].rsum=T[rson].rsum;
    if(T[u].lsum==(len+1)>>1)T[u].lsum+=T[rson].lsum;
    if(T[u].rsum==len>>1)T[u].rsum+=T[lson].rsum;
    T[u].msum=max(T[lson].msum,T[rson].msum);
    T[u].msum=max(T[u].msum,T[lson].rsum+T[rson].lsum);
    T[u].lz=T[lson].lz;
    T[u].rz=T[rson].rz;
    if(T[u].lz==(len+1)>>1)T[u].lz+=T[rson].lz;
    if(T[u].rz==len>>1)T[u].rz+=T[lson].rz;
    T[u].mz=max(T[lson].mz,T[rson].mz);
    T[u].mz=max(T[u].mz,T[lson].rz+T[rson].lz);
    T[u].sum=T[lson].sum+T[rson].sum;
}
void PushDown(int u){
    if(T[u].lef==T[u].rig)return;
    if(T[u].COVER!=-1){
        int len=T[u].rig-T[u].lef+1;
        T[lson].COVER=T[rson].COVER=T[u].COVER;
        T[lson].XOR=T[rson].XOR=0;
        T[lson].lsum=T[lson].rsum=T[lson].msum=T[u].COVER?(len+1)>>1:0;
        T[lson].lz=T[lson].rz=T[lson].mz=T[u].COVER?0:(len+1)>>1;
        T[lson].sum=T[u].COVER?(len+1)>>1:0;
        T[rson].lsum=T[rson].rsum=T[rson].msum=T[u].COVER?len>>1:0;
        T[rson].lz=T[rson].rz=T[rson].mz=T[u].COVER?0:len>>1;
        T[rson].sum=T[u].COVER?len>>1:0;
        T[u].COVER=-1;
    }
    if(T[u].XOR){
        T[u].XOR=0;
        T[lson].XOR^=1;
        T[rson].XOR^=1;
        makeXOR(lson);
        makeXOR(rson);
    }
}
void Build(int u,int l,int r){
    T[u].lef=l;
    T[u].rig=r;
    T[u].COVER=-1;
    T[u].XOR=0;
    if(l==r){
        T[u].lsum=T[u].rsum=T[u].msum=(dat[l]==1);
        T[u].lz=T[u].rz=T[u].mz=(dat[l]==0);
        T[u].sum=dat[l];
        T[u].COVER=dat[l];
        return;
    }
    int mid=(l+r)>>1;
    Build(lson,l,mid);
    Build(rson,mid+1,r);
    PushUp(u);
}
void Update(int u,int l,int r,int op){
    PushDown(u);
    if(l<=T[u].lef&&T[u].rig<=r){
        if(op<2){
            int len=T[u].rig-T[u].lef+1;
            T[u].COVER=op;
            T[u].lsum=T[u].rsum=T[u].msum=op?len:0;
            T[u].lz=T[u].rz=T[u].mz=op?0:len;
            T[u].sum=op?len:0;
        }
        else {
            T[u].XOR=1;
            makeXOR(u);
        }
    }
    else {
        if(l<=T[lson].rig)Update(lson,l,r,op);
        if(r>=T[rson].lef)Update(rson,l,r,op);
        PushUp(u);
    }
}
int Query(int u,int l,int r,int op){
    PushDown(u);
    if(l<=T[u].lef&&T[u].rig<=r){
        if(op==3)return T[u].sum;
        else return T[u].msum;
    }
    else {
        if(r<=T[lson].rig)return Query(lson,l,r,op);
        if(l>=T[rson].lef)return Query(rson,l,r,op);
        if(op==3) return Query(lson,l,T[lson].rig,op)+Query(rson,T[rson].lef,r,op);
        int ret=min(T[lson].rsum,T[lson].rig-l+1)+min(T[rson].lsum,r-T[rson].lef+1);
        int ans=max(Query(lson,l,T[lson].rig,op),Query(rson,T[rson].lef,r,op));
        return max(ans,ret);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        int cmd,a,b;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d",dat+i);
        Build(1,1,n);
        while(m--){
            scanf("%d%d%d",&cmd,&a,&b);
            a++,b++;
            if(cmd<3)Update(1,a,b,cmd);
            else printf("%d\n",Query(1,a,b,cmd));
        }
    }
    return 0;
}
