#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int N = 1001;
const double PI = acos(-1),
             EPS = 1e-8;
struct Angle
{
    double l,r;
};
bool cmp(const Angle &a,const Angle &b)
{
    return a.l  < b.l;
}
int n;
Angle A[N];
int ok(double l,double r,double x)
{
    if(l - r < EPS)
        return l - x < EPS && x - r < EPS;
    return l - x < EPS || x - r < EPS ;
}
int main()
{
    int i,t;
    double a,b,r;
    double x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0; i  < n; ++i)
        {
            scanf("%lf%lf%lf",&a,&b,&r);
            double dis = sqrt(a * a + b * b);
            double si = asin(r/dis);
            double ta = atan2(b,a);
            A[i].l = ta - si;
            if(A[i].l < -PI)
                A[i].l += 2 * PI;
            A[i].r = ta + si;
            if(A[i].r > PI)
                A[i].r -= 2 * PI;
        }
        sort(A, A + n, cmp);
        int res = n,tem;
        for(i = 0; i < n;++i)
        {
            tem = 1;
            double L = A[i].l,R = A[i].r;
            for(int j = 1;j < n; ++j)
            {
                int k = (i + j) % n;
                if(!ok(L,R,A[k].l))
                {
                    L = A[k].l;
                    R = A[k].r;
                    ++ tem ;
                }
                else if(ok(L,R,A[k].r))
                {
                    R = A[k].r;
                }
            }
            if(tem < res)
                res = tem;
        }
        printf("%d\n",res);
    }
    return 0;
}
