#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <functional>
using namespace std;
typedef long long ll;
const double Pi = acos(-1.0);
const double eps = 1e-6;
const int IntMAX = 0x7fffffff;
const double DoubleMAX = 1e307;
#define TMIN(x,y) ( x<y?x:y ) 
const ll Inf = 40000000;
int dp[210][210][210];
int mp[210][210];
int dx[210];
int N,M,Q;
struct node
{
    int C;
    int dx;
    friend bool operator<(node A,node B)
    {
        return A.C<B.C;
    }
};
node cops[210];
int T;
int main()
{
    int a,b,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&cops[i].C);
            cops[i].dx = i;
        }
        sort(cops,cops+N);
        for(int i=0;i<N;i++)
        {
            dx[cops[i].dx] = i+1;
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                mp[i][j] = (i==j?0:Inf);
            }
        }
        for(int i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            mp[dx[a]][dx[b]] = mp[dx[b]][dx[a]] = min(mp[dx[a]][dx[b]],c);
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                dp[i][j][0] = mp[i][j];
            }
        }
        for(int k=1;k<=N;k++)
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    dp[i][j][k] = dp[i][j][k-1];
                }
            }
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    if( dp[i][j][k]>dp[i][k][k-1]+dp[k][j][k-1] )
                    {
                         dp[i][j][k] = dp[i][k][k-1]+dp[k][j][k-1];
                    }
                }
            }
        }
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d %d %d",&a,&b,&c);
            a = dx[a];
            b = dx[b];
            int ans = Inf;
            ans = min(ans,dp[a][b][0]);
            for(int i=N-1;i>=0;i--)
            {
                if( cops[i].C<=c )
                {
                    ans = min(ans,dp[a][b][i+1]);
                    break;
                }
            }
            if( ans==Inf )
                printf("-1\n");
            else
                printf("%d\n",ans);
        }
        printf("\n");
    }
    return 0;
}
