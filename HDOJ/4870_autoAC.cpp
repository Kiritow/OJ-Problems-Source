#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF ((LL)100000000000000000)
#define inf (-((LL)1<<40))
#define lson k<<1, L, mid
#define rson k<<1|1, mid+1, R
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
template<class T> T CMP_MIN(T a, T b) { return a < b; }
template<class T> T CMP_MAX(T a, T b) { return a > b; }
template<class T> T MAX(T a, T b) { return a > b ? a : b; }
template<class T> T MIN(T a, T b) { return a < b ? a : b; }
template<class T> T GCD(T a, T b) { return b ? GCD(b, a%b) : a; }
template<class T> T LCM(T a, T b) { return a / GCD(a,b) * b;    }
typedef long long LL;
const int MAXN = 255;
const int MAXM = 110000;
const double eps = 1e-12;
double t[30];
int main()
{
    double p;
    while(~scanf("%lf", &p))
    {
        t[0] = 0;
        t[1] = 1 / p;
        t[2] = 1 / p + 1 / p / p;
        for(int i=3;i<=20;i++)
        {
            t[i] = 1 / p * t[i-1] + 1 / p - (1-p) / p * t[i-3];
        }
        double ans = 2 *t[19] + t[20] - t[19];
        printf("%lf\n", ans);
    }
    return 0;
}
