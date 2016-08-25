#include<stdio.h>
#include<string.h>
int X, K;
struct Integer
{
    int a[32];
    void init(int x)
    {
        int i;
        for(i = 0; i < 32; i ++)
        {
            a[i] = x % 2;
            x /= 2;
        }
    }
    void getnext()
    {
        int i, j, cnt = 0;
        for(i = 0;; i ++)
            if(a[i] == 1)
            {
                if(a[i + 1] == 0)
                {
                    a[i + 1] = 1;
                    for(j = 0; j <= i; j ++)
                    {
                        if(cnt)
                            -- cnt, a[j] = 1;
                        else
                            a[j] = 0;
                    }
                    break;
                }
                ++ cnt;
            }
    }
}integer;
void solve()
{
    int i;
    long long int ans = 0;
    integer.init(X);
    for(i = 0; i < K; i ++)
        integer.getnext();
    for(i = 31; i >= 0; i --)
        ans = ans * 2 + integer.a[i];
    printf("%I64d\n", ans);
}
int main()
{
    for(;;)
    {
        scanf("%d%d", &X, &K);
        if(!X && !K)
            break;
        solve();
    }
    return 0;
}
