#include<stdio.h>
#include<string.h>
#include<algorithm>
using std::sort;
#define inf -2100000000
#define MAXV1 501
#define MAXV2 51
#define MAXN 301
struct T
{
    int p,v,f;
    bool operator < (const T a) const
    {
        return f>a.f;
    }
} gift[MAXN];
int res[MAXV1][MAXV2][2];
inline int max (int a,int b,int c=0,int d=0)
{
    return (a>b?a:b)>(c>d?c:d)?(a>b?a:b):(c>d?c:d);
}
int main()
{
    int v1,v2,n,i,j,k,m,ts;
    int cas=1;
    while (scanf("%d%d%d",&v1,&v2,&n))
    {
        if (v1==0&&v2==0&&n==0) break;
        memset(res,0,sizeof(res));
        ts=0;
        for (i=1; i<=n; ++i)
        {
            scanf("%d%d%d",&gift[i].p,&gift[i].v,&gift[i].f);
            if (gift[i].f==1) ts+=gift[i].v;
        }
        sort(gift+1,gift+n+1);
        for (k=1; k<=n; ++k)
        {
            if (gift[k].f==0) break;
            for (i=v1; i>=0; --i)
            {
                for (j=v2; j>=0; --j)
                {
                    if (i>=gift[k].p&&j>=gift[k].p)
                    {
                        res[i][j][1]=max(res[i][j][0]+gift[k].v,res[i][j-gift[k].p][1]+gift[k].v,res[i-gift[k].p][j][1]+gift[k].v);
                        res[i][j][0]=max(res[i][j-gift[k].p][0]+gift[k].v,res[i-gift[k].p][j][0]+gift[k].v);
                    }
                    else if (i>=gift[k].p)
                    {
                        res[i][j][1]=max(res[i][j][0]+gift[k].v,res[i-gift[k].p][j][1]+gift[k].v);
                        res[i][j][0]=res[i-gift[k].p][j][0]+gift[k].v;
                    }
                    else if (j>=gift[k].p)
                    {
                        res[i][j][1]=max(res[i][j][0]+gift[k].v,res[i][j-gift[k].p][1]+gift[k].v);
                        res[i][j][0]=res[i][j-gift[k].p][0]+gift[k].v;
                    }
                    else
                    {
                        res[i][j][1]=res[i][j][0]+gift[k].v;
                    }
                }
            }
        }
        m=0;
        if (res[v1][v2][1]<ts&&res[v1][v2][0]<ts) m=-1;
        if (m==0)
        {
            for (; k<=n; ++k)
            {
                for (i=v1; i>=0; --i)
                {
                    for (j=v2; j>=0; --j)
                    {
                        if (res[i][j][0]>=ts) res[i][j][1]=max(res[i][j][1],res[i][j][0]+gift[k].v);
                        if (j>=gift[k].p&&res[i][j-gift[k].p][0]>=ts) res[i][j][0]=max(res[i][j-gift[k].p][0]+gift[k].v,res[i][j][0]);
                        if (i>=gift[k].p&&res[i-gift[k].p][j][0]>=ts) res[i][j][0]=max(res[i-gift[k].p][j][0]+gift[k].v,res[i][j][0]);
                        if (j>=gift[k].p&&res[i][j-gift[k].p][1]>=ts) res[i][j][1]=max(res[i][j-gift[k].p][1]+gift[k].v,res[i][j][1]);
                        if (i>=gift[k].p&&res[i-gift[k].p][j][1]>=ts) res[i][j][1]=max(res[i-gift[k].p][j][1]+gift[k].v,res[i][j][1]);
                    }
                }
            }
            for (i=1; i<=v1; ++i)
            {
                for (j=1; j<=v2; ++j)
                {
                    m=max(m,res[i][j][0],res[i][j][1]);
                }
            }
        }
        printf("Case %d: %d\n\n",cas++,m);
    }
    return 0;
}
