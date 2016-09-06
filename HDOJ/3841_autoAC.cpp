#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1010;
int s[maxn*2][maxn*2];
int get(int x1,int y1,int x2,int y2)
{
    return s[x2][y2]+s[x1-1][y1-1]-s[x1-1][y2]-s[x2][y1-1];
}
int N;
inline void gao(int &n)
{
        if(n<1)
            n=1;
        if(n>N)
            n=N;
}
int main()
{
    int dx,dy,n,q,i,j,k;
    int u,v;
    int ii=0;
    while(scanf("%d%d%d%d",&dx,&dy,&n,&q),dx+dy)
    {
        N=dx+dy;
        for(i=1;i<=dx+dy;i++)
            for(j=1;j<=dx+dy;j++)
                s[i][j]=0;
        while(n--)
        {
            scanf("%d%d",&u,&v);
            s[u+v][v-u+dx]=1;
        }
        for(i=1;i<=dx+dy;i++)
            for(j=1;j<=dx+dy;j++)
                s[i][j]+=s[i][j-1];
        for(i=1;i<=dx+dy;i++)
            for(j=1;j<=dx+dy;j++)
                s[i][j]+=s[i-1][j];
printf("Case %d:\n",++ii);
        while(q--)
        {
            int m;
            scanf("%d",&m);
            int ans=0,x,y;
            int ansx=1,ansy=1;
            for(j=1;j<=dy;j++)
                for(i=1;i<=dx;i++)
                {
                    u=i,v=j-m;
                    x=(u+v),y=(v-u+dx);
                    u=x+m*2,v=y+m*2;
                    gao(x),gao(y);
                    gao(u),gao(v);
                    u=get(x,y,u,v);
                    if(u>ans)
                        ans=u,ansx=i,ansy=j;
                }
            printf("%d (%d,%d)\n",ans,ansx,ansy);
        }
    }
}
