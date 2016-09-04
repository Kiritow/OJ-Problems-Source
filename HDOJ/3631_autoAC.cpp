#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 99999999
using namespace std;
int map[305][305];
int mark[305];
void floyd(int k,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(map[i][j]>map[i][k]+map[k][j])
                map[i][j]=map[i][k]+map[k][j];
        }
    }
}
int main()
{
    int n,m,q;
    int cas=1;
    while(scanf("%d%d%d",&n,&m,&q))
    {
        if(n==0&&m==0&&q==0)
            break;
        int i,j;
        memset(mark,0,sizeof(mark));
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                map[i][j]=(i==j?0:inf);
        for(i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(w<map[u][v])
                map[u][v]=w;
        }
        if(cas!=1)
            printf("\n");
        printf("Case %d:\n",cas++);
        for(i=0;i<q;i++)
        {
            int f;
            scanf("%d",&f);
            if(f==0)
            {
                int t;
                scanf("%d",&t);
                if(mark[t])
                    printf("ERROR! At point %d\n",t);
                else
                {
                    mark[t]=1;
                    floyd(t,n);
                }
            }
            else
            {
                int u,v;
                scanf("%d%d",&u,&v);
                if(!mark[u]||!mark[v])
                    printf("ERROR! At path %d to %d\n",u,v);
                else if(map[u][v]>=inf)
                    printf("No such path\n");
                else
                    printf("%d\n",map[u][v]);
            }
        }
    }
    return 0;
}
