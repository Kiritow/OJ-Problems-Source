#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum[32], re, num;
int main()
{
    int ca, n, k, i, j, po;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d%d", &n, &k);
        memset(sum, 0, sizeof(sum));
        for(i=0; i<n; i++)
        {
            scanf("%d", &num);
            po=0;
            while(num)
            {
                sum[po++]+=num&1;
                num>>=1;
            }
        }
        re=0;
        for(i=0; i<32; i++)
            re+=(sum[i]%(k+1));
        puts(re==0?"Li wins":"Fernandes wins");
    }
    return 0;
}
