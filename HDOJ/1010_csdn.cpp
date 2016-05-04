#include <iostream>
#include <cstring>
using namespace std;
char a[10][10];
int n,m,t;
int sx,sy,ex,ey;
bool flag;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int abs(int x)
{
    return x<0?-x:x;
}
void DFS(int x,int y,int time)//当前位置坐标(x,y),到目前位置消耗时间
{
    if(x<0||x>=n||y<0||y>=m)
        return;
    if(x==ex&&y==ey&&time==t)
    {
        flag =true;
        return ;
    }
    if(flag)
        return;
    int temp=(t-time)-(abs(x-ex)+abs(y-ey));
    if(temp<0||temp&1)
        return;
    for(int i=0;i<4;i++)
    {
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(a[xx][yy]!='X')
        {
            a[xx][yy]='X';
            DFS(xx,yy,time+1);
            a[xx][yy]='.';
            if(flag)
                return ;
        }
    }
}
int main()
{
    while(cin>>n>>m>>t)
    {
        if(n==0&&m==0)
            break;
        int wall=0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='S')
                    sx=i,sy=j;
                else if(a[i][j]=='D')
                    ex=i,ey=j;
                else if(a[i][j]=='X')
                    wall++;
            }
        if(n*m-wall<=t)
        {
            cout<<"NO"<<endl;
            continue;
        }
        flag=false;
        a[sx][sy]='X';
        DFS(sx,sy,0);
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
