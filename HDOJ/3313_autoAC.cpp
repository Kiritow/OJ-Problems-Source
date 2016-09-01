#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAXN 100010
int pre[MAXN],vis[MAXN],low[MAXN];
vector <int> e[MAXN];
int bfs1(int st,int et){
    queue <int> q;
    q.push(st);
    vis[st]=1;pre[st]=-1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=e[now].size()-1;i>=0;i--){
            int next=e[now][i];
            if(vis[next])continue;
            vis[next]=1;
            pre[next]=now;
            if(next==et)return 1;
            q.push(next);
        }
    }
    return 0;
}
int bfs2(int u){
    queue <int> q;
    q.push(u);
    int res=u;
    vis[u]=1;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=e[now].size()-1;i>=0;i--){
            int next=e[now][i];
            if(vis[next])continue;
            vis[next]=1;
            if(low[next]==0)q.push(next);
            else if(low[next]<low[res])res=next;
        }
    }
    return res;
}
int main()
{
    int n,m,st,et;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=n;i++)
        e[i].clear();
        memset(vis,0,sizeof(vis));
        memset(low,0,sizeof(low));
        for(int i=0,x,y;i<m;i++){
            scanf("%d%d",&x,&y);
            e[x].push_back(y);
        }
        scanf("%d%d",&st,&et);
        if(!bfs1(st,et)){
            printf("%d\n",n);
            continue;
        }
        int u=et,tot=1;
        memset(vis,0,sizeof(vis));
        while(u!=-1){
            low[u]=tot++;
            u=pre[u];
        }
        int cnt=1;
        u=st;
        while(u!=et){
            u=bfs2(u);
            ++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
