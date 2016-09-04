#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int N = 10;
struct Domino
{
    int x,y;
}d[40];
struct Uncover
{
    int x,y;
}u[N*N];
int map[N][N],st[3][9],t,num;
int dir[2][2]={{0,1},{1,0}};
bool vis[N][N],flag;
void init()
{
    for(int i=1;i<=8;i++)
        for(int j=i+1;j<=9;j++)
        {
            d[t].x=i,d[t].y=j;
            t++;
        }
}
bool isfinish()
{
    for(int i=0;i<3;i++)
        for(int j=0;j<9;j++)
            if(st[i][j]!=((1<<9)-1))
                return false;
    return true;
}
bool check(int x,int y,int xx,int yy,int first,int second)
{
    int ss1=(x/3)*3+y/3,ss2=(xx/3)*3+yy/3;
    first--,second--;
    if((st[0][x]&(1<<first))||(st[0][xx]&(1<<second)))
        return false;
    if((st[1][y]&(1<<first))||(st[1][yy]&(1<<second)))
        return false;
    if((st[2][ss1]&(1<<first))||(st[2][ss2]&(1<<second)))
        return false;
    st[0][x]|=(1<<first),st[0][xx]|=(1<<second);
    st[1][y]|=(1<<first),st[1][yy]|=(1<<second);
    st[2][ss1]|=(1<<first),st[2][ss2]|=(1<<second);
    return true;
}
void restore(int x,int y,int xx,int yy,int first,int second)
{
    int ss1=(x/3)*3+y/3,ss2=(xx/3)*3+yy/3;
    first--,second--;
    st[0][x]&=~(1<<first),st[0][xx]&=~(1<<second);
    st[1][y]&=~(1<<first),st[1][yy]&=~(1<<second);
    st[2][ss1]&=~(1<<first),st[2][ss2]&=~(1<<second);
}
void set(int x,int y,int a)
{
    int ss=(x/3)*3+y/3;
    a--;
    st[0][x]|=(1<<a);
    st[1][y]|=(1<<a);
    st[2][ss]|=(1<<a);
}
void dfs(int n)
{
    int x=u[n].x,y=u[n].y;
    if(isfinish())
    {
        flag=true;
        return ;
    }
    for(int i=0;i<t;i++)
    {    
        if(vis[d[i].x][d[i].y])
            continue;
        vis[d[i].x][d[i].y]=true;
        for(int f=0;f<2;f++)
        {
            int first=d[i].x,second=d[i].y;
            if(f&1) swap(first,second);
            for(int k=0;k<2;k++)
            {    
                int temp=n;
                int xx=x+dir[k][0];
                int yy=y+dir[k][1];
                if(xx<0 || xx>=9 || yy<0 || yy>=9 || map[xx][yy]!=0)
                    continue;
                if(!check(x,y,xx,yy,first,second))
                    continue;
                map[x][y]=first,map[xx][yy]=second;
                if(map[u[temp+1].x][u[temp+1].y]==0)
                    dfs(temp+1);
                else {
                    while(temp<num && map[u[temp+1].x][u[temp+1].y]!=0)
                        temp++;
                    dfs(temp+1);
                }
                if(flag) return;
                restore(x,y,xx,yy,first,second);
                map[x][y]=0,map[xx][yy]=0;
            }
        }
        vis[d[i].x][d[i].y]=false;
    }            
}
int main()
{
    t=0;
    init();
    int m,cas=0;
    char s1[5],s2[5];
    int a,b,c,d;
    while(scanf("%d",&m)==1 && m)
    {
        memset(vis,false,sizeof(vis));
        memset(map,0,sizeof(map));
        memset(st,0,sizeof(st));
        for(int i=0;i<m;i++)
        {
            scanf("%d %s %d %s",&a,s1,&b,s2);
            int x=s1[0]-'A',y=s1[1]-'0'-1;
            map[x][y]=a;
            set(x,y,a);
            x=s2[0]-'A',y=s2[1]-'0'-1;
            map[x][y]=b;
            set(x,y,b);
            vis[a][b]=vis[b][a]=true;
        }
        for(int i=1;i<=9;i++)
        {
            scanf("%s",s1);
            int x=s1[0]-'A',y=s1[1]-'0'-1;
            set(x,y,i);
            map[x][y]=i;
        }
        num=0;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(map[i][j]==0)
                {
                    u[num].x=i,u[num].y=j;
                    num++;
                }
        flag=false;
        dfs(0);
        printf("Puzzle %d\n",++cas);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                printf("%d",map[i][j]);
            puts("");
        }
    }
    return 0;
}
