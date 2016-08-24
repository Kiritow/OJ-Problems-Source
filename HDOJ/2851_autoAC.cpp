#include<iostream>
#include<stdio.h>
using namespace std;
const int MAX=2001;
const int MAXINT=999999999;
struct point 
{
   int x1,x2;
   int length;
}sq[MAX];
int map[MAX][MAX];
int visit[MAX];
int dist[MAX];
int n,m;
void Dijkstra()
{
    for(int i=1;i<=n;i++)
    {
          visit[i]=0;
          dist[i]=map[1][i];
    } 
    visit[1]=1;
    int k,min; 
    for(int i=1;i<n;i++)
    {
              min=MAXINT; 
              for(int j=1;j<=n;j++)
                    if(!visit[j]&&dist[j]<min)
                    {
                             min=dist[j];
                             k=j; 
                    }
              visit[k]=1;
              for(int j=1;j<=n;j++)
                   if(!visit[j]&&dist[k]+map[k][j]<dist[j])
                         dist[j]=dist[k]+map[k][j]; 
    }
}
int main()
{
   int num;
   scanf("%d",&num);
   while(num--)
   {
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++)
      scanf("%d%d%d",&sq[i].x1,&sq[i].x2,&sq[i].length);  
   for(int i=1;i<=n;i++)
   { 
       for(int j=1;j<=n;j++)
               map[i][j]=MAXINT;
       map[i][i]=0;         
   }  
   for(int i=1;i<n;i++)
       for(int j=i+1;j<=n;j++)
           if(sq[i].x2>=sq[j].x1&&sq[i].x2<=sq[j].x2)
                    map[i][j]=sq[j].length;
   Dijkstra(); 
   int T; 
   for(int i=1;i<=m;i++)
   { 
          scanf("%d",&T); 
           if(dist[T]==MAXINT) printf("-1\n");
           else printf("%d\n",sq[1].length+dist[T]); 
   } 
   }
   return 0;
}
