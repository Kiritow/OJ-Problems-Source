#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
int dp[1005][105][2];
int times[105][1005];
int alltime[105][1005];
struct node
{
    int x,t;
    bool operator < (const node &a) const
    {
        return x<a.x;
    }
} temp;
set<node> line[105];
int check(int x,int t)
{
    int sumt=0;
    for(set<node>::iterator it=line[x].begin(); it!=line[x].end(); ++it)
        sumt+=times[it->x][t];
    return sumt+times[x][t];
}
int main()
{
    int n,m,t,p,q,d,x,a,k;
    for(; ~scanf("%d%d%d",&n,&m,&t);)
    {
        int maxx[2];
        maxx[0]=maxx[1]=0;
        memset(dp,-1,sizeof(dp));
        memset(times,0,sizeof(times));
        for(int i=0; i<=n; ++i) line[i].clear();
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d%d",&p,&q,&d);
            temp.t=d;
            temp.x=q;
            line[p].insert(temp);
            temp.x=p;
            line[q].insert(temp);
        }
        for(;scanf("%d%d%d",&x,&a,&k);)
        {
            if(x+a+k==0)  break;
            times[a][x]+=k;
        }
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=t; ++j)
                alltime[i][j]=check(i,j);
        for(int i=1; i<=n; ++i)
        {
            dp[1][i][0]=times[i][1];
            dp[1][i][1]=alltime[i][1];
        }
        for(int i=1; i<=t; ++i)
            for(int j=1; j<=n; ++j)
            {
                if(dp[i][j][0]!=-1)
                {
                    for(set<node>::iterator it=line[j].begin(); it!=line[j].end(); ++it)
                    {
                        if(i+it->t<=t)
                        {
                            dp[i+it->t][it->x][0]=max(dp[i+it->t][it->x][0],dp[i][j][0]+times[it->x][i+it->t]);
                            dp[i+it->t][it->x][1]=max(dp[i+it->t][it->x][1],dp[i][j][0]+alltime[it->x][i+it->t]);
                            dp[i+it->t][it->x][1]=max(dp[i+it->t][it->x][1],dp[i][j][1]+times[it->x][i+it->t]);
                            maxx[0]=max(maxx[0],dp[i+it->t][it->x][0]);
                            maxx[1]=max(maxx[1],dp[i+it->t][it->x][1]);
                        }
                    }
                    if(i+1<=t)
                    {
                        dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j][0]+times[j][i+1]);
                        dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][0]+alltime[j][i+1]);
                        dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j][1]+times[j][i+1]);
                        maxx[0]=max(maxx[0],dp[i+1][j][0]);
                        maxx[1]=max(maxx[1],dp[i+1][j][1]);
                    }
                }
            }
        printf("%d %d\n",maxx[1],maxx[0]);
    }
    return 0;
}
