#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 128

typedef int ARRAY[MAXN][MAXN];

ARRAY pool;

#define INF 0x3f3f3f3f
#define NINF -INF-1
/*
int MaxSum(int N,int* a)
{
    int sum=0;
    int tmp=0;
    for(int i=0;i<N;i++)
    {
        if(tmp>0)
        {
            tmp+=a[i];
        }
        else
        {
            tmp=a[i];
        }
        if(tmp>sum)
        {
            sum=tmp;
        }
    }
    return sum;
}
//*/
int MaxSum(int n,int *a)
{
    int sum=NINF,b=0;
    for(int i=0; i<n; i++)
    {
        if(b>0)
        {
            b+=a[i];
        }
        else
        {
            b=a[i];
        }
        if(b>sum)
        {
            sum = b;
        }
    }
    return sum;
}
int MaxSumRect(int m,int n,ARRAY& a)
{
    int sum = NINF;
    int* b = new int[n+1];
    for(int i=0; i<m; i++)//枚举行
    {
        memset(b,0,sizeof(int)*(n+1));

        for(int j=i; j<m; j++) //枚举初始行i,结束行j
        {
            for(int k=0; k<n; k++)
            {
                b[k] += a[j][k];//b[k]为纵向列之和
            }
            int max = MaxSum(n,b);
            if(max>sum)
            {
                sum = max;
            }

        }
    }
    delete[] b;
    return sum;
}

int MaxSumSquare(int N,ARRAY& a)
{
    return MaxSumRect(N,N,a);
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(pool,0,sizeof(pool));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&pool[i][j]);
            }
        }
        int ans=MaxSumSquare(n,pool);
        printf("%d\n",ans);
    }
    return 0;
}
