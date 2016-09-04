#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 160
const int N = MAXN * 2 + 2, E = MAXN * 2 + MAXN * MAXN;
typedef long long typec; 
const typec inf = 0x3f3f3f3f3f3f3f3fLL; 
 struct NetWork {
     int _n, _ne, _head[N], _cur[N], _ps[N], _dep[N];
     typec _cost;
     struct Edge {
         int _x, _y, _next;
         typec _c;
     } _bf[E * 2 + 2];
     void add_edge(int x, int y, typec c) { 
         _bf[_ne]._x = x; _bf[_ne]._y = y; _bf[_ne]._c = c;
         _bf[_ne]._next = _head[x]; _head[x] = _ne++;
         _bf[_ne]._x = y; _bf[_ne]._y = x; _bf[_ne]._c = 0;
         _bf[_ne]._next = _head[y]; _head[y] = _ne++;
     }
     inline void build(int n) {
         _n = n; _ne = 2;
         memset(_head, 0, n * sizeof (int));
     }
     typec max_flow(int s, int t) {
         typec tr, res = 0;
         int i, j, k, f, r, top;
         while (1) {
             memset(_dep, -1, _n * sizeof (int));
             for (f = _dep[_ps[0] = s] = 0, r = 1; f != r;)
                 for (i = _ps[f++], j = _head[i]; j; j = _bf[j]._next) {
                     if (_bf[j]._c && -1 == _dep[k = _bf[j]._y]) {
                         _dep[k] = _dep[i] + 1;
                         _ps[r++] = k;
                         if (k == t) {
                             f = r;
                             break;
                         }
                     }
                 }
             if (-1 == _dep[t]) break;
             memcpy(_cur, _head, _n * sizeof (int));
             for (i = s, top = 0;;) {
                 if (i == t) {
                     for (k = 0, tr = inf; k < top; ++k)
                         if (_bf[_ps[k]]._c < tr)
                             tr = _bf[_ps[f = k]]._c;
                     for (k = 0; k < top; ++k)
                         _bf[_ps[k]]._c -= tr, _bf[_ps[k]^1]._c += tr;
                     res += tr;
                     i = _bf[_ps[top = f]]._x;
                 }
                 for (j = _cur[i]; _cur[i]; j = _cur[i] = _bf[_cur[i]]._next)
                     if (_bf[j]._c && _dep[i] + 1 == _dep[_bf[j]._y]) break;
                 if (_cur[i]) {
                     _ps[top++] = _cur[i];
                     i = _bf[_cur[i]]._y;
                 } else {
                     if (0 == top) break;
                     _dep[i] = -1;
                     i = _bf[_ps[--top]]._x;
                 }
             }
         }
         return _cost = res;
     }
 } g;
 int n, m;
 long long love[MAXN], hate[MAXN];
 struct Trie {
     Trie* next[26];
     int terminate;
 } nodes[MAXN * 600], *ptr;
 void insert_trie(char* s, int no) {
     Trie* root = nodes;
     for (int i = 0; s[i]; ++i) {
         if (root->next[s[i] - 'a'] == 0) {
             root->next[s[i] - 'a'] = ++ptr;
             memset(ptr, 0, sizeof(Trie));    
             ptr->terminate = -1;
         }
         root = root->next[s[i] - 'a'];
     }
     if (root->terminate != -1) {
         love[no] += love[root->terminate];
         hate[no] += hate[root->terminate];
     }
     root->terminate = no;
 }
 long long slove[MAXN];
 bool map[MAXN][MAXN];
 void find_trie(char* s, int noo) {
     Trie* root = nodes;
     for (int i = 0; s[i]; ++i)
         if (root->next[s[i] - 'a']) {
             root = root->next[s[i] - 'a'];
             if (root->terminate != -1) {
                 slove[noo] += love[root->terminate];
                 map[noo][root->terminate] = true;
             }
         } else
             return;
 }
 inline int pointS(int x) {
     return x;
 }
 inline int pointP(int x) {
     return n + x;
 }
 char buf[20000];
 int main() {
     int test;
     scanf("%d", &test);
     for (int cas = 1; cas <= test; ++cas) {
         memset(slove, 0, sizeof(slove));
         memset(map, 0, sizeof(map));
         ptr = nodes;
         memset(ptr, 0, sizeof(Trie));        
         scanf("%d%d", &n, &m);
         for (int i = 0; i < n; ++i) {
             scanf("%I64d%I64d%s", love + i, hate + i, buf);
             insert_trie(buf, i);
         }
         for (int i = 0; i < m; ++i) {
             scanf("%s", buf);
             int len = strlen(buf);
             for (int j = 0; j < len; ++j)
                 find_trie(buf + j, i);
         }
         g.build(n + m + 2);
         int src = n + m, sink = n + m + 1;
         for (int i = 0; i < n; ++i)
             g.add_edge(pointS(i), sink, hate[i]);
         long long sum = 0;
         for (int i = 0; i < m; ++i) {
             g.add_edge(src, pointP(i), slove[i]);
             sum += slove[i];
         }
         for (int i = 0; i < n; ++i)
             for (int j = 0; j < m; ++j)
                 if (map[j][i])
                     g.add_edge(pointP(j), pointS(i), inf);
         printf("Case %d: %I64d\n", cas, sum - g.max_flow(src, sink));
     }
     return 0;
 }
