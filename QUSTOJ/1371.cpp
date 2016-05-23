#include <cstdio>
const int MAXN = 1024;
int p[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    int m;
    scanf("%d",&m);
    m=m%n;
    for(int i=n-m;i<n;i++)
    {
        printf("%d ",p[i]);
    }
    for(int i=0;i<n-m;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}
