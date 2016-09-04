#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MAXN 10006
#define INF 1e9
using namespace std;
struct Node
{
    int x,p;
}node[MAXN];
int N,ans;
__int64 K;
int cmp(const void *p1,const void *p2)
{
    return ((struct Node *)p1)->x-((struct Node *)p2)->x;
}
void Init()
{
    int i;
    for(i=1;i<=N;i++)
        scanf("%d%d",&node[i].x,&node[i].p);
    qsort(node+1,N,sizeof(node[0]),cmp);
}
void Solve()
{
    int i,j,k;
    __int64 M,d1,d2;
    int now;
    ans=0;
    for(i=1;i<=N;i++)
    {
        k=i-1;j=i+1;
        M=K;now=node[i].p;
        while(true)
        {
            if(k==0&&j!=N+1) 
            {
                d1=INF;
                d2=node[j].x-node[i].x;
            }
            else if(k!=0&&j==N+1)
            {
                d1=node[i].x-node[k].x;
                d2=INF;
            }
            else if(k!=0&&j!=N+1)
            {
                d1=node[i].x-node[k].x;
                d2=node[j].x-node[i].x;
            }
            else break;
            if(d1<d2)
            {
                if(d1*node[k].p<=M)
                {
                    now+=node[k].p;
                    M-=d1*node[k].p;
                    k--; 
                }
                else
                {
                    now+=M/d1;
                    break;
                }
            }
            else
            {
                if(d2*node[j].p<=M)
                {
                    now+=node[j].p;
                    M-=d2*node[j].p;
                    j++;
                }
                else
                {
                    now+=M/d2;
                    break;
                }
            }
        }
        if(now>ans) ans=now;
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%I64d",&N,&K)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}
