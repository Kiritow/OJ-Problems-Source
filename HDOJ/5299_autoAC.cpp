#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
struct Point
{
    int x,y,r;
}point[20010];
bool cmp(Point a,Point b)
{
    return a.r<b.r;
}
struct Edge
{
    int to,next;
}edge[20010];
int head[20010],tail;
void add(int from,int to)
{
    edge[tail].to=to;
    edge[tail].next=head[from];
    head[from]=tail++;
}
int dfs(int from)
{
    int ans=0;
    for(int i=head[from];i!=-1;i=edge[i].next)
        ans^=dfs(edge[i].to)+1;
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&point[i].x,&point[i].y,&point[i].r);
        sort(point,point+n,cmp);
        tail=0;
        memset(head,-1,sizeof(head));
        for(int i=0;i<n;i++)
        {
            bool flag=0;
            for(int j=i+1;j<n;j++)
                if(ll(point[j].r*point[j].r)>ll(point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y))
                {
                    flag=1;
                    add(j,i);
                    break;
                }
            if(!flag)
                add(n,i);
        }
        if(dfs(n)!=0)
            puts("Alice");
        else
            puts("Bob");
    }
}
