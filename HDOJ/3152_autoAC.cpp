#include<iostream>
#include<queue>
#include<cstring>
#define maxn 125+5
using namespace std;
int n;
int casee=1;
int mapp[maxn][maxn];
int visit[maxn][maxn];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct stu
{
    int x,y;
    int sum;
    friend bool operator<(stu x,stu y)
    {
        return x.sum>y.sum; 
    }
};
void bfs()
{
    stu x,y;
    priority_queue<stu>root;
    x.x=0;
    x.y=0;
    x.sum=mapp[0][0];
    visit[0][0]=1;
    root.push(x);
    while(root.size())
    {
        x=root.top();
        root.pop();
        if(x.x==n-1&&x.y==n-1){cout<<"Problem "<<casee++<<": "<<x.sum<<endl;return;}
        for(int i=0;i<4;i++)
        {
            y.x=x.x+dir[i][0];
            y.y=x.y+dir[i][1];
            if(y.x<0||y.x>=n||y.y<0||y.y>=n||visit[y.x][y.y]){continue;}
            y.sum=x.sum+mapp[y.x][y.y];
            root.push(y);
            visit[y.x][y.y]=1;
        }
    }     
}
int main()
{
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mapp[i][j];
            }
        }
        memset(visit,0,sizeof(visit));
        bfs();
    }
    return 0;
}
