#include <stdio.h>
#include <math.h>
#include <string.h>
const int MAXN=10030;
int a[MAXN];
int main(int argc, char *argv[])
{
    long n;
    while(scanf("%ld",&n) && n)
    {
        int count=1;
        memset(a,0,sizeof(a));
        a[n]=1; 
        while(1)
        {
            long t=n*n/100; 
            n=t%10000;
            a[n]++;
               if(a[n]==2) break;
               count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
