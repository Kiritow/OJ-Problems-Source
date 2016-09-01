#include <stdio.h>
#include <string.h>
int a[10002];
int dg(long n)
{
    if(n==1||n==2||n==0)
      return 0;
    if(n%2==0)
        return dg(n/2)*2;
    else
        return dg(n/2)+dg(n-n/2)+1;
}
int main(int argc, char* argv[])
{
    int n;
    int i;
    long num;
    scanf("%d", &n);    
    memset(a,-1, sizeof(a));
    a[0]=a[1]=a[2]= 0;
    for (i = 0; i < n; i++)
    {
        scanf("%ld", &num);
        printf("%ld\n", dg(num));
    }
    return 0;
}
