#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std ;
#define M 100000 + 10
#define eps 1e-4
int A[M] ;
int n ;
int m ;
int slove(double x)
{
    int sum = 0 ;
    double  d = A[0] ;
    d += 2 * x ;
    int i = 0 ;
    ++ sum ;
    while(d < A[m -1] * 1.0 )
    {
        while(A[i] <= d) ++ i ;
        d = A[i] + 2 * x ;
        sum ++ ;
    }
    return sum ;
}
double Find(double left , double right)
{
    double mid ;
    while(right - left >  eps)
    {
        mid = left + (right - left) / 2 ;
        if(slove(mid) <= n)
            right = mid  ;
        else left = mid +eps   ;
    }
    return  left  ;
}
int main()
{
    int cas ;
    double low ;
    double high ;
    double ans ;
    while(scanf("%d",&cas) != EOF)
    {
        while(cas --)
        {
            scanf("%d%d",&n,&m) ;
            for(int i = 0 ;i < m ; ++ i)
                scanf("%d",&A[i]) ;
            sort(A , A+ m) ;
            low = 0 ;
            high = A[m -1] * 1.0 / n  ;
            ans = Find(low , high) ;
            printf("%.1lf\n",ans) ;
        }
    }
    return 0 ;
}
