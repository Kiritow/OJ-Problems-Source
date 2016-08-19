#include<stdio.h>
#include<string.h>
#define large(a,b)(a>b?a:b)
#define INF 0x3f3f3f
#define max 1000+10
int map[max][max],start[max],end[max];
int n,s,d;
void floyd(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            if(map[k][i]==INF)
            continue;
            for(j=1;j<=n;j++)
            {
                if(map[i][j]>map[i][k]+map[k][j])
                map[i][j]=map[i][k]+map[k][j];
            }
        }
    }
}
int main()
{
    int i,j,x,y,c,m,time;
    while(scanf("%d%d%d",&n,&s,&d)!=EOF)
    {
        for(i=1;i<max;i++)
        {
            for(j=1;j<max;j++)
            {
                if(i==j)
                map[i][j]=0;
                else
                map[i][j]=INF;
            }
        }
        m=0;
        while(n--)
        {
            scanf("%d%d%d",&x,&y,&c);
            if(m<large(x,y))
            m=large(x,y);
            if(map[x][y]>c)
            map[x][y]=map[y][x]=c;
        }
        for(i=0;i<s;i++)
        scanf("%d",&start[i]);
        for(i=0;i<d;i++)
        scanf("%d",&end[i]);
        floyd(m);
        time=INF;
        for(i=0;i<s;i++)
        {
            for(j=0;j<d;j++)
            {
                if(time>map[start[i]][end[j]])
                time=map[start[i]][end[j]];
            }
        }
        printf("%d\n",time);
    }
    return 0;
}
