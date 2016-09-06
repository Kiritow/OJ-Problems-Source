#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define LL long long
#define N 205
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define rank rank1
const int mod = 10007;
int n,a[N];
double dp[N],p[N],ans;
char op[N][5];
int main()
{
    int i,j,k,cas=1;
    while(~scanf("%d",&n))
    {
        for(i = 0; i<=n; i++)
            scanf("%d",&a[i]);
        for(i = 1; i<=n; i++)
            scanf("%s",op[i]);
        for(i = 1; i<=n; i++)
            scanf("%lf",&p[i]);
        ans = 0;
        for(i = 0; i<=20; i++)
        {
            double q;
            if(a[0]&(1<<i)) q = 1;
            else q = 0;
            for(j = 1; j<=n; j++)
            {
                if(a[j]&(1<<i))
                {
                    if(op[j][0]=='&')
                        continue;
                    else if(op[j][0]=='^')
                        q = q*p[j]+(1-q)*(1-p[j]);
                    else
                        q = q*p[j]+(1-p[j]);
                }
                else
                {
                    if(op[j][0]=='&')
                        q = q*p[j];
                    else
                        continue;
                }
            }
            ans += q*(1<<i);
        }
        printf("Case %d:\n%lf\n",cas++,ans);
    }
    return 0;
}
