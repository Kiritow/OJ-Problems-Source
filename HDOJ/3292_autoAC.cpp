#include <cstdio>
#include <cmath>
using namespace std;
#define mod 8191
const int maxn=5;
typedef struct
{
    int m[maxn][maxn];
}Matrix;
int N,x,y;
void search()
{
    y=1;
    while(1){
        x=sqrt(N*y*y+1.0);
        if(x*x-N*y*y==1) break;
        y++;
    }
}
Matrix per,d;
void init()
{
    d.m[0][0]=x%mod;
    d.m[0][1]=y*N%mod;
    d.m[1][0]=y%mod;
    d.m[1][1]=x%mod;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            per.m[i][j]= (i==j);
}
Matrix Multi(Matrix a,Matrix b)
{
    Matrix c;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
        c.m[i][j]=0;
            for(int k=0;k<2;k++)
                c.m[i][j]+=(a.m[i][k]*b.m[k][j])%mod;
            c.m[i][j]%=mod;
    }
    return c;
}
Matrix power(Matrix a,int k)
{
    Matrix r=per;
    while(k)
    {
        if(k&1) r=Multi(r,a);
        a=Multi(a,a);
        k>>=1;
    }
    return r;
}
int main()
{
    int k;
    while(~scanf("%d%d",&N,&k))
    {
        int tmp=sqrt(N+0.0);
        if(tmp*tmp==N){
            printf("No answers can meet such conditions\n");
            continue;
        }
        search();
        init();
        d=power(d,k-1);
        x=(d.m[0][0]*x%mod+d.m[0][1]*y%mod)%mod;
        printf("%d\n",x);
    }
    return 0;
}
