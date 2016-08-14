#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<cmath>
#include<memory.h>
#include<set>
#define ll long long
#define eps 1e-7
#define inf 0xfffffff
const ll INF = 1ll<<61;
using namespace std;
int n,k;
int dp[10 + 5][1000 + 5];
int travel[10 + 5][1000 + 5];
int cost[10 + 5][10 + 5][1000 + 5];
void clear() {
    memset(dp,-1,sizeof(dp));
    memset(travel,0,sizeof(travel));
    memset(cost,0,sizeof(cost));
}
int main() {
    int Case = 0;
    while(scanf("%d %d",&n,&k),n + k) {
        clear();
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i != j) {
                    scanf("%d",&travel[i][j]);
                    for(int l=0;l<travel[i][j];l++)
                        scanf("%d",&cost[i][j][l]);
                }
            }
        }
        dp[1][0] = 0;
        int minn;
        for(int j=1;j<=k;j++) {
            for(int i=1;i<=n;i++) {
                minn = -1;
                for(int l=1;l<=n;l++) {
                    if(i == l || dp[l][j - 1] < 0)continue;
                    int tmp = (j - 1)%travel[l][i];
                    if(cost[l][i][tmp] == 0)continue;
                    if(minn < 0)
                        minn = dp[l][j - 1] + cost[l][i][tmp];
                    else if(minn > dp[l][j - 1] + cost[l][i][tmp])
                        minn = dp[l][j - 1] + cost[l][i][tmp];
                }
                dp[i][j] = minn;
            }
        }
        printf("Scenario #%d\n",++Case);
        if(dp[n][k] < 0)
            printf("No flight possible.\n\n");  
        else
            printf("The best flight costs %d.\n\n",dp[n][k]);  
    }
    return 0;
}
