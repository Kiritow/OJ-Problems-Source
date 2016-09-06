#include<stdio.h>
#include<string.h>
int main()
{
    int a, i, c, n, cnt[105];
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        memset(cnt, 0, sizeof(cnt));
        int Max = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&a);
            cnt[a]++;
            if(a > Max)
                Max = a;
        }
        int ans = Max * 10;  
        for(i = 1; i <= Max; i++)
        {
            if(cnt[i])
                ans += 5 + cnt[i]; 
        }
        printf("%d\n",ans);
    }
    return 0;
}
