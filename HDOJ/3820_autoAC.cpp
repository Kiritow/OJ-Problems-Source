#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int VM=101000;
const int EM=500100;
const int INF=0x3f3f3f3f;
struct Edge{
    int to,nxt;
    int cap;
}edge[EM<<1];
int n,m,G,S,cnt,head[VM],src,des,map1[110][110],map2[110][110];
int dep[VM],gap[VM],cur[VM],aug[VM],pre[VM];
void addedge(int cu,int cv,int cw){
    edge[cnt].to=cv;  edge[cnt].cap=cw;  edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
    edge[cnt].to=cu;  edge[cnt].cap=0;   edge[cnt].nxt=head[cv];
    head[cv]=cnt++;
}
int SAP(int n){
    int max_flow=0,u=src,v;
    int id,mindep;
    aug[src]=INF;
    pre[src]=-1;
    memset(dep,0,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0]=n;
    for(int i=0;i<=n;i++)
        cur[i]=head[i]; 
    while(dep[src]<n){
        int flag=0;
        if(u==des){
            max_flow+=aug[des];
            for(v=pre[des];v!=-1;v=pre[v]){     
                id=cur[v];
                edge[id].cap-=aug[des];
                edge[id^1].cap+=aug[des];
                aug[v]-=aug[des];  
                if(edge[id].cap==0) 
                    u=v;
            }
        }
        for(int i=cur[u];i!=-1;i=edge[i].nxt){
            v=edge[i].to;    
            if(edge[i].cap>0 && dep[u]==dep[v]+1){  
                flag=1;
                pre[v]=u;
                cur[u]=i;
                aug[v]=min(aug[u],edge[i].cap);
                u=v;
                break;
            }
        }
        if(!flag){
            if(--gap[dep[u]]==0)   
                break;
            mindep=n;
            cur[u]=head[u];
            for(int i=head[u];i!=-1;i=edge[i].nxt){
                v=edge[i].to;
                if(edge[i].cap>0 && dep[v]<mindep){
                    mindep=dep[v];
                    cur[u]=i;   
                }
            }
            dep[u]=mindep+1;
            gap[dep[u]]++;
            if(u!=src)
                u=pre[u];
        }
    }
    return max_flow;
}
int main(){
    int t,cases=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&G,&S);
        cnt=0;
        memset(head,-1,sizeof(head));
        src=0; des=n*m*2+1;
        int sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&map1[i][j]);
                sum+=map1[i][j];
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&map2[i][j]);
                sum+=map2[i][j];
            }
        int tmp;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                tmp=(i-1)*m+j;
                if((i+j)%2==0){
                    addedge(src,tmp,map1[i][j]);
                    addedge(tmp,tmp+n*m,INF);
                    addedge(tmp+n*m,des,map2[i][j]);
                    if(i>1) addedge(tmp,tmp-m+n*m,G);
                    if(i<n) addedge(tmp,tmp+m+n*m,G);
                    if(j>1) addedge(tmp,tmp-1+n*m,G);
                    if(j<m) addedge(tmp,tmp+1+n*m,G);
                }else{
                    addedge(src,tmp,map2[i][j]);
                    addedge(tmp,tmp+n*m,INF);
                    addedge(tmp+n*m,des,map1[i][j]);
                    if(i>1) addedge(tmp,tmp-m+n*m,S);
                    if(i<n) addedge(tmp,tmp+m+n*m,S);
                    if(j>1) addedge(tmp,tmp-1+n*m,S);
                    if(j<m) addedge(tmp,tmp+1+n*m,S);
                }
            }
        }
        printf("Case %d: %d\n",++cases,sum-SAP(des+1));
    }
    return 0;
}
