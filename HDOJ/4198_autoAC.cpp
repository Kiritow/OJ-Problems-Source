#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n,m,d;
int t[4][2]={0,1,0,-1,1,0,-1,0},vist[510][510];
int mx,my;
char s[510][510];
struct ss
{
    friend bool operator<(const ss a,const ss b)
    {
        return a.sum>b.sum;
    }
    int x,y,sum;
};
priority_queue<ss>Q;
void bfs()
{
    memset(vist,0,sizeof(vist));
    ss node1,node2;
    node1.x=mx;
    node1.y=my;
    node1.sum=0;
    while(!Q.empty())
        Q.pop();
    Q.push(node1);
    vist[mx][my]=1;
    while(!Q.empty())
    {
        node1=Q.top();
        Q.pop();
        if(node1.x==0||node1.y==0||node1.x==n-1||node1.y==m-1)
        {
            printf("%d\n",node1.sum+1);
            return ;
        }
        for(int i=0;i<4;i++)
        {
            int xx=node1.x+t[i][0];
            int yy=node1.y+t[i][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&s[xx][yy]!='#'&&!vist[xx][yy])
            {
                vist[xx][yy]=1;
                node2.x=xx;
                node2.y=yy;
                if(s[xx][yy]=='.')
                    node2.sum=node1.sum+1;
                else
                    node2.sum=node1.sum+d+1;
                Q.push(node2);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&d);
        int i,j;
        for(i=0;i<n;i++)
        {
            getchar();
            for(j=0;j<m;j++)
            {
                scanf("%c",&s[i][j]);
                if(s[i][j]=='S')
                {
                    mx=i;
                    my=j;
                    s[i][j]='.';
                }
            }
        }
        bfs();
    }
    return 0;
}
