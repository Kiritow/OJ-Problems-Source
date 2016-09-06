#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int VM=200010;
const int EM=200010;
const int INF=0x3f3f3f3f;
struct Edge{
    int to,nxt;
}edge[EM<<1];
long long n,m,cnt,head[VM];
long long dep,top,atype;
long long dfn[VM],low[VM],vis[VM],stack[VM],belong[VM],indeg[VM],outdeg[VM],sum[VM];
void addedge(int cu,int cv){
    edge[cnt].to=cv;    edge[cnt].nxt=head[cu];     head[cu]=cnt++;
}
void Tarjan(int u){
    dfn[u]=low[u]=++dep;
    stack[top++]=u;
    vis[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    int j;
    if(dfn[u]==low[u]){
        atype++;
        do{
            j=stack[--top];
            belong[j]=atype;
            sum[atype]++;   
            vis[j]=0;
        }while(u!=j);
    }
}
void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
    dep=0,  top=0,  atype=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(belong,0,sizeof(belong));
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
    memset(sum,0,sizeof(sum));
}
int main(){
    int t,cases=0;
    scanf("%d",&t);
    while(t--){
        cin>>n>>m;
        if(n==1){
            printf("Case %d: -1\n",++cases);
            continue;
        }
        init();
        int u,v;
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        for(int i=1;i<=n;i++)
            if(!dfn[i])
                Tarjan(i);
        if(atype==1){
            printf("Case %d: -1\n",++cases);
            continue;
        }
        for(int u=1;u<=n;u++)
            for(int i=head[u];i!=-1;i=edge[i].nxt){
                int v=edge[i].to;
                if(belong[u]!=belong[v]){
                    outdeg[belong[u]]++;
                    indeg[belong[v]]++;
                }
            }
        long long ans=0,tmp;
        for(long long i=1;i<=atype;i++)
            if(indeg[i]==0 || outdeg[i]==0){   
                tmp=sum[i];
                ans=max(ans,tmp*(tmp-1)+(n-tmp)*(n-tmp-1)+tmp*(n-tmp)-m);
            }
        cout<<"Case "<<(++cases)<<": "<<ans<<endl;
    }
    return 0;
}
