#include<stdio.h>
#include<cstdio>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
struct Map
{
    int map[6][6];
}star;
struct P
{
    int x, y;
};
int n, m, ans;
int di[4][2] = {0,1, -1,0, 0,-1, 1,0};
int check(struct Map &node)
{
    int i, j;
    for( i = 0 ; i < n ; i++)
        for( j = 0 ; j < m ; j++)
            if( node.map[i][j] != 0)
                return 0;
    return 1;
}
int print( struct Map node)
{
    int i, j;
    printf("\n");
    for( i = 0 ; i < n ; i++)
    {
        for( j = 0 ; j < m ; j++)
            printf("%d ", node.map[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}
int moveh(struct Map &node)
{
    int i, j, flog, flog2, b;
    flog2 = 0;
    for( j = 0 ; j < m ; j++)
    {
        flog = 0;
        for( i = 0 ; i < n ; i++)
            if(node.map[i][j] != 0)
                flog = 1;
        if( flog == 1 && flog2 == 1)
        {   
            for( i = 0 ; i < n ; i++)
                node.map[i][b] = node.map[i][j];
            for( i = 0 ; i < n ; i++)
                node.map[i][j] = 0;
            b++;
        }else if( flog == 0 && flog2 == 0)
        {
            flog2 = 1;
            b = j;
        }
    }
    return 0;
}
int moves(int s, struct Map &node)
{
    int i, j, flog, b;
    flog = 0;
    for( i = n - 1 ; i >= 0 ; i--)
    {
        if( node.map[i][s] == 0 && flog == 0)
        {
            b = i;
            flog = 1;
        }
        else if( node.map[i][s] != 0 && flog == 1)
        {
            node.map[b][s] = node.map[i][s];
            node.map[i][s] = 0;
            b--;
        }
    }
    return 0;
}
int movemap( struct Map &node)
{
    int i;
    for( i = 0 ; i < m ; i++)
        moves(i, node);
    moveh(node);
    return 0;
}
int change_map(struct Map &node, int mark[][6], int x, int y)
{
    int i, j, l, num, flog;
    queue<struct P> Q;
    struct P per, next;
    per.x = x;
    per.y = y;
    num = node.map[x][y];
    mark[x][y] = true;
    Q.push(per);
    while(!Q.empty())
    {
        per = Q.front();
        Q.pop();
        if( node.map[per.x][per.y] == 0)
                continue;
        node.map[per.x][per.y] = 0;
        for(l = 0 ; l < 4 ; l++)
        {
            i = per.x + di[l][0];
            j = per.y + di[l][1];
            if( i < 0 || j < 0 || i >= n || j >= m)
                continue;
            next.x = i;
            next.y = j;
            if( node.map[i][j] == num)
            {
                Q.push(next);
                mark[i][j] = true;
            }
        }
    }
    return 0;
}
int r_map(struct Map &a, struct Map &s)
{
    int i, j;
    for( i = 0 ; i < n ; i++) 
        for( j = 0 ; j < m ; j++)
            a.map[i][j] = s.map[i][j];
    return 0;
}
int DFS(int k,  struct Map per)
{
    int i, j;
    int mark[6][6];
    struct Map temp;
    memset(mark, 0, sizeof(mark));
    if( check(per) == 1)
    {
        if( k < ans)
            ans = k;
        return 0;
    }
    for( i = 0 ; i < n ; i++)
    {
        for( j = 0 ; j < m ; j++)
        {
            if( per.map[i][j] == 0)
                continue;
            if( mark[i][j] == 0)
            {
                mark[i][j] = 1;
                r_map( temp, per);
                change_map(per, mark, i, j);
                 movemap(per);
                DFS(k + 1, per);
                r_map(per, temp);
            }
        }
    }
    return 0;
}
int input()
{
    int i, j;
    for( i = 0 ; i < n ; i++)
        for( j = 0 ; j < m ; j++)
            scanf("%d", &star.map[i][j]);
    return 0;
}
int main()
{
    int i, j;
    while(scanf("%d%d", &n, &m) == 2)
    {
        input();
        ans = 65;
        DFS(0, star);
        printf("%d\n", ans);
    }
    return 0;
}
