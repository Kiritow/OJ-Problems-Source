#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define inf 0x3f3f3f3f
#pragma comment(linker, "/STACK:16777216")
#define eps 1e-6
#define ll long long
using namespace std;
const int maxn=505;
int n,in[maxn],vis[maxn];
char s[maxn][maxn];
int main()
{
    int i,j;
    while(~scanf("%d",&n)&&n)
    {
        memset(in,0,sizeof in);
        for(i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
            for(j=1;j<=n;j++)
                if(s[i][j]=='1')
                    in[j]++;
        }
        vector<int> ans;
        memset(vis,0,sizeof vis);
        int maxin,p,flag=1;
        while(flag)
        {
            flag=0,maxin=-1,p=0;
            for(i=1;i<=n;i++)
            {
                if(!vis[i]&&maxin<in[i])
                {
                    flag=1;
                    maxin=in[i];
                    p=i;
                }
            }
            if(flag)
            {
                vis[p]=1;
                ans.push_back(p);
                for(i=1;i<=n;i++)
                {
                    if(i==p) continue;
                    if(s[p][i]=='1') in[i]--;
                }
            }
        }
        printf("%d",ans[ans.size()-1]);
        for(i=ans.size()-2;i>=0;i--)
            printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}
