#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int sigma_size=26;
const int N=200+100;
const int MAXN=40000+100;
const double eps=1e-8;
const int inf=0x3fffffff;
const int mod=1000000000+7;
#define L(x) (x<<1)
#define R(x) (x<<1|1)
int n,T;
int dp[MAXN],res[MAXN],st[MAXN];
struct node{
    int x,y,t,val;
}p[N];
vector<int>G[N];
bool judge(node a,node b){
    return a.x*b.y == b.x*a.y;
}
bool cmp(int a,int b){
    return p[a].x*p[a].x+p[a].y*p[a].y<p[b].x*p[b].x+p[b].y*p[b].y;
}
int main()
{
    int kase=0;
    while(~scanf("%d%d",&n,&T)){
        for(int i=1;i<=n;i++)
            scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].t,&p[i].val);
        int cnt=0;
        for(int i=1;i<=n;i++){
            int flag=1;
            for(int j=0;j<cnt;j++){
                if(!flag)
                    break;
                if(judge(p[i],p[G[j][0]])){
                    G[j].push_back(i);
                    flag=0;
                }
            }
            if(!flag)
                continue;
            G[cnt].clear(); G[cnt++].push_back(i);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<cnt;i++){
            sort(G[i].begin(),G[i].end(),cmp);
            memcpy(res,dp,sizeof(dp));
            memcpy(st,dp,sizeof(dp));
            int val=0,t=0;
            for(int j=0;j<G[i].size();j++){
                int id=G[i][j];
                t+=p[id].t; val+=p[id].val;
                if(t>T)
                    break;
                for(int k=T;k>=t;k--)
                    if(res[k]<=res[k-t]+val)
                        res[k]=res[k-t]+val;
                for(int k=t;k<=T;k++)
                    dp[k]=max(dp[k],res[k]);
                memcpy(res,st,sizeof(st));
            }
        }
        printf("Case %d: %d\n",++kase,dp[T]);
    }
    return 0;
}
