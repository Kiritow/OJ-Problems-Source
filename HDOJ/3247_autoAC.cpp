#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N 100005
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
struct Trie{
    int next[2],fail;
    int virus,source;
    void Init(){next[0]=next[1]=0;fail=source=virus=0;}
}tree[N];
int n,m;
int tot,cnt;
int path[205][205];
int pos[205];
int dp[1<<10][205];
char str[50005];
void Insert(char *s,int len,int kind){
    int p=0;
    for(int i=0;i<len;i++){
        if(tree[p].next[s[i]-'0']==0){
            tree[++tot].Init();
            tree[p].next[s[i]-'0']=tot;
        }
        p=tree[p].next[s[i]-'0'];
    }
    if(kind>=0) tree[p].source=1<<kind;
    else tree[p].virus=1;
}
void Bulid_fail(){
    int que[N];
    int head=0,tail=0;
    que[tail++]=0;
    while(head<tail){
        int p=que[head++];
        for(int i=0;i<2;i++){
            if(tree[p].next[i]==0) tree[p].next[i]=tree[tree[p].fail].next[i];
            else{
                int q=tree[p].next[i];
                if(p)  tree[q].fail=tree[tree[p].fail].next[i];
                tree[q].source|=tree[tree[q].fail].source;
                tree[q].virus|=tree[tree[q].fail].virus;
                que[tail++]=q;
            }
        }
    }
}
void Bfs(int u){
    int que[N];
    int head=0,tail=0;
    int dist[N];
    memset(dist,-1,sizeof(dist));
    que[tail++]=pos[u];
    dist[pos[u]]=0;
    while(head<tail){
        int p=que[head++];
        for(int i=0;i<2;i++){
            int q=tree[p].next[i];
            if(dist[q]<0&&!tree[q].virus){
                dist[q]=dist[p]+1;
                que[tail++]=q;
            }
        }
    }
    for(int i=0;i<cnt;i++)
        path[u][i]=dist[pos[i]];
}
int DP(){
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<cnt;j++){
            if(dp[i][j]<0) continue;
            for(int k=0;k<cnt;k++){
                if(path[j][k]<0) continue;
                if(dp[i|tree[pos[k]].source][k]==-1) dp[i|tree[pos[k]].source][k]=dp[i][j]+path[j][k];
                else dp[i|tree[pos[k]].source][k]=min(dp[i|tree[pos[k]].source][k],dp[i][j]+path[j][k]);
            }
        }
    }
    int ans=inf;
    for(int i=0;i<cnt;i++)
        if(dp[(1<<n)-1][i]!=-1) ans=min(ans,dp[(1<<n)-1][i]);
    return ans==inf?-1:ans;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        tree[0].Init();cnt=1;tot=0;
        for(int i=0;i<n;i++){
            scanf("%s",str);
            Insert(str,strlen(str),i);
        }
        for(int i=0;i<m;i++){
            scanf("%s",str);
            Insert(str,strlen(str),-1);
        }
        Bulid_fail();
        for(int i=1;i<=tot;i++)
            if(tree[i].source)
                pos[cnt++]=i;
        for(int i=0;i<cnt;i++)
            Bfs(i);
        printf("%d\n",DP());
    }
    return 0;
}
