#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,s,t) for(int i=s;i<t;i++)
#define red(i,s,t) for(int i=s-1;i>=t;i--)
#define ree(i,now) for(int i=head[now];i!=-1;i=edge[i].next)
#define clr(a,v) memset(a,v,sizeof a)
const int N=50005;
const int K=33;
struct Edge{
    int v,next;
}edge[N*2];
int head[N],e;
int Num[N][K];
int son[N],MaxSize;
int root,all;
int n,k,a[K],d[K],x,y,cnt;
ll v[N],dis[N],three[K],mark[N];
int Ans;
bool vis[N];
map<ll,int>mp,mpp;
inline void Init(){
    three[0]=1;
    rep(i,1,K) three[i]=three[i-1]*3;
}
inline int getPos(ll v,int x){
    return v%three[x+1]/three[x];
}
inline ll get(ll val,int *x){
    ll ans=0;
    rep(i,0,k) ans+=((getPos(val,i)+x[i])%3)*three[i];
    return ans;
}
inline void getCh(ll b,int i){
    bool ok=1;
    mark[i]=0;
    if(b==0)return;
    rep(j,0,k){
        Num[i][j]=0;
        while(b>1 && b%a[j]==0){
            Num[i][j]++;
            b/=a[j];
        }
        Num[i][j]%=3;
        mark[i]+=three[j]*Num[i][j];
        if(Num[i][j]!=0) ok=0;
    }
    if(ok) Ans++;
}
inline void addEdge(int u,int v){
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
inline void In(){
    scanf("%d",&k);
    rep(i,0,k) scanf("%d",&a[i]);
    rep(i,1,n+1){
        scanf("%I64d",&v[i]);
        getCh(v[i],i);
    }
    clr(head,-1),e=0;
    rep(i,1,n){
        scanf("%d%d",&x,&y);
        addEdge(x,y);addEdge(y,x);
    }
    clr(vis,0);
}
inline void dfs_Size(int now,int pre){
    all++;
    ree(i,now){
        int nxt=edge[i].v;
        if(!vis[nxt] && nxt!=pre) dfs_Size(nxt,now);
    }
}
inline void dfs_Root(int now,int pre){
    int Max=0;
    son[now]=0;
    ree(i,now){
        int nxt=edge[i].v;
        if(!vis[nxt] && pre!=nxt){
            dfs_Root(nxt,now);
            son[now]+=son[nxt]+1;
            if(son[nxt]+1>Max) Max=son[nxt]+1;
        }
    }
    int res=all-son[now]-1;
    if(Max<res) Max=res;
    if(Max<MaxSize){
        MaxSize=Max;root=now;
    }
}
inline ll Val(int *c){
    ll ans=0;
    rep(j,0,k) ans+=c[j]*three[j];
    return ans;
}
inline ll Transform(ll a,ll b){
    ll ans=0;
    rep(j,0,k) ans+=(getPos(a,j)+getPos(b,j))%3*three[j];
    return ans;
}
inline void dfs_Dis(int now,int pre,ll val){
    dis[cnt++]=val;
    ree(i,now){
        int nxt=edge[i].v;
        if(!vis[nxt] && nxt!=pre){
            dfs_Dis(nxt,now,Transform(val,mark[nxt]));
        }
    }
}
inline ll Suit(ll v){
    ll ans=0;
    rep(i,0,k){
        int x=getPos(v,i);
        int y=(3-x)%3;
        ans+=three[i]*y;
    }
    return ans;
}
inline void Work(int now){
    all=0;
    dfs_Size(now,-1);
    MaxSize=n+10;
    dfs_Root(now,-1);
    vis[root]=1;
    mp.clear();
    ree(i,root){
        int nxt=edge[i].v;cnt=0;
        if(vis[nxt]) continue;
        dfs_Dis(nxt,root,mark[nxt]);
        rep(j,0,cnt){
            int vv=mp[Suit(dis[j])];
            if(vv) Ans+=vv;
        }
        rep(j,0,cnt){
            ll p=get(dis[j],Num[root]);
            if(p==0) Ans++;
            mp[p]++;
        }
    }
    ree(i,root){
        int nxt=edge[i].v;
        if(!vis[nxt]){
            Work(nxt);
        }
    }
}
inline void app(){
    int a[]={2,3,5,7,11,13,17,19,23,29};
    rep(j,0,10){
        printf("3000 10 2 3 5 7 11 13 17 19 23 29\n");
        rep(i,0,3000) printf("%d ",a[rand()%10]);
        rep(i,1,3000) printf("%d 1\n",i+1);
    }
}
int main(){
    Init();
    while(~scanf("%d",&n)){
        Ans=0;
        In();
        Work(1);
        printf("%d\n",Ans);
    }
    return 0;
}
