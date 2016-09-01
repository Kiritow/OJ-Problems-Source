#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MaxN 40
#define MaxS 2000010
using namespace std;
int n, m, N, px, st, ed, hs, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int d[MaxS], dist[MaxN], len[MaxN], g[MaxN][4], pN[5];
bool adj[MaxN][MaxN];
char s[MaxN][MaxN];
struct HeapNode {
 int s, f;
 HeapNode(){}
 HeapNode(int s, int f):s(s),f(f){}
}heap[MaxS];
void sink(int p)
{
 HeapNode a = heap[p];
 for (int q = p<<1; q <= hs; p = q, q <<= 1) {
 if (q < hs && heap[q+1].f < heap[q].f) ++q;
 if (heap[q].f >= a.f) break;
 heap[p] = heap[q];
 }
 heap[p] = a;
}
HeapNode del()
{
 HeapNode r = heap[1];
 heap[1] = heap[hs--];
 sink(1);
 return r;
}
void swim(int p)
{
 HeapNode a = heap[p];
 for (int q = p>>1; q && a.f < heap[q].f; p = q, q >>= 1)
 heap[p] = heap[q];
 heap[p] = a;
}
void ins(HeapNode a)
{
 heap[++hs] = a;
 swim(hs);
}
int h(int s)
{
 int ret = 0;
 for (int i = 0; i < m; ++i, s /= N) ret += dist[s%N];
 return ret;
}
int AStar()
{
 memset(d, 0x3f, sizeof(d));
 int p[5];
 hs = 0;
 ins(HeapNode(st, h(st)));
 d[st] = 0;
 while (hs > 0) {
 HeapNode u = del();
 int s = u.s, first;
 for (int i = 0; i < m; ++i, s/=N) p[i] = s%N;
 for (int i = 0; i < m; ++i) if (p[i] != px) {first = i; break;}
 for (int i = first; i < m; ++i)
 for (int j = 0; j < len[p[i]]; ++j) {
 int np = g[p[i]][j];
 bool fail = 0;
 for (int k = first; k < m; ++k) if (k != i && adj[np][p[k]]) {fail = 1;break;}
 if (!fail) {
 int v = u.s+pN[i]*(np-p[i]);
 if (d[u.s] + 1 < d[v]) {
 d[v] = d[u.s] + 1;
 if (v == ed) return d[v];
 ins(HeapNode(v, d[v] + h(v)));
 }
 }
 }
 }
 return -1;
}
int main()
{
 int T;
 scanf("%d", &T);
 while (T--) {
 scanf("%d%d", &n, &m); N = n*n; st = ed = 0;
 memset(adj, 0, sizeof(adj));
 memset(len, 0, sizeof(len));
 pN[0] = 1; for (int i = 1; i <= m; ++i) pN[i] = pN[i-1] * N;
 for (int i = 0; i < n; ++i) scanf("%s", s[i]);
 for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
 int s1 = i*n+j;
 if (s[i][j] == 'x') px = s1;
 else if (s[i][j] != 'o') st += pN[s[i][j]-'1'] * s1;
 for (int d = 0; d < 4; ++d) {
 int x = i + dx[d], y = j + dy[d], s2 = x*n+y;
 if (x >= 0 && x < n && y >= 0 && y < n) {
 g[s1][len[s1]++] = s2;
 adj[s1][s2] = 1;
 }
 }
 }
 for (int i = 0; i < m; ++i) ed = ed*N + px;
 for (int i = 0; i < n; ++i) 
 for (int j = 0; j < n; ++j) 
 dist[i*n+j] = abs(i-px/n) + abs(j-px%n);
 printf("%d\n", AStar());
 }
 return 0;
}
