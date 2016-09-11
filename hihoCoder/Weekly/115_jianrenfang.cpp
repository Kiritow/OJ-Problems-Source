#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define inf 0x3f3f3f3f
#define mod 10000
typedef long long ll;
using namespace std;
const int N=505;
const int M=100005;
int n,m,k,ans,t;
int pre[N];
struct man
{
    int c,f;
}w[N][N];
bool bfs()
{
    queue<int>q;
    q.push(1);
    memset(pre,0,sizeof(pre));
    pre[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=1;i<=t;i++){
            if( !pre[i] && w[u][i].c>w[u][i].f){
                pre[i]=pre[u]+1;
                q.push(i);
            }
        }
    }
    return pre[t]!=0;
}
int dfs(int u,int sum)
{
    if(u==t||sum==0)return sum;
    int tmp=sum,minn;
    for(int i=1;i<=t;i++){
        if(pre[i]==pre[u]+1&&w[u][i].c>w[u][i].f){
            minn=dfs(i,min(tmp,w[u][i].c-w[u][i].f));
            w[u][i].f+=minn;
            w[i][u].f -=minn;
            tmp-=minn;
        }
    }
    return sum-tmp;
}
void Dinic()
{
    ans=0;
    while(bfs())ans+=dfs(1,inf);
    cout<<ans<<endl;
}
int main() {
    scanf("%d%d",&n,&m);
    memset(w,0,sizeof(w));
    int a,b,v;
    t=n;
    while(m--)scanf("%d%d%d",&a,&b,&v),w[a][b].c+=v;
    Dinic();
    return 0;
}
