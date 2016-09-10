#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
#define eps 1e-6
const int MAXN=220;
double a[MAXN][MAXN],x[MAXN];
int equ,var;
int Gauss()
{
    int i,j,k,col,max_r;
    for(k=0,col=0;k<equ&&col<var;k++,col++){
        max_r = k;
        for(i=k+1;i<equ;i++)
            if(fabs(a[i][col])>fabs(a[max_r][col]))
                max_r = i;
        if(fabs(a[max_r][col])<eps)return 0; 
        if(k != max_r){
            for(j=col;j<var;j++)
                swap(a[k][j],a[max_r][j]);
            swap(x[k],x[max_r]);
        }
        x[k]/=a[k][col];
        for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
        a[k][col] = 1;
        for(i=0;i<equ;i++)
            if(i!=k){
                x[i] -= x[k]*a[i][k];
                for(j=col+1;j<var;j++)a[i][j]-=a[k][j]*a[i][col];
                a[i][col]=0;
            }
    }
    return 1;
}
vector<int>vec[MAXN];
int g[MAXN][MAXN];
int du[MAXN];
int add[MAXN];
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)
            vec[i].clear();
        memset(g,0,sizeof(g));
        memset(du,0,sizeof(du));
        int u,v;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            if(u == v)continue;
            g[u][v] = 1;
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
                if(j != i && g[i][j])
                {
                    du[i]++;
                    vec[j].push_back(i);
                }
        }
        equ = var = n;
        for(int i = 0;i < n;i++)
            x[i] = 0;
        memset(a,0,sizeof(a));
        for(int i = 0;i < n;i++)
        {
            a[i][i] = -1;
            int sz = vec[i].size();
            for(int j = 0;j < sz;j++)
            {
                int v = vec[i][j];
                if(i == v)continue;
                a[i][v] = 1.0 / du[v];
            }
        }
        for(int i = 0;i < n;i++)
            a[n-1][i] = 1;
        x[n-1] = 1;
        for(int k = 0;k < n-1;k++)
            if(g[n-1][k] == 0)
            {
                for(int i = 0;i < n-1;i++)
                {
                    if(g[n-1][i])a[i][var] = 1.0/(du[n-1]+1);
                    else a[i][var] = 0;
                }
                a[k][var] = 1.0/(du[n-1]+1);
                a[n-1][var] = 1;
                add[var] = k;
                var++;
            }
        if(!Gauss())
        {
            printf("INF\n");
            continue;
        }
        double tt = x[n-1];
        double now = x[n-1];
        int ans = -1;
        for(int i = n;i < var;i++)
        {
            if(x[n-1]/a[n-1][i] > now)
            {
                ans = add[i];
                now = x[n-1]/a[n-1][i];
            }
        }
        printf("%d %d\n",1,ans);
    }
    return 0;
}
