#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int maxn = 1000005;
int N,M1,M2,cnt;
int fa[maxn],vis[maxn];
vector<int>G[maxn];
int find_father(int u){
    return u == fa[u] ? u : fa[u] = find_father(fa[u]);
}
void init(){
    for(int i = 1; i <= N; i++) fa[i] = i;
    for(int i = 1; i <= N; i++) G[i].clear();
}
bool dfs(int v){
    vis[v] = -1;
    for(int i = 0; i < G[v].size(); i++){
        int e = G[v][i];
        if(vis[e] < 0) return false;
        if(!vis[e] && !dfs(e)) return false;
    }
    vis[v] = 1;
    return true;
}
int solve(){
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= N; i++){
        int e = find_father(i);
        if(!vis[e]){
            if(!dfs(e)) return true;
        }
    }
    return false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&M1,&M2);
        int u,v,ok = 0;
        init();
        getchar();
        for(int i = 0; i < M1; i++){
            scanf("%d%d",&u,&v);
            int f1 = find_father(u);
            int f2 = find_father(v);
            if(f1 == f2)
                ok = 1;
            else
                fa[f1] = f2;
        }
        for(int i = 0; i < M2; i++){
            scanf("%d%d",&u,&v);
            if(!ok){
                int f1 = find_father(u);
                int f2 = find_father(v);
                G[f1].push_back(f2);
            }
        }
        if(ok)
            printf("YES\n");
        else{
            ok = solve();
            if(ok)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
