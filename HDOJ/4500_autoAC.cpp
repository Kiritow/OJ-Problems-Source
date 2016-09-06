#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int i,j;
struct node{
    int x,y,sum;
}s[520];
int a[22][22];
int cmp(node a,node b)
{
    if(a.sum!=b.sum)
    return a.sum>b.sum;
    else if(a.x!=b.x) 
    return a.x<b.x;
    else if(a.y!=b.y)
    return a.y<b.y;
}
int main()
{
    while(~scanf("%d%d",&n,&m),n||m)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                if(a[i][j]*a[i-1][j]<0)
                s[cnt].sum+=abs(a[i-1][j]);
                else
                s[cnt].sum-=abs(a[i-1][j]);
                if(a[i][j]*a[i+1][j]<0)
                s[cnt].sum+=abs(a[i+1][j]);
                else
                s[cnt].sum-=abs(a[i+1][j]);
                if(a[i][j]*a[i][j-1]<0)
                s[cnt].sum+=abs(a[i][j-1]);
                else
                s[cnt].sum-=abs(a[i][j-1]);
                if(a[i][j]*a[i][j+1]<0)
                s[cnt].sum+=abs(a[i][j+1]);
                else
                s[cnt].sum-=abs(a[i][j+1]);
                s[cnt].x=i;
                s[cnt].y=j;
                cnt++;
            }
        }
        sort(s,s+cnt,cmp);
        printf("%d %d %d\n",s[0].x,s[0].y,s[0].sum);
    }
    return 0;
}
