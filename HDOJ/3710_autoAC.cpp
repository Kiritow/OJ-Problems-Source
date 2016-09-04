#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
const int N = 20005;
const int M = 100005;
const int QN = M;
const int INF = 0X7FFFFFFF;
typedef int vType;
typedef pair<int, int> pii;
#define mkpii make_pair<int, int>
struct e{
    int v;
    e* nxt;
}es[N<<1], *fir[N];
struct node{
    int ls, rs; 
    int l, r;   
    int id;  
    vType Min;  
    int mid() { return (l + r) >> 1;  }
}nodes[N<<1];
struct se{
    pii e;
    int len;
}ses[M<<1], lea[M<<1];
int n, en, qn, m;
vector<pii> qlca[N];
vector<se> nes[N];
int par[N], fa[N]; 
int  ln, cnt; 
int leaNum;
int  sons[N], que[N], dep[N], id[N], st[N], ed[N], root[N], top[N], sNum[N];
int ith[N], pMin[N], seg[N]; 
vType iw[N];  
int tr;  
inline void add_e(int u, int v){
    es[en].v = v;
    es[en].nxt = fir[u];
    fir[u] = &es[en++];
}
inline void newNode(int& id, int l, int r){
    nodes[cnt].ls = nodes[cnt].rs = -1;
    nodes[cnt].l = l;
    nodes[cnt].r = r;
    nodes[cnt].Min = INF;
    id = cnt++;
}
void build(int& id, int l, int r){ 
    newNode(id, l, r);
    if(l >= r){
        nodes[id].id = seg[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(nodes[id].ls, l, mid);
    build(nodes[id].rs, mid+1, r);
}
void initTree(){ 
    int l, r, u, v, i;
    e* cur;
    l = r = 0;
    que[r++] = tr;
    par[tr] = -1;
    dep[tr] = 0;
    while(l != r){
        u = que[l++];
        int g = 1;
        for(cur = fir[u]; cur; cur = cur->nxt){
            if((v = cur->v) != par[u]){
                que[r++] = v;
                par[v] = u;
                dep[v] = dep[u]+1;
                ith[v] = g++;
            }
        }
    }
    for(i = 1; i <= n; i++){
        sons[i] = 1;
        sNum[i] = 0;
        id[i] = -1;
    }
    for(i = r-1; i >= 0; i--){
        u = que[i];
        if(par[u] >= 0){
            sons[par[u]] += sons[u];
            sNum[par[u]]++;
        }
    }
    l = r = 0;
    que[r++] = tr;
    ln = cnt = 0;
    while(l != r){
        u = que[l++];
        st[ln] = dep[u]; 
        top[ln] = u;
        while(u >= 0){
            id[u] = ln;
            ed[ln] = dep[u];
            seg[dep[u]] = u;
            int best;
            for(cur = fir[u], best=-1; cur; cur = cur->nxt){
                if(id[v = cur->v] == -1){
                    if(best == -1 || (best >= 0 && sons[v] > sons[best])){
                        best = v;
                    }
                }
            }
            if(best >= 0){
                for(cur = fir[u]; cur; cur = cur->nxt){
                    if(id[v = cur->v] == -1 && best != v){
                        que[r++] = v;
                    }
                }
            }
            u = best;
        }
        root[ln] = -1;
        build(root[ln], st[ln], ed[ln]);
        ln++;
    }
}
int qrylKthFar(int& id, int i, int k){
    if(nodes[id].l == nodes[id].r) return nodes[id].id;
    int mid = nodes[id].mid();
    if(i - mid - 1 >= k) return qrylKthFar(nodes[id].rs, i, k);
    else return qrylKthFar(nodes[id].ls, i, k);
}
int qryKthFar(int i, int k){
    int u = i, ri;
    while(true){
        ri = id[u];
        if(dep[u] - st[ri] >= k){
            return qrylKthFar(root[ri], dep[u], k);
        }else{
            k -= dep[u] - st[ri] + 1;
            u = par[top[ri]];
        }
    }
}
void inslMin(int& id, int ql, int qr, int mv){
    if(id == -1) return ;
    if(ql <= nodes[id].l && nodes[id].r <= qr){
        if(nodes[id].Min > mv){
            nodes[id].Min = mv;
        }
        return;
    }
    if(nodes[id].l == nodes[id].r) return;
    int mid = nodes[id].mid();
    if(ql <= mid){
        inslMin(nodes[id].ls, ql, qr, mv);
    }
    if(qr > mid){
        inslMin(nodes[id].rs, ql, qr, mv);
    }
}
void insMin(int i, int k, vType mv){  
    int b, u;
    u = i;
    while(true){
        b = id[u];
        if(dep[u]-st[b] >= k){
            inslMin(root[b], dep[u]-k, dep[u], mv);
            return;
        }else{
            inslMin(root[b], st[b], dep[u], mv);
            k -= dep[u] - st[b] + 1;
            u = par[top[b]];
        }
    }
}
bool input(){
    scanf("%d%d", &n, &m);
    int i, k, tn;
    for(i = tn = 0; i < m; i++){
        scanf("%d%d%d%d", &ses[i].e.first, &ses[i].e.second, &ses[i].len, &k);
        if(k == 1){  
            ses[i].len = 0;
        }
        if(ses[i].e.first != ses[i].e.second){
            tn++;
        }
    }
    m = tn;
    return true;
}
inline bool cmp(se a, se b){
    return a.len < b.len;
}
int findFa(int u){
    int k = u;
    while(k != fa[k]) k = fa[k];
    while(u != k){
        int tf = fa[u];
        fa[u] = k;
        u = tf;
    }
    return k;
}
void merge(int u, int v){
    int fu, fv;
    fu = findFa(u);
    fv = findFa(v);
    fa[fu] = fv;
}
int kruskal(int n, int m, int& leaNum, bool flag){ 
    int i, ans, k, u, v;
    for(i = 1; i <= n; i++){
        fa[i] = i;
    }
    if(flag){
        for(i = 1; i <= n; i++){
            iw[i] = 0;
            fir[i] = NULL;
        }
        en = leaNum = 0;
    }
    sort(ses, ses + m, cmp);
    for(i = ans = 0, k = 1; k < n && i < m; i++){
        u = ses[i].e.first;
        v = ses[i].e.second;
        if(findFa(u) != findFa(v)){
            ans += ses[i].len;
            k++;
            merge(u, v);
            if(flag){
                add_e(u, v);
                add_e(v, u);
                iw[u] += ses[i].len;
                iw[v] += ses[i].len;
            }
        }else if(flag){ 
            lea[leaNum++] = ses[i];
        }
    }
    if (flag) {
        for (; i < m; i++) {
            lea[leaNum++] = ses[i];
        }
    }
    if(k < n) ans = INF;
    return ans;
}
void handlelca(int u, int v, int anc, int len){
    if(u != anc && v != anc){
        int ku, kv;
        ku = qryKthFar(u, dep[u] - dep[anc] - 1);
        kv = qryKthFar(v, dep[v] - dep[anc] - 1);
        se te;
        te.e.first = ith[ku];
        te.e.second = ith[kv];
        te.len = len;
        nes[anc].push_back(te);
    }
    if(dep[anc] + 2 <= dep[u]){
        insMin(u, dep[u] - dep[anc] - 2, len);
    }
    if(dep[anc] + 2 <= dep[v]){
        insMin(v, dep[v] - dep[anc] - 2, len);
    }
}
int getlca(int u, int v){
while(id[u] != id[v]){
if(id[u] < id[v]) swap(u, v);
u = par[top[id[u]]];
}
if(dep[u] < dep[v]) swap(u, v);
return v;
}
void lca(se* qs, int qn){
int i;
for(i = 1; i <= n; i++){
nes[i].clear();
}
for(i = 0; i < qn; i++){
int u, v, anc;
u = qs[i].e.first;
v = qs[i].e.second;
anc = getlca(u, v);
handlelca(v, u, anc, qs[i].len);
}
}
void getpMin(int& id, int mv){
    if(mv > nodes[id].Min){
        mv = nodes[id].Min;
    }
    if(nodes[id].l == nodes[id].r){
        pMin[nodes[id].id] = mv;
        return;
    }
    getpMin(nodes[id].ls, mv);
    getpMin(nodes[id].rs, mv);
}
void getpMin(){
    int i;
    for(i = 0; i < ln; i++){
        getpMin(root[i], INF);
    }
}
void solve(){
    tr = 1; 
    int sum, i, sn, v, num;
    e* cur;
    sum = kruskal(n, m, leaNum, true);
    initTree();
    lca(lea, leaNum);
    getpMin();
    for(i = 1; i <= n; i++){
        num = 0;
        sn = sNum[i];
        if (par[i] >= 1) {
            sn++;
            for (cur = fir[i]; cur; cur = cur->nxt) {
                if ((v = cur->v) != par[i] && pMin[v] < INF) {
                    ses[num].e.first = sn;
                    ses[num].e.second = ith[v];
                    ses[num].len = pMin[v];
                    num++;
                }
            }
        }
        int size = nes[i].size(), j;
        for(j = 0; j < size; j++){
            ses[num++] = nes[i][j];
        }
        int ans = kruskal(sn, num, leaNum, false);
        if(ans < INF){
            ans += sum - iw[i];
            printf("%d\n", ans);
        }else{
            printf("inf\n");
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        input();
        solve();
    }
    return 0;
}
