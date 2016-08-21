#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<math.h>
#include<vector>
#include<deque>
#include<list>
#define INF 0x7fffffff
#define inf 0x3f3f3f3f
#define maxn 130
using namespace std;
bool map[maxn][maxn];
int yes[maxn],no[maxn],mark[maxn];
int n,m,a,b;
bool check(int x)
{
    if(yes[x]>=a&&no[x]>=b)
        return 1;
    for(int i=0; i<n; i++)
    {
        if(map[x][i])
            yes[i]--;
        else
            no[i]--;
    }
    return 0;
}
int main()
{
    int x,y;
    int ww=1;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)&&(n||m||a||b))
    {
        memset(map,0,sizeof(map));
        memset(yes,0,sizeof(yes));
        memset(no,0,sizeof(no));
        memset(mark,0,sizeof(mark));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            yes[x]++;
            yes[y]++;
            map[x][y]=map[y][x]=1;
        }
        for(int i=0; i<n; i++)
            no[i]=n-yes[i]-1;
        bool flag=1;
        while(flag)
        {
            flag=0;
            for(int i=0; i<n; i++)
            {
                if(mark[i])
                continue;
                if(!check(i))
                {
                    mark[i]=1;
                    flag=1;
                }
            }
        }
        int c=0;
        for(int i=0; i<n; i++)
        {
            if(!mark[i])
                c++;
        }
        printf("Case #%d: %d\n",ww++,c);
    }
    return 0;
}
