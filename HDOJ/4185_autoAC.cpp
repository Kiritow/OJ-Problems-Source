#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int map[700][700],p[700][700],vis[700],x[700],y[700],t,n,num,k;
char s[700][700];
bool search(int i)
{
    int j;
    for(j=0;j<num;j++)
    {
        if(map[i][j]&&!vis[j])
        {
            vis[j]=1;
            if(!y[j]||search(y[j]))
            {
                y[j]=i;
                x[i]=j;
                return true;
            }
        }
    }
    return false;
}
int match()
{
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    int ans=0;
    for(int i=0;i<num;i++)
    {
        memset(vis,0,sizeof(vis));
        if(search(i)) ans++;
    }
    return ans/2;
}
int main()
{
    scanf("%d",&t);
    k=1;
    while(t--)
    {
        int i,j;
        num=0;
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s",s[i]);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(s[i][j]=='#')
        p[i][j]=num++;
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(s[i][j]=='#')
            {
                if(j<n-1&&s[i][j+1]=='#')
                {
                    map[p[i][j]][p[i][j+1]]=1;
                    map[p[i][j+1]][p[i][j]]=1;
                }
                if(i<n-1&&s[i+1][j]=='#')
                {
                    map[p[i][j]][p[i+1][j]]=1;
                    map[p[i+1][j]][p[i][j]]=1;
                }
            }
        }
        int p=match();
        printf("Case %d: %d\n",k++,p);
    }
    return 0;
}
