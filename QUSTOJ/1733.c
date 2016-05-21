#include <stdio.h>
//数据范围n<=10^18,m<=1000,时间几十ms
#define __int64 long long
__int64 N,M;
int main()
{
    scanf("%lld",&N);
    M=3;
    {
        __int64 f1 = 0;
        __int64 f2;
        __int64 X;
        if (M == 1)
        {
            printf("%lld\n",N);
        }
        else
        {
            for (__int64 i = 2; i <= N; ++ i)
            {
                if (f1 + M < i)//表示很有可能跳过X个i
                {
                    X = (i - f1) / M;//能跳过多少个
                    if (i + X < N)//如果没有跳过n，就是i<=N
                    {
                        i = i + X;//i直接到i+X
                        f2 = (f1 + X*M);//由于f1+X*M肯定<=i,所以这里不用%i
                        f1 = f2;
                    }
                    else//如果跳过了n,那么就不能直接加X了，而是只需要加(N-i)个M即可
                    {
                        f2 = f1+(N-i)*M;
                        f1 = f2;
                        i = N;
                    }
                }
                f2 = (f1 + M) % i;//如果f1+M>=i或者跳过上面的一些i之后还是要继续当前i对于的出列的人
                f1 = f2;
            }
        }
        printf("%lld\n",f2+1);
    }
    return 0;
}
