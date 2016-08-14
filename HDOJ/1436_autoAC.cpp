#include <cstdio>
#include <cstring>
#define MAXN 1001
__int64 com[MAXN][MAXN];
void get_Combination(int n)
{
    int i, j;
    memset(com, 0, sizeof(com));
    com[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        com[i][0] = 1;
        for (j = 1; j <= i; j++) com[i][j] = com[i-1][j-1] + com[i-1][j];
    }
}
int n, m, dlen;
__int64 d[MAXN];
__int64 p1[MAXN], p2[MAXN];
int main()
{
    int i, j, k;
    get_Combination(MAXN);
    while (~scanf("%d %d", &n, &m))
    {
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        for (i = 0; i < n; i++)
        {
            scanf("%d", &dlen);
            for (j = 0; j < dlen; j++) scanf("%I64d", &d[j]);            
            if (i == 0)
            {
                for (j = 0; j < dlen; j++)
                {
                    if (d[j] > m) continue;
                    p1[d[j]] = com[m][d[j]];        
                }
                continue;
            }
            for (j = m; j >= 0; j--)
                if (p1[j] != 0)
                {
                    for (k = 0; k < dlen; k++)
                    {
                        if (j + d[k] > m) break;     
                        p2[j+d[k]] += com[m-j][d[k]] * p1[j];
                    }
                    p2[j] = p1[j];
                }
            for (j = 0; j <= m; j++)
            {
                p1[j] = p2[j];
                p2[j] = 0;
            }
        }
        printf("%I64d\n", p1[m]);
    }
    return 0;
}
