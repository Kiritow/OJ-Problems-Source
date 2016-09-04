#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int board[105][105];
int sep[105][105];
int n,m,l;
struct bnode
{
    int x,y,d,time;
};
int dir[4][2]={0,-1,0,1,-1,0,1,0};
void bfs(int x,int y)
{
    queue<bnode> sav;
    while(!sav.empty())sav.pop();
    board[x][y]++;
    if(board[x][y]>l){
        board[x][y]=0;
        sep[x][y]=0;
        for(int i=0;i<4;++i)
        {
            bnode tmp;
            tmp.x=x+dir[i][0];
            tmp.y=y+dir[i][1];
            tmp.d=i;
            tmp.time=1;
            if(tmp.x<=n&&tmp.x>=1&&tmp.y<=m&&tmp.y>=1)
            sav.push(tmp);
        }
    }
    while(!sav.empty())
    {
        bnode now=sav.front();
        sav.pop();
        if(board[now.x][now.y]<l&&board[now.x][now.y]!=0)
        {
            board[now.x][now.y]++;
        }
        else if(board[now.x][now.y]==l)
        {
            board[now.x][now.y]=0;
            sep[now.x][now.y]=now.time;
            for(int i=0;i<4;++i)
            {
                bnode tmp;
                tmp.x=now.x+dir[i][0];
                tmp.y=now.y+dir[i][1];
                tmp.d=i;
                tmp.time=now.time+1;
                if(tmp.x<=n&&tmp.x>=1&&tmp.y<=m&&tmp.y>=1)
                sav.push(tmp);
            }
        }
        else if(board[now.x][now.y]==0)
        {
            if(sep[now.x][now.y]!=now.time)
            {
                bnode tmp;
                tmp.x=now.x+dir[now.d][0];
                tmp.y=now.y+dir[now.d][1];
                tmp.d=now.d;
                tmp.time=now.time+1;
                 if(tmp.x<=n&&tmp.x>=1&&tmp.y<=m&&tmp.y>=1)
                    sav.push(tmp);
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(sep,0,sizeof(sep));
        scanf("%d%d%d",&n,&m,&l);
        bool flag=false;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%d",&board[i][j]);
                if(board[i][j])flag=true;
            }
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(!flag)continue;
            bfs(x,y);
            flag=false;
            for(int i=1;i<=n;++i)
            {
                if(flag)break;
                for(int j=1;j<=m;++j)
                {
                    if(board[i][j]){flag=true;break;}
                }
            }
        }
        if(!flag)printf("YES\n");
        else
        {
            printf("NO\n");
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=m;++j)
                {
                    printf("%d ",board[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
