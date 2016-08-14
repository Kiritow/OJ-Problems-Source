#include<stdio.h>
#include<queue>
#include<iostream>
#define INF 1000000000
#define N 1005
using namespace std;
int list[N],dis[N],hx[N],hy[N],px[N],py[N],tot,pre[N],pr[N];
char map[205][205];
struct dian
{
   int date,value,next,cost;    
}cun[2000005];
void add(int a,int b,int c,int d)
{
   cun[++tot].date=b;
   cun[tot].value=c;
   cun[tot].next=list[a];
   cun[tot].cost=d;
   list[a]=tot;    
   cun[++tot].date=a;
   cun[tot].value=0;
   cun[tot].next=list[b];
   cun[tot].cost=-d;
   list[b]=tot;
}
int abss(int a)
{
   if(a>0)  return a;
   return -a;    
}
int spfa(int s,int t)
{
   queue<int> p;
   int vis[N];
   for(int i=0;i<1005;i++)
     {
      dis[i]=INF;
      vis[i]=0;
      pre[i]=-1;    
     }
   dis[s]=0;
   p.push(s);
   int k;
   while(!p.empty())
     {
         k=p.front();
         p.pop();
         vis[k]=0;
         for(int i=list[k];i;i=cun[i].next)
            {
              int w=cun[i].value;
              int c=cun[i].cost;
              int to=cun[i].date;
              if(w>0&&dis[to]>dis[k]+c)
                 {
                    dis[to]=dis[k]+c;
                    pre[to]=k;
                    pr[to]=i;
                    if(!vis[to])
                       {
                        vis[to]=1;
                        p.push(to);        
                       }        
                 }    
            }           
     }
   if(dis[t]>=INF)  return 0;
   return 1; 
}
int maxflow(int s,int t)
{
   int min=INF;
   int sum=0;
   while(spfa(s,t))
   {
    for(int i=t;i!=s;i=pre[i])
      {
         if(min<cun[pr[i]].value)
            min=cun[pr[i]].value;        
      }    
    for(int i=t;i!=s;i=pre[i])
      {
         cun[pr[i]].value-=min;
         cun[pr[i]^1].value+=min;        
      }
    sum+=dis[t];
   }
 return sum;  
}
void clear()
{
   memset(list,0,sizeof(list));
   tot=1;    
}
int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)!=EOF)
     {
          if(n==0&&m==0)  break;
          getchar();
          clear();
          int count,kk;
          count=kk=1;
          for(int i=1;i<=n;i++)
           {
            for(int j=1;j<=m;j++)
                {
                    scanf("%c",&map[i][j]);
                    if(map[i][j]=='H')   {hx[count]=i; hy[count++]=j;}
                    if(map[i][j]=='m')    {px[kk]=i; py[kk++]=j;}
                } 
            getchar();
           }  
          for(int i=1;i<kk;i++)
           {
             add(1,i+1,1,0);
             for(int j=1;j<count;j++)
                {
                   int w=abss(hx[i]-px[j])+abs(hy[i]-py[j]);
                   add(i+1,count+1+j,1,w);
                }
           }
          for(int i=1;i<count;i++)
           {
             add(count+1+i,2*count+10,1,0);        
           }
          printf("%d\n",maxflow(1,2*count+10));
     }    
}
