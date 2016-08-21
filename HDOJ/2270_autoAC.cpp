#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;
#define MP make_pair
#define PB push_back
#define foreach(e,x) for(__typedef(x.begin()) e=x.begin(); e!=x.end(); ++e)
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> mapII;
const int MAX_N = 1000000 + 10;
const double PI = acos(-1.);
const double EPS = 1e-8;
int N;
int a[MAX_N];
void read(int &x)
{
    x = 0;
    char ch;
    for( ; ch = getchar(); ) {
        if (isdigit(ch)) break;
    }
    x = ch - '0';
    for( ; ; ) {
        ch = getchar();
        if (! isdigit(ch)) break;
        x = x * 10 + ch - '0';
    }
}
void solve()
{
    for(int i = 1; i <= N; ++ i) a[i] = i;
    int u;
    for(int i = 1; i <= N; ++ i) {
        read(u);
        a[u] = a[i];
    }
    int ret = 0;
    for(int i = 1; i <= N; ++ i)
        ret += a[i] == a[1];
    printf("%d\n", ret - 1);
}
int main()
{
    for( ; cin >> N; ) 
        solve();
    return 0;
}
