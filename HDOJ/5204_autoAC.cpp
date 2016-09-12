#pragma comment(linker, "/STACK:10240000,10240000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <ctime>
#include <cctype>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <stdexcept>
#include <utility>
using namespace std;
#define mem0(a) memset(a, 0, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define define_m int m = (l + r) >> 1
#define rep0(a, b) for (int a = 0; a < (b); a++)
#define rep1(a, b) for (int a = 1; a <= (b); a++)
#define all(a) (a).begin(), (a).end()
#define lowbit(x) ((x) & (-(x)))
#define constructInt4(name, a, b, c, d) name(int a = 0, int b = 0, int c = 0, int d = 0): a(a), b(b), c(c), d(d) {}
#define constructInt3(name, a, b, c) name(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) {}
#define constructInt2(name, a, b) name(int a = 0, int b = 0): a(a), b(b) {}
#define pchr(a) putchar(a)
#define pstr(a) printf("%s", a)
#define sint(a) ReadInt(a)
#define sint2(a, b) ReadInt(a);ReadInt(b)
#define sint3(a, b, c) ReadInt(a);ReadInt(b);ReadInt(c)
#define pint(a) WriteInt(a)
typedef double db;
typedef long long LL;
typedef pair<int, int> pii;
typedef multiset<int> msi;
typedef set<int> si;
typedef vector<int> vi;
typedef map<int, int> mii;
const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
const int maxn = 1e3 + 7;
const int maxm = 1e5 + 7;
const int maxv = 1e7 + 7;
const int max_val = 1e6 + 7;
const int MD = 1e9 +7;
const int INF = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-10;
template<class T>T gcd(T a, T b){return b==0?a:gcd(b,a%b);}
template<class T>void ReadInt(T &x){char c=getchar();while(!isdigit(c))c=getchar();x=0;while(isdigit(c)){x=x*10+c-'0';c=getchar();}}
template<class T>void WriteInt(T i) {int p=0;static int b[20];if(i == 0) b[p++] = 0;else while(i){b[p++]=i%10;i/=10;}for(int j=p-1;j>=0;j--)pchr('0'+b[j]);}
struct abc {
    pii a[100007];
    int l, r;
    void Init() { l = r = 0; }
    void push_back(int x) {
        a[r++] = make_pair(x, 0);
        for(int i = l; i < r - 1; i++) a[i].second++;
        if (r - l >= 62) {
            int pos;
            for (int i = l; i < r; i++) {
                if (a[i].second == 61) {
                    pos = i;
                    break;
                }
            }
            for (int i = pos; i > l; i--) a[i] = a[i - 1];
            l++;
        }
        int p = r - 1;
        while (p > l && a[p].first < a[p - 1].first) {
            swap(a[p], a[p - 1]);
            p--;
        }
    }
    pii &operator [] (int i) {
        return a[l + i];
    }
    int size() {
        return r - l;
    }
};
abc g;
LL calc(LL x, LL pos) {
    if (x < pos) return 0;
    return (x - pos) / pos / 2 + 1;
}
int main() {
    int n;
    while (cin >> n) {
        g.Init();
        rep0(i, n) {
            int id, w;
            sint(id);
            if (id == 1) {
                sint(w);
                g.push_back(w);
            }
            else {
                LL L, R, k;
                sint3(L, R, k);
                int sz = g.size();
                rep0(i, sz) {
                    LL pos = 1LL << g[i].second, c = calc(R, pos) - calc(L - 1, pos);
                    if (k <= c) {
                        pint(g[i].first);
                        pchr('\n');
                        break;
                    }
                    k -= c;
                }
            }
        }
    }
    return 0;
}
