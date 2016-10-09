#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL a[100];

LL b[40];

int ans;

void Init()
{
    a[0] = 0;

    a[1] = 1; a[2] = 2;

    for(int i = 3;i<=47;i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
}

bool dfs(LL u,int st,int num)
{
    if(u == 0) 
    {
        ans = num;

        return true;
    }

    if(st == 0) return false;

    for(int i = st;i>=1;i--)
    {
        if(u >= a[i])
        {
            b[num] = a[i];

            if(dfs(u-a[i],i-1,num+1))
            {
                return true;    
            }
        }
    }
    return false;
}

int main()
{
    Init();

    int T;

    LL n;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%lld",&n);

        if(dfs(n,47,0))
        {
            printf("%lld=",n);

            for(int i = ans - 1;i >=0;i--)
            {
                if(i!=ans-1) printf("+");

                printf("%lld",b[i]);
            }
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}
