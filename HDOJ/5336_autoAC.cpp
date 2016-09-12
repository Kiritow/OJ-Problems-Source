#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int dir_x[4]={0,0,-1,1};
const int dir_y[4]={1,-1,0,0};
int r,c,n,T;
int mid[111][111];
int SZ[111],Time[111];
int X[111],Y[111];
void init()
{
    memset(SZ,0,sizeof(SZ));
    memset(mid,0,sizeof(mid));
    memset(Time,0,sizeof(Time));
}
struct Node
{
    int x,y,d,t;
    void toString()
    {
        printf("(%d,%d) d: %d t: %d\n",x,y,d,t);
    }
};
bool isInside(int x,int y)
{
    if((x>=1&&x<=r)&&(y>=1&&y<=c)) return true;
    return false;
}
void solve(int _x,int _y)
{
    queue<Node> q;
    for(int i=0;i<4;i++)
    {
        Node nd;
        nd.x=_x; nd.y=_y; nd.d=i; nd.t=0;
        q.push(nd);
    }
    while(!q.empty())
    {
        Node u=q.front(); q.pop();
        int bbb=-1;
        int d=u.d;
        Node v;
        v.x=u.x+dir_x[d];
        v.y=u.y+dir_y[d];
        v.d=u.d;
        v.t=u.t+1;
        if(isInside(v.x,v.y)==false) continue;
        int id=mid[v.x][v.y];
        if(id==0)
        {
            if(v.t<T)
            {
                q.push(v);
            }
        }
        else
        {
            if(Time[id]!=0)
            {
                if(Time[id]>=v.t) continue;
                else
                {
                    if(v.t<T)
                    {
                        q.push(v);
                    }
                }
            }
            else if(Time[id]==0)
            {
                SZ[id]++;
                if(SZ[id]>4)
                {
                    Time[id]=v.t;
                    bbb=id;
                }
            }
        }
        if(bbb!=-1)
        {
            for(int j=0;j<4;j++)
            {
                Node n1;
                n1.x=X[bbb]; n1.y=Y[bbb];
                n1.d=j; n1.t=v.t;
                if(n1.t<T) 
                {
                    q.push(n1);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d%d%d",&r,&c,&n,&T)!=EOF)
    {
        init();
        for(int i=1,s;i<=n;i++)
        {
            scanf("%d%d%d",X+i,Y+i,&s);
            int x=X[i],y=Y[i];
            mid[x][y]=i;
            SZ[i]=s;
        }
        int x,y;
        scanf("%d%d",&x,&y);
        solve(x,y);
        for(int i=1;i<=n;i++)
        {
            if(Time[i]!=0) printf("%d %d\n",0,Time[i]);
            else printf("%d %d\n",1,SZ[i]);
        }
    }
    return 0;
}
