#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>
#include <set>
#include <queue>
#define MAX(a,b) (a) > (b)? (a):(b)
#define MIN(a,b) (a) < (b)? (a):(b)
#define mem(a) memset(a,0,sizeof(a))
#define INF 1000000007
#define MAXN 20005
using namespace std;

bool op[105];
int num[105],dp_max[10005], dp_min[10005], n;
bool vis_max[10005],vis_min[10005];
int DP_MIN(int i,int j);
int DP_MAX(int i,int j);


int DP_MAX(int i,int j)//DP求区间最大值
{
    int u = i*100+j;
    if(vis_max[u])return dp_max[u];
    vis_max[u]=1;
    if(j-i <= 1)
    {
        if(j==i)return dp_max[u]=num[i-1];
        if(!op[i])return dp_max[u]=num[i-1]+num[i];
        else return dp_max[u]=num[i-1]*num[i];
    }
    dp_max[u] = -INF;
    for(int k=i;k<j;k++)
    {
        int l=DP_MIN(i,k);
        int r=DP_MIN(k+1,j);
        int ll=DP_MAX(i,k);
        int rr=DP_MAX(k+1,j);
        if(!op[k])dp_max[u] = MAX(dp_max[u], ll+rr);
        else dp_max[u] = MAX(dp_max[u], MAX(ll*rr,MAX(l*r,MAX(l*rr,r*ll))));
    }
    return dp_max[u];
}

int DP_MIN(int i,int j)//DP求区间最小值
{
    int u = i*100+j;
    if(vis_min[u])return dp_min[u];
    vis_min[u]=1;
    if(j-i <= 1)
    {
        if(j==i)return dp_min[u]=num[i-1];
        if(!op[i])return dp_min[u]=num[i-1]+num[i];
        else return dp_min[u]=num[i-1]*num[i];
    }
    dp_min[u] = INF;
    for(int k=i;k<j;k++)
    {
        int l=DP_MIN(i,k);
        int r=DP_MIN(k+1,j);
        int ll=DP_MAX(i,k);
        int rr=DP_MAX(k+1,j);
        if(!op[k])dp_min[u] = MIN(dp_min[u], l+r);
        else dp_min[u] = MIN(dp_min[u], MIN(ll*rr,MIN(l*r,MIN(l*rr,r*ll))));
    }
    return dp_min[u];
}

int main()
{
    while(~scanf("%d%*c",&n))
    {
        mem(op);mem(dp_max);
        mem(num);mem(vis_min);
        mem(vis_max);
        int max=-INF,i;
        char ch;
        for(i=0;i<n;i++)
        {
            scanf("%c %d%*c",&ch,&num[i]);
            op[i]=op[i+n]=(ch=='x');
            num[i+n]=num[i];
        }
        for(i=0;i<n;i++)
        {
            max=MAX(max,DP_MAX(i+1,i+n));
        }
        printf("%d\n",max);
        int ok=1;
        for(i=0;i<n;i++)
        {
            if(DP_MAX(i+1,i+n) == max)
            {
                if(ok){printf("%d",i+1);ok=0;}
                else printf(" %d",i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
