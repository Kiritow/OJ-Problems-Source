#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef __int64 LL;
using namespace std;
const int MAX=(1<<18)+10;
int n,m;
LL dp[MAX][20];
bool edge[20][20];
void DP(){
    int bit=1<<n;
    memset(dp,0,sizeof dp); 
    dp[1][0]=1;
    for(int i=1;i<bit;++i){
        for(int j=0;j<n;++j){
            if(dp[i][j] == 0)continue;
            for(int k=1;k<n;++k){
                if(i&(1<<k))continue;
                if(!edge[j][k])continue;
                dp[i|(1<<k)][k]+=dp[i][j];
            }
        }
    }
    LL sum=0;
    for(int i=0;i<n;++i)if(edge[0][i])sum+=dp[bit-1][i];
    printf("%I64d\n",sum);
}
int main(){
    int u,v;
    while(~scanf("%d%d",&n,&m)){
        memset(edge,false,sizeof edge);
        for(int i=0;i<m;++i){
            scanf("%d%d",&u,&v);
            --u,--v;
            edge[u][v]=edge[v][u]=true;
        }
        DP();
    }
    return 0;
}
