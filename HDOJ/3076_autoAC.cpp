#include<iostream>
using namespace std;
#define N 2005
double a[7],b[7],dp[N][N];
double pa,pb,ptie;
int hp1,hp2;
int main()
{
    int i,j;
    while(scanf("%d%d",&hp1,&hp2)!=EOF)
    {
        swap(hp1,hp2);
        for(i=1;i<=6;i++)
            scanf("%lf",&a[i]);
        for(i=1;i<=6;i++)
            scanf("%lf",&b[i]);
        pa=pb=0;
        for(i=2;i<=6;i++)
        {
            for(j=1;j<=i-1;j++)
            {
                pa+=a[i]*b[j];
                pb+=a[j]*b[i];
            }
        }
        ptie=1-pa-pb;
        if(ptie!=1)
        {
            pa=pa/(1-ptie);
            pb=pb/(1-ptie);
        }
        //dp[i][j]->probability of A won i,B won j
        dp[0][0]=1;
        for(i=0;i<hp2;i++)
        {
            for(j=0;j<=hp1;j++)
            {
                if(i||j)
                {
                    dp[i][j]=0;
                    if(i)
                        dp[i][j]+=dp[i-1][j]*pa;
                    if(j)
                        dp[i][j]+=dp[i][j-1]*pb;
                }
            }
        }
        double ans=0;
        for(i=0;i<hp1;i++)
            ans+=dp[hp2-1][i]*pa;
        if(ans>1)
            ans=1;
        printf("%.6lf\n",ans);
    }
}
