#include<iostream>
#include<algorithm>
using namespace std;
#define lson u<<1
#define rson u<<1|1
const int maxn=100010;
int st[maxn],ed[maxn];
int q[maxn],dat[maxn<<1];
struct Node{
    int lef,rig,delta;
}T[maxn<<2];
void Build(int u,int l,int r){
    T[u].lef=l;
    T[u].rig=r;
    T[u].delta=0;
    if(l==r)return;
    int mid=(l+r)>>1;
    Build(lson,l,mid);
    Build(rson,mid+1,r);
}
void PushDown(int u){
    if(T[u].delta>0){
        T[lson].delta+=T[u].delta;
        T[rson].delta+=T[u].delta;
        T[u].delta=0;
    }
}
void Update(int u,int l,int r){
    if(l<=T[u].lef&&T[u].rig<=r){T[u].delta++;return;}
    else {
        PushDown(u);
        if(l<=T[lson].rig)Update(lson,l,r);
        if(r>=T[rson].lef)Update(rson,l,r);
    }
}
int Query(int u,int index){
    if(T[u].lef==T[u].rig)return T[u].delta;
    else {
        PushDown(u);
        if(index<=T[lson].rig)return Query(lson,index);
        else return Query(rson,index);
    }
}
int main(){
    int t,n,m;
    int cnt;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++){
        scanf("%d%d",&n,&m);
        cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&st[i],&ed[i]);
            dat[cnt++]=st[i];
            dat[cnt++]=ed[i];
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&q[i]);
            dat[cnt++]=q[i];
        }
        sort(dat,dat+cnt);
        cnt=unique(dat,dat+cnt)-dat;
        Build(1,1,cnt);
        for(int i=1;i<=n;i++){
            st[i]=lower_bound(dat,dat+cnt,st[i])-dat+1;
            ed[i]=lower_bound(dat,dat+cnt,ed[i])-dat+1;
            Update(1,st[i],ed[i]);
        }
        printf("Case #%d:\n",cas);
        for(int i=1;i<=m;i++){
            q[i]=lower_bound(dat,dat+cnt,q[i])-dat+1;
            printf("%d\n",Query(1,q[i]));
        }
    }
}
