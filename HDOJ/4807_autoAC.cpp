#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#define N_node 2500 + 50
#define N_edge 10000 + 100
#define INF 2000000000
using namespace std;
typedef struct
{
   int from ,to ,next ,cost ,flow;
}STAR;
STAR E[N_edge];
int list[N_node] ,tot;
int mer[N_edge] ,s_x[N_node];
void add(int a ,int b ,int c ,int d)
{
   E[++tot].from = a;
   E[tot].to = b;
   E[tot].cost = c;
   E[tot].flow = d;
   E[tot].next = list[a];
   list[a] = tot;
}
bool spfa(int s ,int t ,int n)
{
   int mark[N_node] = {0};
   for(int i = 0 ;i <= n ;i ++)
   s_x[i] = INF;
   queue<int>q;
   q.push(s);
   mark[s] = 1 ,s_x[s] = 0;
   memset(mer ,255 ,sizeof(mer));
   while(!q.empty())
   {
      int xin ,tou;
      tou = q.front();
      q.pop();
      mark[tou] = 0;
      for(int k = list[tou] ;k ;k = E[k].next)
      {
         xin = E[k].to;
         if(s_x[xin] > s_x[tou] + E[k].cost && E[k].flow)
         { 
            s_x[xin] = s_x[tou] + E[k].cost;
            mer[xin] = k;
            if(!mark[xin])
            {
               mark[xin] = 1;
               q.push(xin);
            }
         }
      }
   }
   return mer[t] != -1;
}
int M_C_Flow(int s ,int t ,int n ,int k)
{
   if(!k) return 0;
   int minflow ,sum_peo = k ,now_peo = 0 ,list_time = 0 ,ans = INF;
   while(spfa(s ,t ,n))
   {               
      minflow = INF;
      for(int i = mer[t] ;i + 1 ;i = mer[E[i].from])
      if(minflow > E[i].flow) minflow = E[i].flow;
      for(int i = mer[t] ;i + 1 ;i = mer[E[i].from])
      E[i].flow -= minflow ,E[i^1].flow += minflow;
      sum_peo -= (s_x[t] - list_time) * now_peo + minflow;
      list_time = s_x[t] ,now_peo += minflow;
      int now = s_x[t] + (int)ceil((1.0 * (sum_peo < 0 ? 0 : sum_ ))/now_peo);
      if(ans > now) ans = now;
      if(sum_peo < 1) break;
   }
   return ans;
}
int main ()
{
   int n ,m ,k ,i ,a ,b ,c;
   while(~scanf("%d %d %d" ,&n ,&m ,&k))
   {
      memset(list ,0 ,sizeof(list));
      tot = 1;
      for(i = 1 ;i <= m ;i ++)
      {
         scanf("%d %d %d" ,&a ,&b ,&c);
         a ++ ,b ++;
         add(a ,b ,1 ,c) ,add(b ,a ,-1 ,0);
      }
      int ans = M_C_Flow(1 ,n ,n ,k);
      ans == INF ? puts("No solution"):printf("%d\n" ,ans);
   }
   return 0;
}
