#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define max 510
int mo[4][2]={ {-1,0}, {0,1}, {1,0}, {0,-1} };
struct node{
    int ge[4];
    int vis[4];
    int fuhao;
}map[max][max];
struct data{           
    int x,y,g;  
}d[max][max][4]; 
int m,n,color,white;
void bfs(int x,int y,int r)      
{
    queue <data> q;
    int i,j,k;
    if(map[x][y].vis[r])
        return;
    data t;
    t.x=x;t.y=y;t.g=r;
    q.push(t);
    map[x][y].vis[r]=1;
    map[x][y].ge[r]=color;
    while(!q.empty())
    {
        data p;
        p=q.front();
        q.pop();
        i=p.x;
        j=p.y;
        k=p.g;
        if(map[i][j].fuhao=='\\')
        {
            if(map[i][j].vis[(5-k)%4]==0)              {
                q.push(d[i][j][(5-k)%4]);
                map[i][j].vis[(5-k)%4]=1;
                map[i][j].ge[(5-k)%4]=color;
            }
            if(0<=i+mo[k][0]&&i+mo[k][0]<m && 0<=j+mo[k][1]&&j+mo[k][1]<n)
            {
                if(map[i+mo[k][0]][j+mo[k][1]].vis[(k+2)%4]==0)
                {
                    map[i+mo[k][0]][j+mo[k][1]].vis[(k+2)%4]=1;
                    map[i+mo[k][0]][j+mo[k][1]].ge[(k+2)%4]=color;
                    q.push(d[i+mo[k][0]][j+mo[k][1]][(k+2)%4]);
                }
            }
        }
        else
        {
            if(map[i][j].vis[3-k]==0)  
            {
                q.push(d[i][j][3-k]);
                map[i][j].vis[3-k]=1;
                map[i][j].ge[3-k]=color;
            }
            if(0<=i+mo[k][0]&&i+mo[k][0]<m && 0<=j+mo[k][1]&&j+mo[k][1]<n)
            {
                if(map[i+mo[k][0]][j+mo[k][1]].vis[(k+2)%4]==0)
                {
                    map[i+mo[k][0]][j+mo[k][1]].vis[(k+2)%4]=1;
                    map[i+mo[k][0]][j+mo[k][1]].ge[(k+2)%4]=color;
                    q.push(d[i+mo[k][0]][j+mo[k][1]][(k+2)%4]);
                }
            }
        }
    }
}
void init()
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            for(k=0;k<4;k++)
            {
                map[i][j].vis[k]=0;
                map[i][j].fuhao=0;
                map[i][j].ge[k]=0;
            }
    }
}
int main()
{
    int i,j,k;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        getchar();
        init();
        color=0;
        white=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%c",&map[i][j].fuhao);
                for(k=0;k<4;k++)
                {
                    d[i][j][k].x=i;
                    d[i][j][k].y=j;
                    d[i][j][k].g=k;
                }
            }
            getchar();
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<4;k++)
                {
                    if(map[i][j].vis[k]==0)
                    {
                        color++;
                        bfs(i,j,k);
                    }
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                int flag=0,t=map[i][j].ge[0];
                for(k=1;k<4;k++)
                {
                    if(t!=map[i][j].ge[k])
                    {
                        flag=1;
                        break;
                    }
                }
                if(!flag)
                    white++;
            }
        }
        printf("%d\n",white);
    }
    return 0;
}
