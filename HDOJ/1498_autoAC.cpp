#include<stdio.h>
#include<string.h>
int tot,n,k,list[10005],mark_dfs[10005],mark_gx[20005],mark[105],map[205][205];
struct dian
{
  int date,next    ;
}cun[50005];
struct rose
{
  int x[20005],y[20005];
  int count;
}cun1[55];
void add(int a,int b)
{
  cun[tot].date=b;
  cun[tot].next=list[a];
  list[a]=tot++;
}
int dfs(int x)
{
  for(int i=list[x];i;i=cun[i].next)
    {
       int date=cun[i].date;    
       if(mark_dfs[date]) continue;
       mark_dfs[date]=1;
       if(mark_gx[date]==-1||dfs(mark_gx[date]))
         {
            mark_gx[date]=x;
            return 1;        
         }
    }      
  return 0;
}
int main()
{
   int a;
   while(scanf("%d%d",&n,&k)!=EOF)
     {
        if(n==0&&k==0)  break;
        memset(mark,0,sizeof(mark));
        memset(cun1,0,sizeof(cun1));
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)        
             {
              scanf("%d",&a);
              map[i][j]=a;
              mark[a]=1;
              cun1[a].x[cun1[a].count]=i;
              cun1[a].y[cun1[a].count++]=j;
             }
        int flag=0;
        for(int i=1;i<=50;i++)
          {
             if(mark[i])
              {
                tot=1;
                memset(cun,0,sizeof(cun));
                memset(list,0,sizeof(list));
                for(int j=0;j<cun1[i].count;j++)
                  {
                         add(cun1[i].x[j],cun1[i].y[j]);        
                  }    
                memset(mark_gx,255,sizeof(mark_gx));
                int sum=0;
                for(int j=1;j<=105;j++)
                  {
                     memset(mark_dfs,0,sizeof(mark_dfs));
                     sum+=dfs(j);    
                  }
                if(sum>k)   
                { 
                     if(flag==0)
                     printf("%d",i);
                     else printf(" %d",i);
                     flag=1;
                }
              }        
          }
       if(!flag)  printf("-1");
       printf("\n");
     }    
}
