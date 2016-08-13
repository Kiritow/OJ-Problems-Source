#include<stdio.h>
#include<string.h>
int a[1003];
void ice(int x,int y)
{
    a[x]=y;
}
int find(int x)
{
    if(x!=a[x])
        a[x]=find(a[x]);
        return a[x];
}
int main()
{
    int t,n,m,i,j,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        j=0;
        for(i=1;i<=n;i++)
            a[i]=i;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            x=find(x);
            y=find(y);
            ice(x,y);
        }
        for(i=1;i<=n;i++)
        if(a[i]==i)
            j++;
            printf("%d\n",j);
    }
    return 0;
}
