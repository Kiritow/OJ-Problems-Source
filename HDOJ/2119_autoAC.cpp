#include <stdio.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define mod 1000000007
#define inf 0x7f7f7f7f
int vis[505];
int pre[505];
int mat[505][505];
int n,m,ans;
int find(int x)
{
    int i;
    for(i=1;i<=m;i++)
    {
        if(!vis[i]&&mat[x][i])
        {
            vis[i]=1;
            if(pre[i]==-1 ||find(pre[i]))
            {
                pre[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int init()
{
     int i;
     ans=0;
     memset(pre,-1,sizeof(pre));
     for(i=1;i<=n;i++)
     {
           memset(vis,0,sizeof(vis));
           if(find(i))
            ans++;
     }
     return ans;
}
int main()
{
    int i,j;
     while(cin>>n,n)
     {
         cin>>m;
         for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            cin>>mat[i][j];
         int ans1=init();
         cout<<ans1<<endl;
     }
     return 0;
}
