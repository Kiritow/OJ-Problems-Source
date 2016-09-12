#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define maxn 200007
#define inf  1000000000
#define ll long long
ll mod = 1000000007;
struct Node{
    Node *fa,*ch[2];
    bool rev,root;
    ll val,s1,s2,s3,s4;
};
Node pool[maxn];
Node *nil,*tree[maxn];
int cnt = 0;
void init(){
    cnt = 1;
    nil = tree[0] = pool;
    nil->ch[0] = nil->ch[1] = nil;
    nil->s1 = nil->s2 = nil->val = nil->s3 = nil->s4 = 0;
}
Node *newnode(ll val,Node *f){ 
    pool[cnt].fa = f;
    pool[cnt].ch[0]=pool[cnt].ch[1]=nil;
    pool[cnt].rev = false;
    pool[cnt].root = true;
    pool[cnt].val = val;
    pool[cnt].s1 = 0;
    pool[cnt].s2 = 0;
    pool[cnt].s3 = 0;
    pool[cnt].s4 = 0;
    return &pool[cnt++];
}
void update_rev(Node *x){
    if(x == nil) return ;
    x->rev = !x->rev;
    swap(x->ch[0],x->ch[1]);
}
void update(Node *x){
    if(x == nil) return ;
    x->s2 = x->s1 + x->val;
    x->s4 = x->s3;
    if(x->ch[0] != nil){
        x->s2 += x->ch[0]->s2;
        if(x->s2 >= mod)
            x->s2 -= mod;
        x->s4 += x->ch[0]->s4;
        x->s4 %= mod;
    }
    if(x->ch[1] != nil){
        x->s2 += x->ch[1]->s2;
        if(x->s2 >= mod)
            x->s2 -= mod;
        x->s4 += x->ch[1]->s4;
        x->s4 %= mod;
    }
}
void pushdown(Node *x){
    if(x->rev != false){
        update_rev(x->ch[0]);
        update_rev(x->ch[1]);
        x->rev = false;
    }
}
void push(Node *x){
    if(!x->root) push(x->fa);
    pushdown(x);
}
void rotate(Node *x){
    Node *f = x->fa, *ff = f->fa;
    int t = (f->ch[1] == x);
    if(f->root)
        x->root = true, f->root = false;
    else ff->ch[ff->ch[1] == f] = x;
    x->fa = ff;
    f->ch[t] = x->ch[t^1];
    x->ch[t^1]->fa = f;
    x->ch[t^1] = f;
    f->fa = x;
    update(f);
}
void splay(Node *x){
    push(x);
    Node *f, *ff;
    while(!x->root){
        f = x->fa,ff = f->fa;
        if(!f->root)
            if((ff->ch[1]==f)&&(f->ch[1] == x)) rotate(f);
            else rotate(x);
        rotate(x);
    }
    update(x);
}
Node *access(Node *x){
    Node *y = nil,*z;
    while(x != nil){
        splay(x);
        z = x->ch[1];
        x->ch[1]->root = true;
        (x->ch[1] = y)->root = false;
        update(z);
        x->s1 += z->s2;
        x->s3 += (z->s2*z->s2);
        x->s1 %= mod;
        x->s3 %= mod;
        x->s1 -= y->s2;
        x->s3 -= y->s2*y->s2;
        x->s1 %= mod;
        x->s3 %= mod;
        update(x);
        y = x;
        x = x->fa;
    }
    return y;
}
void be_root(Node *x){
    access(x);
    splay(x);
    update_rev(x);
}
int value[maxn];
vector<int> head[maxn];
void dfs(int u,int f){
    tree[u]->fa = tree[f];
    for(int i = 0;i < head[u].size() ;i++){
        int v = head[u][i];
        if(v == f) continue;
        dfs(v,u);
        tree[u]->s1 += tree[v]->s2;
        tree[u]->s1 %= mod;
        tree[u]->s3 += tree[v]->s2*tree[v]->s2;
        tree[u]->s3 %= mod;
    }
    update(tree[u]);
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i = 1;i <= n; i++)
            scanf("%d",&value[i]);
        for(int i = 0;i <= n; i++)
            head[i].clear();
        int u,v;
        for(int i = 1;i < n; i++){
            scanf("%d%d",&v,&u);
            head[v].push_back(u);
            head[u].push_back(v);
        }
        init();
        for(int i=1;i <= n;i++)
            tree[i] = newnode(value[i],nil);
        dfs(1,0);
        ll total = 0;
        for(int i = 1;i <= n; i++)
            total += value[i];
        total %= mod;
        int t;
        for(int i = 0;i < m; i++){
            scanf("%d%d%d",&t,&u,&v);
            if(t == 1){
                be_root(tree[u]);
                access(tree[u]);
                total = total + v - tree[u]->val;
                total %= mod;
                tree[u]->val = v;
                update(tree[u]);
            }
            else {
                be_root(tree[u]);
                access(tree[v]);
                splay(tree[v]);
                ll ans = total*total%mod-tree[v]->s4;
                ans = (ans%mod+mod)%mod;
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
