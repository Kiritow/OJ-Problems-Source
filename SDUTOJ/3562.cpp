#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

/** SPFA 单源最短路径算法 不支持负环*/
#define MAXN 1005
int d[MAXN];/// distance [ From S to ... ]
int mp[MAXN][MAXN]; /// mp[i][j] i<--> j is connected.
int n;/// n is the number of max Point .

int path[MAXN];

void spfa(int StartPoint) /// d[i] is the min distance from StartPoint to i ( Both >=1 )
{
    for(int i=0; i<=n; i++)
    {
        if(mp[0][i]!=INF)path[i]=i;//Path Init
        d[i]=INF;
    }
    queue<int> bus;
    bus.push(StartPoint);
    d[StartPoint]=0;
    while(!bus.empty())
    {
        int c=bus.front();
        bus.pop();
        //v[c]=0;
        for(int i=0; i<=n; i++)
        {
            /// Here : if your mp[i][j] use INF as infinite, then use mp[c][i]!=INF.
            /// Or you may use mp[i][j]!=-1 && d[i] > d[c] + mp[c][i]
            if( d[i]>d[c]+mp[c][i] )
            {
                d[i]=d[c]+mp[c][i];
                //path[i]=min(path[i],path[c]);
                if(i)
                {
                    if(c) path[i]=path[c];
                    bus.push(i);
                }
            }

            if(d[i]==d[c]+mp[c][i])
            {
                if(c)path[i]=min(path[i],path[c]);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%d%d",&n,&m);
        if(!n&&!m) break;
        n=n+1;

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(i==j) mp[i][j]=0;
                else mp[i][j]=mp[j][i]=INF;
            }
        }
        int tu,tv,tw;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&tu,&tv,&tw);
            mp[tu][tv]=tw;
        }



        spfa(0);

        if(d[n]<INF)
        {
            if(path[n]==n)printf("0\n");
            else printf("%d\n",path[n]);
        }
        else printf("-1\n");
    }
    return 0;
}
