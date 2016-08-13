#include <iostream>
#include <cstdio>
#include <cstdlib>
#define max 0x7fffffff
using namespace std;
struct edge
{
    int v1;
    int v2;
    int w;
}e[6000];
int cmp(const void *a,const void *b)
{
    struct edge *aa=(struct edge *)a;
    struct edge *bb=(struct edge *)b;
    if(aa->w != bb->w)
        return aa->w - bb->w;
    else
        return aa->v1 - bb->v1;
}
int main()
{
    int n,q,a,b,map[101][101],vis[101],i,j,k,min;//map璁板绘ョ╅碉vis涓洪《硅剧疆蹇
    while(scanf("%d",&n)!=EOF)
    {
        min=0;
        for(i=1;i<=n;i++) vis[i]=i;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&map[i][j]);
            }
            map[i][i]=max;
        }
        scanf("%d",&q);
        for(i=1;i<=q;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=map[b][a]=0;
        }
        for(i=1,k=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
               e[k].v1=i;
               e[k].v2=j;
               e[k].w=map[i][j];
               k++;
            }
        }
        qsort(&e[1],k-1,sizeof(e[1]),cmp);
        for(i=1,j=1;j<n;i++)
        {
            if(vis[e[i].v1] != vis[e[i].v2])
            {
                int m=vis[e[i].v1]>vis[e[i].v2] ? vis[e[i].v2] : vis[e[i].v1];
                int M=vis[e[i].v1]>vis[e[i].v2] ? vis[e[i].v1] : vis[e[i].v2];
                for(int ii=1;ii<=n;ii++)
                {
                    if(vis[ii]==M)
                        vis[ii]=m;
                }
                min+=e[i].w;
                j++;
            }
        }
        printf("%d\n",min);
    }
    return 0;
}
