#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    long long  a;
    while(T--)
    {
        scanf("%I64d",&a);
        double temp=ceil((1+sqrt(1+4*a))/2)-1;
        long long n=(long long)temp;
        long long res1=n+a;
        long long res2=n*(n+1)*(2*n+1)/3-3*(n+1)*n/2+n+(n+a-n*n+1)*n;
        printf("%I64d %I64d\n",res1,res2);
    }
    return 0;
}
