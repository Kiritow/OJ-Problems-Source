#include<cstdio>
#include<cstring>
using namespace std;
#define inf (-((1<<30)-1))
#define max(a,b) ((a)>(b)?(a):(b))
char opt[105][1005];
int value[105][1005];
int dp[1005];
int n,m,k;
void dfs(int x,int y,int v,int ki,int money,int pre)
{
    if(x==1&&y!=pre)
    {
        dp[y]=max(dp[y],dp[pre]+money);
        return;
    }
    if(ki>=k) return;
    if(y>=m) return;
    money+=(opt[x][y]=='$'?value[x][y]:0);
    int vi=(x!=1?(opt[x][y]!='$'?value[x][y]:0):0);
    for(int i=-1;i<=1;++i)
    {
        int pos=x+v+vi+i;
        if(pos<=1)
            dfs(1,y+1,0,0,money,pre);
        else
        {
            if(pos>n) pos=n;
            dfs(pos,y+1,v+vi+i,ki+1,money,pre);
        }
    }
}
int main()
{
    char c;
    for(; ~scanf("%d%d%d",&n,&m,&k);)
    {
        if(n+m+k==0) break;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                for(;c=getchar();)
                    if(c=='v'||c=='$') break;
                opt[i][j]=c;
                scanf("%d",&value[i][j]);
            }
        }
        dp[1]=0;
        for(int i=2;i<=m;++i) dp[i]=inf;
        for(int i=1;i<m;++i)
           if(dp[i]!=inf)
               dfs(1,i,0,0,0,i);
        printf("%d\n",dp[m]+(opt[1][m]=='$'?value[1][m]:0));
    }
    return 0;
}
