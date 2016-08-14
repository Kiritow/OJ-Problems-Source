#include <cstdio>
#include <cstring>
#include <queue>
char op[7][10]= {"","fill A","fill B","empty A","empty B","pour A B","pour B A"};
struct state
{
    int a,b;
    state() {};
    state(int _a,int _b)
    {
        a=_a;
        b=_b;
    }
};
struct p
{
    int x,y;
    p() {};
    p(int _y,int _x)
    {
        x=_x;
        y=_y;
    }
} mp[1001][1001];
int A,B,n,vis[1001][1001];
void print(int y,int x)
{
    if(vis[y][x]!=-1)
        print(mp[y][x].y,mp[y][x].x);
    if(y||x){
        puts(op[vis[y][x]]);
    }
}
void bfs()
{
    std::queue<state>q;
    memset(vis,0,sizeof(vis));
    q.push(state(0,0));
    vis[0][0]=-1;
    mp[0][0]=p(0,0);
    while(!q.empty())
    {
        state cur=q.front();
        q.pop();
        int x=cur.b,y=cur.a;
        if(x==n)
        {
            print(y,x);
            return ;
        }
        int yy=A;
        if(y<A&&!vis[yy][x])
        {
            vis[yy][x]=1;
            q.push(state(yy,x));
            mp[yy][x]=p(y,x);
        }
        int xx=B;
        if(x<B&&!vis[y][xx])
        {
            vis[y][xx]=2;
            q.push(state(y,xx));
            mp[y][xx]=p(y,x);
        }
        if(y>0)
        {
            yy=0;
            if(!vis[yy][x])
            {
                vis[yy][x]=3;
                q.push(state(yy,x));
                mp[yy][x]=p(y,x);
            }
        }
        if(x>0)
        {
            xx=0;
            if(!vis[y][xx])
            {
                vis[y][xx]=4;
                q.push(state(y,xx));
                mp[y][xx]=p(y,x);
            }
        }
        if(y>0)
        {
            xx=x+y;yy=0;
            if(xx>B){
                yy=xx-B;
                xx=B;
            }
            if(!vis[yy][xx])
            {
                vis[yy][xx]=5;
                q.push(state(yy,xx));
                mp[yy][xx]=p(y,x);
            }
        }
        if(x>0)
        {
            yy=y+x;xx=0;
            if(yy>A){
                xx=yy-A;
                yy=A;
            }
            if(!vis[yy][xx])
            {
                vis[yy][xx]=6;
                q.push(state(yy,xx));
                mp[yy][xx]=p(y,x);
            }
        }
    }
}
int main(void)
{
    while(~scanf("%d%d%d",&A,&B,&n))
    {
        bfs();
        printf("success\n");
    }
    return 0;
}
