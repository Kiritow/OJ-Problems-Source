#include<stdio.h>
#include<string.h>
int main()
{
    int s,n,m,x,y,i,j,count,sum=1;
    char str[1001][1001];
    int a[1001],b[1001];
    scanf("%d",&s);
    while(s--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        count=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            x--,y--;
            a[x]=1-a[x];
            b[y]=1-b[y];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[i]+b[j]==1)
                {
                    if(str[i][j]=='b') count++;
                }
                else
                {
                    if(str[i][j]=='w') count++;
                }
            }
        }
        printf("Case #%d: %d\n",sum++,count);
    }
    return 0;
}
