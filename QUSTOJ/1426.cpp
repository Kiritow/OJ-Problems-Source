#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;

int s[30][10010];
int a[400],F[30],t[30][30],d[30][30],p[30];
int n,m;
int main()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&d[i][j]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&t[i][j]);
    memset(s,0,sizeof(s));
    memset(F,0,sizeof(F));
    memset(p,0,sizeof(p));
    int Max,odle,pos;
    Max=-1;
    for (int i=1;i<=n*m;i++)
    {
        odle=0; p[a[i]]++;
        for (int j=F[a[i]]+1;;j++)
        {
            if (s[d[a[i]][p[a[i]]]][j]) odle=0;
            else odle++;
            if (odle>=t[a[i]][p[a[i]]])
            {
                pos=j; break;
            }
        }
        for (int k=pos-odle+1;k<=pos;k++)
            s[d[a[i]][p[a[i]]]][k]=1;
        F[a[i]]=pos;
        if (pos>Max) Max=pos;
    }
    printf("%d\n",Max);
    return 0;
}
