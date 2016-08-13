# include<stdio.h>
# include<string.h>
int map[1100][1100],vist[1100][1100],move[4][2]={1,0,0,1,-1,0,0,-1};
int a,b,c,d,flag;
void dfs(int x,int y,int t,int p)
{
    int i,x1,y1;
    if(t>3)return;
    if(x==c&&y==d)
    {
        flag=1;return;
    }
    vist[x][y]=1;
    if(t!=0)
    {
        if(map[x][y]!=0)return;
        for(i=0;i<4&&!flag;i++)
        {
            x1=x+move[i][0];
            y1=y+move[i][1];
            if(vist[x1][y1]==1)continue;
            if(p==i)
                dfs(x1,y1,t,p);
            else
                dfs(x1,y1,t+1,i);
            vist[x1][y1]=0;
        }
    }
    else
        for(i=0;i<4&&!flag;i++)
        {
            x1=x+move[i][0];
            y1=y+move[i][1];
            if(vist[x1][y1]==1)continue;
            dfs(x1,y1,t+1,i);
            vist[x1][y1]=0;
        }
}
int main()
{
    int n,m,i,j,t;
    while(scanf("%d%d",&n,&m),n&&m)
    {
        memset(map,1,sizeof(map));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        scanf("%d",&t);
        while(t--)
        {
            flag=0;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(map[a][b]!=map[c][d] || map[a][b]==0 || a<1||c<1||b<1||d<1||a>n||c>n||b>m||d>m)
                printf("NO\n");
            else
            {
                memset(vist,0,sizeof(vist));
                dfs(a,b,0,-1);
                if(flag)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}
