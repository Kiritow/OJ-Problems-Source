#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
using namespace std;
const int MAXN = 50010;
const int INF = 0x3f3f3f3f;
struct Node *null;
struct Node{
    Node *fa,*ch[2];
    int val;
    int Max,Min;
    int mm;
    int rmm;
    int rev,add;
    inline void clear(int _val){
        fa = ch[0] = ch[1] = null;
        val = Max = Min = _val;
        mm = 0;
        rmm = 0;
        rev = 0;
        add = 0;
    }
    inline void push_up(){
        if(this == null)return;
        mm = 0;
        mm = max(mm,ch[0]->mm);
        mm = max(mm,ch[1]->mm);
        mm = max(mm,max(val,ch[1]->Max)-ch[0]->Min);
        mm = max(mm,ch[1]->Max-min(ch[0]->Min,val));
        rmm = 0;
        rmm = max(rmm,ch[0]->rmm);
        rmm = max(rmm,ch[1]->rmm);
        rmm = max(rmm,max(val,ch[0]->Max)-ch[1]->Min);
        rmm = max(rmm,ch[0]->Max-min(ch[1]->Min,val));
        Max = max(val,max(ch[0]->Max,ch[1]->Max));
        Min = min(val,min(ch[0]->Min,ch[1]->Min));
    }
    inline void setc(Node *p,int d){
        ch[d] = p;
        p->fa = this;
    }
    inline bool d(){
        return fa->ch[1] == this;
    }
    inline bool isroot(){
        return fa == null || fa->ch[0] != this && fa->ch[1] != this;
    }
    inline void flip(){
        if(this == null)return;
        swap(ch[0],ch[1]);
        swap(mm,rmm);
        rev ^= 1;
    }
    inline void update_add(int w){
        if(this == null)return;
        val += w;
        Min += w;
        Max += w;
        add += w;
    }
    inline void push_down(){
        if(this == null)return;
        if(rev){
            ch[0]->flip(); ch[1]->flip(); rev = 0;
        }
        if(add){
            ch[0]->update_add(add);ch[1]->update_add(add);
            add = 0;
        }
    }
    inline void go(){
        if(!isroot())fa->go();
        push_down();
    }
    inline void rot(){
        Node *f = fa, *ff = fa->fa;
        int c = d(), cc = fa->d();
        f->setc(ch[!c],c);
        this->setc(f,!c);
        if(ff->ch[cc] == f)ff->setc(this,cc);
        else this->fa = ff;
        f->push_up();
    }
    inline Node* splay(){
        go();
        while(!isroot()){
            if(!fa->isroot())
                d()==fa->d() ? fa->rot() : rot();
            rot();
        }
        push_up();
        return this;
    }
    inline Node* access(){
        for(Node *p = this, *q = null; p != null; q = p, p = p->fa){
            p->splay()->setc(q,1);
            p->push_up();
        }
        return splay();
    }
    inline void make_root(){
        access()->flip();
    }
};
Node pool[MAXN],*tail;
Node *node[MAXN];
struct Edge{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
}
inline void addedge(int u,int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int g[MAXN];
int fa[MAXN];
void bfs(int s){
    int l,r;
    g[l=r=1] = s;
    fa[s] = s;
    while(l <= r){
        int u = g[l++];
        for(int i = head[u];i != -1;i = edge[i].next){
            int v = edge[i].to;
            if(v == fa[u])continue;
            fa[v] = u;
            node[v]->fa = node[u];
            g[++r] = v;
        }
    }
}
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    assert(T > 0 && T <= 10);
    while(T--){
        scanf("%d",&n);
        tail = pool;
        null = tail++;
        null->fa = null->ch[0] = null->ch[1] = null;
        null->Max = -INF;
        null->Min = INF;
        null->mm = 0;
        null->add = null->rev = 0;
        int w;
        for(int i = 1;i <= n;i++){
            scanf("%d",&w);
            node[i] = tail++;
            node[i]->clear(w);
        }
        init();
        int u,v;
        for(int i = 1;i < n;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        bfs(1);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            node[u]->make_root();
            node[v]->access();
            printf("%d\n",node[v]->mm);
            node[v]->update_add(w);
        }
    }
    return 0;
}
