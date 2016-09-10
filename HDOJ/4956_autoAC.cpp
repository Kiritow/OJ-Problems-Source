#include <cstdio>
typedef __int64 LL;
bool Judge(LL tt)
{
    LL sumo = 0, sume = 0;
    LL i = -1;
    while(tt)
    {
        i++;
        LL t = tt%10;
        if(i%2)
            sumo += t;
        else
            sume += t;
        tt /= 10;
    }
    if(sume - sumo == 3)
        return true;
    return false;
}
int main()
{
    int T;
    LL l, r;
    LL i, j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&l,&r);
        for(i = l; ; i++)
        {
            if(i%11 == 3)
                break;
        }
        for(j = i; j <= r; j+=11)
        {
            if(!Judge(j))
                break;
        }
        if(j > r)
            printf("-1\n");
        else
            printf("%I64d\n",j);
    }
    return 0;
}
