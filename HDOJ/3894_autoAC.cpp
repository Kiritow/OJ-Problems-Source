#include <iostream>
#include <stdio.h>
using namespace std;
const int N = 1000005;
struct e{
    int v;
    e* nxt;
}es[N<<1], *fir[N], stk[N];
int n, m, en, p;
int E, W;
bool hasFood[N];
int eastNum[N], westNum[N], par[N];
int minp[N], t[N], que[N], dep[N];
inline void add_e(int u, int v){
    es[en].v = v;
    es[en].nxt = fir[u];
    fir[u] = &es[en++];
}
template <typename T>
void getNum(T& a){
    a = 0;
    char ch;
    while(true){
        ch = getchar();
        if(ch >= '0' && ch <= '9') break;
    }
    a = ch - '0';
    while(true){
        ch = getchar();
        if(ch < '0' || ch > '9') break;
        a = a * 10 + ch - '0';
    }
}
bool input(){
    if(scanf("%d%d%d%d", &n, &m, &E, &W)== EOF) return false;
    int i, u, v;
    en = 0;
    for(i = 1; i <= n; i++){
        fir[i] = NULL;
        hasFood[i] = false;
    }
    for(i = 1; i < n; i++){
        getNum<int>(u);
        getNum<int>(v);
        add_e(u, v);
        add_e(v, u);
    }
    scanf("%d", &p);
    for(i = 1; i <= p; i++){
        getNum(u);
        hasFood[i] = true;
    }
    return true;
}
inline bool isEast(int u){ return u  <= E; }
inline bool has(int u) { return hasFood[u]; }
inline bool isWest(int u){ return u >= n - W + 1; }
inline void push(int v, int p, int& top){
    eastNum[v] = westNum[v] = 0;
    if(isEast(v)){
        eastNum[v]++;
    }else if(isWest(v)){
        westNum[v]++;
    }
    ++top;
    stk[top].v = v;
    stk[top].nxt = fir[v];
    par[v] = p;
}
typedef bool (*fun)(int u);
void bfs(int st, int* ar, fun check){
    int l, r, u, v, num;
    e* cur;
    l = r = num = 0;
    que[r++] = st; dep[st] = 0;
    if(check(st)){
        ar[num++] = 0;
    }
    while(l != r && num < p){
        u = que[l++];
        for(cur = fir[u]; cur; cur = cur->nxt){
            if((v = cur->v) != par[u]){
                que[r++] = v; par[v] = u; dep[v] = dep[u] + 1;
                if(check(v)){
                    ar[num++] = dep[v];
                    if(num >= p) break;
                }
            }
        }
    }
}
void solve(){
    int top = -1, u, v, est, wst, ans;
    int i, maxt;
    push(1, -1, top);
    while(top >= 0){
        u = stk[top].v;
        if(stk[top].nxt == NULL){
            if(eastNum[u] == 0 && westNum[u] == W){
                wst = u;
                est = par[u];
                break;
            }
            if(eastNum[u] == E && westNum[u] == 0){
                wst = par[u];
                est = u;
                break;
            }
            if(par[u] >= 1){
                eastNum[par[u]] += eastNum[u];
                westNum[par[u]] += westNum[u];
            }
            top--;
            continue;
        }else{
            v = stk[top].nxt->v;
            stk[top].nxt = stk[top].nxt->nxt;
            if(v != par[u]){
                push(v, u, top);
            }
        }
    }
    par[est] = wst;
    par[wst] = est;
    bfs(wst, minp, isWest);
    bfs(est, t, has);
    ans = 0;
    maxt = -1;
    for(i = 0; i < p; i++){
        if(t[i] < maxt + 1) t[i] = maxt + 1;
        maxt = t[i];
        if(ans < t[i] + minp[p - i - 1]){
            ans = t[i] + minp[p - i - 1];
        }
    }
    ans++;
    cout<<ans<<endl;
}
int main() {
    while(input()) solve();
    return 0;
}
