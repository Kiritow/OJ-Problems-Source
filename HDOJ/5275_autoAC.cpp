#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <string>
#include <utility>
using namespace std;
typedef long long Int;
const int M=1e9+7;
int rev[250002];
int dp[3002][3002];
int x[3002],y[3002];
inline int getrev(int x){return x<0?-rev[-x]:rev[x];}
int main()
{
    rev[1]=1;
    for(int i=2;i<=250000;i++)rev[i]=(M-M/i)*(Int)rev[M%i]%M;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
        for(int i=1;i<=n;i++)dp[0][i]=y[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j+i<=n;j++)
                dp[i][j]=((dp[i-1][j+1]-dp[i-1][j])*(Int)getrev(x[i+j]-x[j])%M+M)%M;
        int m;scanf("%d",&m);
        while(m--)
        {
            int l,r,q;scanf("%d%d%d",&l,&r,&q);
            int ans=0,cur=1;
            for(int i=0;i<=r-l;i++)
            {
                ans+=dp[i][l]*(Int)cur%M;
                if(ans>=M)ans-=M;
                cur=(cur*(Int)(q-x[l+i])%M+M)%M;
            }printf("%d\n",ans);
        }
    }
}
