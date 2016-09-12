#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
const int size=200111;
typedef long long ll;
ll inf=-1000111000ll;
typedef pair<int,int> P;
ll mod=1000000007;
int t,n,m,a[size],K;
vector<int>V[size];
int vis[size],sum[size],id,tmp;
void find(int u,int fa,int num){
    sum[u]=1;int K=0;
    for(int i=0;i<V[u].size();i++){
        int to=V[u][i];
        if(vis[to]||to==fa)continue;
        find(to,u,num);
        K=max(K,sum[to]);
        sum[u]+=sum[to];
    }
    K=max(K,num-sum[u]);
    if(K<tmp)tmp=K,id=u;
}
P b[size];
int tot;
void dfs(int u,int fa,int mi,int ma){
    sum[u]=1;
    mi=min(mi,a[u]);
    ma=max(ma,a[u]);
    if(ma<=mi+K)b[tot++]=P(mi,ma);
    for(int i=0;i<V[u].size();i++){
        int to=V[u][i];
        if(vis[to]||to==fa)continue;
        dfs(to,u,mi,ma);
        sum[u]+=sum[to];
    }
}
ll gao(int u,int mi,int ma){
    tot=0;
    dfs(u,0,mi,ma);
    sort(b,b+tot);
    ll ans=0;
    for(int i=0;i<tot;i++){
        int p=lower_bound(b,b+i,P(b[i].second-K,0))-b;
        ans+=i-p;
    }
    return ans;
}
ll work(int u,int num){
    tmp=n;
    find(u,0,num);
    u=id;
    ll ans=gao(u,a[u],a[u]);
    vis[u]=1;
    for(int i=0;i<V[u].size();i++){
        int to=V[u][i];
        if(!vis[to])ans-=gao(to,a[u],a[u]);
    }
    for(int i=0;i<V[u].size();i++){
        int to=V[u][i];
        if(!vis[to])ans+=work(to,sum[to]);
    }
    return ans;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>K;
        for(int i=1;i<=n;i++)V[i].clear(),scanf("%d",&a[i]),vis[i]=0;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            V[x].push_back(y);
            V[y].push_back(x);
        }
        cout<<work(1,n)*2<<endl;
    }
}
