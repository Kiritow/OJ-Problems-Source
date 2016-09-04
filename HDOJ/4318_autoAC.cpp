#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct p
{
    int a[50][2];
}p[50010];
double b[51000];
queue<int> q;
int s,t,n;
double m;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(p,-1,sizeof(p));
    for(int i=0;i<51000;i++)
     b[i]=-1;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            scanf("%d",&p[i].a[j][0]);
            scanf("%d",&p[i].a[j][1]);
        }
    }
    scanf("%d%d%lf",&s,&t,&m);
    b[s]=0;
    q.push(s);
    int hd;
    while(!q.empty())
    {
        hd=q.front();
        q.pop();
        for(int i=0;i<50;i++)
        {
            if(p[hd].a[i][0]==hd)
              continue;
            if(p[hd].a[i][0]!=-1&&(b[p[hd].a[i][0]]+1<1e-8||b[p[hd].a[i][0]]>b[hd]+(100.0-b[hd])*p[hd].a[i][1]/100))
            {
                q.push(p[hd].a[i][0]);
                b[p[hd].a[i][0]]=b[hd]+(100.0-b[hd])*p[hd].a[i][1]/100;
            }
        }
    }
   if(b[t]+1<1e-8)
       cout<<"IMPOSSIBLE!\n";
    else
    printf("%.2lf\n",m*b[t]/100);
    }
    return 0;
}
