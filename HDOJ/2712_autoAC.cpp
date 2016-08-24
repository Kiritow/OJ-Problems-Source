#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define N 10010
#define clr(a) (memset(a,0,sizeof(a)))
using namespace std;
int n,k,x;
int vis[N];
int main()
{
    while(scanf("%d%d",&n,&k)>0)
    {
        memset(vis,0,sizeof(vis));
        int num=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(!vis[x])
            {
                vis[x]=1;num++;
            }
            if(num==k)
            {
                memset(vis,0,sizeof(vis));
                num=0;ans++;
            }
        }
        printf("%d\n",ans+1);
    }
}
