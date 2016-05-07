#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
 
using namespace std;
//Constant Declaration
/*--------------------------*/
//#define LL long long 
#define LL __int64
const int M=1100;//最多点数
const int INF=1<<30;
const double EPS = 1e-11;
const double PI = acos(-1.0);
/*--------------------------*/
// some essential funtion
/*----------------------------------*/
void Swap(int &a,int &b){   int t=a;a=b;b=t; }
int Max(int a,int b){   return a>b?a:b;  }
int Min(int a,int b){   return a<b?a:b;  }
int Gcd(int a,int b){   while(b){b ^= a ^=b ^= a %= b;}  return a; }
/*----------------------------------*/
//for (i = 0; i < n; i++)
/*----------------------------------*/

struct djs
{
    int l,p;
}d[M],g[M][M];

bool used[M];//标记i是否被用过
void init(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            g[i][j].l = INF;//初始化图没有边，默认为INF,为了一定更新
            g[i][j].p = INF;
        }
    }
    for (i = 1; i <= n; i++)
    {
        d[i].l = INF;
        d[i].p = INF;
    }
    
    memset(used, 0, sizeof(used));
}



int dijkstra(int star, int end, int n)//起点，终点，总点数(编号为1,2...n)
{
    int min_num;//最小值的位置
    int i;
    d[star].l= 0;
    d[star].p= 0;//起点到起点的最短距离为0，很重要的一步
    for (int cnt = 0; cnt < n; cnt++)//注意别用while(n--),这样会改变n的值。n次贪心
    {
        int min = INF;
        for (i = 1; i <= n; i++)
        {
            if (!used[i] && d[i].l < min)
            {
                min = d[i].l;
                min_num = i;
            }
        }
        
        used[min_num] = 1;

        //把d[min_num]作为中间点，对相邻的点做松弛
        for (i = 1; i <= n; i++)
        {
            if (!used[i] && d[i].l > d[min_num].l + g[min_num][i].l)
            {
                d[i].l = d[min_num].l + g[min_num][i].l;
                d[i].p = d[min_num].p + g[min_num][i].p;
            }
            if (!used[i] && d[i].l == d[min_num].l + g[min_num][i].l && d[i].p > d[min_num].p + g[min_num][i].p)//这里的判断是关键
            {
                d[i].p = d[min_num].p + g[min_num][i].p;
            }
        }
        
    }
    return d[end].l;
}





int main()
{
 //freopen("in.txt","r",stdin);
 //freopen("out.txt","w",stdout);
 //int t, case1 = 0;
 //scanf("%d", &t);
 int n, m;
 int i, j;
 while (scanf("%d%d", &n, &m), n + m)
 {
     init(n);
    for (i = 0; i < m; i++)
    {
        int a, b, c, c1;
        scanf("%d%d%d%d", &a, &b, &c, &c1);
        if (g[a][b].l > c)
        {
            g[b][a].l = g[a][b].l = c;
            g[b][a].p= g[a][b].p = c1;
        }//此题为无向图
        if (g[a][b].l == c && g[b][a].p > c1)//这里的判断是关键
        {
            g[b][a].p= g[a][b].p = c1;
        }

    }
    int star, end,ans;
    scanf("%d%d", &star, &end);
    ans = dijkstra(star, end, n);
    printf("%d %d\n", ans, d[end].p);
 }
 
 return 0;
}
