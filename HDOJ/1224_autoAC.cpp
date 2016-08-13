#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn=102;
int d[maxn];
bool map[maxn][maxn];
int w[maxn];
int pre[maxn];
void print(int x)
{
    if(pre[x]!=0)
        print(pre[x]);
    printf("%d->",x);
}
int main()
{
    int t,n,m,x,y,l,i,j;
    scanf("%d",&t);
    for(l=1;l<=t;l++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&d[i]);
        d[n+1]=0;
        for(i=1;i<=n+1;i++)
        {   
            w[i]=0;
            pre[i]=0;
            for(j=i;j<=n+1;j++)
            {
                map[i][j]=false;
            }
        }
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=true;
        }
        for(j=1;j<=n+1;j++)
        {
            int max=0;
            int k=0;    
            for(i=1;i<j;i++)
            {
                if(map[i][j]&&max<=w[i])
                {
                    max=w[i];
                    k=i;
                }
            }
            pre[j]=k;
            w[j]=max+d[j];
        }
        printf("CASE %d#\npoints : %d\ncircuit : ",l,w[n+1]);
        print(pre[n+1]);
        printf("1\n"); 
        if(l<t) printf("\n");                           
    }                                                                
    return 0;
}
