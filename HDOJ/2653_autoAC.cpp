#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
char g[100][100];
bool vis[88][88][88];
int n,m,p,t,si,sj,ans;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct node
{
    int step,p,x,y;
    node(int a=0,int b=0,int c=0,int d=0):x(a),y(b),p(c),step(d){}
    bool friend operator <(const node a,const node b)
    {
        return a.step>b.step;
    }
};
void BFS()
{
    priority_queue<node> Q;
    node f=node(si,sj,p,0);
    Q.push(f);
    memset(vis,false,sizeof(vis));
    vis[si][sj][p]=true;
    node temp;
    while(!Q.empty())
    {
        temp=Q.top();
        Q.pop();
        if(temp.step>t)
            return ;
        if(g[temp.x][temp.y]=='L')
        {
            ans=temp.step;
            return ;
        }
        for(int k=0;k<4;k++)
        {
            int i=dir[k][0]+temp.x;
            int j=dir[k][1]+temp.y;
            if(i<0||i>n-1 || j<0 || j>m-1||g[i][j]=='#')
                continue;
            if(temp.p!=0 && !vis[i][j][temp.p-1])
            {
                vis[i][j][temp.p-1]=true;
                Q.push(node(i,j,temp.p-1,temp.step+1));
            }
            if(g[temp.x][temp.y]!='@' && g[i][j]!='@'&&!vis[i][j][temp.p])
            {
                vis[i][j][temp.p]=true;
                Q.push(node(i,j,temp.p,temp.step+2));
            }
        }
    }
    return ;
}
int main()
{
    int cas=0;
    while(scanf("%d %d %d %d",&n,&m,&t,&p)==4)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",g[i]);
            for(int j=0;j<m;j++)
                if(g[i][j]=='Y')
                    si=i,sj=j;
        }
        ans=100001;
        BFS();
        printf("Case %d:\n",++cas);
        if(ans>t)
            printf("Poor Yifenfei, he has to wait another ten thousand years.\n");
        else printf("Yes, Yifenfei will kill Lemon at %d sec.\n",ans);
    }
    return 0;
}
