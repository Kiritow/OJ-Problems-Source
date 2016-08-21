#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std ;
#define MEM(a, v)        memset (a, v, sizeof (a))    
#define INF        (-1)
#define MAXN    10000
struct EDGE {
    int v, w, next ;
} ;
bool    used[MAXN] ;
int        nz, nr, edgeCnt ;
int        first[MAXN], max_d[MAXN], dist[MAXN] ;
EDGE    edge[20*MAXN] ;
void add (const int u, const int v, const int w)
{
    edge[edgeCnt].v = v ;
    edge[edgeCnt].w = w ;
    edge[edgeCnt].next = first[u] ;
    first[u] = edgeCnt++ ;
}
void spfa (const int beg)
{
    int i, d, u, v ;
    queue<int>    q ;
    MEM (dist, INF) ;
    MEM (used, 0) ;
    if (max_d[beg] == INF)
        max_d[beg] = 1 ;
    dist[beg] = 1 ;
    used[beg] = 1 ;
    q.push (beg) ;
    while (!q.empty ())
    {
        u = q.front () ;
        q.pop () ;
        used[u] = 0 ;
        for (i = first[u] ; i != -1 ; i = edge[i].next)
        {
            d = dist[u] + edge[i].w ;
            v = edge[i].v ;
            if (dist[v] == INF || dist[v] > d)
            {
                dist[v] = d ;
                if (max_d[v] == INF || max_d[v] < dist[v])
                    max_d[v] = dist[v] ;
                if (!used[v])
                {
                    q.push (v) ;
                    used[v] = 1 ;
                }
            }
        }
    }
}
int main ()
{
    int i, j ;
    int u, v, w ;
    int tcase, mz, minV, id ;
    while (scanf ("%d", &tcase) != EOF)
    {
        while (tcase--)
        {
            MEM (first, -1) ;
            MEM (max_d, INF) ;
            edgeCnt = 0 ;
            scanf ("%d%d", &nz, &nr) ;
            for (i = 0 ; i < nz ; ++i)
            {
                scanf ("%d%d", &u, &mz) ;
                while (mz--)
                {
                    scanf ("%d", &v) ;
                    add (v, u, 1) ;
                    add (u, v, 1) ;
                }
            }
            while (nr--)
            {
                scanf ("%d", &v) ;
                for (i = 0 ; i < v ; ++i)
                {
                    scanf ("%d", &u) ;
                    spfa (u) ;
                }
            }
            minV = INF ;
            id = -1 ;
            for (i = 0 ; i < MAXN ; ++i)
                if (max_d[i] != INF)
                {
                    if (minV == INF || minV > max_d[i])
                    {
                        minV = max_d[i] ;
                        id = i ;
                    }
                }
            printf ("%d %d\n", minV, id) ;
        }
    }
    return 0 ;
}
