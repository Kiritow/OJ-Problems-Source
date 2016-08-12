#include<stdio.h>
#include<math.h>
int time,atx,aty,n,m;
char map[26][26];
bool flag;
void dfs(int x,int y,int t)
{
    if(x<0||x>=n||y<0||y>=m)
        return;
    if(flag==true||(t==0&&x==atx&&aty==y))
    {
        flag=true;
        return;
    }
    int temp=t-abs(x-atx)-abs(y-aty); 
    if(temp<0 || temp&1)
        return;
    map[x][y]='X';
    if(map[x+1][y]!='X')
    {
        dfs(x+1,y,t-1);
        if(flag)
           return;
    }
    if(map[x][y+1]!='X')
    {
        dfs(x,y+1,t-1);
        if(flag)
            return;
    }
    if(map[x-1][y]!='X')
    {
        dfs(x-1,y,t-1);
        if(flag)
            return;
    }
    if(map[x][y-1]!='X')
    {
        dfs(x,y-1,t-1);
        if(flag)
            return;
    }
    map[x][y]='.';
}
int main()
{
    int i,j,x,y,wall;
    while(scanf("%d%d%d",&n,&m,&time)&&(n!=0||m!=0||time!=0))
    {
        flag=false;
        wall=0;
        for(i=0;i<n;++i)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;++j)
            {
                if(map[i][j]=='S')
                {
                    x=i;
                    y=j;
                }
                if(map[i][j]=='D')
                {
                    atx=i;
                    aty=j;
                }
                if(map[i][j]=='X')
                    wall++;
            }
        }
        dfs(x,y,time);
        if(n*m-wall<=time)
        {
            printf("NO\n");
            continue;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
