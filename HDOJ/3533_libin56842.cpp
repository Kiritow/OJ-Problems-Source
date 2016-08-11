#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
#define ads(x) (x<0?-x:x)
int n,m,k,life;
int to[5][2] = {0,1,1,0,0,-1,-1,0,0,0};//四个方向与停止不动的走法
int map[105][105];
bool vis[105][105][1005];

struct period
{
    char c;
    int t,v;
} s[105][105];

struct node
{
    int x,y,step;
};

int check(int x,int y)
{
    if(x<0 || x>n || y<0 || y>m)
        return 1;
    return 0;
}

void bfs()
{
    node a,next;
    queue<node> Q;
    int i,j,flag,dis,tem;
    a.x = a.y = a.step = 0;
    Q.push(a);
    vis[0][0][0] = true;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
          if(a.step>life)
            break;
        if(a.x == n && a.y == m)
        {
            printf("%d\n",a.step);
            return ;
        }
        for(i = 0; i<5; i++)
        {
            next = a;
            next.x+=to[i][0];
            next.y+=to[i][1];
            next.step++;
            if(check(next.x,next.y)) continue;
            if(!s[next.x][next.y].t && !vis[next.x][next.y][next.step] && next.step<=life)//在符合条件的情况下，枚举四个方向
            {
                flag = 1;
                for(j = next.x-1; j>=0; j--)//当位于这点，我们往北向寻找是否有朝南方向射击的炮台
                {
                    if(s[j][next.y].t && s[j][next.y].c == 'S')//找到第一个炮台，且这个炮台是朝南射击的
                    {
                        dis = next.x-j;//看炮台与人的距离
                        if(dis%s[j][next.y].v) break;//因为不需要看子弹中途的点，子弹每一秒跑v，距离是dis，dis不能整除v的话，那么子弹是不可能停在这个点的
                        tem = next.step-dis/s[j][next.y].v;//人走的时间减去第一个子弹飞行到这个位置所需的时间
                        if(tem<0) break;//为负数就是第一个子弹都没有经过这个点，那么人绝对安全
                        if(tem%s[j][next.y].t==0)//看间隔，能整除，那么就是后续有子弹刚好到这个点，人死定了
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[j][next.y].t)//找到炮台但不是朝南射击，那么这个炮台会当下后面所有子弹，所以北方向安全我们不需要再找
                        break;
                }
                if(!flag)//这个方向都死定了，后面也就不需要看了
                    continue;
                //其他方向也是一样的道理，就不注释了
                for(j = next.x+1; j<=n; j++)
                {
                    if(s[j][next.y].t && s[j][next.y].c == 'N')
                    {
                        dis = j-next.x;
                        if(dis%s[j][next.y].v) break;
                        tem = next.step-dis/s[j][next.y].v;
                        if(tem<0) break;
                        if(tem%s[j][next.y].t==0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[j][next.y].t)
                        break;
                }
                if(!flag)
                    continue;
                for(j = next.y-1; j>=0; j--)
                {
                    if(s[next.x][j].t && s[next.x][j].c == 'E')
                    {
                        dis = next.y-j;
                        if(dis%s[next.x][j].v) break;
                        tem = next.step-dis/s[next.x][j].v;
                        if(tem<0) break;
                        if(tem%s[next.x][j].t==0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[next.x][j].t)
                        break;
                }
                if(!flag)
                    continue;
                for(j = next.y+1; j<=m; j++)
                {
                    if(s[next.x][j].t && s[next.x][j].c == 'W')
                    {
                        dis = j-next.y;
                        if(dis%s[next.x][j].v) break;
                        tem = next.step-dis/s[next.x][j].v;
                        if(tem<0) break;
                        if(tem%s[next.x][j].t==0)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(s[next.x][j].t)
                        break;
                }
                if(!flag)
                    continue;
                vis[next.x][next.y][next.step] = true;
                Q.push(next);
            }
        }
    }
    printf("Bad luck!\n");
}

int main()
{
    int i,j,x,y,t,v;
    char str[3];
    while(~scanf("%d%d%d%d",&n,&m,&k,&life))
    {
        memset(s,0,sizeof(s));
        memset(vis,false,sizeof(vis));
        for(i = 0; i<k; i++)
        {
            scanf("%s%d%d%d%d",str,&t,&v,&x,&y);
            s[x][y].v = v;
            s[x][y].t = t;
            s[x][y].c = str[0];
        }
        bfs();
    }

    return 0;
}
