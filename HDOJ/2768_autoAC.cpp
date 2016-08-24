#include<stdio.h>
#include<string.h>
int tot,list[20005],mark_dfs[20005],mark_gx[20005],n,m,k;
struct dian
{
    char need[50];
    char no[50];    
}cun1[20005];
struct ren
{
   int date,next;    
}cun[20005];
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
        if(mark_dfs[date])  continue;
        mark_dfs[date]=1;
        if(mark_gx[date]==-1||dfs(mark_gx[date]))
        {
           mark_gx[date]=x;
           return 1;    
        }
    }     
  return 0;
}
void clear()
{
   memset(list,0,sizeof(list));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
      {
       tot=1;
       clear();
       scanf("%d%d%d",&n,&m,&k);
       for(int i=1;i<=k;i++)
         {
           scanf("%s%s",cun1[i].need,cun1[i].no);        
         }    
       for(int i=1;i<k;i++)
         for(int j=i+1;j<=k;j++)
         {
           if((!strcmp(cun1[i].need,cun1[j].no)||!strcmp(cun1[i].no,cun1[j].need)))
            {
             add(i,j);  
             add(j,i);  
            }
         }    
       memset(mark_gx,255,sizeof(mark_gx));
       int sum=0;
       for(int i=1;i<=k;i++)
          {
             memset(mark_dfs,0,sizeof(mark_dfs));
             sum+=dfs(i);        
          }
       printf("%d\n",k-sum/2);
      }
}
