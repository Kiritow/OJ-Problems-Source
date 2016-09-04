#include <cstdio>
#include <cstring>
const int MAXN = 2000 + 123;
int ap[MAXN], bp[MAXN], as[MAXN], bs[MAXN];
int f[MAXN][MAXN];
struct node
{
    int num, val;
}q[MAXN];
inline int min(int x,int y)
{
    return x<y?x:y;
}
inline int max(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int t, maxp, w;
        scanf("%d%d%d", &t, &maxp, &w);
        for(int i = 1; i <= t; i++) scanf("%d%d%d%d",&ap[i], &bp[i], &as[i], &bs[i]);
        memset(f, 200, sizeof(f));
        for(int i = 1; i <= w + 1; i++)
            for(int j = 0; j <= min(as[i], maxp); j++)
            {
                f[i][j] = -ap[i] * j;
            }
        for(int i = 2; i <= t; i++)
        {
            for(int j = 0; j <= maxp; j++)  f[i][j] = max(f[i][j], f[i-1][j]);
            if(i < w + 2) continue;
            int head = 0, tail = -1;
            q[++tail].num = 0;
            q[tail].val = f[i - w - 1][0];
            for(int j = 1; j <= maxp; j++)
            {
                while(tail >= head && j - q[head].num > as[i]) head++;
                if(head <= tail) f[i][j] = max(f[i][j], q[head].val - (j - q[head].num) * ap[i]);
                while(tail >= head && q[tail].val + (q[tail].num - j) * ap[i] < f[i - w - 1][j]) tail--;
                q[++tail].num = j;
                q[tail].val = f[i- w - 1][j];
            }
            head = 0, tail = -1;
            q[++tail].num = maxp;
            q[tail].val = f[i - w - 1][maxp];
            for(int j = maxp - 1; j >= 0; j--)
            {
                while(tail >= head && q[head].num - j > bs[i])  head++;
                if(head <= tail)  f[i][j] = max(f[i][j], q[head].val + (q[head].num - j) * bp[i]);
                while(tail >= head && q[tail].val + (q[tail].num - j) * bp[i] < f[i - w - 1][j]) tail--;
                q[++tail].num = j;
                q[tail].val = f[i - w - 1][j];
            }
        }
        int rmax = 0;
        for(int i = 0; i <= maxp; i++)
        if(f[t][i] > rmax) rmax = f[t][i];
        printf("%d\n", rmax);
    }
    return 0;
}
