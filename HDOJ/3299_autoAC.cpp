#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <time.h>;
#define cler(arr, val)    memset(arr, val, sizeof(arr))
typedef long long  LL;
const int MAXN = 100010;
const int MAXM = 20006;
const int INF = 0x3f3f3f3f;
const int mod = 10000007;
struct node
{
    int x,y;
}point[200];
bool cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int y[123],on1[111],on2[111],line[111];
int solve(int n,int m)
{
    cler(on1,0);
    cler(on2,0);
    cler(line,0);
    int ans=0;
    if(m<=2) return n;
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            int y1=y[i],y2=y[j];
            int num=0;
            for(int k=0;k<n;k++)
            {
                if(k==0||point[k].x!=point[k-1].x)
                {
                    num++;
                    on1[num]=on2[num]=0;
                    line[num]=line[num-1]+on2[num-1]-on1[num-1];
                }
                if(point[k].y>y1&&point[k].y<y2) on1[num]++;
                if(point[k].y>=y1&&point[k].y<=y2) on2[num]++;
            }
            if(num<=2) return n;
            int maxv=0;
            for(int k=1;k<=num;k++)
            {
                ans=max(ans,line[k]+on2[k]+maxv);
                maxv=max(maxv,on1[k]-line[k]);
            }
        }
    }
    return ans;
}
int main()
{
    int t,cas=1;
    while(scanf("%d",&t),t)
    {
        for(int i=0;i<t;i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
            y[i]=point[i].y;
        }
        sort(y,y+t);
        int tol2=1;
        for(int i=1;i<t;i++)
        {
            if(y[i]!=y[i-1])
                y[tol2++]=y[i];
        }
        sort(point,point+t,cmp);
        printf("Case %d: %d\n",cas++,solve(t,tol2));
    }
}
