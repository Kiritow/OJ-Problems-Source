#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
#define FOR(i, n) for(int i = 0; i < n; ++i)
const int MAXV = 100010;
const int MAXE = MAXV << 1;
const int INF = 0x3f3f3f3f;
const int NINF = -INF;
struct LCT {
    struct Node {
        Node *ch[2], *fa;
        int val, set, add;
        int max[2], cnt[2], size;
        bool rt, rev;
    } statePool[MAXV], *nil;
    int ncnt;
    int head[MAXV], val[MAXV], ecnt;
    int to[MAXE], next[MAXE];
    int n, m, T;
    Node *ptr[MAXV];
    LCT() {
        ptr[0] = nil = statePool;
        nil->size = 0;
        FOR(k, 2) nil->max[k] = NINF;
    }
    void init() {
        memset(head + 1, -1, n * sizeof(int));
        ncnt = 1;
        ecnt = 0;
    }
    void add_edge(int u, int v) {
        to[ecnt] = v; next[ecnt] = head[u]; head[u] = ecnt++;
        to[ecnt] = u; next[ecnt] = head[v]; head[v] = ecnt++;
    }
    Node* new_node(int val, Node *f) {
        Node* x = &statePool[ncnt++];
        x->ch[0] = x->ch[1] = nil; x->fa = f;
        x->val = val; x->set = NINF; x->add = 0;
        x->max[0] = val; x->cnt[0] = 1;
        x->max[1] = NINF;
        x->size = 1;
        x->rt = true; x->rev = false;
        return x;
    }
    void dfs(int u, int f) {
        ptr[u] = new_node(val[u], ptr[f]);
        for(int p = head[u]; ~p; p = next[p]) {
            int v = to[p];
            if(v == f) continue;
            dfs(v, u);
        }
    }
    void get_max(int &a, int &b, int c) {
        if(a != c) {
            if(b < c) swap(b, c);
            if(a < b) swap(a, b);
        }
    }
    void cnt_max(int a, int &cnt, int b, int bcnt) {
        if(a != NINF && a == b) cnt += bcnt;
    }
    void update(Node *x) {
        x->size = x->ch[0]->size + x->ch[1]->size + 1;
        x->max[0] = x->val; x->max[1] = NINF;
        FOR(i, 2) FOR(j, 2)
            get_max(x->max[0], x->max[1], x->ch[i]->max[j]);
        FOR(k, 2) x->cnt[k] = 0;
        FOR(k, 2) cnt_max(x->max[k], x->cnt[k], x->val, 1);
        FOR(k, 2) FOR(i, 2) FOR(j, 2)
            cnt_max(x->max[k], x->cnt[k], x->ch[i]->max[j], x->ch[i]->cnt[j]);
    }
    void rotate(Node *x) {
        Node *y = x->fa;
        int t = (y->ch[1] == x);
        if(y->rt) y->rt = false, x->rt = true;
        else y->fa->ch[y->fa->ch[1] == y] = x;
        x->fa = y->fa;
        (y->ch[t] = x->ch[t ^ 1])->fa = y;
        (x->ch[t ^ 1] = y)->fa = x;
        update(y);
    }
    void update_set(Node *x, int val) {
        if(x == nil) return ;
        x->add = 0;
        x->val = x->set = val;
        x->max[0] = val; x->cnt[0] = x->size;
        x->max[1] = NINF;
    }
    void update_add(Node *x, int val) {
        if(x == nil) return ;
        x->add += val;
        x->val += val;
        FOR(k, 2) if(x->max[k] != NINF)
            x->max[k] += val;
    }
    void update_rev(Node *x) {
        if(x == nil) return ;
        x->rev = !x->rev;
        swap(x->ch[0], x->ch[1]);
    }
    void pushdown(Node *x) {
        if(x->set != NINF) {
            FOR(k, 2) update_set(x->ch[k], x->set);
            x->set = NINF;
        }
        if(x->add != 0) {
            FOR(k, 2) update_add(x->ch[k], x->add);
            x->add = 0;
        }
        if(x->rev) {
            FOR(k, 2) update_rev(x->ch[k]);
            x->rev = false;
        }
    }
    void push(Node *x) {
        if(!x->rt) push(x->fa);
        pushdown(x);
    }
    void splay(Node *x) {
        push(x);
        while(!x->rt) {
            Node *f = x->fa, *ff = f->fa;
            if(!f->rt) rotate(((ff->ch[1] == f) && (f->ch[1] == x)) ? f : x);
            rotate(x);
        }
        update(x);
    }
    Node* access(Node *x) {
        Node *y = nil;
        while(x != nil) {
            splay(x);
            x->ch[1]->rt = true;
            (x->ch[1] = y)->rt = false;
            update(x);
            y = x; x = x->fa;
        }
        return y;
    }
    void be_root(Node *x) {
        access(x);
        splay(x);
        update_rev(x);
    }
    void link(Node *x, Node *y) {
        be_root(x);
        x->fa = y;
    }
    void cut(Node *x, Node *y) {
        be_root(x);
        access(x);
        splay(y);
        y->fa = nil;
    }
    void modify_add(Node *x, Node *y, int w) {
        be_root(x);
        update_add(access(y), w);
    }
    void modify_set(Node *x, Node *y, int w) {
        be_root(x);
        update_set(access(y), w);
    }
    void query(Node *x, Node *y) {
        be_root(x);
        Node *r = access(y);
        if(r->max[1] == NINF) puts("ALL SAME");
        else printf("%d %d\n", r->max[1], r->cnt[1]);
    }
    void work() {
        scanf("%d", &T);
        for(int t = 1; t <= T; ++t) {
            scanf("%d%d", &n, &m);
            init();
            for(int i = 1; i <= n; ++i) scanf("%d", &val[i]);
            for(int i = 1, u, v; i < n; ++i) {
                scanf("%d%d", &u, &v);
                add_edge(u, v);
            }
            dfs(1, 0);
            printf("Case #%d:\n", t);
            for(int i = 0, x, y, a, b, op; i < m; ++i) {
                scanf("%d", &op);
                if(op == 1) {
                    scanf("%d%d%d%d", &x, &y, &a, &b);
                    cut(ptr[x], ptr[y]);
                    link(ptr[a], ptr[b]);
                } else if(op == 2) {
                    scanf("%d%d%d", &a, &b, &x);
                    modify_set(ptr[a], ptr[b], x);
                } else if(op == 3) {
                    scanf("%d%d%d", &a, &b, &x);
                    modify_add(ptr[a], ptr[b], x);
                } else {
                    scanf("%d%d", &a, &b);
                    query(ptr[a], ptr[b]);
                }
            }
        }
    }
} S;
int main() {
    S.work();
}
