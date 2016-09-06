#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
const int MAXN=1010;
struct Node
{
    int x,y;
    int r;
};
bool cmp(Node a,Node b)
{
    return a.r<b.r;
}
int dis2(Node a,Node b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
Node node[MAXN];
Node node1[MAXN];
Node node2[MAXN];
int dp1[MAXN];
int dp2[MAXN];
int main()
{
    int T;
    int n;
    int iCase=0;
    Node st;
    st.x=0;st.y=0;
    Node ed;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        printf("Case %d: ",iCase);
        scanf("%d",&n);
        scanf("%d%d",&ed.x,&ed.y);
        int t1=0;
        int t2=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].r);
            int d1=dis2(st,node[i]);
            int d2=dis2(ed,node[i]);
            if(d1==node[i].r*node[i].r||d2==node[i].r*node[i].r)
                continue;
            if(d1<node[i].r*node[i].r&&d2<node[i].r*node[i].r)continue;
            if(d1>node[i].r*node[i].r&&d2>node[i].r*node[i].r)continue;
            if(d1<node[i].r*node[i].r)
            {
                node1[t1++]=node[i];
            }
            else node2[t2++]=node[i];
        }
        sort(node1,node1+t1,cmp);
        sort(node2,node2+t2,cmp);
        int ans1=0,ans2=0;
        for(int i=0;i<t1;i++)
        {
            dp1[i]=1;
            for(int j=0;j<i;j++)
            {
                int d=dis2(node1[i],node1[j]);
                if(node1[i].r>node1[j].r && d<(node1[i].r-node1[j].r)*(node1[i].r-node1[j].r))
                    dp1[i]=max(dp1[i],dp1[j]+1);
            }
            ans1=max(ans1,dp1[i]);
        }
        for(int i=0;i<t2;i++)
        {
            dp2[i]=1;
            for(int j=0;j<i;j++)
            {
                int d=dis2(node2[i],node2[j]);
                if( node2[i].r>node2[j].r && d<(node2[i].r-node2[j].r)*(node2[i].r-node2[j].r))
                    dp2[i]=max(dp2[i],dp2[j]+1);
            }
            ans2=max(ans2,dp2[i]);
        }
        int ans=max(ans1,ans2);
        for(int i=0;i<t1;i++)
            for(int j=0;j<t2;j++)
            {
                int d1=dis2(node1[i],node2[j]);
                if(d1>(node1[i].r+node2[j].r)*(node1[i].r+node2[j].r))
                    ans=max(ans,dp1[i]+dp2[j]);
            }
        printf("%d\n",ans);
    }
    return 0;
}
