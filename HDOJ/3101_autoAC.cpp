#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <time.h>;
#define cler(arr, val)    memset(arr, val, sizeof(arr))
#define FOR(i,a,b)  for(int i=a;i<=b;i++)
typedef long long  LL;
const int MAXN = 1032;
const int MAXM = 444;
const int INF = 0x3f3f3f3f;
const int mod = 1000000007;
vector<int>G[MAXN];
int val[MAXN],vis[MAXN],ans,num,orz[MAXN],man;
void init()
{
    for(int i=0; i<MAXN; i++)
        G[i].clear();
    cler(val,0);
    cler(vis,0);
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k),n+k)
    {
        init();
        for(int i=0; i<n; i++)
        {
            int a,m;
            scanf("%d%d",&val[i],&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d",&a);
                G[i].push_back(a);
            }
        }
        for(int i=0; i<n; i++)
        {
            orz[i]=val[i];
            for(int j=0; j<G[i].size(); j++)
                orz[i]+=val[G[i][j]];
        }
        ans=0,num=0;
        queue<int>q;
        for(int i=0; i<n; i++)
            if(orz[i]<k)
                q.push(i),vis[i]=1;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            for(int j=0; j<G[i].size(); j++)
            {
                orz[G[i][j]]-=val[i];
                if(orz[G[i][j]]<k&&!vis[G[i][j]])
                    q.push(G[i][j]),vis[G[i][j]]=1;
            }
        }
        for(int i=0; i<n; i++)
            if(!vis[i])
                num++,ans+=val[i];
        printf("%d %d\n",num,ans);
    }
    return 0;
}
