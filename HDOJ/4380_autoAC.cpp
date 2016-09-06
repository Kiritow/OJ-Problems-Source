#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=105;
const int M=1005;
struct Point
{
    LL x,y;
}P1[N],P2[M];
int f[N][N][N];
int n,m;
LL cross(Point a,Point b,Point s)
{
    LL x1=a.x-s.x,y1=a.y-s.y;
    LL x2=b.x-s.x,y2=b.y-s.y;
    return x1*y2-x2*y1;
}
int dis2(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*((a.y-b.y));
}
int cmp(Point a,Point b)
{
    if(cross(a,b,P1[0])>0)
        return 1;
    else return 0;
}
void init()
{
    int i,t;
    for(t=0,i=0;i<n;i++){
        if((P1[i].y-P1[t].y)<0 || (P1[i].y-P1[t].y==0 && P1[i].x-P1[t].x<0))
        t=i;
    }
    swap(P1[0],P1[t]);
    sort(P1+1,P1+n,cmp);
}
int cal(int x,int y,int z)
{
    int i;
    int sum=0;
    LL a,b,c;
    for (i=0;i<m;i++)
    {
        a=cross(P1[y],P2[i],P1[x]);
        b=cross(P1[z],P2[i],P1[y]);
        c=cross(P1[x],P2[i],P1[z]);
        if ((a>=0 && b>=0 && c>=0) || (a<=0 && b<=0 && c<=0))
        {
            sum++;
        }
    }
    return sum;
}
int main()
{
    int i,j,k;
    int CA=0;
    int ans=0;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        ans=0;
        memset(P1,0,sizeof(P1));
        memset(P2,0,sizeof(P2));
        memset(f,0,sizeof(f));
        for (i=0;i<n;i++)
            scanf("%I64d%I64d",&P1[i].x,&P1[i].y);
        for (i=0;i<m;i++)
            scanf("%I64d%I64d",&P2[i].x,&P2[i].y);
        init();
        for (i=2;i<n;i++){
            for (j=1;j<i;j++){
                f[0][j][i]=cal(0,j,i);
                if (f[0][j][i]%2!=0) ans++;
            }
        }
        for (i=2;i<n;i++)
            for (j=1;j<i;j++)
                for (k=j+1;k<i;k++){
                    if (cross(P1[k],P1[i],P1[j])>0)
                        f[j][k][i]=f[0][j][k]+f[0][k][i]-f[0][j][i];
                    else
                        f[j][k][i]=f[0][j][i]-(f[0][j][k]+f[0][k][j]);
                    if (f[j][k][i]%2!=0) ans++;
                }
        printf("Case %d: ",++CA);
        printf("%d\n",ans);
    }
}
