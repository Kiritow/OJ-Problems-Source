#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std ;
int fib[30] ,vis[30];
void chart()
{
    fib[1] = 1 ;
    fib[2] = 2 ;
    for(int i = 3 ; i < 30 ; i++)
        fib[i] = fib[i-1]+fib[i-2] ;
}
int main()
{
    int n ,m;
    scanf("%d",&n) ;
    chart() ;
    while(n--)
    {
        scanf("%d",&m) ;
        memset(vis,0,sizeof(vis)) ;
        for(int i = 29 ; i >= 1 ; i--)
        {
            if(m <= 0) break ;
            if(fib[i] <= m)
            {
                m -= fib[i] ;
                vis[i] = 1 ;
            }
        }
        int ans = 0 ;
        for(int i = 2 ; i < 30 ; i++)
            ans += vis[i]*fib[i-1] ;
        printf("%d\n",ans) ;
    }
    return 0 ;
}
