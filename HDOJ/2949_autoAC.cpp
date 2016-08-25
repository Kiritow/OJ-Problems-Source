#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define clr(a,b)    (memset(a,b,sizeof(a)))
#define rep(i,a)    for(int i=0; i<(int)a.size(); i++)
const int INF = 0x3f3f3f3f;
const double eps = 1E-8;
int T;
int n,l,r;
char s[200010];
int num[200010];
LL tot = 1ll*n*(n+1)/2;
double fun1(int lim)
{
    double ret = 0;
    int ed = 1,sum = num[1];
    for(int st=1; st<=n; st++)
    {
        while(sum <= lim && ed < n)
        {
            ed ++;
            sum += num[ed];
        }
        if(sum > lim)    ret += 1.0*(n - ed + 1)/(1ll*n*(n-st+1)) ;
        sum -= num[st];
    }
    return ret;
}
double fun2(int lim)
{
    double ret = 0;
    int ed = 1,sum = num[1];
    for(int st=1; st<=n; st++)
    {
        while(sum < lim && ed < n)
        {
            ed ++;
            sum += num[ed];
        }
        if(sum >= lim)
        {
            if(ed-1 >= st)    ret += 1.0*(ed - st)/(1ll*n*(n-st+1));
        }
        else
        {
            ret += 1.0*(ed - st + 1)/(1ll*n*(n-st+1));
        }
        sum -= num[st];
    }
    return ret;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s",s+1);
        scanf("%d%d",&l,&r);
        num[0] = 0;
        for(int i=1; i<=n; i++)    num[i] = s[i] - 'A';
        double a,b,c;
        c = fun1(r);
        a = fun2(l);
        b = 1 - a - c;
        printf("%lf %lf %lf\n",b,a,c);
    }
    return 0;
}
