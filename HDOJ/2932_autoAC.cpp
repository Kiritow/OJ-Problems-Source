#include<cstdio>
#include<cstring>
const int maxn = 17;
const int MAXN = 100017;
int main()
{
    int n;
    int cas = 0;
    int a[maxn], b[maxn], c[maxn];
    while(scanf("%d",&n)&&n)
    {
        for(int i = 1; i <= n; i++)
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        int ans;
        int cont = 0;
        for(ans = 1; ans < MAXN; ans++)
        {
            cont = 0;
            for(int i = 1; i <= n; i++)
            {
                if(c[i] <= a[i])
                    cont++;
            }
            if(cont == n)   
                break;
            for(int i = 1; i <= n; i++)
            {
                if(c[i] == a[i]+b[i] || (c[i] == a[i] && cont > n-cont))
                {
                    c[i] = 0;
                }
                c[i]++;
            }
        }
        if(ans == MAXN)
            ans = -1;
        printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}
