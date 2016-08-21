#include<stdio.h>
#include<string.h>
#define INF 1000000000
int tot,list[10005],mark_dfs[10005],mark_gx[10005],n,map[105][105];
int max,min,left,right,kk,mid;
struct dian
{
  int date,next,value;    
}cun[10005];
void add(int a,int b,int c)
{
   cun[tot].date=b;
   cun[tot].value=c;
   cun[tot].next=list[a];
   list[a]=tot++;    
}
int dfs(int x)
{
  for(int i=list[x];i;i=cun[i].next)
   {
      int date=cun[i].date;
      int w=cun[i].value;
      if(mark_dfs[date]||w<kk||w>kk+mid) continue;
      mark_dfs[date]=1;
      if(mark_gx[date]==-1||dfs(mark_gx[date]))    
       {
         mark_gx[date]=x;
         return 1;        
       }    
   }    
   return 0;
}
int finish()
{
    memset(mark_gx,255,sizeof(mark_gx));
    for(int i=1;i<=n;i++)
       {
          memset(mark_dfs,0,sizeof(mark_dfs));
          if(!dfs(i))  return 0;
       }
    return 1;
}
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
    {
       scanf("%d",&n);
       tot=1;
       min=INF;
       max=-INF;
       memset(list,0,sizeof(list));
       for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
           {
             scanf("%d",&map[i][j]);
             if(min>map[i][j])  min=map[i][j];
             if(max<map[i][j])  max=map[i][j];
             add(i,j,map[i][j]);
           }
       right=max-min;
       left=0;
       while(left<=right)
         {
           if(left==right)  break;
           mid=(left+right-1)/2;
           int flag=0;
           for(kk=min;kk+mid<=max;kk++)    
             {
               if(finish())  {flag=1;break;}        
             }
           if(flag) {right=mid;}
           if(!flag) {left=mid+1;}
         }    
      printf("%d\n",right);
    }    
}
