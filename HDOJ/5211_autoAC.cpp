#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAXN 10005
int num[MAXN],n,f[MAXN];
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        int ans = 0;
        memset(f,0,sizeof(f));
        for(int i = 0;i < n;i++)
            scanf("%d",&num[i]);
        for(int i = n - 1;i >= 0;i--)
        {
            ans += f[num[i]];
            int q = sqrt(num[i] + 1) + 1;
            for(int j = 1;j <= q && j <= num[i];j++)
                if(num[i] % j == 0)
                    f[j] = i + 1,
                    f[num[i] / j] = i + 1;
        }
        printf("%d\n",ans);
    }
}
