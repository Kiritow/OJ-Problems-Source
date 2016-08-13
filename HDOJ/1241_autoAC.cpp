#include<stdio.h>
#include<string.h>
char map[110][110];
int move[8][2]={1,0,-1,0,0,1,0,-1,1,1,-1,-1,1,-1,-1,1};
int h,w;
void dfs(int x,int y)
{
    int next_x,next_y,i;
    map[x][y]='*';
    for(i=0;i<8;i++)
    {
        next_x=x+move[i][0];
        next_y=y+move[i][1];
        if(next_x>=0&&next_x<h&&next_y>=0&&next_y<w)
        {
            if(map[next_x][next_y]=='@')
            {
                dfs(next_x,next_y);
            }
        }
    }
}
int main()
{
    int i,j,sum;
    while(scanf("%d%d",&h,&w)&&(h!=0||w!=0))
    {
        for(i=0;i<h;i++)
        scanf("%s",map[i]);
        sum=0;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                if(map[i][j]=='@')
                {
                    dfs(i,j);
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
