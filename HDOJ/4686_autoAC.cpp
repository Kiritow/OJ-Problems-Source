#include<stdio.h>
#include<string.h>
#define LL long long
#define M 1000000007
struct Matrix
{
    LL a[6][6];
}origin,res,tmp,A,ans;
int n;
Matrix mul(Matrix x,Matrix y)
{
    int i,j,k;
    memset(tmp.a,0,sizeof(tmp.a));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            {
                tmp.a[i][j]+=(x.a[i][k]*y.a[k][j])%M;
                tmp.a[i][j]%=M;
            }
    return tmp;
}
void quickpow(LL k)
{
    int i;
    memset(res.a,0,sizeof(res.a));
    for(i=1;i<=n;i++)
        res.a[i][i]=1;
    while(k)
    {
        if(k&1)
            res=mul(res,A);
        A=mul(A,A);
        k>>=1;
    }
}
int main()
{
    LL N,a0,ax,ay,b0,bx,by;
    LL f1,a1,b1,s0;
    while(scanf("%lld %lld %lld %lld %lld %lld %lld",&N,&a0,&ax,&ay,&b0,&bx,&by)!=EOF)
    {
        if(N==0)
        {
            printf("0\n");
            continue;
        }
        a1=(a0*ax+ay)%M;
        b1=(b0*bx+by)%M;
        f1=(a1*b1)%M;
        s0=(a0*b0)%M;
        n=5;
        memset(origin.a,0,sizeof(origin.a));
        origin.a[1][1]=f1;
        origin.a[1][2]=a1;
        origin.a[1][3]=b1;
        origin.a[1][4]=1;
        origin.a[1][5]=s0;
        memset(A.a,0,sizeof(A.a));
        A.a[1][1]=(ax*bx)%M;
        A.a[1][5]=1;
        A.a[2][1]=(ax*by)%M;
        A.a[2][2]=ax%M;
        A.a[3][1]=(ay*bx)%M;
        A.a[3][3]=bx%M;
        A.a[4][1]=(ay*by)%M;
        A.a[4][2]=ay%M;
        A.a[4][3]=by%M;
        A.a[4][4]=1;
        A.a[5][5]=1;
        quickpow(N-1);
        ans=mul(origin,res);
        printf("%lld\n",ans.a[1][5]);
    }
    return 0;
}
