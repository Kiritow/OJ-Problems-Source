#include<stdio.h>
#include<string.h>
#define INF 0x3f3f3f
#define max 150+10
int visit[max],map[max][max],dist[max];
char str[max][max];
int n;
void dijkstra()
{
}
int main()
{
    int i,j,next,mindist;
    int t,x,y,c;
    char s[30],e[30];
    while(scanf("%d",&n)&&(n!=-1))
    {
        for(i=1;i<150;i++)
        {
            for(j=1;j<150;j++)
            {
                if(i==j)
                map[i][j]=0;
                else
                map[i][j]=INF;
            }
        }
        scanf("%s %s",s,e);
        strcpy(str[1],s);
        strcpy(str[2],e);
        t=2;
        for(j=1;j<=n;j++)
        {
            scanf("%s %s %d",s,e,&c);
            for(i=1,x=max,y=max;i<=t;i++)
            {
                if(strcmp(str[i],s)==0&&x==max)
                x=i;
                if(strcmp(str[i],e)==0&&y==max)
                y=i;
                if(x!=max&&y!=max)
                break;
            } 
            if(x==max)
            {
                t++;
                x=t;
                strcpy(str[x],s);
            }
            if(y==max)
            {
                t++;
                y=t;
                strcpy(str[y],e);
            }
            if(map[x][y]>c)
            map[x][y]=map[y][x]=c;
        }
        if(strcmp(str[1],str[2])==0)
        {
            printf("0\n");
            continue;
        }
        for(i=1;i<150;i++)
        {
            visit[i]=0;
            dist[i]=map[1][i];
        }
        visit[1]=1;
        for(i=2;i<=t;i++)
        {
            mindist=INF;
            for(j=1;j<=t;j++)
            {
                if(!visit[j]&&mindist>dist[j])
                {
                    mindist=dist[j];
                    next=j;
                }
            }
            visit[next]=1;
            for(j=1;j<=t;j++)
            {
                if(!visit[j]&&dist[next]+map[next][j]<dist[j])
                {
                    dist[j]=dist[next]+map[next][j];
                }
            }
        }
        if(dist[2]==INF)
        printf("-1\n");
        else
        printf("%d\n",dist[2]);
    }
    return 0;
}
