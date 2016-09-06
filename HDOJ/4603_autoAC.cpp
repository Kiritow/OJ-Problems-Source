#pragma comment(linker, "/STACK:102400000,102400000")  
#include<iostream>  
#include<vector>  
#include<algorithm>  
#include<cstdio>  
#include<queue>  
#include<stack>  
#include<string>  
#include<map>  
#include<set>  
#include<cmath>  
#include<cassert>  
#include<cstring>  
#include<iomanip>  
#include<ctime>  
using namespace std;  
#ifdef _WIN32  
typedef __int64 i64;  
#define out64 "%I64d\n"  
#define in64 "%I64d"  
#else  
typedef long long i64;  
#define out64 "%lld\n"  
#define in64 "%lld"  
#endif  
#define foreach(c,itr)  for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)  
#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)  
#define FF(i,a)         for( int i = 0 ; i < (a) ; i ++)  
#define FFD(i,a,b)      for( int i = (a) ; i >= (b) ; i --)  
#define S64(a)          scanf(in64,&a)  
#define SS(a)           scanf("%d",&a)  
#define LL(a)           ((a)<<1)  
#define RR(a)           (((a)<<1)+1)  
#define pb              push_back  
#define pf              push_front  
#define X               first  
#define Y               second  
#define CL(Q)           while(!Q.empty())Q.pop()  
#define MM(name,what)   memset(name,what,sizeof(name))  
#define MC(a,b)     memcpy(a,b,sizeof(b))  
#define MAX(a,b)        ((a)>(b)?(a):(b))  
#define MIN(a,b)        ((a)<(b)?(a):(b))  
const int inf = 0x3f3f3f3f;  
const long long inf64 = 0x3f3f3f3f3f3f3f3fLL;  
const double oo = 10e9;  
const double eps = 10e-9;  
const double pi = acos(-1.0);  
const int maxn = 100111;  
const int maxlevel = 21;  
struct Node  
{  
    int now;  
    int to;  
    int c;  
    int tot;  
    int ss;  
    const bool operator <  (const Node& cmp) const {  
        return tot > cmp.tot;  
    }  
};  
int all;  
int n, m;  
vector<Node>g[maxn];  
int t[maxn];  
int dep[maxn];  
int df;  
int dfn[maxn];  
int dfv[maxn * 2];  
int st[maxn * 2][maxlevel];  
int up[maxn][maxlevel];  
int dp[maxn];   //down sum   
int xtof[maxn];  
int ftox[maxn];  
int vis[maxn];  
int lg2[maxn*2];  
void dfs(int now)  
{  
    vis[now] = true;  
    int to;  
    for (int i = 0; i < (int)g[now].size(); i++) {  
        to = g[now][i].to;  
        if (!vis[to])   {  
            t[to] = now;  
            dfs(to);  
        }  
    }  
}  
int treedp(int now)  
{     
    int to,id;  
    dp[now] = 0;  
    for (int i = 0; i < (int)g[now].size(); i++) {  
        to = g[now][i].to;  
        if (to != t[now]) {  
            int temp = treedp(to) + g[now][i].c;  
            g[now][i].tot = temp;  
            dp[now] += temp;  
        }  
        else {  
            id = i;  
        }  
    }  
    if (t[now] != -1) {  
        g[now][id].tot = all - dp[now];  
    }  
    return dp[now];  
}  
void euler_circuit(int now ,int step)  
{  
    dep[now] = step;  
    dfn[now] = df;  
    dfv[df++] = now;  
    int to;  
    for (int i = 0; i < (int)g[now].size(); i++) {  
        to = g[now][i].to;  
        if (to != t[now]) {  
            euler_circuit(to,step+1);  
            dfv[df++] = now;  
        }  
    }  
}  
void get_up_node()  
{  
    for (int i = 1; i <= n; i++) {  
        up[i][0] = t[i];  
    }  
    int to;  
    for (int step = 1; step < maxlevel; step++) {  
        for (int now = 1; now <= n; now++) {  
            to = up[now][step - 1];  
            if (to == -1) {  
                up[now][step] = -1;  
            }  
            else {  
                up[now][step] = up[to][step - 1];  
            }  
        }  
    }  
}  
void sparse_table()  
{  
    for (int i = 1; i < df; i++){  
        st[i][0] = dep[dfv[i]];  
    }  
    int to;  
    for (int step = 1; step <= lg2[n] + 1; step++){  
        for (int now = 1; now < df; now++) {  
            to = now + (1 << (step - 1));  
            if (to < df){  
                st[now][step] = min(st[now][step - 1], st[to][step - 1]);  
            }  
            else{  
                st[now][step] = st[now][step - 1];  
            }  
        }  
    }  
}  
void relation()  
{  
    int to;  
    for (int now = 1; now <= n; now++){  
        for (int i = 0; i < (int)g[now].size(); i++){  
            to = g[now][i].to;  
            if (to == t[now]){  
                xtof[now] = i;  
            }  
            else{  
                ftox[to] = i;  
            }  
        }  
    }  
}  
int rmq(int l,int r)  
{  
    return min(st[l][lg2[r - l]], st[r - (1 << lg2[r - l])][lg2[r - l]] );  
}  
int calculate(int x,bool first,int id1,int id2=-1)  
{  
    if (id2 != -1){  
        if (id1 > id2){  
            swap(id1, id2);  
        }  
    }  
    int sum = g[x][0].ss;  
    sum -= g[x][id1].tot;  
    if (id2 != -1){  
        sum -= g[x][id2].tot;  
    }  
    int size = (int)g[x].size() - 1;  
    if (size >= 1){  
        sum += g[x][1].ss;  
    }  
    int ans = g[x][0].ss;  
    if (id1 % 2 ){  
        if (id1 + 1 <= size){  
            ans -= g[x][id1 + 1].ss;  
            if (id1 + 2 <= size){  
                ans += g[x][id1 + 2].ss;  
            }  
        }  
        if (id2 != -1){  
            if (id2 % 2){  
                ans -= g[x][id2].ss;  
                if (id2 + 1 <= size){  
                    ans += g[x][id2 + 1].ss;  
                }  
            }  
            else{  
                if (id2 + 1 <= size){  
                    ans -= g[x][id2 + 1].ss;  
                    if (id2 + 2 <= size){  
                        ans += g[x][id2 + 2].ss;  
                    }  
                }  
            }  
        }  
    }  
    else{  
        ans -= g[x][id1].ss;  
        if (id1 + 1 <= size){  
            ans += g[x][id1 + 1].ss;  
        }  
        if (id2 != -1){  
            if (id2 % 2){  
                ans -= g[x][id2].ss;  
                if (id2 + 1 <= size){  
                    ans += g[x][id2 + 1].ss;  
                }  
            }  
            else{  
                if (id2 + 1 <= size){  
                    ans -= g[x][id2 + 1].ss;  
                    if (id2 + 2 <= size){  
                        ans += g[x][id2 + 2].ss;  
                    }  
                }  
            }  
        }  
    }  
    if (first) return ans;  
    else return sum - ans;  
}  
int go_up(int now, int x)  
{  
    int step = 0;  
    while (x) {  
        if (x & 1) {  
            now = up[now][step];  
        }  
        step++;  
        x >>= 1;  
    }  
    return now;  
}  
int find(int a,int b)  
{  
    int l = dfn[a];  
    int r = dfn[b];  
    if (l == r){  
        return g[a][0].ss;  
    }  
    if (l > r){  
        swap(l, r);  
    }  
    int lca = rmq(l, r + 1);    
    if (dep[a] - lca + dep[b] - lca == 1){  
        if (dep[a] == lca){  
            return g[b][xtof[b]].tot + calculate(b, false, xtof[b]);  
        }  
        else if (dep[b] == lca){  
            return g[b][ftox[a]].tot + calculate(b, false, ftox[a]);  
        }  
    }  
    else if (dep[a] > dep[b]+1){  
        int temp = dep[a] - dep[b];  
        int mid = lca + temp / 2;  
        int child = go_up(a, dep[a] - mid - 1);  
        if (temp % 2){  
            return g[t[child]][ftox[child]].tot + calculate(t[child], false, ftox[child], xtof[t[child]]);  
        }  
        else{  
            return g[t[child]][ftox[child]].tot + calculate(t[child], true, ftox[child], xtof[t[child]]);  
        }  
    }  
    else if (dep[a] == dep[b] + 1) {  
        int ca = go_up(a, dep[a] - lca - 1);  
        int cb = go_up(b, dep[b] - lca - 1);  
        int meet = t[ca];  
        return g[meet][ftox[ca]].tot + calculate(meet, false, ftox[ca], ftox[cb]);  
    }  
    else if (dep[a] < dep[b]){  
        int temp = dep[b] - dep[a];  
        int mid = lca + (temp + 1)/ 2;  
        int child = go_up(b, dep[b] - mid - 1);  
        if (temp % 2){  
            return g[t[child]][xtof[t[child]]].tot + calculate(t[child], false, xtof[t[child]], ftox[child]);  
        }  
        else{  
            return g[t[child]][xtof[t[child]]].tot + calculate(t[child], true, xtof[t[child]], ftox[child]);  
        }  
    }  
    else if(dep[a] == dep[b]) {  
        int ca = go_up(a, dep[a] - lca - 1);  
        int cb = go_up(b, dep[b] - lca - 1);  
        int meet = t[ca];  
        return g[meet][ftox[ca]].tot + calculate(meet, true, ftox[ca], ftox[cb]);  
    }  
    assert(false);    
}  
void start()  
{  
    for (int i = 1; i <= n; i++) {  
        vis[i] = false;  
    }  
    t[0] = t[1] = -1;  
    dfs(1);  
    treedp(1);  
    for (int now = 1; now <= n; now++) {  
        sort(g[now].begin(), g[now].end());  
        for (int i =(int) g[now].size() - 1; i >= 0; i--) {  
            g[now][i].ss = g[now][i].tot;  
            if (i + 3 <= (int)g[now].size()) {  
                g[now][i].ss += g[now][i + 2].ss;  
            }  
        }  
    }  
    df = 1;  
    euler_circuit(1, 0);  
    get_up_node();  
    sparse_table();  
    relation();  
}  
int main()  
{  
    for (int i = 0; i < maxlevel; i++){  
        if ( (1<<i) < maxn*2)  
        lg2[1 << i] = i;  
    }  
    for (int i = 3; i < maxn*2; i++) {  
        if (!lg2[i]){  
            lg2[i] = lg2[i - 1];  
        }  
    }  
    int T;  
    cin >> T;  
    while (T--) {  
        all = 0;  
        cin >> n >> m;  
        for (int i = 0; i <= n; i++){  
            g[i].clear();  
        }  
        Node node;  
        for (int i = 1; i <= n - 1; i++) {  
            SS(node.now);  
            SS(node.to);  
            SS(node.c);  
            g[node.now].push_back(node);  
            swap(node.now, node.to);  
            g[node.now].push_back(node);  
            all += node.c;  
        }  
        start();  
        int a, b;  
        for (int i = 1; i <= m; i++){  
            SS(a); SS(b);  
            printf("%d\n", find(a, b));  
        }  
    }  
    return 0;  
}
