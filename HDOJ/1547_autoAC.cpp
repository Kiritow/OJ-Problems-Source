#include<cstdio>
#include<cstring>
using namespace std;
int dir[6][2]={-1,1,0,2,1,1,1,-1,0,-2,-1,-1};
char mat[205][205];
int n,m,x,y,maxx;
void dfs(int a,int b,char c)
{
    int p,q;
    maxx++;
    mat[a][b]=0;
    for(int i=0;i<6;++i)
    {
        p=a+dir[i][0];q=b+dir[i][1];
        if(0<=a&&a<=n&&0<=b&&b<=m&&mat[p][q])
        {
            if(mat[p][q]==c)
               dfs(p,q,c);
            if(c=='0')
               dfs(p,q,c);
        }
    }
}
int main()
{
    int ans;
    for(;~scanf("%d%d%d%d",&n,&m,&x,&y);)
    {
        memset(mat,0,sizeof(mat));
        ans=maxx=0;
        for(int i=1;i<=n;++i)
            scanf("%s",mat[i]);
        for(int i=1;i<=n;i+=2)
            for(int j=m-1;j>=0;--j)
            {
                if(mat[i][j]=='E')  mat[i][j]=0;
                mat[i][j*2+1]=mat[i][j];
                mat[i][j]=0;
            }
        for(int i=2;i<=n;i+=2)
            for(int j=m-2;j>=0;--j)
            {
                if(mat[i][j]=='E')  mat[i][j]=0;
                mat[i][j*2+2]=mat[i][j];
                mat[i][j]=0;
            }
        m=2*m;
        if(x&1) y=(y-1)*2+1;
        else    y=(y-1)*2+2;
        dfs(x,y,mat[x][y]);
        ans=maxx;
        if(ans<3)
            ans=0;
        else
        {
            for(int i=1;i<=m;++i)
                if(mat[1][i])
                    dfs(1,i,'0');
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j)
                   if(mat[i][j]) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
