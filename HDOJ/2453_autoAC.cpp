#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
    int x,y;
    int res;
    int da;
    int op;
    int A;
    int j;
};
bool operator < (node i,node j)
{
    if(i.da==j.da)
    {
        if(i.A==j.A) return i.op>j.op;
        return i.A>j.A;
    }
    return i.da>j.da;
}
int t,n,m,d,e,c;
char map[30][30];
int dx[]={-1,0,0,1};
int dy[]={0,1,-1,0};
int da[30][30],A[30][30],jia[30][30];
inline void bfs(node vs,node ve)
{
    int flag=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) da[i][j]=jia[i][j]=A[i][j]=410;
    priority_queue<node>q;
    node vn,vw;
    da[vs.x][vs.y]=A[vs.x][vs.y]=jia[vs.x][vs.y]=0;
    vn.x=vs.x,vn.y=vs.y;
    vn.res=e,vn.da=0,vn.op=0,vn.A=0;
    q.push(vn);
    while(!q.empty())
    {
        vn=q.top();q.pop();
        if(vn.x==ve.x&&vn.y==ve.y)
        {
            flag=vn.op;
            break;
        }
        for(int i=0;i<4;i++)
        {
            int a,b;
            if(vn.res>=c)
            {
                a=vn.x,b=vn.y;
                int tag=1;
                for(int j=0;j<d;j++)
                {
                    a+=dx[i],b+=dy[i];
                    if(a<0||a>=n||b<0||b>=m) 
                    {
                        tag=0;break;
                    }
                    if(map[a][b]!=' '&&map[a][b]!='E') 
                    {
                        tag=0;break;
                    }
                }
                if(tag)
                {
                    if(da[a][b]>vn.da||(da[a][b]==vn.da&&A[a][b]>vn.A+d)||((da[a][b]==vn.da&&A[a][b]==vn.A+d&&jia[a][b]>vn.j+1)))
                    {
                        da[a][b]=vn.da;
                        A[a][b]=vn.A+d;
                        jia[a][b]=vn.j+1;
                        vw.x=a,vw.y=b;
                        vw.res=vn.res-c;
                        vw.da=vn.da;
                        vw.op=vn.op+1;
                        vw.A=vn.A+d;
                        vw.j=vn.j+1;
                        q.push(vw);
                    }
                }
            }
            a=vn.x+dx[i],b=vn.y+dy[i];
            if(a>=0&&a<n&&b>=0&&b<m&&map[a][b]!='#')
            {
                if(map[a][b]!='*'&&((da[a][b]>vn.da||(da[a][b]==vn.da&&A[a][b]>vn.A+1)||((da[a][b]==vn.da&&A[a][b]==vn.A+1&&jia[a][b]>vn.j)))))
                {
                    da[a][b]=vn.da;
                    A[a][b]=vn.A+1;
                    jia[a][b]=vn.j;
                    vw.x=a,vw.y=b;
                    vw.da=vn.da;
                    vw.res=vn.res;
                    vw.op=vn.op+1;
                    vw.j=vn.j;
                    vw.A=vn.A+1;
                    q.push(vw);
                }
                else if(map[a][b]=='*'&&vn.res>=c&&((da[a][b]>vn.da||(da[a][b]==vn.da&&A[a][b]>vn.A+1)||((da[a][b]==vn.da&&A[a][b]==vn.A+1&&jia[a][b]>vn.j+1)))))
                {
                    da[a][b]=vn.da+1;
                    A[a][b]=vn.A+1;
                    jia[a][b]=vn.j+1;
                    vw.x=a,vw.y=b;
                    vw.da=vn.da+1;
                    vw.res=vn.res-c;
                    vw.op=vn.op+1;
                    vw.A=vn.A+1;
                    vw.j=vn.j+1;
                    q.push(vw);
                }
            }
        }
    }
    if(flag==-1) printf("can not reach!\n");
    else printf("%d\n",flag);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=0;i<n;i++) gets(map[i]);
        scanf("%d%d%d",&d,&e,&c);
        node vs,ve;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='S') vs.x=i,vs.y=j;
                else if(map[i][j]=='E') ve.x=i,ve.y=j;
            }
        bfs(vs,ve);
    }
}
