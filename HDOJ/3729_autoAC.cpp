#include<stdio.h>
#include<string.h>
#define N 100005
int mark[N],link[N];
struct node
{
    int x,y;
}a[105];
int ss[105];
int n;
int dfs(int t)
{
    int i;
    for(i=a[t].x;i<=a[t].y;i++)
    {
        if(mark[i]==-1)
        {
            mark[i]=1;
            if(link[i]==-1||dfs(link[i]))
            {
                link[i]=t;
                ss[t]=1;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int i;
        for(i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        memset(link,-1,sizeof(link));
        memset(ss,0,sizeof(ss));
        int sum;
        sum=0;
        for(i=n;i>=1;i--)
        {
            memset(mark,-1,sizeof(mark));
            if(dfs(i))
                sum++;
        }
        printf("%d\n",sum);
        for(i=1;i<=n-1;i++)
        {
            if(ss[i]==1)
                printf("%d ",i);
        }
        printf("%d\n",i);
    }
    return 0;
}
