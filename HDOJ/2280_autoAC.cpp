#include <cstdio>
using namespace std;
const int INF=110;
int n,m=5;
int d[1010][40];
int mz[1010];
void dfs(int p,int s,int t,int c,int r)
{
    if(p>=m)
    {
        if(c<d[r][t]) d[r][t]=c;
        return;
    }
    if(p<4 && ((s>>p)&1)==0 && ((t>>p)&3)==0)
        dfs(p+1,s|(1<<p),t|(3<<p),c,r);
    if(p<4 && ((s>>p)&3)==0 && ((t>>p)&3)==0)
        dfs(p+1,s|(3<<p),t|(3<<p),c,r);
    if(p<4 && ((s>>p)&3)==0)
        dfs(p+1,s|(3<<p),t,c,r);
    if(((s>>p)&1)==0 && ((t>>p)&1)==0)
        dfs(p+1,s|(1<<p),t|(1<<p),c,r);
    if(p>0 && (((s>>p)&1)==0) && (t>>(p-1)&3)==0)
        dfs(p+1,s|(1<<p),t|(3<<(p-1)),c,r);
    if(p<4 && ((s>>p)&3)==0 && ((t>>p)&1)==0)
        dfs(p+1,s|(3<<p),t|(1<<p),c,r);
    if(p<4 && ((s>>p)&3)==0 && ((t>>p)&2)==0)
        dfs(p+1,s|(3<<p),t|(2<<p),c,r);
    if(((s>>p)&1)==1) dfs(p+1,s,t,c,r);
    else dfs(p+1,s|(1<<p),t,c+1,r);
}
int f(int x)
{
    int cnt=0;
    x+=32;
    for(int i=0;i<5;i++)
    {
        if((x&1)==1) x>>=1;
        else
        {
            x>>=1;
            if((x&1)==1) cnt++;
            x>>=1;
            i++;
        }
    }
    return cnt;
}
int main()
{
    int c;
    while(~scanf("%d%d",&n,&c))
    {
        for(int i=0;i<n;i++)
        {
            char str[10];
            scanf("%s",str);
            int s=0;
            for(int j=0;j<5;j++) s=(s<<1)+str[j]-'0';
            mz[i]=s;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<32;j++) d[i][j]=INF;
        d[0][mz[0]]=0;
        for(int i=0;i<n-1;i++)
            for(int j=0;j<32;j++) if(d[i][j]<=c)
                dfs(0,j,mz[i+1],d[i][j],i+1);
        bool flag=false;
        for(int i=0;i<32;i++)
            if(d[n-1][i]+f(i)<=c) flag=true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
