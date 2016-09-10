#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int INF=1<<30;
int n,m,t;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
    void set(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
    Point operator + (const Point &b) const
    {
        return Point(x+b.x, y+b.y);
    }
    Point operator - (const Point &b) const
    {
        return Point(x-b.x, y-b.y);
    }
    int operator ^(const Point &b) const
    {
        return x*b.y - y*b.x;
    }
};
struct Line
{
    Point s,e;
    int cover;
    Line(){}
    void set(Point _s, Point _e, int _c)
    {
        s=_s;
        e=_e;
        cover=_c;
    }
    bool operator < (const Line &b)
    {
        return cover < b.cover;
    }
};
Point point[5000];
int p_point = 0;
int map[70][70];
int min_ans = 14;
bool found = false;
void init()
{
    p_point=0;
    memset(map, 0, sizeof(map));
    min_ans = 14;
    found = false;
    return;
}
int gcd(int x, int y)
{
    if(x<y)
        swap(x,y);
    if(y==0)
        return x;
    if(x%y==0)
        return y;
    return gcd(y, x%y);
}
bool valid(Point p)
{
    return p.x >=0 && p.y >= 0 && p.x <=n && p.y <=m;
}
bool CheckLine(int p1, int p2, int &cover)
{
    Point now_vec = point[p2] - point[p1];
    if(gcd( abs(now_vec.x), abs(now_vec.y)) != 1)
        return false;
    int now_cover = 0;
    Point tmp = point[p1];
    tmp = tmp - now_vec;
    while(valid(tmp))
    {
        if(map[tmp.x][tmp.y] == 0)
            return false;
        else if(tmp.x <= point[p1].x)
            return false;
        now_cover ++;
        tmp = tmp - now_vec;
    }
    tmp = point[p2];
    tmp = tmp + now_vec;
    bool found_one = false;
    while(valid(tmp))
    {
        found_one = true;
        if(map[tmp.x][tmp.y] == 0)
            return false;
        now_cover++;
        tmp = tmp + now_vec;
    }
    if(!found_one)
        return false;
    cover = now_cover;
    return true;
}
void DetermineLines(Line line[], int &p_line)
{
    int i,j;
    for(i=1; i<=p_point -1;i++)
    {
        if(map[point[i].x][point[i].y] ==0)
            continue;
        for(j=i+1; j<=p_point; j++)
        {
            if(map[point[j].x][point[j].y]==0)
                continue;
            int cover;
            if( CheckLine(i,j, cover) )
            {
                line[++p_line].set(point[i], point[j], cover);
            }
        }
    }
    return;
}
void drop(Line l)
{
    Point p1 = l.s, p2 = l.e;
    Point now_vec = p2 - p1;
    Point tmp = p1;
    while(valid(tmp))
    {
        map[tmp.x][tmp.y] --;
        tmp = tmp - now_vec;
    }
    tmp = p2;
    while(valid(tmp))
    {
        map[tmp.x][tmp.y] --;
        tmp = tmp + now_vec;
    }
    return ;
}
void resume(Line l)
{
    Point p1 = l.s, p2 = l.e;
    Point now_vec = p2 - p1;
    Point tmp = p1;
    while(valid(tmp))
    {
        map[tmp.x][tmp.y]++;
        tmp = tmp - now_vec;
    }
    tmp = p2;
    while(valid(tmp))
    {
        map[tmp.x][tmp.y]++;
        tmp = tmp + now_vec;
    }
    return ;
}
bool cmp(const Line &a, const Line &b)
{
    return a.cover > b.cover;
}
bool check()
{
    int i;
    for(i=1; i<=p_point; i++)
    {
        if(map[point[i].x][point[i].y] != 0)
            return false;
    }
    return true;
}
void DFS(int depth)
{
    Line line[3000];
    int p_line = 0;
    DetermineLines(line, p_line);
    sort(line+1, line + p_line +1, cmp);
    if(check())
    {
        min_ans = depth-1;
        found = true;
        return ;
    }
    if(depth > min_ans)
        return;
    int i;
    for(i=1; i<=min(p_line,4);i++)
    {
        drop(line[i]);
        DFS(depth+1);
        if(found)
            break;
        resume(line[i]);
    }
    return ;
}
int main()
{
    scanf("%d", &t);
    int files;
    for(files=1; files<=t; files++)
    {
        init();
        scanf("%d %d", &n, &m);
        int i,j;
        for(i=0; i<=n; i++)
        {
            for(j=0; j<=m; j++)
            {
                scanf("%d", &map[i][j]);
                if(map[i][j]!=0)
                {
                    point[++p_point].set(i,j);
                }
            }
        }
        DFS(1);
        printf("%d\n", min_ans);
    }
    return 0;
}
