#include<iostream>
#include<cstring>
using namespace std;
const int maxn=110;
int map[maxn][maxn],color[maxn][maxn];
char s[maxn][maxn];
int n,m,r,c,ans;
void change()
{
    int i,j,k,p;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i+r<=n&&j+c<=m&&map[i][j]!=color[i][j])
            {
                for(k=i;k<i+r;k++)
                {
                    for(p=j;p<j+c;p++)
                        if(color[k][p])
                            color[k][p]=0;
                        else
                            color[k][p]=1;
                }
                ans++;
            }
        }
    }
}
int judge()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(map[i][j]!=color[i][j])
                return 0;
        }
    }
    return 1;
}
int main(void)
{
    int i,j;
    while(scanf("%d%d%d%d",&n,&m,&r,&c)!=EOF)
    {
        if(n==0&&m==0&&r==0&&c==0)
            break;
        memset(map,0,sizeof(map));
        memset(color,0,sizeof(color));
        memset(s,0,sizeof(s));
        ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(j=0;j<m;j++)
            {
                map[i][j]=s[i][j]-'0';
            }
        }
        change();
        if(judge())
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
