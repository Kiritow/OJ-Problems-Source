#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
const int MAXN=10010;
const double eps=1e-9;
double k[MAXN],e[MAXN];
double A[MAXN],B[MAXN],C[MAXN];
vector<int>vec[MAXN];
bool dfs(int t,int pre)
{
    int m=vec[t].size();
    A[t]=k[t];
    B[t]=(1-k[t]-e[t])/m;
    C[t]=1-k[t]-e[t];
    double tmp=0;
    for(int i=0;i<m;i++)
    {
        int v=vec[t][i];
        if(v==pre)continue;
        if(!dfs(v,t))return false;
        A[t]+=(1-k[t]-e[t])/m*A[v];
        C[t]+=(1-k[t]-e[t])/m*C[v];
        tmp+=(1-k[t]-e[t])/m*B[v];
    }
    if(fabs(tmp-1)<eps)return false;
    A[t]/=(1-tmp);
    B[t]/=(1-tmp);
    C[t]/=(1-tmp);
    return true;
}
int main()
{
    int T;
    int n;
    int u,v;
    int iCase=0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)vec[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&k[i],&e[i]);
            k[i]/=100;
            e[i]/=100;
        }
        printf("Case %d: ",iCase);
        if(dfs(1,-1)&&fabs(1-A[1])>eps)
        {
            printf("%.6lf\n",C[1]/(1-A[1]));
        }
        else printf("impossible\n");
    }
}
