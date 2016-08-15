#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int x[39][39];
int n;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
struct node
{
    int x,y,len,dir;
    int move;
} re[19];
bool oor(int x,int y)
{
    if(x<0||x>29) return false;
    if(y<0||y>29) return false;
    return  true;
}
bool stop[19],cash[19];
int map_move[39][39];
void init()
{
    int l,r,c;
    char d[5];
    memset(map_move,-1,sizeof(map_move));
    memset(x,false,sizeof(x));
    for(int i=0; i<n; i++)
    {
        scanf("%s%d%d%d",d,&l,&r,&c);
        re[i].len = l,re[i].x = r,re[i].y = c;
        if(d[0]=='R') re[i].dir = 0;
        else if(d[0]=='U') re[i].dir = 1;
        else if(d[0]=='L') re[i].dir = 2;
        else re[i].dir = 3;
        re[i].move = 1;
        int tx = r,ty = c;
        for(int j =0;j<l;j++)
        {
            map_move[tx][ty] = i;
            tx-=dx[re[i].dir];
            ty-=dy[re[i].dir];
        }
    }
}
void solve()
{
    bool fig = true;
    while(fig)
    {
        fig = false;
        for(int i=0; i<n; i++)
        {
            if(re[i].move==0)
            {
            }
            else
            {
                fig = true;
                re[i].x+=dx[re[i].dir];
                re[i].y+=dy[re[i].dir];
                if(!oor(re[i].x,re[i].y))
                {
                    if(re[i].len>0)
                    {
                        re[i].x-=dx[re[i].dir];
                        re[i].y-=dy[re[i].dir];
                        re[i].len--;
                        if(re[i].len<=0) re[i].move = 0;
                    }
                }
                if(map_move[re[i].x][re[i].y]!=-1&&map_move[re[i].x][re[i].y]!=i)
                {
                    re[map_move[re[i].x][re[i].y]].move = 0;
                    re[i].move = 0;
                    x[re[i].x][re[i].y] = true;
                }
                map_move[re[i].x][re[i].y]=i;
                map_move[re[i].x-dx[re[i].dir]*(re[i].len)][re[i].y-dy[re[i].dir]*(re[i].len)]=-1;
            }
        }
    }
    cout<<"   0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2"<<endl;
    cout<<"   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9"<<endl;
    for(int i=0; i<30; i++)
    {
        printf("%02d",29-i);
        for(int j=0; j<30; j++)
            if(!x[j][29-i]) cout<<" .";
            else cout<<" X";
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    while(~scanf("%d",&n))
    {
        init();
        solve();
    }
    return 0;
}
