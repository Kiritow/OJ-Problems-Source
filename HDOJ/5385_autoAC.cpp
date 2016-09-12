#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1 | 1
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e5+10;
long long inf=1e15;
const int MOD=258280327;
int T,n,m,k,x,y,z,l,tot,t,A,B,q;
int cas=1;
int u[N],v[N];
vector<int> vec[N];
bool vis[N];
int dis[N];
int fa[N];
void relax(int x){
    for(int i=0;i<vec[x].size();i++){
        int v1=vec[x][i];
        if(!vis[v1] && !fa[v1]) fa[v1]=x;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
   while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) vec[i].clear();
        for(int i=1;i<=n;i++) vis[i]=false,fa[i]=0;
        for(int i=1;i<=m;i++){
            scanf("%d%d",u+i,v+i);
            vec[u[i]].push_back(v[i]);
        }
        vis[1]=true;
        dis[1]=0;
        fa[1]=-1;
        int now=1;
        int pre=2,last=n;
        relax(1);
        while(pre<=last){
            if(fa[pre]){
                dis[pre]=now++;
                vis[pre]=true;
                relax(pre);
                pre++;
                continue;
            }
            if(fa[last]){
                dis[last]=now++;
                vis[last]=true;
                relax(last);
                last--;
                continue;
            }
        }
        for(int i=1;i<=m;i++){
            if(fa[v[i]]!=u[i]) printf("%d\n",n);
            else printf("%d\n",dis[v[i]]-dis[u[i]]);
        }
   }
    return 0;
}
