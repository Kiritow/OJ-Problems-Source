#include<cstdio>
#include<cstring>
using namespace std;
int num[2][100000];
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF&&(n||m||k))
    {
        memset(num,0,sizeof(num));
        for(int i=1; i<=m; i++)
            num[1][i]=1;
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=i*m; j++)
                for(int l=1; l<=m; l++)
                    num[i%2][j+l]+=num[(i-1)%2][j];
            memset(num[(i-1)%2],0,sizeof(num[(i-1)%2]));
        }
        double res=0.0;
        int i,j;
        for(i=1; i<=k+1; i++)
            res+=num[n%2][i];
        for(j=2;i<=n*m; i++,j++)
            res+=num[n%2][i]*j;
        int count=1;
        for(int i=1;i<=n;i++)
            count*=m;
        res/=count;
        printf("%.8lf\n",res);
    }
    return 0;
}
