#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#include <stack>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <limits.h>
#include <time.h>
#include <string.h>
using namespace std;
#define LL long long
#define PI acos(-1.0)
#define Max INT_MAX
#define Min INT_MIN
#define eps 1e-8
#define N 201
bool g[N][N];
bool gg[N][N];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int i,j,k;
        memset(g,false,sizeof(g));
        memset(gg,false,sizeof(gg));
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            g[a][b]=true;
        }
        int res=0;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        for(k=1;k<=n;k++)
        if(g[j][i] && g[i][k]){
            g[j][k]=gg[j][k]=true;   
        }
        for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
        if(gg[i][j] || gg[j][i])
        res++;
        printf("%d\n",n*(n-1)/2-res);
    }
    return 0;
}
