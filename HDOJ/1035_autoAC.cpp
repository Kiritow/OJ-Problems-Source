#include <stdio.h>
int maze[11][11];
int r,c,b;
int idx;
void step(int x,int y)
{
    int t;
    if(x<0||x>=r||y<0||y>=c)
    {
        printf("%d step(s) to exit\n",idx-999);
        return;
    }
    if(maze[x][y]>=1000)
    {
        printf("%d step(s) before a loop of %d step(s)\n",maze[x][y]-1000,idx-maze[x][y]+1);
        return;
    }
    t=maze[x][y];
    idx++;
    maze[x][y]=idx;
    switch (t)
    {
    case 'N':
        step(x-1,y);
        break;
    case 'S':
        step(x+1,y);
        break;
    case 'E':
        step(x,y+1);
        break;
    case 'W':
        step(x,y-1);
        break;
    }
}
int main()
{
    int i,j;
    while (scanf("%d%d",&r,&c),r||c)
    {
        scanf("%d",&b);
        getchar();
        for (i=0;i<r;i++)
        {
            for (j=0;j<c;j++)
                maze[i][j]=getchar();
            getchar();
        }
        idx=999;
        step(0,b-1);
    }
    return 0;
}
