#include <stdio.h>
char maze[6][6];
int num,result;
bool placeable(int row,int col)
{
    int i;
    i=col-1;
    while(i>=0&&maze[row][i]!='X')
        if(maze[row][i--]=='*') return false;
    i=row-1;
    while(i>=0&&maze[i][col]!='X')
        if(maze[i--][col]=='*') return false;
    return true;
}
void dfs(int cnt,int max)
{
    int row,col;
    if(cnt==num*num)
    {
        max>result?result=max:1;
        return;
    }
    else
    {
        row=cnt/num;
        col=cnt%num;
        if(maze[row][col]=='.'&&placeable(row,col))
        {
            maze[row][col]='*';
            dfs(cnt+1,max+1);
            maze[row][col]='.';
        }
        dfs(cnt+1,max);
    }
}
int main()
{
    while(scanf("%d",&num)!=EOF&&num)
    {
        for(int i=0;i<num;i++)
            scanf("%s",maze[i]);
        result=0;
        dfs(0,0);
        printf("%d\n",result);
    }
    return 0;
}
