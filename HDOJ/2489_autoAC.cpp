#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f3f
const double esp=1e-3;
int n,m,node[20],edge[20][20],dis[20],visit[20],temp[20],su[20];
double minn;
int prim(int s)
{
    int length=0;
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=m;i++)
       dis[temp[i]]=edge[s][temp[i]];
    visit[s]=1;
    dis[s]=0;
    int point=s;
    for(int i=1;i<m;i++)
    {
        int mit=INF;
        for(int j=1;j<=m;j++)
          if(!visit[temp[j]]&&dis[temp[j]]<mit)
          {
               mit=dis[temp[j]];
               point=temp[j];
          }
        visit[point]=1;
        length+=mit;
        for(int j=1;j<=m;j++)
           if(!visit[temp[j]]&&dis[temp[j]]>edge[point][temp[j]])
              dis[temp[j]]=edge[point][temp[j]];
    }
    return length;
}
void dfs(int shi,int count)
{
    if(count==m)
    {
        double sum_node=0,sum_edge=0;
        for(int i=1;i<=m;i++)
          sum_node+=node[temp[i]];
        sum_edge=prim(temp[1]);
        double ridio=sum_edge/sum_node;
        if(ridio-minn<-esp)
        {
            minn=ridio;
            for(int i=1;i<=m;i++)
              su[i]=temp[i];
        }
        return;
    }
    for(int i=shi+1;i<=n;i++)
    {
        temp[count+1]=i;
        dfs(i,count+1);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        minn=INF;
        for(int i=1;i<=n;i++)
          scanf("%d",&node[i]);
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
             scanf("%d",&edge[i][j]);
        for(int i=1;i<=n;i++)
        {
            temp[1]=i;
            dfs(i,1);
        }
        for(int i=1;i<m;i++)
          printf("%d ",su[i]);
        printf("%d",su[m]);
        printf("\n");
    }
    return 0;
}
