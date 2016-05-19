#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAXSTOCK 101
int m[MAXSTOCK][MAXSTOCK];

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        memset(m,0,sizeof(int)*MAXSTOCK*MAXSTOCK);
        for(int i=1;i<=n;i++)/// From i to...
        {
            int s;
            scanf("%d",&s);
            for(int j=0;j<s;j++)
            {
                int t,v;
                scanf("%d %d",&t,&v);
                /// From i to t, value=v
                m[i][t]=v;
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int f=1;f<=n;f++)
            {
                for(int t=1;t<=n;t++)
                {
                    if(f==t||f==k||t==k) continue;
                    if(m[f][k]!=0&&m[k][t]!=0)
                    {
                        int total=m[f][k]+m[k][t];
                        if(total<m[f][t]||m[f][t]==0)
                        {
                            m[f][t]=total;
                        }
                    }
                }
            }
        }
        /// Judge if is disjoint
        bool found=false;
        int FromPos=-1;
        int FromPosMaxTime=-1;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            int Max=0;
            for(int j=1;j<=n;j++)
            {
                Max=Max>m[i][j]?Max:m[i][j];
                if(m[i][j]) ++cnt;
            }
            if(cnt==n-1)
            {
                found=true;
                if(FromPosMaxTime<0||FromPosMaxTime>Max)
                {
                    FromPos=i;
                    FromPosMaxTime=Max;
                }
            }
        }
        if(!found)
        {
            printf("disjoint\n");
        }
        else
        {
            printf("%d %d\n",FromPos,FromPosMaxTime);
        }
    }
    return 0;
}
