#include <cstdio>
int main()
{
    int n;
    scanf("%d",&n);
    int f=0;
    int m=3;
    for(int i=1;i<=n;i++)
    {
        f=(f+m)%i;
    }
    printf("%d\n",f+1);
    return 0;
}
