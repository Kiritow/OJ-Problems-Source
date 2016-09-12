#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <stack>
using namespace std;
const int MAXM=300010;
const int MAXN=200010;
struct edge{
    int u,v;
}edges[MAXM*2];
int head[MAXN];
int pre[MAXM*2];
int Next[MAXM*2];
int deg[MAXN];
int ans[MAXM];
int ecnt;
int n,m;
int init(){
    memset(head,-1,sizeof(head));
    memset(Next,-1,sizeof(Next));
    memset(deg,0,sizeof(deg));
    ecnt=0;
}
void addedge(int u,int v){
    edges[ecnt].u=u;    edges[ecnt].v=v;
    pre[ecnt]=head[u];
    head[u]=ecnt;
    ecnt++;
    edges[ecnt].u=v;    edges[ecnt].v=u;
    pre[ecnt]=head[v];
    head[v]=ecnt;
    ecnt++;
}
void dfs(int u){
    while(head[u]!=-1){
        deg[u]--;
        int i=head[u];
        int v=edges[i].v;
        if(i&1){
            ans[(i>>1)+1]=0;
        }else{
            ans[(i>>1)+1]=1;
        }
        int pp,nn;
        if(head[u]==i){
            head[u]=pre[i];
        }
        pp=pre[i];
        nn=Next[i];
        if(pp!=-1)Next[pp]=nn;
        if(nn!=-1)pre[nn]=pp;
        int _i=i^1;
        if(head[v]==_i){
            head[v]=pre[_i];
        }
        pp=pre[_i];
        nn=Next[_i];
        if(pp!=-1)Next[pp]=nn;
        if(nn!=-1)pre[nn]=pp;
        u=v;
        if(deg[v])deg[v]--;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        init();
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            deg[u]++;
            deg[v]++;
        }
        for(int i=0;i<ecnt;i++){
            if(pre[i]!=-1)Next[pre[i]]=i;
        }
        for(int i=1;i<=n;i++){
            Next[head[i]]=-1;
        }
        for(int i=1;i<=n;i++){
            if(deg[i]&1){
                dfs(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(deg[i]){
                dfs(i);
            }
        }
        for(int i=1;i<=m;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
