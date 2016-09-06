#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int maxn = 1000010;
struct node {
    int be, ne, weight;
    void init(int b, int e, int v) {
        be = b;
        ne = e;
        weight = v;
    }
};
int rmq[maxn * 2];
struct RMQ {
    int lg[maxn + 1], minn[20][maxn + 1], n;
    RMQ() {
        lg[0] = -1;
        for (int i = 1; i <= maxn; i++) {
            lg[i] = ((i & (i - 1)) == 0) ? lg[i - 1] + 1 : lg[i - 1];
            minn[0][i] = i;
        }
    }
    void init(int n) {
        this->n = n;
        for (int i = 1; i <= lg[n]; i++)
            for (int j = 1; j <= n + 1 - (1 << i); j++) {
                int a = minn[i - 1][j];
                int b = minn[i - 1][j + (1 << (i - 1))];
                minn[i][j] = rmq[a] < rmq[b] ? a : b;
            }
    }
    int getmin(int s, int t) {
        if (s > t) {
            int temp = t;
            t = s;
            s = temp;
        }
        int k = lg[t - s + 1];
        int a = minn[k][s];
        int b = minn[k][t - (1 << k) + 1];
        if (rmq[a] < rmq[b])
            return a;
        else
            return b;
    }
} st;
int root[maxn];
struct LCA {
    int n, len, E[maxn];
    node buf[maxn * 2];
    int F[maxn * 2], pos[maxn], cnt;
    int dis[maxn];
    void init(int n) {
        this->n = n;
        len = 0;
        memset(E, -1, sizeof(E));
    }
    void addedge(int a, int b, int w) {
        buf[len].init(b, E[a], w);
        E[a] = len++;
        buf[len].init(a, E[b], w);
        E[b] = len++;
    }
    int query(int a, int b) {
        int k = st.getmin(pos[a], pos[b]);
        return F[k];
    }
    void dfs(int a, int lev) {
        F[++cnt] = a;
        rmq[cnt] = lev;
        pos[a] = cnt;
        for (int i = E[a]; i != -1; i = buf[i].ne) {
            int b = buf[i].be;
            if (pos[b] != -1)
                continue;
            dis[b] = dis[a] + buf[i].weight;
            dfs(b, lev + 1);
            F[++cnt] = a;
            rmq[cnt] = lev;
        }
    }
    void dfs2(int a, int r) {
        root[a] = r;
        for (int i = E[a]; i != -1; i = buf[i].ne)
            if (root[buf[i].be] == -1)
                dfs2(buf[i].be, r);
    }
    void solve(int root) {
        cnt = 0;
        memset(pos, -1, sizeof(pos));
        memset(dis, 0, sizeof(dis));
        dfs(root, 0);
        st.init(2*n-1);
    }
} lca;
int nxt[maxn],n;
int cc[maxn],pos[maxn],len[maxn],num;
int f[maxn];
int find(int x) {
    if (x != f[x])
        f[x] = find(f[x]);
    return f[x];
}
void circle() {
    for (int i = 1; i <= n; i++)
        f[i] = i;
    num = 0;
    memset(cc, -1, sizeof(cc));
    memset(pos, -1, sizeof(pos));
    for (int i = 1; i <= n; i++) {
        int a = find(i);
        int b = find(nxt[i]);
        if (a == b)
            cc[i]=++num;
        f[a] = b;
    }
    for (int i = 1; i <= n; i++)
        if (cc[i] != -1) {
            int k = nxt[i];
            int cnt = 0;
            pos[i] = ++cnt;
            root[i] = i;
            while (k != i) {
                pos[k] =++cnt;
                root[k]=k;
                cc[k]=cc[i];
                k=nxt[k];
            }
            len[cc[i]] = cnt;
        }
}
int main() {
    int m;
    while (scanf("%d %d", &n, &m) != EOF) {
        lca.init(n + 1);
        memset(root, -1, sizeof(root));
        for (int i = 1; i <= n; i++)
            scanf("%d", nxt + i);
        circle();
        for (int i = 1; i <= n; i++)
            if (root[i]!=i)
                lca.addedge(nxt[i], i, 1);
        for (int i = 1; i <= n; i++){
            if (root[i] == i){
                lca.dfs2(i,i);
                lca.addedge(0, i, 0);
            }
        }
        lca.solve(0);
        int a, b;
        while (m-- > 0) {
            scanf("%d %d", &a, &b);
            int p = lca.query(a, b);
            if (p != 0)
                printf("%d %d\n", (lca.dis[a] - lca.dis[p]), (lca.dis[b]-lca.dis[p]));
            else {
                int ra = root[a], rb = root[b];
                if (cc[ra] != cc[rb])
                    printf("-1 -1\n");
                else {
                    int cnt=len[cc[ra]];
                    int temp1 = lca.dis[a];
                    int temp2 = lca.dis[b];
                    if (pos[ra] < pos[rb])
                        temp1 += pos[rb] - pos[ra];
                    else
                        temp1 += (cnt - pos[ra] + pos[rb]);
                    int temp3 = lca.dis[a];
                    int temp4 = lca.dis[b];
                    if (pos[rb]<pos[ra])
                        temp4 += pos[ra]- pos[rb];
                    else
                        temp4 +=(cnt-pos[rb]+pos[ra]);
                    if (max(temp1, temp2) < max(temp3, temp4))
                        printf("%d %d\n", temp1, temp2);
                    if (max(temp1, temp2) > max(temp3, temp4))
                        printf("%d %d\n", temp3, temp4);
                    if (max(temp1, temp2) == max(temp3, temp4)) {
                        if (min(temp1, temp2) < min(temp3, temp4))
                            printf("%d %d\n", temp1, temp2);
                        if (min(temp1, temp2) > min(temp3, temp4))
                            printf("%d %d\n", temp3, temp4);
                        if (min(temp1,temp2)==min(temp3, temp4)) {
                            if (temp1>=temp2)
                                printf("%d %d\n",temp1,temp2);
                            else
                                printf("%d %d\n",temp3,temp4);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
