#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std ;
double dp[1000005] ;
int main()
{
    dp[1]=1.0 ;
    for(int i=2 ;i<=1000000 ;i++)
        dp[i]=dp[i-1]+1.0/i ;
    int n ; 
    while(~scanf("%d",&n))
    {
        if(n>1000000)printf("%.4f\n",0.57721566490153286060651209+log(n+1)) ;
        else printf("%.4f\n",dp[n]) ;
    }
    return 0 ;
}
