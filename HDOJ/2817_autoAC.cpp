#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=200907;
int main()
{
    __int64 a1,a2,a3,q;
    int n,T;
    __int64 ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d%d",&a1,&a2,&a3,&n);
        if(a2-a1==a3-a2)
        {
            q=a2-a1;
            ans=(a1%M+(((n-1)%M)*(q%M))%M)%M;
        }
        else
        {
            q=(a2/a1)%M;
            long long temp=1;
            n--;
            a1=a1%M;
            while(n)
            {
                if(n&1)
                {
                    temp=temp*q;
                    temp%=M;
                }
                q=(q*q)%M;
                n/=2;
            }
            ans=(a1*temp)%M;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
