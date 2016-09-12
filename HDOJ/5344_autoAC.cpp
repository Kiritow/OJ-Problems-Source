#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
typedef __int64 ll ;
int main()
{
    ll n , m , l , z ;
    int t ;
    scanf("%d" , &t) ;
    while(t--)
    {
        scanf("%I64d%I64d%I64d%I64d" , &n , &m , &z, &l) ;
        ll ans = 0 ;
        ll pre = 0 ;
        ll now ;
        for(int i = 2;i <= n;i++)
        {
           now = (pre*m + z)%l ;
           ans = ans^(2*now) ;
           pre = now ;
        }
       printf("%I64d\n" , ans) ;
    }
}
