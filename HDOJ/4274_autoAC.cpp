#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define inf 110000000
#define M 10005
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
struct Node{
    int v,next;
}edge[N*2];
int n,start[N],tot;
int up[N],low[N];
void addedge(int u,int v){
    edge[tot].v=v;
    edge[tot].next=start[u];
    start[u]=tot++;
}
void _addedge(int u,int v){
    addedge(u,v);
    addedge(v,u);
}
bool ans;
void dfs(int u,int pre){
    if(ans) return;
    if(up[u]!=-1&&low[u]>up[u]){ans=true;return;}
    int tmp=0;
    int leaf=1;
    for(int i=start[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==pre) continue;
        dfs(v,u);
        leaf=0;
        tmp+=low[v];
    }
    if(leaf) return;
    low[u]=max(tmp+1,low[u]);
    if(up[u]!=-1&&low[u]>up[u]) ans=true;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        tot=0;mem(start,-1);
        for(int i=2;i<=n;i++){
            int u;
            scanf("%d",&u);
            _addedge(u,i);
        }
        int m;
        for(int i=1;i<=n;i++){low[i]=1;up[i]=-1;}
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            int u,w;
            char str[5];
            scanf("%d%s%d",&u,str,&w);
            if(str[0]=='<') up[u]=w-1;
            else if(str[0]=='>') low[u]=w+1;
            else low[u]=up[u]=w;
        }
        ans=false;
        dfs(1,0);
        puts(ans?"Lie":"True");
    }
    return 0;
}
