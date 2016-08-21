#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n,m,dir[5][2]={{0,0},{1,0},{0,1},{-1,0},{0,-1}};
char map[81][81];
bool vis[81][81][5];
struct node
{
    int x,y,t,cnt;
    node(int _x=0,int _y=0,int _t=0,int _cnt=0):x(_x),y(_y),t(_t),cnt(_cnt){}
    friend bool operator <(const node &a,const node &b)
    {
        return a.cnt>b.cnt;
    }
};
node f;
priority_queue<node> Q;
int bfs()
{
    Q.push(f);
    while(!Q.empty())
    {
        node temp=Q.top();
        Q.pop();
        if(temp.x==0||temp.x==n-1||temp.y==0||temp.y==m-1)
            return temp.cnt;
        for(int k=1;k<5;k++)
        {
            int i=temp.x+dir[k][0];
            int j=temp.y+dir[k][1];
            if(!vis[i][j][k]&&map[i][j]!='#')
            {
              if(temp.t%2==k%2)
              {
                if(k==temp.t)
                {
                    if(k%2==0&&map[temp.x+1][temp.y]=='#'&&map[temp.x-1][temp.y]=='#')
                    {vis[i][j][k]=1; Q.push(node(i,j,k,temp.cnt+1));}
                    if(k%2==1&&map[temp.x][temp.y+1]=='#'&&map[temp.x][temp.y-1]=='#')
                    {vis[i][j][k]=1; Q.push(node(i,j,k,temp.cnt+1));}
                }
              }
              else {vis[i][j][k]=1;Q.push(node(i,j,k,temp.cnt+1));} 
            }
        }
    }
    return -1;
}
int main()
{
    int cas,si,sj;
    cin>>cas;
    while(cas--)
    {
        while(!Q.empty())
            Q.pop();
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='@')
                {
                    si=i;sj=j;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        f.x=si;f.y=sj;f.t=-1;f.cnt=0;
         cout<<bfs()<<endl;
    }
    return 0;
}
