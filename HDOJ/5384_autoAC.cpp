#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int MAXN = (int)1e5 + 10;
const int maxnode = (int)6e5 + 10;
const int sigma_size = 26;
struct Trie {
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    void clear() { sz = 1; memset(ch[0], 0, sizeof(ch[0]));}
    Trie() {clear();}
    int idx(char c) { return c - 'a';}
    void insert(char *s, int v = 1) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if(!ch[u][c]) {
                memset(ch[sz], 0, sizeof(ch[u]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] += v;
    }
    ll find(const char* s) {
        int u = 0, n = strlen(s);
        ll ret = 0;
        for(int i = 0; i < n; i++) {
            int c = idx(s[i]);
            if(!ch[u][c]) return ret;
            u = ch[u][c];
            ret += val[u];
        }
        return ret;
    }
} trie;
int n, m;
string A[MAXN];
char B[MAXN];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        trie.clear();
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for(int i = 0; i < m; i++) {
            scanf("%s", B);
            trie.insert(B);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++) {
            ans = 0;
            for(int j = 0; j < A[i].size(); j++) {
                ans += trie.find(A[i].c_str()+j);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
