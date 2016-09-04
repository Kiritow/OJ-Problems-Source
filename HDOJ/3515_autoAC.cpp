#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps = 1e-9;
const double Pi = acos(-1.0);
double ls[110];
int n;
inline double f(double s){
    double ret = 0.0, a, b;
    int i;
    for(i = 0; i < n; ++i)
    {
        a = ls[i];
        b = ls[(i+1) % n];
        ret += acos((a*a+b*b - s*s) / (2.0 * a *b));
    }
    return ret;
} 
int main(){
    int i, T, temp;
    double as[110], h, s, at[110], ang, l, r, m;
    scanf("%d", &T);
    while(T--){
        scanf("%d%lf%lf", &n, &s, &h);
        for(i = 0; i < n; ++i){
            scanf("%lf", &at[i]);
            at[i] *= Pi / 180.0;
        }
        sort(at, at + n);
        for((temp=0, i = 0); i < n; i+=2){
            as[temp++] = at[i];
        }
        --i;
        i >= n ? i-=2 : 1;
        for(; i >= 0; i-=2)
            as[temp++] = at[i];
        for(i = 0; i < n; ++i)
            ls[i] = 1.0 / tan(as[i]);
        l = 0.0;
        r = 1e20;
        for(i = 0;i < n; ++i){
            ls[i] + ls[(i+1) % n] < r ? r = ls[i] + ls[(i+1)%n] : 1;
            fabs(ls[i]-ls[(i+1)%n]) > l ? l = fabs(ls[i] - ls[(i+1)%n] ):1;
        } 
        l += eps;
        r -= eps;
        while(r-l > eps){
            m = (l + r) * 0.5;
            f(m) < 2.0 * Pi ? l = m : r = m;
        }
        printf("%.4lf\n", s/m + h *0.01);
    }
    return 0;
}
