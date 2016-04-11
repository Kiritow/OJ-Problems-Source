#include <cstdio>
int main()
{
    long long inc;
    scanf("%I64d",&inc);
    int step=0;
    while(inc>4)
    {
        long long a=inc/3+1;
        long long b=inc-2*a;
        inc=a<b?b:a;
        step++;
    }
    if(inc==2)
    {
        step++;
    }
    else if(inc==3)
    {
        step++;
    }
    else if(inc==4)
    {
        step+=2;
    }
    printf("%d\n",step);
    return 0;
}
