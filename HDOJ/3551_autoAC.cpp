#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 800;
int n,head,tail,start,finish,match[MAXN],fa[MAXN],base[MAXN],Q[MAXN];
int adj[MAXN][MAXN];  
bool mark[MAXN],in_blossom[MAXN],in_queue[MAXN];
inline void Contract (int x,int y){
        memset(mark,0,sizeof(mark));
        memset(in_blossom,0,sizeof(in_blossom));
#define pre fa[match[i]]
        int lca,i;
        for(i = x;i;i = pre){
                i = base[i];
                mark[i] = 1;
        }
        for(i = y;i; i = pre){
                i = base[i];
                if(mark[i]){
                        lca = i;
                        break;
                }
        }
        for (i = x; base[i] != lca; i = pre){
                if(base[pre] != lca) fa[pre] = match[i];
                in_blossom[base[i]] = 1;
                in_blossom[base[match[i]]] = 1;
        }
        for (i = y; base[i] != lca; i = pre){
                if (base[pre] != lca) fa[pre] = match[i];
                in_blossom[base[i]] = 1;
                in_blossom[base[match[i]]] = 1;
        }
#undef pre
        if (base[x] != lca) fa[x] = y;
        if (base[y] != lca) fa[y] = x;
        for (i = 1; i <= n; ++i){
                if (in_blossom[base[i]]){
                        base[i] = lca;
                        if (!in_queue[i]){
                                Q[++tail] = i;
                                in_queue[i] = 1;
                        }
                }
        }
}
inline void Change(){
        int x,y,z;
        z = finish;
        while (z){
                y = fa[z];
                x = match[y];
                match[y] = z;
                match[z] = y;
                z = x;
        }
}
inline void FindAugmentPath(){
        memset(fa,0,sizeof(fa));
        memset(in_queue,0,sizeof(in_queue));
        for(int i = 1; i <= n; ++i)base[i] = i;
        head = 0; tail = 1;
        Q[1] = start;
        in_queue[start] = 1;
        while (head != tail){
                int x = Q[++head];
                for (int y = 1; y <= n; ++y){
                        if (adj[x][y] && base[x] != base[y] && match[x] != y)
                                if (start == y || match[y] && fa[match[y]])
                                        Contract(x,y);
                                else if(!fa[y]){
                                        fa[y] = x;
                                        if(match[y]){
                                                Q[++tail] = match[y];
                                                in_queue[match[y]] = 1;
                                        }
                                        else {
                                                finish = y;
                                                Change();
                                                return;
                                        }
                                }
                }
        }
}
inline void Edmonds(){
        memset(match,0,sizeof(match));
        for (start = 1; start <= n; ++start)
                if (match[start] == 0)
                        FindAugmentPath();
}
inline void init(){
    memset(adj,0,sizeof(adj));
}
int deg[MAXN], D[MAXN], M;
pair<int ,int> edge[MAXN], id[MAXN];
int main(){
        int Case, u, v,V;
        scanf("%d",&Case);
        for(int it = 1;it <= Case; ++it){
                scanf("%d%d",&V,&M);
                memset(deg, 0, sizeof(deg));
                memset(adj, 0, sizeof(adj));
                for(int i = 0;i < M; ++i){
                        scanf("%d%d",&u,&v);
                        u --; v --;
                        edge[i] = make_pair(u, v);
                        deg[u] ++; deg[v] ++;
                }
                for(int i = 0;i < V; ++i){
                        scanf("%d",&D[i]);
                }
                bool flag = true;
                int cnt = 1;
                for(int i = 0;i < MAXN; ++i) id[i] = make_pair(-1, -1);
                for(int i = 0;i < V; ++i)
                        if(deg[i] < D[i]) { flag = false; break; }
                printf("Case %d: ",it);
                if(!flag) {
                        puts("NO");
                        continue;
                }
                for(int i = 0;i < M; ++i){
                        u = edge[i].first;
                        v = edge[i].second;
                        if(id[u].first == -1){
                                id[u] = make_pair(cnt, cnt + deg[u] - D[u] - 1);
                                cnt += (deg[u] - D[u]);
                        }
                        if(id[v].first == -1){
                                id[v] = make_pair(cnt, cnt + deg[v] - D[v] - 1);
                                cnt += (deg[v] - D[v]);
                        }
                        if(id[V+i].first == -1){
                                id[V+i] = make_pair(cnt, cnt + 1);
                                cnt += 2;
                        }
                        int t = id[V+i].first;
                        adj[t][t+1] = adj[t+1][t] = true;
                        for(int j = id[u].first;j <= id[u].second; ++j)
                                adj[t][j] = adj[j][t] = true;
                        for(int j = id[v].first;j <= id[v].second; ++j)
                                adj[t+1][j] = adj[j][t+1] = true;
                }
                int j, sum = 0;
                n  = cnt-1;
                flag = 1;
                Edmonds();
                for(int i = 1; i <= n; ++i){
                        if(!match[i]){
                                flag = 0;
                                break;
                        }
                }
                if(flag) puts("YES");
                else puts("NO");
        }
}
