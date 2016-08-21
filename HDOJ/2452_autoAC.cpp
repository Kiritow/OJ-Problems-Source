#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int NM=10005;
const int MAX=0xfffffff;
int du[NM],dp[NM][2],a[NM];
vector<int>v[NM];
inline int max(int x,int y){
    return x>y?x:y;
}
inline int min(int x,int y){
    return x<y?x:y;
}
int DFS(int t,int s)
{
    int u,ans;
    if(t&1==1){  
        if(dp[s][1]!=-1) return dp[s][1];
        dp[s][1]=a[s];
        for(int i=0;i<v[s].size();i++){
            u=v[s][i];
            dp[s][1]=max(dp[s][1],a[s]+DFS(t+1,u));
        }
        return dp[s][1];
    }
    else{
        if(dp[s][0]!=-1) return dp[s][0];
        dp[s][0]=a[s];
        ans=MAX;
        for(int i=0;i<v[s].size();i++){
            u=v[s][i];
            ans=min(ans,a[s]+DFS(t+1,u));
            dp[s][0]=ans;
        }
        return dp[s][0];
    }    
}
int main()
{
    int n,m,f,i,x,y,u;
    while(~scanf("%d%d%d",&n,&m,&f)){
        for(i=1;i<NM;i++)
            v[i].clear();
        for(i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(du,0,sizeof(du));
        for(i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            du[y]++;
            v[x].push_back(y);
        }
        for(i=1;i<=n;i++){
            if(du[i]==0){
                u=i;break;
            }
        }
        memset(dp,-1,sizeof(dp));
        if(DFS(1,u)>=f) printf("Victory\n");
        else printf("Glory\n");
    }
    return 0;
}
