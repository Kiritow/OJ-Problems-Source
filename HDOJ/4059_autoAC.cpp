#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
#define LL __int64
#define MOD 1000000007
#define maxn 2000007
LL yu[maxn];
struct matrix
{
    LL mat[7][7];
    matrix()
    {
        memset(mat,0,sizeof(mat));
    }
    friend matrix operator *(matrix A,matrix B)
    {
        int i,j,k;
        matrix C;
        for(i=1; i<=6; i++)
        {
            for(j=1; j<=6; j++)
            {
                for(k=1; k<=6; k++)
                {
                    C.mat[i][j]=(C.mat[i][j]+(A.mat[i][k]*B.mat[k][j])%MOD)%MOD;
                }
                C.mat[i][j]=C.mat[i][j]%MOD;
            }
        }
        return C;
    }
} ONE,AA[30];
matrix powmul(matrix A,LL k)
{
    matrix B;
    for(int i=1; i<=6; i++)B.mat[i][i]=1;
    int l=1;
    while(k)
    {
        if(k&1)B=B*AA[l];
        l++;
        k>>=1;
    }
    return B;
}
vector<int>vec;
void init()
{
    int i,j;
    ONE.mat[1][1]=1;ONE.mat[1][2]=1;ONE.mat[1][3]=4;
    ONE.mat[1][4]=6;ONE.mat[1][5]=4;ONE.mat[1][6]=1;
    ONE.mat[2][1]=0;ONE.mat[2][2]=1;ONE.mat[2][3]=4;
    ONE.mat[2][4]=6;ONE.mat[2][5]=4;ONE.mat[2][6]=1;
    ONE.mat[3][1]=0;ONE.mat[3][2]=0;ONE.mat[3][3]=1;
    ONE.mat[3][4]=3;ONE.mat[3][5]=3;ONE.mat[3][6]=1;
    ONE.mat[4][4]=1;ONE.mat[4][5]=2;ONE.mat[4][6]=1;
    ONE.mat[5][4]=0;ONE.mat[5][5]=1;ONE.mat[5][6]=1;
    ONE.mat[6][6]=1;
    yu[0]=0;
    yu[1]=1;
    LL x;
    for(i=2;i<maxn;i++)
    {
        x=i%MOD;
        x=x*i;
        x=x%MOD;
        x=x*i;
        x=x%MOD;
        x=x*i;
        x=x%MOD;
        yu[i]=yu[i-1]+x;
        yu[i]=yu[i]%MOD;
    }
    AA[1]=ONE;
    for(i=2;i<30;i++)AA[i]=AA[i-1]*AA[i-1];
}
matrix A;
LL kan(LL x)
{
    if(x<maxn)return yu[x];
    matrix OP;
    for(int i=1;i<=6;i++)OP.mat[i][1]=1;
    A=powmul(ONE,x-1);
    OP=A*OP;
    return OP.mat[1][1];
}
LL pan(LL n,LL x)
{
    if(x>=n)return 0;
    LL p=1;
    LL ns=4;
    while(ns--)
    {
        p=p*x;
        p=p%MOD;
    }
    ns=(n-1)/x;
    p=p*kan(ns);
    p=p%MOD;
    return p;
}
void dos(LL n)
{
    LL p=1;
    LL ans=0;
    int i,j,leap;
    LL m=n;
    vec.clear();
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            vec.push_back(i);
        }
        while(n%i==0)n=n/i;
    }
    if(n!=1)vec.push_back(n);
    n=m;
    int t=1<<(vec.size());
    for(i=1;i<t;i++)
    {
        leap=0;
        p=1;
        for(j=0;j<vec.size();j++)
        {
            if(i&(1<<j))
            {
                leap++;
                p=p*vec[j];
            }
        }
        leap=leap%2;
        if(leap)ans+=pan(n,p);
        else ans-=pan(n,p);
        ans=(ans+MOD)%MOD;
    }
    ans=kan(n-1)-ans;
    ans=(ans+MOD)%MOD;
    printf("%I64d\n",ans);
}
int main()
{
    int T;
    LL n;
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        if(n==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        dos(n);
    }
    return 0;
}
