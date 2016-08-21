#include <cstdio>
int main()
{
    __int64 sum,n,k;
    while(~scanf("%I64d",&n),(n>=0))
    {
        k=n/3;
        if(n%3==0)
        {
            if(k&1)
                sum=((1+k)>>1)*((1+k)>>1)*k*k*27+3*k*k;
            else
                sum=(k>>1)*(k>>1)*(1+k)*(1+k)*27+3*k*k;
        }
        if(n%3==1)
        {
            if(k&1)
                sum=((1+k)>>1)*((1+k)>>1)*k*k*27+n+3*k*k;
            else
                sum=(k>>1)*(k>>1)*(1+k)*(1+k)*27+n+3*k*k;
        }
        if(n%3==2)
        {
            if(k&1)
                sum=((1+k)>>1)*((1+k)>>1)*k*k*27+n+n-1+3*k*k;
            else
                sum=(k>>1)*(k>>1)*(1+k)*(1+k)*27+n+n-1+3*k*k;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
