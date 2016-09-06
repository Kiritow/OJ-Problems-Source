#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 100000
using namespace std;
__int64 f[405][405][2],MIN,sum1,sum2;
__int64 getsMIN(__int64 x,__int64 y)
{
    x=(x<0)?-x:x;
    y=(y<0)?-y:y;
    __int64 t=x%y;
    while(t!=0)
    {
        x=y;
        y=t;
        t=x%y;
    }
    return y;
}
int main()
{
    f[0][1][1]=1;f[0][1][2]=1;
    f[1][2][1]=1;f[1][2][2]=2;
    f[1][1][1]=1;f[1][1][2]=2;
    int i,j,P,T,m,k,ans;
    for(i=2;i<=400;i++)
    {
        for(j=i+1,sum1=0,sum2=1;j>1;j--)
        {
            f[i][j][1] = i*f[i-1][j-1][1];
            f[i][j][2] = j*f[i-1][j-1][2];
            MIN=getsMIN(f[i][j][1],f[i][j][2]);
            f[i][j][1] /= MIN;
            f[i][j][2] /= MIN;
            if(sum2%f[i][j][2])
            {
                sum1 = sum1*f[i][j][2]+f[i][j][1]*sum2;
                sum2 *= f[i][j][2];
            }
            else sum1 = sum1 + f[i][j][1]*(sum2/f[i][j][2]);
            MIN=getsMIN(sum1,sum2);
            sum1 /= MIN;
            sum2 /= MIN;
        }
        f[i][1][2] = sum2;
        f[i][1][1] = sum2-sum1;
        MIN=getsMIN(f[i][1][1],f[i][1][2]);
            f[i][1][1] /= MIN;
            f[i][1][2] /= MIN;
    }
    scanf("%d",&P);
    while(P--)
    {
        scanf("%d %d %d",&T,&m,&k);
        if(!f[m][k][1])
            printf("%d 0\n",T);
        else
        {
            if(f[m][k][2]==1)
                printf("%d %I64d\n",T,f[m][k][1]);
            else printf("%d %I64d/%I64d\n",T,f[m][k][1],f[m][k][2]);
        }
    }
    return 0;
}
