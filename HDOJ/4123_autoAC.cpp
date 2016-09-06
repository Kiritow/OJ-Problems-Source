#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>
#include<string>
#define N 50010
#define M 510
#define inf 200000000 
int w[N],edge,id[N],an[M];
__int64 dp[N][2],dis[N];
struct qq{
    int id;
    __int64 l;
}q[M];
bool cmp(const qq &a,const qq &b){
    return a.l<b.l;
}
struct node{
    int v,next;
    __int64 l;
}e[N*2];
void add(int u,int v,__int64 l){
    e[edge].v=v;
    e[edge].l=l;
    e[edge].next=w[u];
    w[u]=edge++;
}
void dfs1(int u,int no){
    for(int i=w[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v!=no){
            dfs1(v,u);
            if(dp[v][0]+e[i].l>dp[u][0]){
                dp[u][1]=dp[u][0];
                id[u]=v,dp[u][0]=dp[v][0]+e[i].l;
            }
            else if(dp[v][0]+e[i].l>dp[u][1]) dp[u][1]=dp[v][0]+e[i].l;
        }
    }
}
void dfs2(int u,int no,__int64 l){
    dis[u]=max(l,dp[u][0]);
    for(int i=w[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v!=no){
            if(v==id[u]) dfs2(v,u,max(l,dp[u][1])+e[i].l);
            else dfs2(v,u,dis[u]+e[i].l);
        }
    }
}
int dp_max[N][20],dp_min[N][20];
__int64 p[20];
int max_id(int x,int y){
    return dis[x]>dis[y]?x:y;
}
int min_id(int x,int y){
    return dis[x]>dis[y]?y:x;
}
int log(int x){
    int i=0;
    while(p[i]<=x) i++; 
    return i-1;
}
int get_max_id(int x,int y){
    int t=log(y-x+1);
    return max_id(dp_max[x][t],dp_max[y-p[t]+1][t]);
}
int get_min_id(int x,int y){
    int t=log(y-x+1);
    return min_id(dp_min[x][t],dp_min[y-p[t]+1][t]);
}
__int64 get_min(int x,int y){
    return dis[get_min_id(x,y)];
}
__int64 get_max(int x,int y){
    return dis[get_max_id(x,y)];
}
void RMQ(int n){
    int i,j,l=n,t=0;
    p[0]=1;
    for(i=1;i<18;i++) 
        p[i]=p[i-1]<<1;
    t=log(n);
    for(i=1;i<=n;i++) 
        dp_max[i][0]=dp_min[i][0]=i;
    for(i=1;i<=t;i++){
        l=n-p[i]+1;
        for(j=1;j<=l;j++){
            dp_max[j][i]=max_id(dp_max[j][i-1],dp_max[j+p[i-1]][i-1]);
            dp_min[j][i]=min_id(dp_min[j][i-1],dp_min[j+p[i-1]][i-1]);
        }
    }
}
int main(){
    int n,m,a,b;
    __int64 c;
    while(scanf("%d%d",&n,&m)){
        if(!n&&!m) break;
        edge=0;
        memset(w,-1,sizeof(int)*(n+1));
        for(int i=1;i<n;++i){
            scanf("%d%d%I64d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        memset(dis,0,sizeof(__int64)*(n+1));
        memset(dp,0,sizeof(dp));
        dfs1(1,1);
        dfs2(1,1,0);
        RMQ(n);
        for(int i=0;i<m;++i){
            scanf("%I64d",&q[i].l);
            q[i].id=i;
        }
        sort(q,q+m,cmp);
        for(int i=0;i<m;++i){
            int ans,start=1;
            if(!i) ans=1;
            else ans=an[q[i-1].id];
            while(1){
                int j=start+ans-1;
                for(;j<=n&&get_max(start,j)-get_min(start,j)<=q[i].l;++j);
                if(ans<j-start) ans=j-start;
                if(j==n+1) break;
                ++start;
            }
            an[q[i].id]=ans;
        }
        for(int i=0;i<m;++i) printf("%d\n",an[i]);
    }
    return 0;
}
