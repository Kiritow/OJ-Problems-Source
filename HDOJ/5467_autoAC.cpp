#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long LL;
#define mp(x, y) make_pair(x, y)
const int maxn = 300005;
const int maxm = 300005;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
struct node *null;
struct node
{
    int size, rev;
    LL val, sum;
    node *fa, *ch[2];
    void init()
    {
        rev = val = sum = 0;
        fa = ch[0] = ch[1] = null;
    }
    inline bool d()
    {
        return fa->ch[1] == this;
    }
    inline bool isroot()
    {
        return fa == null || fa->ch[0] != this && fa->ch[1] != this;
    }
    inline void setc(node *p, int d)
    {
        ch[d] = p;
        p->fa = this;
    }
    inline void pushup()
    {
        sum = ch[0]->sum * ch[1]->sum % mod * ((val - 1) * val / 2) % mod;
    }
    inline void flip()
    {
        if(this == null) return;
        swap(ch[0], ch[1]);
        rev ^= 1;
    }
    inline void pushdown()
    {
        if(rev) {
            ch[0]->flip();
            ch[1]->flip();
            rev = 0;
        }
    }
    inline void go()
    {
        if(!isroot()) fa->go();
        pushdown();
    }
    void rot()
    {
        node *f = fa, *ff = fa->fa;
        int c = d(), cc = fa->d();
        f->setc(ch[!c], c);
        this->setc(f, !c);
        if(ff->ch[cc] == f) ff->setc(this, cc);
        else this->fa = ff;
        f->pushup();
    }
    node* splay()
    {
        go();
        while(!isroot()) {
            if(!fa->isroot()) d() == fa->d() ? fa->rot() : rot();
            rot();
        }
        pushup();
        return this;
    }
    node* access()
    {
        for(node *p = this, *q = null; p != null; q = p, p = p->fa) {
            p->splay()->setc(q, 1);
            p->pushup();
        }
        return splay();
    }
    inline void makeroot()
    {
        access()->flip();
    }
    node* getroot() {
        node *x;
        for(x = access(); x->pushdown(), x->ch[0] != null; x = x->ch[0]);
        return x;
    }
    void cut()
    {
        access();
        ch[0]->fa = null;
        ch[0] = null;
        pushup();
    }
    void cut(node *o)
    {
        makeroot();
        o->cut();
    }
    void link(node *p)
    {
        makeroot();
        fa = p;
    }
}*Node[maxn], pool[maxm], *tail;
struct ope
{
    int kk, u, v;
    ope(int kk = 0, int u = 0, int v = 0) : kk(kk), u(u), v(v) {}
}op[maxn];
struct Edge
{
    int v;
    Edge *next;
}*H[maxn], *edges, E[maxn];
vector<int> to[maxn];
LL res[maxn];
int T[maxn];
int a[maxn];
int n, m;
void addedges(int u, int v)
{
    edges->v = v;
    edges->next = H[u];
    H[u] = edges++;
}
node* newnode(int val)
{
    tail->init();
    tail->val = val;
    tail->sum = tail->val * (tail->val - 1) / 2;
    return tail++;
}
void init()
{
    tail = pool;
    null = newnode(1);
    null->sum = 1;
    edges = E;
    memset(H, 0, sizeof H);
    memset(T, 0, sizeof T);
    memset(res, -1, sizeof res);
}
bool add(int u, int v)
{
    if(u == v) return 0;
    if(Node[u]->getroot() == Node[v]->getroot()) return 0;
    Node[u]->link(Node[v]);
    return true;
}
bool del(int u, int v)
{
    if(u == v) return 0;
    if(Node[u]->getroot() != Node[v]->getroot()) return 0;
    Node[u]->makeroot();
    Node[v]->access();
    if(Node[v]->ch[0] != Node[u] || Node[u]->ch[1] != null) return 0; 
    else Node[v]->cut(Node[u]);
    return 1;
}
LL query(node *a, node *b)
{
    a->access();
    for(a = null; b != null; a = b, b = b->fa) {
        b->splay();
        if(b->fa == null) return b->ch[1]->sum * a->sum % mod * (b->val * (b->val - 1) / 2) % mod;
        b->setc(a, 1);
        b->pushup();
    }
}
void modify(int u, LL val)
{
    Node[u]->access();
    Node[u]->val = val;
    Node[u]->pushup();
}
void dfs(int ti)
{
    LL tmp = 0;
    int flag = 0;
    if(op[ti].kk == 1) flag = add(op[ti].u, op[ti].v);
    if(op[ti].kk == 2) flag = del(op[ti].u, op[ti].v);
    if(op[ti].kk == 4) {
        if(Node[op[ti].u]->getroot() != Node[op[ti].v]->getroot()) res[ti] = 0;
        else res[ti] = query(Node[op[ti].u], Node[op[ti].v]);
    }
    if(op[ti].kk == 5) {
        tmp = a[op[ti].u];
        a[op[ti].u] = op[ti].v;
        modify(op[ti].u, op[ti].v);
    }
    for(Edge *e = H[ti]; e; e = e->next) dfs(e->v);
    if(op[ti].kk == 2 && flag) add(op[ti].u, op[ti].v);
    if(op[ti].kk == 1 && flag) del(op[ti].u, op[ti].v);
    if(op[ti].kk == 5) {
        a[op[ti].u] = tmp;
        modify(op[ti].u, tmp);
    }
}
void work()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) to[i].clear();
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) Node[i] = newnode(a[i]);
    for(int i = 1; i <= m; i++) {
        int kk, u, v;
        scanf("%d", &kk);
        if(kk == 3) scanf("%d", &u), T[i] = u;
        else scanf("%d%d", &u, &v), T[i] = i-1;
        op[i] = ope(kk, u, v);
    }
    for(int i = 1; i <= m; i++) addedges(T[i], i);
    dfs(0);
    for(int i = 1; i <= m; i++) if(res[i] != -1) printf("%lld\n", res[i]);
}
int main()
{
    int _;
    scanf("%d", &_);
    while(_--) {
        init();
        work();
    }
    return 0;
}
