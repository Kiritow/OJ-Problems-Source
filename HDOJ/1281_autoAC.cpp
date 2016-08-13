#include<stdio.h>
#include<string.h>
int mark_DFS[10005];
int mark_gx[10005];
int mark_gx2[10005];
int mark_kk[10005];
int tou[10005];
int tot;
typedef struct 
 {
   int date;
   int next;    
 }dian;
 dian cun[10005];
void add(int a,int b)
 {
   tot++;
   cun[tot].date=b;
   cun[tot].next=tou[a];
   tou[a]=tot;        
 }
int DFS(int x)
 {
      for(int i=tou[x];i;i=cun[i].next)
       {
          int too;
          too=cun[i].date;
          if(mark_DFS[too]||mark_kk[too]==x)  continue;
          mark_DFS[too]=1;
          if(mark_gx[too]==-1||DFS(mark_gx[too]))
          {
             mark_gx[too]=x;
             return 1;        
          }        
       }
    return 0;    
 }
int main()
{
   int n,a,b,T=1;
   while(scanf("%d%d%d",&a,&b,&n)!=EOF)
     {
       int x,y;
       tot=1;
      for(int i=0;i<10005;i++)
        {
           cun[i].next=0;
           tou[i]=0;    
        }
       for(int i=1;i<=n;i++)
         {
          scanf("%d%d",&x,&y);
          add(x,y);    
         }
       memset(mark_gx,255,sizeof(mark_gx));
       memset(mark_kk,255,sizeof(mark_kk));
       memset(mark_gx2,255,sizeof(mark_gx2));
       int sum=0;
       for(int i=0;i<=a;i++)
         {
           memset(mark_DFS,0,sizeof(mark_DFS));
           sum+=DFS(i);        
         }
       int max=sum;
       int num=0;       
       for(int i=1;i<=a;i++)   { mark_gx2[i]=mark_gx[i];}
       for(int j=1;j<=a;j++)
        if(mark_gx2[j]!=-1)  
        {
                memset(mark_kk,255,sizeof(mark_kk));
                mark_kk[j]=mark_gx2[j];
                sum=0;
                memset(mark_gx,255,sizeof(mark_gx));
                for(int i=0;i<=a;i++)
                {
                 memset(mark_DFS,0,sizeof(mark_DFS));
                 sum+=DFS(i);        
                }
                if(sum<max)  num++;
        }
       printf("Board %d have %d important blanks for %d chessmen.\n",T++,num,max);   
     }
     return 0;
}
