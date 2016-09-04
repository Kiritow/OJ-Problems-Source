#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define inf 100000
int n,m;
int a[101][10010];
int r[101][10010],c[101][10010];
int que[10010][2],p,q;
inline int max(int x,int y){return x<y?y:x;}
inline int min(int x,int y){return x<y?x:y;}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0 && m==0) return 0;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            r[i][j]=c[i][j]=inf;
        }
        int ans=-1;
        while(1)
        {
            for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                r[i][j]=c[i][j]=inf;
            for (int i=1;i<=n;i++)
            {
                p=1;q=0;
                for (int j=1;j<=m;j++)
                {
                    while(p<=q && a[i][j]+j-1>=que[q][1]) q--;
                    que[++q][0]=j;que[q][1]=a[i][j]+j-1;
                    while(p<=q && que[q][1]<j) q--;
                    if (p<=q)
                        r[i][j]=j-que[q][0]+1;
                }
                p=1;q=0;
                for (int j=m;j>=1;j--)
                {
                    while(p<=q && j-a[i][j]+1<=que[q][1]) q--;
                    que[++q][0]=j;que[q][1]=j-a[i][j]+1;
                    while(p<=q && que[q][1]>j) q--;
                    if (p<=q)
                        r[i][j]=min(r[i][j], que[q][0]-j+1);
                }
            }
            for (int j=1;j<=m;j++)
            {
                p=1;q=0;
                for (int i=1;i<=n;i++)
                {
                    while(p<=q && a[i][j]+i-1>=que[q][1]) q--;
                    que[++q][0]=i;que[q][1]=a[i][j]+i-1;
                    while(p<=q && que[q][1]<i) q--;
                    if (p<=q) c[i][j]=i-que[q][0]+1;
                }
                p=1;q=0;
                for (int i=n;i>=1;i--)
                {
                    while(p<=q && i-a[i][j]+1<=que[q][1]) q--;
                    que[++q][0]=i;que[q][1]=i-a[i][j]+1;
                    while(p<=q && que[q][1]>i) q--;
                    if (p<=q) c[i][j]=min(c[i][j], que[q][0]-i+1);
                }
            }
            int tmp=0;
            for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                tmp=max(tmp,max(c[i][j],r[i][j]));
            }
            if (tmp==ans) break;
            ans=tmp;
            for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                a[i][j]=(a[i][j]<tmp?0:a[i][j]);
            }
        }
        if (ans<inf) printf("%d\n",ans);
        else printf("NO ANSWER!\n");
    }
    return 0;
}
