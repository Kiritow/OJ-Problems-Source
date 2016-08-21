#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define maxn 10010
using namespace std;
int n,m,a,b;
int pre[maxn];
vector <int> map[maxn];
bool vis[maxn];
int solve(){
    queue <int> q;
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre));
    vis[1] = 1;
    q.push(1);
    int ans = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < map[now].size(); i ++)
            pre[map[now][i]] = now;
        for(int i = 1; i <= n;i ++)
            if(!vis[i] && pre[i] != now)
                vis[i] = true, q.push(i),ans ++;
    }
    return ans;
}
int main(){
    int ca = 1;
    while(~scanf("%d%d",&n,&m) && (n || m)){
        for(int i = 1; i <= n; i ++)
            map[i].clear();
        for(int i = 0; i < m; i ++){
            scanf("%d%d",&a,&b);
            map[a].push_back(b);
            map[b].push_back(a);
        }
        printf("Case %d: %d\n",ca ++ ,solve());
    }
    return 0;
}
