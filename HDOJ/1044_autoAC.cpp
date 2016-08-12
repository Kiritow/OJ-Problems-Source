#include<iostream>
#include<queue>
using namespace std;
char map[50][50];
int distan[12][12];
int jewels[12][3];
int mark[50][50];
int visit[12];
int sx,sy,ex,ey,dijige,youjige,cancollect,maxjewels,jieshu;
int u,n,m,t,zhubao,flag;
struct node
{
    int x,y,step;
}w,p;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int bfs(int qx,int qy,int mx,int my)
{
    queue<node> q;
    w.x=qx;w.y=qy;w.step=0;
    while(!q.empty())
        q.pop();
    q.push(w);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p.x==mx&&p.y==my)
            return p.step;
        for(int i=0;i<4;i++)
        {
            w.x=p.x+dir[i][0];
            w.y=p.y+dir[i][1];
            w.step=p.step+1;
            if(w.x>=0&&w.x<n&&w.y>=0&&w.y<m&&map[w.x][w.y]!='*'&&mark[w.x][w.y]==0)
            {
                mark[w.x][w.y]=1;
                q.push(w);
            }
        }
    }
    return 1000001;
}
void dfs(int weizhi,int step,int jewel)
{
    if(step<0) return;
    if(jieshu==1) return;
    if(jewel==cancollect&&step>=0&&weizhi==zhubao+1)
    {
        maxjewels=jewel;
        flag=1;
        jieshu=1;
        return;
    }
    if(weizhi==zhubao+1&&step>=0)
    {
        flag=1;
        if(jewel>maxjewels)
            maxjewels=jewel;
        return;
    }
    for(int i=0;i<zhubao+2;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;
            dfs(i,step-distan[weizhi][i],jewel+jewels[i][2]);
            visit[i]=0;
        }
    }
    return;
}
int main()
{
    cin>>u;
    youjige=u;
    dijige=1;
    while(u--)
    {
        memset(jewels,0,sizeof(jewels));
        cin>>m>>n>>t>>zhubao;
        for(int i=0;i<zhubao;i++)
            cin>>jewels[i][2];
        memset(distan,1000001,sizeof(distan));
        memset(mark,0,sizeof(mark));
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }
                if(map[i][j]=='<')
                {
                    ex=i;
                    ey=j;
                }
                if(map[i][j]>='A'&&map[i][j]<='J')
                {
                    jewels[map[i][j]-'A'][0]=i;
                    jewels[map[i][j]-'A'][1]=j;
                }
            }
        }
        cancollect=0;
        for(int i=0;i<zhubao;i++)
        {
            distan[zhubao][i]=bfs(sx,sy,jewels[i][0],jewels[i][1]);
            memset(mark,0,sizeof(mark));
            distan[zhubao+1][i]=bfs(ex,ey,jewels[i][0],jewels[i][1]);
            memset(mark,0,sizeof(mark));
            distan[i][zhubao]=distan[zhubao][i];
            distan[i][zhubao+1]=distan[zhubao+1][i];
            if(distan[zhubao][i]!=1000001)
                cancollect+=jewels[i][2];
        }
        distan[zhubao][zhubao+1]=bfs(sx,sy,ex,ey);
        memset(mark,0,sizeof(mark));
        distan[zhubao+1][zhubao]=distan[zhubao][zhubao+1];
        for(int i=0;i<zhubao;i++)
            for(int j=0;j<zhubao;j++)
            {
                if(i<j)
                {
                    distan[i][j]=bfs(jewels[i][0],jewels[i][1],jewels[j][0],jewels[j][1]);
                    memset(mark,0,sizeof(mark));
                }
                else
                    distan[i][j]=distan[j][i];
            }
        visit[zhubao]=1;
        maxjewels=0;
        flag=0;
        jieshu=0;
        dfs(zhubao,t,0);
        cout<<"Case "<<dijige<<':'<<endl;
        if(flag==1)
            cout<<"The best score is "<<maxjewels<<'.'<<endl;
        else
            cout<<"Impossible"<<endl;
        if(dijige<youjige)
            cout<<endl;
        dijige++;
    }
    return 0;
}
