#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define clr(a, b) memset(a, b, sizeof(a))
#define SZ(a) ((int)a.size())
#define PB push_back
#define MP make_pair
#define inf 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#ifdef ecust
#define R "%lld"
#else
#define R "%I64d"
#endif
namespace acm {
double x0, y0, x1, y1;
double vx, vy;
double t;
double fun(double x){
    return 1.0/9.8*(x/2*sqrt(x*x+vx*vx)+vx*vx/2*log(x+sqrt(x*x+vx*vx)));
}
void solve(){
    scanf("%lf%lf%lf%lf%lf", &x0, &y0, &x1, &y1, &t);
    if(fabs(t) <= 1e-8) {puts("Impossible."); return;}
    vx = ((x1 - x0))/t;
    vy = ((y1 - y0) + 0.5*9.8*t*t)/t;
    printf("%.3lf\n", fun(vy)-fun(vy-9.8*t));
}
void icpc(){
    int cas; scanf("%d", &cas);
    while(cas--){
        solve();
    }
}
}
int main() {
    acm::icpc();
    return 0;
}
