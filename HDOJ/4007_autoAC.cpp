#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1000100000;
struct node
{
    int x,y;
}n[1010];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
    int p,r,xmax,xmin,ymax,ymin,y[1010];
    while(scanf("%d%d",&p,&r)!=EOF)
    {
        ymax=xmax=-INF;ymin=xmin=INF;
        for(int i=0;i<p;i++)
        {
            scanf("%d%d",&n[i].x,&n[i].y);
            if(ymax<n[i].y)ymax=n[i].y;
            if(ymin>n[i].y)ymin=n[i].y;
            if(xmax<n[i].x)xmax=n[i].x;
            if(xmin>n[i].x)xmin=n[i].x;
        }
        if((ymax-ymin<=r)&&(xmax-xmin<=r))
        {
            printf("%d\n",p);
            continue;
        }
        else
        {
            sort(n,n+p,cmp);
            int ans=0;
            for(int i=0;i<p;i++)
            {
                int k=0;
                for(int j=i;n[j].x<=n[i].x+r&&j<p;j++)
                {
                    y[k++]=n[j].y;
                }
                sort(y,y+k);
                int count=0,tem=0;
                for(int j=0;j<k&&tem<k;j++)
                {
                    while(y[tem]-y[j]<=r&&tem<k)tem++;
                    if(count<tem-j)count=tem-j;
                }
                if(ans<count)ans=count;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
