#include<iostream>
#include<queue>
using namespace std;
typedef struct fun
{
 int a,w,pre;
}e;
fun link[2][1000005];
bool vis[1000005];
int point[2][1000005];
__int64 price[1000005];
int P,Q;
void spfa(int n)
{
 int i;
     for(i=2; i<=P; i++)
  {
   vis[i]=false;
   price[i]=INT_MAX;
  }
  vis[1]=true;
  price[i]=0;
  queue<int>q;
  q.push(1);
  while(q.empty()==false)
  {
   int t=q.front();
   q.pop();
   vis[t]=false;
   i=point[n][t];
   while(i!=-1)
   {
    
    int v=link[n][i].a;
    if(price[v]>price[t]+link[n][i].w)
    {
                 price[v]=price[t]+link[n][i].w;
     if(vis[v]==false)
     {
      vis[v]=true;
      q.push(v);
     }
    }
    i=link[n][i].pre;
   }
  }
}
int main()
{
 int T,i,a,b,c;
 scanf("%d",&T);
 while(T--)
 {
  scanf("%d%d",&P,&Q);
  for(i=1; i<=P; i++)
   point[0][i]=point[1][i]=-1;//这个是用来弄初值的
  i=0;
  for(i=1; i<=Q; i++)
  {
            scanf("%d%d%d",&a,&b,&c);
            link[0][i].a=a;
   link[0][i].w=c;
   link[1][i].a=b;
   link[1][i].w=c; 
   link[1][i].pre=point[1][a];//记录的是以a开头的
   point[1][a]=i;
   link[0][i].pre=point[0][b];
   point[0][b]=i;
  }
   __int64 sum=0;
  spfa(1);//是用来出发点不同的啊
   for(i=1; i<=P; i++)
  { 
    sum+=price[i]; 
   }
  spfa(0);
  for(i=1; i<=P; i++)
  {
   sum+=price[i]; 
  }
  printf("%I64d\n",sum);
 }
 return 0;
}
