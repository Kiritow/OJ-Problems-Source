#include <iostream>   
using namespace std;
#define M 1005
#define INF 1000000000
int n,f[M][M],sum[M][M],s[M][M];
struct POINTS
{
    int x,y;
}stone[M];
int dis(POINTS a,POINTS b,POINTS c,POINTS d)//calculate from a to d; b,c is division point
{
    return abs(c.x-a.x)+abs(d.y-b.y);
}
int main()
{
    int i,j,k,t;
    while(cin>>n)
    {
        for(i=1;i<=n;i++)
            scanf("%d%d",&stone[i].x,&stone[i].y);
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++)
        {
            s[i][i]=i;
        }
        for(int len=2;len<=n;len++)
        {
            for(i=1;i<=n-len+1;i++)
            {
                j=i+len-1;
                f[i][j]=INF;
                for(k=s[i][j-1];k<=s[i+1][j];k++)
                {
                    if(f[i][j]>f[i][k]+f[k+1][j]+dis(stone[i],stone[k],stone[k+1],stone[j]))
                    {
                        f[i][j]=f[i][k]+f[k+1][j]+dis(stone[i],stone[k],stone[k+1],stone[j]);
                        s[i][j]=k;
                    }
                }
            }
        }
        printf("%d\n",f[1][n]);
    }
    return 0;
}
