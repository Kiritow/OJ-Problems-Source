#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define FOR(i,a,b) for(i = (a); i < (b); ++i)
#define FORE(i,a,b) for(i = (a); i <= (b); ++i)
#define CLR(a,b) memset(a,b,sizeof(a))
const int inf = 1 << 30;
const int MAXN = 502000;
const int MAXM = 3100000;
struct node {
    int c,u,v,next;
}edge[MAXM];
int N, M;
int ne, head[MAXN];
int cur[MAXN], ps[MAXN], dep[MAXN];
void addedge(int u, int v,int w) {
    edge[ne].u = u;
    edge[ne].v = v;
    edge[ne].c = w;
    edge[ne].next = head[u];
    head[u] = ne ++;
    edge[ne].u = v;
    edge[ne].v = u;
    edge[ne].c = w;
    edge[ne].next = head[v];
    head[v] = ne ++;
}
int dinic(int s, int t) {
    int tr, res = 0;
    int i, j, k, f, r, top;
    while(1) {
        memset(dep, -1, sizeof(dep));
        for(f = dep[ps[0] = s] = 0, r = 1; f != r;)
            for(i = ps[f++], j = head[i]; j != -1; j = edge[j].next)
                if(edge[j].c > 0 && dep[k = edge[j].v] == -1) {
                    dep[k] = dep[i] + 1;
                    ps[r++] = k;
                    if(k == t) {
                        f = r; break;
                    }
                }
        if(dep[t] == -1) break;
        memcpy(cur, head, sizeof(cur));
        i = s, top = 0;
        while(1) {
            if(i == t) {
                for(tr = inf, k = 0; k < top; k++)
                    if(edge[ps[k]].c < tr)
                        tr = edge[ps[f = k]].c;
                for(k = 0; k < top; k++) {
                    edge[ps[k]].c -= tr;
                    edge[ps[k]^1].c += tr;
                }
                i = edge[ps[top=f]].u;
                res += tr;
            }
            for(j = cur[i]; cur[i] != -1; j = cur[i] = edge[cur[i]].next) {
                if(edge[j].c > 0 && dep[i]+1 == dep[edge[j].v]) break;
            }
            if(cur[i] != -1) {
                ps[top++] = cur[i];
                i = edge[cur[i]].v;
            }
            else {
                if(top == 0) break;
                dep[i] = -1;
                i = edge[ps[--top]].u;
            }
        }
    }
    return res;
}
int main() {
    int i, j, x, y;
    while(scanf("%d %d", &N, &M) == 2) {
        ne = 2;
        CLR(head, -1);
        CLR(cur, 0);
        CLR(ps, 0);
        CLR(dep, 0);
        FORE(i, 1, N + 1) {
            FORE(j, 1, M) {
                scanf("%d", &x);
                addedge(j + (i - 1) * (M + 1), j + (i - 1) * (M + 1) + 1, x);
            }
        }
        FORE(i, 1, N) {
            FORE(j, 1, M + 1) {
                scanf("%d", &x);
                addedge(j + (i - 1) * (M + 1), j + (i - 1) * (M + 1) + (M + 1), x);
            }
        }
        int tmp_cnt1 = (M + 1) * (N + 1) + 1, tmp_cnt2 = (M + 1) * (N + 1) + 1;
        int cntt = 1;
        FORE(i, 1, N) {
            int tt1 = tmp_cnt1, tt2 = tmp_cnt2;
            FORE(j, 1, M) {
                scanf("%d %d", &x, &y);
                addedge(cntt, tt1++, x);
                addedge(cntt + 1, tt2++, y);
                ++cntt;
            }
            ++cntt;
            FORE(j, 1, M) {
                scanf("%d %d", &x, &y);
                addedge(cntt, tmp_cnt1++, x);
                addedge(cntt + 1, tmp_cnt2++, y);
                ++cntt;
            }
            ++cntt;
            cntt -= (M + 1);
        }
        int endd = dinic(1, (N + 1) * (M + 1));
        printf("%d\n", endd);
    }
    return 0;
}
