#include <iostream>
#include <string.h>
using namespace std;
#define  N 3
#define ll __int64
#define MOD 200907
struct Mat 
{
    ll martix[N][N];
};
Mat res,q,tp,tp1,tp2,tp3;
void er_fun(int x)   
{   
    int i,j,k,flag=0;   
    tp1=q;   
    tp=res;   
    while (x)   
    {   
        if(x&1)   
        {   
            flag=1;   
            memset(tp2.martix,0,sizeof(tp2.martix));   
            for (i=0;i<N;i++)   
            {   
                for (j=0;j<N;j++)   
                {   
                    for(k=0;k<N;k++)   
                    {   
                        tp2.martix[i][j]+=(tp.martix[i][k]*tp1.martix[k][j])%MOD;   
                        tp2.martix[i][j]%=MOD;   
                    }   
                }   
            }   
        }   
        memset(tp3.martix,0,sizeof(tp3.martix));   
        for (i=0;i<N;i++)   
        {   
            for (j=0;j<N;j++)   
            {   
                for(k=0;k<N;k++)   
                {   
                    tp3.martix[i][j]+=(tp1.martix[i][k]*tp1.martix[k][j])%MOD;   
                }   
            }   
        }   
        if(flag)   
            tp=tp2;   
        tp1=tp3;   
        x>>=1;   
    }   
}
int main()
{
    int i,j;
    ll n,sum;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            res.martix[i][j]=(i==j);
        }
    }
    q.martix[0][0]=q.martix[1][0]=q.martix[0][2]=q.martix[2][2]=1;
    q.martix[1][1]=q.martix[1][2]=q.martix[2][0]=q.martix[2][1]=0;
    q.martix[0][1]=2;
    while (scanf("%I64d",&n),n)
    {
        if(n==1 || n==2)
        {
            printf("%I64d\n",n);
            continue;
        }
        er_fun(n-2);
        sum=(tp.martix[0][0]*2+tp.martix[0][1]+tp.martix[0][2])%MOD;
        printf("%I64d\n",sum);
    }
    return 0;
}
