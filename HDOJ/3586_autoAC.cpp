#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int VM=1010;
const int INF=1000010;  
struct Edge{
    int to,nxt;
    int cap;
}edge[VM<<1];
int n,m,cnt,head[VM];
int dp[VM],vis[VM];
void addedge(int cu,int cv,int cw){
    edge[cnt].to=cv;
    edge[cnt].cap=cw;
    edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
}
void DFS(int u,int pre,int lim){
    int flag=0; 
    dp[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(v!=pre){
            flag=1;
            DFS(v,u,lim);
            if(edge[i].cap<=lim)
                dp[u]+=min(dp[v],edge[i].cap);
            else
                dp[u]+=dp[v];
        }
    }   
    if(!flag)   
        dp[u]=INF;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==0 && m==0)
            break;
        cnt=0;
        memset(head,-1,sizeof(head));
        int MAX=0;
        int u,v,w;
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
            if(w>MAX)
                MAX=w;
        }
        int l=1,r=MAX,ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            DFS(1,-1,mid);
            if(dp[1]<=m){
                ans=mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
