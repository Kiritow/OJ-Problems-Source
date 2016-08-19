#include <cstdio>
#include <cmath>
int a[47];
void reserve (int pos)
{
    int tt;
    for(int i = 1, j = pos; i < j; i++,j--)
    {
        tt = a[i],a[i] = a[j],a[j] = tt;
    }
    for(int i = 1; i <= pos; i++)
    {
        a[i] = -a[i];
    }
}
int main()
{
    int t;
    int n;
    int cas = 0;
    int b[147];
    scanf("%d",&t);
    while(t--)
    {
        int k = 0;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        int p = 0;
        for(int i = n; i >= 1; i--)
        {
            if(a[i] == i)
                continue;
            for(int j = 1; j <= n; j++)
            {
                if(fabs(a[j]) == i)
                {
                    p = j;
                }
            }
            if(p != 1)
            {
                reserve(p);
                b[k++] = p;
            }
            if(a[1] > 0)
            {
                a[1] = -a[1];
                b[k++] = 1;
            }
            if(i != 1)
            {
                b[k++] = i;
                reserve(i);
            }
            else
            {
                b[k++] = 1;
                a[1] = -a[1];
            }
        }
        printf("%d %d",++cas,k);
        for(int i = 0; i < k; i++)
        {
            printf(" %d",b[i]);
        }
        printf("\n");
    }
    return 0;
}
