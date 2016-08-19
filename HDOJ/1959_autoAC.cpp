#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef __int64 lld;
const int MAX=51;
const int INF=1000000001;
const double PI=acos(-1.0);
const double EPS=1.0e-8;
const int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool used[MAX][MAX];
struct Point
{
    int x,y;
}p[MAX];
bool ok(int x,int y,int len,int n)
{
    int i,tx,ty;
    for(i=0;i<n;i++)
    {
        tx=x-p[i].x;
        ty=y-p[i].y;
        if(tx*tx+ty*ty>len)return false;
    }
    return true;
}
int main()
{
    int n,m;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(used,false,sizeof(used));
        int i,j;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            used[p[i].x][p[i].y]=true;
        }
        int ax=-1,ay=-1;
        for(i=0;i<=n&&ax==-1;i++)
        {
            for(j=0;j<=n&&ax==-1;j++)
            {
                if(used[i][j])continue;
                int len=i;
                if(n-i<len)len=n-i;
                if(j<len)len=j;
                if(n-j<len)len=n-j;
                if(ok(i,j,len*len,m))
                {
                    ax=i;
                    ay=j;
                }
            }
        }
        if(ax!=-1)
        {
            printf("%d %d\n",ax,ay);
        }
        else puts("poodle");
    }
    return 0;
}
