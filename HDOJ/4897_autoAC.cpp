#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ls (p<<1)
#define rs (p<<1|1)
#define NN 201000
int en[NN],fi[NN],te,ne[NN],v[NN];
int tp;
int siz[NN],son[NN],top[NN],fa[NN],dep[NN],tid[NN],ran[NN];
void addedge(int a,int b){
    ++te;ne[te]=fi[a];fi[a]=te;v[te]=b;
    ++te;ne[te]=fi[b];fi[b]=te;v[te]=a;
}
void dfs1(int u,int father,int d){
    siz[u]=1;
    dep[u]=d;
    fa[u]=father;
    int e,vv;
    for(e=fi[u];e!=-1;e=ne[e]){
        vv=v[e];
        if (vv!=father){
            dfs1(vv,u,d+1);
            siz[u]+=siz[vv];
            if (son[u]==-1||siz[vv]>siz[son[u]]){
                son[u]=vv;
            }
        }
    }
}
void dfs2(int u,int ttop){
    top[u]=ttop;
    tid[u]=++tp;
    ran[tid[u]]=u;
    if (son[u]==-1) return;
    dfs2(son[u],ttop);
    int e,vv;
    for(e=fi[u];e!=-1;e=ne[e]){
        vv=v[e];
        if (vv!=fa[u]&&vv!=son[u]){
            dfs2(vv,vv);
        }
    }
}
struct segtree{
    int l,r,tag1,tag2,rev1,rev2;
}t[NN*4];
inline void Rev(int p,int func){
    if (func==1) {t[p].rev1^=1;t[p].tag1=t[p].r+1-t[p].l-t[p].tag1;}
    if (func==2) {t[p].rev2^=1;t[p].tag2^=1;}
}
void lazy(int p){
    if (t[p].l==t[p].r) {t[p].rev1=t[p].rev2=0;return;}
    if (t[p].rev1!=0) {
        t[p].rev1=0;
        Rev(ls,1);
        Rev(rs,1);
    }
    if (t[p].rev2!=0) {
        t[p].rev2=0;
        Rev(ls,2);
        Rev(rs,2);
    }
}
void build(int l,int r,int p){
    t[p].l=l;t[p].r=r;
    t[p].tag1=t[p].tag2=t[p].rev1=t[p].rev2=0;
    if (l==r){return;}
    int m=l+r>>1;
    build(l,m,ls);
    build(m+1,r,rs);
}
inline void update(int p){
    t[p].tag1=t[ls].tag1+t[rs].tag1;
}
void rev(int l,int r,int func,int p){
    if (l>r) return;
    if (t[p].l==l&&t[p].r==r){
        Rev(p,func);
        return;
    }
    lazy(p);
    int m=t[p].l+t[p].r>>1;
    if (r<=m) rev(l,r,func,ls);
    else if (l>m) rev(l,r,func,rs);
    else {
        rev(l,m,func,ls);
        rev(m+1,r,func,rs);
    }
    update(p);
}
int query(int l,int r,int p){
    if (l>r) return 0;
    if (t[p].l==l&&t[p].r==r){
        return t[p].tag1;
    }
    lazy(p);
    int m=t[p].l+t[p].r>>1;
    if (r<=m) return query(l,r,ls);
    else if (l>m) return query(l,r,rs);
    else {
        return query(l,m,ls)+query(m+1,r,rs);
    }
    update(p);
}
int querytag2(int pos,int p){
    if (t[p].l==t[p].r) return t[p].tag2;
    lazy(p);
    int m=t[p].l+t[p].r>>1;
    if (pos<=m) return querytag2(pos,ls);
    else return querytag2(pos,rs);
    update(p);
}
void linerev(int a,int b){
    while(top[a]!=top[b]){
        if (dep[top[a]]<dep[top[b]]) swap(a,b);
        rev(tid[top[a]],tid[a],1,1);
        a=fa[top[a]];
    }
    if (dep[a]>dep[b]) swap(a,b);
    rev(tid[a]+1,tid[b],1,1);
}
void linerevadj(int a,int b){
    while(top[a]!=top[b]){
        if (dep[top[a]]<dep[top[b]]) swap(a,b);
        rev(tid[top[a]],tid[a],2,1);
        int faa=fa[top[a]];
        if (son[faa]==top[a]) rev(tid[top[a]],tid[top[a]],1,1);
        if (son[a]!=-1) rev(tid[son[a]],tid[son[a]],1,1);
        a=fa[top[a]];
    }
    if (dep[a]>dep[b]) swap(a,b);
    rev(tid[a],tid[b],2,1);
    int faa=fa[a];
    if (faa!=0&&son[faa]==a) rev(tid[a],tid[a],1,1);
    if (son[b]!=-1) rev(tid[son[b]],tid[son[b]],1,1);
}
int linequery(int a,int b){
    int ret=0;
    while(top[a]!=top[b]){
        if (dep[top[a]]<dep[top[b]]) swap(a,b);
        ret+=query(tid[top[a]]+1,tid[a],1);
        ret+=(querytag2(tid[fa[top[a]]],1)^querytag2(tid[top[a]],1)^query(tid[top[a]],tid[top[a]],1));
        a=fa[top[a]];
    }
    if (dep[a]>dep[b]) swap(a,b);
    ret+=query(tid[a]+1,tid[b],1);
    return ret;
}
int main(){
    int cas,n,q,i,a,b,c;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        memset(fi,-1,sizeof(fi));
        te=0;
        for(i=1;i<n;++i){
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        memset(son,-1,sizeof(son));
        tp=0;
        dfs1(1,0,0);
        dfs2(1,1);
        build(1,tp,1);
        scanf("%d",&q);
        for(i=1;i<=q;++i){
            scanf("%d%d%d",&a,&b,&c);
            if (a==1){
                if (b==c) continue;
                linerev(b,c);
            }
            else if (a==2){
                linerevadj(b,c);
            }
            else if (a==3){
                printf("%d\n",linequery(b,c));
            }
        }
    }
    return 0;
}
