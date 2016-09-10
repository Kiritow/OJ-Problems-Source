#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<stack>
#define inf 0x3f3f3f3f
#define ll long long
#define mod 1000000007
using namespace std;
double ans;
double visit[1005][1005];
double dfs(int ji,int ou)
{
    if(ji+ou<=0)return 0;
    if(visit[ji][ou])return visit[ji][ou];
    if(ji%2==1)
        return visit[ji][ou]=dfs(ji-1,ou);
    if(ji)
    {
        if(ou)
            return visit[ji][ou]=(dfs(ji-1,ou)*ji+dfs(ji,ou-1)*ou)/(ji+ou)+ji+ou;
        else
            return visit[ji][ou]=dfs(ji-1,ou)+ji+ou;
    }
    return visit[ji][ou]=dfs(ji,ou-1)+ji+ou;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(visit,0,sizeof(visit));
        ans=0;
        int n;
        scanf("%d",&n);
        int ji=0,ou=0;
        for(int i=0; i<n; i++)
        {
            int a;
            scanf("%d",&a);
            if(a%2)ji++;
            else ou++;
        }
        ans=dfs(ji,ou);
        printf("%d\n",(int)(3*ans+0.5));
    }
}
