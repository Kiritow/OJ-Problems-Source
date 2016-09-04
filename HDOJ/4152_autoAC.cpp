# include <cstdio>
# include <cstring>
int d[20]= {1},a[22][22],c[22],fn[22],n,m;
int yes()
{
    for (int i(1); i<=n; i++)
    {
        if (c[i]<fn[i]) return 0;
    }
    return 1;
}
int main()
{
    for (int i(1); i<=18; i++) d[i]=d[i-1]*2;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i(1); i<=n; i++) scanf("%d",&fn[i]);
        scanf("%d",&m);
        for (int i(1); i<=m; i++)
        {
            for (int j(1); j<=n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int ans=0,ansi=0;
        for (int i(d[m+1]-1); i>=0; i--)
        {
            memset(c,0,sizeof(c));
            int num = 0;
            for (int j(1); j<=m; j++)
            {
                if (i&d[j-1])
                {
                    num++;
                    for (int k(1); k<=n; k++) c[k] += a[j][k];
                }
            }
            if (yes() && num >= ans)
            {
                ans = num;
                ansi = i;
            }
        }
        printf("%d",ans);
        for (int i(0); i<m; i++)
        {
            if (ansi & d[i]) printf(" %d",i+1);
        }
        printf("\n");
    }
    return 0;
}
