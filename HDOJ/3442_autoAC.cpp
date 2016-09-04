#include<stdio.h>
#include<string.h>
#include<queue>
 using namespace std;
 struct node
{
    int damage,x,y;
    int mark[5];
    bool operator <(const node &a)const 
    {
        return a.damage<damage;
    }
};
typedef struct tt
{
    int x,y,t;
}NODE;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
node cur,ne;
int n,m,tag;NODE cur1,next1;
char a[55][55];int mark[55][55],mark1[55][55];
void bfs(int x,int y)
{
    priority_queue<node> qu;
    cur.x=x;cur.y=y;cur.damage =0;
    queue<NODE> q;
    int i,j;
    for(i=0;i<5;i++)
    {
        cur.mark[i]=0;
    }
    qu.push(cur);
    while(!qu.empty ())
    {
        cur=qu.top ();
        qu.pop();
        if(a[cur.x][cur.y]=='!')
        {
            tag=1;
            return ;
        }
        for(i=0;i<4;i++)
        {
            ne.x=cur.x+dir[i][0];
            ne.y=cur.y+dir[i][1];
            if(ne.x>=1&&ne.x<=n&&ne.y>=1&&ne.y<=m&&a[ne.x][ne.y]!='#'&&a[ne.x][ne.y]!='A'&&a[ne.x][ne.y]!='B'&&a[ne.x][ne.y]!='D'&&a[ne.x][ne.y]!='E')
            {
                ne.damage =cur.damage ;
                for(j=0;j<5;j++)
                {
                    ne.mark[j]=cur.mark[j];
                }
                if(a[ne.x][ne.y]=='C' && cur.mark[2]==0)
                {
                    ne.damage +=3;
                    ne.mark[2]=1;
                }
                memset(mark1,0,sizeof(mark1));
                while(!q.empty ())
                    q.pop ();
                cur1.x=ne.x;
                cur1.y=ne.y;
                cur1.t=0;
                q.push(cur1);
                    while(!q.empty ())
                    {
                        cur1=q.front ();
                        q.pop();
                        if(cur1.t>3)
                            break;
                        if(ne.mark[0]==0 && cur1.t<=2 && a[cur1.x][cur1.y]=='A')
                        {
                            ne.damage+=1;
                            ne.mark[0]=1;
                        }
                        if(ne.mark[1]==0 && cur1.t<=3 && a[cur1.x][cur1.y]=='B')
                        {
                            ne.damage +=2;
                            ne.mark[1]=1;
                        }
                        if(ne.mark[3]==0 && cur1.t<=2&&a[cur1.x][cur1.y]=='D')
                        {
                            ne.damage +=4;
                            ne.mark[3]=1;
                        }
                        if(ne.mark[4]==0 && cur1.t<=1&&a[cur1.x][cur1.y]=='E')
                        {
                            ne.damage +=5;
                            ne.mark [4]=1;
                        }
                        for(j=0;j<=4;j++)
                        {
                            next1.x=cur1.x+dir[j][0];
                            next1.y=cur1.y+dir[j][1];
                            if(next1.x>=1&&next1.x<=n&&next1.y>=1&&next1.y<=m&&!mark1[next1.x][next1.y])
                            {
                                mark1[next1.x][next1.y]=1;
                                next1.t=cur1.t+1;
                                q.push(next1);
                            }
                        }
                    }
                    if(mark[ne.x][ne.y]>ne.damage)
                    {
                        mark[ne.x][ne.y]=ne.damage;
                        qu.push(ne);
                    }
            }
        }
    }
}
int main()
{
    int t,i,j,sx,sy,count=0;
    scanf("%d",&t);
    while(t--)
    {
        count++;tag=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            getchar();
            for(j=1;j<=m;j++)
            {
                scanf("%c",&a[i][j]);
                mark[i][j]=0xfffffff;
                if(a[i][j]=='$')
                {
                    sx=i;sy=j;
                }
            }
        }
        bfs(sx,sy);
        if(tag)
           printf("Case %d: %d\n",count,cur.damage );
        else
            printf("Case %d: %d\n",count,-1);
    }
    return 0;
}
