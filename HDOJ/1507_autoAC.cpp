#include <stdio.h>
#include <string.h>
int map[105][105];
int m,n,max;
int x_la[50],y_la[50];
int x_temp[50],y_temp[50];
int can_move(int x,int y)
{
    if(x>0&&x<=n&&y>0&&y<=m)
    {
        return 1;
    }
    return 0;
}
void DFS(int x,int y,int num)
{
    int i,j,k;
    if(num>max)
    {
        max=num;
        for(i=0;i<num*2;i++)
        {
            x_la[i]=x_temp[i];
            y_la[i]=y_temp[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(map[i][j]==0)
            {
                for(k=1;k<3;k++)
                {
                    if(k==1)
                    {
                        if(can_move(i+1,j)&&map[i+1][j]==0)
                        {
                            map[i][j]=1;
                            map[i+1][j]=1;
                            x_temp[num*2]=i;
                            y_temp[num*2]=j;
                            x_temp[num*2+1]=i+1;
                            y_temp[num*2+1]=j;
                            DFS(i,j,num+1);
                        }
                    }
                    else
                    {
                        if(can_move(i,j+1)&&map[i][j+1]==0)
                        {
                            map[i][j]=1;
                            map[i][j+1]=1;
                            x_temp[num*2]=i;
                            y_temp[num*2]=j;
                            x_temp[num*2+1]=i;
                            y_temp[num*2+1]=j+1;
                            DFS(i,j,num+1);
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    int t;
    int a,b,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        memset(map,0,sizeof(map));
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        max=0;
        DFS(1,1,0);
        printf("%d\n",max);
        for(i=0;i<max;i++)
        {
            printf("(%d,%d)--(%d,%d)\n",x_la[i*2],y_la[i*2],x_la[i*2+1],y_la[i*2+1]);
        }
    }
    return 0;
}
