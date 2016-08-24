#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool vis[35][35][300][7];
struct node
{
    int x;
    int y;
    int z;
    int w;
    int step;
};
int x,y,ans;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char map[35][35];
char res[10];
void init()
{
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
}
int tomy(int sta)
{
    int a, b, c;
    a=sta%6; b=sta/6%6; c=sta/36%6;
    int d, e, f;
    d=5-a, e=5-b, f=5-c;
    return a+d*6+e*36+b*216+c*1296+f*7776;
}
int top(int sta)
{
    return sta%6;
}
int bt(int sta)
{
    return sta/6%6;
}
int nor(int sta)
{
    return sta/36%6;
}
int sou(int sta)
{
    return sta/216%6;
}
int wes(int sta)
{
    return sta/1296%6;
}
int eas(int sta)
{
    return sta/7776%6;
}
int up(int sta)
{
    int t1, n1, s1, b1, e1, w1;
    t1=sou(sta);
    n1=top(sta);
    s1=bt(sta);
    b1=nor(sta);
    e1=eas(sta);
    w1=wes(sta);
    return t1+s1*6+w1*36;
}
int down(int sta)
{
    int t1, n1, s1, b1, e1, w1;
    t1=nor(sta);
    n1=bt(sta);
    s1=top(sta);
    b1=sou(sta);
    e1=eas(sta);
    w1=wes(sta);
    return t1+s1*6+w1*36;
}
int left(int sta)
{
    int t1, n1, s1, b1, e1, w1;
    t1=eas(sta);
    w1=top(sta);
    b1=wes(sta);
    e1=bt(sta);
    n1=nor(sta);
    s1=sou(sta);
    return t1+s1*6+w1*36;
}
int right(int sta)
{
    int t1, n1, s1, b1, e1, w1;
    t1=wes(sta);
    w1=bt(sta);
    b1=eas(sta);
    e1=top(sta);
    n1=nor(sta);
    s1=sou(sta);
    return t1+s1*6+w1*36;
}
char s[]="rmybgc";
bool bfs()
{
    node n1,n2;
    n1.x=x;
    n1.y=y;
    n1.z=0;
    n1.w=78;
    n1.step=0;
    vis[x][y][78][0]=1;
    queue<node> q;
    q.push(n1);
    while(!q.empty())
    {
        node n2=q.front();
        if(n2.z==6)
        {
            ans=n2.step;
            return true;
        }
        q.pop();
        int t=tomy(n2.w);
        for(int i=0;i<4;i++)
        {
            int tmpx=dx[i]+n2.x;
            int tmpy=dy[i]+n2.y;
            if(map[tmpx][tmpy]=='w')
            {
                int temp;
                if(i==0)
                    temp=right(t);
                else if(i==1)
                    temp=down(t);
                else if(i==2)
                    temp=left(t);
                else
                    temp=up(t);
                if(vis[tmpx][tmpy][temp][n2.z]==0)
                {
                    vis[tmpx][tmpy][temp][n2.z]=1;
                    n1.x=tmpx;
                    n1.y=tmpy;
                    n1.w=temp;
                    n1.z=n2.z;
                    n1.step=n2.step+1;
                    q.push(n1);
                }
            }
            else if(map[tmpx][tmpy]==res[n2.z])
            {
                int temp;
                if(i==0)
                    temp=right(t);
                else if(i==1)
                    temp=down(t);
                else if(i==2)
                    temp=left(t);
                else
                    temp=up(t);
                int top=temp%6;
                if(vis[tmpx][tmpy][temp][n2.z+1]==0&&s[top]==res[n2.z])
                {
                    n1.x=tmpx;
                    n1.y=tmpy;
                    n1.w=temp;
                    n1.z=n2.z+1;
                    n1.step=n2.step+1;
                    vis[tmpx][tmpy][temp][n2.z+1]=1;
                    q.push(n1);
                }
            }
        }
    }
    return false;
}
int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)!=EOF&&n+d)
    {
        init();
        for(int i=1;i<=d;i++)
            for(int j=1;j<=n;j++)
            {
                scanf(" %c",&map[j][i]);
                if(map[j][i]=='#')
                {
                    x=j;
                    y=i;
                    map[j][i]='w';
                }
            }
        scanf(" %s",res);
        if(bfs())
            printf("%d\n",ans);
        else
            printf("unreachable\n");
    }
    return 0 ;
}
