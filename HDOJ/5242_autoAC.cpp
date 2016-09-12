#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define LL __int64
const int maxn=1e5+100;
vector<LL>V[maxn];
priority_queue<LL>Q;
LL a[maxn];
LL dp[maxn];
LL dfs(int cur){
    int i,v;
    LL tmp;
    dp[cur]=a[cur];
    for(i=0;i<V[cur].size();i++){
        v=V[cur][i];
        tmp=dfs(v);
        if(dp[cur]>tmp+a[cur]){ 
            Q.push(tmp);
        }else{    
            Q.push(dp[cur]-a[cur]);
            dp[cur]=tmp+a[cur];
        }
    }
    return dp[cur];
}
int main(){
    int t ,n,m,i,j,k,u,v,cnt=0;
    LL ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            V[u].push_back(v);
        }
        dfs(1);
        ans=dp[1];
        for(i=1;i<k;i++){
            ans+=Q.top();
            Q.pop();
        }
        printf("Case #%d: %lld\n",++cnt,ans);
        while(!Q.empty())
            Q.pop();
        for(i=0;i<=n;i++){
            V[i].clear();
        }
    }
    return 0;
}
