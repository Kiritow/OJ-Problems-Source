#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define N 1001
using namespace std;
int fx[8][2] = { 0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1 }, n, m, sx, sy, ex, ey, tp, tb;  
struct Map
{
    int cb;
    int path;
    int x;
    int y;
    char c;
    friend   bool operator<(Map t1, Map t2)   
    {
        if (t1.cb == t2.cb)
        {
            return t1.path>t2.path;
        }
        return t1.cb>t2.cb;
    }
};
Map map[N][N];
void input()
{
    int i, j, k;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);   
    for (i = 1; i <= n; i++)                 
    {
        getchar();
        for (j = 1; j <= m; j++)
        {
            map[i][j].c = getchar();
            map[i][j].path = -1;           
        }
    }
}
bool isvalide(int x, int y)         
{
    if (x<1 || x>n || y<1 || y>m || map[x][y].c == '0')  
        return false;
    return true;
}
void BFS()
{
    int i, j, k;
    priority_queue<Map> qu;
    Map t1, t2;
    int tx, ty;
    map[sx][sy].path = 0;        
    map[sx][sy].cb = 0;
    t1 = map[sx][sy];
    t1.x = sx;
    t1.y = sy;
    qu.push(t1);
    while (!qu.empty())
    {
        t2 = qu.top();
        if (t2.cb>tb || (t2.cb == tb&&t2.path >= tp))        
            return;
        qu.pop();
        for (i = 0; i<8; i++)
        {
            tx = t2.x + fx[i][0];            
            ty = t2.y + fx[i][1];
            if (isvalide(tx, ty))
            {
                if (map[tx][ty].path != -1)      
                {
                    if (map[tx][ty].c != t2.c)      
                    {
                        if (map[tx][ty].cb<t2.cb + 1 || (map[tx][ty].cb == t2.cb + 1 && map[tx][ty].path <= t2.path + 1))
                            continue;                              
                        map[tx][ty].cb = t2.cb + 1;                
                        map[tx][ty].path = t2.path + 1;
                    }
                    else                            
                    {
                        if (map[tx][ty].cb<t2.cb || (map[tx][ty].cb == t2.cb&&map[tx][ty].path <= t2.path + 1))  
                            continue;                   
                        map[tx][ty].cb = t2.cb;         
                        map[tx][ty].path = t2.path + 1;
                    }
                }
                else   
                {
                    if (map[tx][ty].c != t2.c)        
                    {
                        map[tx][ty].cb = t2.cb + 1;
                        map[tx][ty].path = t2.path + 1;
                    }
                    else                              
                    {
                        map[tx][ty].cb = t2.cb;
                        map[tx][ty].path = t2.path + 1;
                    }
                }
                t1 = map[tx][ty];
                t1.x = tx;
                t1.y = ty;
                if (tx == ex&&ey == ty)        
                {
                    if (t1.cb<tb)
                    {
                        tb = t1.cb;
                        tp = t1.path;
                    }
                    else if (t1.cb == tb&&t1.path<tp)
                    {
                        tp = t1.path;
                    }
                    continue;
                }
                qu.push(t1);      
            }
        }
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        input();
        tb = tp = 100000;       
        BFS();
        printf("%d %d\n", tp + 1, tb);
    }
}
