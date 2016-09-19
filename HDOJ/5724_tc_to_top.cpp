#include <cstdio>
#include <cstring>
int const MAX = 21;
int sg[1 << MAX], vis[MAX]; 

int get_sg(int sta)
{
    memset(vis, false, sizeof(vis));
    for(int i = 20; i >= 0; i--)
    {
        if(sta & (1 << i))
        {
            int tmp = sta;
            for(int j = i - 1; j >= 0; j--)
            {
                if(!(sta & (1 << j)))
                {
                    tmp ^= ((1 << i) ^ (1 << j));
                    vis[sg[tmp]] = true;
                    break;
                }
            }
        }
    }
    for(int i = 0; i <= 20; i++)
        if(!vis[i])
            return i;
    return 0;
}

int main()
{
    memset(sg, 0, sizeof(sg));
    for(int i = 0; i < (1 << 20); i++)
        sg[i] = get_sg(i);
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m, p, ans = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            int sta = 0;
            while(m --)
            {
                scanf("%d", &p);
                sta |= (1 << (20 - p));
            }
            ans ^= sg[sta];
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
}
