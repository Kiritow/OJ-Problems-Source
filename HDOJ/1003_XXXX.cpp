#include <cstdio>
using namespace std;
#define MAXN 100005

typedef struct{ int s, l, r; }Sum;

Sum MaxSub(int a[], int n);

int main(void)
{
    int ar[MAXN], c, n, i, j;
    Sum x = {0, 0, 0};
    scanf("%d", &c);
    for(i = 1; i <= c; i++)
    {
        scanf("%d", &n);
        for(j = 1; j <= n; j++)
            scanf("%d", &ar[j]);
        x = MaxSub(ar, n);
        printf("Case %d:\n%d %d %d", i,x.s, x.l, x.r);
        if(i != c) printf("\n\n");
        else printf("\n");
    }
}

Sum MaxSub(int a[], int n)
{
    int i, s = 0, l = 1, r = 1, b;
    Sum sum = {a[1], 0, 0};
    for(i = 1; i <= n; i++)
    {
        if(s >= 0)
        {
            s += a[i];
            if(a[i] > 0) r = i;
        }
        else
        {
            s = a[i];
            r = l = i;
        }
        if(s >= sum.s)
        {
            sum.s = s;
            sum.l = l;
            sum.r = r;
        }
    }
    return sum;
}
