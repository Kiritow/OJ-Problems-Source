#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define N 510
struct node{
    int nt;
    int cost;
    int x1,x2,y1,y2;
}s[N];
vector<int> g[N];
int linker[N];
bool vis[N];
bool dfs(int u){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v]){
            vis[v]=1;
            if(linker[v]==-1||dfs(linker[v])){
                linker[v]=u;
                return true;
            }
        }
    }
    return false;
}
int hungary(int n){
    memset(linker,-1,sizeof(linker));
    int cnt=0;
    for(int i=0;i<n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i)) cnt++;
    }
    return cnt;
}
int main(){
    int t,n;
    scanf("%d",&t);
    char str[7];
    while(t--){
        scanf("%d",&n);
        int st,cost;
        int x1,y1,x2,y2;
        for(int i=0;i<n;i++){
            scanf("%s",str);
            g[i].clear();
            st=((str[0]-'0')*10+(str[1]-'0'))*60+(str[3]-'0')*10+(str[4]-'0');
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            cost=abs(x1-x2)+abs(y1-y2);
            s[i].nt=st;
            s[i].cost=cost;
            s[i].x1=x1;
            s[i].x2=x2;
            s[i].y1=y1;
            s[i].y2=y2;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i].nt+s[i].cost+1+abs(s[i].x2-s[j].x1)+abs(s[i].y2-s[j].y1)<=s[j].nt){
                    g[i].push_back(j);
                }
            }
        }
        printf("%d\n",n-hungary(n));
    }
    return 0;
}
