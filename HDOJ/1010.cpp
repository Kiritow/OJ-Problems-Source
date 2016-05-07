/// TLE -> WA
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10
#define MAXM 10

char map[MAXN][MAXM];

int N,M,T;

inline void init()
{
    memset(map,0,MAXN*MAXM);
}

inline bool checkmap()
{
    int wall=0;
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXM;j++)
        {
            if(map[i][j]=='X') ++wall;
        }
    }
    if(N*M-wall<=T)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void findSD(int* pSx,int* pSy,int* pDx,int* pDy)
{
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<MAXM;j++)
        {
            switch(map[i][j])
            {
            case 'S':
                *pSx=i;*pSy=j;
                break;
            case 'D':
                *pDx=i;*pDy=j;
                break;
            }
        }
    }
}

int startx,starty,endx,endy;
bool endflag;
void DFS(int x,int y,int step)
{
    if(endflag) return;
    if(x<1||x>N||y<1||y>M) return;
    if(x==endx&&y==endy&&step==T)
    {
        endflag=true;
        return;
    }
    /// TLE? Try this
    int temp=T-step-(abs(endx-x)+abs(endy-y));
    if(temp<0||temp%2)
    {
        return;
    }
    if(map[x-1][y]=='.'||map[x-1][y]=='D')
    {
        map[x-1][y]='X';
        DFS(x-1,y,step+1);
        map[x-1][y]='.';
    }
    if(map[x+1][y]=='.'||map[x+1][y]=='D')
    {
        map[x+1][y]='X';
        DFS(x+1,y,step+1);
        map[x+1][y]='.';
    }
    if(map[x][y-1]=='.'||map[x][y-1]=='D')
    {
        map[x][y-1]='X';
        DFS(x,y-1,step+1);
        map[x][y-1]='.';
    }
    if(map[x][y+1]=='.'||map[x][y+1]=='D')
    {
        map[x][y+1]='X';
        DFS(x,y+1,step+1);
        map[x][y+1]='.';
    }
}


int main()
{
    while(scanf("%d %d %d",&N,&M,&T)==3&&N+M+T!=0)
    {
        init();
        for(int i=1;i<=N;i++)
        {
            scanf("%s",&map[i][1]);
        }
        if(!checkmap())
        {
            printf("NO\n");
            continue;
        }
        findSD(&startx,&starty,&endx,&endy);
        endflag=false;
        DFS(startx,starty,0);
        if(endflag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
