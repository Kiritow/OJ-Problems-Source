#include <iostream>
using namespace std ;
int main()
{
    int n ;
    while(~scanf("%d",&n))
    {
        double ans=1 ;
        for(int i=n-1;i>=2;i-=2)
            ans*=(i-1)*1.0/i ;
        printf("%.5lf\n",ans) ;
    }
    return 0 ;
}
