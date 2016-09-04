#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=1e+3;
const int MAXM=1e+5;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();
struct Edge
{
    int from,to;
    LL ci;int next;
    Edge(){}
    Edge(int _from,int _to,LL _ci,int _next):from(_from),to(_to),ci(_ci),next(_next){}
}e[MAXM],e1[MAXM];
int head[MAXN],tot;
int dis[MAXN];
int top,sta[MAXN],cur[MAXN],tmp[MAXN];
int vis1[100],vis2[MAXM];
int n;
inline void init(){
    memset(head,-1,sizeof(head));
    tot=0;
}
inline void AddEdge(int u,int v,LL ci0,LL ci1=0){
    e[tot]=Edge(u,v,ci0,head[u]);
    head[u]=tot++;
    e[tot]=Edge(v,u,ci1,head[v]);
    head[v]=tot++;
}
inline bool bfs(int st,int et){
    memset(dis,0,sizeof(dis));
    dis[st]=1;
    queue <int> q;
    q.push(st);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=head[now];i!=-1;i=e[i].next){
            int next=e[i].to;
            if(vis2[i])continue;
            if(e[i].ci&&!dis[next]){
                dis[next]=dis[now]+1;
                if(next==et)return true;
                q.push(next);
            }
        }
    }
    return false;
}
LL Dinic(int st,int et){
    LL ans=0;
    while(bfs(st,et)){
        top=0;
        memcpy(cur,head,sizeof(head));
        int u=st,i;
        while(1){
            if(u==et){
                int pos;
                LL minn=LL_INF;
                for(i=0;i<top;i++)
                {
                    if(minn>e[sta[i]].ci){
                        minn=e[sta[i]].ci;
                        pos=i;
                    }
                }
                for(i=0;i<top;i++){
                    e[sta[i]].ci-=minn;
                    e[sta[i]^1].ci+=minn;
                }
                top=pos;
                u=e[sta[top]].from;
                ans+=minn;
            }
            for(i=cur[u];i!=-1;cur[u]=i=e[i].next)
                if(vis2[i]);
                else if(e[i].ci&&dis[u]+1==dis[e[i].to])break;
            if(cur[u]!=-1){
                sta[top++]=cur[u];
                u=e[cur[u]].to;
            }
            else {
                if(top==0)break;
                dis[u]=0;
                u=e[sta[--top]].from;
            }
        }
    }
    return ans;
}
int main()
{
    char ch;
    while(~scanf("%d",&n)&&n){
        init();
        memset(vis2,0,sizeof(vis2));
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %c",&ch);
            if(ch=='Y'){
                AddEdge(i,j+n,1);
            }
        }
        }
        memcpy(e1,e,sizeof(e));
        memcpy(tmp,head,sizeof(head));
        int st=500,et=501;
        int ttot=tot;
        int l=0,r=100,ans=0,mid;
        while(l<=r){
            mid=(l+r)>>1;
            for(int i=1;i<=n;i++){
                AddEdge(st,i,mid);
                AddEdge(i+n,et,mid);
            }
            if(Dinic(st,et)==(LL)n*mid){
                ans=mid;
                //if(ans<mid)ans=mid;
                l=mid+1;
            }
            else r=mid-1;
            memcpy(e,e1,sizeof(e));
            memcpy(head,tmp,sizeof(head));
            tot=ttot;
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++){
            AddEdge(st,i,ans);
            AddEdge(i+n,et,ans);
        }
        Dinic(st,et);
        for(int i=1;i<=n;i++){
            for(int j=head[i];~j;j=e[j].next){
                if(e[j].ci&&e[j].to!=st){
                    vis2[j^1]=vis2[j]=1;
                }
            }
        }
        memcpy(e,e1,sizeof(e));
        memcpy(head,tmp,sizeof(head));
        tot=ttot;
        for(int j=1;j<=n;j++){
            AddEdge(st,j,1);
            AddEdge(j+n,et,1);
        }
        for(int i=0;i<ans;i++){
            memset(vis1,0,sizeof(vis1));
            tot=ttot;
            Dinic(st,et);
            for(int j=1;j<=n;j++){
                for(int k=head[j];~k;k=e[k].next){
                    if(vis2[k])continue;
                    if(e[k].ci==0&&e[k].to!=st){
                        vis1[e[k].to-n]=j;
                        vis2[k^1]=vis2[k]=1;
                        break;
                    }
                }
            }
            for(int j=1;j<n;j++){
            printf("%d ",vis1[j]);
            if(!vis1[j])while(1);
            }
            printf("%d\n",vis1[n]);
            if(!vis1[n])while(1);
            for(int j=head[st];~j;j=e[j].next){
                e[j].ci=1;e[j^1].ci=0;
            }
            for(int j=head[et];~j;j=e[j].next){
                e[j^1].ci=1;e[j].ci=0;
            }
        }
    }
    return 0;
}
