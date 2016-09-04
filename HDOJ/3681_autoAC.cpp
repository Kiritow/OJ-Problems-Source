#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
char gp[16][16];
int nd[16][2],dp[1<<16][16],n,m,fis,ac,cnt=0,dis[16][16];
int dr[4][2]={1,0,-1,0,0,1,0,-1};
int bfs(int x,int y,int xx,int yy)
{
    queue<int> a,b;
    int vd[16][16];
    memset(vd,-1,sizeof(vd));
    if(xx==x&&y==yy) return 0;
    a.push(x);
    b.push(y);
    vd[x][y]=0;
    while(a.empty()==0)
    {
        int nx=a.front(),ny=b.front();
        a.pop();b.pop();
        for(int i=0;i<4;i++)
        {
            int dx=nx+dr[i][0],dy=ny+dr[i][1];
            if(dx<0||dx>=n||dy<0||dy>=m||vd[dx][dy]!=-1||gp[dx][dy]=='D')continue;
            vd[dx][dy]=vd[nx][ny]+1;
            a.push(dx);b.push(dy);
            if(dx==xx&&dy==yy)return vd[dx][dy];
        }
    }
    return -1;
}
bool check(int gs)
{
    memset(dp,-1,sizeof(dp));
    dp[1<<fis][fis]=gs;
    int ans=-1;
    for(int i=0;i<(1<<cnt);i++)
        for(int j=0;j<cnt;j++)
        {
            if((i&(1<<j))==0)continue;
            if((i&(ac))==ac)
                if(dp[i][j]!=-1)
                    return true;
            for(int k=0;k<cnt;k++)
            {
                if(dp[i][j]==-1||k==j||(i&(1<<k))||dis[j][k]==-1)continue;
                int tem=dp[i][j]-dis[j][k];
                if(tem<0)continue;
                dp[i+(1<<k)][k]=max(dp[i+(1<<k)][k],tem);
                if(gp[nd[k][0]][nd[k][1]]=='G')dp[i+(1<<k)][k]=gs;
            }
        }
        return false;
}
void init()
{
    int i,j;
    for(int i=0;i<cnt;i++)
        for(int j=0;j<cnt;j++)
        {
            if(i==j)dis[i][j]=0;
            else
                dis[i][j]=bfs(nd[i][0],nd[i][1],nd[j][0],nd[j][1]);
        }
}
int main()
{  
    int l,r,mid;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)return 0;
        getchar();
        ac=0;cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&gp[i][j]);
                if(gp[i][j]=='F')
                {
                    fis=cnt;
                    nd[cnt][0]=i;
                    nd[cnt][1]=j;
                    ac+=1<<cnt;
                    cnt++;
                }
                else
                    if(gp[i][j]=='G')
                    {
                        nd[cnt][0]=i;
                        nd[cnt][1]=j;
                        cnt++;
                    }
                    else
                        if(gp[i][j]=='Y')
                        {
                            nd[cnt][0]=i;
                            nd[cnt][1]=j;
                            ac+=1<<cnt;
                            cnt++;
                        }
            }
            getchar();
        }
        init();
        l=0,r=300;
        int ans=1<<30;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(check(mid))
            {
                r=mid-1;
                ans=min(mid,ans);
            }
            else
                l=mid+1;
        }
        if(ans==(1<<30))
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
