#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=6000+10;
int n,size,head[MAX],pre[MAX];
int temp[2],val[MAX];
struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX];
void Init(int num){
    for(int i=0;i<=num;++i)head[i]=-1,pre[i]=0;
    size=0;
}
void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++; 
}
void dfs(int u){
    int dp[2]={0,0};
    for(int i=head[u];i != -1;i=edge[i].next){
        int v=edge[i].v;
        dfs(v);
        dp[0]=dp[0]+max(temp[0],temp[1]);
        dp[1]=dp[1]+temp[0];
    }
    temp[0]=dp[0];
    temp[1]=dp[1]+val[u];
}
int main(){
    int u,v;
    while(~scanf("%d",&n)){
        Init(n);
        for(int i=1;i<=n;++i)scanf("%d",&val[i]);
        while(scanf("%d%d",&v,&u),u+v)pre[v]=u;
        for(int i=1;i<=n;++i)InsertEdge(pre[i],i);
        dfs(0);
        printf("%d\n",temp[0]);
    }
    return 0;
}
