#pragma comment(linker,"/STACK:1024000000,1024000000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<map>
using namespace std;
const int N = 100005;
#define LL __int64
struct EDG{
    int to,next;
}edg[N*2];
int eid,head[N];
int fath[N],deep[N],top[N],num[N],son[N],p[N],pos;
void init(){
    pos=0; eid=0;
    memset(head,-1,sizeof(head));
}
void addEdg(int u,int v){
    edg[eid].to=v; edg[eid].next=head[u]; head[u]=eid++;
    edg[eid].to=u; edg[eid].next=head[v]; head[v]=eid++;
}
void dfs(int u,int pre,int d){
    fath[u]=pre; num[u]=1; deep[u]=d; son[u]=-1;
    for(int i=head[u]; i!=-1; i=edg[i].next){
        int v=edg[i].to;
        if(v==pre)continue;
        dfs(v,u,d+1);
        num[u]+=num[v];
        if(son[u]==-1||num[son[u]]<num[v])
            son[u]=v;
    }
}
void getpos(int u,int root){
    top[u]=root;
    p[u]=++pos;
    if(son[u]==-1)
        return ;
    getpos(son[u],root);
    for(int i=head[u]; i!=-1; i=edg[i].next){
        int v=edg[i].to;
        if(son[u]==v||v==fath[u])
            continue;
        getpos(v,v);
    }
}
int root[N*3]; 
int a[N];
void build(int l,int r,int k){
    if(l==r){
       root[k]=a[l];
       return ;
    }
    int m=(l+r)>>1;
    build(l,m,k<<1);
    build(m+1,r,k<<1|1);
    root[k]=root[k<<1]^root[k<<1|1];
}
void updata(int l,int r,int k,int id,int vule){
    if(l==r){
        root[k]=vule;
        return ;
    }
    int m=(l+r)>>1;
    if(id<=m)
        updata(l,m,k<<1,id,vule);
    else
        updata(m+1,r,k<<1|1,id,vule);
    root[k]=root[k<<1]^root[k<<1|1];
}
int query(int l,int r,int k,int L,int R){
    if(L<=l&&r<=R){
        return root[k];
    }
    int m=(l+r)>>1 , ans=0;
    if(L<=m)
       ans^= query(l,m,k<<1,L,R);
    if(m<R)
        ans^=query(m+1,r,k<<1|1,L,R);
    return ans;
}
void swp(int &aa,int &bb){
    int tt=aa; aa=bb; bb=tt;
}
int Operat(int u,int v){
    int fu=top[u] , fv=top[v],ans=0;
    while(fu!=fv){
        if(deep[fu]<deep[fv]){
            swp(fu,fv); swp(u,v);
        }
       ans^= query(1,pos,1,p[fu],p[u]);
       u=fath[fu]; fu=top[u];
    }
    if(deep[u]>deep[v])
        swp(u,v);
    ans^=query(1,pos,1,p[u],p[v]);
    return ans;
}
int main()
{
   int T,n,q,val[N],u,v;
   scanf("%d",&T);
   while(T--){
    scanf("%d%d",&n,&q);
    init();
    for(int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        addEdg(u,v);
    }
    for(int i=1; i<=n; i++){
        scanf("%d",&val[i]);
        val[i]++;
    }
    dfs(1,1,1);
    getpos(1,1);
    for(int i=1; i<=n; i++)
        a[p[i]]=val[i];
    build(1,pos,1);
    while(q--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==0)
            updata(1,pos,1,p[x],y+1);
        else{
            printf("%d\n",Operat(x,y)-1);
        }
    }
   }
    return 0;
}
