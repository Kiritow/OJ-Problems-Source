#include<stdio.h>
#include<string.h>
#include<queue>
#define N_node 2000
#define N_eage 200090
#define inf 1000000000
using namespace std;
typedef struct
{
    int from ,to ,next ,cost ,flow;
}STAR;
STAR E[N_eage];
int list[N_node] ,tot;
int mer[N_eage];
int s_x[N_node];
void add(int a ,int b ,int c ,int d)
{
    E[++tot].from = a;
    E[tot].to = b;
    E[tot].cost = c;
    E[tot].flow = d;
    E[tot].next = list[a];
    list[a] = tot;
    E[++tot].from = b;
    E[tot].to = a;
    E[tot].cost = -c;
    E[tot].flow = 0;
    E[tot].next = list[b];
    list[b] = tot;
}
bool spfa(int s ,int t ,int n)
{
    for(int i = 0; i<= n ;i ++)
    s_x[i] = inf;
    s_x[s] = 0;
    bool mark[N_node] = {0};
    mark[s] = 1;
    queue<int>q;
    q.push(s);
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
                mer[xin] = k;
                s_x[xin] = s_x[tou] + E[k].cost;
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
int M_C_flow(int s ,int t ,int n ,int p_num)
{
    int minflow ,mincost = 0 ,maxflow = 0;
    while(spfa(s ,t ,n))
    { 
        minflow = inf;
        for(int i = mer[t] ;i + 1 ;i = mer[E[i].from])
        {
            if(minflow > E[i].flow)
            minflow = E[i].flow;
        }
        for(int i = mer[t] ;i + 1 ;i = mer[E[i].from])
        {
            E[i].flow -= minflow;
            E[i^1].flow += minflow;
            mincost += E[i].cost * minflow;
        }
        maxflow += minflow;
    }
    if(maxflow != p_num) mincost = 1;
    return mincost;
}
int main ()
{
    int i ,j ,n ,m ,num ,k ,a ,b ,c ,cc = 1;
    while(~scanf("%d %d %d" ,&n ,&m ,&k))
    {
        memset(list ,0 ,sizeof(list));
        tot = 1;
        for(i = 1 ;i <= k ;i ++)
        {
            scanf("%d %d %d" ,&a ,&b ,&c);
            a++ ,b ++;
            if(c < 0)continue;
            add(a ,b + n ,-c ,1);
        }    
        int e = n + m + 1;
        for(i = 1 ;i <= n ;i ++)
        {
            add(0 ,i ,0 ,1);
        }        
        for(i = 1 ;i <= m ;i ++)
        {
            add(i + n ,e ,0 ,1);
        }
        printf("Case %d: %d\n" ,cc++ ,-M_C_flow(0 ,e ,e ,n));
    }
    return 0;
}
