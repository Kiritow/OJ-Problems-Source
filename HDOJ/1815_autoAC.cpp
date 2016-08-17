#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
#define MAXN 1111
struct Edge{
    int v,Next;
}edge[MAXN*MAXN*11];
int N,A,B,NE;
int head[MAXN];
void Insert(int u,int v)
{
    edge[NE].v=v;
    edge[NE].Next=head[u];
    head[u]=NE++;
}
int cnt,_count;
int low[MAXN],dfn[MAXN];
int color[MAXN];
bool mark[MAXN];
stack<int>S;
void Tarjan(int u)
{
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    S.push(u);
    for(int i=head[u];i!=-1;i=edge[i].Next){
        int v=edge[i].v;
        if(dfn[v]==0){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(mark[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        int v;
        _count++;
        do{
            v=S.top();
            S.pop();
            mark[v]=false;
            color[v]=_count;
        }while(u!=v);
    }
}
struct Point{
    int x,y;
}pp[MAXN],hate[MAXN],like[MAXN],s1,s2;
int dist[MAXN][MAXN];
inline int Get_dist(Point p,Point q)
{
    return abs(p.x-q.x)+abs(p.y-q.y);
}
void Build(int limit)
{
    NE=0;
    memset(head,-1,(2*N+4)*sizeof(int));
    for(int i=1;i<=A;i++){
        Insert(hate[i].x,hate[i].y+N);
        Insert(hate[i].y,hate[i].x+N);
        Insert(hate[i].x+N,hate[i].y);
        Insert(hate[i].y+N,hate[i].x);
    }
    for(int i=1;i<=B;i++){
        Insert(like[i].x,like[i].y);
        Insert(like[i].y+N,like[i].x+N);
        Insert(like[i].x+N,like[i].y+N);
        Insert(like[i].y,like[i].x);
    }
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(dist[i][N+1]+dist[j][N+1]>limit){
                Insert(i,j+N);
                Insert(j,i+N);
            }
            if(dist[i][N+2]+dist[j][N+2]>limit){
                Insert(i+N,j);
                Insert(j+N,i);
            }
            if(dist[i][N+1]+dist[N+1][N+2]+dist[j][N+2]>limit){
                Insert(i,j);
                Insert(j+N,i+N);
            }
            if(dist[i][N+2]+dist[N+1][N+2]+dist[j][N+1]>limit){
                Insert(i+N,j+N);
                Insert(j,i);
            }
        }
    }
}
bool Judge()
{
    cnt=_count=0;
    memset(mark,false,(2*N+4)*sizeof(bool));
    memset(dfn,0,(2*N+4)*sizeof(int));
    for(int i=1;i<=2*N;i++)if(dfn[i]==0)Tarjan(i);
    for(int i=1;i<=N;i++){
        if(color[i]==color[i+N])return false;
    }
    return true;
}
int main()
{
    while(~scanf("%d%d%d",&N,&A,&B)){
        scanf("%d%d%d%d",&s1.x,&s1.y,&s2.x,&s2.y);
        dist[N+1][N+2]=Get_dist(s1,s2);
        for(int i=1;i<=N;i++){
            scanf("%d%d",&pp[i].x,&pp[i].y);
            dist[i][N+1]=Get_dist(pp[i],s1);
            dist[i][N+2]=Get_dist(pp[i],s2);
        }
        for(int i=1;i<=A;i++){
            scanf("%d%d",&hate[i].x,&hate[i].y);
        }
        for(int i=1;i<=B;i++){
            scanf("%d%d",&like[i].x,&like[i].y);
        }    
        int low=0,high=44444444,mid,ans=-1;
        while(low<=high){
            mid=(low+high)>>1;
            Build(mid);
            if(Judge()){
                ans=mid;
                high=mid-1;
            }else 
                low=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
