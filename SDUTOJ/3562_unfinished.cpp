#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#define mod 1000000007
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
#define RANGE 1005
#define MAX 0x3f3f3f3f
int cost[RANGE][RANGE];
int d[RANGE];
bool used[RANGE];
int n,m;
int pre[1005];
void spfa(int s)
{
    int i,j,now;
    for(i=0; i<=n+1; i++)
    {
        d[i]=MAX;
        used[i]=false;
    }
    int flag=0;
    for(i=0; i<=n+1; i++)
    {
        if(cost[0][i]<MAX)pre[i]=i;//初始化pre数组
    }
    used[s]=true;
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(i=0; i<=n+1; i++)
        {
            if(d[i]>d[now]+cost[now][i])
            {
                d[i]=d[now]+cost[now][i];
                if(used[i]==0)
                {
                    if(now!=0)pre[i]=pre[now];
                    used[i]==true;
                    q.push(i);
                }
            }
            if(d[i]==d[now]+cost[now][i])
            {
                if(now!=0)pre[i]=min(pre[i],pre[now]);
            }
        }
    }
}
int main()
{
    int i,j,a,b,c;
    int we;
    scanf("%d",&we);
    while(we--)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m) break;
        for(i=0; i<=n+1; ++i)
        {
            for(j=0; j<=i; j++)
            {
                if(i==j)  cost[i][j]=0;
                else  cost[i][j]=cost[j][i]=MAX;
            }
        }
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            cost[a][b]=c;
        }
        spfa(0);
        if(d[n+1]<MAX)
        {
            if(pre[n+1]==n+1)printf("0\n");
            else printf("%d\n",pre[n+1]);
        }
        else printf("-1\n");
    }
    return 0;
}
