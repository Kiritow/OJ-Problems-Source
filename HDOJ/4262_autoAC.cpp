#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson u<<1
#define rson u<<1|1
#define MAXN 100005
int map[MAXN];
struct Node{
    int lef,rig;
    int sum;
}T[MAXN<<2];
void PushUp(int u){
    T[u].sum=T[lson].sum+T[rson].sum;
}
void Build(int u,int l,int r){
    T[u].lef=l;
    T[u].rig=r;
    if(l==r){T[u].sum=1;return;}
    int mid=(l+r)>>1;
    Build(lson,l,mid);
    Build(rson,mid+1,r);
    PushUp(u);
}
void Update(int u,int pos,int val){
    if(T[u].lef==T[u].rig){T[u].sum=val;return;}
    if(pos<=T[lson].rig)Update(lson,pos,val);
    else Update(rson,pos,val);
    PushUp(u);
}
int Query(int u,int l,int r){
        if(l<=T[u].lef&&T[u].rig<=r)return T[u].sum;
        if(r<=T[lson].rig)return Query(lson,l,r);
        if(l>=T[rson].lef)return Query(rson,l,r);
        return Query(lson,l,T[lson].rig)+Query(rson,T[rson].lef,r);
}
int main(){
    int n;
    while(scanf("%d",&n)&&n){
        int tmp;
        for(int i=1;i<=n;i++){
            scanf("%d",&tmp);
            map[tmp]=i;
        }
        Build(1,1,n);
        int cur=1;
        __int64 ans=n;
        for(int i=1;i<n;i++){
            if(i==1)tmp=Query(1,cur,map[i])-1;
            else if(map[i]>cur)tmp=Query(1,cur+1,map[i])-1;
            else tmp=Query(1,map[i],cur-1);
            ans+=min(tmp,n-i+1-tmp);
            Update(1,map[i],0);
            cur=map[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
