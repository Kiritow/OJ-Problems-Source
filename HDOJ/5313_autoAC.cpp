#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int x,y;
vector<int>v[10004];
set<int>s[2];
int dfs(int p,int b)
{
    s[b].insert(p);
    int l=v[p].size();
    for(int i=0;i<l;i++)
        if(!s[!b].count(v[p][i]))
            dfs(v[p][i],!b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x,&y);
        for(int i=0;i<y;i++)
        {
            int tx,ty;
            scanf("%d%d",&tx,&ty);
            v[tx].push_back(ty);
            v[ty].push_back(tx);
        }
        s[0].clear();
        s[1].clear();
        for(int i=0;i<x;i++)
            if(v[i].size())
        {
            dfs(i,0);
            break;
        }
        long long  line;
        long long  mmax=(s[0].size(),s[1].size());
        if(mmax<(x/2))
        {
            line=(x/2)*(x-x/2)-y;
        }
        else
            line=(x-mmax)*(x-(x-mmax))-y;
        printf("%I64d\n",line);
        for(int i=0;i<=x;i++)
            v[i].clear();
    }
    return 0;
}
