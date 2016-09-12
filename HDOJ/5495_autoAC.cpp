#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define maxn 100007
int a[maxn],b[maxn],vis[maxn];
int dfs(int x){
    vis[x] = 1;
    if(vis[b[a[x]]]) return 1;
    return dfs(b[a[x]])+1;
}
int main(){
    int t,n,u;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1;i <= n; i++){
            scanf("%d",&u);
            a[u] = i;
        }
        for(int i = 1;i <= n; i++)
            scanf("%d",&b[i]);
        memset(vis,0,sizeof(vis));
        int ans = n;
        for(int i = 1;i <= n; i++){
            if(vis[i] == 0) {
                if(dfs(i) > 1) ans--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
