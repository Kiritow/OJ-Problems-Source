#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define maxn 31
bool mat[maxn][maxn][maxn];
struct point
{
    short x,y,z,rot,dir,step;
    point(){}
    point(int a,int b,int c,int d,int e):x(a),y(b),z(c),rot(d),dir(e){}
    bool operator ==(const point q)
    {
        return x == q.x && y == q.y && z == q.z && rot == q.rot && dir == q.dir;
    }
}ST,EN;
int n;
char opt[10] = {0,'F','L','R','U','D','B'};
point pre[maxn][maxn][maxn][7][7];
short step[maxn][maxn][maxn][7][7];
int dis[maxn][maxn][maxn][7][7];
int LEFT[7][7] = 
{
    0,0,0,0,0,0,0,
    0,0,3,5,0,6,2,
    0,6,0,1,3,0,4,
    0,2,4,0,5,1,0,
    0,0,6,2,0,3,5,
    0,3,0,4,6,0,1,
    0,5,1,0,2,4,0
};
int RIGHT[7][7] = 
{
    0,0,0,0,0,0,0,
    0,0,6,2,0,3,5,
    0,3,0,4,6,0,1,
    0,5,1,0,2,4,0,
    0,0,3,5,0,6,2,
    0,6,0,1,3,0,4,
    0,2,4,0,5,1,0
};
int dx[7] = {0,1,0,0,-1,0,0};
int dy[7] = {0,0,1,0,0,-1,0};
int dz[7] = {0,0,0,1,0,0,-1};
int back[7] = { 0,4,5,6,1,2,3 };
char record[maxn * maxn * maxn * 10 * 10];
bool check(point p)
{
    int x = p.x,y = p.y,z = p.z;
    return (1 <= x && x <= n) && (1 <= y && y <= n) && (1 <= z && z <= n) && !mat[x][y][z];
}
queue <point> Q;
void bfs()
{
    while(!Q.empty())
        Q.pop();
    int x = ST.x,y = ST.y,z = ST.z,rot = ST.rot,dir = ST.dir;
    if(!check(ST))
        return ;
    dis[x][y][z][rot][dir] = 0;
    if(ST == EN)
        return ;
    pre[x][y][z][rot][dir] = ST;
    ST.step = 0;
    Q.push(ST);
    while(!Q.empty())
    {
        point now = Q.front();
        Q.pop();
        for(int i = 1;i <= 6;i++)
        {
            if(i == 1)
            {
                rot = now.rot;
                dir = now.dir;
                x = now.x + dx[now.dir];
                y = now.y + dy[now.dir];
                z = now.z + dz[now.dir];
            }
            else
            {
                if(i == 2)
                {
                    rot = now.rot;
                    dir = LEFT[now.rot][now.dir];
                }
                else if(i == 3)
                {
                    rot = now.rot;
                    dir = RIGHT[now.rot][now.dir];
                }
                else if(i == 4)
                {
                    rot = back[now.dir];
                    dir = now.rot;
                }
                else if(i == 5)
                {
                    rot = now.dir;
                    dir = back[now.rot];
                }
                else
                {
                    rot = now.rot;
                    dir = back[now.dir];
                }
                x = now.x;
                y = now.y;
                z = now.z;
            }
            if(check(point(x,y,z,rot,dir)) && dis[x][y][z][rot][dir] > now.step + 1)
            {
                dis[x][y][z][rot][dir] = now.step + 1;
                pre[x][y][z][rot][dir] = now;
                step[x][y][z][rot][dir] = i;
                point haha(x,y,z,rot,dir);
                haha.step = now.step + 1;
                Q.push(haha);
            }
        }
    }
}
void come(int temp)
{
    record[temp + 1] = 0;
    point rc = EN;
    while(!(rc == ST))
    {
        int x = rc.x,y = rc.y,z = rc.z,rot = rc.rot,dir = rc.dir;
        record[temp--] = opt[step[x][y][z][rot][dir]];
        rc = pre[x][y][z][rot][dir];
    }
}
void solve()
{
    scanf("%d",&n);
    int a,b,c,d,e;
    memset(mat,0,sizeof(mat));
    for(int i = 0;i < 2;i++)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        if(i == 0)
            ST = point(a,b,c,e,d);
        else
            EN = point(a,b,c,e,d);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            char str[15];
            str[0] = 'x';
            scanf(" %s",&str[1]);
            int l = strlen(str);
            bool code[35];
            memset(code,0,sizeof(code));
            for(int q = l - 1;q >= 1;q--)
            {
                int fuck = str[q] - '0';
                for(int k = 1;k <= 3;k++)
                {
                    if(fuck & 1)
                        code[(l - q - 1) * 3 + k] = 1;
                    fuck >>= 1;
                }
            }
            for(int k = n;k >= 1;k --)
                mat[j][k][i] = code[k];
        }
    }
    memset(dis,0x7f,sizeof(dis));
    memset(pre,0,sizeof(pre));
    memset(step,0,sizeof(step));
    bfs();
    if(dis[EN.x][EN.y][EN.z][EN.rot][EN.dir] == 0x7f7f7f7f)
        puts("Sorry, I can't get there.");
    else
    {
        int ans = dis[EN.x][EN.y][EN.z][EN.rot][EN.dir];
        come(ans);
        printf("%d\n",ans);
        puts(&record[1]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)solve();
}
