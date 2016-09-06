# include<stdio.h>
# include<string.h>
# define N 600000
# define mod 1000000007
int n,m;
__int64 dp[2][N],sum;
char map[15][15][5];
int a[200],tag,flag;
int s[15];
void DFS(int r,int up,int down,int num,int right)
{
    int xx,rr,yy,ll,i;
    if(num==m)
    {
        if(r==0) dp[flag][down]+=tag;
        else
        {
            dp[flag][down]+=dp[(flag+1)%2][up]*tag;
            dp[flag][down]%=mod;
        }
        return;
    }
    for(i=1;i<4;i++)
        if(map[r][num][i]!=map[r][num][0]) break;
    if(i==4)
    {
        tag*=4;
        xx=a[map[r][num][0]];
        if(xx==right || right==-1) DFS(r,up*3+xx,down*3+xx,num+1,xx);
        tag/=4;
        return;
    }
    for(i=0;i<4;i++)
    {
        xx=a[map[r][num][i]];
        rr=a[map[r][num][(i+1)%4]];
        yy=a[map[r][num][(i+2)%4]];
        ll=a[map[r][num][(i+3)%4]];
        if(right==-1 || ll==right) DFS(r,up*3+xx,down*3+yy,num+1,rr);
    }
}
int main()
{
    int i,j,ncase,t;
    scanf("%d",&ncase);
    a['F']=0;
    a['C']=1;
    a['R']=2;
    s[0]=1;
    for(i=1;i<=12;i++)
        s[i]=s[i-1]*3;
    for(t=1;t<=ncase;t++)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%s",map[i][j]);
        flag=0;
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)
        {
            tag=1;
            flag=(flag+1)%2;
            DFS(i,0,0,0,-1);
            for(j=0;j<s[m];j++) dp[(flag+1)%2][j]=0;
        }
        sum=0;
        for(i=0;i<s[m];i++)
        {
            sum+=dp[flag][i];
            sum%=mod;
        }
        printf("Case %d: %I64d\n",t,sum);
    }
    return 0;
}
