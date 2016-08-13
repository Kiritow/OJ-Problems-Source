#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;
const int MAXN=110;
const double MAXNUM=1e8;
int n,step[MAXN];
double x[MAXN],y[MAXN];
double d,dis[MAXN],map[MAXN][MAXN];
bool mark[MAXN];
double dist(int i,int j)
{
    double X=(x[i]-x[j])*(x[i]-x[j]);
    double Y=(y[i]-y[j])*(y[i]-y[j]);
    return sqrt(X+Y);
}
void SPFA()
{
    int i;
    queue<int> q;
    for(i=1;i<=n+1;i++)
    {
        dis[i]=MAXNUM;
        mark[i]=0;
    }
    step[0]=0;
    dis[0]=0.0;
    q.push(0);
    mark[0]=1;
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        mark[s]=0;
        for(i=1;i<=n+1;i++)
        {
            if(map[s][i]<=d&&map[s][i]+dis[s]<dis[i])
            {
                dis[i]=map[s][i]+dis[s];
                step[i]=step[s]+1;
                if(!mark[i])
                q.push(i);
            }
            else if(map[s][i]<=d&&dis[i]==map[s][i]+dis[s])
            {
                if(step[i]>step[s]+1)
                {
                    step[i]=step[s]+1;
                    if(!mark[i])
                    q.push(i);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%lf",&n,&d)==2)
    {
        int i,j;
        x[0]=y[0]=0;
        for(i=1;i<=n;i++)
            scanf("%lf%lf",x+i,y+i);
        if(d>=42.50)
        {
            puts("42.50 1");
            continue;
        }
        for(i=1;i<=n;i++)
        {
            map[i][i]=MAXNUM;
            for(j=i+1;j<=n;j++)
                map[i][j]=map[j][i]=dist(i,j);
        }
        for(i=1;i<=n;i++)
        {
            map[i][0]=0.0;
            map[0][i]=sqrt(x[i]*x[i]+y[i]*y[i])-7.5;
        }
        for(i=1;i<=n;i++)
        {
            map[n+1][i]=0.0;
            if(50.00-fabs(x[i])>50.00-fabs(y[i]))
                map[i][n+1]=50.00-fabs(y[i]);
            else map[i][n+1]=50.00-fabs(x[i]);
        }
        map[0][n+1]=MAXNUM;
        SPFA();
        if(dis[n+1]==MAXNUM)
            puts("can't be saved");
        else printf("%.2lf %d\n",dis[n+1],step[n+1]);
    }
    return 0;
}
