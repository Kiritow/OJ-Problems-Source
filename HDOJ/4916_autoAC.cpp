#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string>
#include <time.h>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
typedef long long ll;
int fun(){
       char ch;int flag=1,a=0;
       while(ch=getchar())if((ch>='0'&&ch<='9')||ch=='-')break;
       if(ch=='-')flag=-1;else a=ch-'0';
       while(ch=getchar()){
              if(ch>='0'&&ch<='9')a=10*a+ch-'0';
              else break;
       }
       return flag*a;
}
const int maxn=1001000;
int head[maxn],tol;
int subtree[maxn];
int belong[maxn];
int child[maxn][4];
int que[maxn];
int path[maxn];
int fa[maxn];
int dep[maxn];
struct Edge{
    int next,to;
}edge[2*maxn];
void addedge(int u,int v){
    edge[tol].to=v;
    edge[tol].next=head[u];
    head[u]=tol++;
}
int main()
{
     int n,m;
     while(~scanf("%d%d",&n,&m)){
         memset(head,-1,sizeof(head));tol=0;
         for(int i=1;i<n;i++){
             int u,v;
             u=fun();v=fun();
             addedge(u,v);
             addedge(v,u);
         }
         int front=0,rear=0;
         dep[1]=0;fa[1]=-1;
         que[rear++]=1;
         while(front!=rear){
             int u=que[front++];
             for(int i=head[u];i!=-1;i=edge[i].next){
                 int v=edge[i].to;
                 if(v==fa[u])continue;
                 dep[v]=dep[u]+1;
                 fa[v]=u;
                 que[rear++]=v;
             }
         }
         for(int i=1;i<=n;i++)
             for(int j=0;j<4;j++)
                 child[i][j]=INF;
         for(int i=rear-1;i>=0;i--){
             int u=que[i];
             subtree[u]=min(u,child[u][0]);
             int p=fa[u];
             if(p==-1)continue;
             child[p][3]=subtree[u];
             sort(child[p],child[p]+4);
         }
         front=0,rear=0;
         path[1]=INF;
         belong[1]=-1;
         for(int i=head[1];i!=-1;i=edge[i].next){
             int u=edge[i].to;
             path[u]=INF;
             belong[u]=subtree[u];
             que[rear++]=u;
         }
         while(front!=rear){
             int u=que[front++];
             for(int i=head[u];i!=-1;i=edge[i].next){
                 int v=edge[i].to;
                 if(v==fa[u])continue;
                 path[v]=min(path[u],child[u][subtree[v]==child[u][0]]);
                 belong[v]=belong[u];
                 que[rear++]=v;
             }
             path[u]=min(path[u],child[u][0]);
         }
         int last=0;
         while(m--){
             int u,v;
             u=fun();v=fun();
             u^=last;v^=last;
             if(u>v)swap(u,v);
             if(u!=1&&belong[u]==belong[v])last=1;
             else{
                 int i=0;
                 while(child[1][i]==belong[u]||child[1][i]==belong[v])i++;
                 last=u==1?path[v]:min(path[u],path[v]);
                 last=min(last,child[1][i]);
             }
             printf("%d\n",last);
         }
     }
     return 0;
}
