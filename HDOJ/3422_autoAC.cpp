#include <stdio.h>
int main()
{
    long long i,j,n;
    while(scanf("%I64d",&n)!=EOF)
    {
        printf("%I64d %I64d\n",4*n*n+6*n-1,2*n*n+2*n+1);
    }
    return 0;
}
