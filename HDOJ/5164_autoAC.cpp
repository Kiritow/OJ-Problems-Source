#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1e9
#define inf (-((LL)1<<40))
#define lson k<<1, L, mid
#define rson k<<1|1, mid+1, R
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
#define FOPENIN(IN) freopen(IN, "r", stdin)
#define FOPENOUT(OUT) freopen(OUT, "w", stdout)
#define rep(i, a, b) for(int i = a; i <= b; i ++)
template<class T> T CMP_MIN(T a, T b) { return a < b; }
template<class T> T CMP_MAX(T a, T b) { return a > b; }
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a,b) * b;    }
typedef __int64 LL;
const int MAXN = 110000;
const int MAXM = 1000006;
const double eps = 1e-10;
const LL MOD = 1000000007;
int T, n, m, s, k, x, y;
int val[MAXM], f[MAXM], last[MAXM];
LL ans;
struct Node {
    int up, down;
    Node(){}
    Node(int _up, int _down) {
        int g = GCD(_up, _down);
        up = _up / g;
        down = _down / g;
    }
    bool operator == (const Node& A) const {
        return up == A.up && down == A.down;
    }
    bool operator != (const Node& A) const {
        return up != A.up || down != A.down;
    }
    bool operator <  (const Node& A) const {
        if(up != A.up) return up < A.up;
        return down < A.down;
    }
};
map<int, map<Node, int> >ch;
vector<Node>e[MAXM];
Node fa[MAXN], chi[MAXN];
void init()
{
    s = 1;  ans = 0; 
    ch.clear(); e[0].clear();
    mem0(val); mem0(f); mem0(last);
}
void input(int n, Node* a)
{
    scanf("%d", &x);
    for(int i = 1; i < n; i ++) {
        scanf("%d", &y);
        a[i - 1] = Node(x, y);
        x = y;
    }
}
void addEdge()
{
    int p = 0;
    for(int i = 0; i < k - 1; i ++) {
        Node u = chi[i];
        if(ch[p][u] == 0) {
            e[p].push_back(u);
            val[s] = 0;
            e[s].clear();
            ch[p][u] = s++;
        }
        p = ch[p][u];
    }
    val[p] ++;
}
void getFail()
{
    queue<int>q;
    for(int i = 0; i < e[0].size(); i ++) {
        int u = ch[0][e[0][i]];
        f[u] = last[u] = 0;
        q.push(u);
    }
    while(!q.empty()) {
        int r = q.front(); q.pop();
        for(int i = 0; i < e[r].size(); i ++) {
            Node c = e[r][i];
            int u = ch[r][c];
            if(!u) {
                ch[r][c] = ch[f[r]][c];
                continue;
            }
            q.push(u);
            int v = f[r];
            while(v && !ch[v][c]) v = f[v];
            f[u] = ch[v][c];
            last[u] = val[f[u]] ? f[u] : last[f[u]];
            val[u] += val[last[u]];
        }
    }
}
void getNext()
{
    f[0] = f[1] = 0;
    for(int i = 1; i < k - 1; i ++) {
        int j = f[i];
        while(j && chi[i] != chi[j]) j = f[j];
        f[i + 1] = chi[i] == chi[j] ? j + 1 : 0;
    }
}
LL KMP()
{
    if(k == 1) return ans;
    getNext();
    int j = 0;
    for(int i = 0; i < n - 1; i ++) {
        while(j && chi[j]!=fa[i]) j = f[j];
        if(chi[j] == fa[i]) j ++;
        if(j == k - 1) ans ++;
    }
    return ans;
}
LL ACT()
{
    getFail();
    int j = 0;
    for(int i = 0; i < n - 1; i ++) {
        Node c = fa[i];
        while(j && !ch[j][c]) j = f[j];
        j = ch[j][c];
        ans += val[j];
    }
    return ans;
}
int main()
{
    while(~scanf("%d", &T)) while(T--) {
        scanf("%d %d", &n, &m);
        init();
        input(n, fa);
        for(int i = 1; i <= m; i ++) {
            scanf("%d", &k);
            input(k, chi);
            if(k > 1) addEdge();
            else ans += n;
        }
        cout<< (m == 1 ? KMP() : ACT()) << endl;
    }
    return 0;
}
